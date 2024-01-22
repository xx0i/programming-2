#pragma once
#include "Point2D.h"
#include "Console.h"

//class Shape
class Shape
{
public:
	//accessors
	Point2D StartPt()const;
	ConsoleColor Colour()const;

	//mutators
	void setStartPt(Point2D newPt);
	void setColour(ConsoleColor newColour);

	//First constructor takes 2 parameters : a Point2D and a ConsoleColor.
	Shape(Point2D const point, ConsoleColor const colour);
	//Second constructor takes 3 parameters : 2 ints for the x and y and a ConsoleColor.
	Shape(int const x, int const y, ConsoleColor const colour);

	//draw method
	void draw();

	//member fields Point2D startPt, ConsoleColor colour
private:
	Point2D startPt_;
	ConsoleColor colour_;
};

