#define ldr A2
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_ana = analogRead(ldr);
  Serial.println(ldr_ana);
  if(ldr_ana > 500){
    digitalWrite(led,HIGH);
  }else {
    digitalWrite(led,LOW);
  }
  
  
}
