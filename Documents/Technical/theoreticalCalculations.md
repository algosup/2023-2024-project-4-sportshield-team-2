# Theoretical Calculation

This document aims to find the best way to optimize the battery by the theoretical way based on component specifications and without any test due to defaulter components.

<details>
<summary>Table of content</summary>

- [Theoretical Calculation](#theoretical-calculation)
  - [Components](#components)
  - [Work type consumption](#work-type-consumption)
    - [Buzzer consumption](#buzzer-consumption)
    - [SIM Module consumption](#sim-module-consumption)
      - [Working](#working)
      - [Sleep mode](#sleep-mode)
      - [Sleep mode minus data sending](#sleep-mode-minus-data-sending)
    - [Full calculations](#full-calculations)
  - [Online Documentation](#online-documentation)
    - [Xiao BLE Sense nrf52840](#xiao-ble-sense-nrf52840)
    - [GNSS PA1010D](#gnss-pa1010d)
    - [GSM/2G SIM800L](#gsm2g-sim800l)
    - [Electromagnet](#electromagnet)
    - [Piezoelectric Buzzer](#piezoelectric-buzzer)
    - [Molex 1462360031](#molex-1462360031)

</details>

## Components

| Name                 | Reference                                           | Battery Voltage | Battery Consumption per hour                                                                                                                   | description                                      |
| -------------------- | --------------------------------------------------- | --------------- | --------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------ |
| **micro-controller** | [Xiao BLE Sense nrf52840](#xiao-ble-sense-nrf52840) | 3.3V            | **200mA** -> Operating mode<br>**5µA** -> In deep sleep mode                                                                            | The main component                               |
| **GPS**              | [GNSS PA1010D](#gnss-pa1010d)                       | 3.3V-5V         | **30mA** (average)<br>**28mA** -> Acquisition<br>**36mA** -> Tracking<br>**18µA** ->sleep mode                                          | The GPS                                          |
| **SIM Module**       | [GSM/2G SIM800L](#gsm2g-sim800l)                    | 3.7-4.2         | **2.0 mA** -> Sleep mode<br>**7.0mA** -> empty mode<br>**350mA** (Average) -> Transmission GSM<br>**2000mA** (Peek) -> Transmission GSM | To send and received data through the 2G network |
| **Electromagnet**    | [N/A](#electromagnet)                               | 12V             | **350mA**-**500mA**                                                                                                                     |                                                  |
| **Buzzer**           | [Piezoelectric buzzer](#piezoelectric-buzzer)       | 3-24V           | **10mA** (Maximum)                                                                                                                      | The piece making noise                           |
| **NFC antenna**      | [Molex 1462360031](#molex-1462360031)               | 3-12V           | None                                                                                                                                    | To receive a NFC signal                          |

## Work type consumption

Based on a Work type of 6 hours and a sleep time of 18 hours.

### Buzzer consumption

The buzzer consume 10mA/h.
10 / 60 = 0,16mA/minute
0,16 / 60 = 0,0027mA/second = 2,7µA/second

| Alarm Type | Number of signal | activation time | rest time | total activation time | consumption |
| ---------- | ---------------- | --------------- | --------- | --------------------- | ----------- |
| **Short**  | 2                | 0.5s            | 0.5s      | **1s**                | **2,7µA**       |
| **Medium** | 4                | 1s              | 0.5s      | **4s**                | **10,8µA**      |
| **High**   | 10               | 5s              | 1s        | **50s**               | **135µA**       |

### SIM Module consumption

#### Working

SIM 800L consume ~350mA/hour for data sending.
350 / 60 = 5,83mA/minute
5,83 / 60 = 0,097mA/second = 97µA/second

Based on a 3s data sending.
97µA x 3 = 291µA

During work time we send data every 15 minutes.

1 hour = 60 minutes
60 / 15 = 4
4 x 291µA = 1,16mA/h
3 x 4 = 12 seconds of activations/hour

#### Sleep mode

SIM 800L consume 2mA/hour

2/60 = 0,033 mA = 33µA/minute
33 / 60 = 0,55µA

During sleep mode we only send data 1 time per hour.

#### Sleep mode minus data sending

**Sleep mode**
3 x 0,55 = 1,65µA
2mA - 0,00165 = 1,99835mA/h

**Work Mode**
12 x 0,55 = 6,6µA
2mA - 0,0066 = 1,9934mA/h

### Full calculations

**full work (Average)** => 200mA + 30mA + 350mA + 425mA + 10mA = 725 mA/h
**full work (max)** => 200mA + 36mA + 350 mA + 500mA + 10mA = 1096mA/h
**sleep mode (without data sending)** => Xiao BLE + GNSS + SIM Module => 5µA + 18µA + 2mA = 2.023mA/h
**calm work time** => Xiao BLE + GNSS + SIM Module (sleeping) + SIM module (activated - 3s/sending - 12s in total) => 5µA + 28mA + 1,9934mA + 1,16mA = 31,1584mA/h
**sleep mode** => Xiao BLE + GNSS + SIM module (sleeping) + SIM Module (activated - 3s/sending) => 5µA + 18µA + 1,99835mA + 291µA = 2,31235mA/h

The electromagnet and alarms haven't been taken into consideration, cause their consumption depends on how many times you will trigger them by default their consumption is 0 if you don't trigger them.

Based on 6 hours of work and 18 hours of sleep.

6 x 31,1584 = 186,9504mA
18 x 2,31235 = 41,6223mA

186,9504 + 41,6223 = 228,5727mA

We have a total consumption of 228,5727mA per day.

With the provided battery of 1100mA the device can be used for approximately 4,8 days.
With our own battery of 3700mA the device can be used for approximately 16,1 days.

## Online Documentation

### Xiao BLE Sense nrf52840

- **Processor:** Nordic nRF52840 - ARM® Cortex®-M4 with FPU runs up to 64 MHz
- **Wireless:** Bluetooth 5.0/NFC
- **On-chip Memory:** 1 MB flash and 256 kB RAM
- **Onboard Memory:** 2 MB QSPI flash
- **Interfaces:**
  - 1x UART
  - 1x I2C
  - 1x SPI
  - 1x NFC
  - 1xSWD
  - 11x GPIO (PWM)
  - 6x ADC
- **Power:**
  - Operating Voltage: 3.3V@200mA
  - Charging Current: 50mA/100mA
  - Input Voltage: 5VDC
  - Standby power consumption: <5μA

**source:** [KIWI electronics](https://www.kiwi-electronics.com/en/seeed-studio-xiao-nrf52840-11041)

### GNSS PA1010D

- Support for GPS, GLONASS, GALILEO, QZSS
- -165 dBm sensitivity, up to 10 Hz updates
- Up to 210 PRN channels with 99 search channels and 33 simultaneous tracking channels
- 5V friendly design and only 30mA current draw
- Breadboard-able, with 4 mounting holes
- UART and I2C interfaces, pick whichever you like most!
- RTC battery-compatible
- PPS output on fix ±20ns jitter
- Internal patch antenna
- Low-power and standby mode with WAKE pin

**Source:** [Adafruit](https://www.adafruit.com/product/4415)

- Built-in 10x10x4.0mm ceramic patch antenna on the top of module
- Ultra-High Sensitivity: -165dBm (w/o patch antenna), up to 45dB C/N of SVs in open sky reception.
- AlwaysLocate: Intelligent Algorithm (Advance Power Periodic Mode) for power saving
- EASY: Self-Generated Orbit Prediction for instant positioning fix
- GPS Consumption current(@3.3V):
- Acquisition: 36mA Typical
- Tracking: 28mA Typical
- High accuracy 1-PPS timing support for Timing Applications (±20ns jitter)
- High Update Rate: up to 10Hz(note1)
- Logger function Embedded(note2)
- Supports QZSS, SBAS(WAAS, EGNOS, GAGAN, MSAS) ranging
- Ultra-High Sensitivity: -165dBm
- Automatic antenna switching function
- Interface: UART, I2C

**Source:** [Adafruit P1010D DataSheet](https://cdn-learn.adafruit.com/assets/assets/000/084/295/original/CD_PA1010D_Datasheet_v.03.pdf?1573833002)

### GSM/2G SIM800L

**Chip**: SIM800L
**Voltage**: 3.7-4.2V
**Support networks**: China Mobile, China Unicom and global quad-band network
**Module size**: 2.5cmx2.3cm

TTL serial port for serial port, you can link directly to the microcontroller. No need MAX232 Power module automatically boot, homing network Onboard signal lights all the way. It flashes slowly when there is a signal, it flashes quickly when there is no signal NOTE: The pins are golden or grey one, we send them by ramdonly

**Source:** [Kuongshun](https://www.kuongshun-ks.com/uno/uno-board-shield/smallest-sim800l-gprs-gsm-module-microsim-card-cor.html)

- **Supply voltage:** 3,8V - 4,2V
- **Recommended supply voltage:** 4V
- **Power consumption:**
  - sleep mode <2.0mA
  - Empty mod <7.0mA
- **GSM transmission (average):** 350 mA
- **GSM transmission (peek):** 2000mA
- **Module size:** 25 x 23 mm
- **Interface:** UART (maks. 2.8V) ve AT commands
- **SIM card socket:** microSIM (underside)
- **Supported frequencies:** Quad Band (850/950/1800/1900 MHz)
- **Antenna connection:** IPX
- **Status signal:** LED
- **Operating temperature range:** -40 ila + 85 ° C
- ATE0
- AT+IPR=9600  
- ATE0&W
- Code to be given for all baud rate Operation
- AT+IPR=0

**Source:** [robotistan](https://www.robotistan.com/sim800l-gprs-module)

### Electromagnet

No real information was found due to an unknown brand and make.
But I found some sources of similar items.

**Source:**

- [Walmart](https://www.walmart.com/ip/Electronic-Latch-Lock-Catch-Door-12V-Electro-magnet-Release-Solenoid-Slant-Slug/5283466766?from=/search)
- [emag.ro](https://www.emag.ro/electromagnet-cu-bolt-retractabil-ajmaker-12v-0-35a-32x27x27-mm-z000612/pd/D2FQLHYBM/)
- [ebay](https://www.ebay.com/itm/154024886231)
- [Amazon](https://www.amazon.in/DIY-Crafts-Solenoid-Electromagnetic-Electric/dp/B07V5NXWSC)
- [Amazon](https://www.amazon.com.au/Atoplee-Electric-Assembly-Solenoid-27X29X18mm/dp/B01FH1JCPU?th=1)

### Piezoelectric Buzzer

**Model:** 2312  
**Colour:** Black.
**Diameter:** 23 mm.  
**Height:** 12 mm.  
**Cable length:** 100 mm.  
**Sound pressure level:** 85 to 95 decibels.  
**Nominal voltage:** 12 VDC.  
**Operating voltage range:** 3V-24V.  
**Maximum current:** 10 mA.  
**Weight:** 3g (approximately)

**Source:**  [Amazon](https://www.amazon.com/Buzzer-piezoelectric-Electronic-Audible-Continuous/dp/B09XCYY7C2)

### Molex 1462360031

It doesn't consume any ampere by itself it depends on the connected device.
The connector typically operates with a voltage range of around 3 to 12 volts. (no documentation to confirm)
