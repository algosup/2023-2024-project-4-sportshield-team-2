# Code Documentation Team 2

<br>


| Code link |
| -------------- |
| [SportShield Code](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/tree/main/Src) |

<br>

## Libraries Included  

Library for managing timer interrupts on the NRF52 platform : 
-  **NRF52_MBED_TimerInterrupt.h**

Library for managing ISR timer interrupts on the NRF52 platform : 
-  **NRF52_MBED_ISR_Timer.h**

Main Arduino library for application development :
-  **Arduino.h**

Library for Bluetooth Low Energy (BLE) communication on Arduino : 
-  **ArduinoBLE.h**
  
Library for communication with the LSM6DS3 accelerometer and gyroscope : 
- **LSM6DS3.h**

Library for I2C protocol communication : 
-  **Wire.h**
  
Library for communication with Adafruit GPS module :
-  **Adafruit_GPS.h**

Library for communication with SIM800L GSM 2G module :
-  **SIM800L.h**

Header file containing the defined structure used in the code : 
- **struct.h**


## Variables Global  

### Configuration 

- `myConfig Config` : Structure containing configurations.

- `bool isAuthenticate` : Boolean variable indicating whether authentication has been successful.
 
 
### Timers 

- `NRF52_MBED_Timer ITimer(NRF_TIMER_3)` : Timer for interrupts.

- `NRF52_MBED_ISRTimer ISR_Timer` : ISR timer.

- `#define HW_TIMER_INTERVAL_MS 1` : Hardware timer interval in milliseconds.

- `#define TIMER_INTERVAL_120S 120000L` : Timer interval in milliseconds.
 

### Module bluetooth 

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

 
The code above are the Bluetooth Declarations of Service, Features and Descriptors.

In addition, there are the Bluetooth Configuration Variables.
 
 
### Movement and Acceleration Tracker 

- `LSM6DS3 imu(I2C_MODE, 0x6A)` : Acceleration/Rotation/Motion sensor 
 
### Module GPS 

- `Adafruit_GPS GPS(&Serial1)` : GPS module.

- `bool start_gps` : Indicates whether GPS is started.

- `bool position_acquired` : Indicates whether a position has been acquired.

### Module SIM 

- `UART Serial2(D0, D1, NC, NC)` : Initialize the communication with the SIM CARD.

  - Definition of pins for SIM800L module control.

  - Control variables for sending data via SIM800L module.

### Others variables  

- Constants and variables for motion and rotation thresholds.
    - `float MotionData` : Motion data.
    - `float RotationData` : Rotation data.

- Battery management.

- `int buzzerPin, int magnetPin` : Pins for buzzer and electromagnet.

- `unsigned long previousMillis` : Previous time for buzzer.

- `int currentRep` : Number of repetitions for buzzer.

- `const int ledPin` : LED pin.

- Function declarations for buzzer, GPS sensor, motion sensor, etc.

## Setup functions  

```
void setup(){
}
```

This function is a one-time function and will initialize the following elements: 

- Pin and peripheral initialization

- Timer initialization 

- Initialization of Bluetooth, IMU, GPS and SIM modules

- Battery voltage reading. 

## Loop functions  

```
void loop(){
}
```

The void loop() function being the main function of the code, it contains major pieces of code.
As these pieces of code are numerous, they won't be documented in this document.
Although, they will be well-commented by the developers, to enhance a clear understanding.


## Additional functions  

 The additional functions can be used for a variety of purposes. For example, to retrieve sensor data (such as battery voltage, motion and rotation data), manage time, activate/deactivate GPS and alarm, communicate with a Bluetooth Low Energy (BLE) device, and convert GPS coordinates.

Below is a more detailed description of the additional functions: 

```
float getBatteryVoltage() {}
```
 
- This function retrieves the battery voltage. It is useful to know if the battery needs to be charged or not. 


```
float getMotionData() {}
```

 - This function recovers movement data from the sensor. This makes it possible to measure the intensity of the shock (more or less strong) and to sound the buzzer according to the calculated intensity of the shock.


```
float getRotationData() {}
```

- Like the function `float getMotionData() `, it retrieves rotation data to make the buzzer sound according to the intensity of rotation. 

```
void Temps(void) {}
``` 
 - This function initializes the seconds and minutes. It can be used to display in the serial monitor when a shock occurs, for example or to initialize timers.
 
```
void PulseBuzzer(int repetitions, unsigned long durationOn, unsigned long durationOff) {}
```

- This function allows the buzzer to sound with repetitions and durations that can be defined.

```
void GPS_ISR() {}
```

- This function manages the start of GPS position search when required and the transmission of the acquired position when available, depending on the status of GPS activation and the status of the acquired position.
 
```
void activateGPS() {}
```

- This function activates the GPS, allowing GPS coordinates to be retrieved when a shock is detected.

```
void TimerHandler() {}
```
- This function launch the ISR timer. 

```
void SIM_ISR() {}
```

- Initializes position as TRUE boolean.

```
void onConnect(BLEDevice central) {}
```

- This functions allow the bluetooth connection and turn on a led to show if something is connect on bluetooth and if the apparaing bluetooth in on. 

```
void onDisconnect(BLEDevice central) {}
```

- This fonction allow the disconnection of the bluetooth and turn on a led to show it. 

```
void onWritePassword(BLEDevice central, BLECharacteristic characteristic) {}
```

- This fonction, intialize a password to connect with the bluetooth. That is useful for the security of the device. 


`char Conversion(unsigned short int data) {}`
- This function converts decimal values into hexadecimal values. It allows the code to understand correctly the decimal input as a hexadecimal input.

`void onWriteName(BLEDevice central, BLECharacteristic characteristic) {}`

- This function saves and displays an input name only if the user is authenticated.
It allows the user to rename the device.

`void onReadName(BLEDevice central, BLECharacteristic characteristic) {}`

- This function checks and displays the input name. It allows the user to display the saved name.

`void onWriteActivation(BLEDevice central, BLECharacteristic characteristic) {}`
- This function displays if the alarm is enabled or not. This allows the user to know when the alarm gets enabled or disabled.

`void onReadActivation(BLEDevice central, BLECharacteristic characteristic) {}`
- This function sets if the alarm is enabled or not. This allows the code to know when the alarm gets enabled or disabled.

`void onWriteUnlock(BLEDevice central, BLECharacteristic characteristic) {}`
- This function activates the electromagnet if the user is authenticated. This allows the user to know when the electromagnet should ring.

`String convertDMMtoDD(String dmmCoordinates) {}`
- This function converts decimal minutes to decimal degrees. This allows the code to understand correctly minutes as degrees.