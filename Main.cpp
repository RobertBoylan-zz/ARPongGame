#include "Game.h"

Game game;

int main() {

	game.GameInitialize();

	while (true) {

		game.GameDisplay();

		char key = waitKey(1);

		if (key == 27) {
			break;
		}
	}
	return 0;
}