/*
 Name:		Sketch9.ino
 Created:	7/28/2020 12:33:41 PM
 Author:	Janie
*/
#pragma region Variables
int sensorValue, sensorLOW = 1023, sensorHIGH = 0;
const int ledPin = 13;
#pragma endregion

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, HIGH);

	while (millis() < 5000)
	{
		sensorValue = analogRead(A0);
		if (sensorValue > sensorHIGH)
		{
			sensorHIGH = sensorValue;
		}
		if (sensorValue<sensorLOW)
		{
			sensorLOW = sensorValue;
		}
	}
	digitalWrite(ledPin, LOW);
}

// the loop function runs over and over again until power down or reset
void loop() {
	sensorValue = analogRead(A0);
	int pitch = map(sensorValue, sensorLOW, sensorHIGH, 50, 4000);

	tone(8, pitch, 20);
	delay(10);
}
