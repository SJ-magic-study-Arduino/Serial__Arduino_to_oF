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
	if(RECEIVE_DATA_SIZE_1_TIME <= serial.available()){
		/********************
		********************/
		while(RECEIVE_DATA_SIZE_1_TIME < serial.available()){
			serial.readByte(); // 読み捨て
		}
		
		/********************
		********************/
		serial.readBytes(receiveData, RECEIVE_DATA_SIZE_1_TIME);
		int id = 0;
		
		while(id < RECEIVE_DATA_SIZE_1_TIME){
			if(128 <= receiveData[id]) break;
			id++;
		}
		
		if(id < RECEIVE_DATA_SIZE_1_TIME - 2){
			int Head = (int)receiveData[id];
			int High = (int)receiveData[id + 1];
			int Low  = (int)receiveData[id + 2];
			
			ReceivedData = ((Head - 128) << 14) + (High << 7) + (Low);
		}
	}
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
