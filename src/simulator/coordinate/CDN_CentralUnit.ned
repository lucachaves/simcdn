package src.simulator.coordinate;

simple CDN_CentralUnit
{
    parameters:
        string policy;
        string objectsReference = default("./dataset/objects");
        double startTime = default(5.0);
        double intervalSurrogate = default(5.0);
        double intervalLoad  = default(3600.0);
        int distributedLoad = default(0);
    gates:
        input fromAlternateServerDetector;
}
