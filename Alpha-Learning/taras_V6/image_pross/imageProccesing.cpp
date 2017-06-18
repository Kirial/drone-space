#include "imageProccesing.h"
imPros::imPros() {

}
int imPros::getQR(Mat frame) {
	string s[26] = { "P.00","P.01","P.02","P.03","P.04","P.05","W00.00","W00.01","W00.02","W00.03","W00.04","W01.00","W01.01","W01.02","W01.03","W01.04","W02.00","W02.01","W02.02","W02.03","W02.04","W03.00","W03.01","W03.02","W03.03","W03.04" };
	int code[26] = { P00,P01,P02,P03,P04,P05,W0000,W0001,W0002,W0003,W0004,W0100,W0101,W0102,W0103,W0104,W0200,W0201,W0202,W0203,W0204,W0300,W0301,W0302,W0303,W0304};
	Mat frame_grayscale;
	// Convert to grayscale
	cvtColor(frame, frame_grayscale, CV_BGR2GRAY);

	// Obtain image data
	int width = frame_grayscale.cols;
	int height = frame_grayscale.rows;
	uchar *raw = (uchar *)(frame_grayscale.data);

	// Wrap image data
	Image image(width, height, "Y800", raw, width * height);

	// Scan the image for barcodes
	scanner.scan(image);

	// Extract results
	int amount = 0;
	for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
	
		if (symbol->get_location_size() == 4) {
					array_qr[amount].qr_data = symbol->get_data();
					int l = sizeof(code)/sizeof(int);
					for (int i = 0; i < l; i++) {
						if (array_qr[amount].qr_data.compare(s[i]) == 0) {
							array_qr[amount].code = code[i];							
						}
					}
					int x1 = symbol->get_location_x(0);
					int x2 = symbol->get_location_x(1);
					int x3 = symbol->get_location_x(2);
					int x4 = symbol->get_location_x(3);
					int y1 = symbol->get_location_y(0);
					int y2 = symbol->get_location_y(1);
					int y3 = symbol->get_location_y(2);
					int y4 = symbol->get_location_y(3);
				
					array_qr[amount].x = (y2-(y4-y2)/(x4-x2)*x2-y1+(y3-y1)/(x3-x1)*x1)/((y3-y1)/(x3-x1)-(y4-y2)/(x4-x2));
					array_qr[amount].y = array_qr[amount].x*(y3 - y1) / (x3 - x1) - (y3 - y1) / (x3 - x1)*x1 + y1;
					array_qr[amount].size = sqrt((x2-x1)*(x2 - x1)+ (y2 - y1)*(y2 - y1));
					/*
					cout << "x " << array_qr[amount].x << endl;
					cout << "y " << array_qr[amount].x << endl;
					cout << symbol->get_location_x(0) << endl;
					cout << symbol->get_location_x(1) << endl;
					cout << symbol->get_location_x(2) << endl;
					cout << symbol->get_location_x(3) << endl;
					cout << symbol->get_location_y(0) << endl;
					cout << symbol->get_location_y(1) << endl;
					cout << symbol->get_location_y(2) << endl;
					cout << symbol->get_location_y(3) << endl;*/
					amount++;
		}
		
	}

	return amount;

}


vector<RotatedRect> imPros::getElipser(Mat frame) {
	cout << frame.size;
	ellipses.clear();
	contours.clear(); // variable for counters 
	hierarchy.clear(); // 
	minumect.clear();
	minEllipse.clear();
	RNG rng(12345);
	Mat threshold_output;  // new empty image


	Mat image_inv = ~frame; // invert frame 
	Mat new_img; // new empty image

	/// detect red/warm colors 
	cvtColor(image_inv, new_img, CV_BGR2HSV); // 
	Mat1b mask; // new empty image 
	inRange(new_img, Scalar(90 - 10, 70, 50), Scalar(90 + 10, 255, 255), mask); // Cyan is 90 																				/// Detect edges using Threshold
	threshold(mask, threshold_output, 100, 255, THRESH_BINARY);

	/// Find contours
	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Find the rotated rectangles and ellipses for each contour
	minumect.resize(contours.size());
	minEllipse.resize(contours.size());

	for (unsigned int i = 0; i < contours.size(); i++)
	{
		minumect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 250)
		{
			minEllipse[i] = fitEllipse(Mat(contours[i]));
		}
	}

	int k = 0;
	ellipses.resize(1);
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		if (minEllipse[i].size.width > 100 && minEllipse[i].size.height > 100) {

			ellipses[k] = minEllipse[i];
			k++;
			ellipses.resize(k+1);
		}
	}
	return ellipses;

}
