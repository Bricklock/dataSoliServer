#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

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

		ofxOscReceiver receiver;
		int receivePort1;

};
