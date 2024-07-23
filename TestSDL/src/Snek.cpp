#include "Snek.h"
#include <SDL.h>
#include "drawStuff.h"
#include <iostream>
#include <random>
#include "globals.h"
#include <vector>

Position::Position() { }

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Position:: inBounds() {
    return x > 0 && y > 0 && x <= 11 && y <= 11;
}

Position Position::operator+(const Position& other) const {
    return Position(this->x + other.x, this->y + other.y);
}

Position& Position::operator+=(const Position& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

bool Position::operator==(const Position& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Position::operator!=(const Position& other) const {
    return this->x != other.x || this->y != other.y;
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    os << "{" << pos.x << ", " << pos.y << "}";
    return os;
}

// ======================================================

Part::Part() { }

Part::Part(int x, int y) {
    pos.x = x;
    pos.y = y;
}

Part::Part(Position p) {
    pos = p;
}

void Part::drawPart(SDL_Renderer *rend) {
    setColor(rend, 0, 255, 45);
    
    int x = (pos.x - 1) * 40 + 4;
    int y = (pos.y - 1) * 40 + 4;

    fillRect(rend, x, y, 40, 40);
}

// ======================================================

Body::Body() {
    body.push_back(Part(3, 6));
    head = &body[0];
    // direc.push(Position(1, 0));
    
    direction = Position(1, 0);

}

void Body::drawBody(SDL_Renderer *rend) {
    for (Part p : body) {
        p.drawPart(rend);
    }
}

void Body::updateBody(SDL_Renderer *rend) {
    
    
    
    
    
    
    
    
    if (direc.size() > 0) {
        direction = direc.front();
        direc.pop();
    }
    
    
    body.insert(body.begin(), Part(head->pos + direction));
    head = &body[0];
    
    bool growing = false;
    
    if (head->pos == apple.pos) {
        apple.setRandom();
        growing = true;
    } else if (checkLost(head->pos)) {
        SDL_Delay(2500);
        SDL_Quit();
    }

    

    if (!growing) {
        body.pop_back();
    }
}



int Body::getHeadPos() {
    return body[0].pos.x;
}

// void Body::setDirection(Position dir) {
//     direction = dir;
// }


Position Body::getDirection() {
    return direction;
}

bool Body::containsPos(Position p) {
    for (Part part : body) {
        if (part.pos == p) {
            return true;
        }
    }
    return false;
}

bool Body::checkLost(Position p) {
    for (int i = 1; i < body.size(); i++) {
        if (body[i].pos == p) {
            return true;
        }
    }

    if (!p.inBounds()) {
        return true;
    }

    return false;
}

void Body::switchDirection(Position dir) {
    if (direc.size() == 0 && direction + dir != Position(0, 0)) {
        pushDirection(dir);
    } else if (direc.size() == 1 && direc.front() + dir != Position(0, 0)) {
        pushDirection(dir);
    }
}

void Body::pushDirection(Position dir) {
    if (direc.size() < 2) {
        direc.push(dir);
    }
}

void Body::printDirections() {
    queue<Position> print = direc;
    while (!print.empty()) {
        cout << print.front() << " | ";
        print.pop();
    }
    // cout << direc.front() << " | " << direc.back();
}

// ======================================================

Fruit::Fruit() {
    pos.x = 9;
    pos.y = 6;
}

Fruit::Fruit(int x, int y) {
    pos.x = x;
    pos.y = y;
}

void Fruit::drawFruit(SDL_Renderer *rend) {
    setColor(rend, 255, 0, 0);
    
    int x = (pos.x - 1) * 40 + 4;
    int y = (pos.y - 1) * 40 + 4;

    fillRect(rend, x, y, 40, 40);
}

void Fruit::setRandom() {
    std::random_device ran;
    std::mt19937 rng(ran());

    std::uniform_int_distribution<> dis(1, 11);

    pos.x = dis(rng);
    pos.y = dis(rng);

    while (snake.containsPos(pos)) {
        pos.x = dis(rng);
        pos.y = dis(rng);
    }
}



