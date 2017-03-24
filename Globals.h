#pragma once
#include <windows.h>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\core\core.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\video\video.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

#define INTRODUCTION_IMAGE "C:/Users/Robert/Documents/Visual Studio 2013/Projects/ARProject/ARProject/Images/IntroductionImage.png"
#define HAND_HAAR_CASCADE "C:/Users/Robert/Documents/Visual Studio 2013/Projects/ARProject/ARProject/Haar Classifiers/Hand.xml"
#define FACE_HAAR_CASCADE "C:/Users/Robert/Documents/Visual Studio 2013/Projects/ARProject/ARProject/Haar Classifiers/Face.xml"
#define WINDOW_WIDTH  800.0f
#define WINDOW_HEIGHT 600.0f

using glm::vec2;
using namespace std;
using namespace cv;