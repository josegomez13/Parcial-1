#define DATA 2 //Definicion de pin de datos
#define SHIFT 3 //Definicion de pin de cambio de registro
#define STORE 4 //Definicion de pin de almacenamiento
void verificacion();

// PROGRAMA

int opcion = 0;

Serial.print("MANUAL DE USO.");
Serial.print("bla bla bla.");
Serial.print("opciones del sistema. ");
Serial.print("(1). Funcion verificacion (2). Funcion imagen (3). Funcion publik");
opcion = Serial.read();

int patron = 0;

while(opcion>0 && opcion<=3){

  if(opcion == 1){}

  else if(opcion == 2){
    
    Serial.print("Ingrese un solo caracter: ");
    patron = Serial.read();
    LetrasNumeros[] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,0,1,2,3,4,5,6,7,8,9,*,+,-,¿,?,#,(,),<,>,¡,!,=}; //arreglo con todos los posibles patrones
	
    imagen(LetrasNumeros, patron);
    
  }

  else if(opcion == 3){}
  
  else{
    Serial.print("opciones");
    Serial.print("1. verificacion 2. imagen 3. publik");
    opcion = Serial.read()}

}







void setup()
{
  pinMode(DATA, OUTPUT);
  pinMode(SHIFT, OUTPUT);
  pinMode(STORE, OUTPUT);
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

int Imagen[]={}


void loop()
{
  for(int i=0; i<8; i++)
   {
     shiftOut(DATA, SHIFT, LSBFIRST, Imagen[i]);
  shiftOut(DATA, SHIFT, LSBFIRST, 128 >> i);
    store();
  }

}




// PROGRAMANDO LOS LED'S 


//Vector para las filas con su numero de pin

const int fila[8]={
  
  2,7,19,5,13,18,12,16


};

//Vector para las columnas con su numero de pin

const in columna[8]={
  
  6,11,10,3,17,4,8,9

};

int A[8][8]=  {        {1,1,0,0,0,0,1,1},
					   {1,0,0,0,0,0,0,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,1,1,0,0,0},
               };

int E[8][8]=  {        {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,1,1,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,1,1,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
               };


int I[8][8]=  {        {1,0,0,0,0,0,0,1},
					   {1,0,0,0,0,0,0,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,0,0,0,0,1},
               };

int O[8][8]=  {        {1,0,0,0,0,0,0,1},
					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,0,0,0,0,1},
               };

int U[8][8]=  {        {1,0,0,1,1,0,0,1},
					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,0,0,0,0,1},
               };

int contadorTiempo = 0, VelAnimacion = 20; //variables para la animacion punto 5

LetrasNumeros[] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,0,1,2,3,4,5,6,7,8,9,*,+,-,¿,?,#,(,),<,>,¡,!,=}; //arreglo con todos los posibles patrones

void setup(){
  
  //inicializar los pines como salidas con los vectores columna y fila
  
  for(int i=0; i<8; i++){
    
    pinMode(columna[i], OUTPUT);
    pinMode(fila[i], OUTPUT);
    Serial.begin(9600);
    
    // matriz catodo comun, así que ponemos en high todas las columnas(catodos)
    
    digitalWrite(columna[i], HIGH); //todo apagado de entrada
     
  }

}

// programación de pines para la vocal A

void loop(){
  
  contadorTiempo++;
  
  if(contadorTiempo <= VelAnimacion){
  
    encenderLed(A);}
  }


void encenderLed(int arreglo[8][8]){

  for (int i=0; i<8; i++){

    digitalWrite(fila[i], HIGH); // fila en nivel alto

    for(int j=0; j<8; j++){

      if (A[i][j]==1){ //condicion para que se encienda el led en esa posicion [i][j]

        digitalWrite(columna[j], LOW); 
      }  		
    }
    delay(2); //duracion de encendido
    digitalWrite(fila[i], LOW);

    for(int j=0; j<8; j++){
      digitalWrite(columna[j], HIGH);

    }  
  }  

}


void imagen(int arreglo[], int a){ //funcion para mostrar un patron ingresado por el usuario
  
  for(int k=0; k<49; k++){
    if(arreglo[k] == a){
      encenderLed(a);
    }
  }
}




















