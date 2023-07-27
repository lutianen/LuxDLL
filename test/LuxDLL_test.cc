/**
 * @brief
 *
 * @version 1.0
 * @author Tianen Lu (tianen.xd@gmail.com)
 * @date 2022-11
 */

#include "../src/LuxDLL.h"

#include <stdint.h>
#include <string.h>

#include <ctime>
#include <fstream>
#include <iostream>

#include "../src/LuxCheck.h"

int main(int argc, char** argv) {
    auto t = clock();

    std::string filename;

    filename = "../images/20221115222819.45.raw";
    t = clock();
    std::cout << LuxLoadImageDataFromFileEnhanced(
                     filename.c_str(), 2, 2560, 1920, 16, 1,
                     "../images/LuxDLL_00", "../images/LuxDLL_00", true, true,
                     true, 3, cv::COLOR_BayerRG2RGB)
              << std::endl
              << "LuxLoadImageDataFromFileEnhanced cost: "
              << (double)(clock() - t) / CLOCKS_PER_SEC << " seconds."
              << std::endl;

    std::ifstream fs(filename.c_str(), std::ios_base::binary);
    if (!fs.is_open()) {
        std::cerr << "Open " << filename << " failed." << std::endl;
        return -1;
    }

    int length = 0;
    fs.seekg(0, fs.end);
    length = fs.tellg();
    fs.seekg(0, fs.beg);

    unsigned char* src = new unsigned char[length];
    fs.read(reinterpret_cast<char*>(src), length);
    fs.close();

    unsigned char* RDst = new unsigned char[length / 4];
    unsigned char* G1Dst = new unsigned char[length / 4];
    unsigned char* G2Dst = new unsigned char[length / 4];
    unsigned char* BDst = new unsigned char[length / 4];

    t = clock();
    auto ret =
        LuxGetBayerRawChanenls(src, 2560, 1920, 0, RDst, G1Dst, G2Dst, BDst);
    std::cout << "0 is sucessful else failed: " << ret << std::endl;
    std::cout << __FILE__ << " " << __LINE__
              << " -->> Cost: " << (double)(clock() - t) / CLOCKS_PER_SEC
              << " sec." << std::endl;

    t = clock();
    std::cout << LuxSetChannelFactors(src, 2560, 1920, 0, 1.23, 3.2, 1)
              << std::endl;
    std::cout << __FILE__ << " " << __LINE__
              << " -->> Cost: " << (double)(clock() - t) / CLOCKS_PER_SEC
              << " sec." << std::endl;

    delete[] src;
    src = nullptr;
    delete[] RDst;
    src = nullptr;
    delete[] G1Dst;
    src = nullptr;
    delete[] G2Dst;
    src = nullptr;
    delete[] BDst;
    src = nullptr;
}
