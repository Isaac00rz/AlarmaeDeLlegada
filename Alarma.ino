/*Autor: Isaac Ulises Hernandez Marquez
  Materia: Sistemas programables
  Instituto Tecnologico de Leon
*/

#include <avr/sleep.h>
#include <avr/power.h>

int pinRedSw = 3; //Pin usado para leer el Reed Switch
int pinBuzzer = 13; //Pin usado para el sonido de la alarma


void setup() {
  Serial.begin(9600);
  pinMode(pinRedSw, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, LOW);
}

void loop() {
  digitalWrite(pinBuzzer, LOW);// Cambio del boozer a low
  Serial.println("Voy a dormir...");
  delay(500); // Delay para que cargue el modo sleep power down
  attachInterrupt(digitalPinToInterrupt(pinRedSw), despertar,LOW);// Interrupcion para despertar
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();// Activacion del bajo consumo
  sleep_mode();// Modo dormir
  
  //Aqui se duerme el programa, y al despertar empezara desde la linea de abajo
  //Inicio de la alarma 
  Serial.println("Desperte!!");
  while(digitalRead(pinRedSw)==LOW){ //Ciclo para que la alarma no se desactive hasta que el estado no pase a high
    digitalWrite(pinBuzzer, HIGH);
  }
}

void despertar(void){
  sleep_disable();// Desactivar el modo ahorro de energia
}
