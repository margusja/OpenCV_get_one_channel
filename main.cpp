//
//  main.cpp
//  opencv_get_one_channel
//
//  Created by Margusja on 15/11/2017.
//  Copyright © 2017 Margusja. All rights reserved.
//

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

int main() {
    
    // Load an color image in grayscale
    Mat img = imread("/Users/margusja/Pictures/faces/margusja2.jpg", CV_LOAD_IMAGE_COLOR);
    Mat rgb[3];   //destination array
    split(img,rgb);
    
    //by default opencv put channels in BGR order , so in your situation you want to copy the first channel which is blue. Set green and red channels elements to zero.
    rgb[1]=Mat::zeros(img.rows, img.cols, CV_8UC1); // green channel is set to 0
    rgb[2]=Mat::zeros(img.rows, img.cols, CV_8UC1);// red channel is set to 0
    
    //then merge them back
    Mat out;
    merge(rgb,3,out);
    
    std::cout << "Channels: " << out.channels() << endl;
    std::cout << "Type: " << out.type() << endl;
    
    cv::Size s = out.size();
    int rows = s.height;
    int cols = s.width;
    
    cout << "Image heigth: " << rows << " cols: " << cols << endl;
    
    imshow("blue channel",out);
    
    waitKey(0);
    
    //waitKey( 0 );
    return(0);
}


