int in = 1;
int s1 = 2;
int s2 = 3;
int s3 = 4;
int s4 = 5;
int a = 6;
int b = 7;
int c = 8;
int d = 9;
int e = 10;
int f = 11;
int g = 12;
int dot = 13;
int hrs=0;
int mi=0;
int sec = 0;
void setup() {
  Serial.begin(9600);
   pinMode(in, INPUT);
   pinMode(s1, OUTPUT);
   pinMode(s2, OUTPUT);
   pinMode(s3, OUTPUT);
   pinMode(s4, OUTPUT);
   pinMode(a, OUTPUT);
   pinMode(b, OUTPUT);
   pinMode(c, OUTPUT);
   pinMode(d, OUTPUT);
   pinMode(e, OUTPUT);
   pinMode(f, OUTPUT);
   pinMode(g, OUTPUT);
   pinMode(dot, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sec = sec + 1;
  digitalWrite(dot,HIGH);
  if(sec>60){
    mi = mi +1;
    sec =0;
  }
  if(mi>60){
    hrs = hrs +1;
    hrs =0;
  }
  if(hrs>24){
    hrs =0;
  }
  if(in==HIGH){
    Serial.println("switch was pushed");
  show(hrs,mi);
  delay(300);
  digitalWrite(dot,LOW);
  delay(300);
  }
  else if(in==0){
    Serial.println("switch was not pushed");
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
   delay(500);
  digitalWrite(dot,LOW);
  delay(500);
  }
}
void show(int h, int m){
  int digit1 =0;
  int digit2 =0;
  int digit3 =0;
  int digit4 =0;
  digit1 = m%10;
  digit2 = m/10;
  digit3 = h%10;
  digit4 = h/10;
  Decode(digit4, digit3, digit2, digit1);
}
void Decode(int d4, int d3, int d2, int d1){
  Display(d4,4);
  delay(100);
  Display(d3,3);
  delay(100);
  Display(d2,2);
  delay(100);
  Display(d1,1);
  delay(100);
}
void Display(int num, int seg ){
  switch(num){
  case 0:
  zero();
  digitalWrite(seg,LOW);
  break;
  case 1:
  one();
  digitalWrite(seg,LOW);
  break;
  case 2:
  two();
  digitalWrite(seg,LOW);
  break;
  case 3:
  three();
  digitalWrite(seg,LOW);
  break;
  case 4:
  four();
  digitalWrite(seg,LOW);
  break;
  case 5:
  five();
  digitalWrite(seg,LOW);
  break;
  case 6:
  six();
  digitalWrite(seg,LOW);
  delay(100);
  break;
  case 7:
  seven();
  digitalWrite(seg,LOW);
  break;
  case 8:
  eight();
  digitalWrite(seg,LOW);
  break;
  case 9:
  nine();
  digitalWrite(seg,LOW);
  break;
  }
}
void zero(void){
  Serial.println("zero");
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}
void one(void){
  Serial.println("one");
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}
void two(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}
void three(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(g, HIGH);
}
void four(void){
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
}
void five(void){
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}
void six(void){
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void seven(void){
  digitalWrite(a, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(a, HIGH);
}
void eight(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void nine(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
