package src.simulator.genericNode;

import inet.transport.tcp.TCP;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.linklayer.ppp.PPPInterface;
import inet.linklayer.ethernet.EthernetInterface;
import inet.base.NotificationBoard;
import inet.util.NAMTraceWriter;
import inet.transport.udp.UDP;
import inet.applications.udpapp.UDPApp;
import src.simulator.coordinate.CDN_RequestsAssignerReceiver;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_AlternateServerDetector;
import src.simulator.genericNode.contentExchange.static.handler.StaticContentExchange_TCPClientHandler;
import src.simulator.genericNode.contentExchange.static.handler.StaticContentExchange_UDPClientHandler;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_ClientNegotiator;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_ClientUnit;
import src.simulator.genericNode.contentExchange.static.handler.StaticContentExchange_TCPServerHandler;
import src.simulator.genericNode.contentExchange.static.handler.StaticContentExchange_UDPServerHandler;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_ServicePeer;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_StateTester;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_ServerUnit;
import src.simulator.genericNode.contentExchange.static.StaticContentExchange_ServerNegotiator;
module GenericHost
{
    parameters:
        @node();
        double nServerHandlers = default(0);
        double nClientHandlers = default(1);
        double nDownloaders = default(1000);
        string udpAppTypeC = default("UDPVideoStreamCli");
        string udpAppTypeS = default("UDPVideoStreamSvr");
        bool IPForward;
        string routingFile;
        string type = default("c"); //o, s, c
    gates:
        inout pppg[];
        inout ethg[];
    submodules:
        /////////////////////////////////////////////////////////////////////////////////////////////
        //CDN related
        tcpServerHandlers[nServerHandlers]: StaticContentExchange_TCPServerHandler {
            parameters:
                port = gimmeport(nServerHandlers+nClientHandlers);
                @display("i=block/app;p=559,300");
        }
        tcpClientHandlers[nClientHandlers]: StaticContentExchange_TCPClientHandler {
            parameters:
                port = gimmeport(nServerHandlers+nClientHandlers);

                @display("i=block/app;p=559,359");
        }
        udpServerHandlers[nServerHandlers]: StaticContentExchange_UDPServerHandler {
            parameters:
                port = gimmeport(nServerHandlers+nClientHandlers);
                @display("i=block/app;p=563,461");
        }
        udpClientHandlers[nClientHandlers]: StaticContentExchange_UDPClientHandler {
            parameters:
                port = gimmeport(nServerHandlers+nClientHandlers);

                @display("i=block/app;p=564,533");
        }
        cdn_RequestsAssignerReceiver: CDN_RequestsAssignerReceiver {
            @display("p=559,24");
        }
        staticContentExchange_ServicePeer: StaticContentExchange_ServicePeer {
            @display("p=559,100");
        }
        staticContentExchange_ClientUnit: StaticContentExchange_ClientUnit {
            @display("p=559,166");
        }
        staticContentExchange_AlternateServerDetector: StaticContentExchange_AlternateServerDetector {
            @display("p=277,24");
        }
        staticContentExchange_StateTester: StaticContentExchange_StateTester {
            @display("p=271,100");
        }
        staticContentExchange_ClientNegotiator: StaticContentExchange_ClientNegotiator {
            @display("p=559,231");
        }
        staticContentExchange_ServerUnit: StaticContentExchange_ServerUnit {
            @display("p=271,166");
        }
        staticContentExchange_ServerNegotiator: StaticContentExchange_ServerNegotiator {
            @display("p=271,231");
        }
        notificationBoard: NotificationBoard {
            @display("p=49,166");
        }
        interfaceTable: InterfaceTable {
            @display("p=49,24");
        }
        routingTable: RoutingTable {
            parameters:
                IPForward = IPForward;
                routerId = "";
                routingFile = routingFile;
                @display("p=49,100");
        }
        tcp: TCP {
            @display("p=394,339");
        }
        networkLayer: NetworkLayer {
            parameters:
                proxyARP = false;
                @display("p=223,437");
            gates:
                ifIn[sizeof(pppg)+sizeof(ethg)];
                ifOut[sizeof(pppg)+sizeof(ethg)];
        }
        ppp[sizeof(pppg)]: PPPInterface {
            @display("p=53,481");
        }
        eth[sizeof(ethg)]: EthernetInterface {
            @display("p=54,401");
        }
        udp: UDP {
            @display("p=401,503");
        }
    connections allowunconnected:
        //----------------------------------------------------------
        for i=0..nServerHandlers-1 {
            tcpServerHandlers[i].tcpOut --> tcp.appIn++;
            tcpServerHandlers[i].tcpIn <-- tcp.appOut++;
            udpServerHandlers[i].udpOut --> udp.appIn++;
            udpServerHandlers[i].udpIn <-- udp.appOut++;
        }
        for i=0..nClientHandlers-1 {
            tcpClientHandlers[i].tcpOut --> tcp.appIn++;
            tcpClientHandlers[i].tcpIn <-- tcp.appOut++;
            udpClientHandlers[i].udpOut --> udp.appIn++;
            udpClientHandlers[i].udpIn <-- udp.appOut++;
        }
        //----------------------------------------------------------
        tcp.ipOut --> networkLayer.tcpIn;
        tcp.ipIn <-- networkLayer.tcpOut;
        udp.ipOut --> networkLayer.udpIn;
        udp.ipIn <-- networkLayer.udpOut;


        // connections to network outside
        for i=0..sizeof(pppg)-1 {
            pppg[i] <--> ppp[i].phys;
            ppp[i].netwOut --> networkLayer.ifIn[i];
            ppp[i].netwIn <-- networkLayer.ifOut[i];
        }


        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> eth[i].phys;
            eth[i].netwOut --> networkLayer.ifIn[sizeof(pppg)+i];
            eth[i].netwIn <-- networkLayer.ifOut[sizeof(pppg)+i];
        }

}
