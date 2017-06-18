#pragma once
#include "RPC_drone_Interface_h.h"
#include "../ardrone/ardrone.h"
#include "../image_pross/imageProccesing.h"
class rpc_drone_s{
public:
	void RPC_setup(ARDrone *ardrone, imPros *image_reader);
};