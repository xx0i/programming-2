#pragma once
#include "Shape.h"
#include "Line.h"
#include <vector>

class Triangle : public Shape {
public:
	//accessors
	Point2D P2()const;
	Point2D P3()const;

	//mutators 
	void setP2(Point2D newPt);
	void setP3(Point2D newPt);

	//vector<Line> field called lines.
	std::vector<Line>lines;

	//constructor with the following parameters : p1, p2, p3, colour
	Triangle(Point2D const p1, Point2D const p2, Point2D const p3, ConsoleColor const colour);

	//draw method
	void draw();

private:
	Point2D p2_;
	Point2D p3_;
};