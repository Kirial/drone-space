#pragma once
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iomanip>
#include "../include/zbar.h"
#include <iostream>

#define P00 1
#define P01 2
#define P02 4
#define P03 8
#define P04 16
#define P05 32

#define W0000 64 
#define W0001 128
#define W0002 256
#define W0003 512
#define W0004 1024
#define W0100 2048
#define W0101 4096
#define W0102 8192
#define W0103 16384
#define W0104 32798

#define W0200 65536
#define W0201 131072
#define W0202 262144
#define W0203 524288
#define W0204 1048576

#define W0300 2097152
#define W0301 4194304
#define W0302 8388608
#define W0303 16777216
#define W0304 33554432

using namespace std;
using namespace cv;
using namespace zbar;
#ifndef imageProccesing_H_
#define imageProccesing_H_

struct qr_struct {
	int coordinats[4][2];
	int size;
	string qr_data;
	int code;
};




class imPros {
	public: 
		int getQR(Mat frame);
		vector<RotatedRect> getElipser(Mat frame);

		// qr array 
		qr_struct array_qr[25];
private:
	vector<RotatedRect> ellipses;
	vector<vector<Point> > contours; // variable for counters 
	vector<Vec4i> hierarchy; // 
	vector<RotatedRect> minumect;
	vector<RotatedRect> minEllipse;

	//for qr

	ImageScanner scanner;
	int QRcenterX;
	int QRcenterY;

};
#endif