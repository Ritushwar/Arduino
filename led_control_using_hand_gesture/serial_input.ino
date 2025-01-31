int bulb = 3;
int x;
int i = 0;
void setup(){
  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(bulb,OUTPUT);
}
void loop(){
  while(!Serial.available());
  x = Serial.readString().toInt();
  if(x==1){
    digitalWrite(bulb,HIGH);
  }
  else if(x==0){
    digitalWrite(bulb, LOW);
    }
  Serial.print(x);
}
