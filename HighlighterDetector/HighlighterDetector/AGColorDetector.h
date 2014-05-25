//
//  AGColorDetector.h
//  HighlighterDetector
//
//  Created by Aleksander Grzyb on 25/05/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#ifndef __HighlighterDetector__AGColorDetector__
#define __HighlighterDetector__AGColorDetector__

#include <iostream>
#include <opencv2/opencv.hpp>

class AGColorDetector {
public:
    void detectGreenColorInImage(cv::Mat& image);
};

#endif /* defined(__HighlighterDetector__AGColorDetector__) */
