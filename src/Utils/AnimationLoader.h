#pragma once

using namespace std;
#include "../Component/Animation.h"
#include <string>

namespace AnimationLoader {
	Animation LoadAnimation(string fileName, SDL_Renderer* gRenderer);
}
