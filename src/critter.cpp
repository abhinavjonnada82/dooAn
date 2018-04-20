#include <iostream>
#include "critter.hpp"
#include "game.hpp"



Critter::Critter(Game* aWorld, int xC, int yC) {
	world = aWorld;
	x = xC;
	y = yC;
	timeLapse = 0;
	moved = false;
	world ->setAt(x, y, this);//sets the critter at position (x,y)
}

//flags the organism as moved or not
void Critter::setMoved(bool hasMoved) {
   moved = hasMoved;
}

bool Critter::hasMoved() const {
	return moved;
}


void Critter::moveTo (int xNew, int yNew){ //moves the organism from coordinnates (x,y) to (xNew, yNew)
      world->setAt(xNew, yNew, world->getAt(x, y));
	  world->setAt(x, y, NULL);

	  x = xNew;
	  y = yNew;

    world->getAt(x, y)->setMoved(true); 

}


void Critter::breedAtAdjacentCell() {

	if((world->getAt(x, y + 1) == NULL ) && inLimit(x, y + 1)) {
		generateOffSpring(x, y + 1);
	}
	else if((world->getAt(x, y - 1) == NULL) && inLimit(x, y -1)) {
        generateOffSpring(x, y - 1);    
	}
	else if((world->getAt(x - 1, y) == NULL) && inLimit(x - 1, y)) {
		generateOffSpring(x - 1, y);
	}
	else if((world->getAt(x + 1, y) == NULL) && inLimit(x + 1, y)) {
		generateOffSpring(x + 1, y);
	}
}

bool Critter::inLimit(int xX, int yY) {
	return (xX >= 0) && (xX < DIM) && (yY >= 0) && (yY < DIM);
}

//returns true if organism is dead, false otherwise
bool Critter::isDead() const {
	return false;
}
// void Critter::getCoordinate(int& x, int& y, int move) const {
	
// 	if (move == LEFT) x--;
// 	if (move == RIGHT) x++;
// 	if (move == UP) y++;
// 	if (move == DOWN) y--;

// }

// bool Critter::isValidCoordinate(int x, int y) const {
// 	if (x < 0 || x >= DIM || y< 0 || y >= DIM)
// 	   return false;
// 	return true; 
// }

// void Critter::move() {
// 	timeStepCount++;
// 	timeTillBreed--;
// 	int randomMove = currGame -> generateRandomNumber(LEFT, UP);
// 	int newX = x;
// 	int newY = y;
//     getCoordinate(newX, newY, randomMove);
//     if (isValidCoordinate(newX, newY)){
// 		if(currGame -> world[newX] [newY} != nullptr) return;
// 		currGame->world[x][y] = nullptr;
// 		currGame->world[newX][newY] = this;
// 		x=newX;
// 		y=newY;
// 	}
// }
// }

// vector<int> Critter::emptyCell(int x, int y) const {
// 	vector<int> moveToEmptyCells;
// 	int tempX, tempY;
// 	for (int move=LEFT; move <= UP; move++) {
// 		tempX=x;
// 		tempY=y;
// 		getCoordinate(temX, tempY, nove);
// 		if(!isValidCoordinate(tempX, tempY)) continue;
// 		if(currGame->world[tempX][tempY] == nullptr)
// 		  moveToEmptyCells.push_back(move);
// 	}
// 	return moveToEmptyCells;
// }
