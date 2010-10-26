package models.exp01;

import inet.world.ChannelInstaller;
import inet.networklayer.autorouting.FlatNetworkConfigurator;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;
import ned.DatarateChannel;
import src.simulator.coordinate.CDN_CentralUnit;
import src.simulator.coordinate.stats.Stats;
import src.simulator.genericNode.GenericHost;

channel fiberline extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 100Mbps;
}
channel fiberline10G extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 10Gbps;
}
channel fiberline2G extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 2.5Gbps;
}
channel fiberline622M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 622Mbps;
}
channel fiberline155M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 155Mbps;
}
channel fiberline257M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 257Mbps;
}
channel fiberline34M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 34Mbps;
}
channel fiberline20M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 2Mbps;
}
channel fiberline6M extends DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 6Mbps;
}
network base
{
    parameters:
        int n = default(10); // number of switch on the router
    submodules:
        channelInstaller: ChannelInstaller {
            parameters:
                channelClass = "ThruputMeteringChannel";
                channelAttrs = "format=u";
                @display("p=84,50;i=block/cogwheel_s");
        }
        configurator: FlatNetworkConfigurator {
            parameters:
                @display("p=185,50;i=block/cogwheel_s");
        }
        cdn_CentralUnit: CDN_CentralUnit {
            @display("p=382,50");
        }
        stats: Stats {
            @display("p=276,50");
        }
        
        r0: Router {
            parameters:
                @display("i=abstract/router;p=202,231");
        }
        r1: Router {
            parameters:
                @display("i=abstract/router;p=526,596");
        }
        r2: Router {
            parameters:
                @display("i=abstract/router;p=257,565");
        }
        r3: Router {
            parameters:
                @display("i=abstract/router;p=318,517");
        }
        r4: Router {
            parameters:
                @display("i=abstract/router;p=929,636");
        }
        r5: Router {
            parameters:
                @display("i=abstract/router;p=929,188");
        }
        r6: Router {
            parameters:
                @display("i=abstract/router;p=347,188");
        }
        r7: Router {
            parameters:
                @display("i=abstract/router;p=573,540");
        }
        r8: Router {
            parameters:
                @display("i=abstract/router;p=241,293");
        }
        r9: Router {
            parameters:
                @display("i=abstract/router;p=630,496");
        }
        r10: Router {
            parameters:
                @display("i=abstract/router;p=300,334");
        }
        r11: Router {
            parameters:
                @display("i=abstract/router;p=389,334");
        }
        r12: Router {
            parameters:
                @display("i=abstract/router;p=659,188");
        }
        r13: Router {
            parameters:
                @display("i=abstract/router;p=698,496");
        }
        r14: Router {
            parameters:
                @display("i=abstract/router;p=860,447");
        }
        r15: Router {
            parameters:
                @display("i=abstract/router;p=93,636");
        }
        r16: Router {
            parameters:
                @display("i=abstract/router;p=929,422");
        }
        r17: Router {
            parameters:
                @display("i=abstract/router;p=750,540");
        }
        r18: Router {
            parameters:
                @display("i=abstract/router;p=422,548");
        }
        r19: Router {
            parameters:
                @display("i=abstract/router;p=454,293");
        }
        r20: Router {
            parameters:
                @display("i=abstract/router;p=659,636");
        }
        r21: Router {
            parameters:
                @display("i=abstract/router;p=860,384");
        }
        r22: Router {
            parameters:
                @display("i=abstract/router;p=93,188");
        }
        r23: Router {
            parameters:
                @display("i=abstract/router;p=93,486");
        }
        r24: Router {
            parameters:
                @display("i=abstract/router;p=347,636");
        }
        r25: Router {
            parameters:
                @display("i=abstract/router;p=781,596");
        }
        r26: Router {
            parameters:
                @display("i=abstract/router;p=487,225");
        }
        r27: Router {
            parameters:
                @display("i=abstract/router;p=202,941");
        }
        r28: Router {
            parameters:
                @display("i=abstract/router;p=558,1211");
        }
        r29: Router {
            parameters:
                @display("i=abstract/router;p=270,1279");
        }
        r30: Router {
            parameters:
                @display("i=abstract/router;p=309,1219");
        }
        r31: Router {
            parameters:
                @display("i=abstract/router;p=929,1316");
        }
        r32: Router {
            parameters:
                @display("i=abstract/router;p=929,899");
        }
        r33: Router {
            parameters:
                @display("i=abstract/router;p=346,899");
        }
        r34: Router {
            parameters:
                @display("i=abstract/router;p=526,1279");
        }
        r35: Router {
            parameters:
                @display("i=abstract/router;p=241,984");
        }
        r36: Router {
            parameters:
                @display("i=abstract/router;p=620,1165");
        }
        r37: Router {
            parameters:
                @display("i=abstract/router;p=309,1040");
        }
        r38: Router {
            parameters:
                @display("i=abstract/router;p=391,1034");
        }
        r39: Router {
            parameters:
                @display("i=abstract/router;p=659,899");
        }
        r40: Router {
            parameters:
                @display("i=abstract/router;p=705,1165");
        }
        r41: Router {
            parameters:
                @display("i=abstract/router;p=848,1149");
        }
        r42: Router {
            parameters:
                @display("i=abstract/router;p=93,1316");
        }
        r43: Router {
            parameters:
                @display("i=abstract/router;p=929,1099");
        }
        r44: Router {
            parameters:
                @display("i=abstract/router;p=758,1211");
        }
        r45: Router {
            parameters:
                @display("i=abstract/router;p=415,1235");
        }
        r46: Router {
            parameters:
                @display("i=abstract/router;p=454,984");
        }
        r47: Router {
            parameters:
                @display("i=abstract/router;p=659,1316");
        }
        r48: Router {
            parameters:
                @display("i=abstract/router;p=848,1053");
        }
        r49: Router {
            parameters:
                @display("i=abstract/router;p=93,899");
        }
        r50: Router {
            parameters:
                @display("i=abstract/router;p=93,1099");
        }
        r51: Router {
            parameters:
                @display("i=abstract/router;p=357,1316");
        }
        r52: Router {
            parameters:
                @display("i=abstract/router;p=797,1279");
        }
        r53: Router {
            parameters:
                @display("i=abstract/router;p=510,941");
        }
        r54: Router {
            parameters:
                @display("i=abstract/router;p=346,764");
        }
        r55: Router {
            parameters:
                @display("i=abstract/router;p=449,795");
        }
        r56: Router {
            parameters:
                @display("i=abstract/router;p=347,826");
        }
        c57: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c58: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c59: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c60: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c61: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c62: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c63: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c64: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c65: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c66: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c67: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c68: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c69: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c70: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c71: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c72: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c73: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c74: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c75: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c76: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c77: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c78: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c79: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c80: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c81: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c82: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c83: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c84: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c85: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c86: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c87: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c88: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c89: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c90: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c91: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c92: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c93: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c94: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c95: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c96: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c97: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c98: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c99: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c100: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c101: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c102: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c103: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c104: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c105: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c106: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c107: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c108: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c109: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c110: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c111: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c112: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c113: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c114: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c115: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c116: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c117: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c118: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c119: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c120: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c121: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c122: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c123: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c124: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c125: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c126: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c127: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c128: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c129: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c130: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c131: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c132: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c133: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c134: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c135: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c136: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c137: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c138: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c139: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c140: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c141: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c142: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c143: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c144: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c145: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c146: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c147: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c148: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c149: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c150: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c151: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c152: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c153: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c154: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c155: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        c156: GenericHost{
            parameters:
                @display("i=device/laptop");
        }
        s157: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s158: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s159: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s160: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s161: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s162: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s163: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s164: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s165: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s166: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s167: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s168: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s169: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s170: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s171: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s172: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s173: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s174: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s175: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s176: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s177: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s178: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s179: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s180: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s181: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s182: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	s183: GenericHost{
            parameters:
                @display("i=abstract/cache_s");
        }
    	o184: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o185: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o186: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o187: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o188: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o189: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o190: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o191: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o192: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o193: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o194: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o195: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o196: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o197: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o198: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o199: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o200: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o201: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o202: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o203: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o204: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o205: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o206: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o207: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o208: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o209: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	o210: GenericHost{
            parameters:
                @display("i=device/server_s");
        }
	connections allowunconnected:
		r0.pppg++ <--> fiberline6M <--> r6.pppg++;
		r0.pppg++ <--> fiberline <--> s157.pppg++;
		r0.pppg++ <--> fiberline <--> o184.pppg++;
		r1.pppg++ <--> fiberline34M <--> r20.pppg++;
		r1.pppg++ <--> fiberline <--> s158.pppg++;
		r1.pppg++ <--> fiberline <--> o185.pppg++;
		r2.pppg++ <--> fiberline20M <--> r24.pppg++;
		r2.pppg++ <--> fiberline <--> s159.pppg++;
		r2.pppg++ <--> fiberline <--> o186.pppg++;
		r3.pppg++ <--> fiberline20M <--> r24.pppg++;
		r3.pppg++ <--> fiberline <--> s160.pppg++;
		r3.pppg++ <--> fiberline <--> o187.pppg++;
		r4.pppg++ <--> fiberline2G <--> r16.pppg++;
		r4.pppg++ <--> fiberline20M <--> r20.pppg++;
		r4.pppg++ <--> fiberline <--> s161.pppg++;
		r4.pppg++ <--> fiberline <--> o188.pppg++;
		r5.pppg++ <--> fiberline2G <--> r12.pppg++;
		r5.pppg++ <--> fiberline2G <--> r16.pppg++;
		r5.pppg++ <--> fiberline <--> s162.pppg++;
		r5.pppg++ <--> fiberline <--> o189.pppg++;
		r6.pppg++ <--> fiberline622M <--> r8.pppg++;
		r6.pppg++ <--> fiberline155M <--> r10.pppg++;
		r6.pppg++ <--> fiberline155M <--> r11.pppg++;
		r6.pppg++ <--> fiberline10G <--> r12.pppg++;
		r6.pppg++ <--> fiberline6M <--> r19.pppg++;
		r6.pppg++ <--> fiberline2G <--> r22.pppg++;
		r6.pppg++ <--> fiberline10G <--> r24.pppg++;
		r6.pppg++ <--> fiberline34M <--> r26.pppg++;
		r6.pppg++ <--> fiberline <--> s163.pppg++;
		r6.pppg++ <--> fiberline <--> o190.pppg++;
		r7.pppg++ <--> fiberline155M <--> r20.pppg++;
		r7.pppg++ <--> fiberline <--> s164.pppg++;
		r7.pppg++ <--> fiberline <--> o191.pppg++;
		r8.pppg++ <--> fiberline <--> s165.pppg++;
		r8.pppg++ <--> fiberline <--> o192.pppg++;
		r9.pppg++ <--> fiberline155M <--> r20.pppg++;
		r9.pppg++ <--> fiberline <--> s166.pppg++;
		r9.pppg++ <--> fiberline <--> o193.pppg++;
		r10.pppg++ <--> fiberline <--> s167.pppg++;
		r10.pppg++ <--> fiberline <--> o194.pppg++;
		r11.pppg++ <--> fiberline <--> s168.pppg++;
		r11.pppg++ <--> fiberline <--> o195.pppg++;
		r12.pppg++ <--> fiberline10G <--> r20.pppg++;
		r12.pppg++ <--> fiberline <--> s169.pppg++;
		r12.pppg++ <--> fiberline <--> o196.pppg++;
		r13.pppg++ <--> fiberline20M <--> r20.pppg++;
		r13.pppg++ <--> fiberline <--> s170.pppg++;
		r13.pppg++ <--> fiberline <--> o197.pppg++;
		r14.pppg++ <--> fiberline155M <--> r16.pppg++;
		r14.pppg++ <--> fiberline <--> s171.pppg++;
		r14.pppg++ <--> fiberline <--> o198.pppg++;
		r15.pppg++ <--> fiberline2G <--> r23.pppg++;
		r15.pppg++ <--> fiberline2G <--> r24.pppg++;
		r15.pppg++ <--> fiberline <--> s172.pppg++;
		r15.pppg++ <--> fiberline <--> o199.pppg++;
		r16.pppg++ <--> fiberline155M <--> r21.pppg++;
		r16.pppg++ <--> fiberline <--> s173.pppg++;
		r16.pppg++ <--> fiberline <--> o200.pppg++;
		r17.pppg++ <--> fiberline34M <--> r20.pppg++;
		r17.pppg++ <--> fiberline <--> s174.pppg++;
		r17.pppg++ <--> fiberline <--> o201.pppg++;
		r18.pppg++ <--> fiberline6M <--> r24.pppg++;
		r18.pppg++ <--> fiberline <--> s175.pppg++;
		r18.pppg++ <--> fiberline <--> o202.pppg++;
		r19.pppg++ <--> fiberline <--> s176.pppg++;
		r19.pppg++ <--> fiberline <--> o203.pppg++;
		r20.pppg++ <--> fiberline10G <--> r24.pppg++;
		r20.pppg++ <--> fiberline2G <--> r25.pppg++;
		r20.pppg++ <--> fiberline <--> s177.pppg++;
		r20.pppg++ <--> fiberline <--> o204.pppg++;
		r21.pppg++ <--> fiberline <--> s178.pppg++;
		r21.pppg++ <--> fiberline <--> o205.pppg++;
		r22.pppg++ <--> fiberline2G <--> r23.pppg++;
		r22.pppg++ <--> fiberline <--> s179.pppg++;
		r22.pppg++ <--> fiberline <--> o206.pppg++;
		r23.pppg++ <--> fiberline <--> s180.pppg++;
		r23.pppg++ <--> fiberline <--> o207.pppg++;
		r24.pppg++ <--> fiberline10G <--> r54.pppg++;
		r24.pppg++ <--> fiberline <--> s181.pppg++;
		r24.pppg++ <--> fiberline <--> o208.pppg++;
		r25.pppg++ <--> fiberline <--> s182.pppg++;
		r25.pppg++ <--> fiberline <--> o209.pppg++;
		r26.pppg++ <--> fiberline <--> s183.pppg++;
		r26.pppg++ <--> fiberline <--> o210.pppg++;
		r27.pppg++ <--> fiberline6M <--> r33.pppg++;
		r27.pppg++ <--> fiberline <--> c154.pppg++;
		r28.pppg++ <--> fiberline34M <--> r47.pppg++;
		r28.pppg++ <--> fiberline <--> c155.pppg++;
		r29.pppg++ <--> fiberline20M <--> r51.pppg++;
		r29.pppg++ <--> fiberline <--> c156.pppg++;
		r30.pppg++ <--> fiberline20M <--> r51.pppg++;
		r31.pppg++ <--> fiberline2G <--> r43.pppg++;
		r31.pppg++ <--> fiberline2G <--> r47.pppg++;
		r31.pppg++ <--> fiberline <--> c57.pppg++;
		r31.pppg++ <--> fiberline <--> c58.pppg++;
		r31.pppg++ <--> fiberline <--> c59.pppg++;
		r31.pppg++ <--> fiberline <--> c60.pppg++;
		r32.pppg++ <--> fiberline2G <--> r39.pppg++;
		r32.pppg++ <--> fiberline2G <--> r43.pppg++;
		r32.pppg++ <--> fiberline <--> c61.pppg++;
		r32.pppg++ <--> fiberline <--> c62.pppg++;
		r32.pppg++ <--> fiberline <--> c63.pppg++;
		r32.pppg++ <--> fiberline <--> c64.pppg++;
		r33.pppg++ <--> fiberline622M <--> r35.pppg++;
		r33.pppg++ <--> fiberline155M <--> r37.pppg++;
		r33.pppg++ <--> fiberline155M <--> r38.pppg++;
		r33.pppg++ <--> fiberline10G <--> r39.pppg++;
		r33.pppg++ <--> fiberline6M <--> r46.pppg++;
		r33.pppg++ <--> fiberline2G <--> r49.pppg++;
		r33.pppg++ <--> fiberline10G <--> r51.pppg++;
		r33.pppg++ <--> fiberline34M <--> r53.pppg++;
		r33.pppg++ <--> fiberline10G <--> r56.pppg++;
		r33.pppg++ <--> fiberline <--> c65.pppg++;
		r33.pppg++ <--> fiberline <--> c66.pppg++;
		r33.pppg++ <--> fiberline <--> c67.pppg++;
		r33.pppg++ <--> fiberline <--> c68.pppg++;
		r33.pppg++ <--> fiberline <--> c69.pppg++;
		r33.pppg++ <--> fiberline <--> c70.pppg++;
		r33.pppg++ <--> fiberline <--> c71.pppg++;
		r33.pppg++ <--> fiberline <--> c72.pppg++;
		r33.pppg++ <--> fiberline <--> c73.pppg++;
		r33.pppg++ <--> fiberline <--> c74.pppg++;
		r33.pppg++ <--> fiberline <--> c75.pppg++;
		r33.pppg++ <--> fiberline <--> c76.pppg++;
		r33.pppg++ <--> fiberline <--> c77.pppg++;
		r33.pppg++ <--> fiberline <--> c78.pppg++;
		r33.pppg++ <--> fiberline <--> c79.pppg++;
		r33.pppg++ <--> fiberline <--> c80.pppg++;
		r33.pppg++ <--> fiberline <--> c81.pppg++;
		r33.pppg++ <--> fiberline <--> c82.pppg++;
		r34.pppg++ <--> fiberline155M <--> r47.pppg++;
		r35.pppg++ <--> fiberline <--> c83.pppg++;
		r36.pppg++ <--> fiberline155M <--> r47.pppg++;
		r39.pppg++ <--> fiberline10G <--> r47.pppg++;
		r39.pppg++ <--> fiberline <--> c84.pppg++;
		r39.pppg++ <--> fiberline <--> c85.pppg++;
		r39.pppg++ <--> fiberline <--> c86.pppg++;
		r39.pppg++ <--> fiberline <--> c87.pppg++;
		r39.pppg++ <--> fiberline <--> c88.pppg++;
		r39.pppg++ <--> fiberline <--> c89.pppg++;
		r39.pppg++ <--> fiberline <--> c90.pppg++;
		r39.pppg++ <--> fiberline <--> c91.pppg++;
		r39.pppg++ <--> fiberline <--> c92.pppg++;
		r39.pppg++ <--> fiberline <--> c93.pppg++;
		r39.pppg++ <--> fiberline <--> c94.pppg++;
		r39.pppg++ <--> fiberline <--> c95.pppg++;
		r39.pppg++ <--> fiberline <--> c96.pppg++;
		r39.pppg++ <--> fiberline <--> c97.pppg++;
		r39.pppg++ <--> fiberline <--> c98.pppg++;
		r39.pppg++ <--> fiberline <--> c99.pppg++;
		r39.pppg++ <--> fiberline <--> c100.pppg++;
		r39.pppg++ <--> fiberline <--> c101.pppg++;
		r40.pppg++ <--> fiberline20M <--> r47.pppg++;
		r41.pppg++ <--> fiberline155M <--> r43.pppg++;
		r42.pppg++ <--> fiberline2G <--> r50.pppg++;
		r42.pppg++ <--> fiberline2G <--> r51.pppg++;
		r42.pppg++ <--> fiberline <--> c102.pppg++;
		r42.pppg++ <--> fiberline <--> c103.pppg++;
		r42.pppg++ <--> fiberline <--> c104.pppg++;
		r42.pppg++ <--> fiberline <--> c105.pppg++;
		r43.pppg++ <--> fiberline155M <--> r48.pppg++;
		r43.pppg++ <--> fiberline <--> c106.pppg++;
		r43.pppg++ <--> fiberline <--> c107.pppg++;
		r43.pppg++ <--> fiberline <--> c108.pppg++;
		r43.pppg++ <--> fiberline <--> c109.pppg++;
		r44.pppg++ <--> fiberline34M <--> r47.pppg++;
		r45.pppg++ <--> fiberline6M <--> r51.pppg++;
		r47.pppg++ <--> fiberline10G <--> r51.pppg++;
		r47.pppg++ <--> fiberline34M <--> r52.pppg++;
		r47.pppg++ <--> fiberline <--> c110.pppg++;
		r47.pppg++ <--> fiberline <--> c111.pppg++;
		r47.pppg++ <--> fiberline <--> c112.pppg++;
		r47.pppg++ <--> fiberline <--> c113.pppg++;
		r47.pppg++ <--> fiberline <--> c114.pppg++;
		r47.pppg++ <--> fiberline <--> c115.pppg++;
		r47.pppg++ <--> fiberline <--> c116.pppg++;
		r47.pppg++ <--> fiberline <--> c117.pppg++;
		r47.pppg++ <--> fiberline <--> c118.pppg++;
		r47.pppg++ <--> fiberline <--> c119.pppg++;
		r47.pppg++ <--> fiberline <--> c120.pppg++;
		r47.pppg++ <--> fiberline <--> c121.pppg++;
		r47.pppg++ <--> fiberline <--> c122.pppg++;
		r47.pppg++ <--> fiberline <--> c123.pppg++;
		r47.pppg++ <--> fiberline <--> c124.pppg++;
		r47.pppg++ <--> fiberline <--> c125.pppg++;
		r47.pppg++ <--> fiberline <--> c126.pppg++;
		r47.pppg++ <--> fiberline <--> c127.pppg++;
		r49.pppg++ <--> fiberline2G <--> r50.pppg++;
		r49.pppg++ <--> fiberline <--> c128.pppg++;
		r49.pppg++ <--> fiberline <--> c129.pppg++;
		r49.pppg++ <--> fiberline <--> c130.pppg++;
		r49.pppg++ <--> fiberline <--> c131.pppg++;
		r50.pppg++ <--> fiberline <--> c132.pppg++;
		r50.pppg++ <--> fiberline <--> c133.pppg++;
		r50.pppg++ <--> fiberline <--> c134.pppg++;
		r50.pppg++ <--> fiberline <--> c135.pppg++;
		r51.pppg++ <--> fiberline <--> c136.pppg++;
		r51.pppg++ <--> fiberline <--> c137.pppg++;
		r51.pppg++ <--> fiberline <--> c138.pppg++;
		r51.pppg++ <--> fiberline <--> c139.pppg++;
		r51.pppg++ <--> fiberline <--> c140.pppg++;
		r51.pppg++ <--> fiberline <--> c141.pppg++;
		r51.pppg++ <--> fiberline <--> c142.pppg++;
		r51.pppg++ <--> fiberline <--> c143.pppg++;
		r51.pppg++ <--> fiberline <--> c144.pppg++;
		r51.pppg++ <--> fiberline <--> c145.pppg++;
		r51.pppg++ <--> fiberline <--> c146.pppg++;
		r51.pppg++ <--> fiberline <--> c147.pppg++;
		r51.pppg++ <--> fiberline <--> c148.pppg++;
		r51.pppg++ <--> fiberline <--> c149.pppg++;
		r51.pppg++ <--> fiberline <--> c150.pppg++;
		r51.pppg++ <--> fiberline <--> c151.pppg++;
		r51.pppg++ <--> fiberline <--> c152.pppg++;
		r51.pppg++ <--> fiberline <--> c153.pppg++;
		r54.pppg++ <--> fiberline10G <--> r55.pppg++;
		r55.pppg++ <--> fiberline10G <--> r56.pppg++;
}
