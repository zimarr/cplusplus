#ifndef SNEK_H
#define SNEK_H

#include <vector>
#include <SDL.h>
#include <queue>
#include <iostream>

using namespace std;

struct Position {
    public:
        //Instance Variables
        int x, y;

        //Constructors
        Position();
        Position(int x, int y);

        //Methods
        bool inBounds();

        //Operators
        Position operator+(const Position& other) const;
        Position& operator+=(const Position& other);
        bool operator==(const Position& other) const;
        bool operator!=(const Position& other) const;
        friend ostream& operator<<(ostream& os, const Position& obj);
};

class Part {
    public:
        //Instance Variables
        Position pos;
    public:
        //Constructors
        Part();
        Part(int x, int y);
        Part(Position p);

        //Methods
        void drawPart(SDL_Renderer *rend);
};

class Body {
    private:
        //Instance Variables
        vector<Part> body;
        Part *head;
        queue<Position> direc;
        Position direction;
    public:
        //Constructors
        Body();

        

        //Get
        int getHeadPos();
        Position getDirection();

        //Set
        void setDirection(Position dir);
        
        //Methods
        void drawBody(SDL_Renderer *rend);
        void updateBody(SDL_Renderer *rend);

        void switchDirection(Position dir);
        void pushDirection(Position dir);  

        void printDirections();

        bool containsPos(Position p);
        bool checkLost(Position p);
};

class Fruit {
    public:
        //Instance Variables
        Position pos;
    public:
        //Constructors
        Fruit();
        Fruit(int x, int y);

        //Set
        void setRandom();

        //Methods
        void drawFruit(SDL_Renderer *rend);
};










#endif