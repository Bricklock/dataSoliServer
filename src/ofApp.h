#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);
		
		//Sender
		ofxOscSender sender;
		string clientDestination1;
		string clientDestination2;
		string clientDestination3;
		int clientPort1;
		int clientPort2;
		int clientPort3;
		//message args
		string participantID;
		int repetitions;
		
		ofxOscReceiver receiver;
		int receivePort1;

		//GUI
		ofxPanel gui;

		ofxIntSlider repSlider;
		ofxButton startButton;
		ofxTextField participantIdField;
};

void clickStart();