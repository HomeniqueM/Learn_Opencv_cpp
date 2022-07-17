#include "basicFuntions.h"
/**
 * IMAGEM
 */

void cv_gray_scale()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    cv::imshow("Imagem Original", img);
    cv::imshow("Gray Scale", imgGray);
    cv::waitKey(0);
}

void cv_gaussian_blur()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgOut;
    cv::GaussianBlur(img, imgOut, cv::Size(7, 7), 5, 0);

    cv::imshow("Imagem Original", img);
    cv::imshow("Gaussian_Blur", imgOut);
    cv::waitKey(0);
}

void cv_Canny()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian;
    cv::Mat imgOut;

    cv::GaussianBlur(img, imgGaussian, cv::Size(7, 7), 5, 0);
    cv::Canny(imgGaussian, imgOut, 25, 75);

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Canny", imgOut);
    cv::waitKey(0);
}

void cv_dilate()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian, imgCanny, imgOut;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    cv::GaussianBlur(img, imgGaussian, cv::Size(7, 7), 5, 0);
    cv::Canny(imgGaussian, imgCanny, 25, 75);
    cv::dilate(imgCanny, imgOut, kernel);

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Dilate", imgOut);
    cv::waitKey(0);
}

void cv_erode()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgGaussian, imgCanny, imgDilate, imgOut;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    cv::GaussianBlur(img, imgGaussian, cv::Size(7, 7), 5, 0);
    cv::Canny(imgGaussian, imgCanny, 25, 75);
    cv::dilate(imgCanny, imgDilate, kernel);
    cv::erode(imgDilate, imgOut, kernel);

    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem Erode", imgOut);
    cv::waitKey(0);
}

void cv_resize()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgRezise, imgRezise2;
    std::cout << "Tamanho da imagem origina: " << img.size() << "\n";

    // Maneira 1
    cv::resize(img, imgRezise, cv::Size(500, 500));
    std::cout << "Novo tamanho da imagem: " << imgRezise.size() << "\n";

    // Maneira 2 Desta forma vai ser feitro uma escala por proporcionalidade
    cv::resize(img, imgRezise2, cv::Size(), 0.20, 0.20);
    std::cout << "Novo tamanho da imagem: " << imgRezise2.size() << "\n";

    cv::imshow("Imagem Original", img);
    cv::imshow("Resize 1", imgRezise);
    cv::imshow("Resize 2 20% do tamanho", imgRezise2);
    cv::waitKey(0);
}

void cv_crop()
{
    std::string path = "imgs/trigulos.jpg";
    cv::Mat img = cv::imread(path); // Matriz para lidar com images
    cv::Mat imgCrop;
    cv::Rect roi(0, 0, 300, 300);

    imgCrop = img(roi);
    cv::imshow("Imagem Original", img);
    cv::imshow("CROP", imgCrop);
    cv::waitKey(0);
}

/**
 * Como desenhar formas e letras em uma imagem
 *
 */

cv::Mat empty_image8bits(int height, int width)
{
    cv::Mat img(height, width, CV_8UC3, cv::Scalar(40, 33, 28));
    return img;
}

void cv_circle_drawing()
{
    cv::Mat img = empty_image8bits(512, 512);
    cv::imshow("Imagem Vazia", img);

    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255));
    cv::imshow("Imagem com um circulo", img);
    // Aumentar a borda
    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255), 10);
    cv::imshow("Imagem com um circulo borda +10", img);

    // Preencher o circulo
    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255), cv::FILLED);
    cv::imshow("Imagem com um circulo preenchido", img);

    cv::waitKey(0);
}

void cv_rectangle_drawing()
{
    cv::Mat img = empty_image8bits(512, 512);

    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255), cv::FILLED);
    cv::rectangle(img, cv::Point(130, 226), cv::Point(382, 286), cv::Scalar(255, 255, 255), cv::FILLED);
    cv::imshow("Imagem com um Retângulo", img);
    // Aumentar a borda
    cv::waitKey(0);
}

void cv_line_drawing()
{
    cv::Mat img = empty_image8bits(512, 512);
    // imagem, ponto inicial (x,y) ponto final (x,y)
    cv::line(img, cv::Point(130, 296), cv::Point(382, 296), cv::Scalar(0, 0, 255), 5);
    cv::line(img, cv::Point(130, 296), cv::Point(130, 100), cv::Scalar(216, 140, 26), 5);
    cv::line(img, cv::Point(130, 100), cv::Point(382, 296), cv::Scalar(0, 255, 0), 5);
    cv::imshow("Line", img);
    cv::waitKey(0);
}

void cv_text_drawing()
{
    cv::Mat img = empty_image8bits(512, 512);

    // imagem, ponto inicial (x,y) ponto final (x,y)
    cv::line(img, cv::Point(130, 296), cv::Point(382, 296), cv::Scalar(0, 69, 255), 3);
    cv::rectangle(img, cv::Point(70, 200), cv::Point(457, 286), cv::Scalar(255, 255, 255), cv::FILLED);
    cv::putText(img, "Hello World", cv::Point(70, 262), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 69, 255), 2);
    cv::imshow("Line", img);
    cv::waitKey(0);
}

void cv_warp_perspective()
{
    float width = 250, height = 350;
    cv::Mat matrix, imgWarp, imgWarpQueen, imgWarpJack;
    std::string path = "imgs/cards.jpg";
    cv::Mat img = cv::imread(path);

    // Point com ponto flutuante
    cv::Point2f srcKing[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    cv::Point2f srcQueen[4] = {{64, 328}, {338, 280}, {90, 634}, {404, 571}};
    cv::Point2f srcJack[4] = {{776, 110}, {1019, 84}, {842, 357}, {1116, 330}};
    cv::Point2f dst[4] = {{0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height}};

    // Transformação
    matrix = cv::getPerspectiveTransform(srcKing, dst);
    cv::warpPerspective(img, imgWarp, matrix, cv::Point(width, height));

    matrix = cv::getPerspectiveTransform(srcQueen, dst);
    cv::warpPerspective(img, imgWarpQueen, matrix, cv::Point(width, height));

    matrix = cv::getPerspectiveTransform(srcJack, dst);
    cv::warpPerspective(img, imgWarpJack, matrix, cv::Point(width, height));

    for (int i = 0; i < 4; i++)
    {
        cv::circle(img, srcKing[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
        cv::circle(img, srcQueen[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
        cv::circle(img, srcJack[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    cv::line(img, srcKing[0], srcKing[1], cv::Scalar(0, 0, 255), 3);
    cv::line(img, srcKing[0], srcKing[2], cv::Scalar(0, 0, 255), 3);
    cv::line(img, srcKing[1], srcKing[3], cv::Scalar(0, 0, 255), 3);
    cv::line(img, srcKing[2], srcKing[3], cv::Scalar(0, 0, 255), 3);

    cv::imshow("Card", img);
    cv::imshow("Card Warp king", imgWarp);
    cv::imshow("Card Warp Queen", imgWarpQueen);
    cv::imshow("Card Warp Jack", imgWarpJack);
    cv::waitKey();
}

void cv_color_detection()
{
    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 240;

    std::string path = "imgs/Similar-geometric-shapes.png";
    cv::Mat mask, imgHVS, img = cv::imread(path);
    cv::Scalar lower(hmin, smin, vmin);
    cv::Scalar upper(hmax, smax, vmax);

    // Converter a imagem para HVS
    cv::cvtColor(img, imgHVS, cv::COLOR_BGR2HSV);
    cv::inRange(imgHVS, lower, upper, mask);

    cv::imshow("Original", img);
    cv::imshow("Img HVS", imgHVS);
    cv::imshow("mask", mask);
    cv::waitKey(0);
}

void cv_color_detection_and_trackBar()
{
    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 240;

    std::string path = "imgs/Similar-geometric-shapes.png";
    std::string windowName = "Trackbars";
    cv::Mat mask, imgHVS, img = cv::imread(path);
    // Converter a imagem para HVS
    cv::cvtColor(img, imgHVS, cv::COLOR_BGR2HSV);

    cv::namedWindow(windowName, (400, 200));
    cv::createTrackbar("Hue Min", windowName, &hmin, 179);
    cv::createTrackbar("Hue Max", windowName, &hmax, 179);
    cv::createTrackbar("Sat Min", windowName, &smin, 255);
    cv::createTrackbar("Sat Max", windowName, &smax, 255);
    cv::createTrackbar("Val Min", windowName, &vmin, 255);
    cv::createTrackbar("Val Max", windowName, &vmax, 255);

    while (true)
    {
        cv::Scalar lower(hmin, smin, vmin);
        cv::Scalar upper(hmax, smax, vmax);

        cv::inRange(imgHVS, lower, upper, mask);

        cv::imshow("Original", img);
        //  cv::imshow("Img HVS", imgHVS);
        cv::imshow("mask", mask);
        cv::waitKey(1);
    }
}

void get_contours(cv::Mat base,cv::Mat outPutImage){
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(base,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);

    cv::drawContours(outPutImage,contours,-1,cv::Scalar(255,0,255),3);
    

}


void cv_shape_contour_detection()
{
    std::string path = "imgs/Similar-geometric-shapes.png";
    cv::Mat imgCanny, imgGray, imgBlur, imgDil, ImgErode;
    cv::Mat img = cv::imread(path);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    // Pre processamento
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
    cv::Canny(imgBlur, imgCanny, 25, 75);
    cv::dilate(imgCanny,imgDil,kernel);

    get_contours(imgDil,img);

    cv::imshow("Image", img);

    cv::waitKey(0);
}
