#include <avr/sleep.h>
#include <avr/power.h>
int pinRedSw = 3; //Pin usado para leer el Reed Switch
int pinBoozer = 13; //Pin usado para el sonido de la alarma


void setup() {
  pinMode(pinRedSw, INPUT);
  pinMode(pinBoozer, OUTPUT);
  digitalWrite(pinBoozer, LOW);
}

void loop() {
  digitalWrite(pinBoozer, LOW);// Cambio del boozer a low
  
  attachInterrupt(digitalPinToInterrupt(pinRedSw), despertar,LOW);// Interrupcion para despertar
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();// Activacion del bajo consumo
  sleep_mode();// Modo dormir
  //Aqui se duerme el programa, y al despertar empezara desde la linea de abajo

  //Inicio de la alarma 
  
  while(digitalRead(pinRedSw)==LOW){ //Ciclo para que la alarma no se desactive hasta que el estado no pase a high
    digitalWrite(pinBoozer, HIGH);
  }
  
}

void despertar(void){
  detachInterrupt(digitalPinToInterrupt(pinRedSw)); // Detach de la interrupcion para que no se vuelva a despertar 
  sleep_disable();// Desactivar el modo ahorro de energia
}
