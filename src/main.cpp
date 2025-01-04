#include <Arduino.h>
#include "WiFi.h"
#include "ThingSpeak.h"
#include <LiquidCrystal_I2C.h>

//Copy the Channel ID and API key from newly created channel at https://thingspeak.mathworks.com/
#define CHANNEL_ID    //new channel_id from the think speak website
#define CHANNEL_API_KEY   //"api_key"

WiFiClient client;

//Hardcode the WiFi SSID (network name) and password (network password)
#define WIFI_NETWORK    //"your_network_name"
#define WIFI_PASSWORD   //"your_network_password"
#define WIFI_TIMEOUT_MS 20000   //20s

//SENS0 is for MQ135 gas sensor (analog input) & SENS1 is for LM393 sound sensor (analog input)
#define ANLG_SENS0 34   //pin 34
#define ANLG_SENS1 32   //pin 32
//*_pins[0] is for MQ135 gas sensor (digital input) & *_pins[1] is for LM393 sound sensor (digital input) (redundant currently ver 1.00)
// const int dinput_pins[] = {35, 33};    //pin 35 and pin 33
// int n = sizeof(dinput_pins) / sizeof(int);

int sound_val = 0;
int gas_val = 0;
int connected = 0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display 

//function to connect to a WiFi network
void connectToWiFI(){
  Serial.print("Connecting to Wifi...");
  lcd.print("Connecting...");
  WiFi.mode(WIFI_STA);          //Initializing esp32 in station mode
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.print(".");
    delay(100);   //0.1s delay
  }
  Serial.println();

  if(WiFi.status() != WL_CONNECTED){
    lcd.clear();          //printing "failed to connect" status on lcd display and serial monitor
    lcd.setCursor(0,0);
    lcd.print("Failed to");
    lcd.setCursor(0,1);
    lcd.print("connect");

    Serial.println("Failed to connect");
  }else{
    connected = 1;
    lcd.clear();            //printing "connected" status on lcd display and serial monitor
    lcd.setCursor(0,0);
    lcd.print("Connected to");
    lcd.setCursor(0,1);
    lcd.print(WiFi.localIP());

    Serial.print("Connected to ");
    Serial.println(WiFi.localIP());
  }

  delay(3000);    //3s delay
}

//main() function
void setup() {
  //initializes the LCD Display
  lcd.clear();
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  // To initialize digital pins of sensors as input (redundant currently ver 1.00)
  // for(int i = 0; i < n; ++i){
  // pinMode(dinput_pins[i], INPUT);
  // }

  connectToWiFI();
  ThingSpeak.begin(client);
}

//arduino loop() function

void loop() {
  //Only executes if WiFi module is connected to a network
  if(connected){
    sound_val = analogRead(ANLG_SENS1);
    gas_val = analogRead(ANLG_SENS0);

    Serial.print("Air Quality Index and Noise respectively: ");
    Serial.print(gas_val, DEC); 
    Serial.print(" ppm , ");
    Serial.print(sound_val, DEC); 
    Serial.println(); 

    lcd.clear();          //Displaying runtime sensor values over lcd display
    lcd.setCursor(0,0);
    lcd.printf("AQI: %d ppm", gas_val);
    lcd.setCursor(0,1);
    lcd.printf("Noise: %d",sound_val);

    //Displaying the changes in gas_val and sound_val over channels in Thingspeak (https://thingspeak.mathworks.com/)
    ThingSpeak.setField(1, gas_val);
    ThingSpeak.setField(2, sound_val);
    ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY); 
    delay(15000);   //15s delay
  
  }
}

