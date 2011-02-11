package src.simulator.genericNode.contentExchange.static.handler;

simple StaticContentExchange_TCPServerHandler
{
    parameters:
        double port;
    gates:
        input tcpIn;
        input fromServerNegotiator;
        output tcpOut;
}
