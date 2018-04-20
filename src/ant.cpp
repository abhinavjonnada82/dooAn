#include <iostream>
#include <cstdlib>
#include "ant.hpp"
#include "critter.hpp"
#include "game.hpp"

using namespace std;

Ant::Ant(Game* aWorld, int xC, int yC) : Critter(aWorld, xC, yC)
{
  
}

void Ant::move()
{
  timeLapse++;
  Move mover = world->randomMove();
  switch (mover) {
    case UP:
         if(world->getAt(x, y + 1) == NULL && inLimit(x, y + 1))
         {
           moveTo(x, y + 1);
         }
         break;
    case DOWN:
         if(world->getAt(x, y - 1) == NULL && inLimit(x, y - 1))
         {
           moveTo(x, y - 1);
         }
         break;
    case LEFT:
        if(world->getAt(x - 1, y) == NULL && inLimit(x - 1, y))
        {
          moveTo(x - 1, y);
        }
        break;
    case RIGHT:
        if(world->getAt(x + 1, y) == NULL && inLimit(x + 1, y))
        {
          moveTo(x + 1, y);
        }
        break;
    default:
        break;

  }

}

void Ant::generateOffSpring(int wX, int wY)
{
  new Ant(this -> world, wX, wY);
  timeLapse = 0;
}

void Ant::breed()
{
  if (timeLapse >= BREED_ANTS)
  {
    breedAtAdjacentCell();
  }
}


OrganismType Ant::getType() const
{
  return ANT;
}

char Ant::rep()const
{
  return 'o';
}
int Ant::size() const
{
  return 10;
}
bool Ant::inLimit(int xX, int yY)
{
  return (xX >= 0) && (xX < DIM) && (yY >= 0) && (yY < DIM);
}


// vector<int> Doodlebug::getMovesToAnts(int x, int y) const {
//   vector<int> movesToAnts;
//   int tempX, tempY;
//   for (int move = LEFT; move <= UP; move++){
//     tempX = x;
//     tempY = y;
//     getCoordinate(tempX, tempY, move);
//     if (!isValidCoordinate(tempX, tempY)) continue;
//     if (currGame->world[tempX][tempY] == nullptr) continue;
//     if (currGame->world[tempX][tempY]->getType() == ANT) 
//       movesToAnts.push_back(move);
//   }
//   return movesToAnts;
// }

// Doodlebug::Doodlebug(GamePtr currGame, int x, int y): Organism(currGame, x, y){
//   timeTillStarve = DOODLEBUG_STARVE_TIME;
//   timeTillBreed = DOODLEBUG_BREED_TIME;
// }

// void Doodlebug::breed(){
//   if (timeTillBreed > 0) return;
//   vector<int> validMoves = getMovesToEmptyCells(x, y);
//   if (validMoves.size() == 0) return;
//   int randomMove = validMoves[currGame->generateRandomNumber(0, validMoves.size() - 1)];
//   int newX = x;
//   int newY = y;
//   getCoordinate(newX, newY, randomMove);
//   currGame->world[newX][newY] = new Doodlebug(currGame, newX, newY);
//   timeTillBreed = DOODLEBUG_BREED_TIME;
// }

// void Doodlebug::move(){
//   if (timeStepCount == currGame->timeStepCount) return;
//   vector<int> movesToAnts = getMovesToAnts(x, y);
//   if (movesToAnts.size() == 0){
//     Organism::move();
//     timeTillStarve--;
//     return;
//   }
//   timeStepCount++;
//   timeTillStarve = DOODLEBUG_STARVE_TIME;
//   int randomMove = movesToAnts[currGame->generateRandomNumber(0, movesToAnts.size() - 1)];
//   int antX = x;
//   int antY = y;
//   getCoordinate(antX, antY, randomMove);
//   delete currGame->world[antX][antY];
//   currGame->world[antX][antY] = this;
//   currGame->world[x][y] = nullptr;
//   x = antX;
//   y = antY;
// }
