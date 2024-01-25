#include "ShapeFactory.h"

//RandomPoint should return a random Point2D struct.
Point2D ShapeFactory::RandomPoint()
{
	//generates a random x value, y value ; both values range from 1 to 1 less than the size of the console window to prevent a division by 0 exception (for circle)
	int x = (rand() % Console::GetWindowHeight());
	int y = (rand() % Console::GetWindowHeight());
	//generates a random point
	Point2D point(x, y);

	return point;
}

//RandomColor should return a random ConsoleColor.
ConsoleColor ShapeFactory::RandomColour()
{
	ConsoleColor colour = ConsoleColor(1 + rand() % 7);
	//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default
	return colour;
}

//RandomShape should return a random Shape.
std::unique_ptr<Shape> ShapeFactory::RandomShape()
{
	//generates the random point and colour for the shape
	Point2D shapePoint = RandomPoint();
	ConsoleColor shapeColour = RandomColour();

	//unique pointer of random shape
	std::unique_ptr<Shape> pShape = std::make_unique<Shape>(shapePoint, shapeColour);

	//returns randomShape
	return pShape;
}

//RandomLine should return a random Line.
std::unique_ptr<Line> ShapeFactory::RandomLine()
{
	//generates the random points and colour for the line
	Point2D linePoint1 = RandomPoint();
	Point2D linePoint2 = RandomPoint();
	ConsoleColor lineColour = RandomColour();

	//unique pointer of random line
	std::unique_ptr<Line> pLine = std::make_unique<Line>(linePoint1, linePoint2, lineColour);

	//returns random line
	return pLine;
}

//RandomRectangle should return a random Rectangle.
std::unique_ptr<Rectangle> ShapeFactory::RandomRectangle()
{
	//generates the height, width, random point and colour for the rectangle
	int rectangleWidth = (rand() % Console::GetWindowWidth());
	int rectangleHeight = (rand() % Console::GetWindowHeight());
	Point2D rectanglePoint = RandomPoint();
	ConsoleColor rectangleColour = RandomColour();

	//unique pointer of random rectangle
	std::unique_ptr<Rectangle> pRectangle = std::make_unique<Rectangle>(rectangleWidth, rectangleHeight, rectanglePoint, rectangleColour);

	//returns random rectangle
	return pRectangle;
}

//RandomTriangle should return a random triangle.
std::unique_ptr<Triangle> ShapeFactory::RandomTriangle()
{
	//generates the random points and colour for the triangle
	Point2D trianglePoint1 = RandomPoint();
	Point2D trianglePoint2 = RandomPoint();
	Point2D trianglePoint3 = RandomPoint();
	ConsoleColor triangleColour = RandomColour();

	//unique pointer of random triangle
	std::unique_ptr<Triangle> pTriangle = std::make_unique<Triangle>(trianglePoint1, trianglePoint2, trianglePoint3, triangleColour);

	//returns random triangle
	return pTriangle;
}

//RandomCircle should return a random Circle.
std::unique_ptr<Circle> ShapeFactory::RandomCircle()
{
	//generates the random point, and colour for the circle
	Point2D circlePoint = RandomPoint();
	ConsoleColor circleColour = RandomColour();
	
	//uses the random point to generate a random radius
	int d1 = abs(circlePoint.x_ - 0);//left
	int d2 = abs(circlePoint.x_ - Console::GetWindowWidth());//right
	int d3 = abs(circlePoint.y_ - Console::GetWindowHeight());//top
	int d4 = abs(circlePoint.y_ - 0);//bottom
	int minDistance = std::min(std::min(d1, d2), std::min(d3, d4)); //finds the min of all distances
	while (minDistance == 0) {
		circlePoint = RandomPoint();
	}
	int circleRadius = (rand() % minDistance);

	//unique pointer of random circle
	std::unique_ptr<Circle> pCircle = std::make_unique<Circle>(circleRadius, circlePoint, circleColour);

	//returns random circle
	return pCircle;
}
