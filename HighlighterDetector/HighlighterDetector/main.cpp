//
//  main.cpp
//  HighlighterDetector
//
//  Created by Aleksander Grzyb on 24/05/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "CornerDetector.h"

using namespace cv;
using namespace std;

void showImage(Mat& image)
{
    imshow("Image", image);
    waitKey(0);
}

void drawCornersInImage(Mat& image, vector<Point> imageCorners)
{
    circle(image, imageCorners[0], 10, cv::Scalar(255, 0, 0), 4);
    circle(image, imageCorners[1], 10, cv::Scalar(0, 255, 255), 4);
    circle(image, imageCorners[2], 10, cv::Scalar(255, 255, 0), 4);
    circle(image, imageCorners[3], 10, cv::Scalar(255, 0, 255), 4);
}


int main(int argc, const char * argv[])
{
    // Loading image
    Mat sheetImage = imread("/Users/AleksanderGrzyb/Documents/Studia/Semestr_8/Zarzadzanie_Projektami/HighlighterDetector/SampleImages/sheet.JPG");
    vector<Point> corners;
    AGCornerDetector cornerDetector;
    cornerDetector.findCornersInImage(sheetImage, corners);
    cornerDetector.cropDetectedCornersInImage(sheetImage, corners, 100);
    Mat croppedImage = sheetImage(Rect(corners[TOP_LEFT_POINT].x, corners[TOP_LEFT_POINT].y, corners[TOP_RIGHT_POINT].x - corners[TOP_LEFT_POINT].x, corners[BOTTOM_LEFT_POINT].y - corners[TOP_LEFT_POINT].y));
    resize(croppedImage, croppedImage, Size(croppedImage.size().width * 0.2, croppedImage.size().height * 0.2));
    showImage(croppedImage);
    return 0;
}

