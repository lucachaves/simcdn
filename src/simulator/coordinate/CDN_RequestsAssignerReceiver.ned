package src.simulator.coordinate;

simple CDN_RequestsAssignerReceiver
{
    parameters:
        double nRetries;
        double mean;
        string commandsScript = default("NULL");
    gates:
        input fromNegotiator;
        input fromServicePeer;
        input fromCentralUnit;
        input retry;
}
