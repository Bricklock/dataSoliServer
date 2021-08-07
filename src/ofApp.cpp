#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliServer");
	ofSetFrameRate(30);

	
	//Setup Sender Objects
	clientDestination1 = "localhost";
	clientPort1 = 10001;
	clientDestination2 = "123123.12.3123/123.";
	clientPort2 = 10002;
	clientDestination3 = "2341234.12.351/234.1235.";
	clientPort3 = 10003;
	sender.setup(clientDestination1, clientPort1);
	//sender.setup(clientDestination2, clientPort2);
	//sender.setup(clientDestination3, clientPort3);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofxOscMessage m;
	m.setAddress("/testInfo/participantID");
	m.addStringArg(participantID);
	m.addFloatArg(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.f, 1.f, true));
	m.addFloatArg(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.f, 1.f, true));
	sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::draw(){

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
