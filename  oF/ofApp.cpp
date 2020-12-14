/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(){
}

/******************************
******************************/
ofApp::~ofApp(){
	serial.close();
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("Serial");
	
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
	/*
	ofSetVerticalSync(false);
	ofSetFrameRate(0);
	/*/
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
    //*/
	
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	font.load("font/RictyDiminished-Regular.ttf", 36, true, true, false, 0.3f, 72);
	
	serial.setup("/dev/cu.usbmodem1412401", 9600); // "/dev/cu.usbmodem1412401"の部分は、Arduino IDEのツール/シリアルポート から持ってくる : (Arduino Uno)部分は不要
}

/******************************
******************************/
void ofApp::update(){
	// int Loops = 0;
	
	while(SIZE_DATA_SET <= serial.available()){
		int temp = serial.readByte();
		if(128 <= temp){ // is Header?
			// Loops++;
			
			int Head = temp;
			int High = serial.readByte();
			int Low  = serial.readByte();
			
			ReceivedData = ((Head - 128) << 14) + (High << 7) + (Low);
		}
	}
	/*
	printf("Loops : %d\n", Loops);
	fflush(stdout);
	*/
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
	
	char buf[512];
	sprintf(buf, "%d", ReceivedData);
	font.drawString(buf, 124, 160);
}

/******************************
******************************/
void ofApp::keyPressed(int key){
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
