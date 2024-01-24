#include "Circle.h"
//radius accessor
int Circle::Radius()const {
	return radius_;
}

//radius mutator
void Circle::setRadius(int newRadius) {
	radius_ = newRadius;
}

//Pass the startPt and color to the base constructor.Use radius parameter to set the radius data.
Circle::Circle(int const radius, Point2D const startPt, ConsoleColor const colour) : Shape(startPt, colour), radius_(radius) {
}

//plot method
void Circle::Plot(int const x, int const y) {
	Console::SetCursorPosition(x, y);
	Console::Write(" ");
}

//DrawCirclePoints method
void Circle::DrawCirclePoints(int const xc, int const yc, int const x, int const y) {
	Plot((xc + x), (yc + y));
	Plot((xc - x), (yc + y));
	Plot((xc + x), (yc - y));
	Plot((xc - x), (yc - y));
	Plot((xc + y), (yc + x));
	Plot((xc - y), (yc + x));
	Plot((xc + y), (yc - x));
	Plot((xc - y), (yc - x));
}

//DrawCircle method
void Circle::DrawCircle(int const xc, int const yc, int const r) {
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;
	DrawCirclePoints(xc, yc, x, y);
	while (y >= x) {
		x += 1;
		if (d > 0) {
			y -= 1;
			d = d + 4 * (x - y) + 10;
		}
		else {
			d = d + 4 * x + 6;
		}
		DrawCirclePoints(xc, yc, x, y);
	}
}

//overriden draw method
void Circle::draw() {
	Console::SetBackgroundColor(colour_);
	DrawCircle(startPt_.x_, startPt_.y_, radius_);
	Console::Reset();
}