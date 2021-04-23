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
  char LetrasNumeros[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','*','+','-','¿','?','#','(',')','<','>','¡','!','='}; //arreglo con todos los posibles patrones
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
//t LetrasMatriz[5][8][8];
//trasMatriz[0]=A;



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
Serial.println(" bla bla bla.");
Serial.println("Opciones del sistema. ");
Serial.println("(1). Funcion de verificacion (2). Funcion imagen (3). Funcion publik");
  
//cion = Serial.read();
    

 
  

  verificacion();
  
} // cierre del setup


 void poti()
{
  potiValue = analogRead(0);
}


void loop()
{
  


  
  if(Serial.available()>0){
    opcion = Serial.read();
  	//rificacion();
    //rial.println(opcion);
    //rificacion();
  
    if(opcion>48 && opcion<=51){

        if(opcion == 49){
          verificacion();
         }

        else if(opcion == 50){
			/*for(int i =0; i<8; i++){
              for(int j =0; j<8; j++){
                  if(A[i][j]==1){
                      bitA[i] += pow(2,j);
                    Serial.println(pow(2,j));
                    Serial.println(bitA[i]);
                  }
              }
              Serial.println(bitA[i]);
            }*/
          for(int k=0; k<8; k++){
          	bitA[k]=(int)pow(2,k); 
          }
          encenderLed(bitA);
          //Serial.print(" Ingrese un solo caracter: ");
          //patron = Serial.read();	
          //imagen(patron);

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



/*void encenderLed(int arreglo[8][8]){ // funcion para encender los led's

  for (int i=0; i<8; i++){

    digitalWrite(fila[i], HIGH); // fila en nivel alto

    for(int j=0; j<8; j++){

      if (arreglo[i][j]== 0){ //condicion para que se encienda el led en esa posicion [i][j]

        digitalWrite(columna[j], LOW); 
      }  		
    }
    delay(2000); //duracion de encendido
    digitalWrite(fila[i], LOW);

    for(int j=0; j<8; j++){
      digitalWrite(columna[j], HIGH);

    }  
  }  
 poti();
}*/

void encenderLed(int arreglo[8]){
  for (int i=0; i<8; i++){
    Serial.println((int)pow(2,7+i)+1);
  	shiftOut(DATA, SHIFT, LSBFIRST, ~arreglo[i]);
    shiftOut(DATA, SHIFT, LSBFIRST, 128 >> i);
  }
  store();
}


void imagen(int a){ //funcion para mostrar un patron ingresado por el usuario
  
  for(int i =0; i<8; i++){
    for(int j =0; j<8; j++){
        if(A[i][j]==1){
            bitA[i] += pow(2,j);
        }
    }
  }
  
  if(a==65){
  	encenderLed(bitA);
}
  
//for(int k=0; k<49; k++){
//  if(LetrasNumeros[k] == a){
//    encenderLed(LetrasMatriz[k]);
//  }  
    
//}
  
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
  store();
  shiftOut(DATA, SHIFT, MSBFIRST, 0);
  store();
  
}




void store ()
{  
	digitalWrite (STORE, HIGH);
    delayMicroseconds (100);
  	digitalWrite (STORE, LOW);
    delayMicroseconds (10000);

}







