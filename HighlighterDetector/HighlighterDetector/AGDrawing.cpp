//
//  AGDrawing.cpp
//  HighlighterDetector
//
//  Created by Aleksander Grzyb on 25/05/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include "AGDrawing.h"

using namespace cv;
using namespace std;

void AGDrawing::drawCornersInImage(Mat& image, vector<Point> imageCorners)
{
    circle(image, imageCorners[0], 10, cv::Scalar(255, 0, 0), 4);
    circle(image, imageCorners[1], 10, cv::Scalar(0, 255, 255), 4);
    circle(image, imageCorners[2], 10, cv::Scalar(255, 255, 0), 4);
    circle(image, imageCorners[3], 10, cv::Scalar(255, 0, 255), 4);
}