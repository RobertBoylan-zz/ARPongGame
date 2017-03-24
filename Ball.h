#pragma once
#include "Globals.h"

class Ball {

public:
	Ball();

	void LoadBall();
	void DrawBall(Mat frame);
	void Move();
	void Bounce(Point paddleCentre, float paddleWidth, float paddleHeight);
	bool Collision(Point paddleCentre, float paddleWidth, float paddleHeight);
	Point getBallCentre() const { return centre; }
	float getBallRadius() const { return radius; }

private:
	float radius, bounce;
	vec2 speed;
	Point centre;
};