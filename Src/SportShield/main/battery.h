
//---------------GLOBAL VARIABLE-------------------

#define VBAT_ENABLE 14
float getBatteryVoltage();
float getBatteryPercentage();

float MotionData;
float RotationData;



//----------------SETUP FUNCTIONS--------------------

float getBatteryVoltage() {
  //unsigned int adcCount = analogRead(PIN_VBAT);
  float adcCount = analogRead(PIN_VBAT);
  float adcVoltage = (((adcCount - 3000) / 4096) * 0.15) + 3.9;
  //float vBat = adcVoltage * 1510.0/510.0;
  return adcVoltage;
}

float getBatteryPercentage()
{
  const float maxVoltage = 4.2; // Maximum voltage when fully charged
  const float minVoltage = 3.0; // Minimum voltage when almost empty
  float currentVoltage = getBatteryVoltage();
  float percentage = ((currentVoltage - minVoltage) / (maxVoltage - minVoltage)) * 100.0;
  percentage = constrain(percentage, 0, 100);

  return percentage;
}




