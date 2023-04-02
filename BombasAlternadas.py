# programa de bombas de agua para raspberry pi Pico
from machine import Pin
from machine import PWM
import time

# configuracion de pines de entrada y salida
# definicion de salidas
BombaPrincipal = Pin(27,Pin.OUT)
BombaAuxiliar = Pin(26,Pin.OUT)

# definicion de entradas
BajoBajo = Pin(2, Pin.IN)
Bajo = Pin(3, Pin.IN)
Alto = Pin(4, Pin.IN)
AltoAlto = Pin(5, Pin.IN)
BotonInicio = Pin(0, Pin.IN)
BotonParo = Pin(1, Pin.IN)

# configuracion de estados
EstadoBomba1 = 0
EstadoBomba2 = 0
EstadoBotonInicio = 0
EstadoBotonParo = 0
EstadoBajoBajo = 0
EstadoBajo = 0
EstadoAlto = 0
EstadoAltoAlto = 0
Encendido = 1
Apagado = 0
espera = 0.1
EstadoBomba1 = BombaPrincipal
EstadoBomba2 = BombaAuxiliar

# leer estados de las entradas
def LeerEstado():
    global EstadoBajoBajo, EstadoBajo, EstadoAlto, EstadoAltoAlto, EstadoBotonParo
    EstadoBajoBajo = digitalRead(BajoBajo)
    EstadoBajo = digitalRead(Bajo)
    EstadoAlto = digitalRead(Alto)
    EstadoAltoAlto = digitalRead(AltoAlto)
    EstadoBotonParo = digitalRead(BotonParo)

# activar bombas
def ActivarBombas(bomba1, bomba2):
    global EstadoBomba1, EstadoBomba2
    digitalWrite(EstadoBomba1, bomba1)
    time.sleep(espera)
    digitalWrite(EstadoBomba2, bomba2)
    time.sleep(espera)

# presionar boton inicio
def BotonInicio():
    global EstadoBotonInicio, EstadoBotonParo
    EstadoBotonParo = digitalRead(BotonParo)
    if EstadoBotonParo == 1:
        EstadoBotonInicio = 0
    else:
        EstadoBotonInicio = digitalRead(BotonInicio)

# presionar boton de paro
def BotonParo():
    global EstadoBomba1, EstadoBomba2
    if EstadoBomba2 == 27:
        EstadoBomba1 = 27
        EstadoBomba2 = 26
        ActivarBombas(Apagado, Apagado)
    else:
        EstadoBomba1 = 26
        EstadoBomba2 = 27
        ActivarBombas(Apagado, Apagado)

# bucle principal

BotonInicio()

if EstadoBotonInicio == 1:
    LeerEstado()
if EstadoBajoBajo == 1 and EstadoBajo == 0:
    while EstadoBajoBajo == 1 and EstadoBajo == 0 and EstadoBotonParo == 0:
        ActivarBombas(Encendido, Encendido)
        LeerEstado()
    ActivarBombas(Encendido, Apagado)
    
elif EstadoBajo == 1 and EstadoAlto == 0:
    while EstadoBajo == 1 and EstadoAlto == 0 and EstadoBotonParo == 0:
        ActivarBombas(Encendido, Apagado)
        LeerEstado()
    ActivarBombas(Apagado, Apagado)
    
elif EstadoAlto == 1 and EstadoAltoAlto == 0:
    while EstadoAlto == 1 and EstadoAltoAlto == 0 and EstadoBotonParo == 0:
        ActivarBombas(Apagado, Apagado)
        LeerEstado()
        
elif EstadoAltoAlto == 1:
    while EstadoAltoAlto == 1:
        ActivarBombas(Apagado, Apagado)
        
elif digitalRead(BotonParo) == 1:
    BotonParo()
    EstadoBotonInicio = 0
    
else:
ActivarBombas(Apagado, Apagado)