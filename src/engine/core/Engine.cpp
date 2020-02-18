#include "Engine.h"	

engine::core::Engine::Engine(std::unique_ptr<EventDispatcher> eDispatcher,
	std::unique_ptr<GameStateUpdater> gsUpdater,
	std::unique_ptr<ViewUpdater> vUpdater)
	: eventDispatcher{ std::move(eDispatcher) },
	gameStateUpdater{ std::move(gsUpdater) },
	viewUpdater{ std::move(vUpdater) }{}

engine::core::Engine::~Engine() {}

void engine::core::Engine::gameLoop() {
	bool quit = false;
	SDL_Event currentEvent;
	std::chrono::time_point<std::chrono::steady_clock> prevTime = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::steady_clock> currentTime;
	while (!quit) {
		while (SDL_PollEvent(&currentEvent)) {
			eventDispatcher->dispatchEvent(currentEvent);
		}

		currentTime = std::chrono::high_resolution_clock::now();
		prevTime = currentTime;
		long long dt = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - prevTime).count();
		gameStateUpdater->updateGameState(dt);

		viewUpdater->updateView();
		
	}
}
