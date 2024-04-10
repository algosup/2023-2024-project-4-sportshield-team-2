# Code Documentation  

<br>

[<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg"  width="25px" align=right>](https://www.linkedin.com/in/rapha%C3%ABl-descamps-201112293)


| Author :       | Code link |
| -------------- | -------------- |
| **Raphaël Descamps** <img src="https://ca.slack-edge.com/T019N8PRR7W-U05TNB290FJ-abc72bbf0d47-512" width="50px" align=center> | [SportShield Code](../CodeDocumentation/SportShield_Code/SS_05-03_anglais-batterycontrol/SS_05-03_anglais-batterycontrol.ino) |

## library's included : 

Library for managing timer interrupts on the NRF52 platform : 
-  **NRF52_MBED_TimerInterrupt.h**

Library for managing ISR timer interrupts on the NRF52 platform : 
-  **NRF52_MBED_ISR_Timer.h**

Main Arduino library for application development :
-  **Arduino.h**

Library for Bluetooth Low Energy (BLE) communication on Arduino : 
-  **ArduinoBLE.h**

Header file containing the defined structure used in the code : 
- **struct.h**

Library for communication with the LSM6DS3 accelerometer and gyroscope : 
- **LSM6DS3.h**

Library for I2C protocol communication : 
-  **Wire.h**

Library for communication with Adafruit GPS module :
-  **Adafruit_GPS.h**

Library for communication with SIM800L GSM 2G module :
-  **SIM800L.h**

## Variables Global  :

### Configuration :

- `myConfig Config` : Structure containing configurations.

- `bool isAuthenticate` : Boolean variable indicating whether authentication has been successful.
 
 
### Timers :

- `NRF52_MBED_Timer ITimer(NRF_TIMER_3)` : Timer for interrupts.

- `NRF52_MBED_ISRTimer ISR_Timer` : ISR timer.

- `#define HW_TIMER_INTERVAL_MS 1` : Hardware timer interval in milliseconds.

- `#define TIMER_INTERVAL_120S 120000L` : Timer interval in milliseconds.
 

### Module bluetooth :

```
BLEService PasswordService("19B10000-E8F2-537E-4F6C-D104768A1213");  
BLEService ConfigService("19B10000-E8F2-537E-4F6C-D104768A1214");

BLEShortCharacteristic PasswordCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1213", BLEWrite);  
BLEStringCharacteristic NameCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite, 20);
BLEStringCharacteristic MACCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1217", BLERead, 20);
BLEBooleanCharacteristic ActivationCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);
BLEBooleanCharacteristic UnlockCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1216", BLEWrite);

BLEDescriptor PasswordDescriptor("2901", "Password");  
BLEDescriptor NameDescriptor("2901", "Name");
BLEDescriptor ActivationDescriptor("2901", "Activation");
BLEDescriptor UnlockDescriptor("2901", "Unlock");
BLEDescriptor MACDescriptor("2901", "MAC Address");

bool BLE_activated = true;  
uint32_t tim_connec = 0;
```

 
The code below are the Bluetooth Declarations of Service, Features and Descriptors.

In addition, there are the Bluettoth Configuration Variables.
 
 
### Movement and Acceleration tracker :

- `LSM6DS3 imu(I2C_MODE, 0x6A)` : Acceleration/Rotation/motion sensor 
 
### Module GPS :

- `Adafruit_GPS GPS(&Serial1)` : GPS module.

- `bool start_gps` : Indicates whether GPS is started.

- `bool position_acquired` : Indicates whether a position has been acquired.

### Module SIM :

- `UART Serial2(D0, D1, NC, NC)` : Initialize the communication with the SIM CARD

  - Definition of pins for SIM800L module control.

  - Control variables for sending data via SIM800L module.

### Others : 
 
