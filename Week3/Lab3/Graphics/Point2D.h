#pragma once
//struct Point2D with 2 public member fields int x and int y
struct Point2D {
	int mX;
	int mY;

	//constructor Point2D with 2 parameters used to initialize int x and int y
	Point2D(int x, int y) : mX(x), mY(y) {
	}
};