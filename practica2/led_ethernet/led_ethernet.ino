#include <Ethernet.h>
#include <SPI.h>

//version 1.0 para ligar um foco por Ethernet 
// Dados da rede

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192, 168, 0, 101 }; // Ip do arduino
byte gateway[] = { 196,168, 0, 1 };
byte subnet[] = {255, 255, 255, 0};

int comparativo=0;
String numasstr;
String foco;

EthernetServer server(99); // Porta do arduino

int rele = 7;    // pino do relé: pino D7
String estado_foco;
int foco2;

void setup()
{
  // Inicializa os pinos como entrada ou saida
  Serial.begin(9600);
  // Configura dados de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  delay(1000);
  Serial.println("Setup complete");

  // configura pino D7 como saída e coloca em estado alto  
  pinMode(rele, OUTPUT);
  digitalWrite(rele,HIGH);
  
}



void loop()
{
// Configura o Cliente Arduino
EthernetClient client = server.available();

if (client) {
  numasstr = "";            
  Serial.println("Cliente conectado");
     
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;

    //Espera e guarda os dados quando esteja disponivel na rede.
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (numasstr.length() < 30) {
          numasstr.concat(c);
        }
        
      }
  }

    Serial.println("string: "+ numasstr);
    //Serial.println(numasstr.substring(0,4));
    
    
    Serial.println(numasstr.substring(2,3));
    estado_foco = numasstr.substring(2,3);
    foco2 = numasstr.substring(2,3).toInt();
    
          
    //printf(numasstr.substring(5,9));
    //cont = numasstr.toInt();
    //Proposito debug    
    //Serial.println("comparativo: "+ comparativo);
    //server.write(cont);

    
    //Imprime na consola serial os dados que recebe do Site.    
    Serial.println(numasstr.substring(0,1));
    foco = numasstr.substring(0,1);
    // No caso dois liga o relei, no caso um só imprime o valor na consola serial.
    switch (foco.toInt()) {
    case 1:
      comparativo = numasstr.substring(2,7).toInt();
      Serial.println(comparativo);
      break;
    case 2:
        switch(foco2){
        case 0:
           digitalWrite(rele,HIGH);
           Serial.println("low");
            break;
        case 1:
           digitalWrite(rele,LOW);       
           Serial.println("high");
           break;
        default:   
           digitalWrite(rele,LOW);       
           break;
        }  
      break;
    default: 
      // if nothing else matches, do the default
    break;
  }
    
    //else Serial.println("??"); 
    delay(1);
    //Desliga a conexão.
    client.stop();
    Serial.println("Cliente Desconectado");
  
 }  
}
