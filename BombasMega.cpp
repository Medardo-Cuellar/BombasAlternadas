//programa de bombas de agua para mega
// definicion de salidas
int BombaPrincipal = 34;
int BombaAuxiliar = 36;
// definicion de entradas
const int BajoBajo = 22;
const int Bajo = 24;
const int Alto = 26;
const int AltoAlto = 28;
const int BotonInicio = 30;
const int BotonParo = 32;

int EstadoBomba1 = 0;
int EstadoBomba2 = 0;
int EstadoBotonInicio = 0;
int EstadoBotonParo=0;
int EstadoBajoBajo;
int EstadoBajo;
int EstadoAlto;
int EstadoAltoAlto;

int Encendido = 1;
int Apagado = 0;
int floatON = 1;
int floatOFF = 0;
int Trayectoria = 0;

int espera = 100;

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
	if(EstadoBomba2==BombaAuxiliar)
	{
		EstadoBomba1=BombaAuxiliar;
		EstadoBomba2=BombaPrincipal;
	}
	else
	{
		EstadoBomba1=BombaPrincipal;
		EstadoBomba2=BombaAuxiliar;
	}
}

void CambiarTrayecoria()
{
	if(Trayectoria==0)
	{
		Trayectoria=1;
	}
	else
	{
		Trayectoria = 0;
	}
}

void ModoAutomatico()

{
	while(EstadoBotonInicio==1&&EstadoBotonParo==0)
	{
		LeerEstado();
		if(EstadoBajoBajo==floatOFF&&EstadoBotonInicio==1&&Trayectoria==0)
		{
			while (EstadoBajoBajo==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Encendido);
				LeerEstado();
				EstadoBotonInicio=1;
			}
		}
		else if(EstadoBajoBajo==floatON&&EstadoBajo==floatOFF&&EstadoBotonInicio==1&&Trayectoria==0)
		{
			while (EstadoBajoBajo==floatON&&EstadoBajo==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Encendido);
				LeerEstado();
				EstadoBotonInicio=1;
			}
		}
		else if(EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatOFF&&EstadoBotonInicio==1&&Trayectoria==0)
		{ 
			while (EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			AlternarBombas();
		}
		else if(EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatON&&EstadoAltoAlto==floatOFF&&EstadoBotonInicio==1&&Trayectoria==0)
		{
			while (EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatON&&EstadoAltoAlto==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Apagado,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			CambiarTrayecoria();
			//AlternarBombas();
		}
		if(EstadoBajoBajo==floatOFF&&EstadoBotonInicio==1&&Trayectoria==1)
		{
			while (EstadoBajoBajo==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Encendido);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			CambiarTrayecoria();
		}
		else if(EstadoBajoBajo==floatON&&EstadoBajo==floatOFF&&EstadoBotonInicio==1&&Trayectoria==1)
		{
			while (EstadoBajoBajo==floatON&&EstadoBajo==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Encendido,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
		}
		else if(EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatOFF&&EstadoBotonInicio==1&&Trayectoria==1)
		{ 
			while (EstadoBajoBajo==floatON&&EstadoBajo==floatON&&EstadoAlto==floatOFF&&EstadoBotonParo==0)
			{
				ActivarBombas(Apagado,Apagado);
				LeerEstado();
				EstadoBotonInicio=1;
			}
			AlternarBombas();
			//CambiarTrayecoria();
		}
		else if(EstadoAltoAlto==floatON)
		{
			while (EstadoAltoAlto==floatON)
			{
				ActivarBombas(Apagado,Apagado);
				EstadoBotonInicio=0;
			}
		}
		else if(EstadoBotonParo==1)
		{
			AlternarBombas();
			//CambiarTrayecoria();
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