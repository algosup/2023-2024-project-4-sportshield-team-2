# Sportshield Project Test Plan

---

<details>
<summary>Table of Contents</summary>

- [Sportshield Project Test Plan](#sportshield-project-test-plan)
  - [I. Introduction](#i-introduction)
      - [A. Overview](#a-overview)
      - [B. Requirements](#b-requirements)
      - [C. Roles and Responsabilities](#c-roles-and-responsabilities)
  - [II. Ressources Requirements](#ii-ressources-requirements)
      - [A. Testing Environment](#a-testing-environment)
      - [B. Testing Tool Requirements](#b-testing-tool-requirements)
      - [C. Additional Ressource Requirements](#c-additional-ressource-requirements)
  - [III. Strategy](#iii-strategy)
      - [A. Test Strategy](#a-test-strategy)
      - [B. Testing Type](#b-testing-type)
  - [IV. Installation Qualification](#iv-installation-qualification)
  - [V. Test Documentation](#v-test-documentation)
  - [Glossary](#glossary)

</details>

[Readme](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/blob/main/README.md)

---

## I. Introduction

#### A. Overview

<span style="color:red">to be defined</span>

#### B. Requirements

<span style="color:red">to be defined</span>

#### C. Roles and Responsabilities

| Name | Role | Responsability | GitHub |
|---|---|---|---|
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06MT3ZEBP1-g8dddf3c594e-64"> DEBRY Robin | Project Manager |  | [GitHub](https://github.com/robin-debry) |
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06NA4GBKTN-g7986289d5c2-64"> GAGNEPAIN Mathias | Program Manager |  | [GitHub](https://github.com/MathiasGagnepain) |
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06NWDSQ38Q-gd0f64565afd-64"> DELILLE Elone | Technical Leader |  | [GitHub](https://github.com/HiNett) |
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06N7LH3KB4-g20f42d2a13d-64"> GUILLOUCHE Enzo | Technical Writer |  | [GitHub](https://github.com/EnzoGuillouche) |
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06N7H57DA7-g10c7c642461-64"> DESCAMPS Raphaël | Software Engineer |  | [GitHub](https://github.com/Raphaeldcp) |
| <img src="https://ca.slack-edge.com/T06NA42V4FN-U06N11QLUDU-g83dc41ed93a-64"> PAGNOUX Grégory | Quality Assurance |  | [GitHub](https://github.com/Gregory-Pagnoux) |

## II. Ressources Requirements

#### A. Testing Environment

Operating system : MacOS, Windows, Arduino
language : C, Arduino
Integrated Development Environment : VisualStudioCode
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

#### A. Test Strategy

<span style="color:red">to be defined</span>

#### B. Testing Type

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

## IV. Installation Qualification

<span style="color:red">to be defined</span>

## V. Test Documentation

<span style="color:red">to be defined</span>

**Criterias**

<span style="color:red">to be defined</span>

**Testing Schedule**

| ID | Function | Developer | Description | Deadline | Completion date |
| - | - | - | - | - | - |
| 01 |  |  |  | XX/0X/2024 | XX/0X/2024 |
| 02 |  |  |  | XX/0X/2024 | XX/0X/2024 |
| 03 |  |  |  | XX/0X/2024 | XX/0X/2024 |
| 04 |  |  |  | XX/0X/2024 | XX/0X/2024 |
| 05 |  |  |  | XX/0X/2024 | XX/0X/2024 |

**Test convention**

<span style="color:red">to be defined</span>

[Test case](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/issues) is done on GitHub issues category.

## Glossary

<span style="color:red">to be defined</span>

*source : [link]()*
