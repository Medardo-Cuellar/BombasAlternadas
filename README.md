
# Portada
Universidad Tecnológica de Nuevo Laredo

Control de Motores II

Proyecto 3 Control de Bombeo Alternado	

**Docente: Jose Martin Zamora Fernandez**

Cuatrimestre: 8 Grupo: A

*Luis Medardo Rodríguez Cuellar*

*Kenia Alexali Aranda Romero*

Fecha de entrega 

18 de abril de 2023
# <a name="_toc132787073"></a>**Introducción**
Consta de la automatización de dos bombas con función de alternado. Las cuales alternan entre los siguientes estados:

|**Botón START**|**Botón STOP**|**Bajo-Bajo**|**Bajo**|**Alto**|**Alto-Alto**|**Que ocurre**|
| :- | :- | :- | :- | :- | :- | :- |
|1|0|1|0|0|0|Las dos bombas entran en funcionamiento|
|1|0|1|1|0|0|Solo una bomba entra en funcionamiento "está alternando" si aun con la bomba funcionando, continua el nivel, vuelve a encender las dos bombas. Si se detecta que se drena en este estado no se enciende la bomba hasta llegar al sensor.|
|1|0|1|1|1|0|Las dos bombas están apagadas, pero todavía se puede controlar con los botones y si se baja el nivel, entra la bomba alternada|
|1|0|1|1|1|1|El sistema se queda apagado completo y no dejan de funcionar los botones|
|1 V 0|1|1|0|0|0|Las dos bombas se apagan si se presiona el botón paro|
|1 V 0|1|1|1|0|0|Se apaga la bomba que está funcionando|
|1 V 0|1|1|1|1|0|Se desactiva el modo automático y aunque baje el nivel, las bombas no se van a accionar|
|1 V 0|1|1|1|1|1|El sistema está completamente desactivado, no se puede hacer control, se tiene que reiniciar como medida de seguridad|



# <a name="_toc132787074"></a>**Desarrollo**
## <a name="_toc132787075"></a>**Materiales**

|**Objeto**|**Cantidad**|
| :- | :-: |
|Breadboard|1|
|Pushbutton|2|
|Jumpers|18|
|Data cable|1|
|Modulo de relevadores|1|
|Manguera flexible transparente|3|
|Bombas 12V|2|
|Flotadores|4|
|Resistencias|6|
|Depositos de plastico|2|
|Fuente de 12V|1|

# **Código**
Este se encuentra dentro de este repositorio, está disponible para ver

Incluidos los cambios realizados con el tiempo.
# **Diagramas**
Se encuentran también en este repositorio
# <a name="_toc132787080"></a>**Conclusión**
Saber controlar motores es una habilidad importante que puede abrir un abanico de oportunidades en diversos campos y contribuir al desarrollo de tecnologías innovadoras que mejoren nuestras vidas.

