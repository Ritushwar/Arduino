int triggerPin = 2;
int echoPin = 3;
long duration;
long distance;
void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = duration*(0.034/2);
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.print("\n");
  delay(10);
  // put your main code here, to run repeatedly:

}
