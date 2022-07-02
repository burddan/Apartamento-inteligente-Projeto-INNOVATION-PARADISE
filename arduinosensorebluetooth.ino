//ATENÇÃO!!!! porta digital 1 utilizando para o modulo bluetooth
//Variável que irá receber comando do bluetooth
char data = 0;


// aCriando variável do buzzer
int buzzer = 2;



// Criando variáveis dos sensores
int TRIGsensor_1 = 4;
int ECHOsensor_1 = 5;

int TRIGsensor_2 = 6;
int ECHOsensor_2 = 7;

int TRIGsensor_3 = 8;
int ECHOsensor_3 = 9;

int TRIGsensor_4 = 12;
int ECHOsensor_4 = 13;

void setup() { //Colocando os as variáveis dos sensores nos pinos de entrada e saida
  
  Serial.begin (9600);
  
  pinMode(TRIGsensor_1, OUTPUT);
  pinMode(ECHOsensor_1, INPUT);
 
  pinMode(TRIGsensor_2, OUTPUT);
  pinMode(ECHOsensor_2, INPUT);
 
  pinMode(TRIGsensor_3, OUTPUT);
  pinMode(ECHOsensor_3, INPUT);
  
  pinMode(TRIGsensor_4, OUTPUT);
  pinMode(ECHOsensor_4, INPUT);
  pinMode(buzzer, OUTPUT);
 
}

void sensor_1(){ // Função do sensor 1 DA SALA
  int duration1, distance1;
  digitalWrite (TRIGsensor_1, HIGH);
  delayMicroseconds (10);
  digitalWrite (TRIGsensor_1, LOW);
  duration1 = pulseIn (ECHOsensor_1, HIGH);
  distance1 = (duration1/2) / 29.1;
      
  if (distance1 >= 14 and distance1 <= 18 ) //MUDAR A DISTANCIA NA SALAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  { 
    Serial.println("Sensor da sala detectado");
    Serial.print("Distancia do objeto ao sensor: ");
    Serial.print(distance1);
    Serial.println(" cm");
    
    tone(buzzer,1200);   
    delay(130);
    noTone(buzzer);
    delay(130);
    tone(buzzer,800);   
    delay(130);
    noTone(buzzer);
    delay(130);
    tone(buzzer,1000);   
    delay(240);
    tone(buzzer,1200);   
    delay(130);
    noTone(buzzer);
  }
}
void sensor_2(){ // Função do sensor 2
    int duration2, distance2;
    digitalWrite (TRIGsensor_2, HIGH);
    delayMicroseconds (10);
    digitalWrite (TRIGsensor_2, LOW);
    duration2 = pulseIn (ECHOsensor_2, HIGH);
    distance2 = (duration2/2) / 29.1;
    if (distance2 >= 26 and distance2 < 27)
  {
      Serial.println("Sensor do banheiro detectado");
      Serial.print("Distancia do objeto ao sensor: ");
      Serial.print(distance2);
      Serial.println(" cm");
      
      tone(buzzer,1000);   
      delay(250);
      noTone(buzzer);
      delay(250);
      tone(buzzer,1000);   
      delay(250);
      noTone(buzzer);
      delay(250);
  }
  
}
void sensor_3(){ // Função do sensor 3
    int duration3, distance3;
    digitalWrite (TRIGsensor_3, HIGH);
    delayMicroseconds (10);
    digitalWrite (TRIGsensor_3, LOW);
    duration3 = pulseIn (ECHOsensor_3, HIGH);
    distance3 = (duration3/2) / 29.1;
      
    if (distance3 >= 6 and distance3 < 11)
  {
      Serial.println("Sensor da lavanderia detectado");
      Serial.print("Distancia do objeto ao sensor: ");
      Serial.print(distance3);
      Serial.println(" cm");
      
      tone(buzzer, 800);   
      delay(220);
      noTone(buzzer);
      delay(220);
      tone(buzzer,700);   
      delay(220);
      noTone(buzzer);
      delay(220);
  }
  
      

}

void sensor_4(){ // Função do sensor 4
  int duration4, distance4;
  digitalWrite (TRIGsensor_4, HIGH);
  delayMicroseconds (10);
  digitalWrite (TRIGsensor_4, LOW);
  duration4 = pulseIn (ECHOsensor_4, HIGH);
  distance4 = (duration4/3) / 29.1;
 
  if (distance4 < 4 and distance4 < 0)
  {
    Serial.println("Sensor do quarto de casal detectado");
    Serial.print("Distancia do objeto ao sensor: ");
    Serial.print(distance4);
    Serial.println(" cm");
    
    tone(buzzer,1400);   
    delay(250);
    noTone(buzzer);
    delay(250);
    tone(buzzer,1200);   
    delay(250);
    noTone(buzzer);
    delay(250);
      
  }
        
     
}

void loop() {
  if(Serial.available() > 0)
  {
    //Verificar e ler o serial no bluetooth
    data = Serial.read();
  }   
sensor_1();
sensor_2();
sensor_3();
sensor_4();
}
  
