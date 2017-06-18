#ifndef CV_H
#define CV_H
#include "Klient/RPC_drone.h"
class CV {

public:
	rpc_drone *rpc;
	CV(rpc_drone *_rpc) { rpc = _rpc; }

  // CV - Hoops
  int askHoops() {return rpc->askHoops();}
  int askHoopX(int n) {return rpc->askHoopX(n);} // X position on camera
  int askHoopY(int n) {return rpc->askHoopY(n);} // Y position on camera
  int askHoopH(int n) {return rpc->askHoopH(n);} // Vertical Radius
  int askHoopW(int n) {return rpc->askHoopW(n);} // Horizontal Radius

  // CV - QR
  int askQRs() {return rpc->askQR();}
  int askQRX(int n) {return rpc->askQRX(n);}
  int askQRY(int n) {return rpc->askQRY(n);}
  int askQRsize(int n) {return rpc->askQRsize(n);}

};

#endif /* end of include guard: CV_H */
