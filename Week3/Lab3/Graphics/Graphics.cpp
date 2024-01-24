#include <iostream>
#include "Console.h"
#include "Input.h"
#include <algorithm>
#include <memory>
#include "Tester.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"


int main()
{
	Tester graphicsTest;
	srand((unsigned int)time(NULL)); //seed the random # generator

	Console::ResizeWindow(150, 30);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Draw Shape", "2. Draw Line", "3. Draw Rectangle", "4. Draw Triangle",  "5. Draw Circle", "6. Draw Random Shapes", "7. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			/*

				Part A-1: Add a Point2D struct to the Graphics project.
					An easy way to create a struct is to add a new class then change it from a class to a struct.
					Add 2 fields: x and y. The type of these fields is int. (They need to be visible outside of the struct)
					Add a constructor that takes 2 int parameters. Use these to initialize x and y.

				Part A-2: Add a Shape class to the Graphics project.
					Add 2 fields with getters/setters: a Point2D called startPt and a ConsoleColor called color.
					Add 2 constructors:
					•	First constructor takes 2 parameters: a Point2D and a ConsoleColor. Set the data with these parameters.
					•	Second constructor takes 3 parameters: 2 ints for the x and y and a ConsoleColor. Use the x and y parameters to initialize the startPt. Use the ConsoleColor parameter to set the color.
					Add a Draw method.
					•	Set the background color.
					•	Move the cursor to the Point2D position.
					•	Print a space.
					•	Reset the color in the console. (call the reset method on the Console class).

				Part A-3: add code to case 1 of the menu switch.
					Generate a random Point2D with an x,y anywhere in the console.
					Use that point to create a Shape instance with any color you want.
					Call Draw on the Shape instance.


			*/
			//generates a random x value, y value, and a random colour
			int x = (rand() % Console::GetWindowWidth());
			int y = (rand() % Console::GetWindowHeight());
			ConsoleColor colour = ConsoleColor(1 + rand() % 7);
			//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default

			//generates random point
			Point2D point(x, y);

			//creates Shape object and draw method
			Shape shape(point, colour);
			shape.draw();

			break;
		}
		case 2:
		{
			/*

				Part B-1: Add a Line class to the Graphics project. The Line class should derive from Shape.
					Add 1 field with getter/setter: a Point2D property called endPt.
					Add a constructor that takes a start Point2D, end Point2D, and console color. Make sure to call the base constructor. Don’t duplicate what the base constructors do.
					Implement the pseudocode for the plotLine and plot methods. (see the pseudo-code for plotLine below).
					NOTE: plot is a method that moves the cursor to the x,y position and prints a space.
					Override the draw method of the Shape class (that means you need to mark the base as virtual).
					Do not call the base.
					Instead, set the background color, call plotLine, then reset the color.

					In Main, add code to case 2 of the menu switch.
					Generate 2 random Point2D points with an x,y anywhere in the console.
					Use those points to create a Line instance with any color you want.
					Call draw on the Line instance.

			*/
			//generates 2 random pairs of x values and y values, and a random colour
			int x1 = (rand() % Console::GetWindowWidth());
			int y1 = (rand() % Console::GetWindowHeight());
			int x2 = (rand() % Console::GetWindowWidth());
			int y2 = (rand() % Console::GetWindowHeight());
			ConsoleColor colour = ConsoleColor(1 + rand() % 7);
			//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default

			//generates 2 random points
			Point2D point1(x1, y1);
			Point2D point2(x2, y2);

			//creates line object and draw method
			Line line(point1, point2, colour);
			line.draw();

			break;
		}
		case 3:
		{
			/*

				Part B-2: Add a Rectangle class to the Graphics project. The Rectangle class should derive from Shape.
					Add 2 int fields with getters/setters: width and height.
					Add 1 vector<Line> field: lines.
					Add 1 constructor with the following parameters: width, height, startPt, color.
					Pass the startPt and color to the base constructor.
					Use width and height to set the properties. The constructor should create 4 Lines and add them to the lines field.
					The 4 Lines:
					•	top left to top right
					•	top right to bottom right
					•	bottom left to bottom right
					•	top left to bottom left
					Override the draw method of the Shape class (that means you need to mark the base as virtual). Do not call the base. Instead, call the draw method of each Line in the lines list.

					In Main, add code to case 3 of the menu switch.
					•	Generate a random Point2D point with an x,y anywhere in the console. This point will be the top-left position of the Rectangle.
					•	Calculate a random width and height – ensure that it will NOT extend the Rectangle beyond the bounds of the console.
					•	Use the point, width, and height to create a Rectangle instance with any color you want.
					•	Call draw on the Rectangle instance.

			*/
			//generates a random x value, y value, a random width value, a random height value, and a random colour
			int x = (rand() % Console::GetWindowWidth());
			int y = (rand() % Console::GetWindowHeight());
			int width = (rand() % Console::GetWindowWidth());
			int height = (rand() % Console::GetWindowHeight());
			ConsoleColor colour = ConsoleColor(1 + rand() % 7);
			//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default
			
			if (x + width > Console::GetWindowWidth()) {
				width = (x + width) - Console::GetWindowWidth() % (x + width);
			}
			if (y + height > Console::GetWindowHeight()) {
				height = (y + height)-Console::GetWindowHeight() % (y + height);
			}


			//generates a random point
			Point2D point(x, y);

			//creates rectangle object and draw method
			Rectangle rectangle(width, height, point, colour);
			rectangle.draw();

			break;
		}
		case 4:
		{
			/*

				Part B-3:Add a Triangle class to the Graphics project. The Triangle class should derive from Shape.
					Add 2 Point2D fields with getters/setters: p2 and p3.
					Add 1 vector<Line> field: lines.
					Add 1 constructor with the following parameters: p1, p2, p3, color.
					Pass the p1 and color to the base constructor.
					Use p2 and p3 to set the data.
					The constructor should create 3 Lines connecting the points and add them to the lines field.
					The 3 Lines:
					•	P1 to p2
					•	p2 to p3
					•	p3 to p1

					Override the draw method of the Shape class (that means you need to mark the base as virtual).
					Do not call the base. Instead, call the draw method of each Line in the lines vector.


					In Main, add code to case 4 of the menu switch.
					•	Generate 3 random Point2D points with an x,y anywhere in the console.
					•	Use the points to create a Triangle instance with any color you want.
					•	Call draw on the Triangle instance.


			*/
			//generates 3 random pairs of x values and y values, and a random colour
			int x1 = (rand() % Console::GetWindowWidth());
			int y1 = (rand() % Console::GetWindowHeight());
			int x2 = (rand() % Console::GetWindowWidth());
			int y2 = (rand() % Console::GetWindowHeight());
			int x3 = (rand() % Console::GetWindowWidth());
			int y3 = (rand() % Console::GetWindowHeight());
			ConsoleColor colour = ConsoleColor(1 + rand() % 7);
			//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default

			//generates 3 random points
			Point2D point1(x1, y1);
			Point2D point2(x2, y2);
			Point2D point3(x3, y3);

			//creates triangle object and draw method
			Triangle triangle(point1, point2, point3, colour);
			triangle.draw();

			break;
		}
		case 5:
		{
			/*

				Part B-4:Add a Circle class to the Graphics project. The Circle class should derive from Shape.
					Add 1 int field with a getter/setter: radius.
					Add 1 constructor with the following parameters: radius, startPt, color.
					Pass the startPt and color to the base constructor.
					Use radius parameter to set the radius data.

					Implement the pseudocode for the drawCircle, drawCirclePoints, and plot methods. (see the pseudo-code below).
					NOTE: plot is a method that moves the cursor to the x,y position and prints a space.

					Override the draw method of the Shape class (that means you need to mark the base as virtual).
					Do not call the base. Instead, set the background color, call drawCircle, then reset the color.


					In Main, add code to case 5 of the menu switch.
					•	Generate a random Point2D point with an x,y anywhere in the console. This point will be the center position of the Circle.
					•	Calculate a random radius – ensure that it will NOT extend the Circle beyond the bounds of the console.
					•	Use the point and radius to create a Circle instance with any color you want.
					•	Call draw on the Circle instance.


			*/
			//generates a random x value, y value, and a random colour
			int x = (rand() % Console::GetWindowWidth());
			int y = (rand() % Console::GetWindowHeight());
			ConsoleColor colour = ConsoleColor(1 + rand() % 7);
			//random colour between 1 - 7 and not the range of the whole enum because 0 is black and wouldn't be visible, there is no 8, and 9 is default

			//generates random point
			Point2D point(x, y);
			
			//generates a random radius value
			//finds the distance between the point and each edge of the console window
			int d1 = abs(x - 0);//left
			int d2 = abs(x - Console::GetWindowWidth());//right
			int d3 = abs(y - Console::GetWindowHeight());//top
			int d4 =  abs(y - 0);//bottom
			int minDistance = std::min(std::min(d1,d2),std::min(d3,d4)); //finds the min of all distances
			int radius = (rand() % minDistance);

			//creates circle object and draw method
			Circle circle(radius ,point, colour);
			circle.draw();

			break;
		}
		case 6:
		{
			/*

				Part C-1: Create a class called ShapeFactory.

				Add a static method for creating a random point, a random color, and for each Shape type to create a random Shape.
					The methods that create the random Shapes should use make_unique and return a unique_ptr.

					RandomPoint should return a random Point2D struct.
					RandomColor should return a random ConsoleColor.
					RandomShape should return a random Shape.
					RandomLine should return a random Line.
					RandomRectangle should return a random Rectangle.
					RandomTriangle should return a random triangle.
					RandomCircle should return a random Circle.



				Part C-2: add code to case 6 of the menu switch.
				•	Create a vector variable that holds unique_ptr of Shapes.
				•	Create 100 random Shapes and add them to the vector.
					o	Randomly pick which type of Shape to create (Shape, Line, Rectangle, Triangle, Circle).
					o	Create the instance according to its Shape. (call the appropriate method of the ShapeFactory)
				•	After this loop, loop over the Shapes vector and call draw on each Shape.



			*/

			break;
		}
		default:
			break;
		}

		Input::PressEnter(true);

	} while (menuSelection != menuOptions.size());
}