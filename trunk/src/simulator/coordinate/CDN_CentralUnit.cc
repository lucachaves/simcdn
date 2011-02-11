#define CDN_CENTRALUNIT_CC
#include "CDN_CentralUnit.h"
#include "StaticContentExchange_ServicePeerCommand.h"
#include "CDN_CentralUnit_Reply.h"
#include "Request.h"
#include "RequestMessage.h"
#include "cache/Cache.h"
#include "Exceptions.h"
#include "InterNodeRequestProtocol.h"
#include <assert.h>
#include <climits>
Define_Module( CDN_CentralUnit);

void CDN_CentralUnit::initialize(int stage) {
	if (stage == 99) {
		cTopology topo("topo");
		//this->_topology = topo;
		topo.extractByProperty("node");

		//mad ids to indexes
		int index = 0;
		for (vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<
				CDN_RequestsAssignerReceiver*> >::iterator tempIterator =
				this->_availableSurrogateServers.begin(); tempIterator
				!= this->_availableSurrogateServers.end(); tempIterator++) {
			this->_surrogateIdToIndex.insert(make_pair(
					(*tempIterator)->getParentModule()->getId(), index));
			index++;
		}

		index = 0;
		for (vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<
				CDN_RequestsAssignerReceiver*> >::iterator tempIterator =
				this->_availableClients.begin(); tempIterator
				!= this->_availableClients.end(); tempIterator++) {
			this->_clientIdToIndex.insert(make_pair(
					(*tempIterator)->getParentModule()->getId(), index));
			index++;
		}

		index = 0;
		for (vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<
				CDN_RequestsAssignerReceiver*> >::iterator tempIterator =
				this->_availableOriginServers.begin(); tempIterator
				!= this->_availableOriginServers.end(); tempIterator++) {
			this->_originIdToIndex.insert(make_pair(
					(*tempIterator)->getParentModule()->getId(), index));
			index++;
		}

		//Setup surrogate - surrogate distances
		this->_surrogateToSurrogateDistance
				= new double*[this->_availableSurrogateServers.size()];

		for (int i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
			this->_surrogateToSurrogateDistance[i]
					= new double[this->_availableSurrogateServers.size()];
		}

		for (vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<
				CDN_RequestsAssignerReceiver*> >::iterator iteratorFrom =
				this->_availableSurrogateServers.begin(); iteratorFrom
				!= this->_availableSurrogateServers.end(); iteratorFrom++) {
			for (vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<
					CDN_RequestsAssignerReceiver*> >::iterator iteratorTo =
					this->_availableSurrogateServers.begin(); iteratorTo
					!= this->_availableSurrogateServers.end(); iteratorTo++) {
				cTopology::Node* surrogateNodeFrom = topo.getNodeFor(
						(*iteratorFrom)->getParentModule());
				cTopology::Node* surrogateNodeTo = topo.getNodeFor(
						(*iteratorTo)->getParentModule());

				if (surrogateNodeFrom == NULL) {
					throw cRuntimeError(
							"Node <%s> is not in the topology (line: %d, file: %s)",
							(*iteratorFrom)->getParentModule()->getName(),
							__LINE__, __FILE__);
						}
						if (surrogateNodeTo == NULL) {
							throw cRuntimeError("Node <%s> is not in the topology (line: %d, file: %s)", (*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
				}

				topo.calculateUnweightedSingleShortestPathsTo( surrogateNodeTo );

				if (surrogateNodeFrom->getNumPaths() == 0 && (0 != strcmp((*iteratorFrom)->getParentModule()->getName(),(*iteratorTo)->getParentModule()->getName()))){
					throw cRuntimeError("Node <%s> has no path to <%s> (line: %d, file: %s)", (*iteratorFrom)->getParentModule()->getName(),(*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
				}

				this->_surrogateToSurrogateDistance[this->_surrogateIdToIndex[(*iteratorFrom)->getParentModule()->getId()]][this->_surrogateIdToIndex[(*iteratorTo)->getParentModule()->getId()]] = surrogateNodeFrom->getDistanceToTarget();
			}
				}

				//Setup origin - surrogate distances
				this->_originToSurrogateDistance = new double*[ this->_availableOriginServers.size() ];

				for ( int i = 0; i <= (int)this->_availableOriginServers.size()-1; i++ ) {
					this->_originToSurrogateDistance[i] = new double[ this->_availableSurrogateServers.size() ];
				}

				for(vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> >::iterator iteratorFrom = this->_availableOriginServers.begin(); iteratorFrom != this->_availableOriginServers.end(); iteratorFrom++ ) {
					for(vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> >::iterator iteratorTo = this->_availableSurrogateServers.begin(); iteratorTo != this->_availableSurrogateServers.end(); iteratorTo++ ) {
						cTopology::Node* originNodeFrom = topo.getNodeFor( (*iteratorFrom)->getParentModule() );
						cTopology::Node* surrogateNodeTo = topo.getNodeFor( (*iteratorTo)->getParentModule() );

						if (originNodeFrom == NULL) {
							throw cRuntimeError("Node <%s> is not in the topology (line: %d, file: %s)", (*iteratorFrom)->getParentModule()->getName(), __LINE__, __FILE__);
						}
						if (surrogateNodeTo == NULL) {
							throw cRuntimeError("Node <%s> is not in the topology (line: %d, file: %s)", (*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
						}

						topo.calculateUnweightedSingleShortestPathsTo( surrogateNodeTo );

						if (originNodeFrom->getNumPaths() == 0) {
							throw cRuntimeError("Node <%s> has no path to <%s> (line: %d, file: %s)", (*iteratorFrom)->getParentModule()->getName(),(*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
						}

						this->_originToSurrogateDistance[this->_originIdToIndex[(*iteratorFrom)->getParentModule()->getId()]][this->_surrogateIdToIndex[(*iteratorTo)->getParentModule()->getId()]] = originNodeFrom->getDistanceToTarget();
					}
				}

				//Setup surrogate - client distances
				this->_surrogateToClientDistance = new double*[ this->_availableSurrogateServers.size() ];

				for ( int i = 0; i <= (int)this->_availableSurrogateServers.size()-1; i++ ) {
					this->_surrogateToClientDistance[i] = new double[ this->_availableClients.size() ];
				}

				for(vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> >::iterator iteratorFrom = this->_availableSurrogateServers.begin(); iteratorFrom != this->_availableSurrogateServers.end(); iteratorFrom++ ) {
					for(vector<CDN_RequestsAssignerReceiver*, boost::pool_allocator<CDN_RequestsAssignerReceiver*> >::iterator iteratorTo = this->_availableClients.begin(); iteratorTo != this->_availableClients.end(); iteratorTo++ ) {
						cTopology::Node* surrogateNodeFrom = topo.getNodeFor( (*iteratorFrom)->getParentModule() );
						cTopology::Node* clientNodeTo = topo.getNodeFor( (*iteratorTo)->getParentModule() );

						if (surrogateNodeFrom == NULL) {
							throw cRuntimeError("Node <%s> is not in the topology (line: %d, file: %s)", (*iteratorFrom)->getParentModule()->getName(), __LINE__, __FILE__);
						}
						if (clientNodeTo == NULL) {
							throw cRuntimeError("Node <%s> is not in the topology (line: %d, file: %s)", (*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
						}

						topo.calculateUnweightedSingleShortestPathsTo( clientNodeTo );

						if (surrogateNodeFrom->getNumPaths() == 0) {
							throw cRuntimeError("Node <%s> has no path to <%s> (line: %d, file: %s)", (*iteratorFrom)->getParentModule()->getName(),(*iteratorTo)->getParentModule()->getName(), __LINE__, __FILE__);
						}

						this->_surrogateToClientDistance[this->_surrogateIdToIndex[(*iteratorFrom)->getParentModule()->getId()]][this->_clientIdToIndex[(*iteratorTo)->getParentModule()->getId()]] = surrogateNodeFrom->getDistanceToTarget();
					}
				}

				// Setup closest origin to surrogate server
				for ( int k = 0; k <= (int)this->_availableSurrogateServers.size()-1; k++ ) {
					double minDistance = INT_MAX;
					int selectedOrigin = -1;
					int i = 0;
					for (i = 0; i <= (int)this->_availableOriginServers.size()-1; i++ ) {
						if(this->_originToSurrogateDistance[i][k] <= minDistance) {
							minDistance = this->_originToSurrogateDistance[i][k];
							selectedOrigin = i;
						}
					}
					this->_closestOriginToSurrogate.insert(make_pair(k, selectedOrigin));
				}

				// Setup closest surrogate server to client
				for ( int k = 0; k <= (int)this->_availableClients.size()-1; k++ ) {
					double minDistance = INT_MAX;
					int selectedSurrogate = -1;
					int i = 0;
					for (i = 0; i <= (int)this->_availableSurrogateServers.size()-1; i++ ) {
						if(this->_surrogateToClientDistance[i][k] <= minDistance) {
							minDistance = this->_surrogateToClientDistance[i][k];
							selectedSurrogate = i;
						}
					}
					this->_closestSurrogateToClient.insert(make_pair(k, selectedSurrogate));
				}
				int distributedLoad = this->par("distributedLoad");
				this->startTime = this->par("startTime");
				if(distributedLoad == 1)
					scheduleAt((this->startTime - 1) > 0?(this->startTime - 1):2.0, new cMessage);
			}
}
int CDN_CentralUnit::numInitStages() const {
	return 100;
}
void CDN_CentralUnit::handleMessage(cMessage *msg) {
	if(msg->isSelfMessage()){
		this->handleSelfMessage(msg);
	}else if(msg->arrivedOn("fromAlternateServerDetector")){
		handleFromAlternateServerDetectorMessage(msg);
	}
}
void CDN_CentralUnit::finish() {
}

void CDN_CentralUnit::handleSelfMessage(cMessage *msg){
	delete msg;
	this->distributeContentInSurrogate();
	double intervalLoad = this->par("intervalLoad");
	scheduleAt(intervalLoad + SIMTIME_DBL(simTime()), new cMessage);
}
void CDN_CentralUnit::handleFromAlternateServerDetectorMessage(cMessage *msg) {
	Request* originalRequest = ((RequestMessage*) msg)->detachRequest(); //detach the original-request
	cModule* genericHost = msg->getSenderModule()->getParentModule();
	delete msg;

	int	requestedObjectId =
					((StaticContentExchange_ServicePeerCommand*) originalRequest->getCommand())->getObjectId();
	cGate* alternateServerGate = NULL;
	if (!strcmp(par("policy"), "0")) {
		alternateServerGate = this->getCooperativeAlternateServerGate(
				requestedObjectId, genericHost);
	}
	if (!strcmp(par("policy"), "1")) {
		alternateServerGate = this->getNonCooperativeAlternateServerGate(
				requestedObjectId, genericHost);
	}
	if (!strcmp(par("policy"), "2")) {
		alternateServerGate = this->getRandomAlternateServerGate(
				requestedObjectId, genericHost);
	}
	if (!strcmp(par("policy"), "3")) {
		alternateServerGate = this->getLoadBalanceAlternateServerGate(
				requestedObjectId, genericHost);
	}
	if (!strcmp(par("policy"), "4")) {
		alternateServerGate
				= this->getCooperativeAlternateServerGateDistributed(
						requestedObjectId, genericHost);
	}

	CDN_CentralUnit_Reply* reply = new CDN_CentralUnit_Reply();
	reply->setServerGate(alternateServerGate);

	sendReply(this, originalRequest, reply, OK);
}
void CDN_CentralUnit::registerSurrogateServer(
		CDN_RequestsAssignerReceiver* surrogateServer) {
	this->_availableSurrogateServers.push_back(surrogateServer);
}
void CDN_CentralUnit::registerClient(CDN_RequestsAssignerReceiver* client) {
	this->_availableClients.push_back(client);
}
void CDN_CentralUnit::registerOriginServer(
		CDN_RequestsAssignerReceiver* originServer) {
	this->_availableOriginServers.push_back(originServer);
}
CDN_CentralUnit::~CDN_CentralUnit() {
	this->_availableSurrogateServers.clear();
	this->_availableOriginServers.clear();
	this->_availableClients.clear();
}
cGate* CDN_CentralUnit::getNonCooperativeAlternateServerGate(
		int requestedObjectId, cModule *client) {
	if (!strcmp(client->par("type"), "c")) {//we asume that there is at least one surrogate server
		return this->_availableSurrogateServers.at(
				this->_closestSurrogateToClient[this->_clientIdToIndex[client->getId()]])->gate(
				"fromNegotiator");
	} else {
		if (!strcmp(client->par("type"), "s")) {
			int index = this->_surrogateIdToIndex[client->getId()];
			int minDistance = INT_MAX;
			int selectedSurrogate = -1;
			for (int i = 0; i <= (int) this->_availableOriginServers.size() - 1; i++) {
				if (((Cache*) this->_availableOriginServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
					requestedObjectId)) {
					if (this->_originToSurrogateDistance[i][index] 	<= minDistance) {
						minDistance = this->_originToSurrogateDistance[i][index];
						selectedSurrogate = i;
					}
				}
			}
			return this->_availableOriginServers.at(selectedSurrogate)->gate("fromNegotiator");
		} else {

			throw cRuntimeError(
					"WTF? origin server asks for object? (line: %d, file: %s)",
					__LINE__, __FILE__);

				}
			}
			return NULL;
		}
cGate* CDN_CentralUnit::getCooperativeAlternateServerGate(int requestedObjectId, cModule *client) {
	if (!strcmp(client->par("type"), "c")) {//we asume that there is at least one surrogate server
		return this->_availableSurrogateServers.at(
				this->_closestSurrogateToClient[this->_clientIdToIndex[client->getId()]])->gate(
				"fromNegotiator");
	} else {
		if (!strcmp(client->par("type"), "s")) {
			// find closest SS that contains object
			double minDistance = INT_MAX;
			int index = this->_surrogateIdToIndex[client->getId()];
			int selectedSurrogate = -1;
			int i = 0;
			for (i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
				if (((Cache*) this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
						requestedObjectId)) {
					if (this->_surrogateToSurrogateDistance[i][index]<= minDistance) {
						minDistance	= this->_surrogateToSurrogateDistance[i][index];
						selectedSurrogate = i;
					}
				}
			}
			if (selectedSurrogate != -1) {
				return this->_availableSurrogateServers.at(selectedSurrogate)->gate("fromNegotiator");
			} else { //or origin server
				minDistance = INT_MAX;
				for (i = 0; i <= (int) this->_availableOriginServers.size() - 1; i++) {
					//cout << requestedObjectId << " " <<((cModule*)this->_availableOriginServers.at(i))->getParentModule()->getFullName()<<endl;
					if (((Cache*) this->_availableOriginServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
						requestedObjectId)) {
						if (this->_originToSurrogateDistance[i][index] 	<= minDistance) {
							minDistance = this->_originToSurrogateDistance[i][index];
							selectedSurrogate = i;
						}
					}
				}
				return this->_availableOriginServers.at(selectedSurrogate)->gate("fromNegotiator");
			}
		} else {
			throw cRuntimeError("WTF? origin server asks for object? (line: %d, file: %s)",	__LINE__, __FILE__);
		}
	}
	return NULL;
}
cGate* CDN_CentralUnit::getCooperativeAlternateServerGateDistributed(
		int requestedObjectId, cModule *client) {
	if (!strcmp(client->par("type"), "c")) {//we asume that there is at least one surrogate server
		return this->_availableSurrogateServers.at(
				this->_closestSurrogateToClient[this->_clientIdToIndex[client->getId()]])->gate(
				"fromNegotiator");
	} else {
		if (!strcmp(client->par("type"), "s")) {
			// find closest SS that contains object
			double minDistance = INT_MAX;
			int index = this->_surrogateIdToIndex[client->getId()];
			int selectedOrigin = -1;
			int i = 0;
			for (i = 0; i <= (int) this->_availableOriginServers.size() - 1; i++) {
				if (((Cache*) this->_availableOriginServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
						requestedObjectId)) {
					if (this->_originToSurrogateDistance[i][index]
							<= minDistance) {
						minDistance
								= this->_originToSurrogateDistance[i][index];
						selectedOrigin = i;
					}
				}
			}
			int selectedSurrogate = -1;
			for (i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
				if (this->_originToSurrogateDistance[selectedOrigin][i] == 2) {
					selectedSurrogate = i;
					//cout <<index<<"-"<< selectedOrigin << " " << i << " " <<this->_originToSurrogateDistance[selectedOrigin][i]<<endl;
				}
			}
			if (selectedSurrogate != index) {
				for (i = 0; i <= (int) this->_availableSurrogateServers.size()
						- 1; i++) {
					if (this->_surrogateToSurrogateDistance[index][i] == 3)
						for (int j = 0; j
								<= (int) this->_availableSurrogateServers.size()
										- 1; j++) {
							if (this->_surrogateToSurrogateDistance[i][selectedSurrogate]
									== this->_surrogateToSurrogateDistance[index][selectedSurrogate]
											- 1)
								selectedSurrogate = i;
						}
				}
			} else {
				selectedSurrogate = -1;
			}
			if (selectedSurrogate != -1) {
				return this->_availableSurrogateServers.at(selectedSurrogate)->gate(
						"fromNegotiator");
			} else { //or origin server
				return this->_availableOriginServers.at(
						this->_closestOriginToSurrogate[index])->gate(
						"fromNegotiator");
			}
		} else {

			throw cRuntimeError(
					"WTF? origin server asks for object? (line: %d, file: %s)",
					__LINE__, __FILE__);

				}
			}
			return NULL;
		}
cGate* CDN_CentralUnit::getRandomAlternateServerGate(int requestedObjectId,
		cModule *client) {
	if (!strcmp(client->par("type"), "c")) {//we asume that there is at least one surrogate server
		return this->_availableSurrogateServers.at(0
				+ int(_availableSurrogateServers.size() * rand() / (RAND_MAX
						+ 1.0)))->gate("fromNegotiator");
	} else {
		if (!strcmp(client->par("type"), "s")) {
			int i = 0;
			vector<int> surrogateServersContainingObject;
			for (i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
				if (((Cache*) this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
						requestedObjectId)) {
					surrogateServersContainingObject.push_back(i);
				}
			}

			if (surrogateServersContainingObject.size() > 0) {
				int selectedSurrogate = surrogateServersContainingObject.at(
						0 + int(surrogateServersContainingObject.size()
								* rand() / (RAND_MAX + 1.0)));
				surrogateServersContainingObject.clear();
				return this->_availableSurrogateServers.at(selectedSurrogate)->gate(
						"fromNegotiator");
			} else { //or origin server
				surrogateServersContainingObject.clear();
				vector<int> originServersContainingObject;
				for (i = 0; i <= (int) this->_availableOriginServers.size() - 1; i++) {
					if (((Cache*) this->_availableOriginServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
							requestedObjectId)) {
						originServersContainingObject.push_back(i);
					}
				}
				int selectedOrigin = originServersContainingObject.at(
						0 + int(originServersContainingObject.size()
								* rand() / (RAND_MAX + 1.0)));
				return this->_availableOriginServers.at(selectedOrigin)->gate("fromNegotiator");
			}
		} else {

			throw cRuntimeError(
					"WTF? origin server asks for object? (line: %d, file: %s)",
					__LINE__, __FILE__);

				}
			}
			return NULL;
		}

cGate* CDN_CentralUnit::getLoadBalanceAlternateServerGate(
		int requestedObjectId, cModule *client) {
	if (!strcmp(client->par("type"), "c")) { //we asume that there is at least one surrogate server
		double minLoad = 1.0;
		int selectedSurrogate = -1;
		int i = 0;
		for (i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
			if (this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->uploadLoad()
					<= minLoad) {
				minLoad	= this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->uploadLoad();
				selectedSurrogate = i;
			}
		}
		return this->_availableSurrogateServers.at(selectedSurrogate)->gate("fromNegotiator");
	} else {
		if (!strcmp(client->par("type"), "s")) {
			double minLoad = 1.0;
			int selectedSurrogate = -1;
			int i = 0;
			for (i = 0; i <= (int) this->_availableSurrogateServers.size() - 1; i++) {
				if (((Cache*) this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->getInformationSet())->objectExists(
						requestedObjectId)) {
					if (this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->uploadLoad()
							<= minLoad) {
						minLoad	= this->_availableSurrogateServers.at(i)->getStaticContentExchangeState()->uploadLoad();
						selectedSurrogate = i;
					}
				}
			}

			if (selectedSurrogate != -1 && minLoad < 0.95) {
				return this->_availableSurrogateServers.at(selectedSurrogate)->gate("fromNegotiator");
			} else { //or origin server
				double minLoad = 1.0;
				int selectedOrigin = -1;
				int i = 0;
				for (i = 0; i <= (int) this->_availableOriginServers.size() - 1; i++) {
					if (this->_availableOriginServers.at(i)->getStaticContentExchangeState()->uploadLoad() <= minLoad
							&& ((Cache*) this->_availableOriginServers.at(i)->getStaticContentExchangeState()->
							getInformationSet())->objectExists(requestedObjectId)) {
						minLoad	= this->_availableOriginServers.at(i)->getStaticContentExchangeState()->uploadLoad();
						selectedOrigin = i;
					}
				}
				return this->_availableOriginServers.at(selectedOrigin)->gate("fromNegotiator");
			}
		} else {
			throw cRuntimeError(
				"WTF? origin server asks for object? (line: %d, file: %s)",
				__LINE__, __FILE__);

		}
	}
	return NULL;
}

vector<int> CDN_CentralUnit::loadScript(const char* script) {
	char line[1024];
	int objectId = -1;
	vector<int> objects;
	if (!strcmp(script, "NULL")) {
		return objects;
	}
	FILE* scriptFile = fopen(script, "r");
	if (!scriptFile) {
		throw cRuntimeError("Unable to read file <%s> (line: %d, file: %s)",
				script, __LINE__, __FILE__);
	}
	//the format should be:
	//	double int\n
	//meaning time objectId

	while ( fgets( line, 1024, scriptFile )) {
		if ( 1 != sscanf( line, "%d", &objectId) ) {
			throw cRuntimeError("Invlaid trace file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}
		if (objectId < 0) {
			throw cRuntimeError("Invlaid trace file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}
		objects.push_back(objectId);
	}
	fclose(scriptFile);
	return objects;
}

void CDN_CentralUnit::distributeContentInSurrogate() {
	int objectId = 0;
	double intervalSurrogate = this->par("intervalSurrogate");
	double intervalLoad = this->par("intervalLoad");
	unsigned int i;
	bool objectExist = false;
	vector<int> objects = this->loadScript(this->par("objectsReference"));
	for (cModule::SubmoduleIterator iter(getParentModule()); !iter.end(); iter++) {
		if (0 == strcmp(iter()->getNedTypeName(), "genericNode.GenericHost")
				&& 0 == strcmp(iter()->par("type"), "s")) {
			//cout << iter()->getFullName() << endl;
			StaticContentExchange_ServicePeer
					* staticContentExchange_ServicePeer = NULL;
			CDN_RequestsAssignerReceiver* cdn_RequestsAssignerReceiver = NULL;
			for (cModule::SubmoduleIterator it(iter()); !it.end(); it++) {
				if (it()->isName("staticContentExchange_ServicePeer")) {
					staticContentExchange_ServicePeer
							= (StaticContentExchange_ServicePeer*) it();
					break;
				}
			}
			for (cModule::SubmoduleIterator it(iter()); !it.end(); it++) {
				if (it()->isName("cdn_RequestsAssignerReceiver")) {
					cdn_RequestsAssignerReceiver
							= (CDN_RequestsAssignerReceiver*) it();
					break;
				}
			}
			for (i = 0; i < objects.size(); i++) {
				objectId = objects.at(i);
				objectExist = cdn_RequestsAssignerReceiver->getStaticContentExchangeState()->getCache()->objectExists(objectId);
				if (!objectExist) {
					StaticContentExchange_ServicePeerCommand* command =
							new StaticContentExchange_ServicePeerCommand();
					command->setTime(this->startTime);
					cout <<"Command TIME - Distributed" << this->startTime << endl;
					if(i == 0)
						command->setFlag(true);
					command->setObjectId(objectId);
					command->setTransportType(UDP_P);

					Request* request = new Request();
					request->setCommand(command);
					request->setTransportType(command->getTransportType());

					//Pack it inside a message
					RequestMessage* requestMessage = new RequestMessage();
					requestMessage->setRequest(request);

					//send it
					this->sendDirect(
							requestMessage,
							0,
							0,
							cdn_RequestsAssignerReceiver->gate(
									"fromCentralUnit"));
					this->startTime += 0.001;
				}
			}
			this->startTime += intervalSurrogate;
		}
	}
	this->startTime += intervalLoad;
}
