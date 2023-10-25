int pin1= 11 ;
int pin2= 10 ;
int pin3= 9 ;
int ledPin4= 5 ;
int ledPin5= 3 ;

int pulsador1=0;
int pulsador2=0;
int pulsador3=0;

int estado=0;
/*
Estados:
	1- El led está prendido
    2- El led está apagado
    3- Estado sin acción
*/

int auxParaCambiarLeds=0;
int ledVal=0;

void setup(){
 pinMode(pin1, INPUT);
 pinMode(pin2, INPUT);
 pinMode(pin3, INPUT);
 pinMode(ledPin4, OUTPUT);
 pinMode(ledPin5, OUTPUT);
}

void  loop () { 
	pulsador1=digitalRead(pin1);
  	pulsador2=digitalRead(pin2);
  	pulsador3=digitalRead(pin3);
  
  	if(pulsador1==HIGH){
    	estado=1;
      	ledVal=0;
    }else if(pulsador2==HIGH){
     	estado=2; 
      	ledVal=255;
    }else if(pulsador3==HIGH){
     	auxParaCambiarLeds=ledPin4;
      	ledPin4=ledPin5;
      	ledPin5=auxParaCambiarLeds;
    }
      
  if(estado==1){
    if(ledVal<255){
    ledVal++;
    analogWrite(ledPin4,ledVal);
    Serial.println(ledVal);
    delay(5);
    }else{
    estado=3;
    }
  }else if (estado==2){
    if(ledVal>0){
    analogWrite(ledPin4,ledVal);
    Serial.println(ledVal);
    ledVal--;
    delay(5);
    }else{
    estado=3;
    }
  }else {
  	estado=3; //No hay acción alguna que realizar
  }
  
}