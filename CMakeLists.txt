cmake_minimum_required(VERSION 3.20)
project(LuxDLL)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


add_library(LuxDLL SHARED src/LuxDLL.cc src/LuxCheck.cc)
set(OpenCV_DIR "F:\\opencv3\\mingw-build\\install\\x64\\mingw")
FIND_PACKAGE(OpenCV REQUIRED)
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(LuxDLL ${OpenCV_LIBS})
else(OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV library not found")
endif(OpenCV_FOUND)


add_executable(LuxDLLTEST test/LuxDLL_test.cc)
target_link_libraries(LuxDLLTEST LuxDLL)

