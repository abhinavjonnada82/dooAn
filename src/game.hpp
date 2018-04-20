
#ifndef GAME_HPP
#define GAME_HPP

#include "critter.hpp"



enum Move {UP=0, DOWN, LEFT, RIGHT};

//the number of each critter we initialize the world with
const int INIT_DOODLEBUG_COUNT = 5;//no. of initial bugs
const int INIT_ANT_COUNT = 100;//no. initial ants
const int DIM = 20; //size of the world
//
//time step between breeding of ants, bugs and if they have not eaten
const int BREED_ANTS = 3;
const int BREED_BUGS = 8;
const int STARVE_BUGS = 3;

struct Coordinate {
	
	int x;
	int y;
	
};


//typedef Organism* OrganismPtr;
//typedef Game* GamePtr;

class Game {

	
 private:
    Critter* world[DIM][DIM]; //The way the grid works, it starts at top-left corner
    //loops through one column at a time and ends at the bottom right corner
    
    void createLife(OrganismType cType, int count);//Randomly create count many critter of type cType
    //it uses parameterized constructor in Ant and Bug
    
    void resetC();//reset critters to not move
    
    void moveC(OrganismType aType);// move critter of type aTYpe to move, 
    //moves critter which hasn't moved already
    
    void cleanup();//removes starved bugs by iterating through the grid and
    //uses the methof  Organism::isDead() to test if an organism is dead
    
    void breedC();//breed every critter by iteration and only the ones which
    //have moved and not new ones  
    
    /*int timeStepCount;
    int generateRandomNumber(int startRange, int endRange) const;*/
    
    
 public:
 //constructor: creates and initializes the game and seed is usd for seeding 
 //the random behaviour
    Game(unsigned int seed);
    ~Game();
    Critter* getAt(int x, int y) const; //returns the critter at the given coor
    void setAt(int x, int y, Critter* critt);//sets the critter at position (x,y)
    void display() const;//dislays this world
    void simulateStep();//simulate one step
    Coordinate randomPosition() const;//retrns a random position 
    Move randomMove() const;//returns a random move (UP, DOWN, LEFT or RIGHT)    
};

#endif
