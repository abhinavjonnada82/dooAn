#include <iostream>
#include <cstdlib> //for random
#include "game.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

using namespace std;

//Default constructor: creates and iniitializes the world
//the seed is used for seeding the random behaviour

Game::Game(unsigned int seed) 
{
	//seed the random generator
	srand(seed);
	//create an empty world
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			world[i][j] = NULL;

		}
	}

	createLife(ANT, INIT_ANT_COUNT);
	//creates 3 ANTS
	createLife(BUG, INIT_DOODLEBUG_COUNT);
	//creates 8 doodlebugs
}

Game::~Game() {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			if (world[i][j] != NULL) {
				delete world[i][j];
			}
		}
	}
}

//Return the critter at the given coordinates
//if the coordinates are not valid, returns null

Critter* Game::getAt(int x, int y) const {
	if (( x >= 0) && (x < DIM) && (y >= 0) && (y < DIM)){
		return world[x][y];
	} 
	else {
		return NULL;
	}
}
//set the entry at x,y to the value passed in

void Game::setAt(int x, int y, Critter* critt) {
	if (( x >= 0) && ( x < DIM) && (y >= 0) && (y < DIM)) {
		world[x][y] = critt;
	}
}

//Display the world in ASCII

void Game::display()const {
	int numAnts = 0;
	int numBugs = 0;
	cout << endl;
	for (int j = 0; j < DIM; j++){
		for (int i =0; i < DIM; i++){
			if (world[i][j] == NULL) {
				cout << ".";
			}
			else {
				if (world[i][j] -> getType() == ANT) {
					numAnts++;
				}
				else if (world[i][j]-> getType() == BUG) {
					numBugs++;
				}
				cout << world[i][j] -> rep();
			}
		}
		cout << endl;
	}
	cout <<"Ants:"<< numAnts << "Doodlebugs:"<< numBugs << endl;
}

void Game::simulateStep() {
	//Simulates one turn
	//1.) Move Doodlebugs
	//2.) Move Ants
	//3.) Make Doodlebug starve (which happens under a certain condition)
	//4.) Make Critters Breed (which happens under a certain condition)

	//Reset
	resetC();
	//Move
	moveC(BUG);
	moveC(ANT);
	cleanup();//Make doodlebug starve
	breedC();//Make them breed;
}

Coordinate Game::randomPosition() const { //returns a random number in the range 0 to MAX-1
    Coordinate c;
	c.x = rand() % DIM;
	c.y = rand() % DIM;
	return c;
}

Move Game::randomMove() const {
	return static_cast<Move>(rand()% 4);
}

//Private Functions

void Game::createLife(OrganismType cType, int count) {
	int cCount = 0;
	while (cCount < count) {
		Coordinate c = randomPosition();

		//Pnly put ani in empty spot
		if (world[c.x][c.y] == NULL) {
			cCount++;
			if (cType == ANT) {
				new Ant(this, c.x, c.y); //create an Ant and place it in the grid
			}
			else if (cType == BUG) {
				new Doodlebug(this, c.x, c.y); //create a bug and put it into the world
			}
		}
	}
}

//Reset
void Game::resetC() {
	for(int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if(world[i][j] != NULL)
			{
				world[i][j] ->setMoved(false);
			}
		}
	}
}

void Game::moveC(OrganismType aType) {
	for (int i = 0; i < DIM ; i++) {
		for (int j = 0; j < DIM; j++) {
			if (world[i][j] != NULL) {
				if (world[i][j] -> getType() == aType && !(world[i][j]->hasMoved()))
				{
					world[i][j]->move();
				}
			}
		}
	}
	
}

//Remove all dead critters from the world

void Game::cleanup() {
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if ((world[i][j] != NULL) && world[i][j]->isDead()) {
				delete world[i][j];
				world[i][j] = NULL;
			}
		}
	}
}

void Game::breedC() {
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (world [i][j] != NULL)
			{
				world[i][j] -> breed();
			}
		}
	}
}
// int Game::generateRandomNumber(int startRange, int endRange) const {
// 	return rand() % (endRange - startRange + 1) + startRange;
	
// }

// Game::Game() {
// 	srand(time(NULL));
// 	timeStepCount = 0;
	
// 	for (int x = 0; x < dim; x++)
// 	  for (int y = 0; y < dim; y++)
// 	    world[x][y] = nullptr;
// }

// void Game::startGame() {
// 	int x, y;
// 	int doodlebugCount = 0;
// 	int antCount = 0;
	
// 	while (doodlebugCount < INIT_DOODLEBUG_COUNT) {
// 		x = generateRandomNumber(0, DIM -1);
// 		y = generateRandomNumber(0, DIM -1);
// 		if (world[x][y] != nullptr) continue;
// 		world[x][y] = new Doodlebug(this, x, y);
// 		doodlebugCount++;
// 	}
	
// 	while (antCount < INIT_ANT_COUNT_COUNT) {
// 		x = generateRandomNumber(0, DIM -1);
// 		y = generateRandomNumber(0, DIM -1);
// 		if (world[x][y] != nullptr) continue;
// 		world[x][y] = new Ant(this, x, y);
// 		antCount++;
// 	}


// void Game::takeTimeStep() {
// 		timeStepCount++;
		
// 		for (int x = 0; x < DIM; x++){
// 			for (int y = 0; y < DIM; y++){
// 				if (world[x][y] == nullptr) continue;
// 				if (world[x][y]->getType() == DOODLEBUG)
// 				  world[x][y]->move();
// 			  }
// 		  }
		  
// 		  for (int x = 0; x < DIM; x++){
// 			for (int y = 0; y < DIM; y++){
// 				if (world[x][y] == nullptr) continue;
// 				if (world[x][y]->getType() == ANT)
// 				  world[x][y]->move();
// 			  }
// 		  }
		  
// 		  for (int x = 0; x < DIM; x++){
// 			for (int y = 0; y < DIM; y++){
// 				if (world[x][y] == nullptr) continue;
// 				world[x][y]->breed();
// 			  }
// 		  }
		  
// 		    for (int x = 0; x < DIM; x++){
// 			for (int y = 0; y < DIM; y++){
// 				if (world[x][y] == nullptr) continue;
// 				if (world[x][y]->starves()){
// 					delete world[x][y];
// 					world[x][y] = nullptr;
// 			  }
// 		  }
// 	  }
//   }
  
  
// void Game::printWorld() const {
// 	for (int x = 0; x < DIM; x++){
// 	  for (int y = 0; y < DIM; x++) {
// 		  if (world[x][y] == nullptr)
// 		    cout << '-';
// 		  else if (world[x][y] -> getType() == ANT)
// 		    cout << 'o';
// 		  else 
// 		    cout << 'X';
// 		}
// 		cout << endl;
// 	}
// }

  

// }
		  
		  
		  
		  
		  
