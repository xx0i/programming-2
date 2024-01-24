#include "Rectangle.h"
//width and height accessors
int Rectangle::Width()const {
	return width_;
}

int Rectangle::Height()const {
	return height_;
}

//width and height mutators
void Rectangle::setWidth(int num) {
	width_ = num;
}

void Rectangle::setHeight(int num) {
	height_ = num;
}

//Pass the startPt and color to the base constructor.Use width and height to set the fields.
Rectangle::Rectangle(int const width, int const height, Point2D const startPt, ConsoleColor const colour) : Shape(startPt, colour), width_(width), height_(height) {

	//points to create the lines (corners of the rectangle)
	Point2D pt2((startPt.x_ + width), startPt.y_);
	Point2D pt3((startPt.x_ + width), (startPt.y_ - height));
	Point2D pt4(startPt.x_, (startPt.y_ - height));

	//lines to be pushed back to the vector
	Line top(startPt, pt2, colour);
	Line right(pt2, pt3, colour);
	Line bottom(pt3, pt4, colour);
	Line left(pt4, startPt, colour);

	//adding the lines to the vector
	lines.push_back(top);
	lines.push_back(right);
	lines.push_back(bottom);
	lines.push_back(left);
}

//overridden draw method
void Rectangle::draw()
{
	for (Line line : lines) {
		line.draw();
	}
}