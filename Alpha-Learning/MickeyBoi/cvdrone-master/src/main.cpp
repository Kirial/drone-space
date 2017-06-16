#include "ardrone/ardrone.h"
//#include "opencv2/imagecodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iomanip>

#include "3rdparty\zbar\include\zbar.h"
#include <iostream>  
//#include "3rdparty\imageMagick\include\Magick++.h"
using namespace std;
using namespace zbar;
using namespace cv;


int live[12][4];
string QR_decoded;
int circle_qr = 0;

int totalCircles = 0;
int sliderPos = 70;
Mat img;
Mat image;
/// Function header
int circle_x(int circle_num);
int circle_y(int circle_num);
int circle_w(int circle_num);
int circle_h(int circle_num);
int found_circles();
void thresh_callback(int, void*);
string decoded_QR();

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);


Mat frame; Mat frame_grayscale;
// --------------------------------------------------------------------------
// main(Number of arguments, Argument values)
// Description  : This is the entry point of the program.
// Return value : SUCCESS:0  ERROR:-1
// --------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ImageScanner scanner;
    // AR.Drone class
    ARDrone ardrone;

    // Initialize
    if (!ardrone.open()) {
        cout << "Failed to initialize." << endl;
        return -1;
    }

    // Battery
    cout << "Battery = " << ardrone.getBatteryPercentage() << "[%]" << endl;

	/*
    // Instructions
    cout << "***************************************" << endl;
    cout << "*       CV Drone sample program       *" << endl;
    cout << "*           - How to play -           *" << endl;
    cout << "***************************************" << endl;
    cout << "*                                     *" << endl;
    cout << "* - Controls -                        *" << endl;
    cout << "*    'Space' -- Takeoff/Landing       *" << endl;
    cout << "*    'Up'    -- Move forward          *" << endl;
    cout << "*    'Down'  -- Move backward         *" << endl;
    cout << "*    'Left'  -- Turn left             *" << endl;
    cout << "*    'Right' -- Turn right            *" << endl;
    cout << "*    'Q'     -- Move upward           *" << endl;
    cout << "*    'A'     -- Move downward         *" << endl;
    cout << "*                                     *" << endl;
    cout << "* - Others -                          *" << endl;
    cout << "*    'C'     -- Change camera         *" << endl;
    cout << "*    'Esc'   -- Exit                  *" << endl;
    cout << "*                                     *" << endl;
    cout << "***************************************" << endl;
	*/

	// Configure the reader
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	while (1) {
		// Key input
		int key = waitKey(33);
		if (key == 0x1b) break;

		// Get an image
		//Mat image = ardrone.getImage();

			// Get an image
			frame = ardrone.getImage();

			img = frame;

			/***********************************************THIS IS FOR QR-DECODING*******************************************/
			// Convert to grayscale
			cvtColor(frame, frame_grayscale, CV_BGR2GRAY);

			// Obtain image data
			int width = frame_grayscale.cols;
			int height = frame_grayscale.rows;
			uchar *raw = (uchar *)(frame_grayscale.data);

			// Wrap image data
			Image image(width, height, "Y800", raw, width * height);

			// Scan the image for barcodes
			//int n = scanner.scan(image);
			scanner.scan(image);

			// Extract results
			int counter = 0;
			for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
				time_t now;
				tm *current;
				now = time(0);
				current = localtime(&now);

				// do something useful with results
				cout << "[" << current->tm_hour << ":" << current->tm_min << ":" << setw(2) << setfill('0') << current->tm_sec << "] " << counter << " "
					<< "decoded " << symbol->get_type_name()
					<< " symbol \"" << symbol->get_data() << '"' << endl;

				//cout << "Location: (" << symbol->get_location_x(0) << "," << symbol->get_location_y(0) << ")" << endl;
				//cout << "Size: " << symbol->get_location_size() << endl;

				// Draw location of the symbols found
				if (symbol->get_location_size() == 4) {
					//rectangle(frame, Rect(symbol->get_location_x(i), symbol->get_location_y(i), 10, 10), Scalar(0, 255, 0));
					line(frame, Point(symbol->get_location_x(0), symbol->get_location_y(0)), Point(symbol->get_location_x(1), symbol->get_location_y(1)), Scalar(0, 255, 0), 2, 8, 0);
					line(frame, Point(symbol->get_location_x(1), symbol->get_location_y(1)), Point(symbol->get_location_x(2), symbol->get_location_y(2)), Scalar(0, 255, 0), 2, 8, 0);
					line(frame, Point(symbol->get_location_x(2), symbol->get_location_y(2)), Point(symbol->get_location_x(3), symbol->get_location_y(3)), Scalar(0, 255, 0), 2, 8, 0);
					line(frame, Point(symbol->get_location_x(3), symbol->get_location_y(3)), Point(symbol->get_location_x(0), symbol->get_location_y(0)), Scalar(0, 255, 0), 2, 8, 0);
				}

				// Get points
				/*for (Symbol::PointIterator point = symbol.point_begin(); point != symbol.point_end(); ++point) {
					cout << point << endl;
				} */
				counter++;
			}

			// Show captured frame, now with overlays!
			imshow("captured", frame);
			/******************************************************************************************************************/
			
			
			
			if (img.empty()) cerr << "empty image!" << endl;
			cvtColor(img, src_gray, CV_BGR2GRAY);
			blur(src_gray, src_gray, Size(3, 3));

			/// Create Window
			char* source_window = "Source";
			namedWindow(source_window, CV_WINDOW_AUTOSIZE);
			//imshow(source_window, image);

			createTrackbar(" Threshold:", "Source", &thresh, max_thresh, thresh_callback);
			thresh_callback(0, 0);

			if (key == ' ') {
				cout << "amount of circles found: " << found_circles() << endl;
				for (int i = 0; i < 4; i++) {
					cout << "circla data:" << endl;
					cout << "circle x:      " << circle_x(1) << endl;
					cout << "circla y:	    " << circle_y(1) << endl;
					cout << "circla width:  " << circle_w(1) << endl;
					cout << "circla height: " << circle_h(1) << endl;
				}
			}



			/*********************FOR DRONE CONTROL*************************
			// Take off / Landing
			if (key == ' ') {
				if (ardrone.onGround()) ardrone.takeoff();
				else                    ardrone.landing();
			}

			// Move
			double vx = 0.0, vy = 0.0, vz = 0.0, vr = 0.0;
			if (key == 'i' || key == CV_VK_UP)    vx = 1.0;
			if (key == 'k' || key == CV_VK_DOWN)  vx = -1.0;
			if (key == 'u' || key == CV_VK_LEFT)  vr = 1.0;
			if (key == 'o' || key == CV_VK_RIGHT) vr = -1.0;
			if (key == 'j') vy = 1.0;
			if (key == 'l') vy = -1.0;
			if (key == 'q') vz = 1.0;
			if (key == 'a') vz = -1.0;
			ardrone.move3D(vx, vy, vz, vr);

			// Change camera
			static int mode = 0;
			if (key == 'c') ardrone.setCamera(++mode % 4);

			/***********************************************************/


			// Display the image
			Mat gray;

			cvtColor(img, gray, COLOR_BGR2GRAY);
			medianBlur(gray, gray, 5);
			vector<Vec3f> circles;
			HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
				gray.rows / 16, // change this value to detect circles with different distances to each other
				100, 30, 1, 30 // change the last two parameters
							   // (min_radius & max_radius) to detect larger circles
			);
			for (size_t i = 0; i < circles.size(); i++)
			{
				Vec3i c = circles[i];
				circle(img, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
				circle(img, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
			}
			imshow("detected circles", img);

			//imshow("camera", img);
	}



	// See you
	ardrone.close();

	return 0;
}


void thresh_callback(int, void*)
{

	int count = 0;
	int totalCircles = 0;

	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using Threshold
	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);
	/// Find contours
	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Find the rotated rectangles and ellipses for each contour
	vector<RotatedRect> minumect(contours.size());
	vector<RotatedRect> minEllipse(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		minumect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 5)
		{
			minEllipse[i] = fitEllipse(Mat(contours[i]));
		}
	}

	/// Draw contours + rotated rects + ellipses
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{

		Scalar color = Scalar(rng.uniform(255, 255), rng.uniform(255, 255), rng.uniform(255, 255));
		// contour
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		// ellipse
		if (minEllipse[i].size.width > 30 && minEllipse[i].size.height > 30) {
			//if (minEllipse[i].size.width < 200 && minEllipse[i].size.height > 400) {
			ellipse(drawing, minEllipse[i], color, 2, 8);
			totalCircles++;
			count++;
			switch (circle_qr) {
			case 1:
				count--;
				live[0][0] = minEllipse[i].center.x;
				live[0][1] = minEllipse[i].center.y;
				live[0][2] = minEllipse[i].size.width;
				live[0][3] = minEllipse[i].size.height;
				break;
			case 2:
				count--;
				live[1][0] = minEllipse[i].center.x;
				live[1][1] = minEllipse[i].center.y;
				live[1][2] = minEllipse[i].size.width;
				live[1][3] = minEllipse[i].size.height;
				break;
			case 3:
				count--;
				live[2][0] = minEllipse[i].center.x;
				live[2][1] = minEllipse[i].center.y;
				live[2][2] = minEllipse[i].size.width;
				live[2][3] = minEllipse[i].size.height;
				break;
			case 4:
				count--;
				live[3][0] = minEllipse[i].center.x;
				live[3][1] = minEllipse[i].center.y;
				live[3][2] = minEllipse[i].size.width;
				live[3][3] = minEllipse[i].size.height;
				break;
			case 5:
				count--;
				live[4][0] = minEllipse[i].center.x;
				live[4][1] = minEllipse[i].center.y;
				live[4][2] = minEllipse[i].size.width;
				live[4][3] = minEllipse[i].size.height;
				break;
			case 6:
				count--;
				live[5][0] = minEllipse[i].center.x;
				live[5][1] = minEllipse[i].center.y;
				live[5][2] = minEllipse[i].size.width;
				live[5][3] = minEllipse[i].size.height;
				break;
			case 0:
				if (count < 7) {
					live[count + 5][0] = minEllipse[i].center.x;
					live[count + 5][1] = minEllipse[i].center.y;
					live[count + 5][2] = minEllipse[i].size.width;
					live[count + 5][3] = minEllipse[i].size.height;
				}
				break;
			default:
				break;
			}
			//}
		}
		// rotated rectangle
		Point2f rect_points[4]; minumect[i].points(rect_points);
		for (int j = 0; j < 4; j++)
			line(drawing, rect_points[j], rect_points[(j + 1) % 4], color, 1, 8);
	}

	/// Show in a window
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
}

int circle_x(int circle_num) {

	int tmp[12][4];

	//tmp = live;

	return live[circle_num][0];
}

int circle_y(int circle_num) {

	int tmp[12][4];

	//tmp = live;

	return live[circle_num][1];
}

int circle_w(int circle_num) {

	int tmp[12][4];

	//tmp = live;

	return live[circle_num][2];
}

int circle_h(int circle_num) {

	int tmp[12][4];

	//tmp = live;

	return live[circle_num][3];
}

int found_circles() {

	return totalCircles;
}

string decoded_QR() {
	return QR_decoded;
}

