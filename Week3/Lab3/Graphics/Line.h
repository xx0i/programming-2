#pragma once
#include "Shape.h"
class Line : public Shape
{
public:
	//accessors
	Point2D EndPt()const;

	//mutators
	void setEndPt(Point2D newPt);

	//Add a constructor that takes a start Point2D, end Point2D, and console color.
	Line(Point2D const start, Point2D const end, ConsoleColor const colour);

	//plot method
	void Plot(int const x, int const y);

	//plotline method
	void PlotLine(int x0, int y0, int const x1, int const y1);

	//draw method
	void draw()override;

private:
	//point2D member field endPt
	Point2D endPt_;
};