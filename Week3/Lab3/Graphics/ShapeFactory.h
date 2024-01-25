#pragma once
#include <memory>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

class ShapeFactory
{
	//RandomPoint should return a random Point2D struct.
	static Point2D RandomPoint();
	//RandomColor should return a random ConsoleColor.
	static ConsoleColor RandomColour();
	//RandomShape should return a random Shape.
	static std::unique_ptr<Shape> RandomShape();
	//RandomLine should return a random Line.
	static std::unique_ptr<Line> RandomLine();
	//RandomRectangle should return a random Rectangle.
	static std::unique_ptr<Rectangle> RandomRectangle();
	//RandomTriangle should return a random triangle.
	static std::unique_ptr <Triangle> RandomTriangle();
	//RandomCircle should return a random Circle.
	static std::unique_ptr<Circle> RandomCircle();
};

//Create a class called ShapeFactory.
// Add 7 static methods : a method for creating a random point, a method for creating a random color, and methods for creating each Shape
//type.The methods that create the random Shapes should use make_unique and return a unique_ptr.
