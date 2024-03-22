# SportShield - Test Plan

---

<details>
<summary>Table of Contents</summary>

- [SportShield - Test Plan](#sportshield---test-plan)
  - [I. Introduction](#i-introduction)
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
  - [Glossary](#glossary)

</details>

---

## I. Introduction

### A. Overview

The project was commissioned by [CORIS Innovation](https://www.corisinnovation.com)[^1] from [ALGOSUP](https://algosup.com/en.html) students, and involved software maintenance.
The software is an application for securing sports equipment, which is implemented on hardware supplied by the company.

The goal of the project is to optimize the consumption to make it last longer, from 3 days to 7 days or more, add an NFC[^2] component, and improve the security and the user experience based on the existing prototype.

### B. Requirements

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

### A. Testing Environment

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

### B. Testing Tool Requirements

[W3C - Testing/Requirements](https://www.w3.org/wiki/Testing/Requirements)

## III. Strategy

### A. Testing Type

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

### B. Test Strategy

There are 8 categories of tests that are carried out independently, from the most important to the least important:

- battery management
- security issues
- locking/unlocking
- NFC
- alarm management
- alarm notification
- GNSS position acquisition
- activation/deactivation by application

To test the product, we must use a code convention[^7] and each test must be run 3 times correctly to be validated.

We assess the severity[^8] of the tests using 4 levels of evaluation:
Level 1 - Critical (system shutdown, complete system failure)
Level 2 - Major (significant degradation of service)
Level 3 - Minor (most of the system is operational)
Level 4 - Low (informative)

Due to a problem with the hardware provided, we have to use ancillary equipment. In order to test whether the features are functional, we use Breadboards with LEDs to simulate the components (buzzer, electromagnet, etc.) and resistors.

*Source: [TestSigma] (https://testsigma.com/blog/difference-between-priority-and-severity/)*

## IV. Documentation test

| ID | Document | Writer | Reviewers | Deadline | Completion date |
| - | - | - | - | - | - |
| a | Project Charter | Elone DELILLE (Technical Leader) | Grégory PAGNOUX (Quality Assurance), Mathias GAGNEPAIN (Program Manager), Robin DEBRY (Project Manager), Enzo GUILLOUCHE (Technical Writer)  | 14/03/2024 | 14/03/2024 |
| b | 1st Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance), Mathias GAGNEPAIN (Program Manager) | 15/03/2024 | 15/03/2024 |
| c | Functional Specifications | Mathias GAGNEPAIN (Program Manager) | Grégory PAGNOUX (Quality Assurance), Enzo GUILLOUCHE (Technical Writer), Robin DEBRY (Project Manager) | 18/03/2024 | 18/03/2024 |
| d | 2nd Weekly Report | Robin DEBRY (Project Manager) | Grégory PAGNOUX (Quality Assurance) | 22/03/2024 | 22/03/2024 |
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

- naming variables (without magic chain[^9])

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

| ID | Function | Developer | Description criteria | Severity |
| - | - | - | - | - |
| 01 | Hardware | Coris Innovation | - battery supplies the board <br> - LED on board flash <br> - buzzer ring <br> - Electromagnet can be locked <br> - SIM card communicate data <br> - GNSS antenna communicate position <br> - NFC | Critical |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |

**Testing Schedule**

| ID | Test Type | Description | Deadline | Completion date | Result |
| - | - | - | - | - | - |
| 01 | End-to-End test | Hardware | 20/03/2024 | 19/03/2024 | Fail |
|  |  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  |  | XX/0X/2024 | XX/0X/2024 | None |
|  |  |  | XX/0X/2024 | XX/0X/2024 | None |

**Test cases**

[Test cases](https://github.com/algosup/2023-2024-project-4-sportshield-team-2/issues) are done on GitHub issues.

## Glossary

[^1]: CORIS Innovation
The company's main activities are engineering and engineering consultancy, recruitment and headhunting, business management consultancy, and strategic operations. The head office is not far from Lyon and has been in existence since 2015 thanks to Thibault Peltier and Stéphane Maite.
*source: [CORIS Innonvation](https://www.corisinnovation.com)*

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
Coding conventions are a set of guidelines for a specific programming language that recommend programming styles, practices, and methods for each aspect of a program written in that language.
*source: [Wikipedia](https://en.wikipedia.org/wiki/Coding_conventions#:~:text=Coding%20conventions%20are%20a%20set,program%20written%20in%20that%20language.)*

[^8]: Severity
The severity is the impact of the issues on the project/program. It measures thanks to a level system where 1 is critical, 2 is Major, 3 is Minor, and 4 is Low. It's the role of the QA to define the severity of the issue.
*source: [TestSigma](https://testsigma.com/blog/difference-between-priority-and-severity/)*

[^9]: Magic Chain
A value that is not defined and for which we do not know what it represents.
(e.g: ```Action actual = () => stringCalculator.Add("1001");```
"1001" is a magic chain and must be defined using a constant such as:
```const string MAXIMUM_RESULT = "1001";```
```Action actual = () => stringCalculator.Add(MAXIMUM_RESULT);```)
