package src.simulator.genericNode.contentExchange.static.handler;

simple StaticContentExchange_UDPServerHandler
{
    parameters:
        double port;
    gates:
        input udpIn;
        input fromServerNegotiator;
        output udpOut;
}
