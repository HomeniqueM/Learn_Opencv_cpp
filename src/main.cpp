#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "includes/basicFuntions.h"

/**
 * IMAGEM
 */
void inputopencv()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images

    cv::imshow("Leitura de Imagem", img);
    cv::waitKey(0);
}

/**
 * @brief Um video pode ser é basicamente uma sequencia de imagens
 * então a leitura de video de seguir esse pensamento
 *
 */
void inputVideosOpenCV()
{
    std::string path = "imgs/nomeDoArquivo.mp4";
    cv::Mat image;
    cv::VideoCapture cap(path);
    while (true)
    {   cap.read(image);
        cv::imshow("Leitura de Imagem", image);
        cv::waitKey(20);
    }
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, char const *argv[])
{
    cv_warp_perspective();

    return 0;
}
