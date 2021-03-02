/*
 CONNECTIONS:
 D7 ---------> IN1(RELAY)WHICH IS FAN
 D6 ---------> IN2(RELAY)WHICH IS LIGHT
 D8 ---------> LED WHICH REPRESENTS Tv
 3v ---------> vcc(RELAY)
 GND --------> GND(RELAY)
 GND --------> GND(LED)
 
*/








//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
 
//Access point credentials
const char* ssid = "Sakthivel";           // YOUR HOTSPOT NAME
const char* pwd = "12345654321";          // YOUR HOTSPOT PASSWORD
const char* host = "http://192.168.1.8";  // YOUR IPV4 ADDRESS
String get_host = "http://192.168.1.8";
 
WiFiServer server(80);  // open port 80 for server connection
 
void setup() 
{
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  Serial.begin(115200); //initialise the serial communication
  delay(20);
 
  WiFi.begin(ssid, pwd);
 
   
    //starting the server
    server.begin();
 
}
 
void loop()
{
  //call_test();
  String s = get_device_status("tv");
  String t = get_device_status("fan");
  String u = get_device_status("light");
  Serial.println(s+t+u);
  
  if(s=="on")
  {
     digitalWrite(D8, HIGH); 
     
  }
  else if(s=="off")
  {
    digitalWrite(D8, LOW); 
  }
  if(t=="off")
  {
     digitalWrite(D7, HIGH); 
     
  }
  else if(t=="on")
  {
    digitalWrite(D7, LOW); 
  }
  if(u=="off")
  {
     digitalWrite(D6, HIGH); 
     
  }
  else if(u=="on")
  {
    digitalWrite(D6, LOW); 
  }
}
 
 
String get_device_status(String device_name)
  {
    
    WiFiClient client = server.available();
 
        HTTPClient http;
        String url = get_host+"/nodemcu/GetData.php?DN='"+device_name+"'";    // YOUR PHP FILE LOCATION
        
        http.begin(url);
       
        //GET method
        int httpCode = http.GET();
        String payload = http.getString();
        
        http.end();
        delay(1000);
        return payload;
  
  }
