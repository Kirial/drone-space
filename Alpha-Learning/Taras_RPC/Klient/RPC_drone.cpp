#include "RPC_drone.h" 
#include <iostream>
#include "RPC_drone_interface_h.h" // man skal være sikker på at det er den rigtig path man angiver 

RPC_STATUS status;
RPC_CSTR szStringBinding = NULL;


void rpc_drone::rpc_innit() {
	status = RpcStringBindingComposeA(
		NULL, // UUID to bind to.
		(RPC_CSTR)("ncacn_ip_tcp"), // Use TCP/IP protocol.
		(RPC_CSTR)("localhost"), // TCP/IP network address to use.
		(RPC_CSTR)("4747"), // TCP/IP port to use.
		NULL, // Protocol dependent network options to use.
		&szStringBinding); // String binding output.

	if (status)
		std::exit(status);

	// Validates the format of the string binding handle and converts
	// it to a binding handle.
	// Connection is not done here either.
	status = RpcBindingFromStringBindingA(
		szStringBinding, // The string binding to validate.
		&hcv_drone_intBinding); // Put the result in the implicit binding
								// handle defined in the IDL file.

	if (status)
		std::exit(status);
}

void rpc_drone::rpc_exit() {
	// Releases binding handle resources and disconnects from the server.
	status = RpcBindingFree(
		&hcv_drone_intBinding); // Frees the implicit binding handle defined in the IDL file.
	if (status)
		std::exit(status);
}

int rpc_drone::askHoop() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoop();
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}

int rpc_drone::askHoopX(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopX(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
} // X position on camera

int rpc_drone::askHoopY(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopY(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
} // Y position on camera


int rpc_drone::askHoopRa(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopRa(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
} // Vertical Radius

int rpc_drone::askHoopRb(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopRb(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
} // Horizontal Radius

					  // CV - QR
int rpc_drone::askQR() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askQR();
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}

int rpc_drone::askQRX(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askQRX(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::askQRY(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askQRY(n);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}

// Drone Sensors
int rpc_drone::askHeight() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHeight();
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}

int rpc_drone::askMagnetometerOrientation() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askMagnetometerOrientation();
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}

// Drone Instructions (True, ready to move, false can't move now)
int rpc_drone::tellMove(int x, int y, int z) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellMove(x, y, z);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::tellTurn(int a) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellTurn(a);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::tellSetSpeed(int ms) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellSetSpeed(ms);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::tellForceMove(int x, int y, int z) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellForceMove(x, y, z);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::tellForceTurn(int a) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellForceTurn(a);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}
int rpc_drone::tellForceSetSpeed(int ms) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _tellForceSetSpeed(ms);
	}
		RpcExcept(1)
	{
		std::cerr << "Runtime reported exception " << RpcExceptionCode()
			<< std::endl;
		return -1;
	}
	RpcEndExcept

		// Free the memory allocated by a string.
		status = RpcStringFreeA(
			&szStringBinding); // String to be freed.

	if (status)
		std::exit(status);

	return rtn_nr;
}




//functioner som skal bruges af rpc... jeg ved ikke noget om det
void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
	free(p);
}