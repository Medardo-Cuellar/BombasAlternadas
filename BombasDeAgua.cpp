//programa de bombas de agua
// definicion de salidas
int BombaPrincipal = 12, BombaAuxiliar = 13;
// definicion de entradas
const int BajoBajo = 2, Bajo = 3, Alto = 4, AltoAlto = 5, BotonInicio = 6, BotonParo = 7; 

int EstadoBomba1 = 0, EstadoBomba2 = 0,EstadoBotonInicio = 0, EstadoBotonParo=0, EstadoBajoBajo, EstadoBajo, EstadoAlto, EstadoAltoAlto, Encendido = 1, Apagado =0, espera = 100;

void setup()
{
	pinMode(BajoBajo,INPUT);
	pinMode(Bajo,INPUT);
	pinMode(Alto,INPUT);
	pinMode(AltoAlto,INPUT);

	pinMode(BombaPrincipal,OUTPUT);
	pinMode(BombaAuxiliar,OUTPUT);

    EstadoBomba1 = BombaPrincipal;
    EstadoBomba2 = BombaAuxiliar;
}
void LeerEstado()
{
	EstadoBajoBajo = digitalRead(BajoBajo);
	EstadoBajo = digitalRead(Bajo);
	EstadoAlto = digitalRead(Alto);
	EstadoAltoAlto = digitalRead(AltoAlto);
    EstadoBotonParo=digitalRead(BotonParo);
}

void ActivarBombas(int bomba1, int bomba2)
{
	digitalWrite(EstadoBomba1,bomba1);
	delayMicroseconds(espera);
	digitalWrite(EstadoBomba2,bomba2);
	delayMicroseconds(espera);
}

void BotonInicio()
{
    EstadoBotonParo=digitalRead(BotonParo);
    if(EstadoBotonParo==1)
    {
        EstadoBotonInicio=0;
    }
    else
    {
        EstadoBotonInicio=digitalRead(BotonInicio);
    }
}

void BotonParo()
{
	if(EstadoBomba2==13)
	{
		EstadoBomba1=13;
		EstadoBomba2=12;
		ActivarBombas(Apagado,Apagado);
	}
	else
	{
		EstadoBomba1=12;
		EstadoBomba2=13;
		ActivarBombas(Apagado,Apagado);
	}
}

void loop()
{
	BotonInicio();
	if(EstadoBotonInicio==1)
	{
		LeerEstado();
		if(EstadoBajoBajo==1&&EstadoBajo==0)
		{
			while (EstadoBajoBajo==1&&EstadoBajo==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Encendido);
                LeerEstado();
			}
			ActivarBombas(Encendido,Apagado);
		}
		else if(EstadoBajo==1&&EstadoAlto==0)
		{
			while (EstadoBajo==1&&EstadoAlto==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Apagado);
                LeerEstado();
			}
			ActivarBombas(Apagado,Apagado);
		}
		else if(EstadoAlto==1&&EstadoAltoAlto==0)
		{
			while (EstadoAlto==1&&EstadoAltoAlto==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Apagado,Apagado);
                LeerEstado();
			}
		}
		else if(EstadoAltoAlto==1)
		{
			while (EstadoAltoAlto==1)
			{
				ActivarBombas(Apagado,Apagado);
			}
		}
	}
	else if(digitalRead(BotonParo)==1)
	{
		BotonParo();
        EstadoBotonInicio = 0;
	}
    else
    {
        ActivarBombas(Apagado,Apagado);
    }
}