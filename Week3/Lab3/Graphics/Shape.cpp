#include "Shape.h"
//starPt and colour accessors
Point2D Shape::StartPt()const {
	return startPt_;
}
ConsoleColor Shape::Colour()const {
	return colour_;
}

//startPt and colour mutators
void Shape::setStartPt(Point2D newPt) {
	startPt_ = newPt;
}
void Shape::setColour(ConsoleColor newColour) {
		colour_ = newColour;
}

//First constructor takes 2 parameters: a Point2D and a ConsoleColor. Set the data with these parameters.
Shape::Shape(Point2D const point, ConsoleColor const colour) : startPt_(point), colour_(colour){
}

//Second constructor takes 3 parametersUse the x and y parameters to initialize the startPt. Use the ConsoleColor parameter to set the color.
Shape::Shape(int const x, int const y, ConsoleColor const colour) : startPt_(x, y), colour_(colour) {
}

//draw method
void Shape::draw() {
	Console::SetBackgroundColor(colour_);
	//Console::SetCursorPosition(x, y);
	Console::Write(" ");
	Console::Reset();
}
//• Move the cursor to the Point2D position.