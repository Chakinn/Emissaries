#pragma once

#include <SDL.h>

class EventDispatcher {
public:
	virtual void dispatchEvent(const SDL_Event& event)=0;
};

