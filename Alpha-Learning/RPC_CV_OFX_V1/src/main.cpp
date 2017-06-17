#include "ardrone/ardrone.h"
#include "Server/RPC_drone_s.h"
#include <iostream>

// --------------------------------------------------------------------------
	// this project is used like a server so all the functions and logic is called from 
	// openframeworks client 

// --------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    // AR.Drone class
	ARDrone ardrone;
    // Initialize
    if (!ardrone.open()){
        std::cout << "Failed to initialize." << std::endl;
        return -1;
    }
	rpc_drone_s test;
	test.RPC_setup(&ardrone);
	
    ardrone.close();

    return 0;
}