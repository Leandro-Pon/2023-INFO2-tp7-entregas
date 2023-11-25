import processing.serial.*;

Serial miPuerto;

int ancho=170;
int alto=75;

int anch = 75;
int alt = 75;

int alturaText=40;
int sw = 5; //grosor de las líneas (sw==StrokeWeight)
boolean E1, E2, S1, S2;

void setup(){
  size(700,400);
  background(100);
  strokeWeight(sw);
  
  miPuerto=new Serial(this, "COM6", 9600);
  
  E1=false;
  E2=false;
  S1=false;
  S2=false;
  
  //entrada
  fill(0, 230, 70);
  rect(width/8, height/6, ancho,alto);
  fill(0);
  textSize(alturaText);
  text("Entradas", width/8+10, height/6+50);
 
  //Entrada 1 y 2:
  fill(200,0,10);
  
  square(width/2, height/6, alto);
  square(width/1.4, height/6, alto);
  fill(0);
  textSize(alturaText);
  text("E1", width/2+15, height/6+50);
  text("E2", width/1.4+15, height/6+50);
  
  
  //salida
  fill(250, 10, 50);
  rect(width/8, height/1.5, ancho,alto);
  fill(0);
  textSize(alturaText);
  text("Salidas", width/8+25, height/1.5+50);
  
}

void draw(){
  //Entrada 1
 if(mousePressed && mouseX<(width/2+alto) && mouseX>width/2 && mouseY<(height/6+alto) && mouseY>height/6){
   E1=!E1;
   S1=!S1;
   miPuerto.write('1');
   if(E1==false){
     fill(200,0,10);
     square(width/2, height/6, alto);
   }else{
     fill(0,200,10);
     square(width/2, height/6, alto);
   }
   
 }
 //Entrada 2
 if(mousePressed && mouseX<(width/1.4+alto) && mouseX>width/1.4 && mouseY<(height/6+alto) && mouseY>height/6){
   E2=!E2;
   S2=!S2;
   miPuerto.write('2');
   if(E2==false){
     fill(200,0,10);
     square(width/1.4, height/6, alto);
   }else{
     fill(0,200,10);
     square(width/1.4, height/6, alto);
   }
   
 }
 
 if(S1==true){
  fill(255,255,0);
 }else{
  fill(100);
 }
   strokeWeight(sw);
  circle(width/2+anch/2, height/1.5+anch/2, anch);
  fill(0);
  textSize(alturaText);
  text("S1", width/2+15, height/1.5+50);
 
 if(S2==true){
  fill(255,255,0);
 }else{
  fill(100);
 }
   strokeWeight(sw);
  circle(width/1.4+anch/2, height/1.5+anch/2, anch);
  fill(0);
  textSize(alturaText);
  text("S2", width/1.4+15, height/1.5+50);
 
   fill(0);
   textSize(alturaText);
   text("E1", width/2+15, height/6+50);
   text("E2", width/1.4+15, height/6+50);
 
}
