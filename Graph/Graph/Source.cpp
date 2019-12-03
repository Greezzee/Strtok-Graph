#include <stdlib.h>
#include <math.h>
#include "TXLib.h"

const int SCREEN_X = 800, SCREEN_Y = 600;
typedef double (*PlotFunc)(double);
void drawPlot(PlotFunc func, double scaleX, double scaleY) {
	txLine(0, 300, 800, 300);
	txLine(400, 0, 400, 600);

	static char matrix[SCREEN_Y][SCREEN_X] = {};
	for (int x = 0; x < SCREEN_X; x++) {
		double y = -func((double)(x - SCREEN_X / 2) * scaleX) * scaleY + SCREEN_Y / 2;
		if (y != NAN && y >= 0 && y < SCREEN_Y)
			matrix[(int)y][x] = 1;
	}
	for (int y = 0; y < SCREEN_Y; y++)
		for (int x = 0; x < SCREEN_X; x++)
			if (matrix[y][x])
				txPixel(x, y, 1, 1, 1);

}

void drawMultiplyPlots(PlotFunc plots[], size_t count, double scaleX, double scaleY) {
	for (int i = 0; i < count; i++)
		drawPlot(plots[i], scaleX, scaleY);
}

double F(double x) {
	return x;
}
double G(double x) {
	return 0;
}

double H(double x) {
	return 0;
}

int main() {
	txCreateWindow(SCREEN_X, SCREEN_Y);
	PlotFunc plots[] = { F, G, H };
	drawMultiplyPlots(plots, 3, 100, 100);
	return 0;
}


//ÑÏÅÖÈÀËÈÇÀÖÈß ØÀÁËÎÍÎÂ