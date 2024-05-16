#include <ESP8266WiFi.h>
#include <PubSubClient.h> 

// WiFi
const char *ssid = "punya gw";        // Enter your WiFi name
const char *password = "slebew123";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const String topic1 = "PA/IOT/API";
const String topic2 = "PA/IOT/PIR";
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;

// Sensor Pins
#define pirSensor D7
#define fireSensor D6

WiFiClient espClient;
PubSubClient client(espClient);

bool alarmState = false;

void setup() {
  // Set software serial baud to 115200;
  Serial.begin(115200);

  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");

  // Setting LED pin as output
  pinMode(pirSensor, INPUT);
  pinMode(fireSensor, INPUT);

  // Connecting to an MQTT broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "mqttx_37aad4ab";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Public EMQX MQTT broker connected");
    } else {
      Serial.print("Failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  // Publish and subscribe
  client.publish(topic1.c_str(), "NodeMCU berhasil terkoneksi");
  client.subscribe(topic1.c_str());
  client.publish(topic2.c_str(), "NodeMCU berhasil terkoneksi");
  client.subscribe(topic2.c_str());
  sendSensorApi();
  sendSensorPir();
}

void sendSensorApi() {
  bool fire = digitalRead(fireSensor);
  String sensorData = String(fire);
  client.publish(topic1.c_str(), sensorData.c_str());
}

void sendSensorPir() {
  bool pir = digitalRead(pirSensor);
  String sensorData = String(pir);
  client.publish(topic2.c_str(), sensorData.c_str());
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];  // Convert *byte to string
  }
  Serial.print(message);
  Serial.println();
  Serial.println("-----------------------");
}

void loop() {
  client.loop();
  sendSensorApi();
  sendSensorPir();
  delay(3000);
}