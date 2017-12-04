#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetColor(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int rotate_deg = 0;
	if (ofGetFrameNum() % 720 < 360) {
		rotate_deg = ofGetFrameNum();
	}

	float size = 15;
	ofColor color;
	this->cam.begin();

	for (float radius = 0; radius < 200; radius += 15) {
		ofRotateY(rotate_deg);
		ofRotateX(rotate_deg * 2);

		ofBeginShape();
		for (float deg = 0; deg <= 360; deg += 1) {
			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		}

		for (float deg = 360; deg >= 0; deg -= 1) {
			ofVertex((radius + size) * cos(deg * DEG_TO_RAD), (radius + size) * sin(deg * DEG_TO_RAD));
		}
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}