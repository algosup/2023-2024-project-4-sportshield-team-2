![CORIS Innovation Logo]()
# Technical Specifications Document

<details>
<summary>Table of contents</summary>

- [Technical Specifications Document](#technical-specifications-document)
  - [1. Overview](#1-overview)
    - [1.1 Project Folder Overview](#11-project-folder-overview)
  - [2. Requirement](#2-requirement)
    - [2.1 Hardware Requirement](#21-hardware-requirement)
    - [2.2 Client Requirement](#22-client-requirement)
      - [2.2.1 Actual Product](#221-actual-product)
      - [2.2.2 Futur Product](#222-futur-product)
    - [2.3 Existing products](#23-existing-products)
  - [3. Software Architecture](#3-software-architecture)
    - [3.1 System Overview](#31-system-overview)
    - [3.2 Data Flow Diagram](#32-data-flow-diagram)
    - [3.3 Module Descriptions](#33-module-descriptions)
    - [3.4 Communication Protocols](#34-communication-protocols)
    - [3.5 Technology Stack](#35-technology-stack)
    - [3.6 Security Architecture](#36-security-architecture)
  - [4. Detailed Functionality](#4-detailed-functionality)
    - [4.1 Device Information Transmission](#41-device-information-transmission)
    - [4.2 Efficient Alarm Management](#42-efficient-alarm-management)
    - [4.3 NFC Module Implementation](#43-nfc-module-implementation)
    - [4.4 Security Enhancements](#44-security-enhancements)
    - [4.5 Power Consumption Optimization](#45-power-consumption-optimization)
  - [5. Integration with External Systems](#5-integration-with-external-systems)
    - [5.1 SIM800L GSM/GPRS Module Integration](#51-sim800l-gsmgprs-module-integration)
    - [5.2 Server-Side API](#52-server-side-api)
    - [5.3 User Application Integration](#53-user-application-integration)
  - [6. Testing Strategies](#6-testing-strategies)
    - [6.1 Unit Testing](#61-unit-testing)
    - [6.2 Integration Testing](#62-integration-testing)
    - [6.3 Stress Testing](#63-stress-testing)
  - [7. Maintenance and Support](#7-maintenance-and-support)
    - [7.1 Firmware Updates](#71-firmware-updates)
    - [7.2 Troubleshooting Common Issues](#72-troubleshooting-common-issues)
  - [8. Compliance and Standards](#8-compliance-and-standards)
  - [9. Future Developments](#9-future-developments)
  - [Glossary](#glossary)
</details>

## 1. Overview

> ⚠️ The Sportshield project was commissioned by CORIS Innovation. All rights reserved to CORIS Innovation.

On 11 March 2024, a representative of CORIS Innovation France came to ALGOSUP to ask the students to maintain one of their projects: an anti-theft device for ski equipment.

The students were given an existing code by the company, as well as the hardware. The students therefore had to rework the code and implement the customer's requirements.

The languages used by the students will therefore be C++ for the most part, as well as a few implementations in C using the Arduino integrated development environment.

### 1.1 Project Folder Overview

```log
Sportshield-Project/
│
├── ConventionFileFolder/
│   └── convention.md
├── Documents/                     # Documentation and manuals
│   ├── Communication/
│       ├── 03_18_2024_meetingSummary.md
│       └── 03_18_2024_meetingSummary.pdf
│   ├── Functional/
│       ├── Img/
│           ├── ALGOSUP-logo.png
│           ├── ashley_ricks.png
│           ├── Coris-innovation-logo.png
│           ├── proto_scheme_bottom.png
│           ├── proto_scheme.png
│           ├── steve_sinclair.png
│           └── william_greener.png
│       └── functionalSpecifications.md
│   ├── Management/
│       └── WeeklyReports/
│           └── mainWeeklyReport.md
│           └── weeklyReportFirstWeek.md
│       └── managementDocuments.md
│       └── projectCharter.md
│   ├── Technical/
│       └── technicalSpecifications.md
│   ├── TestPlan__/
│       └── testPlan.md
│   └── UserManual__/
│       ├── userManual.md
│       ├── userManual.pdf
│       └── Img/
│           ├── BluetoothSettings.png
│           ├── BluetoothSettingsFunctionnalities.png
│           ├── BluetoothUnlock.png
│           ├── cableHolderAndExit.png
│           ├── chargingPort.png
│           ├── device.png
│           ├── deviceBottom.png
│           └── findBluetooth.jpg
```

## 2. Requirement
### 2.1 Hardware Requirement

The students have access to hardware, which is used as a prototype to test all the functions requested by the customer. The hardware consists of :

| Hardware Photo | Hardware Name | Technical Specifications |
|---|---|---|
| ![Xiao BLE Sense nrf52840 - Illustration]() | Xiao BLE Sense nrf52840 | 2 x 2 x 0,5 cm<br>BLE 5.0 & 6 DoF IMU<br>11 GPIO (UART, SPI, I2C)|
| ![GNSS PA1010D - Illustration]() | GNSS PA1010D | 2,5 x 2,5 x 1 cm<br>Integrated antenna<br>UART & I2C|
| ![GSM/2G SIM800L Module - Illustration]() | GSM/2G SIM800L Module | 2,2 x 1,8 x 0,5 cm<br>GPRS & HTTP, UART<br>SIM Card holder (With 1NCE SIM card)|
| ![Electromagnet - Illustration]() | Electromagnet | 12V, 500mA<br>2,7 x 1,6 x 1,3 cm |
| ![Piezoelectric Buzzer - Illustration]() | Piezoelectric buzzer | 12V, with oscillator control circuit<br>~ 90-100 dB|
| ![Lithium-Polymer Battery - Illustration]() | Lithium-Polymer battery | 5,1 x 3,5 x 0,6 cm<br>3.7V, 1100mAh, 4.1Wh |
| ![NFC Antenna - Illustration]() | NFC antenna | 5,5 x 4,5 x 0,017 cm<br>13,56MHz frequency |

Chacun des composants à donc une utilitée technique au sein du produit final, chaque utilitée est indiquée dans le tableau ci-dessous :
| Hardware Name | Technical Characteristics |
|---|---|
| Xiao BLE Sense nrf52840 | Based on the Nordic nRF52840 chip, it is equipped with an ARM Cortex-M4 processor with FPU, capable of operating at up to 64 MHz.<br><br>It features Bluetooth 5.0 and BLE with an integrated antenna, as well as NFC connectivity.<br><br>It is designed for ultra-low power consumption, with just 5 μA in deep sleep mode. It also includes lithium battery charge management.<br><br>As part of the project, the XIAO BLE Sense board will contain our software and communicate with all the components on the board. |
| GNSS PA1010D | Supports GPS, GLONASS, GALILEO and QZSS for global coverage and improved accuracy<br><br>With a sensitivity of -165 dBm, it can perform up to 10 position updates per second for high-speed, high-sensitivity tracking<br><br>Consumes only 30 mA during navigation<br><br>Within the project, the purpose of GNSS is to detect the smallest to the largest movements. |
| GSM/2G SIM800L Module | The module is designed for low power consumption, with a standby consumption of less than 2.0 mA.<br><br>Supports GPRS class 10 for data transfer rates of up to 85.6 kbps, and incorporates a TCP/IP stack for internet connection<br><br>Within the project, the purpose of the module is to manage notifications by HTTP Post request, or by messaging, the aim being to alert the user in the event of movement of his system. |
| Electromagnet | The electromagnet is used to unlock the safety lock by modifying the reception power, to a greater or lesser extent, for a fraction of a second.<br><br>With a power rating of 12V, avoid leaving it switched on for too long, as this could lead to system failure.<br><br>Within the project, the electromagnet's objective is to keep the safety lock, as well as to cut the magnetic force to unlock the safety lock. |
| Piezoelectric buzzer | With a power level ranging from 90 to 130 dB, the buzzer can make a noise of varying degrees of loudness.<br><br>The frequency is 3790Hz with a decibel peak at 130dB which could damage a human ear at long exposure.<br><br>The buzzer is designed to deter thieves from making off with the product. |
| Lithium-Polymer battery | The Lithium-Polymer battery has a discharge rate of around 1 to 2% per month without use.<br><br>Its low rate of discharge means that the system can run for more or less a long time without any significant loss of battery. That's what the project is all about, trying to keep this battery active for as long as possible. The data provided by the company indicates an activity time of 3 days at present. |
| NFC antenna |  The NFC antenna complies with the ISO/IEC 14443 standard, making it compatible with the vast majority of today's devices.<br><br>Within the project, this card will be used to unlock and activate the equipment security system. |

### 2.2 Client Requirement

#### 2.2.1 Actual Product

The current software is supposed to take account of hardware movement, thanks to the GNSS sensor located on the hardware. Depending on the intensity of the movement, the buzzer is supposed to make a noise of varying length and loudness.

Also, if a movement is deemed "powerful", then the buzzer is supposed to :
- Emit a long, powerful sound
- Send an HTTP Post request to an API (stored on a VPS) and send a notification from the user application indicating significant movement

The aim is not to alert the user to a small shock/movement. However, no motion data is pre-set. In other words, no calculation has been made to define whether a given shock deserves a short and weak alarm triggering, or conversely, a long and strong one.

Currently, the battery in working order lasts around 3 days (no precise calculation has been provided by the company, apart from test assumptions).

The electromagnet is supposed to work, so it should cut off the magnetic force if the user decides to unlock his anti-theft device.

The SIM cards are supposed to work with the 2G GSM module, so you can have a bit of data to send requests and text messages. The company is supplying the SIM cards with 500 MB of internet, as well as an availability of 250 messages.

The device for detecting an NFC card has not been implemented in the code, so it was not functional at the start of the project.

#### 2.2.2 Futur Product

The new software is supposed to work perfectly and meet the customer's expectations.

The software must therefore be able to deactivate Bluetooth if no movement has been detected in the last minute. The aim here is to disable Bluetooth quickly to avoid unnecessary battery consumption. Bluetooth is only reactivated after the device has moved.

Motion detection will also be more accurate, and there will be 3 types of alarm:
- The first type is two signals, of low intensity and short, over a period of 0.5 seconds of sound, 0.5 seconds of rest, to make it clear to anyone that a system is placed on a piece of equipment, to avoid moving the equipment.
- The second is 4 signals of medium intensity, short and at a fast rate, over a period of 1 second of sound, 0.5 seconds of rest, to give further warning if the system moves a little too much.
- The third is a high intensity noise, over a period of 5 seconds of sound, 1 second of rest and this for 1 full minute. The purpose of this is to make it clear that the product is being moved strongly and/or is being stolen.

In the event of the last type of movement, a notification is sent to the VPS API via an HTTP Post request containing the Mac Address of the anti-theft device, so that the owner can receive notification as quickly as possible that his product and/or has undergone a strong movement. Requests sent take 119 bits to send, so we can send a maximum of 33,613,445 requests, given that we have 500 MB available.

In terms of functionality, the NFC reader will work with cards with a frequency of 13.56 MHz. This will enable the user to unlock the device without having to use their phone, should the phone run out of battery.
The electromagnet will work, so when the final prototype is implemented, the device can be locked and unlocked completely. 

### 2.3 Existing products

Among the existing products, we can currently find on the market ski safety equipment called Loqski. This is a small padlock for protecting skis.

As far as its advantages are concerned, it remains a low-cost solution at £40 (tax included, delivery not included).  It allows you to secure your skis temporarily.

However, the disadvantages are that it doesn't alert the user if the equipment is stolen, or locate them if they move.
The skis are therefore temporarily protected, but not on a large scale, since a person can leave with them without any alarm system going off.

Just like the Decathlon Dreamscape anti-theft system. It's really not expensive, but it doesn't allow you to keep a close eye on your equipment. With a low price tag of just €12, it has a code of just 4 digits, so it's fairly easy to unlock if you put your mind to it.

There's plenty of other equipment for securing skis, but these don't provide any data, and there's no real anti-theft system as their name suggests. All they allow you to do is lock your skis, and most of these solutions are not very effective in terms of the resistance of the lock to attack. They are therefore inexpensive solutions, but they don't really provide the user with a secure product in the event of theft.

## 3. Software Architecture

### 3.1 System Overview
The Sportshield anti-theft system is engineered around a microcontroller-based architecture, specifically utilizing the Arduino platform. This choice is underpinned by several critical considerations tailored to meet the project's stringent requirements for reliability, ease of development, and real-time responsiveness.

**Choice of Arduino Platform**<br>
The Arduino platform, renowned for its simplicity and accessibility, offers an ideal environment for rapid prototyping and development of embedded systems. The Sportshield system leverages Arduino's extensive ecosystem, including its integrated development environment (IDE), libraries, and community support, to streamline the development process. This approach enables the team to focus on implementing robust anti-theft functionalities while ensuring system stability and reliability.

**Integration with Specified Hardware**<br>
The hardware components selected for the Sportshield project, including the Xiao BLE Sense nrf52840, GNSS PA1010D, GSM/2G SIM800L Module, Electromagnet, Piezoelectric Buzzer, Lithium-Polymer Battery, and NFC Antenna, are fully compatible with the Arduino environment. This compatibility allows for seamless integration and communication between the microcontroller and peripheral devices, crucial for detecting theft attempts, triggering alarms, and communicating with the user's mobile device.

**Real-time Responsiveness**<br>
Real-time operation is a core requirement for the Sportshield anti-theft system, where immediate detection of unauthorized movements and prompt responses (such as triggering alarms or sending notifications) are critical for its effectiveness. The Arduino platform's real-time capabilities, supported by the efficiency of C++ code, ensure that the system can process sensor inputs and execute defined actions with minimal latency.

**Ease of Development and Maintenance**<br>
Given the project's context within an academic setting at ALGOSUP, with students responsible for maintaining and enhancing the system, the Arduino platform's user-friendly nature facilitates ongoing development and troubleshooting. The extensive documentation, active forums, and availability of open-source libraries reduce the learning curve and support innovation.

**Conclusion**<br>
By basing the Sportshield system on the Arduino platform and coding in C++, the project strikes a balance between performance, development efficiency, and future scalability. This architecture ensures that the anti-theft device remains responsive, reliable, and adaptable to evolving requirements, all while providing a solid foundation for students to engage in hands-on learning and practical application of embedded system development.

### 3.2 Data Flow Diagram

```LOG
Coming soon...
```

### 3.3 Module Descriptions

**NRF52_MBED_TimerInterrupt** & **NRF52_MBED_ISR_Timer**<br>
<u>Purpose & Functionality</u>: These libraries are designed for the nRF52 series microcontrollers, enabling precise timer interrupts. They allow your system to execute specific code blocks at set intervals, independent of the main program loop, which is crucial for time-sensitive tasks like periodic sensor readings or status updates.

<u>Interactions</u>: These libraries can interact with any module that requires precise timing for its operations, such as periodic data sampling from the IMU or GPS modules, or scheduling regular check-ins via the GSM module.

**ArduinoBLE**<br>
<u>Purpose & Functionality</u>: The ArduinoBLE library is used for Bluetooth Low Energy communications on Arduino boards. In your system, it's likely used for establishing a BLE connection between the anti-theft device and the user's smartphone, enabling features such as device configuration, status monitoring, or alerts directly on the user's device.

<u>Interactions</u>: This library would primarily interact with the user interface module (e.g., a smartphone app) and could be involved in activating or deactivating the device's anti-theft features based on user input.

**LSM6DS3 & Wire**<br>
<u>Purpose & Functionality</u>: The LSM6DS3 library, used in conjunction with the Wire library for I2C communication, facilitates interaction with the LSM6DS3 IMU sensor. This sensor provides acceleration and gyroscope readings, which are essential for detecting movement of the ski equipment to trigger alarms or notifications.

<u>Interactions</u>: This module feeds data into the motion detection logic of your system, potentially interacting with the NRF52 timer libraries for periodic readings and the ArduinoBLE library to alert users of movement via BLE notifications.

**Adafruit_GPS**<br>
<u>Purpose & Functionality</u>: The Adafruit_GPS library is designed to interface with GPS modules, parsing the NMEA sentences to extract location data. In the context of your anti-theft device, it's used to obtain the precise location of the ski equipment, which is critical for tracking in the event of theft.

<u>Interactions</u>: Location data from this module could be used to provide location-based alerts or tracking information to the user through BLE communications or GSM messages.

**SIM800L**<br>
<u>Purpose & Functionality</u>: The SIM800L library is tailored for interfacing with the SIM800L GSM/GPRS module. This module enables your device to communicate over cellular networks, allowing it to send SMS alerts or HTTP requests to a server, notifying the user of potential theft incidents even when Bluetooth connectivity is not an option.

<u>Interactions</u>: This library likely interacts with both the GPS module (to send location data) and the system's central logic (to initiate communications based on detected movements or user commands).


### 3.4 Communication Protocols

This section of the Technical Specifications Document describes the communication protocols used by the Sportshield anti-theft system. These protocols enable the system to interact with external devices and services, such as CORIS Innovation's server, to send important data like battery level and GPS position.

**Bluetooth Low Energy (BLE)**<br>
The system utilizes Bluetooth Low Energy for wireless communication between the anti-theft device and the user's smartphone. Through BLE, the device can transmit its status, including activation state and battery level, and receive commands, such as unlocking requests or configuration changes. This communication is facilitated by the ArduinoBLE library, which manages the BLE service and characteristics for password management, device configuration, and state updates.

BLE Services and Characteristics: The system defines multiple custom BLE services and characteristics for different functionalities, including password entry, device name configuration, activation state, and unlock commands. BLE descriptors are used to provide human-readable descriptions of each characteristic's purpose.
Security Considerations: To ensure secure communication, the system implements an authentication process via a BLE characteristic, where a correct password must be written to gain access to certain functionalities like name change or activation toggle.

**Global Positioning System (GPS)**<br>
GPS data is collected using the Adafruit_GPS library, which parses NMEA sentences from the GPS module to obtain the current location of the ski equipment. This location data is crucial for tracking the equipment in case of theft.

Position Acquisition and Power Management: The system periodically wakes the GPS module to update the location data. Efficient power management is achieved by putting the GPS module into backup mode when not actively acquiring data, conservatively using battery resources.

**General Packet Radio Service (GPRS)**<br>
The SIM800L library enables GPRS communication via the SIM800L GSM module, allowing the system to send HTTP POST requests to the CORIS Innovation server. This capability is critical for remote monitoring, enabling the system to report significant events, such as detected movements, and regular updates on the device's GPS position and battery status.

HTTP Communication: The system constructs HTTP requests containing JSON-formatted data, including latitude, longitude, and battery level, sending this information to predefined server endpoints. This communication occurs over GPRS, ensuring the device can transmit data even without Bluetooth connectivity.
Network Configuration and Power Management: The SIM800L module is configured with the appropriate APN settings for network access. Similar to GPS, the module's power mode is managed to balance functionality and battery efficiency, transitioning to minimum functionality or sleep mode when not actively communicating.

**Motion Detection and Timer Management**<br>
Motion detection is facilitated by the IMU sensor, interfacing through the LSM6DS3 library. The system evaluates acceleration and rotation data to determine movement intensity. NRF52 timer libraries (NRF52_MBED_TimerInterrupt and NRF52_MBED_ISR_Timer) are employed for precise timing, enabling periodic checks and managing sensor polling intervals.

Dynamic Motion Analysis: Based on the detected motion data, the system categorizes movement intensity and decides on the appropriate response, from triggering local alarms to sending alerts and location data via GPRS.

### 3.5 Technology Stack
The Sportshield anti-theft system is developed using a combination of hardware-specific programming languages and a suite of libraries tailored to interface with various hardware components and external services. Below is a detailed overview of the technology stack:

**Programming Languages**<br>
C++: The primary programming language used for developing the system, taking advantage of its performance and efficiency in low-level hardware interaction. C++ is particularly suited for developing embedded systems like Sportshield, where direct control over hardware and system resources is critical.

**Development Frameworks and Platforms**<br>
Arduino: A key component of the development stack, the Arduino platform provides a comprehensive ecosystem for programming microcontrollers. It includes an Integrated Development Environment (IDE), which simplifies coding, compiling, and uploading code to the hardware. The Arduino framework is chosen for its accessibility, extensive support for various modules and sensors, and a large community contributing to a wide range of libraries.

**Libraries**<br>
NRF52_MBED_TimerInterrupt & NRF52_MBED_ISR_Timer: Used for managing high-precision timer interrupts on the NRF52840 chip, enabling the system to perform timed operations and sensor polling with accuracy.
ArduinoBLE: Facilitates Bluetooth Low Energy communications, allowing for secure and efficient wireless interaction between the device and users' smartphones.
LSM6DS3: A library for interfacing with the LSM6DS3 IMU sensor, providing capabilities to measure acceleration and rotation, crucial for detecting movements of the ski equipment.
Adafruit_GPS: Enables parsing of NMEA sentences from the GPS module, allowing the system to acquire and process location data for tracking purposes.
SIM800L: Supports GSM/GPRS communication via the SIM800L module, used for sending alerts and data to a remote server over cellular networks.

**Third-party Services**<br>
CORIS Innovation Server: An external server setup to receive HTTP POST requests from the system. This server is responsible for processing incoming data, such as GPS location and battery status, and triggering appropriate responses or notifications to the user.

**Hardware**<br>
The system is built on a variety of hardware components, each interfaced and controlled via specific libraries. These include the Xiao BLE Sense NRF52840 for the microcontroller, GNSS PA1010D for GPS positioning, GSM/2G SIM800L Module for cellular communication, and various sensors and actuators for detecting movement and managing device security features.

### 3.6 Security Architecture
The Sportshield anti-theft system incorporates several layers of security to protect against unauthorized access and ensure the privacy and safety of user data. These measures are critical, given the system's reliance on wireless communication and its role in safeguarding valuable equipment.

**Authentication Mechanisms**<br>
BLE Communication: The system uses Bluetooth Low Energy (BLE) for local communication with the user's smartphone. To secure this channel, an authentication mechanism is implemented where a predefined password must be correctly provided before allowing any configuration changes through the BLE interface. This prevents unauthorized users from manipulating the device's settings or disabling its security features.
SIM800L Module: For cellular communication, the SIM800L module requires authentication with the cellular network via a SIM card. This ensures that data transmissions over GPRS are associated with a registered account, adding a layer of accountability and security.

**Encryption**<br>
Data Transmission: While the system sends data to the CORIS Innovation server, including GPS coordinates and battery levels, employing encryption in this layer is crucial. If not natively supported by the SIM800L library, implementing HTTPS for data transmission or encrypting the payload before sending it over HTTP ensures that sensitive information (e.g., location data) is protected against interception during transmission.
BLE Encryption: The BLE protocol inherently includes options for encrypting data communication between devices. By enabling encryption at the BLE level, the system ensures that all information exchanged between the anti-theft device and the user's smartphone is secure from eavesdropping.

**Secure Data Storage**<br>
On-Device Data Storage: The system minimizes the amount of sensitive data stored on the device itself. Configuration settings, including the user-defined password and device identifiers, are stored in the device's non-volatile memory. Ensuring this data is stored securely involves encrypting the data at rest or using secure storage mechanisms provided by the microcontroller, if available.

**Physical Security**<br>
Tamper Detection: Considering the physical security of the device is also essential. While not directly related to software architecture, incorporating sensors to detect tampering attempts and triggering alerts or disabling the device can protect against physical attacks aiming to bypass the system's security features.

**Future Considerations**<br>
Security Updates: The ability to update the device's firmware over the air (OTA) can be a double-edged sword; it allows for the timely patching of security vulnerabilities but introduces potential risks if the update mechanism is not secured. Implementing a secure bootloader and verifying firmware signatures before applying updates can mitigate these risks.
Regular Security Audits: Continuous testing and auditing of the system's security measures are necessary to identify and rectify potential vulnerabilities, ensuring the system remains robust against evolving threats.

## 4. Detailed Functionality

The Sportshield project, requested by Coris Innovation, focuses on optimizing battery consumption, integrating NFC technology, enhancing security, and improving user experience. This section outlines the technical implementations of the specified functional requirements.

### 4.1 Device Information Transmission

Objective: **Transmit essential device information to the CORIS Innovation server API, including battery level, GPS position, and movement detection data.**

<u>Implementation:</u><br>
Battery Level: Implement a function to read the battery voltage through an ADC (Analog to Digital Converter) channel. The reading is then converted into percentage format and transmitted.
GPS Position: Utilize the Adafruit_GPS library to acquire latitude and longitude. Data is captured in NMEA format, parsed, and formatted before transmission.<br>
Movement Detection: Employ the LSM6DS3 library for IMU sensor data to detect motion and orientation changes. Algorithm thresholds differentiate between minor and significant movements.

### 4.2 Efficient Alarm Management

Objective: **Enhance alarm functionalities to respond appropriately to detected movements and allow user intervention to stop the alarm.**

<u>Implementation:</u><br>
Alarm Activation: Define thresholds for light and strong shocks using accelerometer and gyroscope data. Light shocks trigger a sequence of three short, light sounds, while strong shocks initiate five long, high-intensity sounds.<br>
User Control: Implement a BLE characteristic within the ArduinoBLE library to receive stop commands from the user's mobile app, immediately ceasing the alarm regardless of its cycle.

### 4.3 NFC Module Implementation

Objective: **Integrate an NFC module to provide an alternative device locking and unlocking mechanism, enhancing user convenience and accessibility.**

<u>Implementation:</u><br>
NFC Reader Integration: Incorporate an NFC library compatible with the chosen NFC hardware module. Program the NFC reader to recognize authorized tags or devices for locking and unlocking actions.<br>
User Interaction: Set up an event-driven mechanism that reacts to NFC tag detection. Execute lock/unlock commands based on the tag's credentials and update the device's state accordingly.

### 4.4 Security Enhancements

Objective: **Increase the system's security to prevent unauthorized access and ensure user data confidentiality.**

<u>Implementation:</u><br>
Authentication: Strengthen the existing BLE password mechanism by incorporating a more robust authentication process, possibly using encrypted tokens or challenge-response methods.<br>
Data Transmission Security: Ensure all communications with the server are encrypted using SSL/TLS protocols. Evaluate and integrate HTTPS capabilities in the SIM800L module for secure data transmission.

### 4.5 Power Consumption Optimization

Objective: **Extend the battery life from 3 days to 7 days or more through efficient power management.**

<u>Implementation:</u><br>
Sleep Mode Activation: Develop a power management scheme that puts the GPS, GSM, and IMU sensors into low-power mode when not actively in use. Utilize the deep sleep modes of the microcontroller for minimal power draw during inactivity periods.<br>
Dynamic Sensor Management: Implement algorithms to dynamically adjust the frequency of sensor data collection based on the device's state, reducing unnecessary power consumption without compromising functionality.

## 5. Integration with External Systems

The Sportshield anti-theft device is designed to communicate securely and efficiently with external systems to provide real-time updates and notifications to users. This communication is primarily facilitated through the SIM800L GSM/GPRS module, enabling the device to send data over cellular networks to a designated API endpoint. This section outlines the mechanisms and protocols governing these interactions.

### 5.1 SIM800L GSM/GPRS Module Integration

Objective: **Enable the Sportshield device to transmit critical data, including GPS location, battery status, and alarm events, to the CORIS Innovation server, ensuring users receive timely updates via the application.**

<u>Implementation:</u><br>
GSM/GPRS Communication: Utilize the SIM800L library for establishing cellular network connectivity. Configure the module with appropriate APN settings for network access and initiate GPRS sessions for data transmission.<br>
HTTP POST Requests: Craft HTTP POST requests containing JSON-formatted data payloads. These requests are sent to a predefined API endpoint managed by CORIS Innovation, conveying information like device ID, GPS coordinates, and battery level.<br>
Data Formatting: Structure data payloads as JSON objects for compatibility with the server-side API, facilitating easy parsing and processing by the backend system.

### 5.2 Server-Side API

Objective: **Process incoming data from the Sportshield device, updating the system's state and pushing relevant notifications to the user's application in real time.**

<u>Implementation:</u><br>
API Endpoint Configuration: Set up secure RESTful API endpoints to receive and process HTTP POST requests from the Sportshield device. Implement authentication and validation mechanisms to ensure data integrity and security.<br>
Real-Time Data Processing: Upon receiving data, the server parses the JSON payload, updates the device's status in the database, and determines whether to trigger notifications based on the reported state (e.g., movement alerts, battery low warnings).<br>
User Notification System: Integrate with push notification services to relay important alerts to the user's application, ensuring they are promptly informed of any significant events concerning their equipment.

### 5.3 User Application Integration

Objective: **Present real-time data and notifications received from the server in a user-friendly interface, allowing users to monitor their equipment's status and control the Sportshield device remotely.**

<u>Implementation:</u><br>
Data Synchronization: Implement mechanisms within the application to regularly poll the server for updates or utilize web sockets for real-time data streaming, ensuring the application reflects the current state of the user's equipment.<br>
Interactive Notifications: Design the application to display alerts and notifications in an actionable format, enabling users to respond to events (e.g., disabling an alarm) directly within the app.<br>
Remote Device Management: Provide features within the app for users to remotely configure the Sportshield device settings, such as changing the sensitivity of movement detection or updating the NFC access list.


## 6. Testing Strategies

The testing strategy for the Sportshield anti-theft system is meticulously designed to ensure the application's reliability, functionality, security, and user experience. It encompasses several types of tests, each targeting specific aspects of the system, from basic hardware functionality to complex software interactions and real-world usability.

### 6.1 Unit Testing

Objective: **To validate the functionality of individual methods and functions within the software, ensuring they perform as expected in isolation.**

<u>Implementation:</u><br>
Follow the test conventions outlined, explicitly stating the purpose of each test, separating actions (Arrange, Act, Assert), naming variables clearly, and avoiding logic within tests.<br>
Utilize the Arduino IDE and C++ language for creating test cases that assess the behavior of small units of code.<br>
Focus on critical functions such as battery level calculation, GPS data parsing, NFC interactions, and alarm management logic.<br>
Execute each test case three times to ensure consistency and reliability of results.

### 6.2 Integration Testing

Objective: **To test the interactions between integrated modules or services, verifying that the system operates cohesively.**

<u>Implementation:</u><br>
Test the integration of the hardware components (e.g., GSM module, GPS sensor, NFC reader) with the software to ensure accurate data transmission and processing.<br>
Verify the system's ability to send device information to the API and manage real-time events like alarm notifications and position updates effectively.<bR>
Use the described testing environment and tools, including Arduino IDE and external libraries, to simulate real-world operating conditions.<br>
Assess the system's response to simulated user interactions, such as locking/unlocking via NFC and app commands.

### 6.3 Stress Testing

Objective: **To evaluate the system's performance under extreme conditions, ensuring it remains functional and responsive during high load or unusual scenarios.**

<u>Implementation:</u><br>
Simulate scenarios with rapid consecutive GPS updates, frequent locking/unlocking actions, and continuous alarm triggers to test the system's resilience.<br>
Monitor battery consumption rates under heavy usage to validate improvements in power management and ensure the battery life meets the project goal.<br>
Utilize ancillary equipment like Breadboards and LEDs to mimic component behavior and verify the system's ability to handle multiple events in real-time.<br>
Document the system's performance, noting any failures or significant performance degradation, to identify areas for optimization.


## 7. Maintenance and Support

The ongoing maintenance and support for the Sportshield anti-theft system are critical components to ensure user satisfaction and system reliability post-deployment. This section addresses the framework for delivering firmware updates, troubleshooting common system issues, and providing robust customer support.

### 7.1 Firmware Updates

Objective: **To continuously improve and update the Sportshield system, addressing bugs, enhancing features, and ensuring compatibility with evolving technology standards.**

<u>Implementation:</u><br>
Over-the-Air (OTA) Updates: Implement OTA firmware update capability, allowing users to easily upgrade their device's software without needing physical access. This includes secure authentication and verification processes to prevent unauthorized firmware modifications.<br>
Version Control: Maintain a versioning system for firmware releases, documenting changes, improvements, and fixes in each version. This helps users understand the benefits of updating their device and ensures backward compatibility.<br>
User Notification: Proactively inform users of available updates through the application, highlighting new features or critical fixes to encourage timely updates.<br>

### 7.2 Troubleshooting Common Issues

<u>Alarm Management and Notifications Issues:</u><br>
Symptom: The alarm cannot be stopped once initiated; the user must wait for the sound to finish. Concurrently sending notifications and triggering the buzzer is problematic, requiring a delay before or after the alarm sound.

Resolution Steps:
- Firmware Optimization: Refactor the alarm management logic to allow interruptible alarm sequences, enabling users to stop the alarm through the application at any time.
- Concurrent Processing: Enhance the system's multitasking capabilities to manage simultaneous actions (e.g., sending notifications while the alarm is sounding) without delays or conflicts.
- User Feedback Collection: Implement a feedback mechanism within the app to gather user experiences and issues encountered, guiding future troubleshooting and system improvements.


## 8. Compliance and Standards

## 9. Future Developments

## Glossary