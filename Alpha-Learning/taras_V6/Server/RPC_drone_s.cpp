#include "RPC_drone_s.h"
#include <iostream>
#define SCREENW 640
#define SCREENH 360
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK; // Always allow anyone.
}
ARDrone *ardrone;
imPros *image_reader;
vector<RotatedRect> elipser;
vector<int> elipser_nr;
bool elRead;
bool qr_read;
int found;


void rpc_drone_s::RPC_setup(ARDrone *_ardrone, imPros *_image_reader) {
	image_reader = _image_reader;
	ardrone = _ardrone;
	RPC_STATUS status;
	qr_read = false;
	elRead = false;

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

	elipser.clear(); // clear array from prev read
	int margin = 50; // magrin i px 
	Mat img = ardrone->getImage(); // get drone image
	vector<RotatedRect> elp; 
	bool sameE = false; 
	elp = image_reader->getElipser(img);  // get elipser 
	found = image_reader->getQR(img);  //get qr codes 
	if (found > 0) {
		qr_read = true; // whis der er qr code funedet 
	}
	int foundUE = 0;

	for (int i = 0; i < (elp.size()-1); i++) { // test from 0 to end -1
		sameE = false;  // ready to test next 
		for (int a = i+1; a < elp.size(); a++) { // test from 1 to end
			if ((elp[i].center.x - elp[a].center.x) < margin && (elp[i].center.x - elp[a].center.x) > (margin*-1) && (elp[i].center.y - elp[a].center.y) < margin && (elp[i].center.y - elp[a].center.y) > (margin*-1)) {
				// test if qr on the same x plan
				sameE = true;
				break;
			}
		}
		if (!sameE) { // there are double 
			foundUE++; // add to array 
			elipser.resize(foundUE); // change vector size 
			elipser[foundUE-1] = elp[i]; // add to array
		}

	}

	if (foundUE > 0) {
		elRead = true;
	}

	elipser_nr.resize(foundUE); // new array to save opcodes 

	int rtrn_value = 0;
	sameE = false; 
	int ukend_e = 64;
	for (int i = 0; i < elipser.size(); i++) {
		for (int a = 0; a < found; a++) {
			if (image_reader->array_qr[a].code <= P05){ // test if elipse qr found 
				if ((image_reader->array_qr[a].x - elipser[i].center.x) < margin && (image_reader->array_qr[a].x - elipser[i].center.x) > -margin){
					// test margin of elipse 
					rtrn_value = rtrn_value | image_reader->array_qr[a].code;  // add opcode to return value 
					elipser_nr[i] = image_reader->array_qr[a].code; // add opcode on the right possition
					sameE = true; 
					break;
				}
			}
		}
		if (!sameE) {
			elipser_nr[i] = ukend_e; // unknown elipse 
			rtrn_value = rtrn_value | ukend_e; // add to return value 
			ukend_e =ukend_e * 2; // ready for the next value 
		}
		sameE = false;

	}
	return rtrn_value; // return value 
}

int _askHoopX(int n) { // X position on camera
	if (!elRead) return 1337;
	for (int i = 0; i < elipser_nr.size(); i++) {
		if(elipser_nr[i] == n){
			cout << elipser[i].center.x << endl;
			return elipser[i].center.x - SCREENW;
		}
	}
	return 1337;
}

int _askHoopY(int n) {
	if (!elRead) return 1337;
	for (int i = 0; i < elipser_nr.size(); i++) {
		if (elipser_nr[i] == n) {
			cout << elipser[i].center.y << endl;
			return SCREENH-elipser[i].center.y;
		}
	}
	return 1337;
}

int _askHoopH(int n) {
	if (!elRead) return 1337;
	for (int i = 0; i < elipser_nr.size(); i++) {
		if (elipser_nr[i] == n) {
			return elipser[i].size.height;
		}
	}
	return 1337;
}

int _askHoopW(int n) {
	if (!elRead) return 1337;
	for (int i = 0; i < elipser_nr.size(); i++) {
		if (elipser_nr[i] == n) {
			return elipser[i].size.width;
		}
	}
	return 1337;
} 

  // CV - QR
int _askQR() {
	found = image_reader->getQR(ardrone->getImage());
	int rtrn_value=0;
	for (int i = 0; i < found; i++) {		
		rtrn_value = rtrn_value | image_reader->array_qr[i].code;
	}
	if(rtrn_value > 0) qr_read = true;
	return rtrn_value;

}
int _askQRX(int n) {
	if (!qr_read) return 1337;
	for (int i = 0; i < found; i++) {
		if (image_reader->array_qr[i].code == n) {
			return image_reader->array_qr[i].x - SCREENW;
		}
	}
	
	return 1337;
}
int _askQRY(int n) {
	if (!qr_read) return 1337;
	for (int i = 0; i < found; i++) {
		if (image_reader->array_qr[i].code == n) {
			return (SCREENH-image_reader->array_qr[i].y);
		}
	}
	return 1337;
}
int _askQRsize(int n) {
	if (!qr_read) return 1337;
	for (int i = 0; i < found; i++) {
		if (image_reader->array_qr[i].code == n) {
			return image_reader->array_qr[i].size;
		}
	}
	return 1337;
}

int _askYaw() {
	double yaw = ardrone->getYaw() * RAD_TO_DEG * 1000;
	return (int)yaw;
}


// Drone Sensors
int _askPitch() {
	double tempPitch = ardrone->getPitch() * RAD_TO_DEG * 1000;
	return (int)tempPitch;
}

int _askRoll() {
	double tempRoll = ardrone->getRoll() * RAD_TO_DEG * 1000;
	return (int)tempRoll;

}

// Drone Sensors
int _askHeight() {
	double tempH = ardrone->getAltitude();
	return (int)tempH * 100;
}

// Drone Instructions (True, ready to move, false can't move now)
int _instruct(int x, int y, int z, int alfa) {
	double vx = x / 100;
	double vy = y / 100;
	double vz = z / 100;
	double vr = (alfa / 180)*3.14;
	ardrone->move3D(vx, vy, vz, vr);
	return 1;
}

int _takeOff(){
	ardrone->takeoff();
	return 1;
}

int _land() {
	ardrone->landing();
	return 0;
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