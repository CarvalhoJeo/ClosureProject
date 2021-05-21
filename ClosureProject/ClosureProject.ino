void setup() {
  //Inicia o monitor serial
  Serial.begin(9600);
  //Adiciona os sensores como INPUT
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  //Cria variaveis para saber quais sensores são quais
  int sensorFora = digitalRead(8), sensorDentro = digitalRead(7);
  //Criar duas variaveis estáticas para não cairem no loop
  static int pessoasSala = 0, c, c2 = 0;

  delay(100);


  //Vê se o sensor de fora foi detectado se for da 1 para a variavel de controle
  if(sensorFora < 1 && c2 == 0){
    c = 1;
    c2 = 1;
  }
  
  //Depois vê se o sensor de dentro vai ser detectado logo depois se for, ele vai adicionar uma pessoas pois primeiro passou pelo sensor de fora
  if(sensorDentro < 1 && c == 1){
    pessoasSala++;
    Serial.println("Pessoas na sala:");
    Serial.println(pessoasSala);
    c = 0;
    c2 = 2;
    }
      
  if(sensorDentro < 1 && c2 == 2 && c != 1){
    c = 2;
    c2 = 1;
  }
  if(sensorFora < 1 && c == 2){
    pessoasSala--;
    Serial.println("Pessoas na sala:");
    Serial.println(pessoasSala);
    c = 0;
    c2 = 0;
  }
 }
 
