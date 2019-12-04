#ifndef DOT_H
#define DOT_H
#include <SDL.h>
#include "LTexture.h"
class Particle;
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    static const int TOTAL_PARTICLES = 20;
    static const int GRAVITY_SPEED = 2;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	LTexture* particleTextures;
	LTexture* gDotTexture;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variables and allocates particles
	Dot(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, LTexture* particleTextures, LTexture* gDotTexture);

    //Deallocates particles
    ~Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    //Moves the dot
    void move();

    //Shows the dot on the screen
    void render(SDL_Renderer* gRenderer);

private:
    //The particles
    Particle *particles[TOTAL_PARTICLES];

    //Shows the particles
    void renderParticles(SDL_Renderer* gRenderer);

    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
};
#endif