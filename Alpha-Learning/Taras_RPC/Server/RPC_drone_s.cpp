#include "RPC_drone_s.h"
#include <iostream>
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK; // Always allow anyone.
}

void rpc_drone_s::RPC_setup(ARDrone *_ardrone) {
	ardrone = _ardrone;
	RPC_STATUS status;

	// Uses the protocol combined with the endpoint for receiving
	// remote procedure calls.
	status = RpcServerUseProtseqEpA(
		(RPC_CSTR)("ncacn_ip_tcp"), // Use TCP/IP protocol.
		RPC_C_PROTSEQ_MAX_REQS_DEFAULT, // Backlog queue length for TCP/IP.
		(RPC_CSTR)("4747"), // TCP/IP port to use.
		NULL); // No security.

	if (status)
		exit(status);

	// Registers the Example1 interface.
	status = RpcServerRegisterIf2(
		cv_drone_int_v1_0_s_ifspec, // Interface to register.
		NULL, // Use the MIDL generated entry-point vector.
		NULL, // Use the MIDL generated entry-point vector.
		RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, // Forces use of security callback.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT, // Use default number of concurrent calls.
		(unsigned)-1, // Infinite max size of incoming data blocks.
		SecurityCallback); // Naive security callback.

	if (status)
		exit(status);

	// Start to listen for remote procedure
	// calls for all registered interfaces.
	// This call will not return until
	// RpcMgmtStopServerListening is called.
	status = RpcServerListen(
		1, // Recommended minimum number of threads.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT, // Recommended maximum number of threads.
		FALSE); // Start listening now.

	if (status)
		exit(status);
}

int _askHoops() {
	std::cout << 1 << std::endl;
	return 1;
}

int _askHoopX(int n) { // X position on camera
	std::cout << n << std::endl;
	return n;
}

int _askHoopY(int n) {
	std::cout << n << std::endl;
	return n;
} // Y position on camera

int _askHoopH(int n) {
	std::cout << n << std::endl;
	return n;
} // Vertical Radius

int _askHoopW(int n) {
	std::cout << n << std::endl;
	return n;
} // Horizontal Radius

  // CV - QR
int _askQR() {
	std::cout << 6 << std::endl;
	return 6;
}
int _askQRX(int n) {
	std::cout << n << std::endl;
	return n;
}
int _askQRY(int n) {
	std::cout << n << std::endl;
	return n;
}
int _askQRsize(int n) {
	std::cout << n << std::endl;
	return n;
}

int _askYaw() {
	double yaw = ardrone->getYaw() * RAD_TO_DEG * 1000;
	return (int)yaw;
}

// Drone Instructions (True, ready to move, false can't move now)
int _instruct(int x, int y, int z, int alfa) {
	double vx = x/100;
	double vy = y/100;
	double vz = z/100;
	double vr = (alfa/180)*3.14;
	ardrone->move3D(vx, vy, vz,  vr);
	return 1;
}


// Drone Sensors
int _askPitch() {
	std::cout << 12 << std::endl;
	return 12;
}

int _askRoll() {
	std::cout << 13 << std::endl;
	return 13;
}

// Drone Sensors
int _askHeight() {
	std::cout << 14 << std::endl;
	return 14;
}








void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
	free(p);
}