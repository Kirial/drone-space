#pragma once
#include "RPC_drone_Interface_h.h"
#include "ardrone/ardrone.h"
class rpc_drone_s{
public:
	void RPC_setup(ARDrone *ardrone);
private:
	ARDrone *ardrone;
};