//
//  AGColorDetector.cpp
//  HighlighterDetector
//
//  Created by Aleksander Grzyb on 25/05/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include "AGColorDetector.h"
#include <stdio.h>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void AGColorDetector::detectGreenColorInImage(cv::Mat& image, cv::Mat& outputImage)
{
    int lowHue = 40, highHue = 50;
    int lowSaturation = 0, highSaturation = 255;
    int lowValue = 0, highValue = 255;

    Mat blurredImage, hsvImage;
    medianBlur(image, blurredImage, 5);
    cvtColor(blurredImage, hsvImage, CV_BGR2HSV);
    inRange(hsvImage, Scalar(lowHue, lowSaturation, lowValue), Scalar(highHue, highSaturation, highValue), outputImage);
    morphologyEx(outputImage, outputImage, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(9, 9)));
    cvtColor(outputImage, outputImage, CV_GRAY2BGR);
}

void AGColorDetector::findGreenColorAreaInImage(cv::Mat& image, cv::Mat& outputImage, std::vector<cv::Point>& greenArea)
{
    int treshold = 100;
    Mat processingImage;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    cvtColor(image, processingImage, CV_BGR2GRAY);
    Canny(processingImage, processingImage, treshold, 2 * treshold);
    findContours(processingImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    int maxContourArea = 0, maxContourIndex = 0;
    for(int i = 0; i < contours.size(); i++) {
        if (maxContourArea < contourArea(contours[i], false)) {
            maxContourArea = contourArea(contours[i], false);
            maxContourIndex = i;
        }
    }
    Mat drawing = Mat::zeros(processingImage.size(), CV_8UC3);
    drawContours(outputImage, contours, maxContourIndex, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
}












