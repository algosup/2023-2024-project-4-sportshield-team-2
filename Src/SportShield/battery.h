
//---------------GLOBAL VARIABLE-------------------

#define VBAT_ENABLE 14
float getBatteryVoltage();

float MotionData;
float RotationData;



//----------------SETUP FUNCTIONS--------------------

float getBatteryVoltage() {
  //unsigned int adcCount = analogRead(PIN_VBAT);
  float adcCount = analogRead(PIN_VBAT);
  float adcVoltage = (((adcCount - 3000) / 4096) * 0.55) + 3.6;
  //float vBat = adcVoltage * 1510.0/510.0;
  return adcVoltage;
}
