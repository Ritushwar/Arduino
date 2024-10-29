#define dirPin 2
#define stepPin 3
#define pot_1 A0
int pos_1a = 0;
int pos_1b = 0;
int deg_1 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(pot_1, INPUT);
}

void loop() {
  pos_1a = analogRead(pot_1);
  pos_1a = map(pos_1a,0,1023,0,200);
  if(pos_1a > pos_1b){
    digitalWrite(dirPin, LOW);  // For Clockwise
    deg_1 = pos_1a - pos_1b;
    for (int x = 0; x < deg_1; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(600);
    }
    pos_1b = pos_1a;
    Serial.println("Clock Wise");
  }
  if(pos_1b > pos_1a){
    digitalWrite(dirPin, HIGH);
    deg_1 = pos_1b - pos_1a;
    for (int x = 0; x < deg_1; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(600);
    }
    pos_1b = pos_1a;
    Serial.println("Anti ClockWise");
  }
  // put your main code here, to run repeatedly:
}

