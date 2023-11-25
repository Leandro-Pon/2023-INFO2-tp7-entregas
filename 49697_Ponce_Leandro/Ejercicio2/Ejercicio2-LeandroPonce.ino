int pin1=10;
int pin2=11;
int ledPin1=5;
int ledPin2=6;

int pulsador1=0;
int pulsador2=0;

boolean estado1=false;
boolean estado2=false;
/*
Estados:
	1- El led está prendido
    2- El led está apagado
    3- Estado sin acción
*/
char num;
void setup()
{
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{
  if(Serial.available()){
    num = Serial.read();
  }
  pulsador1=digitalRead(pin1);
  pulsador2=digitalRead(pin2);
 	
  if(pulsador1>0 || num=='1'){
     estado1 = !estado1;
  	 }
  if(pulsador2>0 || num=='2'){
     estado2 = !estado2;
     }
  
  if(estado1==true){
  analogWrite(ledPin1, 255);
  }
  else{
  analogWrite(ledPin1, 0);
  }
  
  if(estado2==1){
  analogWrite(ledPin2, 255);
  }
  else{
  analogWrite(ledPin2, 0);
  }
  
  delay(100);
}