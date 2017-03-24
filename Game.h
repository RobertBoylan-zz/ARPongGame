#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "FeatureDetection.h"

enum { GAME_START, GAME_RUN, GAME_OVER };

class Game {

public:
	Game();

	void GameInitialize();
	void GameDisplay();
	void Introduction();
	void GameOver();
	void IncreaseScore();
	void Text(Mat frame, String text, Point location, double size, Scalar colour, int thickness);

private:
	int score, detectionMode, gameState;
	char key;
	bool gameOver;
	Mat introductionImage, videoFrame;
	FeatureDetection hand, face;
	Point featurePosition;
	Ball* ball;
	Paddle paddle;
	VideoCapture capture;
};