
#Smart Aquarium Monitoring
The "Smart_Aquarium_Monitoring" project enables the monitoring of various parameters in an aquarium using an ESP32 board and the ThingSpeak IoT platform. The project periodically measures and publishes temperature, pH, and flow rate readings to a specified ThingSpeak channel.

#Dependencies
WiFi library
ThingSpeak library

#Configuration
Set the SSID and password variables (SSID and password) to match your Wi-Fi network credentials.
Assign your ThingSpeak channel number and write the API key to the variables myChannelNumber and myWriteAPIKey, respectively.
Adjust the timer delay (timerDelay) to set the interval between readings and updates.

#Operation
The code initializes the serial communication and sets the ESP32 in Wi-Fi station mode.
The ThingSpeak library is initialized using the begin function.
In the loop function, the code checks if the specified time interval (timerDelay) has elapsed since the last reading and update.
If the interval has passed, the code attempts to connect or reconnect to Wi-Fi if necessary.
Temperature, pH, and flow rate readings are simulated and stored in the respective variables (temperatureC, pH, flow).
The values are set in the ThingSpeak fields using the setField function.
The writeFields function is called to publish the data to the ThingSpeak channel.
The HTTP response code is checked, and a corresponding message is printed to the serial monitor.

#Usage
Set up the ESP32 board and connect it to the Wi-Fi network.
Create a ThingSpeak channel and obtain the channel number and write API key.
Upload the code to the ESP32 board.
Open the serial monitor to view the temperature, pH, and flow rate readings, as well as the status of the channel update.
