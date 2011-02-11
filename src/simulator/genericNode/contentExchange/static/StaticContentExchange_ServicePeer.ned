package src.simulator.genericNode.contentExchange.static;

simple StaticContentExchange_ServicePeer
{
    parameters:
        string cacheType = default("LRU");
        string cacheContents = default("NULL");
        string cacheSizeInMbs = default("0.0");
        volatile double shrink = default(0);
        string objectsReference = default("./dataset/objects");

    gates:
        input fromCDN_RequestsAssignerReceiverToClientUnit;
        input fromCDN_RequestsAssignerReceiverToServerUnit;
        input fromClientUnitOrServerUnit;
}
