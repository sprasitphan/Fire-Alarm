#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#define WIFI_NAME "HR-ONLINE"
#define WIFI_PASSWORD "HR@TET21"
#define LINE_TOKEN "UvsI5TkXVIgLYNaIw0DKtNO0RQ3KrBgngHtrNjGa0o5"

const char* ssid     = WIFI_NAME;
const char* password = WIFI_PASSWORD;

void wifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
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

int repeat_alarm_zs1 = -1;

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
  LINE.setToken(LINE_TOKEN);
  pinMode(sensor0, OUTPUT); 
  pinMode(sensor1, OUTPUT); 
  pinMode(sensor2, OUTPUT); 
  pinMode(sensor3, OUTPUT); 
  pinMode(sensor4, OUTPUT); 
  pinMode(sensor5, OUTPUT); 
  pinMode(sensor6, OUTPUT); 
  pinMode(sensor7, OUTPUT); 
  pinMode(sensor8, OUTPUT); 
}

void loop() {

  // MeOH ZS1
  alarm_zs1 = digitalRead(sensor0);
  if (alarm_zs1 == HIGH){
  Serial.print("ZS1: ");
  Serial.println(alarm_zs1); 
  limit_time_zs1--;
  if(limit_time_zs1 == 0) {LINE.notify("FIRE ALARM MeOH ZS1");}
  Serial.print("REPEAT ALARM: ");
  Serial.println(repeat_alarm_zs1);
  if(limit_time_zs1/65 == repeat_alarm_zs1) {LINE.notify("(REPEAT) FIRE ALARM MeOH ZS1"); repeat_alarm_zs1--;}
  }

  else {
  alarm_zs1 = digitalRead(sensor0);
  Serial.print("ZS1: ");
  Serial.println(alarm_zs1);
  limit_time_zs1 = 5;
  }

  delay(1000);

}