#include "basicFuntions.h"
/**
 * IMAGEM
 */

void cv_gray_scale()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray,cv::COLOR_BGR2GRAY);

    cv::imshow("Imagem Original", img);
    cv::imshow("Gray Scale",imgGray);
    cv::waitKey(0);
}

void cv_gaussian_blur()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgOut;
    cv::GaussianBlur(img,imgOut,cv::Size(7,7),5,0);

    cv::imshow("Imagem Original", img);
    cv::imshow("Gaussian_Blur",imgOut);
    cv::waitKey(0);
}

void cv_Canny(){
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian;
    cv::Mat imgOut;

    
    cv::GaussianBlur(img,imgGaussian,cv::Size(7,7),5,0);
    cv::Canny(imgGaussian,imgOut,25,75);
    

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Canny",imgOut);
    cv::waitKey(0);
}


void cv_dilate(){
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian,imgCanny,imgOut;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));

    
    cv::GaussianBlur(img,imgGaussian,cv::Size(7,7),5,0);
    cv::Canny(imgGaussian,imgCanny,25,75);
    cv::dilate(imgCanny, imgOut,kernel);
    

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Dilate",imgOut);
    cv::waitKey(0);
}

void cv_erode(){
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian,imgCanny,imgDilate,imgOut;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));

    
    cv::GaussianBlur(img,imgGaussian,cv::Size(7,7),5,0);
    cv::Canny(imgGaussian,imgCanny,25,75);
    cv::dilate(imgCanny, imgDilate,kernel);
    cv::erode(imgDilate,imgOut,kernel);
    

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Erode",imgOut);
    cv::waitKey(0);
}