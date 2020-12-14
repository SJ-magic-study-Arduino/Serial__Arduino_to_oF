/************************************************************
■概要
・	oF -Serial-> Arduino

■参考URL
	■openframeworksとArduinoの連携
		http://interactive0811.hatenablog.jp/entry/2015/11/16/182212
		
	■よく分かる！ シリアル通信基礎講座
		https://emb.macnica.co.jp/articles/8191/
		
	■Arduino シリアル通信の高速処理化
		https://garchiving.com/high-speed-processing-of-serial-communication-in-arduino/
		
	■UART（非同期シリアル通信）の説明
		http://tri-s.world.coocan.jp/SfStS_N64/SfStS_Common/UART/Explain_UART.html
		
	■ArduinoとOpenframeworksのシリアル通信。
		http://ryoizu.com/blog/2016/06/08/arduino%E3%81%A8openframeworks%E3%81%AE%E3%82%B7%E3%83%AA%E3%82%A2%E3%83%AB%E9%80%9A%E4%BF%A1%E3%80%82/
		
	■ArduinoからProcessingへint型のデータを送る
		https://kougaku-navi.hatenablog.com/entry/20141008/p1
		
	■RECEIVE BUFFER 
		https://doc.4d.com/4Dv16/4D/16.6/RECEIVE-BUFFER.301-4446005.ja.html
		
	■オーバーランエラーの原因
		https://ednjapan.com/edn/articles/1507/14/news015.html

■sj´s note
・	ArduinoのSerial Monitorを立ち上げた状態で、oFを立ち上げると、
		[ error ] ofSerial: unable to open /dev/cu.usbmodem1412401
	と言われて、接続できなかった。
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/

class ofApp : public ofBaseApp{
private:
	enum{
		WINDOW_WIDTH	= 300,
		WINDOW_HEIGHT	= 300,
	};
	enum{
		SIZE_DATA_SET = 3,
		RECEIVE_DATA_SIZE_1_TIME = 5,
	};
	
	ofSerial serial;
	unsigned char receiveData[RECEIVE_DATA_SIZE_1_TIME];
	int ReceivedData = 0;
	
	ofTrueTypeFont font;

public:
	ofApp();
	~ofApp();
	
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
