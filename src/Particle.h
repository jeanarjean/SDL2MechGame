#ifndef PARTICLE_H
#define PARTICLE_H
#include <SDL_video.h>
#include <SDL_image.h>
class LTexture;
class Particle
{
public:
	//Initialize position and animation
	Particle(int x, int y, LTexture* particleTextures) ;

	//Shows the particle
	void render(SDL_Renderer *gRenderer, LTexture* particleTextures);

	//Checks if particle is dead
	bool isDead();

private:
	//Offsets
	int mPosX, mPosY;

	//Current frame of animation
	int mFrame;

	//Type of particle
	LTexture* mTexture;
};
#endif