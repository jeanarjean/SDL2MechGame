/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
// TODO fix this
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <string>
#include "src/System/RenderSystem.h"
#include "src/System/MovementSystem.h"
#include "src/System/AttackSystem.h"
#include "src/System/EnemyMovementSystem.h"
#include "src/System/BulletDestroyerSystem.h"
#include "src/System/GameProgressSystem.h"
#include "src/Render/RenderLayer.h"
#include "src/EventHandler/InputHandler.h"
#include <entt/entt.hpp>
#include "src/Utils/TextureUtils.h"
#include "src/Component/Background.h"
#include "src/Component/Player.h"
#include "src/Utils/CoordTranslator.h"
#include "src/Utils/GameWorldInitiator.h"
#include "src/System/HealthSystem.h"
#include "src/Utils/Factories/PrefabsFactory.h"
#include "cassert"
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "src/Utils/Factories/BodiesFactory.h"
#include "src/Component/TileComponent.h"


#define main    SDL_main
#undef main



//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//Particle count
const int TOTAL_PARTICLES = 20;

// Phyiscs numbers
const int GRAVITY_SPEED = 2;

//Starts up SDL and creates window
bool initSDL();

//Frees media and shuts down SDL
void closeSDL();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

entt::registry registry;

TTF_Font* font;

//Main loop flag
bool quit = false;

// Define the gravity vector.
b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);
PrefabsFactory::PrefabsFactory* prefabsFactory;
MovementSystem::MovementSystem* movementSystem;
EnemyMovementSystem::EnemyMovementSystem enemyMovementSystem;
AttackSystem::AttackSystem* attackSystem;
GameWorldInitiator::GameWorldInitiator* gameWorldInitiator;
Renderable* tex;

// Prepare for simulation. Typically we use a time step of 1/60 of a
// second (60Hz) and 10 iterations. This provides a high quality simulation
// in most game scenarios.
float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 2;
int32 positionIterations = 6;
Uint64 t = 0;
Uint64 dt = 16;
Uint64 currentTime = SDL_GetPerformanceCounter();
Uint64 accumulator = 0;

bool initSDL()
{
	//Initialization flag
	bool success = true;

	//Initialize SDLSDL_Renderer* gRenderer
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		assert(false);
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
		gWindow = SDL_CreateWindow("SDL2MECHGAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			assert(false);
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				assert(false);
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
					assert(false);
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_Mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					assert(false);
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}

				if (TTF_Init() < 0) {
					assert(false);
					SDL_LogCritical(1, "Error initializing SDL_ttf: %s", TTF_GetError());
					success = false;
				}


				font = TTF_OpenFont("../resources/ariblk.ttf", 24);
				if (!font) {
					assert(false);
					SDL_LogCritical(1, "Error loading font: %s", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}
void InitOtherObjects()
{
	movementSystem = new MovementSystem::MovementSystem();
	prefabsFactory = new PrefabsFactory::PrefabsFactory(gRenderer);
	attackSystem = new AttackSystem::AttackSystem(prefabsFactory);
	gameWorldInitiator = new GameWorldInitiator::GameWorldInitiator(prefabsFactory);
}

void InitMap()
{
	tmx::Map map;
	if (map.load("../maps/level1.tmx"))
	{
		const auto& layers = map.getLayers();
		auto map_dimensions = map.getTileCount();
		unsigned rows = map_dimensions.y;
		unsigned cols = map_dimensions.x;
		auto tilesize = map.getTileSize();
		unsigned tile_width = tilesize.x;
		unsigned tile_height = tilesize.y;
		int tileSizeMultiplicator = 1;

		std::map<unsigned, b2Vec2> tilesets;

		auto& map_tilesets = map.getTilesets();
		for (auto& tset : map_tilesets) {
			auto imagePath = tset.getImagePath();
			tex = new Renderable{ NULL, 0, 0 };
			assert(LoadFromFile(imagePath, gRenderer, *tex));
			prefabsFactory->_tileSet = tex;
		}

		for (const auto& layer : layers)
		{
			auto layerqwe = layer->getType();
			if (layer->getType() == tmx::Layer::Type::Object)
			{
				const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
				const auto& objects = objectLayer.getObjects();
				for (const auto& object : objects)
				{
					float left = object.getAABB().left / tilesize.x;
					float top = rows - object.getAABB().top / tilesize.y;
					prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(left, 73), b2Vec2(0.9f, 0.9f));
					//do stuff with object properties
				}
			}
			else if (layer->getType() == tmx::Layer::Type::Tile)
			{
				const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
				auto layerTiles = tileLayer.getTiles();
				for (auto y = 0; y < rows; ++y) {
					for (auto x = 0; x < cols; ++x) {
						auto tile_index = x + (y * cols);
						auto cur_gid = layerTiles[tile_index].ID;
						b2Vec2 position(x * tileSizeMultiplicator, cols * tileSizeMultiplicator - y * tileSizeMultiplicator);
						b2Vec2 size(1.f, 1.f);

						if (x == 5 && y - 5 == tile_width)
						{
							prefabsFactory->CreatePlayerPrefab(registry, world, gRenderer, position, b2Vec2(0.9f, 0.9f));
						}
						if (cur_gid != 0)
						{
							auto entity = registry.create();
							auto ts_width = 0;
							auto ts_height = 0;

							cur_gid = cur_gid - 1;


							SDL_QueryTexture(tex->mTexture,
								NULL, NULL, &ts_width, &ts_height);
							auto region_x = (cur_gid % (ts_width / tile_width)) * tile_width;
							auto region_y = (cur_gid / (ts_width / tile_height)) * tile_height;

							const SDL_Rect tileZone{ region_x , region_y , tile_width, tile_height };
							registry.assign<Renderable>(entity, Renderable{ tex->mTexture, (float)tileSizeMultiplicator, (float)tileSizeMultiplicator });
							registry.assign<TileComponent>(entity, TileComponent{ tileZone });
							b2Body* body = BodiesFactory::CreateStaticBody(world, entity, position, b2Vec2(tileSizeMultiplicator, tileSizeMultiplicator));
							registry.assign<b2Body*>(entity, body);
						}
					}
				}
				//read out tile layer properties etc...
			}
		}

	}
}

void DestoryOtherObjects()
{
	free(movementSystem);
	movementSystem = nullptr;

	free(prefabsFactory);
	prefabsFactory = nullptr;

	free(attackSystem);
	attackSystem = nullptr;

	free(gameWorldInitiator);
	gameWorldInitiator = nullptr;
}

void closeSDL()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	TTF_CloseFont(font);

	gWindow = nullptr;
	gRenderer = nullptr;
	font = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!initSDL())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		InitOtherObjects();

		//Event handler
		SDL_Event e;

		CoordTranslator* translator = CoordTranslator::instance();
		translator->setResolution(b2Vec2(SCREEN_WIDTH, SCREEN_HEIGHT));
		//The dot that will be moving around on the screen

		B2_NOT_USED(argc);
		B2_NOT_USED(args);


		// Potential Problem if integer overflows./
		int currentTick = 0;


		gameWorldInitiator->InitiateGameWorld(registry, world, gRenderer, b2Vec2{ 1600, 900 });
		InitMap();
		//While application is running
		while (!quit)
		{
			Uint64 newTime = SDL_GetPerformanceCounter();
			Uint64 frameTime = ((newTime - currentTime) * 1000) / SDL_GetPerformanceFrequency();
			//SDL_Log("%d ms frame time", frameTime);
			if (frameTime > 16)
				frameTime = 16;
			currentTime = newTime;

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				//Handle input for the dot
				InputHandler::HandleInputs(registry, e);
			}

			accumulator += frameTime;
			while (accumulator >= dt)
			{
				//simulate physics
				world.Step(timeStep, velocityIterations, positionIterations);
				t += dt;
				accumulator -= dt;
				currentTick++;

				movementSystem->MovePlayer(currentTick, registry);
				attackSystem->PlayerAttack(currentTick, registry, world, gRenderer);
				enemyMovementSystem.MoveEnemies(currentTick, registry, world, gRenderer);

			}

			BulletDestroyerSystem::ProcessBullets(registry, world, gRenderer);
			HealthSystem::ProcessHealth(registry, world, gRenderer);
			GameProgressSystem::ProcessGameState(registry, world, gRenderer, font);

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);
			Renderer::Render(registry, gRenderer);

			// Strings to display
			string fps = "Current FPS: " + to_string(1000.0f / frameTime);
			SDL_Rect dest = { 10, 10, 0, 0 };


			RenderLayer::RenderText(gRenderer, dest, font, fps);

			auto view = registry.view<Enemy>();
			if (view.size() < 1)
			{
				string youWinText = "YOU WIN";
				SDL_Rect dest = { 50, 50, 0, 0 };

				RenderLayer::RenderText(gRenderer, dest, font, youWinText);
			}
			auto view2 = registry.view<Player>();
			if (view2.size() < 1)
			{
				string youWinText = "YOU LOST";
				SDL_Rect dest = { 50, 50, 0, 0 };

				RenderLayer::RenderText(gRenderer, dest, font, youWinText);
			}

			//Update screen
			SDL_RenderPresent(gRenderer);
		}
	}

	//Free resources and close SDL
	closeSDL();

	return 0;
}

