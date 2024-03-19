![CORIS Innovation Logo]()
# Technical Specifications Document

<details>
<summary>Table of contents</table><br>

- [Technical Specifications Document](#technical-specifications-document)
  - [1. Overview](#1-overview)
  - [2. Requirement](#2-requirement)
    - [2.1 Hardware Requirement](#21-hardware-requirement)
</details>

## 1. Overview

> ⚠️ The Sportshield project was commissioned by CORIS Innovation. All rights reserved to CORIS Innovation.

On 11 March 2024, a representative of CORIS Innovation France came to ALGOSUP to ask the students to maintain one of their projects: an anti-theft device for ski equipment.

The students were given an existing code by the company, as well as the hardware. The students therefore had to rework the code and implement the customer's requirements.

The languages used by the students will therefore be C++ for the most part, as well as a few implementations in C using the Arduino integrated development environment.

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