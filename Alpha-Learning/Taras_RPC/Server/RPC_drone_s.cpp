#include "RPC_drone_s.h"
#include <iostream>
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK; // Always allow anyone.
}

void rpc_drone_s::RPC_setup() {
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

int _askHoop() {
	std::cout << 1 << std::endl;
	return -1;
}

int _askHoopX(int n) { // X position on camera
	std::cout << n << std::endl;
	return -1;
}

int _askHoopY(int n) {
	std::cout << n << std::endl;
	return -1;
} // Y position on camera

int _askHoopRa(int n) {
	std::cout << n << std::endl;
	return -1;
} // Vertical Radius

int _askHoopRb(int n) {
	std::cout << n << std::endl;
	return -1;
} // Horizontal Radius

  // CV - QR
int _askQR() {
	std::cout << 6 << std::endl;
	return -1;
}
int _askQRX(int n) {
	std::cout << n << std::endl;
	return -1;
}
int _askQRY(int n) {
	std::cout << n << std::endl;
	return -1;
}

// Drone Sensors
int _askHeight() {
	std::cout << 9 << std::endl;
	return -1;
}
int _askMagnetometerOrientation() {
	std::cout << 10 << std::endl;
	return -1;
}

int _askAngle() {
	return 100;
}

// Drone Instructions (True, ready to move, false can't move now)
int _tellMove(int x, int y, int z) {
	std::cout << x << std::endl;
	return -1;
}

int _tellTurn(int a) {
	std::cout << a << std::endl;
	return -1;
}
int _tellSetSpeed(int ms) {
	std::cout << ms << std::endl;
	return -1;
}
int _tellForceMove(int x, int y, int z) {
	std::cout << x << std::endl;
	return -1;
}
int _tellForceTurn(int a) {
	std::cout << a << std::endl;
	return -1;
}
int  _tellForceSetSpeed(int ms) {
	std::cout << ms << std::endl;
	return -1;
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