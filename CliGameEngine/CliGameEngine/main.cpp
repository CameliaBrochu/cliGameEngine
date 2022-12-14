#include <stdio.h>
#include "CliGameEngine.h"

class demoGame : public cliGE::CliGameEngine
{
public:
	using CliGameEngine::CliGameEngine;

	void onGameLoad() {
		pX = 0;
		pY = 0;
	}
	void onGameUpdate() {
		// A : 0x41
		if (keyPressed(0x41)) {
			--pX;
		}

		// D : 0x44
		if (keyPressed(0x44)) {
			++pX;
		}

		// W : 0x57
		if (keyPressed(0x57)) {
			--pY;
		}

		// S : 0x53
		if (keyPressed(0x53)) {
			++pY;
		}
	}

	void onGameDraw() {
		writeCharAt('P', pX, pY);
	}
private:
	size_t pX;
	size_t pY;
};

int main() {

	demoGame demo(120, 40);
	demo.start();

	return 0;
}