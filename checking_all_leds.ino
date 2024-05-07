//checking all the led of display
int data_a=2;
int data_b=3;
int clock_a=4;
int clock_b=5;
int latch=6;
int p_value=0x00;
int n_value=0xFF;
void setup() {
  pinMode(data_a,OUTPUT);
  pinMode(data_b,OUTPUT);
  pinMode(clock_a,OUTPUT);
  pinMode(clock_b,OUTPUT);
  pinMode(latch,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  for(int i=7;i>=0;i--){
    bitSet(p_value,i);
    for(int j=7;j>=0;j--){
      bitClear(n_value,j);
      update_shift(p_value,n_value);
      bitSet(n_value,j);
    }
    bitClear(p_value,i);
  }
  
  
  // put your main code here, to run repeatedly:
}
void update_shift(int p_value,int n_value){
  digitalWrite(latch,LOW);
  shiftOut(data_a,clock_a,LSBFIRST,p_value);
  shiftOut(data_b,clock_b,LSBFIRST,n_value);
  digitalWrite(latch,HIGH);
  delay(1000);
  }