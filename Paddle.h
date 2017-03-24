#pragma once
#include "Globals.h"

class Paddle {

public:
	Paddle();

	void DrawPaddle(Mat videoFrame, Point handPosition);
	Point getTopLeft() const { return topLeft; }
	Point getBottomRight() const { return bottomRight; }
	Point getCentre();
	float getWidth() const { return width; }
	float getHeight()const { return height; }

private:
	float width, height;
	Point topLeft, bottomRight;
}; 














/*class Paddle {

public:
	Paddle();

	void LoadPaddle();
	void DrawPaddle(Mat videoFrame);
	void CalculateTranslation();
	void MoveLeft();
	void MoveRight();
	void KeySpecial(int key, int x, int y);
	void KeySpecialUp(int key, int x, int y);
	void KeyOperations();
	vec2 getPaddlePosition() const { return position; }

private:
	float speed, width, height;
	vec2 position;
	GLuint shaderProgramID, VAO;
	Point handPosition;
	Model paddleModel;
	HandDetection hand;
	enum specialKeyStates { NOT_PUSHED, PUSHED } specialKeyArray[256];
};*/