#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliServer");
	ofSetFrameRate(30);

	
	//Setup Sender Objects
	clientDestination1 = "localhost";
	clientPort1 = 10001;
	clientDestination2 = "1p2";
	clientPort2 = 10002;
	clientDestination3 = "ip1";
	clientPort3 = 10003;
	sender.setup(clientDestination1, clientPort1);
	//sender.setup(clientDestination2, clientPort2);
	//sender.setup(clientDestination3, clientPort3);

	//Setup Receiver
	receiver.setup(10000);

	//Gui Setup
	gui.setup("Data Collection for multi Soli experiment");
	gui.setSize(ofGetWidth() / 2.5, 10);

	//Participant Id entry
	gui.add(participantIdField.setup("pid", "p_000"));
	//Slider to set number of repetitions for each gesture
	gui.add(repSlider.setup("Repetitions per gesture", 50, 0, 50));
	//TODO dropdown selection for gesture set, FingerPinch, KnobTwist, Swipes, Large, Resting

	//Start test button
	//This should send the above data to the clients
	gui.add(startButton.setup("Start"));

}

//--------------------------------------------------------------
void ofApp::update(){
	if (startButton) {
		ofxOscBundle bundle;
		
		ofxOscMessage mRepetitions;
		mRepetitions.setAddress("/testInfo/repetitions");
		mRepetitions.addStringArg(ofToString(repSlider.getParameter()));
		ofxOscMessage mParticipantId;
		mParticipantId.setAddress("/testInfo/participantID");
		mParticipantId.addStringArg(ofToString(participantIdField.getParameter()));

		ofxOscMessage mStart;
		mStart.setAddress("/start");
		mParticipantId.addStringArg("start");

		bundle.addMessage(mRepetitions);
		bundle.addMessage(mParticipantId);
		bundle.addMessage(mStart);
		sender.sendBundle(bundle);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

void clickStart() {

}
