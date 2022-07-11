#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

void inputopencv(){
   std::string path = "imgs/trigulos.jpg";
   cv::Mat img = cv::imread(path);// Matriz para lidar com images 

   cv::imshow("Leitura de Imagem",img);
   cv::waitKey(0);
}



int main(int argc, char const *argv[])
{
    inputopencv();

    return 0;
}
