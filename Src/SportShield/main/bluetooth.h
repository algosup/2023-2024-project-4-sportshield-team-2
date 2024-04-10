// BLE
#include <ArduinoBLE.h>
#include "struct.h"

//-----------------------GLOBAL VARIABLE--------------------------
myConfig Config;
bool isAuthenticated = false;

BLEService PasswordService("19B10000-E8F2-537E-4F6C-D104768A1213");  // Bluetooth® Low Energy Service
BLEService ConfigService("19B10000-E8F2-537E-4F6C-D104768A1214");

BLECharacteristic PasswordCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1213", BLEWrite | BLEAuthenticate);  // Bluetooth® Low Energy Characteristic
BLECharacteristic NameCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite | BLEAuthenticate, 20);
BLECharacteristic MACCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1217", BLERead, 20);
BLECharacteristic ActivationCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite | BLEAuthenticate);
BLECharacteristic UnlockCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1216", BLEWrite | BLEAuthenticate);

BLEDescriptor PasswordDescriptor("2901", "Password");  // Bluetooth® Low Energy Descriptor
BLEDescriptor NameDescriptor("2901", "Name");
BLEDescriptor ActivationDescriptor("2901", "Activation");
BLEDescriptor UnlockDescriptor("2901", "Unlock");
BLEDescriptor MACDescriptor("2901", "MAC Address");

bool BLE_activated = true;  //true if the bluetooth is activated
uint32_t tim_connec = 0;    // time in ms or we start to activate the bluetooth following a detection of movement

// ----------------SETUP FUNCTION--------------------------------

void ble_setup(void) {
  if (!BLE.begin()) {
    Serial.println("Starting Bluetooth® Low Energy module failed!");
    while (1) {
      // Set a reset in this case? Risk of card crash?
    }
  }
  
  // Set advertised local name and service UUID:
  BLE.setLocalName("SportShield Team 2");
  BLE.setDeviceName("SportShield Team 2");
  BLE.setAdvertisedService(PasswordService);
  
  // Add descriptors
  PasswordCharacteristic.addDescriptor(PasswordDescriptor);
  NameCharacteristic.addDescriptor(NameDescriptor);
  ActivationCharacteristic.addDescriptor(ActivationDescriptor);
  UnlockCharacteristic.addDescriptor(UnlockDescriptor);
  MACCharacteristic.addDescriptor(MACDescriptor);
  
  // Add the characteristic to the service
  PasswordService.addCharacteristic(PasswordCharacteristic);
  ConfigService.addCharacteristic(NameCharacteristic);
  ConfigService.addCharacteristic(ActivationCharacteristic);
  ConfigService.addCharacteristic(UnlockCharacteristic);
  ConfigService.addCharacteristic(MACCharacteristic);
  
  // Add service
  BLE.addService(PasswordService);
  BLE.addService(ConfigService);
  
  // Set the initial value for the characteristic:
  PasswordCharacteristic.writeValue(0);
  NameCharacteristic.writeValue("\n");
  ActivationCharacteristic.writeValue(false);
  UnlockCharacteristic.writeValue(false);
  MACCharacteristic.writeValue(BLE.address());
  
  // Set event handler
  BLE.setEventHandler(BLEConnected, onConnect);
  BLE.setEventHandler(BLEDisconnected, onDisconnect);
  PasswordCharacteristic.setEventHandler(BLEWritten, onWritePassword);
  NameCharacteristic.setEventHandler(BLEWritten, onWriteName);
  NameCharacteristic.setEventHandler(BLERead, onReadName);
  ActivationCharacteristic.setEventHandler(BLEWritten, onWriteActivation);
  ActivationCharacteristic.setEventHandler(BLERead, onReadActivation);
  UnlockCharacteristic.setEventHandler(BLEWritten, onWriteUnlock);
  
  // Start advertising
  BLE.advertise();
}

void onConnect(BLEDevice central) {
  Serial.print("Connected to ");
  Serial.println(central.address());
  Serial.println(BLE.address());
  digitalWrite(LEDB, LOW);
}

void onDisconnect(BLEDevice central) {
  Serial.print(F("Disconnected from central: "));
  Serial.println(central.address());
  isAuthenticated = false;
  digitalWrite(LEDB, HIGH);
}

void onWriteName(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    Config.Name = NameCharacteristic.value();
    String value = NameCharacteristic.value();
    Serial.print("Written name : ");
    Serial.println(value);
  } else {
    NameCharacteristic.writeValue("\n");
  }
}

void onReadName(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    NameCharacteristic.writeValue(Config.Name);
  } else {
    NameCharacteristic.writeValue("\n");
  }
}

void onWritePassword(BLEDevice central, BLECharacteristic characteristic) {
  const int expectedPassword = 13330; 
  uint32_t value = PasswordCharacteristic.value();
  isAuthenticate = (value == expectedPassword);
  Serial.println(isAuthenticated ? "Successful authentication" : "Wrong password");
}

void onWriteActivation(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    Config.isActivate = ActivationCharacteristic.value();
    if (Config.isActivate != 0) {
      Serial.println("Alarm enabled");
      digitalWrite(SIM800_DTR_PIN, LOW);  // Put in normal mode
      delay(100);
      sim800l->setPowerMode(NORMAL);  // Set normal functionality mode
    } else {
      Serial.println("Deactivation");
      sim800l->setPowerMode(MINIMUM);      // Set minimum functionality mode
      digitalWrite(SIM800_DTR_PIN, HIGH);  // Put in sleep mode
    }
  } else {
    ActivationCharacteristic.writeValue(Config.isActivate);
  }
}

void onReadActivation(BLEDevice central, BLECharacteristic characteristic) {
  ActivationCharacteristic.writeValue(Config.isActivate);
}

void onWriteUnlock(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticated) {
    // Activate electromagnet
    digitalWrite(aimantPin, HIGH);
    delay(2000);
    digitalWrite(aimantPin, LOW);
  }
}
