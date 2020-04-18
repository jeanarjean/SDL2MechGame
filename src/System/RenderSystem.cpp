#include "RenderSystem.h"
#include "../Component/BoundingBox.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Platform.h"
#include "../Component/Dynamic.h"
#include "../Component/Background.h"
#include "../Component/Frame.h"
#include "../Component/Animation.h"
#include "../Component/TileComponent.h"
#include "../Utils/TextureUtils.h"
#include "../Utils/CoordTranslator.h"
#include "../Render/RenderLayer.h"
#include <Box2D/Box2D.h>

namespace Renderer
{
	void Render(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		RenderBackground(registry, gRenderer);
		RenderBoundingBox(registry, gRenderer);
		RenderPlatforms(registry, gRenderer);
		RenderPlayer(registry, gRenderer);
		RenderTiles(registry, gRenderer);
#ifdef COLLISION_DEBUG 
		DebugRender(registry, gRenderer);
#endif
	}

	void RenderPlayer(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Animation, Renderable, b2Body*>().each([gRenderer](auto& animation, auto& renderable, auto* body) {
			const SDL_Rect dest = RenderLayer::AdvanceFrame(animation);

			RenderLayer::RenderGameObject(gRenderer, renderable, body->GetPosition(), dest);
			});
	}

	void RenderPlatforms(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, b2Body*, Platform>().each([gRenderer](auto& renderable, auto* body, auto& platform) {
			RenderLayer::RenderGameObject(gRenderer, renderable, body->GetPosition(), NULL);
			});
		registry.view<Renderable, b2Body*, DynamicBody>().each([gRenderer](auto& renderable, auto* body, auto& dynamicBody) {
			RenderLayer::RenderGameObject(gRenderer, renderable, body->GetPosition(), NULL);
			});
	}

	void RenderBackground(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, Background>().each([gRenderer](auto& renderable, auto Background) {
			RenderLayer::RenderBackground(gRenderer, renderable);
			});
	}

	void RenderBoundingBox(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, BoundingBox, b2Body*>().each([gRenderer](auto& renderable, auto& boundingBox, auto* body) {
			RenderLayer::RenderGameObject(gRenderer, renderable, body->GetPosition(), NULL);
			});
	}

	void RenderTiles(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, TileComponent, b2Body*>().each([gRenderer](auto& renderable, auto& boundingBox, auto* body) {
			RenderLayer::RenderGameObject(gRenderer, renderable, body->GetPosition(), boundingBox.tileZone);
			});
	}

	void DebugRender(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, b2Body*>().each([gRenderer](auto& animation, auto& renderable, auto* body) {
			RenderLayer::DebugRenderCollisionObject(gRenderer, body->GetFixtureList()[0].GetAABB(0).upperBound , body->GetFixtureList()[0].GetAABB(0).lowerBound);
			});
	}
}
