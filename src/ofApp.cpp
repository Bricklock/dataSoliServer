#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliServer");
	ofSetFrameRate(30);

	
	//Setup Sender Objects
	clientDestination1 = "localhost";
	clientPort1 = 10001;
	clientDestination2 = "localhost";
	clientPort2 = 10002;
	clientDestination3 = "localhost";
	clientPort3 = 10003;
	sender1.setup(clientDestination1, clientPort1);
	sender2.setup(clientDestination2, clientPort2);
	sender3.setup(clientDestination3, clientPort3);
	//Setup Receiver
	receiver.setup(10000);

	//Gui Setup
	gui.setup("Data Collection for multi Soli experiment");
	gui.setSize(ofGetWidth() / 2.5, 10);

	//Participant Id entry
	gui.add(participantIdField.setup("pid", "p_000"));

	//Slider to set number of repetitions for each gesture
	gui.add(repSlider.setup("Repetitions per gesture:", 50, 0, 50));

	//TODO dropdown selection for gesture set, FingerPinch, KnobTwist, Swipes, Large, Resting


	//Start test button
	//This should send the above data to the clients
	gui.add(startButton.setup("Start"));

	//TODO implement pause button for soli
	gui.add(pause.setup("Pause", "Pause"));

	//Connected status
	gui.add(client1.setup("Client1", "Disconnected"));
	gui.add(client2.setup("Client2", "Disconnected"));
	gui.add(client3.setup("Client3", "Disconnected"));
}

//--------------------------------------------------------------
void ofApp::update(){
	if (startButton) {
		ofxOscMessage mRepetitions;
		mRepetitions.setAddress("/testInfo/repetitions");
		mRepetitions.addStringArg(ofToString(repSlider.getParameter()));
		ofxOscMessage mParticipantId;
		mParticipantId.setAddress("/testInfo/participantID");
		mParticipantId.addStringArg(ofToString(participantIdField.getParameter()));

		ofxOscMessage mStart;
		mStart.setAddress("/start");
		mStart.addStringArg("start");

		sender1.sendMessage(mRepetitions);
		sender1.sendMessage(mParticipantId);
		sender1.sendMessage(mStart);
		sender2.sendMessage(mRepetitions);
		sender2.sendMessage(mParticipantId);
		sender2.sendMessage(mStart);
		sender3.sendMessage(mRepetitions);
		sender3.sendMessage(mParticipantId);
		sender3.sendMessage(mStart);
	}

	ofxOscMessage mStatus1;
	mStatus1.setAddress("/status");
	mStatus1.addIntArg(1);
	client1 = "Disconnected";
	sender1.sendMessage(mStatus1);
	ofxOscMessage mStatus2;
	mStatus2.setAddress("/status");
	mStatus2.addIntArg(2);
	client2 = "Disconnected";
	sender2.sendMessage(mStatus2);
	ofxOscMessage mStatus3;
	mStatus3.setAddress("/status");
	mStatus3.addIntArg(3);
	client3 = "Disconnected";
	sender3.sendMessage(mStatus3);

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage msg;
		receiver.getNextMessage(msg);
		if (msg.getAddress() == "/status") {
			if (msg.getArgAsInt(0) == 1) {
				client1 = "Connected";
			}
			else if (msg.getArgAsInt(0) == 2) {
				client2 = "Connected";
			}
			else if (msg.getArgAsInt(0) == 3) {
				client3 = "Connected";
			}
		}
		else {}
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
