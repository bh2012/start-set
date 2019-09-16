// shape.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

class Rectangle {
private:
	double width;
	double height;
public:
	Rectangle(double w, double h);
	double Area();

};
Rectangle::Rectangle(double w, double h) {
	width = w;
	height = h;
}
double Rectangle::Area() {
	return width * height;
}
class Circle {
private:
	double radius;
	double pi = 3.1415926535897;
public:
	Circle(double r_in);
	double circle_area();
	double circumference();
};
Circle::Circle(double r_in){
	radius = r_in;
	}
double Circle::circle_area() {
	return pi * radius * radius;
}
double Circle::circumference() {
	return 2 * pi * radius;
}
int main()
{
   vector<string> shape_names = { "Rectangle", "Circle"};
   string user_selection;
   bool valid = false; 
   cout << "What shape do you want to make? ";
   cin >> user_selection;
   while (valid == false) {
	   if (user_selection.compare("Rectangle") == 0) {
		   valid = true;
		   double w = 0;
		   double h = 0;
		   cout << "Width: ";
		   cin >> w;
		   cout << "Height: ";
		   cin >> h;
		   Rectangle rect(w, h);
		   cout << "You made a rectangle with width " << w << " And height " << h << "\n";
		   cout << "The area of your rectangle is " << rect.Area();


	   }
	   else if (user_selection.compare("Circle") == 0) {
		   valid = true;
		   double r_in = 0;
		   cout << "Radius: ";
		   cin >> r_in;
		   Circle cir(r_in);
		   cout << "You made a circle with radius " << r_in << "\n";
		   cout << "The circle has an area of " << cir.circle_area() << "\n";
		   cout << "The circle has a circumference of " << cir.circumference() << "\n";
	   }
	   else {
		   cout << "Please enter a valid shape name ";
		   cin >> user_selection;
	   }
   }
 
   return 0;

   }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
