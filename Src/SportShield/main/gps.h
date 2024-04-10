//GPS
#include <Adafruit_GPS.h>


//----------------------GLOBAL VARIABLE-----------------

// GPS PA1010D
Adafruit_GPS GPS(&Serial1);
bool start_gps = false;
bool position_acquired = false;
uint32_t timer = millis();
#define GPS_WKUP_PIN D8


//----------------------SETUP FUNCTIONS-----------------

void gps_setup(void) {
  pinMode(GPS_WKUP_PIN, OUTPUT);
  digitalWrite(GPS_WKUP_PIN, LOW);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand("$PMTK225,4*2F");  // send to backup mode

}


void GPS_ISR() {
  if (Config.isActivate != 0) {
    if (!position_acquired) {
      start_gps = true;
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    } else {
      send_position = true;
      position_acquired = false;
    }
  }
}


void activateGPS() {
  if (start_gps == true) {
    digitalWrite(GPS_WKUP_PIN, HIGH);
    start_gps = false;
  }
}