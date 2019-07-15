# Project-Drushti
Navigational guide for a physically challenged person.

This project is an IoT based project which focuses on providing aid to a visually impaired person through voice commands and beep signals which are present in the shoe of the person.
It comprises of an Arduino microcontroller and a Node MCU as the working brains.
It contains 2 ultrasonic sensors on each foot which track the front and the left/right hand side obstructions which are present.
Underneath the shoe is present a near IR proximity sensor for the detection of potholes on the ground (both empty or filled with any dirt).
It contains a GPS Module which tracks the location of the user who is wearing the shoes for this purpose a node MCU has been used to relay the locations of the GPS to the mobile phone of a concerned relative via message in case some emergency occurs.

The code for the arduino contains the control paramters under which the sensors mentioned above should be working to provide a seamless concurrency in their operation.
It is configured to produce a beep sound along with the direction in which the obstacle is present to the user.

The app for this has been developed on android platform. It collects the data which is provided by the sensors and relays it to the phone using bluetooth module and from there the android code picks up the data and further processing is done.

Future enhancement 
- To provide a protective covering to prevent the damage to the sensors and other important materials on the shoe.
- To implement a method through which a data map of all the locations of potholes are created on the internet as and when recorded   by any device in current usage.
- To implement crowd sourcing to analyse he kind of challenges that come up when such a device has been put to use in highly crowded areas and how to tune the parameters of the sensors for easy usage in such areas.
