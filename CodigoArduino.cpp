
#define DATA 2 //Definicion de pin de datos
#define SHIFT 3 //Definicion de pin de cambio de registro
#define STORE 4 //Definicion de pin de almacenamiento
void verificacion();

void setup()
{
  
}

void verificacion ()
{
  shiftOut(DATA, SHIFT, MSBFIRST, 0);
  shiftOut(DATA, SHIFT, MSBFIRST, 255);
  store();
}

void store ()
{
  
	digitalWrite (STORE, HIGH);
    delayMicroseconds (10);
  	digitalWrite (STORE, LOW);
    delayMicroseconds (10);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}