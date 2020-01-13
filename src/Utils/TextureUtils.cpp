#include "TextureUtils.h"
#include "../Component/Renderable.h"

void Free(Renderable& renderable)
{
	//Free texture if it exists
	if (renderable.mTexture != NULL)
	{
		SDL_DestroyTexture(renderable.mTexture);
		renderable.mTexture = NULL;
		renderable.mWidth = 0;
		renderable.mHeight = 0;
	}
}

bool LoadFromFile(std::string path, SDL_Renderer* gRenderer, Renderable& renderable)
{
	//Get rid of preexisting texture
	Free(renderable);

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			renderable.mWidth = loadedSurface->w;
			renderable.mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	renderable.mTexture = newTexture;
	return newTexture != NULL;
}