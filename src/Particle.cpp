#include "Particle.h"
#include "LTexture.h"
#include <stdlib.h>
Particle::Particle(int x, int y, LTexture* particleTextures)
{
	//Set offsets
	mPosX = x - 5 + (rand() % 25);
	mPosY = y - 5 + (rand() % 25);

	//Initialize animation
	mFrame = rand() % 5;

	//Set type
	switch (rand() % 3)
	{
	case 0: mTexture = &particleTextures[0]; break;
	case 1: mTexture = &particleTextures[1]; break;
	case 2: mTexture = &particleTextures[2]; break;
	}
}

void Particle::render(SDL_Renderer* gRenderer, LTexture* particleTextures)
{
	//Show image
	mTexture->render(mPosX, mPosY, gRenderer);

	//Show shimmer
	if (mFrame % 2 == 0)
	{
		particleTextures[3].render(mPosX, mPosY, gRenderer);
	}

	//Animate
	mFrame++;
}

bool Particle::isDead()
{
	return mFrame > 10;
}
