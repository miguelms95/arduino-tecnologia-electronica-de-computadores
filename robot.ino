/*
Autor: Miguel Martínez Serrano. www.miguelms.es
Robot TEC: declaración de constantes
*/
// los pines digitales 2 y 3 controlan el motor derecho
const int In1 = 2; // pin motor derecho
const int In2 = 3; // pin motor derecho
// los pines digitales 4 y 5 controlan el motor izquierdo
const int In3 = 4; // pin motor izquierdo
const int In4 = 5; // pin motor izquierdo
//los pines digitales 9 y 10 habilitan los motores
const int ENA = 9; // habilita el motor derecho
const int ENB = 10; // habilita el motor izquierdo

const int sensorIzquierda = 6; // pin del Arduino conectado al sensor óptico Izquierdo
const int sensorDerecha = 7; // pin del Arduino conectado al sensor óptico Derecho

const int BLANCO = 0; // si tapo da 0, porque refleja
const int NEGRO = 1;

int VELOCIDAD = 170;
int contador = 0;
//configuración de señales para el movimiento de los motores

/*
//giro hacia adelante del motor derecho
In1=HIGH In2=LOW
//giro hacia adelante del motor izquierdo
In3=HIGH In4=LOW
//giro hacia atrás del motor derecho
In1=LOW In2=HIGH
//giro hacia atrás del motor izquierdo
In3=LOW In4= HIGH
//Parar el motor derecho
In1= In2
//Parar el motor izquierdo
In3= In4 */

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);

  pinMode(sensorIzquierda,INPUT);
  pinMode(sensorDerecha,INPUT);
}

void acelera(){
  digitalWrite(In1, HIGH); digitalWrite(In2, LOW);  //adelante derecho
  digitalWrite(In3, HIGH); digitalWrite(In4, LOW);  //adelante izquierdo
}

void marchaAtras(){
  digitalWrite(In1, LOW); digitalWrite(In2, HIGH);  //atras derecho
  digitalWrite(In3, LOW); digitalWrite(In4, HIGH);  //atras izquierdo
}
void giraDerecha(){
  digitalWrite(In1, LOW); digitalWrite(In2, HIGH);  //atras derecho
  digitalWrite(In3, HIGH); digitalWrite(In4, LOW);  //adelante izquierdo
}
void giraIzquierda(){
  digitalWrite(In1, HIGH); digitalWrite(In2, LOW);  //adelante derecho
  digitalWrite(In3, LOW); digitalWrite(In4, HIGH);  //atras izquierdo
}
void frena(){
  //digitalWrite(ENA, LOW);
  //digitalWrite(ENB, LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

int leeIzquierda(){
  if(digitalRead(sensorIzquierda))
    return NEGRO;
  else
    return BLANCO;
}
int leeDerecha(){
  if(digitalRead(sensorDerecha))
    return NEGRO;
  else
    return BLANCO;
}

void loop() {
  //digitalWrite(ENA, HIGH);
  //digitalWrite(ENB, HIGH);
  analogWrite(ENA,VELOCIDAD);
  analogWrite(ENB,VELOCIDAD);
  
  if(leeIzquierda()==BLANCO){
    giraDerecha();
    delay(80);
  }
  if(leeDerecha()==BLANCO){
    giraIzquierda();
    delay(80);
  }
  while(leeIzquierda()==BLANCO && leeDerecha()==BLANCO){
    marchaAtras();
    delay(110);
    VELOCIDAD=160; // reduzco la velocida del giro izquierda
    giraIzquierda();
    delay(105);
    VELOCIDAD=170;
  }

  while(leeIzquierda()==NEGRO && leeDerecha()==NEGRO){
    acelera();
    /*if(contador == 3){
      giraDerecha();
      delay(150);
      contador = 0;
    }else{
      contador += 1;
    }*/
  }
}


