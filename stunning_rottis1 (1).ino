#define DATA 2 //Definicion de pin de datos
#define SHIFT 3 //Definicion de pin de cambio de registro
#define STORE 4 //Definicion de pin de almacenamiento



// PROGRAMA

// Declaracion de funciones y variables.

  const int fila[8] = {2,7,19,5,13,18,12,16}; // Vector para las filas
  const int columna[8] = {6,11,10,3,17,4,8,9}; //Vector para las columnas 
  //void imagen(char, int);
  void encenderLed(char);
  void verificacion();
  int opcion = 0;
  int contadorTiempo=0;
  int VelAnimacion=0;
  char LetrasNumeros[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','*','+','-','¿','?','#','(',')','<','>','¡','!','='}; //arreglo con todos los posibles patrones
  int Numpatron;
  char patrones []={};
  char patron;
  char times[]={};
  int time;
	int A[8][8]=  {    {1,1,0,0,0,0,1,1},
					   {1,0,0,0,0,0,0,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,0,0,0},
  					   {0,0,0,1,1,0,0,0},
               };
	int E[8][8]=  {       {0,0,0,0,0,0,0,0},
					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,1,1,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,1,1,1,1,1},
  					   {0,0,0,0,0,0,0,0},
  					   {0,0,0,0,0,0,0,0},
               };


int I[8][8]=  {       {1,0,0,0,0,0,0,1},
					   {1,0,0,0,0,0,0,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,1,1,0,0,1,1,1},
  					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,0,0,0,0,1},
               };

int O[8][8]=  {       {1,0,0,0,0,0,0,1},
					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,1,1,0,0,1},
  					   {1,0,0,0,0,0,0,1},
  					   {1,0,0,0,0,0,0,1},
               };

int U[8][8]=  {       {1,0,0,1,1,0,0,1},
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
  Serial.println("MANUAL DE USO.");
Serial.println("bla bla bla.");
Serial.println("opciones del sistema. ");
Serial.println("(1). Funcion de verificacion (2). Funcion imagen (3). Funcion publik");
  
} // cierre del setup






void loop()
{
  


opcion = Serial.read();
  

while(opcion>0 && opcion<=3){

  if(opcion == 1){
    verificacion();
    //encenderLed(A);
  }
  
  else if(opcion == 2){

    Serial.print("Ingrese un solo caracter: ");
    patron = Serial.read();	
    //imagen(patron);
    
  }

  else if(opcion == 3){
    Serial.print("Ingrese el numero de patrones: ");
    Numpatron = Serial.read();
    for(int i=0; i< Numpatron; i++){
      Serial.print("Ingrese patron: ");
      patron= Serial.read();
      patrones[i]= patron;
      Serial.print("Ingrese el tiempo de duracion para ese patron: ");
      time= Serial.read();
      times[i]= time;
      //publik(patrones, times);
      
 		}
    
  }
  
  else{
    Serial.print("opciones");
    Serial.print("(1). Funcion de verificacion (2). Funcion imagen (3). Funcion publik");
    opcion = Serial.read();
  }
    
}
  
} // cierre del Loop
  



// PROGRAMANDO LOS LED'S 








void encenderLed(int arreglo[8][8]){ // funcion para encender un los led's

  for (int i=0; i<8; i++){

    digitalWrite(fila[i], HIGH); // fila en nivel alto

    for(int j=0; j<8; j++){

      if (arreglo[i][j]== 1){ //condicion para que se encienda el led en esa posicion [i][j]

        digitalWrite(columna[j], LOW); 
      }  		
    }
    delay(2000); //duracion de encendido
    digitalWrite(fila[i], LOW);

    for(int j=0; j<8; j++){
      digitalWrite(columna[j], HIGH);

    }  
  }  

}


void imagen(char a){ //funcion para mostrar un patron ingresado por el usuario
  
  for(int k=0; k<49; k++){
    if(LetrasNumeros[k] == a){
      encenderLed(A[8][8]);
    }
  }
}

/*void publik(char a[], char b[]){
  contadorTiempo++; 
  
  for(int k=0; k< Numpatron; k++){
  
    while (contadorTiempo < times[k]){
      char Encender= patrones[k];
      encenderLed(Encender[8][8]);


   	 }
    
  contadorTiempo=0;
  
 
  }

}*/


void verificacion ()
{
  shiftOut(DATA, SHIFT, MSBFIRST, 0);
  shiftOut(DATA, SHIFT, MSBFIRST, 255);
  store();
  
}

void store ()
{
  
	digitalWrite (STORE, HIGH);
    delayMicroseconds (1000);
  	digitalWrite (STORE, LOW);
    delayMicroseconds (1000);
}
