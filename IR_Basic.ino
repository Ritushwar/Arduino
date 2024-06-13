//Basic Setup for IR Sensor
int readingPin = 2;
int led = 4;
void setup() {
  pinMode(readingPin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(readingPin)==LOW){  //if IR detects the object it will send low 
    Serial.print("Reading:");
    Serial.print(digitalRead(readingPin));
    Serial.print("\n");
    digitalWrite(led,HIGH);
    }
   else{
    digitalWrite(led,LOW);
    }
  // put your main code here, to run repeatedly:
}
