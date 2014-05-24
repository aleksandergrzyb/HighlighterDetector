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
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void showImage(Mat& image)
{
    imshow("Image", image);
    waitKey(0);
}

int main(int argc, const char * argv[])
{
    // Loading image
    Mat sheetImage = imread("/Users/AleksanderGrzyb/Documents/Studia/Semestr_8/Zarzadzanie_Projektami/HighlighterDetector/SampleImages/sheet.JPG");
    showImage(sheetImage);
    return 0;
}

