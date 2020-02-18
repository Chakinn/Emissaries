#pragma once

#include <chrono>
#include <memory>

#include "EventDispatcher.h"
#include "GameStateUpdater.h"
#include "ViewUpdater.h"


namespace engine {
	namespace core {
		class Engine {
		public:
			Engine(
				std::unique_ptr<EventDispatcher> eventDispatcher,
				std::unique_ptr<GameStateUpdater> gameStateUpdater,
				std::unique_ptr<ViewUpdater> viewUpdater);

			~Engine();

			void gameLoop();

		private:
			std::unique_ptr<EventDispatcher> eventDispatcher;
			std::unique_ptr<GameStateUpdater> gameStateUpdater;
			std::unique_ptr<ViewUpdater> viewUpdater;
		};
	}
}
