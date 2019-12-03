#ifndef DOT_H
#define DOT_H
class Particle;
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    static const int TOTAL_PARTICLES = 20;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variables and allocates particles
    Dot();

    //Deallocates particles
    ~Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    //Moves the dot
    void move();

    //Shows the dot on the screen
    void render();

private:
    //The particles
    Particle *particles[TOTAL_PARTICLES];

    //Shows the particles
    void renderParticles();

    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
};
#endif