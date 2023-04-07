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

void RutinaBotonInicio()
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

void AlternarBombas()
{
	if(EstadoBomba2==13)
	{
		EstadoBomba1=13;
		EstadoBomba2=12;
	}
	else
	{
		EstadoBomba1=12;
		EstadoBomba2=13;
	}
}

void ModoAutomatico()
{
	while(EstadoBotonInicio==1&&EstadoBotonParo==0)
	{
		LeerEstado();
		if(EstadoBajoBajo==1&&EstadoBajo==0&&EstadoBotonInicio==1)
		{
			while (EstadoBajoBajo==1&&EstadoBajo==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Encendido);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			
		}
		else if(EstadoBajoBajo==1&&EstadoBajo==1&&EstadoAlto==0&&EstadoBotonInicio==1)
		{
			while (EstadoBajoBajo==1&&EstadoBajo==1&&EstadoAlto==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			AlternarBombas();
		}
		else if(EstadoBajoBajo==1&&EstadoBajo==1&&EstadoAlto==1&&EstadoAltoAlto==0&&EstadoBotonInicio==1)
		{
			while (EstadoBajoBajo==1&&EstadoBajo==1&&EstadoAlto==1&&EstadoAltoAlto==0&&EstadoBotonParo==0)
			{
				ActivarBombas(Apagado,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			AlternarBombas();
			
		}
		else if(EstadoAltoAlto==1)
		{
			while (EstadoAltoAlto==1)
			{
				ActivarBombas(Apagado,Apagado);
				EstadoBotonInicio=0;
			}
		}
		else if(EstadoBotonParo==1)
		{
			AlternarBombas();
			EstadoBotonInicio = 0;
			ActivarBombas(Apagado,Apagado);
		}
		else
		ActivarBombas(Apagado,Apagado);
	}
	ActivarBombas(Apagado,Apagado);

}
void loop()
{
	RutinaBotonInicio();
	ModoAutomatico();
	EstadoBotonParo=0;
}