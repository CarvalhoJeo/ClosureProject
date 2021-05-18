void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  int sensorFora = digitalRead(8), sensorDentro = digitalRead(7), pessoasSala = 0;

  delay(1000);
  if(sensorFora < 1){
    if(sensorDentro < 1){
      pessoasSala++;
      Serial.println("Pessoas na sala:");
      Serial.println(pessoasSala);
    }else{
      Serial.println("Pessoas na sala:");
      Serial.println(pessoasSala);
    }
    }else if(sensorDentro < 1){
      if(sensorFora < 1){
      pessoasSala--;
      Serial.println("Pessoas na sala:");
      Serial.println(pessoasSala);
    }else{
      Serial.println("Pessoas na sala:");
      Serial.println(pessoasSala);
    }
  }
}
