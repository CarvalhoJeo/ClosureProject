void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  int sensorFora = digitalRead(8), sensorDentro = digitalRead(7);
  static int pessoasSala = 0, c;

  delay(1000); 
  if(sensorFora < 1){
    c = 1;
  }
  if(sensorDentro < 1 && c == 1){
    pessoasSala++;
    Serial.println("Pessoas na sala:");
    Serial.println(pessoasSala);
    c = 0;
    } 
  if(sensorDentro < 1){
    c = 2;
  }
  if(sensorFora < 1 && c == 2){
    pessoasSala++;
    Serial.println("Pessoas na sala:");
    Serial.println(pessoasSala);
    c = 0;
  }
 }
