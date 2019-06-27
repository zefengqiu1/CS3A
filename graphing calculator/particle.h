#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <string>
#include "random.h"
#include <constants.h>
#include <SFML/Graphics.hpp>
using namespace std;

class Particle
{
public:
    Particle();
    virtual void Step(int command);
    virtual void Draw(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    sf::Vector2f vel;


};

#endif // PARTICLE_H
