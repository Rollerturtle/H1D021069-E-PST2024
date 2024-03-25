#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>


int yelLED = D0;
int greLED = D1;
int redLED = D2;

const char *ssid ="TEKNIK UNSOED D3";
const char *password = "";

String web;
AsyncWebServer server(8080);

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yelLED, OUTPUT);
  pinMode(greLED, OUTPUT);

  Serial.begin(9600);
  delay(10);

  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ssid, pass);
  // Serial.print("TestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTest");
  //  Serial.println(ssid);
  // Serial.println(WiFi.softAPIP());

  // setting mode station
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  web+= "<h1> Web Control ESP8266</h1>";
  web+= "<p>LED 1: ";
  web+= "<a href=\"redLEDON\"\"><button>ON</button></a><a     href=\"redLEDOFF\"\"><button>OFF</button></a></p><br>";
  web+= "<p>LED 2: ";
  web+= "<a href=\"yelLEDON\"\"><button>ON</button></a><a href=\"yelLEDOFF\"\"><button>OFF</button></a></p><br>";
  web+= "<p>LED 3: ";
  web+= "<a href=\"greLEDON\"\"><button>ON</button></a><a href=\"greLEDOFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", web);
  });
  
  server.on("/redLEDON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, HIGH);
    request->send(200, "text/html", web);
  });
  
  server.on("/yelLEDON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yelLED, HIGH);
    request->send(200, "text/html", web);
  });

  server.on("/greLEDON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greLED, HIGH);
    request->send(200, "text/html", web);
  });

  server.on("/redLEDOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(redLED, LOW);
    request->send(200, "text/html", web);
  });
  
  server.on("/yelLEDOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yelLED, LOW);
    request->send(200, "text/html", web);
  });

  server.on("/greLEDOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(greLED, LOW);
    request->send(200, "text/html", web);
  });

  server.begin();

}

void loop() {

}