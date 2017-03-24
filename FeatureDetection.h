#include "Globals.h"

enum { HAND_DETECTION, FACE_DETECTION };

class FeatureDetection {

public:
	FeatureDetection();

	void LoadHaarClassifier(const char* filePath);
	Point FindFeature(Mat currentFrame);

private:

	Mat currentFrame, grayFrame;
	vector<Rect> feature;
	CascadeClassifier classifier;
};