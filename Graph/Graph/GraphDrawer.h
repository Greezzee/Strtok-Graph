#pragma once
#include "TXLib.h"

typedef double (*GraphFunc) (double);

class GraphDrawer
{
public:

	~GraphDrawer() 
	{
		delete[] Funcs;
	}

	GraphDrawer(GraphFunc funcs[], int graphs_count) 
	{
		Funcs = new GraphFunc[graphs_count];
		for (int i = 0; i < graphs_count; i++)
			Funcs[i] = funcs[i];
		scale_x = 1;
		scale_y = 1;
		graph_count = graphs_count;
		txCreateWindow(600, 600);
	}

	void Draw() 
	{
		txLine(0, 300, 600, 300);
		txLine(300, 0, 300, 600);

		for (int i = 0; i < graph_count; i++) {
			DrawOneGraph(Funcs[i]);
		}
	}

	void SetScale(double new_x, double new_y) 
	{
		scale_x = new_x;
		scale_y = new_y;
	}

private:

	void DrawOneGraph(GraphFunc F)
	{
		double prev_x, prev_y;
		prev_x = -300.f / scale_x;
		prev_y = -F(prev_x);

		for (double x = -300.f / scale_x; x < 300.f / scale_x; x += 1.f / scale_x) {
			double y = -F(x);

			double realX1 = prev_x * scale_x + 300;
			double realX2 = x * scale_x + 300;
			double realY1 = prev_y * scale_y + 300;
			double realY2 = y * scale_y + 300;

			if (realX1 < 0)   realX1 = 0;
			if (realX2 < 0)   realX2 = 0;
			if (realY1 < 0)   realY1 = 0;
			if (realY2 < 0)   realY2 = 0;

			if (realX1 > 600) realX1 = 600;
			if (realX2 > 600) realX2 = 600;
			if (realY1 > 600) realY1 = 600;
			if (realY2 > 600) realY2 = 600;

			txLine(realX1, realY1, realX2, realY2);

			prev_x = x;
			prev_y = y;
		}
	}

	GraphFunc* Funcs;
	double scale_x, scale_y;
	size_t graph_count;
};