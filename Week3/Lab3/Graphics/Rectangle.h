#pragma once
#include "Shape.h"
#include <vector>
#include "Line.h"

class Rectangle : public Shape
{
public:
	//accessors
	int Width()const;
	int Height()const;

	//mutators
	void setWidth(int& num);
	void setHeight(int& num);

	//constructor with the following parameters : width, height, startPt, colour.
	Rectangle(int const& width, int const& height, Point2D const& startPt, ConsoleColor const& colour);

	//draw method
	void draw() override;

private:
	//int member fields width and height
	int width_;
	int height_;

	//vector<Line> field called lines.
	std::vector<Line>lines;
};