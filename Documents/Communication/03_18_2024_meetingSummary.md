# Meeting summary (03/18/2024)

- [Meeting summary (03/18/2024)](#meeting-summary-03182024)
  - [List of participant](#list-of-participant)
  - [Summary](#summary)
      - [Technical Questions](#technical-questions)
        - [How can we manage to work with the SIM card?](#how-can-we-manage-to-work-with-the-sim-card)
        - [Which kind of information do you have in your application?](#which-kind-of-information-do-you-have-in-your-application)
        - [What happen if data can't be sent?](#what-happen-if-data-cant-be-sent)
        - [Do you have something to ping the device?](#do-you-have-something-to-ping-the-device)
        - [How do we manage in low battery level situtation?](#how-do-we-manage-in-low-battery-level-situtation)
        - [What to do if components is malfunctioning?](#what-to-do-if-components-is-malfunctioning)
        - [How does the SIM forfait works?](#how-does-the-sim-forfait-works)
        - [Do we need to search by ourselves a library which can manage to our board or you already have a specific library to do that?](#do-we-need-to-search-by-ourselves-a-library-which-can-manage-to-our-board-or-you-already-have-a-specific-library-to-do-that)
        - [Can we use others library?](#can-we-use-others-library)
        - [It is the updated electronics circuit diagram?](#it-is-the-updated-electronics-circuit-diagram)
      - [Usage](#usage)
        - [What would a package contain? Like the device, a charger (USB-C?), anything else?](#what-would-a-package-contain-like-the-device-a-charger-usb-c-anything-else)
        - [Is the app expected to be available on Google Play Store and Apple App Store?](#is-the-app-expected-to-be-available-on-google-play-store-and-apple-app-store)
        - [Does it meet specific criteria to test robustness of the SportShield device, such as waterproofness, cold-resistance in these fields such as IP ratings?](#does-it-meet-specific-criteria-to-test-robustness-of-the-sportshield-device-such-as-waterproofness-cold-resistance-in-these-fields-such-as-ip-ratings)
        - [Are notifications (sent by the SportShield device) only supported by the app? Or should they be also sent by Bluetooth somehow?](#are-notifications-sent-by-the-sportshield-device-only-supported-by-the-app-or-should-they-be-also-sent-by-bluetooth-somehow)
        - [Do you have a mail or phone number for technical support? For example if my device isn't working, who can I email/call?](#do-you-have-a-mail-or-phone-number-for-technical-support-for-example-if-my-device-isnt-working-who-can-i-emailcall)


## List of participant

| Name              | Role             |
| ----------------- | ---------------- |
| Robin DEBRY       | Project Manager  |
| Elone DELILLE     | Technical Leader |
| Mathias GAGNEPAIN | Program Manager  |
| Florent ANON      | Customer         |

## Summary 

#### Technical Questions

##### How can we manage to work with the SIM card?
- The problem is complex, there is a lot of thing to take in consideration like the building isolation.
- The battery hasn't enough power to supply the SIM module.
- Can be caused by the reset button.
- The issue can also come from the module itself.
- Finally he told us to skip the part about the module assuming that it's working.

##### Which kind of information do you have in your application?
- Notification information about locking/unlocking.
- Gave us the Firebase App Distribution access, because it can be interesting to understand how it's works.
- The application on itself is not relevant for us.

##### What happen if data can't be sent? 
- At this stage nothing is implemented yet.
- Try to resend 3 to 5 times.
- After 5 minutes abandon data and continue the process.

##### Do you have something to ping the device?
- No, the idea is to keep the device the simpliest has possible.

##### How do we manage in low battery level situtation?
- Regarding battery in 0% level situation don't give the possiblity to switch on the device.
- The device need to inform the user in critical state before it switch off (under 15%).

##### What to do if components is malfunctioning?
- It's a relevant idea but try to keep the device as simpliest as possible.
- Possibility to trigger components malfunctioning at the board initialization.

##### How does the SIM forfait works?
- It's a 10 years forfait without renewal and we have 500MB and 250 SMS.

##### Do we need to search by ourselves a library which can manage to our board or you already have a specific library to do that?
- We can find it.
- They asked to seeds studio to do one for them.

##### Can we use others library?
- We can feel free to use different libraries.

##### It is the updated electronics circuit diagram?
- No, he will send us the updated version.

#### Usage

##### What would a package contain? Like the device, a charger (USB-C?), anything else?
- It's just a prototype they didn't thought about that yet.

##### Is the app expected to be available on Google Play Store and Apple App Store?
- Yes, they expect it will be available on both.

##### Does it meet specific criteria to test robustness of the SportShield device, such as waterproofness, cold-resistance in these fields such as IP ratings?
- No, it's just a prototype and it hasn't been tested in real condition.
- But it resistant to 2-3 meter height falling.

##### Are notifications (sent by the SportShield device) only supported by the app? Or should they be also sent by Bluetooth somehow?
- We can feel free to add some use cases but Bluetooth isn't relevant cause if the user is near to the device, he doesn't need to receive notifications.

##### Do you have a mail or phone number for technical support? For example if my device isn't working, who can I email/call?
- Yes, but not for now, it's too early to have a real plan of technical and client support.

<div align="center">
  <a href="https://algosup.com"><img alt="ALGOSUP Logo" src="../Functional/Img/ALGOSUP-logo.png" style="max-height:200px"></a>
  <a href="https://www.corisinnovation.com/"><img alt="Coris Innovation Logo" src="../Functional/Img/Coris-innovation-logo.png" style="max-height:200px"></a>
</div>