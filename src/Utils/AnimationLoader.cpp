#include "AnimationLoader.h"
#include <nlohmann/json.hpp>
#include "TextureUtils.h"
#include <fstream>
#include <sstream>
#include "../Component/Frame.h"
#include <iostream>

using json = nlohmann::json;
namespace AnimationLoader {
	Animation LoadAnimation(string fileName, SDL_Renderer* gRenderer)
	{
		json ja;

		std::stringstream ssResourceLocation;

		ssResourceLocation << "../resources/" << fileName << ".json";
		std::ifstream iaasda(ssResourceLocation.str());
		json j = json::parse(iaasda);

		std::vector<Frame> frames{};

		for (auto& el : j["frames"].items())
		{
			std::stringstream debugIteratorString;
			debugIteratorString << el.key() << " : " << el.value() << '\n';
			int x = el.value()["frame"]["x"];
			int y = el.value()["frame"]["y"];
			int w = el.value()["frame"]["w"];
			int h = el.value()["frame"]["h"];
			Uint8 duration = el.value()["duration"];
			Frame frame1{ x , y , h , w, duration, 0 };
			frames.push_back(frame1);
			SDL_Log(debugIteratorString.str().c_str());
		}

		std::stringstream ssImageLocation;
		ssImageLocation << "../resources/" << fileName << ".png";

		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile(ssImageLocation.str(), gRenderer, renderable))
			printf("Failed to load dot texture!\n");
		Animation animation{ frames, renderable };
		return animation;
	}
}
