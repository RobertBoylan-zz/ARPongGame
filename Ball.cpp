#include "Ball.h"

Ball::Ball(){

	radius = 30.0f;
	bounce = 2.0f;
	speed.x = -bounce;
	speed.y = 15.0f;
	centre = Point((WINDOW_WIDTH / 2), radius);
}

void Ball::DrawBall(Mat frame) {

	circle(frame, centre, radius, Scalar(0, 0, 255), -1, 8);
}

void Ball::Move() {

	centre.x += speed.x;
	centre.y += speed.y;
}

void Ball::Bounce(Point paddleCentre, float paddleWidth, float paddleHeight) {

	if (centre.x < radius || centre.x > (WINDOW_WIDTH - radius)) {

		speed.x *= -1;
	}

	if (centre.y < radius || Collision(paddleCentre, paddleWidth, paddleHeight)) {

		speed.y *= -1;
	}

	if (Collision(paddleCentre, paddleWidth, paddleHeight) && (centre.x >= (paddleCentre.x - (paddleWidth / 2) - radius)) && (centre.x < paddleCentre.x - (paddleWidth / 2) + radius)) {

		if (speed.x == bounce) {

			speed.x = -(bounce * 2);
		}
		else if (speed.x == -bounce) {

			speed.x = -(bounce * 2);
		}
	}

	else if (Collision(paddleCentre, paddleWidth, paddleHeight) && (centre.x >= paddleCentre.x - (paddleWidth / 2) + radius) && (centre.x < paddleCentre.x)) {

		if (speed.x == (bounce * 2)) {

			speed.x = bounce;
		}
		else if (speed.x == -(bounce * 2)) {

			speed.x = -bounce;
		}
	}

	else if (Collision(paddleCentre, paddleWidth, paddleHeight) && (centre.x >= paddleCentre.x) && (centre.x < paddleCentre.x + (paddleWidth / 2) - radius)) {

		if (speed.x == (bounce * 2)) {

			speed.x = bounce;
		}
		else if (speed.x == -(bounce * 2)) {

			speed.x = -bounce;
		}
	}
	else if (Collision(paddleCentre, paddleWidth, paddleHeight) && (centre.x >= paddleCentre.x + (paddleWidth / 2) - radius) && (centre.x <= (paddleCentre.x + (paddleWidth / 2) + radius))) {

		if (speed.x == bounce) {

		speed.x = (bounce * 2);
		}
		else if (speed.x == -bounce) {

		speed.x = (bounce * 2);
		}
	}
}

bool Ball::Collision(Point paddleCentre, float paddleWidth, float paddleHeight) {

	if (centre.y >= (paddleCentre.y - (paddleHeight / 2) - radius) && (centre.x >= (paddleCentre.x - (paddleWidth / 2) - radius)) && (centre.x <= (paddleCentre.x + (paddleWidth / 2) + radius))) {

		return true;
	}

	return false;
}