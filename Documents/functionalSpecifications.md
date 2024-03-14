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

The sportShield must allow for the following actions:
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



## Acceptance criteria


## Solution overview


### Errors

### Usage

## Non-functional requirements

### Performance

### Maintainability

### Usability

### Security

## Risks and assumptions

## Future improvements

## Glossary