#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#define WIFI_NAME "KEMET Manufacturing"
#define WIFI_PASSWORD "P0lym3riZ@t!on"
#define LINE_TOKEN "JBF4OwoRbl3Klc0JYTIJCIlOQPXMY3momMkteXSwFaD"

const char* ssid     = WIFI_NAME;
const char* password = WIFI_PASSWORD;

void wifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }  
}

int limit_time_zs1 = 5;
int limit_time_zs2 = 5;
int limit_time_z1 = 5;
int limit_time_z2 = 5;
int limit_time_z3 = 5;
int limit_time_z4 = 5;
int limit_time_z9 = 5;
int limit_time_z10 = 5;
int limit_time_z11 = 5;

int repeat_alarm = -1;

const int sensor0 = D0;
const int sensor1 = D1;
const int sensor2 = D2;
const int sensor3 = D3;
const int sensor4 = D4;
const int sensor5 = D5;
const int sensor6 = D6;
const int sensor7 = D7;
const int sensor8 = D8;

int alarm_zs1 = 0;
int alarm_zs2 = 0;
int alarm_z1 = 0;
int alarm_z2 = 0;
int alarm_z3 = 0;
int alarm_z4 = 0;
int alarm_z9 = 0;
int alarm_z10 = 0;
int alarm_z11 = 0;

void setup() {
  Serial.begin(115200);
  wifi();
  pinMode(sensor0, INPUT); 
  pinMode(sensor1, INPUT_PULLUP); 
  pinMode(sensor2, INPUT_PULLUP); 
  pinMode(sensor3, INPUT_PULLUP); 
  pinMode(sensor4, INPUT_PULLUP); 
  pinMode(sensor5, INPUT_PULLUP); 
  pinMode(sensor6, INPUT_PULLUP); 
  pinMode(sensor7, INPUT_PULLUP); 
  pinMode(sensor8, INPUT);
  LINE.setToken(LINE_TOKEN);
  LINE.notify("ZS1 Ready..."); 
}

void loop() {

  // MeOH ZS1 GND
  alarm_zs1 = digitalRead(sensor0);
  if (alarm_zs1 == 0){
  Serial.print("ZS1: ");
  Serial.println(alarm_zs1); 
  limit_time_zs1 -= 1;
  if(limit_time_zs1 == 0) {LINE.notify("ZS1 - Internal room1"); LINE.notifyPicture("https://media.tenor.com/bH5qXUAuk4kAAAAC/fire.gif");}
  Serial.print("REPEAT ALARM: ");
  Serial.println(repeat_alarm);
  if(limit_time_zs1/65 == repeat_alarm) {LINE.notify("(REPEAT) ZS1 - Internal room1"); LINE.notifyPicture("https://media.tenor.com/bH5qXUAuk4kAAAAC/fire.gif"); repeat_alarm--;}
  }

  else {
  alarm_zs1 = digitalRead(sensor0);
  Serial.print("ZS1: ");
  Serial.println(alarm_zs1);
  limit_time_zs1 = 5;
  }

  delay(1000);

}