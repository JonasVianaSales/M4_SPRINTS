/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <ESPmDNS.h>


const char* ssid = "Confortare esto vir!";
const char* password = "QazWsx@123";

// Set web server port number to 80
WiFiServer server(80);

String header;

String output1State = "off";
String output2State = "off";
String output7State = "off";
String output8State = "off";
String output37State = "off";

const int output1 = 1;
const int output2 = 2;
const int output7 = 7;
const int output8 = 8;
const int output37 = 37;

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output7, OUTPUT);
  pinMode(output8, OUTPUT);
  pinMode(output37, OUTPUT);
  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output7, LOW);
  digitalWrite(output8, LOW);
  digitalWrite(output37, LOW);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   

  if (client) {                             
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {            
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                    

          if (currentLine.length() == 0) {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("GPIO 1 on");
              output1State = "on";
              digitalWrite(output1, HIGH);
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(output1, LOW);
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(output2, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            }
              else if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("GPIO 7 on");
              output7State = "on";
              digitalWrite(output7, HIGH);
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("GPIO 7 off");
              output7State = "off";
              digitalWrite(output7, LOW);
            } else if (header.indexOf("GET /8/on") >= 0) {
              Serial.println("GPIO 8 on");
              output8State = "on";
              digitalWrite(output8, HIGH);
            } else if (header.indexOf("GET /8/off") >= 0) {
              Serial.println("GPIO 8 off");
              output8State = "off";
              digitalWrite(output8, LOW);
            }
              else if (header.indexOf("GET /37/on") >= 0) {
              Serial.println("GPIO 37 on");
              output37State = "on";
              digitalWrite(output37, HIGH);

              



            } else if (header.indexOf("GET /37/off") >= 0) {
              Serial.println("GPIO 37 off");
              output37State = "off";
              digitalWrite(output37, LOW);
            }
            
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4C4CAF; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            client.println("<body><h1>Cada jogador pega um bloco, se errar, o buzzer toca e o jogador perde</h1>");
                  
            if (output1State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">??</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">Safe</button></a></p>");
            } 
               
     
            if (output2State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">??</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">Safe</button></a></p>");
            }
            client.println("</body></html>");
     
            if (output37State=="off") {
              client.println("<p><a href=\"/37/on\"><button class=\"button\">??</button></a></p>");
            } else {
              client.println("<p><a href=\"/37/off\"><button class=\"button button2\">ERROU</button></a></p>");
            }
            client.println("</body></html>");


            if (output7State=="off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button\">??</button></a></p>");
            } else {
              client.println("<p><a href=\"/7/off\"><button class=\"button button2\">Safe</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            
            // If the output8State is off, it displays the ON button       
            if (output8State=="off") {
              client.println("<p><a href=\"/8/on\"><button class=\"button\">??</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button button2\">Safe</button></a></p>");
            }
            client.println("</body></html>");
            
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') { 
          currentLine += c; 
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
