/*
date 9.11.2020

Q.	A superellipse is a two-dimensional shape defined by the equation

	|x/a|^m+|y/b|^m = 1;		(m,a,b are positive numbers)
//instead of |x/a|^m+|y/b|^n = 1;(m,n are positive numbers). which is from the book.	(?)

Look up superellipe on the web to get a better idea of what such shapes look like.
Write a program that draws "starlike" patterns by connecting points on a superellipse.
Take a,b,m,N as arguments.
Select N points on the superellipse defined by a,b,m. Make the points equally spaced for
some definition of "equal". Connect each of those N points to one oor more othher points
(if you like you can make the number of points to which to connect a point another argument
 or just use N - 1, i.e. all the other points).

A.
I couldn't find how to put the axis center-0-style
so for now, I skip this exercise

*/

#include"Simple_window.h"
#include"Graph.h"
#include<cmath>

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,x_max() - 20,y_max() - 60,"Canvas" };

	Point center{ win.x_max() / 2 ,win.y_max() / 2 };

//	int notches = int((win.x_max() - 80) / ((win.y_max() - 80) / 20));
/*
	Axis xa{ Axis::x, center,- 74,10,"x axis" };
	win.attach(xa);
	xa.set_color(Color::black);

	Axis ya{ Axis::y,Point{win.x_max() / 2,win.y_max() - 20}, win.y_max() - 80,20,"y axis" };
	win.attach(ya);
	ya.set_color(Color::black);
*/
	win.wait_for_button();
}