#include "Paddle.h"

Paddle::Paddle(){

	width = 100.0f;
	height = 20.0f;
	topLeft.y = WINDOW_HEIGHT - height;
	bottomRight.y = WINDOW_HEIGHT;
}

void Paddle::DrawPaddle(Mat videoFrame, Point handPosition) {

	topLeft.x = handPosition.x - (width / 2);
	bottomRight.x = handPosition.x + (width / 2);

	rectangle(videoFrame, topLeft, bottomRight, Scalar(0, 0, 255), -1, 8);
}

Point Paddle::getCentre() {

	Point centre;
	
	centre.x = topLeft.x + (width / 2);
	centre.y = topLeft.y + (height / 2);

	return centre;
}