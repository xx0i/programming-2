#include "Triangle.h"
//p2 and p3 accessors
Point2D Triangle::P2()const {
	return p2_;
}

Point2D Triangle::P3()const {
	return p3_;
}

//width and height mutators
void Triangle::setP2(Point2D& newPt) {
	p2_ = newPt;
}

void Triangle::setP3(Point2D& newPt) {
	p3_ = newPt;
}

//Pass the p1 and color to the base constructor.Use p2 and p3 to set the data.The constructor should create 3 Lines connecting the points and add them to the lines field.
Triangle::Triangle(Point2D const& p1, Point2D const& p2, Point2D const& p3, ConsoleColor const& colour) : Shape(p1, colour), p2_(p2), p3_(p3) {
	Line p1p2 (p1, p2, colour);
	Line p2p3(p2, p3, colour);
	Line p3p1(p3, p1, colour);

	lines.push_back(p1p2);
	lines.push_back(p2p3);
	lines.push_back(p3p1);
}

//overriden draw method
void Triangle::draw()
{
	for (Line line : lines) {
		line.draw();
	}
}
