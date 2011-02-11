package src.simulator.genericNode.contentExchange.static.handler;


simple StaticContentExchange_TCPClientHandler
{
    parameters:
        double port;
        string downloaderClass;
    gates:
        input tcpIn;
        output tcpOut;
}
