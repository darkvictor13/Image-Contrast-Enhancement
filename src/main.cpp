#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "image_enhancement.h"

using std::chrono::high_resolution_clock;

void MyTimeOutput(const std::string& str, const high_resolution_clock::time_point& start_time, const high_resolution_clock::time_point& end_time)
{
    std::cout << str << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0 << "ms" << std::endl;
    return;
}

int main(int argc, char** argv)
{
    cv::Mat src = cv::imread(argv[1], 1);

    if (src.empty()) {
        std::cout << "Can't read image file." << std::endl;
        return -1;
    }

    high_resolution_clock::time_point start_time, end_time;

    start_time = high_resolution_clock::now();
    cv::Mat AINDANE_dst;
    AINDANE(src, AINDANE_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AINDANE: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat WTHE_dst;
    WTHE(src, WTHE_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("WTHE: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat GCEHistMod_dst;
    GCEHistMod(src, GCEHistMod_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("GCEHistMod: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat LDR_dst;
    LDR(src, LDR_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("LDR: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat AGCWD_dst;
    AGCWD(src, AGCWD_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCWD: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat AGCIE_dst;
    AGCIE(src, AGCIE_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("AGCIE: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat IAGCWD_dst;
    IAGCWD(src, IAGCWD_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("IAGCWD: ", start_time, end_time);

    //start_time = high_resolution_clock::now();
    //cv::Mat Ying_dst;
    //Ying_2017_CAIP(src, Ying_dst);
    //end_time = high_resolution_clock::now();
    //MyTimeOutput("Ying处理时间: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat CEusingLuminanceAdaptation_dst;
    CEusingLuminanceAdaptation(src, CEusingLuminanceAdaptation_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("CEusingLuminanceAdaptation: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat adaptiveImageEnhancement_dst;
    adaptiveImageEnhancement(src, adaptiveImageEnhancement_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("adaptiveImageEnhancement: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat JHE_dst;
    JHE(src, JHE_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("JHE: ", start_time, end_time);

    start_time = high_resolution_clock::now();
    cv::Mat SEF_dst;
    SEF(src, SEF_dst);
    end_time = high_resolution_clock::now();
    MyTimeOutput("SEF: ", start_time, end_time);

    cv::imwrite("images/01_src.bmp", src);
    cv::imwrite("images/02_AINDANE_dst.bmp", AINDANE_dst);
    cv::imwrite("images/03_WTHE_dst.bmp", WTHE_dst);
    cv::imwrite("images/04_GCEHistMod_dst.bmp", GCEHistMod_dst);
    cv::imwrite("images/05_LDR_dst.bmp", LDR_dst);
    cv::imwrite("images/06_AGCWD_dst.bmp", AGCWD_dst);
    cv::imwrite("images/07_AGCIE_dst.bmp", AGCIE_dst);
    cv::imwrite("images/08_IAGCWD_dst.bmp", IAGCWD_dst);
    cv::imwrite("images/09_CEusingLuminanceAdaptation_dst.bmp", CEusingLuminanceAdaptation_dst);
    cv::imwrite("images/10_adaptiveImageEnhancement_dst.bmp", adaptiveImageEnhancement_dst);
    cv::imwrite("images/11_JHE_dst.bmp", JHE_dst);
    cv::imwrite("images/12_SEF_dst.bmp", SEF_dst);

    return 0;
}
