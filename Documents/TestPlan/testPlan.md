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
  - [III. Strategy](#iii-strategy)
      - [A. Testing Type](#a-testing-type)
      - [B. Test Strategy](#b-test-strategy)
  - [IV. Installation Qualification](#iv-installation-qualification)
  - [V. Documentation test](#v-documentation-test)
  - [VI. Code test](#vi-code-test)
  - [Glossary](#glossary)

</details>

[Readme](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/blob/main/README.md)

---

## I. Introduction

#### A. Overview

The project was commissioned by [CORIS Innovation](https://www.corisinnovation.com)[^1] from [ALGOSUP](https://algosup.com/en.html) students, and involved software maintenance.
The software is an application for securing sports equipment, which is implemented on hardware supplied by the company.

The goal of the project is to optimize the consumption to make it last longer, from 3 days to 7 days or more, add an NFC[^2] component, and improve the security and the user experience based on the existing prototype.

#### B. Requirements

By following the requests of the client company, the students will focus on the following points of the project:
- Send device information to the API[^3]
  - Battery level
  - Position (latitude, longitude)
  - Movement (rotation, new position)
- Efficient Alarm management
  - 3 light sounds when a light shock is detected
  - 5 long high sounds when a strong shock is detected
  - Give the possibility for the user to make the alarm stop ringing whenever he wants
- Manage the battery: it lasts as long as possible without recharging
- Manage security issues: resolve as many basic errors as possible to prevent the end user from having access to the software
- Have an NFC: be able to activate/deactivate the locking mechanism without using the phone
- Manage multiple events in real-time
- Send notification to the phone

All the code must be written in Arduino's[^4] language (a variant of the C++[^5] programming language), following the existing code convention. No libraries except the ones that have already been given are allowed.

## II. Ressources Requirements

#### A. Testing Environment

Operating system: MacOS, Windows
language: C++, Arduino
IDE[^6]: [VisualStudioCode](https://code.visualstudio.com/download), [Arduino IDE](https://www.arduino.cc/en/software)
Libraries:
- [NRF52_MBED_TimerInterrupt](https://github.com/khoih-prog/NRF52_MBED_TimerInterrupt) V1.4.1
- [ArduinoBLE](https://www.arduino.cc/reference/en/libraries/arduinoble/) V1.3.6
- [Adafruit GPS Library](https://www.arduino.cc/reference/en/libraries/adafruit-gps-library/) V1.7.4 (install all)
- [Sim800L http connector](https://www.arduino.cc/reference/en/libraries/sim800l-http-connector/) V1.14.0
- [Seeed Arduino LSM6DS3](https://www.arduino.cc/reference/en/libraries/seeed-arduino-lsm6ds3/) V2.0.3
- [OneWire](https://github.com/PaulStoffregen/OneWire) V2.3.7

#### B. Testing Tool Requirements

[W3C - Testing/Requirements](https://www.w3.org/wiki/Testing/Requirements)

## III. Strategy

#### A. Testing Type

**Unit tests**

Unit tests are very low-level and close to the source of an application. They consist of testing individual methods and functions of the classes, components, or modules used by your software. Unit tests are generally quite cheap to automate and can run very quickly by a continuous integration server.

**Integration tests**

Integration tests verify that different modules or services used by your application work well together. For example, it can be testing the interaction with the database or making sure that microservices work together as expected. These types of tests are more expensive to run as they require multiple parts of the application to be up and running.

**Functional tests**

Functional tests focus on the business requirements of an application. They only verify the output of an action and do not check the intermediate states of the system when performing that action.

**End-to-end tests**

End-to-end testing replicates a user behavior with the software in a complete application environment. It verifies that various user flows work as expected.

**Smoke tests**

Smoke tests are basic tests that check the basic functionality of a device. They are meant to be quick to execute, and their goal is to assure you that the major features of your system are working as expected.

*source: [Atlsassian - types of software testing](https://www.atlassian.com/continuous-delivery/software-testing/types-of-software-testing)*

#### B. Test Strategy

**battery management tests**

Test 01:
For 5 minutes with the same position, the battery give the minimum of powerful to the bluetooth, in an ambient environment.
- modify code to wait 5 secondes
- wait 5 secondes
- see the message send

Test 02:
For 5 minutes with the same position, the battery give the minimum of powerful to the bluetooth, in a cold environment.
- modify code to wait 5 secondes
- put in the freezer
- wait 5 secondes
- see the message send

Test 03:
The lifespan of the battery is 7 days with 6 hours of operation and 18h in stand-by, in an ambient environment.
- write program to power on and power off at good time
- unplug the the device
- wait

Test 04:
The lifespan of the battery is 7 days with 6 hours of operation and 18h in stand-by, in a cold environment.
- write program to power on and power off at good time
- unplug the the device
- put in the freezer
- wait

Test 05:
The battery reaches 20% level and turn off.

Test 06:
The battery reaches 80% level and stops charging.
- charge the battery
- wait 80% level
- send message
- wait a few minutes for the level to remain unchanged

**Security issue**

allowed to all users by default |-> increase access to alarm
device ask password to phone and phone ask to device
Test 0.:
<span style="color:red">to be defined</span>

**Lock / unlock**

Test 1.:
<span style="color:red">to be defined</span>

Test 1.:
<span style="color:red">to be defined</span>

**NFC**

Test 1.:
<span style="color:red">to be defined</span>

**Alarm management**

3 light sounds -> little movement / 5 long high sounds -> big movement, shock
Test 1.:
<span style="color:red">to be defined</span>

**Shock notification**

Test 2.:
<span style="color:red">to be defined</span>

**GNSS position acquisition**

Test 2.:
<span style="color:red">to be defined</span>

**Activate / desactivate by app**

Test 2.:
<span style="color:red">to be defined</span>

Test 2.:
<span style="color:red">to be defined</span>

## IV. Installation Qualification

<span style="color:red">to be defined</span>

## V. Documentation test

| ID | Document | Writer | Reviewers | Deadline | Completion date |
| - | - | - | - | - | - |
| a | Project Charter | Elone DELILLE (Technical Leader) | Grégory PAGNOUX (Quality Assurance), Mathias GAGNEPAIN (Program Manager), Robin DEBRY (Project Manager), Enzo GUILLOUCHE (Technical Writer)  | 14/03/2024 | 14/03/2024 |
| b | 1st Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance), Mathias GAGNEPAIN (Program Manager) | 15/03/2024 | 15/03/2024 |
| c | Functional Specifications | Mathias GAGNEPAIN (Program Manager) | Grégory PAGNOUX (Quality Assurance), Enzo GUILLOUCHE (Technical Writer), Robin DEBRY (Project Manager) | 18/03/2024 | XX/0X/2024 |
| d | 2nd Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 22/03/2024 | XX/0X/2024 |
| e | Technical Specifications | Elone DELILLE (Technical Leader) | Grégory PAGNOUX (Quality Assurance) | 26/03/2024 | XX/0X/2024 |
| f | 3rd Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 29/03/2024 | XX/03/2024 |
| g | 4th Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 05/04/2024 | XX/0X/2024 |
| h | 5th Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 12/04/2024 | XX/0X/2024 |
| i | User Manual | Enzo GUILLOUCHE (Technical Writer) | Grégory PAGNOUX (Quality Assurance) | 10/04/2024 | XX/0X/2024 |
| j | Test Plan | Grégory Pagnoux (Quality Assurance) | Grégory PAGNOUX (Quality Assurance), Enzo GUILLOUCHE (Technical Writer) | 10/04/2024 | XX/0X/2024 |
| k | 6th Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 19/04/2024 | XX/0X/2024 |
| l | Readme | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 19/04/2024 | XX/0X/2024 |

## VI. Code test

**Test convention**

- explicitly state the purpose of the test
```C++
[Fact]
public void Add_SingleNumber_ReturnsSameNumber()
{
    var stringCalculator = new StringCalculator();

    var actual = stringCalculator.Add("0");

    Assert.Equal(0, actual);
}
```

- separate each of these actions
```C++
[Fact]
public void Add_EmptyString_ReturnsZero()
{
    // Arrange
    var stringCalculator = new StringCalculator();

    // Act
    var actual = stringCalculator.Add("");

    // Assert
    Assert.Equal(0, actual);
}
```

- naming variables (without magic chains[^7])
```C++
[Fact]
void Add_MaximumSumResult_ThrowsOverflowException()
{
    var stringCalculator = new StringCalculator();
    const string MAXIMUM_RESULT = "1001";

    Action actual = () => stringCalculator.Add(MAXIMUM_RESULT);

    Assert.Throws<OverflowException>(actual);
}
```

- No logic in the tests
```C++
[Theory]
[InlineData("0,0,0", 0)]
[InlineData("0,1,2", 3)]
[InlineData("1,2,3", 6)]
public void Add_MultipleNumbers_ReturnsSumOfNumbers(string input, int expected)
{
    var stringCalculator = new StringCalculator();

    var actual = stringCalculator.Add(input);

    Assert.Equal(expected, actual);
}
```

- Execute 3 times the test (if it's possible)

*source: [Microsoft Learn](https://learn.microsoft.com/fr-fr/dotnet/core/testing/unit-testing-best-practices)*

**Criterias**

| ID | Function | Developer | Description criteria |
| - | - | - | - |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |

**Testing Schedule**

| ID | Deadline | Completion date | Result |
| - | - | - | - |
|  | XX/0X/2024 | XX/0X/2024 | None |
|  | XX/0X/2024 | XX/0X/2024 | None |
|  | XX/0X/2024 | XX/0X/2024 | None |
|  | XX/0X/2024 | XX/0X/2024 | None |
|  | XX/0X/2024 | XX/0X/2024 | None |

[Test cases](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/issues) are done on GitHub issues.

## Glossary

[^1]: CORIS Innovation
The company's main activities are engineering and engineering consultancy, recruitment and headhunting, business management consultancy, and strategic operations. The head office is not far from Lyon and has been in existence since 2015 thanks to Thibault Peltier and Stéphane Maite.
*source: [CORIS Innonvation](https://www.corisinnovation.com)*

[^2]: NFC (Near Field Communication)
Wireless transmission technology that simplifies the exchange of data. The technology is used in particular for Bluetooth on mobile phones.
*source: [Phonandroïd](https://www.phonandroid.com/nfc-android-comment-marche-pour-quels-usages.html#:~:text=Le%20NFC%20)*

[^3]: API (Application Programming Interface)
A software interface that allows one piece of software or service to be "connected" to another piece of software or service in order to exchange data and functions.
*source: [CNIL](https://www.cnil.fr/fr/definition/interface-de-programmation-dapplication-api#:~:text=Une%20API%20)*

[^4]: Arduino
Arduino designs, manufactures, and supports electronic devices and software, allowing people to easily access advanced technologies that interact with the physical world. 
*source: [Arduino](https://www.arduino.cc/en/about)*

[^5]: C++
C++ is a programming language developed in 1983 by Bjarne Stroustrup, who wanted to 'increment' the C language (hence the name, c++ meaning 'add 1 to C'). It is object-oriented programming. C++ allows you to write optimised, extremely fast code.
It is one of the most widely used languages, particularly in software development (e.g. iPod interface, web browsers) or video game programming (e.g. PS3, PS4 operating systems), due to its performance and versatility.
*source: [DataScientest](https://datascientest.com/langage-c-plus-plus)*

[^6]: IDE (Integrated Development Environment)
Software application combining all the tools needed for a software development project in one place. It provides an interface for writing code, organising text groups, and automating redundant programming tasks.
*source: [DataScientest](https://datascientest.com/ide)*

[^7]: Magic Chains
A value that is not defined and for which we do not know what it represents.
(e.g: ```Action actual = () => stringCalculator.Add("1001");```
"1001" is a magic chains and must be defined using a constant such as:
```const string MAXIMUM_RESULT = "1001";```
```Action actual = () => stringCalculator.Add(MAXIMUM_RESULT);```)
