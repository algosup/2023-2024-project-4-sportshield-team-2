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
    - [Personas](#personas)
      - [Persona 1 - Ashley Ricks](#persona-1---ashley-ricks)
        - [Goals](#goals)
        - [Challenges](#challenges)
      - [Persona 2 - William Greener](#persona-2---william-greener)
        - [Goals](#goals-1)
        - [Challenges](#challenges-1)
      - [Persona 3 - Steve Sinclair](#persona-3---steve-sinclair)
        - [Goals](#goals-2)
        - [Challenges](#challenges-2)
    - [Use Cases](#use-cases)
      - [Movements \& Shocks detection](#movements--shocks-detection)
      - [Battery Status](#battery-status)
      - [Battery is running out](#battery-is-running-out)
      - [Battery is fully charged](#battery-is-fully-charged)
      - [Locking/Unlocking with the mobile app](#lockingunlocking-with-the-mobile-app)
      - [Locking/Unlocking with NFC device](#lockingunlocking-with-nfc-device)
  - [Acceptance criteria](#acceptance-criteria)
  - [Solution overview](#solution-overview)
    - [Movement Detection Improvement](#movement-detection-improvement)
    - [Battery Management Improvement](#battery-management-improvement)
    - [Security Improvement](#security-improvement)
    - [Alarm Management](#alarm-management)
    - [NFC \[1\] Reader](#nfc-1-reader)
    - [Errors](#errors)
    - [Usage](#usage)
      - [Charge your SportShield](#charge-your-sportshield)
      - [How to use it?](#how-to-use-it)
        - [**To Protect your stuff:**](#to-protect-your-stuff)
        - [**To open release your stuff.**](#to-open-release-your-stuff)
  - [Non-functional requirements](#non-functional-requirements)
    - [Performance](#performance)
    - [Maintainability](#maintainability)
    - [Usability](#usability)
    - [Security](#security)
  - [Risks and assumptions](#risks-and-assumptions)
  - [Future improvements](#future-improvements)
  - [Glossary](#glossary)
  - [Appendix](#appendix)
    - [SportShield Scheme](#sportshield-scheme)
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

### Personas

#### Persona 1 - Ashley Ricks

| Ashley Ricks                                                                      | 22 years old                                                                                                                                                                                                                                                                                     |
| --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| <img alt="Ashley Picture" src="./Img/ashley_ricks.png" style="max-width: 200px;"> | **Description:**<br>A vibrant young woman, revels in the exhilarating rush of vacationing amidst the clouds. She finds herself gliding gracefully down a majestic snow-capped mountain, her skis carving elegant trails in the pristine white snowscape.<br><br>**Frequence of use:** <br>- Rare |

##### Goals
  - Ashley wants to secure her skies with the SportShield.
  - She hopes the system is secured and she will not receive false positive.

##### Challenges
  - Ashley needs to be able to let her skies in outdoor lockers without the SportShield freezing.
  - She needs to be able to use it during the entire week without running out of battery.
  - She needs to be noticed if someone touches to her skies.

<hr>

#### Persona 2 - William Greener

| William Greener                                                                  | 37 years old                                                                                                                                                                                                                                                                                                |
| -------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <img alt="Bill Picture" src="Img/william_greener.png" style="max-width: 200px;"> | **Description:**<br>A seasoned adventurer, embodies the spirit of freedom and adventure as he stands tall on the golden sands of the Canary Islands. He eagerly awaits the beckoning waves, ready to embrace the thrill of surfing beneath the warm, tropical sun.<br><br>**Frequence of use:** <br>- Often |

##### Goals
  - He wants to get used to use the product.
  - He wants to secure his surf board.
  - He wants to be able to use it during an entire week-end or during his vacation in the Canary Islands.

##### Challenges
  - William needs a product which won't burn under the sun's heat of Canary Islands.
  - He needs a product which won't often run out of battery.
  - He needs a durable and weatherproof device to withstand outdoor conditions (Water & Sand).

<hr>

#### Persona 3 - Steve Sinclair


| Steve Sinclair                                                                     | 63 years old                                                                                                                                                                                                                                                                                                                                                             |
| ---------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| <img alt="Steve Picture" src="./Img/steve_sinclair.png" style="max-width: 200px;"> | **Description:**<br>An old man with a white and gray beard, he is traveling around the world with his wife in a camping-car, to enjoy his retirement. With each new destination, they discover the beauty of nature and the richness of different cultures, cherishing every moment of their shared journey together.<br><br>**Frequence of use:** <br>- Almost Everyday |

##### Goals
  - He wants to protect his stuff while he is not in his camping-car.
  - He wants to stay alerted if someone touches his stuff but he is not that confident with smartphones.

##### Challenges
  - He needs to be able to use another way to unlock than his smartphone.
  - He wants a hardware which will resist to different climates he may encounter.
  - It should have a connectivity around the world.

<hr>

### Use Cases

#### Movements & Shocks detection
| Use Case Name      | Movements & Shocks Detection                                                                                                                                                                        |
| ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Actors             | SportShield Device, User, Mobile App                                                                                                                                                      |
| Description        | The user should be notified on his mobile phone and SportShield must ring if the device is movement or rotating.                                                                          |
| Pre-conditions     | The device is activated, and checking the position and shocks.                                                                                                                            |
| Post-conditions    | The device send a notification to the user through the API.                                                                                                                               |
| Normal Flow        | 1. The user activate the device in the application.<br>2. Someone try to stole the user's stuff.<br>3. The device ring and send a notification.<br>4. The user receive the notification. |
| Alternative Flows  | 1. If the device is't connected to the network, the status can't be communicated to the app.<br>2. The device can be moved for multiple reason else than a steal.                                         |
| Exception Handling | 1. The device will send the notification when the signal will be found.<br>2. The device will send a false positive making the user worry.                                                |

#### Battery Status
| Use Case Name      |  Battery Status   |
| ------------------ | --- |
| Actors             | SportShield, Mobile App    |
| Description        | The user must know the battery status.    |
| Pre-conditions     | The device is powered and connected to the network    |
| Post-conditions    | The battery level is updated in the application.    |
| Normal Flow        | Every X time the device send the battery state to the App.    |
| Alternative Flows  | 1. If the device is't connected to the network, the battery status can't be communicated |
| Exception Handling | 1. The device will send the notification when it will be connected.    |

#### Battery is running out
| Use Case Name      |  Battery is running out   |
| ------------------ | --- |
| Actors             | SportShield, Mobile App    |
| Description        | The user must be informed when the device is running out of battery. If the device is too low, release the rope and turn it off.    |
| Pre-conditions     | The device is running out of battery    |
| Post-conditions    | A notification is sent to inform the user    |
| Normal Flow        | 1. When the battery is low the device send a notification to the user<br>3. when the battery is very too low the device release the cable and turn it-self off to prevent irreversible damage on the battery.   |
| Alternative Flows  | 1. If the device is't connected to the network, the notification can't be sent.<br>2. The battery level is too low and the device isn't connected to the network, it will turn it-self off without sending any notification. |
| Exception Handling | 1. The device will send the notification when it will be connected.<br>2. The user will not be informed.    |

#### Battery is fully charged
| Use Case Name      |  Battery is fully charged   |
| ------------------ | --- |
| Actors             | SportShield, Mobile App    |
| Description        | The user must be informed when the battery is fully charged. When the device is charged, it stopped charging to prevent irreversible battery damage.    |
| Pre-conditions     | The battery is fully charged    |
| Post-conditions    | A notification is sent to inform the user    |
| Normal Flow        | 1. When the battery is fully charge the device stop charging and send a notification to the user    |
| Alternative Flows  | 1. If the device is't connected to the network, the battery status can't be communicated but it will stop charging |
| Exception Handling | 1. The device will send the notification when it will be connected.<br>2. The user will not received the notification.    |


#### Locking/Unlocking with the mobile app
| Use Case Name      |  Locking/Unlocking with the mobile app  |
| ------------------ | --- |
| Actors             |  User, SportShield, Mobile App   |
| Description        | The user can lock or unlock the device at any moment with the app on his smartphone.    |
| Pre-conditions     | The device must be powered, the device and the smartphone are connected to the network.    |
| Post-conditions    | The device will be locked or unlocked    |
| Normal Flow        | 1. The user can lock the SportShield through the App, which will enable the movement detection.<br>2. The user can unlock the sport shield through the App, which will disable the movements detection.    |
| Alternative Flows  | 1. SportShield or user's mobile isn't connected to the network, the user can't interact with the SportShield.    |
| Exception Handling | 1. The device will wait until it receive a user interaction.<br>2. if it's locked the user ins't able to move it without making ring and he can't get back his stuffs.    |

#### Locking/Unlocking with NFC device
| Use Case Name      | Unlock/Unlock the device with NFC    |
| ------------------ | --- |
| Actors             | User, SportShield, Mobile App    |
| Description        | The user can lock or unlock the SportShield without his smartphone by using a NFC device.    |
| Pre-conditions     | The device must be powered and the user should have a NFC device.    |
| Post-conditions    | The device is now lock or unlock.    |
| Normal Flow        | By making contact between the NFC device and the SportShield it will lock or unlock like by using the mobile app.    |
| Alternative Flows  | 1. The NFC card in the device isn't working, the interaction can't be detected.<br>2. The NFC device hasn't the right to access to the SportShield.    |
| Exception Handling | 1. If the NFC card isn't working nothing will happend.<br>2. If access right are invalid, the user will be inform of a unsuccessful locking/unlocking attempt.  |


## Acceptance criteria

The electromagnet mustn't stay locked if the user wants to take back his stuff.

The Alarm must be deactivatable without waiting if the user made a misstake.

The Battery must last for 7 days or more.

It must run without any issues, If not, it need to catch them and alert the user of the error.

To ensure that the project is viable, all the specifications must be approved by the client and the programs must be tested in intern by our Quality Assurance and potentially other team members.

## Solution overview

### Movement Detection Improvement
The actual movement detection triggers the alarm only on rotation.

| Problem Occurs                                                       | Solution                         |
| -------------------------------------------------------------------- | -------------------------------- |
| We can move the device on until we don't rotate it, it doesn't ring. | We add a detection on axis x, y. |

### Battery Management Improvement

| Problem Occurs                             | Solution                                                                                                                                   |
| ------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------ |
| A full battery will be empty in 3 days.    | - We must check each component one by one to reduce the usage consumption.<br>- Turn all components in sleep mode when we don't need them. |
| The electromagnet consumes a lot of energy | We will activate it less than 1 second when we need it.                                                                                    |

### Security Improvement

By default, the device is accessible to everyone.

| Problem Occurs                              | Solution                                                         |
| ------------------------------------------- | ---------------------------------------------------------------- |
| Everyone can lock or unlock the SportShield | We will restrict the authentication to the owner or trust people |

### Alarm Management

| Problem Occurs                                                | Solution                                                                                                                                |
| ------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| While the alarm is ringing, all other actions are unavailable | We will modify the alarm to make it ring while other actions are executed (possibility for the user to disable the alarm at any moment) |
| The alarm is too loud.                                        | We want to reduce the decibel from 135dB to 80dB, to reduce damage to the hearing.                                                      |

### NFC [[1]](#glossary-1) Reader

Currently, the NFC [[1]](#glossary-1) reader isn't been implemented yet, we should include it for easier usage of the product, making user able to unlock/lock the SportShield with a NFC [[1]](#glossary-1) card or badge (without their smartphone), or by contact with their smartphone (depending of brand and phone's model).

### Errors

The program must never be stuck on an issue, and continue without these features in the following case:
- **Impossible to reach the API [[2]](#glossary-2) server**
  - Retrying in a few minutes
- **Impossible to find a signal**
  -  Retrying in a few minutes
- **Buzzer not working**
  - Inform the client about the issue and continue to send device data in case of movement

The program will stop working if:
- **A hardware issue is encountered**
- **The SportShield has run out of battery**

### Usage

#### Charge your SportShield
A fully-charged SportShield can last over 6 days.

To charge SportShield:

Plug the charger into the USB port on the SportShield.
Plug the other end of the charger into an outlet.

The SportShield is now charging. Try to not use SportShield during its charging.

To use the device correctly please follow these steps:

#### How to use it?
##### **To Protect your stuff:**
1. Pull the rope and enclose your stuff.
2. Insert the rope into the hole.
3. Enable the lock:
     - **With Bluetooth:**
       1. Authenticate yourself.
       2. Enable locking.
     - **With a NFC [[1]](#glossary-1) device:**
       1. Make contact between the NFC [[1]](#glossary-1) device and the SportShield
<hr>

##### **To open release your stuff.**
1. Release the rope:
   - **With Bluetooth:**
     1. Authenticate yourself.
     2. Disable locking.
    - **With a NFC [[1]](#glossary-1) device:**
      1. Make contact between the NFC [[1]](#glossary-1) device and the SportShield
2. Pull the rope from the hole.

You can refer to the user manual for detailed usage, which you can find: [HERE](../userManual.pdf)

## Non-functional requirements

### Performance

The program must be able to set each module in sleep mode will no movement has been detected to economize the battery and wake them up only when it needs them. The code must be executed almost fast, less than 1s.

### Maintainability

In the event the client decides to change their requirements, we must be able to easily update the program to fit the new requirements. Also, if the client wants to update it with an intern or with another developpement team the code must be commented on and documented to help its understanding.

### Usability

Although we used a self-made API [[2]](#glossary-2) to test efficiently the program the client can easily replace it with his own API [[2]](#glossary-2).

This API [[2]](#glossary-2) will receive a JSON [[5]](#glossary-5) array containing device information like:
```json
{
    "latitude":"{currentLatitude}", 
    "longitude":"{currentLatitude}", 
    "batterie":"{batteryVoltage}"
}
```

We will probably add some useful information like battery level (in percent), which you can use or not in your API [[2]](#glossary-2)

### Security

We can update the internal program by plugging it into the charging port, which can lead to invalid data targets, wrong information or even more, the disabling of the device or the installation of malware.

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


1. **Remote Locking and Unlocking**: Enable users to remotely lock or unlock the device via a secure online portal or mobile app, providing convenience and peace of mind, especially in situations where physical access to the device is not possible.

2. **Customizable Alarm Settings**: Allow users to customize alarm settings based on their preferences and environment, such as adjusting alarm volume, duration, and sensitivity to better suit their needs.

3. **Data Encryption and Privacy**: Implement robust data encryption protocols to ensure the confidentiality and integrity of user data transmitted between the device and external servers, safeguarding sensitive information from unauthorized interception or tampering.

4. **Enhanced Durability and Weather Resistance**: Develop ruggedized hardware components and weatherproof enclosures to withstand harsh environmental conditions, including extreme temperatures, moisture, and physical impacts, ensuring reliable operation in various outdoor settings.

5. **Extended Battery Life**: Continuously optimize power management algorithms and hardware components to further extend the device's battery life, allowing for prolonged usage between recharges and minimizing downtime.

These future improvements aim to enhance the functionality, usability, and security of the SportShield device, providing users with a comprehensive and reliable solution for protecting their sports equipment and ensuring peace of mind during outdoor activities. These Improvements way are just theorical and will not be implemented without Coris Innovation Approval.

## Glossary

| Id                       | Term        | Definition                                                                                                                                                                                                                     | What it means in this project                                                                                  | Additional Content                                                  |
| :----------------------- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- |
| <p id="glossary-1">1</p> | **NFC**     | Near Field Communication (NFC) is a set of short-range wireless technologies, typically requiring a distance of 4 cm or less to initiate a connection.                                                                         | The SportShield will be able to be lock or unlock with a card or a badge.                                      | [Wikipedia](https://en.wikipedia.org/wiki/Near-field_communication) |
| <p id="glossary-2">2</p> | **API**     | API stands for Application Programming Interface. In the context of APIs, the word Application refers to any software with a distinct function. Interface can be thought of as a contract of service between two applications. | The device must send data from the application through the API to keep the user informed of the device status. | [Wikipedia](https://en.wikipedia.org/wiki/API)                      |
| <p id="glossary-3">3</p> | **Arduino** | Arduino is an Italian open-source hardware and software company, project, and user community that designs and manufactures single-board microcontrollers and microcontroller kits for building digital devices.                | We will use Arduino IDE and a variant of C++ made for Arduino during this project.                             | [Wikipedia](https://en.wikipedia.org/wiki/Arduino)                  |
| <p id="glossary-4">4</p> | **C++**     | C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup.                                                                                                              | Arduino's Language is a variant of C++ specialized to manage their microcontrollers.                           | [Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B)                  |
| <p id="glossary-5">5</p> | **JSON**    | JSON is a text format that is completely language independent but uses conventions that are familiar to programmers of the C-family of languages, including C, C++.                                                            | Information about the device (position, battery, etc...) will be sent to the API in JSON format.               | [Wikipedia](https://en.wikipedia.org/wiki/JSON)                     |

## Appendix

### SportShield Scheme

<!-- TODO: Add SportShield Scheme to easily visualize the postion of each important part (Awaiting to receive it from Coris) -->