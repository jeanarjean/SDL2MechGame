/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
// TODO fix this
#include <SDL.h>
#include <SDL_image.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <string>
#include "src/Particle.h"
#include "src/LTexture.h"
#include "src/System/RenderSystem.h"
#include "src/System/MovementSystem.h"
#include "src/EventHandler/InputHandler.h"
#include <entt/entt.hpp>
#include "src/Utils/TextureUtils.h"
#include "src/Component/Background.h"
#include "src/Utils/CoordTranslator.h"
#include "src/Utils/GameWorldInitiator.h"
#include "src/Utils/BackgroundLoader.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//Particle count
const int TOTAL_PARTICLES = 20;

// Phyiscs numbers
const int GRAVITY_SPEED = 2;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gDotTexture;
LTexture particleTextures[4];

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDLSDL_Renderer* gRenderer
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if (!gDotTexture.loadFromFile("../resources/doommarine.jpg", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	//Load red texture
	if (!particleTextures[0].loadFromFile("../resources/red.bmp", gRenderer))
	{
		printf("Failed to load red texture!\n");
		success = false;
	}

	//Load green texture
	if (!particleTextures[1].loadFromFile("../resources/green.bmp", gRenderer))
	{
		printf("Failed to load green texture!\n");
		success = false;
	}

	//Load blue texture
	if (!particleTextures[2].loadFromFile("../resources/blue.bmp", gRenderer))
	{
		printf("Failed to load blue texture!\n");
		success = false;
	}

	//Load shimmer texture
	if (!particleTextures[3].loadFromFile("../resources/shimmer.bmp", gRenderer))
	{
		printf("Failed to load shimmer texture!\n");
		success = false;
	}

	//Set texture transparency
	particleTextures[0].setAlpha(192);
	particleTextures[1].setAlpha(192);
	particleTextures[2].setAlpha(192);
	particleTextures[3].setAlpha(192);

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	particleTextures[0].free();
	particleTextures[1].free();
	particleTextures[2].free();
	particleTextures[3].free();
	particleTextures->free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			CoordTranslator* translator = CoordTranslator::instance();
			translator->setResolution(b2Vec2(SCREEN_WIDTH, SCREEN_HEIGHT));
			//The dot that will be moving around on the screen
			entt::registry registry;

			B2_NOT_USED(argc);
			B2_NOT_USED(args);

			Uint64 t = 0;
			Uint64 dt = 16;
			Uint64 currentTime = SDL_GetPerformanceCounter();
			Uint64 accumulator = 0;

			// Define the gravity vector.
			b2Vec2 gravity(0.0f, -10.0f);
			// Construct a world object, which will hold and simulate the rigid bodies.
			b2World world(gravity);

			// Prepare for simulation. Typically we use a time step of 1/60 of a
			// second (60Hz) and 10 iterations. This provides a high quality simulation
			// in most game scenarios.
			float32 timeStep = 1.0f / 60.0f;
			int32 velocityIterations = 6;
			int32 positionIterations = 2;


			InitiateGameWorld(registry, world, gRenderer, b2Vec2{ 1600, 900 });
			BackgroundLoader::LoadBackground(registry, gRenderer);

			//While application is running
			while (!quit)
			{
				Uint64 newTime = SDL_GetPerformanceCounter();
				Uint64 frameTime = newTime - currentTime;
				if (frameTime > 25)
					frameTime = 25;
				currentTime = newTime;


				bool keysHandled = true;
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle input for the dot
					HandleInputs(registry, e);
				}
				MovePlayer(registry);

				accumulator += frameTime;
				while (accumulator >= dt)
				{

					//simulate physics
					world.Step(timeStep, velocityIterations, positionIterations);
					t += dt;
					accumulator -= dt;
				}


				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				Renderer::Render(registry, gRenderer);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}