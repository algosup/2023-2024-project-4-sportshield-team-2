this document contains the main documentation for the management of the project like :

- [Project charter](#project-charter)
- [Task schedule](#task-schedule)
- [RACI matrix](#raci-matrix)
- [MoSCoW](#moscow)
- [Target Key Performace Indicators](#target-key-performace-indicators)
- [Statement of work](#statement-of-work)

## Project charter

The project charter is a document that formally authorizes a project. The project charter provides a high-level overview of the project and is a critical document for getting the project started. Our project charter is [here](projectCharter.md).

## Task schedule

The task schedule of this project is on the projects on GitHub [here]( https://github.com/orgs/algosup/projects/25/views/1).

## RACI matrix

|Tasks|Project Manager|Program Manager|Technical Leader|Software Engineer|Quality Assurance|Technical Writer|Customer|
|-----|---------------|---------------|----------------|-----------------|------------------|-----------------|--------|
|Project brief|I|I|I|I|I|I|R / A|
|Project charter|R / A|C / I|C/I|C / I|C / I|C / I|C / I|
|Task schedule|R / A|C|C / I|C / I|C / I|C / I|I|
|Code|I|I|C|R / A|C|C|X|
|Code review|C / I|C / I|R / A|R|C / I|C / I|X|
|Code documentation|C / I|I|C|R / A|C|C|X|
|Test planning|C / I|I|A|C / I|R / A|C|X|
|Test execution|C / I|I|I|C / I|R / A|C|X|
|User manual|C / I|I|C|C|C|R / A|I|

Legend:

|Letter|Name|Description|
|------|----|-----------|
|R|Responsible|The person who does the work to achieve the task. There should be exactly one person with this assignment for each task.|
|A|Accountable|The person who is accountable for the correct and thorough completion of the task.|
|C|Consulted|The people who provide information for the project.|
|I|Informed|The people who are kept informed of the project's progress.|
|X|Not applicable|The task is not applicable to the person or role.|

## MoSCoW

| Must Have| Should Have | Could Have | Won't Have |
| -------- | ----------- | ---------- | ---------- |
| - Battery lifespan of seven days <br> - Manage all security issues <br> - Shock detection <br> - Unlock the device | - Unlock the device with NFC <br> - Shock notification|X| - GNSS position acquisition <br> - Activate/Desactivate by app|

## Target Key Performace Indicators

| KPI | Description | Target |
| --- | ----------- | ------ |
| Battery lifespan | The battery must last at least 7 days | 7 days |
| Security | The device must be able to manage all security issues | 99% |
| Unlock the device with NFC | The device must be able to unlock with NFC | 99% |
| Shock notification | The device must be able to send a notification when a shock is detected | 95% |
| GNSS position acquisition | The device must be able to acquire the GNSS position | 80% |

These target KPIs are based on the client's requirements.

## Statement of work
