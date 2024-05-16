#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define BUZZ D1
#define LED D2

const char* ssid = "punya gw";
const char* password = "slebew123";
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;
const char* mqtt_topic1 = "PA/IOT/API";
const char* mqtt_topic2 = "PA/IOT/PIR";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received message on topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  String payloadString;
  for (int i = 0; i < length; i++) {
    payloadString += (char)payload[i];
  }

  if (String(topic) == mqtt_topic1){
    if (payloadString == "1"){
      tone(BUZZ, 10);
    } else {
      noTone(BUZZ);
    }
  } else if (String(topic) == mqtt_topic2){
    if (payloadString == "1"){
      digitalWrite(LED, 1);
    } else {
      digitalWrite(LED, 0);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("mqtt-subscriber")) {
      Serial.println("connected");
      client.subscribe(mqtt_topic1);
      client.subscribe(mqtt_topic2);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  pinMode(BUZZ, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}