#ifndef BASICFUNTIONS
#define BASICFUNTIONS
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void cv_gray_scale();
void cv_gaussian_blur();
void cv_Canny();
void cv_dilate();
void cv_erode();
void cv_resize();
void cv_crop();
cv::Mat empty_image8bits();
void cv_circle_drawing();

#endif