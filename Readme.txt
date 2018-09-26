Sistema de alarma de llegada de individuos.
Programado en arduino para la clase de Sistemas Programables
Autor: Hernandez Marquez Isaac Ulises

Materiales:
    Arduno uno
    Buzzer
    ReedSwitch
    Iman
    Resistencia 320
    ProtoBoard

Funcionamiento:
    Arduino estara en modo de bajo consumo electrico mientras la alarma no ese activada, para ello se utilizan las 
    bibliotecas sleep.h y power.h

    Para mandar la interrupcion que activara la alarma se utilizara el ReedSwitch
    conectado a un pin de interrupcion(en el caso de arduino uno son el 2 y 3).

    Una vez activada la interrupcion(que la puerta se abra) con el iman, la alarma no dejara
    de sonar hasta que el iman sea retirado, es decir, la puerta se cierre.
    
    Una vez el iman sea retirado el arduino volvera a modo de bajo consumo energetico.
    