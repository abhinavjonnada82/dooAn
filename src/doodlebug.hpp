#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP


#include <iostream>
#include "game.hpp"
#include "critter.hpp"



class Doodlebug: public Critter {


// private:
//   int timeTillStarve;
//   //given a coordinate of the cell(x,y),
//   //returns a list of valid moves to adjacent 
  // vector<int> getAntsToMove(int x, int y) const;
  

public:
  
  Doodlebug(Game* aWorld, int xC, int yC);
  void breed();
  void move();
  OrganismType getType() const;//returns the type of critter
  char rep() const;//the char rep of critter
  int size() const; //size of the criiter
  bool isDead() const; //returns true if critter is dead, flase otherwise
  bool inLimit(int xX, int yY);

private:
  
  void generateOffSpring(int wX, int wY);
  int deathCount;
};


#endif


  
