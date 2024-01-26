#pragma once
#include "Shape.h"
class Circle : public Shape {
public:
	//accessors
	int Radius()const;

	//mutators
	void setRadius(int& newRadius);

	//constructor with the following parameters : radius, startPt, color
	Circle(int const& radius, Point2D const& startPt, ConsoleColor const& colour);

	//plot method
	void Plot(int const& x, int const& y);
	
	//DrawCirclePoints method
	void DrawCirclePoints(int const& xc, int const& yc, int const& x, int const& y);

	//DrawCircle method
	void DrawCircle(int const& xc, int const& yc, int const& r);
	
	//draw method
	void draw()override;

private:
	//int member field radius
	int radius_;
};