#define DATA 2 //Definicion de pin de datos
#define SHIFT 3 //Definicion de pin de cambio de registro
#define STORE 4 //Definicion de pin de almacenamiento



// PROGRAMA

// Declaracion de funciones y variables.
  int potiValue;
  const int fila[8] = {2,7,19,5,13,18,12,16}; // Vector para las filas
  const int columna[8] = {6,11,10,3,17,4,8,9}; //Vector para las columnas 
  void imagen(char, int);
  void encenderLed(int);
  void verificacion();
  int opcion = 0;
  int contadorTiempo=0;
  int VelAnimacion=0;
  int Numpatron;
  char patrones []={};
  char patron;
  char times[]={};
  int time;

int A[8][8]=  {        {1,1,0,0,0,0,1,1},
					   {1,0,0,0,0,0,0,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,1,1,0,0,0},
               };

int bitA[] = {0,0,0,0,0,0,0,0}; 

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


void setup(){
  
  	  pinMode(DATA, OUTPUT);
      pinMode(SHIFT, OUTPUT);
      pinMode(STORE, OUTPUT);
  

  	for(int i=0; i<8; i++){ //inicializar los pines como salidas con los vectores columna y fila
    
      pinMode(columna[i], OUTPUT);
      pinMode(fila[i], OUTPUT);
      Serial.begin(9600);
                                          
    
      
      digitalWrite(columna[i], HIGH); 	// matriz catodo comun, así que ponemos en high todas las columnas(catodos)
  
	}

    
    Serial.println(" MANUAL DE USO.");
    Serial.println("El presente manual esta organizado de la siguiente  manera:");
    Serial.println(" ");
    Serial.println("1. Funcion de verificacion");
    Serial.println("2. Funcion imagen");
    Serial.println("3. Funcion publik.");
    Serial.println("-----------------------------------------");
    Serial.println("1. Funcion de verificacion");
    Serial.println("En esta funcion usted podra comprobar que todos los leds de la matriz 8x8 estan funcionando correctamente, encendiendo los 64 leds.");
    Serial.println("-----------------------------------------");
    Serial.println("Presiona 1 para continuar ");
      while(Serial.available()==0){}
  	Serial.println(" ");
    Serial.println("2. Funcion imagen.");
    Serial.println("Esta funcion le permitira mostrar un patron en la matriz de leds. Le pedira ingresar un solo caracter, para esto puede ingresar letras de la A-Z, numeros del 0-9 y caracteres especiales como *, +, -, ¿, ?, #, (, ), <, >, ¡, !, =, luego de ingresarlo podra ver su caracter iluminado en la matriz de leds.");
    Serial.println("-----------------------------------------");
    Serial.println("3. Funcion publik");
    Serial.println("Con esta funcion se le permitira mostrar una secuencia de caracteres. Le pedira ingresar el numero de caracteres que desee iluminar en la matriz led, una vez ingresado le seguira pidiendo caracter por caracter y por cada caracter ingresado le pedira que ingrese un numero de tiempo que sera lo que tardara la visualización entre patrones, hasta completar la cantidad ingresada por usted al inicio de la funcion.");
    Serial.println(" ");

  
    //memoria dinamica
 
  char *pentrada= new char[11];
  char valor[11]={'B','I','E','N','V','E','N','I','D','O','.'};
    
  for(int k=0; k<11; k++){
    *(pentrada+k)= valor[k];				
  }
   for (int k=0; k<11;k++){
     Serial.print(*(pentrada+k));
  }
            
  delete [] pentrada;
 
Serial.println("Cual de las opciones del sistema desea ejecutar? ");
Serial.println(" ");
Serial.println("(1). Funcion de verificacion");
Serial.println("(2). Funcion imagen");
Serial.println("(3). Funcion publik");
  

  

  

  verificacion();
  
} // cierre del setup



void loop()
{
  


  
  if(Serial.available()>0){
    opcion = Serial.read();

  
    if(opcion>48 && opcion<=51){

        if(opcion == 49){
          verificacion();
         }

        else if(opcion == 50){

          Serial.print(" Ingrese un solo caracter: ");
          //Serial.println(patron);
          while(!Serial.available()){}
          if(Serial.available()){
            patron = (char)Serial.read();
          	imagen(patron);
          }

         }

        else if(opcion == 51){
          Serial.print("Ingrese el numero de patrones: ");
          Numpatron = Serial.read();
          for(int i=0; i< Numpatron; i++){
            Serial.print("Ingrese patron: ");
            patron= Serial.read();
            patrones[i]= patron;
            Serial.print("Ingrese el tiempo de duracion para ese patron: ");
            time= Serial.read();
            times[i]= time;
            //publik(patrones, times, Numpatron );

            }

      }

      else{
        Serial.println("Opciones");
        Serial.println("(1). Funcion de verificacion (2). Funcion imagen (3). Funcion publik");
        opcion = Serial.read();
      }
  }
	
  
  }  
  
} // cierre del Loop
  



// PROGRAMANDO LOS LED'S 



void encenderLed(int arreglo[8]){
  
  for (int i=0; i<8; i++){
    
    //Serial.println((int)pow(2,7+i)+1);
  	shiftOut(DATA, SHIFT, LSBFIRST, ~arreglo[i]);
    shiftOut(DATA, SHIFT, LSBFIRST, 128 >> i);
	unstore();
    store();
  }
}


void imagen(int a){ //funcion para mostrar un patron ingresado por el usuario
  
  if(a==65){
  for(int i =0; i<8; i++){
    for(int j =0; j<8; j++){
        if(A[i][j]==1){
            bitA[i] += (int)pow(2,j);
        }
    }
  }
 
  encenderLed(bitA);

}

  
}

/*void publik(char a[], char b[], int num){ // recibe patrones[], times[] y Numpatron
  
  contadorTiempo++; 
  
  for(int k=0; k< num; k++){
  
    while (contadorTiempo < b[k]){
      char Encender= a[k];
      encenderLed(Encender);


   	 }
    
  contadorTiempo=0;
  
 
  }

}*/


void verificacion ()
{
  shiftOut(DATA, SHIFT, MSBFIRST, 0);
  shiftOut(DATA, SHIFT, MSBFIRST, 255);
  unstore();
  store();
  shiftOut(DATA, SHIFT, MSBFIRST, 0);
  unstore();
  store();
  
}




void store ()
{  
  	digitalWrite (STORE, LOW);
    delayMicroseconds (100000);

}

void unstore()
{
 	digitalWrite (STORE, HIGH);
    delayMicroseconds (100000);
}






