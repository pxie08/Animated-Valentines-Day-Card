/****************************************************
**hw4.cpp
**Valentine's Day
**Patrick Xie, (02/05/2010)
*****************************************************/

#include "ccc_win.h"
#include <time.h>
using namespace std;

//declared functions
void drawHeart();
void drawCouple();

/****************************************************
**drawHeart: draws hearts
**Parameters: point; double scale for changing 
			  scale of hearts
**returns: nothing
*****************************************************/
void drawHeart(Point mouseClick, double scale){
	cwin	//right side of heart
		<<	Line(Point((mouseClick.get_x()),(mouseClick.get_y()+1*scale)),
				 Point((mouseClick.get_x()+1*scale),(mouseClick.get_y()+3*scale)))

		<<	Line(Point((mouseClick.get_x()+1*scale),(mouseClick.get_y()+3*scale)),
				 Point((mouseClick.get_x()+2*scale),(mouseClick.get_y()+4*scale)))

		<<	Line(Point((mouseClick.get_x()+2*scale),(mouseClick.get_y()+4*scale)),
				 Point((mouseClick.get_x()+3*scale),(mouseClick.get_y()+4*scale)))

		<<	Line(Point((mouseClick.get_x()+3*scale),(mouseClick.get_y()+4*scale)),
				 Point((mouseClick.get_x()+5*scale),(mouseClick.get_y()+1*scale)))

		<<	Line(Point((mouseClick.get_x()+5*scale),(mouseClick.get_y()+1*scale)),
				 Point((mouseClick.get_x()),(mouseClick.get_y()-6*scale)))

		//left side of heart
		<<	Line(Point((mouseClick.get_x()),(mouseClick.get_y()+1*scale)),
				 Point((mouseClick.get_x()-1*scale),(mouseClick.get_y()+3*scale)))

		<<	Line(Point((mouseClick.get_x()-1*scale),(mouseClick.get_y()+3*scale)),
				 Point((mouseClick.get_x()-2*scale),(mouseClick.get_y()+4*scale)))

		<<	Line(Point((mouseClick.get_x()-2*scale),(mouseClick.get_y()+4*scale)),
				 Point((mouseClick.get_x()-3*scale),(mouseClick.get_y()+4*scale)))

		<<	Line(Point((mouseClick.get_x()-3*scale),(mouseClick.get_y()+4*scale)),
				 Point((mouseClick.get_x()-5*scale),(mouseClick.get_y()+1*scale)))

		<<	Line(Point((mouseClick.get_x()-5*scale),(mouseClick.get_y()+1*scale)),
				 Point((mouseClick.get_x()),(mouseClick.get_y()-6*scale)));
	return;
}


/****************************************************
**drawCouple: draws two stick figures
**Parameters: none
**returns: two stick figures
*****************************************************/
void drawCouple(){
	//person right
	cwin << Circle(Point(1.25,-5), 1);
	cwin << Line(Point(1.25,-6),Point(1.25,-8));
	cwin << Line(Point(1.25,-8),Point(0.25,-9.5));
	cwin << Line(Point(1.25,-8),Point(2.25,-9.5));
	//person left
	cwin << Circle(Point(-1.25,-5), 1);
	cwin << Line(Point(-1.25,-6),Point(-1.25,-8));
	cwin << Line(Point(-1.25,-8),Point(-0.25,-9.5));
	cwin << Line(Point(-1.25,-8),Point(-2.25,-9.5));
	//touching hands
	cwin << Line(Point(1.25,-6.5),Point(0,-7.5));
	cwin << Line(Point(-1.25,-6.5),Point(0,-7.5));
	//other arms
	cwin << Line(Point(-1.25,-6.5),Point(-2.5,-7.5));
	cwin << Line(Point(1.25,-6.5),Point(2.5,-7.5));
	return;
}


/****************************************************
**pause: pauses the animation 
**Parameters: int milimeters
**returns: nothing
*****************************************************/
void pause(int x){
    clock_t goal = x + clock();
    while (goal > clock());
}


int ccc_win_main() {

	string userResponse = "y";
	while (userResponse == "y" || userResponse == "Y") {
		string usersName= cwin.get_string("What is your name? ");
		string inputName = cwin.get_string("What is the name of the person you like? ");
		drawCouple();
		cwin << Message(Point(-8.75,-9.5), "This is " + usersName + " and " + inputName + ".");

		double scale=0.03;
		int clickerCount = 0;

		while (clickerCount <=4) {
			Point clicker1 = cwin.get_mouse("Click somewhere!");
			cwin << clicker1;
			clickerCount ++;

			Point clicker2 = cwin.get_mouse("Click somewhere again!");
			cwin << clicker2;
			clickerCount ++;

			Point clicker3 = cwin.get_mouse("Click somewhere again!");
			cwin << clicker3;
			clickerCount ++;

			Point clicker4 = cwin.get_mouse("Click somewhere again!");
			cwin << clicker4;
			clickerCount ++;

			while ( clickerCount >= 4 && clickerCount <=35){
				cwin.clear();
				drawCouple();
				cwin << Message(Point(-8.75,-9.5), "This is " + usersName + " and " + inputName + ".");
				drawHeart(clicker1, 1.5*scale);
				drawHeart(clicker2, scale);
				drawHeart(clicker3, 0.5*scale);
				drawHeart(clicker4, 0.75*scale);
				pause(100);
				scale +=0.02;
				clickerCount++;
			}
			cwin << Message(Point(-9,8), usersName+ " and " + inputName);
			pause(1000);
			cwin << Message(Point(-9,7), "bound by fate");
			pause(1000);
			cwin << Message(Point(-9,6), "never to be apart,");
			pause(1000);
			cwin << Message(Point(-9,5), "no matter the wait");
			pause(1000);
			cwin << Message(Point(-9,4), "to be a new start,");
			pause(1000);
			cwin << Message(Point(-9,3), "once begun");
			pause(1000);
			cwin << Message(Point(-9,2), "there will be no other,");
			pause(1000);
			cwin << Message(Point(-9,1), "that compares to your hun.");
			pause(1000);
			cwin << Message(Point(-9,0), "Stay in Love,");
			pause(1000);
			cwin << Message(Point(-9,-1), "and Watch it Grow,");
			pause(1000);
			cwin << Message(Point(-9,-2), "just like these hearts.");
			pause(1000);
			cwin << Message(Point(-9,-3), "Happy Valentine's Day! :)");
			pause(1000);
		}

		userResponse = cwin.get_string("Watch again? (y/n): ");
		cwin.clear();
	}
	cwin.clear();
	return 0;
}