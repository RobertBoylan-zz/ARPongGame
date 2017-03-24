#include "FeatureDetection.h"

FeatureDetection::FeatureDetection() {}

void FeatureDetection::LoadHaarClassifier(const char* filePath) {

	classifier.load(filePath);
}

Point FeatureDetection::FindFeature(Mat currentFrame) {

	Mat grayFrame;
	Point centre;

	cvtColor(currentFrame, grayFrame, CV_BGR2GRAY);
	equalizeHist(grayFrame, grayFrame);

	classifier.detectMultiScale(grayFrame, feature, 1.1, 3, 0 | CV_HAAR_FIND_BIGGEST_OBJECT, Size(30, 30));

	for (int i = 0; i < (int)feature.size(); i++) {

		centre = Point(feature[i].x + feature[i].width / 2, feature[i].y + feature[i].height / 2);

		circle(currentFrame, centre, feature[i].width / 2, Scalar(0, 255, 255), 2, 8);
	}

	return centre;
}