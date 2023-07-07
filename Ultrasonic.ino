#define pingPin 13
#define inPin 12


void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop(){
  float duration, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(inPin, HIGH);
  cm = (duration/ 1000000)*173 *100;

  Serial.println(cm);
  Serial.print("cm");
  Serial.println();

  delay(500);
}

//40 hz ulatrasonic

