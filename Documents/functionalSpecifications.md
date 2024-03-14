# SportShield - Functional specifications

This project was requested by [Coris Innovation](https://www.corisinnovation.com/), a French IT company.

The goal of the project is to optimize the battery consumption to make keep it alive from 3 days to 7 days or more, adding NFC component, improve the security and the user experience based on the existing prototype.

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

| Name    | Occupation                                                    | Links                                       |
| ------- | ------------------------------------------------------------- | ------------------------------------------- |
| Florent | Client (Coris Innovation - Management of innovative projects) | [Website](https://www.corisinnovation.com/) |

## Project scope

We have multiple objectives for this project:
- Reducing the battery consumption.
- Increasing the security.
- Implement the NFC module.
- Improve the alarm function to be able to stop it when we want without waiting the loop end.

## Functional requirements

The SportShield must allow for the following actions:
- Send device information to the API
  - Battery level
  - Position (latitude, longitude)
  - Movement (rotation, new position)
- Efficient Alarm management
  - 3 light sounds when a light shock is detected
  - 5 long high sounds when a strong shock is detected
  - Give possibility for user to stop ringing alarm at any moment

All the code must written in the Arduino language (a variant of the C++ programming language), following the existing code convention.
No libraries outside of the ones already use in the existing software.

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

Ashley Ricks is a 22 year old student in vacation to the mountain.

#### Goals
  - Ashley wants to secure her skies with the SportShield.
  - She hopes the system is secured and she will not receive false positive.

#### Challenges
  - Ashley needs to be able to let her skies in outdoor lockers without the sportshield freeze.
  - She needs to be able to use it during the entire week without running out of battery.
  - She needs to by notice if someone touch to her skies.

### Persona 2 - William Greener

William is a 37 year old fan of surfs where I goes everymonth.

#### Goals
  - He aims to use the product for a while.
  - He wants to secure is surf board.
  - He wants to be able to use it during an entire week-end or during is vacation in the Canary Islands.

#### Challenges
  - Bill needs a product which will not burn in the heat sun of Canary islandes.
  - He needs a production wich will not run out of battery.
  - He needs a device that is durable and weatherproof to withstand outdoor conditions (Water & Sand).

### Persona 3 - Steve Sinclair

Steve Sinclair is a 63 year old retreated. He is in road trip around the world with his wife, to enjoy his retreat.

#### Goals
  - He wants to protect is stuff will he is not in his camping-car.
  - He intends to stay alert if someone touch to his stuff but he is not very good with smartphones.

#### Challenges
  - He need to be able to use another way of unlocking than his smartphone.
  - He intends a hardware which will resist to different climate he can encounter.
  - It should have a connectivity around the world.

## Acceptance criteria

The electromagnet mustn't stay locked if the user want to take back his stuff.

The Alarm must to be able to be disabled without waiting if the user made a misstake.

The Battery must stay alive for 7 days or more.

It must run without any issues, If this event happen it need to catch them and alert the user of the error.

To ensure that the project is viable, all the specifications must be approved by the client and the the programs must be tested in intern by our Quality Assurance and potentially others teams members.

## Solution overview

<!-- TODO: List all our solutions -->

### Errors

The program will must never be stuck on an issue, and continue without this features in the following case:
- **Impossible to reach the API server**
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



Although we used a selfmade API to test efficently the program the client can easily replace it by is own API.

This API will receive JSON array cointaing device informations like:
```json
{
    "latitude":"{currentLatitude}", 
    "longitude":"{currentLatitude}", 
    "batterie":"{batteryVoltage}"
}
```

but we will probably add some usefull information like batterie level (in percent), which you can use or not in your API

### Security

We can update the internal program by plugin on the charging port, it can lead to invalid data target, wrong inform or even more, the disabling of the device or the installation of a malware.

## Risks and assumptions

## Future improvements

## Glossary