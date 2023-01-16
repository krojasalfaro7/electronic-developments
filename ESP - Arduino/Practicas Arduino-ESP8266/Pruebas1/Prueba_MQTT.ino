#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void setup(){
    const char* ssid = "ESP8266nodeMCU"; // Nombre del Wifi
    const char* password = "esp8266#"; // contraseña del Wifi 
    const char* mqttServer = "test.mosquitto.org"); // Ip del host mosquitto
    const int   mqttPort = 1883; // Puerto que maneja mosquitto
    
    WiFiClient espClient; // objeto de la clase WifiClient, el que va a permitir un conexion a un IP y puerto especifico
    PubSubClient client(espClient); // recibe la entrada de WifiClient
    
    Serial.begin(115200); // Iniciando monitor serial
    Wifi.begin(ssid, password); // iniciando conexion al router
    
    while (Wifi.status() != WL_CONNECTED){  // bucle que espera que la conexion se complete
        delay(1000);
        Serial.println("Conectadonde a la red...");
    }
    Serial.println("Conectado a la red WIFI: ");
    Serial.println(Wifi.localIP());

    client.setServer(mqttServer, mqttPort); // indicando los parametros para conectarse al broker mosquito
    while (!client.connected()){
        if (client.connected("ESP8266Client")){
            Serial.println("connected");
        }
        else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
        }
    }
    client.publish("prueba_1", "Hola desde el ESP8266");
    client.subscribe("prueba_1");

void callback(char* topic, byte* payload, unsigned int length) {
 
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
 
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
  }
 
    Serial.println();
    Serial.println("-----------------------");
}   
}


void loop(){
  client.loop();
}

