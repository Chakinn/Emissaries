#include "SpriteManager.h"

using namespace game::graphics;

SpriteManager::SpriteManager() {
	
}

SpriteManager::~SpriteManager() {}

std::string game::graphics::SpriteManager::addSprite(const engine::render::Sprite & sprite) {
	std::string id = newId();
	sprites.insert(std::make_pair(id, sprite));
	return id;
}

engine::render::Sprite SpriteManager::getSprite(const std::string& spriteId) {
	return sprites.at(spriteId);
}

std::string game::graphics::SpriteManager::newId() {
	currentSpriteId++;
	return "S:"+std::to_string(currentSpriteId);
}
