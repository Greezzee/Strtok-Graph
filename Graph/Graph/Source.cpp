#include <stdlib.h>
#include <math.h>
#include "GraphDrawer.h"

typedef double (*GraphFunc) (double);

double F(double x) {
	return x * x - 1;
}

double G(double x) {
	if (x == 0)
		return 0;
	return 1 / x;
}

double H(double x) {

	return sin(x);
}

int main() {

	GraphFunc graphs[] = { F, G, H };

	GraphDrawer g(graphs, 3);
	g.SetScale(100, 100);
	g.Draw();
	return 0;
}