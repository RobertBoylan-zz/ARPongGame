#include "Game.h"

Game::Game(){

	detectionMode = HAND_DETECTION;
	gameState = GAME_START;
	ball = NULL;
}

void Game::GameInitialize() {

	introductionImage = imread(INTRODUCTION_IMAGE, CV_LOAD_IMAGE_COLOR);

	capture.open(0);
	capture.set(CV_CAP_PROP_FRAME_WIDTH, WINDOW_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, WINDOW_HEIGHT);
	
	hand.LoadHaarClassifier(HAND_HAAR_CASCADE);
	face.LoadHaarClassifier(FACE_HAAR_CASCADE);
}

void Game::GameDisplay() {

	if (gameState == GAME_START) {

		score = 0;
		ball = new Ball();
		Introduction();
	}

	else if (gameState == GAME_RUN) {
		
		cvDestroyWindow("Introduction");

		capture >> videoFrame;
		flip(videoFrame, videoFrame, 1);

		if (detectionMode == HAND_DETECTION) {
			
			featurePosition = hand.FindFeature(videoFrame);
			Text(videoFrame, "Detection Mode: HAND", Point(20, 40), 0.4, Scalar(0, 255, 0), 1);
		}
		else if (detectionMode == FACE_DETECTION) {

			featurePosition = face.FindFeature(videoFrame);
			Text(videoFrame, "Detection Mode: FACE", Point(20, 40), 0.4, Scalar(0, 255, 0), 1);
		}

		paddle.DrawPaddle(videoFrame, featurePosition);
		ball->DrawBall(videoFrame);
		ball->Move();
		ball->Bounce(paddle.getCentre(), paddle.getWidth(), paddle.getHeight());
		GameOver();
		IncreaseScore();
		Text(videoFrame, "Score: " + to_string(score), Point(20, 20), 0.4, Scalar(0, 255, 0), 1);

		imshow("Pong Game", videoFrame);
	}

	else if (gameState == GAME_OVER) {

		capture >> videoFrame;
		flip(videoFrame, videoFrame, 1);

		paddle.DrawPaddle(videoFrame, featurePosition);
		ball->DrawBall(videoFrame);
		Text(videoFrame, "GAME OVER", Point((WINDOW_WIDTH / 2) - 160, WINDOW_HEIGHT / 2), 2.0, Scalar(0, 0, 255), 2);
		Text(videoFrame, "Press 'R' to restart", Point((WINDOW_WIDTH / 2) - 100, (WINDOW_HEIGHT / 2) + 120), 0.8, Scalar(255, 0, 0), 2);

		imshow("Pong Game", videoFrame);

		char key = waitKey(1);

		if (key == 82) {
			cvDestroyWindow("Pong Game");
			gameState = GAME_START;
		}
	}
}

void Game::Introduction() {

	Text(introductionImage, "AR PONG GAME", Point(300, 250), 2.0, Scalar(0, 0, 255), 3);
	Text(introductionImage, "Hand detection or face detection? [H/F] ", Point(285, 400), 0.8, Scalar(255, 255, 255), 2);
	Text(introductionImage, "By Robert Boylan", Point(780, 740), 0.8, Scalar(0, 0, 255), 2);

	imshow("Introduction", introductionImage);

	char key = waitKey(1);

	if (key == 72) {
		detectionMode = HAND_DETECTION;
		gameState = GAME_RUN;
	}
	else if (key == 70) {
		detectionMode = FACE_DETECTION;
		gameState = GAME_RUN;
	}
}

void Game::GameOver() {

	if (ball->getBallCentre().y >= (WINDOW_HEIGHT + ball->getBallRadius() + 20.0f) && !ball->Collision(paddle.getCentre(), paddle.getWidth(), paddle.getHeight())) {

		gameState = GAME_OVER;
	}
}

void Game::IncreaseScore() {

	if (ball->Collision(paddle.getCentre(), paddle.getWidth(), paddle.getHeight())) {

		score++;
	}
}

void Game::Text(Mat frame, String text, Point location, double size, Scalar colour, int thickness) {

	putText(frame, text, location, FONT_HERSHEY_SIMPLEX, size, colour, thickness, 8);
}