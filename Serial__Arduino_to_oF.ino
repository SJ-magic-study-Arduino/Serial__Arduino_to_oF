/************************************************************
・	ArduinoのSerial Monitorを立ち上げた状態で、oFを立ち上げると、
		[ error ] ofSerial: unable to open /dev/cu.usbmodem1412401
	と言われて、接続できなかった。
************************************************************/

/******************************
******************************/
void setup() {
	Serial.begin(9600);
}

/******************************
******************************/
void loop() {
	// int value = analogRead(0);
	int value = millis() / 1000 + 250/* offset : 6秒後から 2Byte data */; // int : ArduinoUno : 2Byte
	
	byte low  = value & 0x7F; // byte : 8bit unsigned
	byte high = (value >> 7) & 0x7F;
	byte head = ((value >> 14) & 0x7F) + 0x80;
	
	Serial.write(head);
	Serial.write(high);
	Serial.write(low);
	
	delay(33);
	// delay(10);
}


