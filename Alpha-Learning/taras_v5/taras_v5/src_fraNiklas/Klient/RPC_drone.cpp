#include "RPC_drone.h" 
#include <iostream>
#include "RPC_drone_interface_h.h" // man skal være sikker på at det er den rigtig path man angiver 

RPC_STATUS status;
RPC_CSTR szStringBinding = NULL;

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////             ///////////////////////////////////////*/
/*//////////////////////////////////////////   SET UP    ///////////////////////////////////////*/
/*//////////////////////////////////////////             ///////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/


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

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////   elipse functions   //////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/


int rpc_drone::askHoops() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoops();
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

int rpc_drone::askHoopH(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopH(n);
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

int rpc_drone::askHoopW(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askHoopW(n);
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




/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////       CV QR code     //////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/

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

int rpc_drone::askQRsize(int n) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askQRsize(n);
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


/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////     DRone Sensors    //////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
int rpc_drone::askYaw() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askYaw();
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

int rpc_drone::askPitch() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askPitch();
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

int rpc_drone::askRoll() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _askRoll();
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

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////     DRone Control    //////////////////////////////*/
/*//////////////////////////////////////////                      //////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////*/

int rpc_drone::inctruct(int x, int y, int z, int alfa) {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _inctruct(x, y, z,alfa);
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
int rpc_drone::takeOff() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _takeOff();
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
int rpc_drone::land() {
	int rtn_nr;
	RpcTryExcept
	{
		rtn_nr = _land();
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