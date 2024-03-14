# Sportshield - Test Plan

---

<details>
<summary>Table of Contents</summary>

- [Sportshield - Test Plan](#sportshield---test-plan)
  - [I. Introduction](#i-introduction)
      - [A. Overview](#a-overview)
      - [B. Requirements](#b-requirements)
  - [II. Ressources Requirements](#ii-ressources-requirements)
      - [A. Testing Environment](#a-testing-environment)
      - [B. Testing Tool Requirements](#b-testing-tool-requirements)
      - [C. Additional Ressource Requirements](#c-additional-ressource-requirements)
  - [III. Strategy](#iii-strategy)
      - [A. Testing Type](#a-testing-type)
      - [B. Test Strategy](#b-test-strategy)
  - [IV. Installation Qualification](#iv-installation-qualification)
  - [V. Test Documentation](#v-test-documentation)
  - [Glossary](#glossary)

</details>

[Readme](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/blob/main/README.md)

---

## I. Introduction

#### A. Overview

The project was commissioned by [CORIS Innovation](https://www.corisinnovation.com)[^1] from [ALGOSUP](https://algosup.com/en.html) students, and involved software maintenance.
The software is an application for securing sports equipment, which is implemented on hardware supplied by the company.

The goal of the project is to optimize the consumption to make it last longer, from 3 days to 7 days or more, adding NFC[^2] component, improve the security and the user experience based on the existing prototype.

#### B. Requirements

By following the requests of the client company, the students will focus on the following points of the project :
- Send device information to the API[^3]
  - Battery level
  - Position (latitude, longitude)
  - Movement (rotation, new position)
- Efficient Alarm management
  - 3 light sounds when a light shock is detected
  - 5 long high sounds when a strong shock is detected
  - Give possibility for user to make the alarm stop ringing whenever he wants
- Manage the battery : it lasts as long as possible without recharging
- Manage security issues : resolve as many basic errors as possible to prevent the end user from having access to the software
- Have an NFC : be able to activate/deactivate the locking mechanism without using the phone
- Manage multiple events in real time
- Send notification to the phone

All the code must be written in the Arduino's[^4] language (a variant of the C++[^5] programming language), following the existing code convention. No libraries except the ones that have already been given are allowed.

## II. Ressources Requirements

#### A. Testing Environment

Operating system : MacOS, Windows
language : C++, Arduino
IDE[^6] : [VisualStudioCode](https://code.visualstudio.com/download), [Arduino IDE](https://www.arduino.cc/en/software)
Libraries :
- [NRF52_MBED_TimerInterrupt](https://github.com/khoih-prog/NRF52_MBED_TimerInterrupt) V1.4.1
- [ArduinoBLE](https://www.arduino.cc/reference/en/libraries/arduinoble/) V1.3.6
- [Adafruit GPS Library](https://www.arduino.cc/reference/en/libraries/adafruit-gps-library/) V1.7.4 (install all)
- [Sim800L http connector](https://www.arduino.cc/reference/en/libraries/sim800l-http-connector/) V1.14.0
- [Seeed Arduino LSM6DS3](https://www.arduino.cc/reference/en/libraries/seeed-arduino-lsm6ds3/) V2.0.3
- [OneWire](https://github.com/PaulStoffregen/OneWire) V2.3.7

#### B. Testing Tool Requirements

<span style="color:red">to be defined</span>

#### C. Additional Ressource Requirements

<span style="color:red">to be defined</span>

## III. Strategy

#### A. Testing Type

**Unit tests**

Unit tests are very low level and close to the source of an application. They consist in testing individual methods and functions of the classes, components, or modules used by your software. Unit tests are generally quite cheap to automate and can run very quickly by a continuous integration server.

**Integration tests**

Integration tests verify that different modules or services used by your application work well together. For example, it can be testing the interaction with the database or making sure that microservices work together as expected. These types of tests are more expensive to run as they require multiple parts of the application to be up and running.

**Functional tests**

Functional tests focus on the business requirements of an application. They only verify the output of an action and do not check the intermediate states of the system when performing that action.

**End-to-end tests**

End-to-end testing replicates a user behavior with the software in a complete application environment. It verifies that various user flows work as expected.

**Smoke tests**

Smoke tests are basic tests that check the basic functionality of an application. They are meant to be quick to execute, and their goal is to give you the assurance that the major features of your system are working as expected.

*source : [Atlsassian - types of software testing](https://www.atlassian.com/continuous-delivery/software-testing/types-of-software-testing)*

#### B. Test Strategy

**battery management tests**

Test 1 :
For 5 minutes with the same position, the battery give the minimum of powerful to the bluetooth, in an ambient environment.
- modify code to wait 5 secondes
- wait 5 secondes
- see the message send

Test 2 :
For 5 minutes with the same position, the battery give the minimum of powerful to the bluetooth, in a cold environment.
- modify code to wait 5 secondes
- put in the freezer
- wait 5 secondes
- see the message send

Test 3 :
The lifespan of the battery is 7 days with 6 hours of operation and 18h in stand-by, in an ambient environment.
- write program to power on and power off at good time
- unplug the the device
- wait

Test 4 :
The lifespan of the battery is 7 days with 6 hours of operation and 18h of sleep mode, in a cold environment.
- write program to power on and power off at good time
- unplug the the device
- put in the freezer
- wait

Test 5 :
The battery reaches 20% level and turn off.
- ...

Test 6 :
The battery reaches 80% level and stops charging.
- ...

**Security issue**

<span style="color:red">to be defined</span>
allowed to all users by default |-> increase access to alarm

**Lock / unlock**

<span style="color:red">to be defined</span>

**NFC**

<span style="color:red">to be defined</span>

**Alarm management**

<span style="color:red">to be defined</span>
3 light sounds -> little movement / 5 long high sounds -> big movement, shock

**Shock notification**

<span style="color:red">to be defined</span>

**GNSS position acquisition**

<span style="color:red">to be defined</span>

**Activate / desactivate by app**

<span style="color:red">to be defined</span>

## IV. Installation Qualification

<span style="color:red">to be defined</span>

## V. Test Documentation

<span style="color:red">to be defined</span>

| ID | Document | Writer | Reviewers | Deadline | Completion date |
| - | - | - | - | - | - |
| a | Project Charter | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance), Mathias GAGNEPAIN (Program Manager), Elone DELILLE (Technical Leader), Enzo GUILLOUCHE (Technical Writer)  | 14/03/2024 | 14/03/2024 |
| b | Functional Specifications | Mathias GAGNEPAIN (Program Manager) | Grégory PAGNOUX (Quality Assurance), Enzo GUILLOUCHE (Technical Writer), Robin DEBRY (Project Manager) | 18/03/2024 | XX/0X/2024 |
| c | Technical Specifications | Elone DELILLE (Technical Leader) | Grégory PAGNOUX (Quality Assurance), | 26/03/2024 | XX/0X/2024 |
| d | User Manual | Enzo GUILLOUCHE (Technical Writer) | Grégory PAGNOUX (Quality Assurance), | 10/04/2024 | XX/0X/2024 |

**Test convention**

<span style="color:red">to be defined</span>

**Criterias**

| ID | Function | Developer | Description criteria |
| - | - | - | - |
| 01 |  |  |  |
| 02 |  |  |  |
| 03 |  |  |  |
| 04 |  |  |  |
| 05 |  |  |  |

**Testing Schedule**

| ID | Deadline | Completion date | Result |
| - | - | - | - |
| 01 | XX/0X/2024 | XX/0X/2024 | None |
| 02 | XX/0X/2024 | XX/0X/2024 | None |
| 03 | XX/0X/2024 | XX/0X/2024 | None |
| 04 | XX/0X/2024 | XX/0X/2024 | None |
| 05 | XX/0X/2024 | XX/0X/2024 | None |

[Test case](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/issues) is done on GitHub issues category.

## Glossary

[^1]: CORIS Innovation
The company's main activities are engineering and engineering consultancy, recruitment and headhunting, business management consultancy and strategic operations. The head office is not far from Lyon and has been in existence since 2015 thanks to Thibault Peltier and Stéphane Maite.
*source : [CORIS Innonvation](https://www.corisinnovation.com)*

[^2]: NFC
...
*source : []()*

[^3]: API
...
*source : []()*

[^4]: Arduino
...
*source : []()*

[^5]: C++
...
*source : []()*

[^6]: IDE
...
*source : []()*
