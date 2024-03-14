# SportShield - Functional specifications

This project was requested by [Coris Innovation](https://www.corisinnovation.com/), a French IT company.

The goal of the project is to optimize the consumption to make it last longer, from 3 days to 7 days or more, adding NFC [[1]](#glossary-1) component, improve the security and the user experience based on the existing prototype.

<details>
<summary>Table of Contents</summary>

- [SportShield - Functional specifications](#sportshield---functional-specifications)
  - [Stakeholders](#stakeholders)
    - [Project members](#project-members)
    - [Other stakeholders](#other-stakeholders)
  - [Project scope](#project-scope)
  - [Functional requirements](#functional-requirements)
  - [Deliverables and milestones](#deliverables-and-milestones)
  - [Personas and use cases](#personas-and-use-cases)
    - [Persona 1 - Ashley Ricks](#persona-1---ashley-ricks)
      - [Goals](#goals)
      - [Challenges](#challenges)
    - [Persona 2 - William Greener](#persona-2---william-greener)
      - [Goals](#goals-1)
      - [Challenges](#challenges-1)
    - [Persona 3 - Steve Sinclair](#persona-3---steve-sinclair)
      - [Goals](#goals-2)
      - [Challenges](#challenges-2)
  - [Acceptance criteria](#acceptance-criteria)
  - [Solution overview](#solution-overview)
    - [Movement Detection Improvement](#movement-detection-improvement)
    - [Battery Management Improvement](#battery-management-improvement)
    - [Security Improvement](#security-improvement)
    - [Alarm Management](#alarm-management)
    - [NFC Reader](#nfc-reader)
    - [Errors](#errors)
    - [Usage](#usage)
  - [Non-functional requirements](#non-functional-requirements)
    - [Performance](#performance)
    - [Maintainability](#maintainability)
    - [Usability](#usability)
    - [Security](#security)
  - [Risks and assumptions](#risks-and-assumptions)
  - [Future improvements](#future-improvements)
  - [Glossary](#glossary)
</summary></details>

## Stakeholders

### Project members

| Full name         | Occupation        | Links                                                                    |
| ----------------- | ----------------- | ------------------------------------------------------------------------ |
| Robin DEBRY       | Project manager   | [LinkedIn](https://www.linkedin.com/in/robin-debry/)                     |
| Mathias GAGNEPAIN | Program manager   | [LinkedIn](https://www.linkedin.com/in/mathias-gagnepain-426a131b0/)     |
| Elone DELILLE     | Technical leader  | [LinkedIn](https://www.linkedin.com/in/elonedelille/)                    |
| Enzo GUILLOUCHE   | Technical Writer  | [LinkedIn](https://www.linkedin.com/in/enzo-g-b62114293/)                |
| Raphael DESCAMPS  | software engineer | [LinkedIn](https://www.linkedin.com/in/rapha%C3%ABl-descamps-201112293/) |
| Gregory PAGNOUX   | Quality assurance | [LinkedIn](https://www.linkedin.com/in/gregory-pagnoux-313b3a251/)       |

### Other stakeholders

| Name         | Occupation                                                    | Links                                       |
| ------------ | ------------------------------------------------------------- | ------------------------------------------- |
| Florent ANON | Client (Coris Innovation - Management of innovative projects) | [Website](https://www.corisinnovation.com/) |

## Project scope

We have multiple objectives for this project:
- Reducing the battery consumption.
- Increasing the security.
- Implement the NFC [[1]](#glossary-1) module.
- Improve the alarm function to be able to stop it whenever we want, either the alarm cycle is finished or not.

## Functional requirements

The SportShield must allow for the following actions:
- Send device information to the API [[2]](#glossary-2)
  - Battery level
  - Position (latitude, longitude)
  - Movement (rotation, new position)
- Efficient Alarm management
  - 3 light sounds when a light shock is detected
  - 5 long high sounds when a strong shock is detected
  - Give possibility for user to make the alarm stop ringing whenever he wants.

All the code must be written in the Arduino's [[3]](#glossary-3) language (a variant of the C++ [[4]](#glossary-4) programming language), following the existing code convention. No libraries except the ones that have already been given are allowed.

## Deliverables and milestones


| Date and time       | Deliverable              |
| ------------------- | ------------------------ |
| 18 March 2024, 5 PM | Functional specification |
| 26 March 2024, 5 PM | Technical specification  |
| 10 April 2024, 5 PM | Test plan                |
| 10 April 2024, 5 PM | User Manual              |
| 10 April 2024, 5 PM | Code                     |

## Personas and use cases

### Persona 1 - Ashley Ricks

| Ashley Ricks                                                                                  | 22 years old                                                                                                                                                                                                                         |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| <img alt="Ashley Picture" src="./Img/functional/ashley_ricks.png" style="max-height: 200px;"> | **Description:**<br>A vibrant young woman, revels in the exhilarating rush of vacationing amidst the clouds. She finds herself gliding gracefully down a majestic snow-capped mountain, her skis carving elegant trails in the pristine white snowscape. |

#### Goals
  - Ashley wants to secure her skies with the SportShield.
  - She hopes the system is secured and she will not receive false positive.

#### Challenges
  - Ashley needs to be able to let her skies in outdoor lockers without the SportShield freezing.
  - She needs to be able to use it during the entire week without running out of battery.
  - She needs to be notice if someone touch to her skies.

<hr>

### Persona 2 - William Greener

| William Greener                                                                                | 37 years old                                                                                                                                                                                                                                   |
| ---------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <img alt="Bill Picture" src="./Img/functional/william_greener.png" style="max-height: 200px;"> | **Description:**<br>A seasoned adventurer, embodies the spirit of freedom and adventure as he stands tall on the golden sands of the Canary Islands. He eagerly awaits the beckoning waves, ready to embrace the thrill of surfing beneath the warm, tropical sun. |

#### Goals
  - He wants to get used to use the project.
  - He wants to secure his surf board.
  - He wants to be able to use it during an entire week-end or during his vacation in the Canary Islands.

#### Challenges
  - William needs a product which won't burn under the sun's heat of Canary islandes.
  - He needs a product which won't often run out of battery.
  - He needs a durable and weatherproof device to withstand outdoor conditions (Water & Sand).

<hr>

### Persona 3 - Steve Sinclair


| Steve Sinclair                                              | 63 years old                                                                                                                      |
| ----------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| <img alt="Steve Picture" src="./Img/functional/steve_sinclair.png" style="max-height: 200px;"> | **Description:**<br>An old man with a white and gray beard, he is traveling around the world with his wife in a camping-car, to enjoy his retirement. |

#### Goals
  - He wants to protect his stuff will he is not in his camping-car.
  - He wants to stay alerted if someone touches his stuff but he is not that confident with smartphones.

#### Challenges
  - He needs to be able to use another way to unlock than his smartphone.
  - He wants a hardware which will resist to different climates he may encounter.
  - It should have a connectivity around the world.

<hr>

## Acceptance criteria

The electromagnet mustn't stay locked if the user want to take back his stuff.

The Alarm must to be able to be disabled without waiting if the user made a misstake.

The Battery must stay alive for 7 days or more.

It must run without any issues, If this event happen it need to catch them and alert the user of the error.

To ensure that the project is viable, all the specifications must be approved by the client and the the programs must be tested in intern by our Quality Assurance and potentially others teams members.

## Solution overview

### Movement Detection Improvement
The actual movement detection trigger the alarm only on rotation.

| Problem Occurs | Solution |
| ---- | ---- |
| We can move the device on until we don't rotate it, it doesn't ring. | We add a detection on axis x, y. |

### Battery Management Improvement

| Problem Occurs | Solution |
| --- | --- |
| A full battery will be empty in 3 days. | - We must check each component one by one to reduce the using consumption.<br>- Turn all component in sleep mode when we don't need them. |
| The electromagnet consume a lot of energy | We will active it less than 1 second when we need it. |

### Security Improvement

By default the device is accessible to everyone.

| Problem Occurs | Solution |
| --- | --- |
| Everyone can lock or unlock the SportShield | We will restreint the authentication to the owner or trust people |

### Alarm Management

| Problem Occurs | Solution |
| --- | --- |
| While the alarm is ringing, all others actions are unavailable | We will modify alarm to make it ringing while others action are executed (possibility for the user to disable the alarm at any moment) |
| The alarm is too loud. | We want to reduced the decible from 135dB to 80dB, to readuce damage on the hearing. |

### NFC Reader

Currently, the NFC reader isn't implemented yet, we should include it for an easier usage of the product, make user able to unlock/lock the Sport with a NFC card or badge (without their smartphone), or by contact with their smartphone (depending of brand and phone's model).

### Errors

The program will must never be stuck on an issue, and continue without this features in the following case:
- **Impossible to reach the API [[2]](#glossary-2) server**
  - Retrying in few minutes
- **Impossible to find a signal**
  -  Retrying in few minutes
- **Buzzer not working**
  - Inform client about the issue and continue to send device data in case of movement

The program will stop working if:
- **An hardware issue is encounter**
- **The SportShield is run out of battery**

### Usage

<!-- TODO: Write it based on user manual -->

## Non-functional requirements

### Performance

The program must be able to set each module in sleep mode will no movement has been detected to economize battery and wake them up only when it need them. The code must be exectuted almost fast less than 1s.

### Maintainability

In the event the client decides to change their requirements, we must be able to easily update the program to fit to the new requirements. Also, if the client want to update it in intern or with another developpement team the code must commented and documented to help to it understanding.

### Usability

Although we used a selfmade API [[2]](#glossary-2) to test efficently the program the client can easily replace it by is own API [[2]](#glossary-2).

This API [[2]](#glossary-2) will receive JSON [[5]](#glossary-5) array cointaing device informations like:
```json
{
    "latitude":"{currentLatitude}", 
    "longitude":"{currentLatitude}", 
    "batterie":"{batteryVoltage}"
}
```

but we will probably add some usefull information like batterie level (in percent), which you can use or not in your API [[2]](#glossary-2)

### Security

We can update the internal program by plugin on the charging port, it can lead to invalid data target, wrong inform or even more, the disabling of the device or the installation of a malware.

## Risks and assumptions



| ID    | Description                                 | Risks                                                                                                                                                                                                       | Impact                                                | Likelihood                                            | Solution                                                                                                                                                                     |
| ----- | ------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- | ----------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **1** | Difficulty to understand the existing code. | We may not clearly understand how the existing code works leading to a bad implementation or program issues.                                                                                                | ![High](https://img.shields.io/badge/High-bb2124)     | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | We should reverse Engineer the program and comment uncommented stuff.                                                                                                        |
| **2** | Hardware issue or code misswriting.         | As a prototype not used very often, the hardware can malfunctionning leading to understandable issue if not detected as soon as possible, and the libraries or API [[2]](#glossary-2) urls can be outdated. | ![High](https://img.shields.io/badge/High-bb2124)     | ![Low](https://img.shields.io/badge/Low-3B71CA)       | We will test each hardware module and the existing/fixing if needed before working on it improvement.                                                                        |
| **3** | Lack of documentation for reference.        | Inadequate documentation may hinder troubleshooting or leading to inefficiencies or delays.                                                                                                                 | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | Implement a documentation strategy to comprehensively capture, components, and usage instructions.                                                                           |
| **4** | Inadequate security measures                | Inadequate security measures could make the device vulnerable to unauthorized access or data breaches, compromising user privacy and system integrity.                                                      | ![High](https://img.shields.io/badge/High-bb2124)     | ![Low](https://img.shields.io/badge/Low-3B71CA)       | Implement robust encryption protocols, secure authentication mechanisms, and regular security audits.                                                                        |
| **5** | Environmental factors affecting performance | Environmental factors such as temperature, humidity, or physical shocks may impact the device's performance or durability, affecting its reliability in various conditions.                                 | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | Conduct rigorous environmental testing to assess the device's performance under different conditions.                                                                        |
| **6** | Lack of user acceptance                     | If users do not find the device easy to use, intuitive, or beneficial, adoption rates may be low, leading to reduced market penetration and revenue generation.                                             | ![High](https://img.shields.io/badge/High-bb2124)     | ![Medium](https://img.shields.io/badge/Medium-E4A11B) | Conduct user research and usability testing to understand user needs and preferences, incorporate feedback into the design process, and provide comprehensive user training. |

## Future improvements

<!-- TODO: After we choose what we will do or not -->

## Glossary

| Id                       | Term        | Definition                                                                                                                                                                                                                     | What it means in this project                                                                              | Additional Content                                                  |
| :----------------------- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- |
| <p id="glossary-1">1</p> | **NFC**     | Near Field Communication (NFC) is a set of short-range wireless technologies, typically requiring a distance of 4 cm or less to initiate a connection.                                                                         | The SportShield will be able to be lock or unlock with a card or a badge.                                  | [Wikipedia](https://en.wikipedia.org/wiki/Near-field_communication) |
| <p id="glossary-2">2</p> | **API**     | API stands for Application Programming Interface. In the context of APIs, the word Application refers to any software with a distinct function. Interface can be thought of as a contract of service between two applications. | The device must send data from the application through the API to keep the user informed of device status. | [Wikipedia](https://en.wikipedia.org/wiki/API)                      |
| <p id="glossary-3">3</p> | **Arduino** | Arduino is an Italian open-source hardware and software company, project, and user community that designs and manufactures single-board microcontrollers and microcontroller kits for building digital devices.                | We will used Arduino IDE and a variant of C++ made for arduino during this project.                        | [Wikipedia](https://en.wikipedia.org/wiki/Arduino)                  |
| <p id="glossary-4">4</p> | **C++**     | C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup.                                                                                                              | Arduino's Language is a variant for C++ specialized to managed their microcontrollers.                     | [Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B)                  |
| <p id="glossary-5">5</p> | **JSON**    | JSON is a text format that is completely language independent but uses conventions that are familiar to programmers of the C-family of languages, including C, C++.                                                            | Information about the device (position, battery, etc...) will be sent to the API in JSON format.           | [Wikipedia](https://en.wikipedia.org/wiki/JSON)                     |