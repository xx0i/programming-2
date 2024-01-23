#include "Line.h"
//endPt accessor
Point2D Line::EndPt()const {
	return endPt_;
}

//endPt mutators
void Line::setEndPt(Point2D newPt) {
	endPt_ = newPt;
}

//constructor that takes a start Point2D, end Point2D, and console color. Make sure to call the base constructor, don’t duplicate what the base constructors do
Line::Line(Point2D const start, Point2D const end, ConsoleColor colour) : Shape(start, colour), endPt_(end) {
}

//plot method
void Line::Plot(int const x, int const y) {
	Console::SetCursorPosition(x, y);
	Console::Write(" ");
}

//plotline method
void Line::PlotLine(int x0, int y0, int const x1, int const y1) {
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (true) {
		Plot(x0, y0);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if (e2 >= dy) {
			if (x0 == x1) break;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			if (y0 == y1) break;
			error += dx;
			y0 += sy;
		}
	}
}

//overridden draw method
void Line::draw()
{
	Console::SetBackgroundColor(colour_);
	PlotLine(startPt_.x_, endPt_.x_, startPt_.y_, endPt_.y_);
	Console::Reset();
}