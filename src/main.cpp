/* ABHINAV JONNADA
 * B956D578
 * 04/04/2018
 * Program 6, SimAnt
 */
 


#include <iostream>
#include <stdio.h>
#include <ctime>
#include "game.hpp"


using namespace std;

int main () {
	
	Game myGame(time(0));
	
	myGame.display();
	
	char ch;
	
	while (cin.get(ch) && ch != 'q'){
		
		myGame.simulateStep();
		myGame.display();
	}
	
	return 0;
}

