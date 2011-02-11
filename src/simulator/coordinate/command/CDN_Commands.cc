#define CDN_COMMANDS_CC
#include "CDN_Commands.h"
#include "Exceptions.h"
#include "AnakreonCommon.h"
#include <algorithm>
#include <assert.h>
void CDN_Commands::loadScript(const char* script, const char* generiNodeType){
	if(!strcmp(script, "NULL")){
		return;
	}
	FILE* scriptFile = fopen(script,"r");
	if(!scriptFile){
		throw cRuntimeError("Unable to read file <%s> (line: %d, file: %s)", script, __LINE__, __FILE__);
	}
	//the format should be:
	//	double int\n
	//meaning time objectId
	char line[1024];
	double time = -1.0;
	int objectId = -1;
	char transportType = 'n';//unknow
	while ( fgets( line, 1024, scriptFile )){
		if ( 3 != sscanf( line, "%lf %d %c", &time, &objectId, &transportType) ){
			throw cRuntimeError("Invlaid trace file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}

		if ( time < 0 || objectId < 0 || !(transportType == 't' || transportType == 'u') ){
			throw cRuntimeError("Invlaid trace file format near line <%s> (line: %d, file: %s)", line, __LINE__, __FILE__);
		}

		StaticContentExchange_ServicePeerCommand* staticContentExchange_ServicePeerCommand = new StaticContentExchange_ServicePeerCommand();
		staticContentExchange_ServicePeerCommand->setTime(time);
		staticContentExchange_ServicePeerCommand->setObjectId(objectId);
		staticContentExchange_ServicePeerCommand->setTransportType(transportType == 't'?TCP_P:transportType == 'u'?UDP_P:UNKNOWN_P);
		this->insertCommandByTime(staticContentExchange_ServicePeerCommand);
	}
	fclose(scriptFile);
}
void CDN_Commands::insertCommandByTime(StaticContentExchange_ServicePeerCommand* staticContentExchange_ServicePeerCommand){
	assert(staticContentExchange_ServicePeerCommand);

// 	vector<StaticContentExchange_ServicePeerCommand*>::iterator it;
// 	int i = 0;


// 	if(this->_commands.empty()){
// 		this->_commands.push_back(staticContentExchange_ServicePeerCommand);
// 		return;
// 	}

// 	it = this->_commands.begin();
// 	for(i = this->_commands.size()-1 ; i>=0 ; i--){
// 		if( this->_commands.at(i)->getTime() >= staticContentExchange_ServicePeerCommand->getTime() ){
// 			this->_commands.insert(it+i+1,staticContentExchange_ServicePeerCommand);
// 			return;
// 		}
// 	}
//
// 	this->_commands.insert(this->_commands.begin(),staticContentExchange_ServicePeerCommand);
//
	this->_commands.insert(this->_commands.begin(),staticContentExchange_ServicePeerCommand);
	return;
}
CDN_Commands::~CDN_Commands(){
	for_each(this->_commands.rbegin(), this->_commands.rend(), delete_elem<StaticContentExchange_ServicePeerCommand>());
	this->_commands.clear();
}
double CDN_Commands::getGetNextCommandTime(){
	if(this->_commands.empty()){
		throw new NoCommandsException();
	}

	return this->_commands.back()->getTime();
}
StaticContentExchange_ServicePeerCommand* CDN_Commands::detachNextCommand(){
	StaticContentExchange_ServicePeerCommand* command = this->_commands.back();
	this->_commands.pop_back();
	return command;
}
