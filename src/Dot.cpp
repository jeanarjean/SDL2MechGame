#include "Dot.h"
#include "Particle.h"

Dot::Dot(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, LTexture* particleTextures, LTexture* gDotTexture)
{
	//Initialize the offsets
	mPosX = 0;
	mPosY = 0;
	Dot::SCREEN_WIDTH = SCREEN_WIDTH;
	Dot::SCREEN_HEIGHT = SCREEN_HEIGHT;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	//Initialize particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		particles[i] = new Particle(mPosX, mPosY, particleTextures);
	}
	Dot::gDotTexture = gDotTexture;
	Dot::particleTextures = particleTextures;
}

Dot::~Dot()
{
	//Delete particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		delete particles[i];
	}
}

void Dot::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Dot::move()
{
	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went too far to the left or right
	if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;
	mPosY += GRAVITY_SPEED;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		//Move back
		mPosY -= mVelY;
		mPosY -= GRAVITY_SPEED;
	}
}

void Dot::render(SDL_Renderer* gRenderer)
{
	//Show the dot
	gDotTexture->render(mPosX, mPosY, gRenderer);

	//Show particles on top of dot
	renderParticles(gRenderer);
}

void Dot::renderParticles(SDL_Renderer* gRenderer)
{
	//Go through particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		//Delete and replace dead particles
		if (particles[i]->isDead())
		{
			delete particles[i];
			particles[i] = new Particle(mPosX, mPosY, particleTextures);
		}
	}

	//Show particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		particles[i]->render(gRenderer, particleTextures);
	}
}
