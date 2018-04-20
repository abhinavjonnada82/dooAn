#ifndef CRITTER_HPP
#define CRITTER_HPP


enum OrganismType {ANT, BUG};

class Game;

class Critter {
	
public:
//creat a critter at the given coordinates.

	Critter(Game* aWorld, int xC, int yC);    //constructor
	virtual ~Critter() {};
	virtual void breed() = 0; //makes critter breed
	virtual void move() = 0; //moves critter move
	virtual OrganismType getType() const = 0;//returns the type of organism
	void setMoved(bool hasMoved);//flags this organism as moved or not
	virtual char rep() const = 0; //the character rep of this organisn
	virtual int size() const = 0; //the size of the organism
	bool hasMoved() const; //has the organism moved or nor?
	virtual bool isDead() const;//returns true if organism is dead, else false
	bool inLimit(int xX, int yY);
	
protected:
    
    virtual void generateOffSpring(int whereX, int whereY) = 0; //generated an offspring at the given position
    void moveTo (int xNew, int yNew);//moves the organism from coordinnates (x,y) to (xNew, yNew)
    void breedAtAdjacentCell();////breeds at an adjacent cell.
    
    int x; 
    int y;
    
    bool moved;
    
    int timeLapse;//breededticks
    
    Game* world; //pointer to the world in which critter llives
    

};


#endif
