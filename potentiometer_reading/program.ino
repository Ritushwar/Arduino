// C++ code
//
int sensor_value = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
}

void loop()
{
  sensor_value = analogRead(A0);
  sensor_value = map(sensor_value,0,1023,0,255);
  Serial.println(sensor_value);
  analogWrite(A1,sensor_value);
}
