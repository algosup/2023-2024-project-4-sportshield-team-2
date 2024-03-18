# Sportshield Project Test Plan

---

<details>
<summary>Table of Contents</summary>

- [Sportshield Project Test Plan](#sportshield-project-test-plan)
  - [I. Introduction](#i-introduction)
<<<<<<< HEAD:Documents/TestPlan/testPlan.md
    - [A. Overview](#a-overview)
    - [B. Requirements](#b-requirements)
  - [II. Ressources Requirements](#ii-ressources-requirements)
    - [A. Testing Environment](#a-testing-environment)
    - [B. Testing Tool Requirements](#b-testing-tool-requirements)
  - [III. Strategy](#iii-strategy)
    - [A. Testing Type](#a-testing-type)
    - [B. Test Strategy](#b-test-strategy)
  - [IV. Documentation test](#iv-documentation-test)
  - [V. Code test](#v-code-test)
=======
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
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md
  - [Glossary](#glossary)

</details>

[Readme](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/blob/main/README.md)

---

## I. Introduction

### A. Overview

<span style="color:red">to be defined</span>

### B. Requirements

<<<<<<< HEAD:Documents/TestPlan/testPlan.md
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
=======
<span style="color:red">to be defined</span>
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md

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

### A. Testing Environment

<<<<<<< HEAD:Documents/TestPlan/testPlan.md
Operating system: MacOS, Windows
language: C++, Arduino
IDE[^6]: [VisualStudioCode](https://code.visualstudio.com/download), [Arduino IDE](https://www.arduino.cc/en/software)
Libraries:

=======
Operating system : MacOS, Windows, Arduino
language : C, Arduino
Integrated Development Environment : VisualStudioCode
Libraries :
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md
- [NRF52_MBED_TimerInterrupt](https://github.com/khoih-prog/NRF52_MBED_TimerInterrupt) V1.4.1
- [ArduinoBLE](https://www.arduino.cc/reference/en/libraries/arduinoble/) V1.3.6
- [Adafruit GPS Library](https://www.arduino.cc/reference/en/libraries/adafruit-gps-library/) V1.7.4 (install all)
- [Sim800L http connector](https://www.arduino.cc/reference/en/libraries/sim800l-http-connector/) V1.14.0
- [Seeed Arduino LSM6DS3](https://www.arduino.cc/reference/en/libraries/seeed-arduino-lsm6ds3/) V2.0.3
- [OneWire](https://github.com/PaulStoffregen/OneWire) V2.3.7

### B. Testing Tool Requirements

<span style="color:red">to be defined</span>

#### C. Additional Ressource Requirements

<span style="color:red">to be defined</span>

## III. Strategy

<<<<<<< HEAD:Documents/TestPlan/testPlan.md
### A. Testing Type
=======
#### A. Test Strategy

<span style="color:red">to be defined</span>

#### B. Testing Type
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md

**Unit tests**

Unit tests are very low level and close to the source of an application. They consist in testing individual methods and functions of the classes, components, or modules used by your software. Unit tests are generally quite cheap to automate and can run very quickly by a continuous integration server.

**Integration tests**

Integration tests verify that different modules or services used by your application work well together. For example, it can be testing the interaction with the database or making sure that microservices work together as expected. These types of tests are more expensive to run as they require multiple parts of the application to be up and running.

**Functional tests**

Functional tests focus on the business requirements of an application. They only verify the output of an action and do not check the intermediate states of the system when performing that action.

**End-to-end tests**

End-to-end testing replicates a user behavior with the software in a complete application environment. It verifies that various user flows work as expected.

**Smoke tests**

<<<<<<< HEAD:Documents/TestPlan/testPlan.md
Smoke tests are basic tests that check the basic functionality of a device. They are meant to be quick to execute, and their goal is to assure you that the major features of your system are working as expected.

*source: [Atlsassian - types of software testing](https://www.atlassian.com/continuous-delivery/software-testing/types-of-software-testing)*

### B. Test Strategy



**battery management tests**

Test ID 01: (functional test)

For 5 minutes in the same position, the battery gives the minimum of power to the bluetooth, in an ambient environment.

- Modify code to wait 5 seconds.
- Wait 5 secondes.
- See the message send.

Test ID 02: (functional test)

For 5 minutes in the same position, the battery gives the minimum of power to the bluetooth, in a cold environment.

- Modify code to wait 5 seconds.
- Put in the freezer (-10°C).
- Wait 5 secondes.
- See the message send.

Test ID 03: (end-to-end test)

The lifespan of the battery is 7 days with 6 hours of operation and 18 hours on stand-by, in an ambient environment.

- Write program to power on and power off at a good time.
- Unplug the device.
- Wait.

Test ID 04: (end-to-end test)

The lifespan of the battery is 7 days with 6 hours of operation and 18 hours on stand-by, in a cold environment.

- Write program to power on and power off at a good time.
- Unplug the device.
- Put in the freezer (-10°C).
- Wait.

Test ID 05: (smoke test)

The battery reaches a 20% level and turns off.

Test ID 06: (integration test)

The battery reaches a 80% level and stops charging.

- Charge the battery.
- Wait 80% level.
- Send message.
- Wait a few minutes for the level to remain unchanged.

**Security issues**

Test ID 07: (integration test)

The phone sendsa request to the device to give the password

- Write a program which sends "I need a password" to the device when we press "give a password" button.

Test ID 08: (functional test)

The device sends an e-mail with the password

- Write a program which sends "password given" to an e-mail.
- Check receipt of the e-mail.

Test ID 09: (integration test)

The device sends a request which opens the application to put the password given

- Write a program to open the application.
- Send information to the phone.
- The window is open on the screen phone.

Test ID 10: (unit test)

When the wrong password is entered, print a message

- Write the password on the smartphone.
- Press "validate" button.
- "Wrong password" message print.

Test ID 11: (unit test)

When the good password is entered, print a message and close the password screen

- Write the password on the smartphone.
- Press the "validate" button.
- "Good password" message print.
- The window closes.

**Lock/unlock**

Test ID 12: (unit test)

We can unlock the device, with the device, in an ambient environment

- Test the code to unlock the electromagnet.

Test ID 13: (unit test)

We can unlock the device, with device, in a cold environment

- Put in the freezer (-10°C)
- Test the code to unlock the electromagnet.

Test ID 14: (unit test)

We can lock the device, with device, in an ambient environment

- Test the code to lock the electromagnet.

Test ID 15: (unit test)

We can lock the device, with device, in a cold environment

- Put in the freezer (-10°C).
- Test the code to lock the electromagnet.

Test ID 16: (integration test)

We can unlock the device, with the phone, in an ambient environment

- Press the unlock button on the phone.
- Request sent to the device by the phone.
- Unlock the electromagnet.

Test ID 17: (integration test)

We can unlock the device, with the phone, in a cold environment

- Put in the freezer (-10°C).
- Press the unlock button on the phone.
- Request sent to the device by the phone.
- Unlock the electromagnet.

Test ID 18: (integration test)

We can lock the device, with the phone, in an ambient environment

- Press the lock button on the phone.
- Request sent to the device by the phone.
- Lock the electromagnet.

Test ID 19: (integration test)

We can lock the device, with the phone, in a cold environment

- Put in the freezer (-10°C).
- Press the lock button on the phone.
- Request sent to the device by the phone.
- Lock the electromagnet.

**NFC**

Test ID 20:

<span style="color:red">to be defined</span>

Test ID 21:

<span style="color:red">to be defined</span>

**Alarm management**

Test ID 22: (unit test)

Move the device slowly to have 3 light sounds.

Test ID 23: (unit test)

Move the device quickly to have 5 high sounds.

Test ID 24: (unit test)

Shock the device to have 5 high sounds.

**Shock notification**

Test ID 25:

<span style="color:red">to be defined</span>

**GNSS position acquisition**

Test ID 2.:

<span style="color:red">to be defined</span>

**Activate / desactivate by app**

Test ID 2.:

<span style="color:red">to be defined</span>

Test ID 2.:

<span style="color:red">to be defined</span>

## IV. Documentation test

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
| j | Test Plan | Grégory Pagnoux (Quality Assurance) | Grégory PAGNOUX (Quality Assurance), Robin DEBRY (Project Manager) | 10/04/2024 | XX/0X/2024 |
| k | 6th Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 19/04/2024 | XX/0X/2024 |
| l | Readme | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 19/04/2024 | XX/0X/2024 |

## V. Code test

**Test convention**

- explicitly state the purpose of the test

*ex:*

```C++
public void Add_SingleNumber_ReturnsSameNumber()
{
    var stringCalculator = new StringCalculator();

    var actual = stringCalculator.Add("0");

    Assert.Equal(0, actual);
}
```

- separate each of these actions

*ex:*

```C++
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

- naming variables (without magic chains[^8])

*ex:*

```C++
void Add_MaximumSumResult_ThrowsOverflowException()
{
    var stringCalculator = new StringCalculator();
    const string MAXIMUM_RESULT = "1001";

    Action actual = () => stringCalculator.Add(MAXIMUM_RESULT);

    Assert.Throws<OverflowException>(actual);
}
```

- No logic in the tests

*ex:*

```C++
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

| ID | Function | Developer | Description criteria | Severity[^9] |
| - | - | - | - | - |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |

**Testing Schedule**

| ID | Type | Deadline | Completion date | Result |
| - | - | - | - | - |
|  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  | XX/0X/2024 | XX/0X/2024 | None |
=======
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
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md

**Test convention**

<span style="color:red">to be defined</span>

[Test case](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/issues) is done on GitHub issues category.

## Glossary

<span style="color:red">to be defined</span>

<<<<<<< HEAD:Documents/TestPlan/testPlan.md
[^2]: NFC (Near Field Communication)
Wireless transmission technology that simplifies the exchange of data. The technology is used in particular for Bluetooth on mobile phones.
*source: [Phonandroïd](https://www.phonandroid.com/nfc-android-comment-marche-pour-quels-usages.html#:~:text=Le%20NFC%20)*

[^3]: API (Application Programming Interface)
A software interface that allows one piece of software or service to be "connected" to another piece of software or service to exchange data and functions.
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

[^7]: Code convention
Coding conventions are a set of guidelines for a specific programming language that recommend programming style, practices, and methods for each aspect of a program written in that language.
*source: [Wikipedia](https://en.wikipedia.org/wiki/Coding_conventions#:~:text=Coding%20conventions%20are%20a%20set,program%20written%20in%20that%20language.)*

[^8]: Magic Chains
A value that is not defined and for which we do not know what it represents.
(e.g: ```Action actual = () => stringCalculator.Add("1001");```
"1001" is a magic chain and must be defined using a constant such as:
```const string MAXIMUM_RESULT = "1001";```
```Action actual = () => stringCalculator.Add(MAXIMUM_RESULT);```)

[^9]: Sevrity
The severity is the impact of the issues on the project/program. Is measure thanks level system which the 1 is critical, 2 is Major, 3 is Minor, and 4 is Low. It's the role of the QA to define the severity of the issue.
*source: [TestSigma](https://testsigma.com/blog/difference-between-priority-and-severity/)*
=======
*source : [link]()*
>>>>>>> 9546b5fa72fd5bd5ed0b9e4bed90cba1bd3c09c8:Documents/testPlan.md
