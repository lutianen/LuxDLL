/**
 * @file LuxTW2_test.cc
 * @brief 
 * 
 * @version 1.0
 * @author Tianen Lu (tianenlu957@gmail.com)
 * @date 2022-11
 */

#include <iostream>
#include <stdint.h>
#include <string.h>
#include <ctime>

#include "../src/LuxDLL.h"
#include "../src/LuxCheck.h"


int main( int argc, char ** argv ) {
	auto t = clock();

    std::string filename;

    filename = "../images/20221115222819.45.raw";
    t = clock();
    std::cout << 
        LuxLoadImageDataFromFileEnhanced(filename.c_str(),
                2,
                2560, 1920,
                16,
                1,
                "../images/LuxDLL_00",
                "../images/LuxDLL_00",
                true,
                true,
                true,
                3,
                CV_BayerRG2RGB)
        << std::endl
        << "LuxLoadImageDataFromFileEnhanced cost: " 
            << (double)(clock() - t) / CLOCKS_PER_SEC << " seconds." << std::endl;
	return 0;
}
