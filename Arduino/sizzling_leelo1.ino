#define PIR_PIN 2       // Pino onde o sensor PIR está conectado
#define LED_PIN 8       // Pino onde a lâmpada (LED) está conectada

void setup() {
  pinMode(PIR_PIN, INPUT);   // Configura o PIR como entrada
  pinMode(LED_PIN, OUTPUT);  // Configura o LED como saída
  digitalWrite(LED_PIN, LOW); // Lâmpada desligada inicialmente
  Serial.begin(9600);
  Serial.println("Sistema inicializado...");
}

void loop() {
  int pirState = digitalRead(PIR_PIN); // Lê o estado do PIR
  
  if (pirState == HIGH) { // Movimento detectado
    Serial.println("Movimento detectado! Ligando a lâmpada.");
    digitalWrite(LED_PIN, HIGH); // Liga o LED
  } else { // Sem movimento
    Serial.println("Sem movimento. Desligando a lâmpada.");
    digitalWrite(LED_PIN, LOW); // Desliga o LED
  }
  
  delay(500); // Pequeno atraso para estabilidade
}
