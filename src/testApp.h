#pragma once

#include "ofMain.h"
#include "korg.h"

class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();

	Korg korg;
};
