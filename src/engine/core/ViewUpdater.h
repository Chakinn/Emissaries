#pragma once

/**
	Interface for engine interacion.
	Class implementing this is responsible for managing all the render calls each frame.
*/
class ViewUpdater {
public:
	/**
		This method is called once per frame in main game loop.
		Implement it so it make all the neccessary render calls (including clear and renderPresent)
	*/
	virtual void updateView() = 0;;
};
