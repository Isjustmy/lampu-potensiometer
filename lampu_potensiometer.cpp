/*
    Analog Input Demonstrates analog input by
    reading an analog sensor on analog pin 0 and
    controlling LEDs based on the sensor value.
*/

int sensorValue = 0;
const int greenLedPin = 13;   // Pin untuk LED hijau
const int redLedPin = 12;     // Pin untuk LED merah
const int yellowLedPin = 11;  // Pin untuk LED kuning
const int blueLedPin = 10;    // Pin untuk LED biru
const int whiteLedPin = 9;   // Pin untuk LED putih
const int orangeLedPin = 8;  // Pin untuk LED oranye

void setup()
{
  pinMode(A0, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(whiteLedPin, OUTPUT);
  pinMode(orangeLedPin, OUTPUT);
  
  Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop()
{
  // Baca nilai dari sensor
  sensorValue = analogRead(A0);

  // Cetak nilai ke konsol
  Serial.println("Nilai sensor: " + String(sensorValue));

  // Matikan semua LED terlebih dahulu
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
  digitalWrite(whiteLedPin, LOW);
  digitalWrite(orangeLedPin, LOW);

  // Menghidupkan lampu hijau saat potensiometer berada dalam rentang 0-170
  if (sensorValue >= 0 && sensorValue <= 170) {
    digitalWrite(greenLedPin, HIGH);
  }
  if (sensorValue >= 171 && sensorValue <= 340) {
    digitalWrite(redLedPin, HIGH);
  }
  if (sensorValue >= 341 && sensorValue <= 510) {
    digitalWrite(yellowLedPin, HIGH);
  }
  if (sensorValue >= 511 && sensorValue <= 680) {
    digitalWrite(blueLedPin, HIGH);
  }
  if (sensorValue >= 681 && sensorValue <= 850) {
    digitalWrite(whiteLedPin, HIGH);
  }
  if (sensorValue >= 851 && sensorValue <= 1023) {
    digitalWrite(orangeLedPin, HIGH);
  }

  // Jeda sejenak sebelum membaca nilai lagi
  delay(50); // Jeda 1 detik
}