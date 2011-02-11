package src.simulator.genericNode.contentExchange.static.handler;


simple StaticContentExchange_UDPClientHandler
{
    parameters:
        double port;
        string downloaderClass;
    gates:
        input udpIn;
        output udpOut;
}
