void setup() 
{
  // Configura o pino d7 como saída 
  pinMode(7, OUTPUT);
}

void loop() 
{
  // Configura o pino 7 como HIGH
  digitalWrite(7, HIGH);
  // Espera 1000 ms (1 segundo)
  delay(1000);             
  // Configura o pino 7 como LOW
  digitalWrite(7, LOW);   
  // Espera 1000 ms (1 segundo)
  delay(1000);            
}
