//
//  CornerDetector.h
//  HighlighterDetector
//
//  Created by Aleksander Grzyb on 24/05/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#ifndef __HighlighterDetector__CornerDetector__
#define __HighlighterDetector__CornerDetector__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define BIGGEST_AREA 6000.0f
#define A_COEFFICIENT 0
#define B_COEFFICIENT 1
#define LEFT_SIDE 0
#define RIGHT_SIDE 1

#define TOP_LEFT_POINT 0
#define TOP_RIGHT_POINT 1
#define BOTTOM_RIGHT_POINT 2
#define BOTTOM_LEFT_POINT 3

class AGCornerDetector {
    void calculateLineEquationFromPoints(vector<cv::Point>& pointVector, vector<double>& lineCoefficientVector);
    double angle(Point point1, Point point2, Point point3);
    Point calculatePointAfterCrop(vector<double> lineCoefficientVector, Point pointToMove, bool side, int distance);
    void sortCorners(vector<Point>& corners); // 0 TL, 1 TR, 2 BR, 3 BL
public:
    void findCornersInImage(Mat& image, vector<Point>& corners);
    void findSquaresInImage(Mat& image, vector<vector<Point>>& squares);
    void cropDetectedCornersInImage(Mat& image, vector<Point>& corners, int distance);
};

#endif /* defined(__HighlighterDetector__CornerDetector__) */
