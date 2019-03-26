#include "SimpleDraw.h"
class BirdBaseClass {

	virtual void draw() = 0;
	virtual	void clear() = 0;
	virtual	void move(int px, int py) = 0;
};