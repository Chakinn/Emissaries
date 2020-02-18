#pragma once

class GameStateUpdater {
public:
	virtual void updateGameState(long dt)=0;
};