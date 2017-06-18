#ifndef FLIGHT_H
#define FLIGHT_H
#include "Klient\RPC_drone.h"

class ARDrone{

public:	
		rpc_drone *rpc;
		ARDrone(rpc_drone *_rpc) { rpc = _rpc; }
		int askYaw() { return rpc->askYaw(); }
		int askRoll() {return rpc->askRoll();}
		int askPitch() {return rpc->askPitch();}
		int askHeight() {return rpc->askHeight();}
		int instruct(float x, float y, float z, float a) {return rpc->inctruct((x*100),(y*100),(z*100),(a*50));}
		int land() { return rpc->land(); }
		int takeoff() { return rpc->takeOff(); }

};

#endif /* end of include guard: FLIGHT_H */
