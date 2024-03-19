<p align="center">
    <img src="https://assets-global.website-files.com/656097f111c9c42578f4fa01/65648d5d98f6814022b9474a_6e5ca96fcf317623caec20ca96892327.png">
</p>

# <div style="text-align: right; text-align: down"> User manual </div>
# <div style="text-align: right; text-align: down"> Version 0.5 </div>

<div style="page-break-after: always;"></div>

<details open>
<summary>Table of Contents</summary>

- [ User manual ](#-user-manual-)
- [ Version 0.5 ](#-version-05-)
- [Get Started](#get-started)
  - [What's in the box](#whats-in-the-box)
  - [Charge your SportShield](#charge-your-sportshield)
  - [Set up SportShield](#set-up-sportshield)
- [How to lock SportShield](#how-to-lock-sportshield)
- [How to unlock SportShield](#how-to-unlock-sportshield)
- [Alarm](#alarm)
- [App](#app)
- [Notifications](#notifications)
- [General Info and Specifications](#general-info-and-specifications)
  - [Components](#components)
  - [Robustness Assurance](#robustness-assurance)
    - [Anti-theft Cable](#anti-theft-cable)
  - [Environmental conditions](#environmental-conditions)
  - [Security](#security)
</details>

<br>

<div style="page-break-after: always;"></div>

# Get Started

SportShield is an innovative anti-theft device designed for sports equipment, equipped with sensors and actuators to detect movement, activate an alarm, and notify the owner.
<br><br>
**SportShield is still in development. This prototype doesn't include yet all the features that we are planning to implement.**


## What's in the box

Your SportShield includes:

- An anti-theft SportShield device<br>
<img src="./Img/device.png" width="225"/>
<img src="./Img/deviceBottom.png" width="200"/>
- This user manual

## Charge your SportShield

If the SportShield device runs ou of battery, it won't work anymore until it gets charged.<br>
A fully-charged SportShield can last over 6 days.

To charge SportShield:

1. Plug the charger into the USB port on the SportShield.<br>
<img src="./Img/chargingPort.png" width="200"/>
2. Plug the other end of the charger into an outlet.

<br>

The SportShield is now charging. Try to not use SportShield during its charging.

<div style="page-break-after: always;"></div>

## Set up SportShield

To fully use the SportShield device, you'd need to set up a few things with your smartphone. <br>
You can either set up by Bluetooth, with a NFC card or with the SportShield app. <br><br>
By Bluetooth:

- Enable your Bluetooth connection on your phone.
- You should find a device named "SportShield".<br>
<img src="./Img/findBluetooth.jpg" width="200"/>
- Connect your smartphone with the device. <br>
<img src="./Img/BluetoothSettings.png" width="200"/>
<br><br>
  
With a NFC card:

- Make contact between the NFC device and the SportShield.

Regarding the SportShield app, see the [dedicated manual part](#app).

<br>

The SportShield is now set up, you can use it whenever and wherever you want.

<div style="page-break-after: always;"></div>

# How to lock SportShield 

The SportShield prevents your sports belongings from thieves. Its installation deals with a few steps:

1. Wind the cable from the cable exit of the SportShield device.
2. Surround your belongings with the cable.
3. Attach the cable to the cable holder.<br>
<img src="./Img/cableHolderAndExit.png" width="200"/>

If SportShield is not connected to your smartphone or with a NFC card, refer to the [set up part](#set-up-sportshield).<br><br>
The SportShield is now locked and you won't be able to pull the cable anymore, if you don't unlock it. <br><br>
You'll receive a notification if the SportShield detects a shock. <br>
For more information about notifications, refer to the [dedicated manual part](#notifications).

<div style="page-break-after: always;"></div>

# How to unlock SportShield

SportShield's uninstallation is quite simple. You can unlock it either by Bluetooth or with the app. <br>
By Bluetooth:

1. Go to your Bluetooth settings.<br>
<img src="./Img/BluetoothSettingsFunctionnalities.png" width="200"/>
2. Click on the "Unlock" button to unlock SportShield.<br>
<img src="./Img/BluetoothUnlock.png" width="200"/>

With a NFC card:

- Make contact between the NFC device and the SportShield.

Regarding the SportShield app, see the [dedicated manual part](#app).

<br>
The SportShield is now unlocked. The alarm won't ring and you can take your device back.

<br>

<div style="page-break-after: always;"></div>

# Alarm

When the SportShield is locked, each detected shock will ring an alarm. <br>The alarm intensity depends on the shock intensity: <br>

- 3 light sounds when a light shock is detected.
  
- 5 long high sounds when a strong shock is detected.
<br><br>

Moreover, you can stop the alarm whenever you want. To do so, you can use either the Bluetooth or the app. <br>

By Bluetooth: these are the same steps as [to unlock SportShield](#how-to-unlock-sportshield).

With the NFC card, these are the same steps as [to unlock SportShield](#how-to-unlock-sportshield).

Regarding the SportShield app, see the [dedicated manual part](#app).

When the alarm rings, a notification is sent to the linked smartphone.<br>
For more information about notifications, refer to the [dedicated manual part](#notifications).
<br>

# App

The SportShield app would be available either on the Apple App Store and the Google Play Store.<br>
Even though, the app has not been synchronized with the SportShield device yet. In this user manual, you won't be able to find any useful information about this application for the moment.

# Notifications

Since no application has been synchronized with the SportShield device, the implemented simulation reproduces perfectly how it would work. <br><br>

When the alarm rings, a notification is sent to the linked smartphone.

The notifications contain some information about the device, such as the GPS coordinates (longitude latitude) and the remaining battery percentage.<br>

<!-- add a notification image -->

<div style="page-break-after: always;"></div>

# General Info and Specifications

## Components

Here's a list of the components a SportShield device contains:

- Xiao BLE Sense nrf52840
- GNSS PA1010D
- GSM/2G SIM800L Module
- Electromagnet
- Piezoelectric Buzzer
- Lithium-Polymer Battery
- NFC Antenna

## Robustness Assurance

Since the SportShield is an anti-theft device, it has to be resistant enough, meeting some resistance criteria.
<!-- Waterproofness, cold-resistance, and robustness against break-in attempts. -->

### Anti-theft Cable

**The cable in itself has some adjustments to meet the resistance criteria.** <br>
For physical security, a multi-layered cable and electromagnetic lock have been implemented.<br>
Moreover, the cable automatically retracts into the housing and prevents unwinding when locked.

## Environmental conditions

<!-- 3 days autonomy in ambient environment (60% more consumption in cold environment) -->

## Security

SportShield prioritizes the fundamental principles that are Confidentiality, Integrity, and Availability.

By meticulously categorizing data based on its potential impact if compromised, SportShield enforces stringent measures to thwart unauthorized access attempts, ensuring that confidential data remains secure and inaccessible to unauthorized entities.

By fortifying data against unauthorized alterations, such as when a thief would want to corrupt your SportShield device, SportShield guarantees the integrity of critical information.

<div style="page-break-after: always;"></div>

©2015-2024 Coris Innovation. All rights reserved. Coris Innovation and the Coris Innovation logo are trademarks or registered trademarks of Coris Innovation.
