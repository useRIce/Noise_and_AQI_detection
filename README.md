# IoT Air & Sound Pollution Monitoring System

I..Overview
The **IoT Air & Sound Pollution Monitoring System** is a real-time monitoring solution that measures air quality and sound levels using an ESP32 microcontroller. This system utilizes an LM393 sound sensor and an MQ135 gas sensor to collect data, which is displayed locally on a 16x2 LCD screen and sent to the ThingSpeak platform for remote monitoring and analysis.

---
II.. Features
- **Real-time monitoring** of air quality (in AQI) and sound levels (in dB).
- **IoT-enabled**: Data visualization and analysis using ThingSpeak.
- **Local display**: 16x2 LCD screen for on-site monitoring.
- **Customizable alerts**: Define thresholds for pollution and noise levels.
- **Scalable and portable**: Ideal for homes, offices, and public spaces.

---
III.. Components Used
1. **ESP32 Microcontroller**  
   - Provides Wi-Fi connectivity and acts as the processing hub.
2. **LM393 Sound Sensor**  
   - Measures sound levels in decibels (dB).
3. **MQ135 Gas Sensor**  
   - Detects air pollutants and measures air quality (ppm/AQI).
4. **16x2 LCD Display**  
   - Displays the real-time readings.
5. **Power Source**  
   - USB power or a 3.7V Li-ion battery.

---

IV... Circuit Diagram
[Attach or link to a circuit diagram showing component connections.]


---

V.. Setup Instructions
### Hardware Setup:
1. Connect the LM393 sound sensor and MQ135 gas sensor to the ESP32 analog pins.
2. Connect the 16x2 LCD to the ESP32 via I2C or direct GPIO pins.
3. Power the ESP32 using a USB cable or battery.

### Software Setup:
1. Install **PlatformIO**:
   - Download and install the [PlatformIO IDE](https://platformio.org/).
   - Set up PlatformIO in your preferred IDE (e.g., Visual Studio Code).

3. Use ThingSpeak:
   - Create a [ThingSpeak account](https://thingspeak.com/).
   - Set up a new channel and note the **Channel ID** and **API Key**.
   - Update the project code with your Wi-Fi credentials and ThingSpeak API key.

4. Upload Code:
   - Connect the ESP32 to your computer and upload the code using PlatformIO.
   - Verify that data is displayed on the LCD and sent to ThingSpeak.

---

VI.. Example
   - AQI
     ![Screenshot 2025-01-14 223534](https://github.com/user-attachments/assets/20850a00-5e24-4230-ae76-2782124a3b74)
     
   - Noice
   ![Screenshot 2025-01-14 223602](https://github.com/user-attachments/assets/8402040e-dbfd-4c1a-bf10-bfe80fd4bc1c)


---

VII.. Future Enhancements
- Add particulate matter sensors (e.g., PM2.5, PM10).
- Enable mobile alerts via email or SMS for critical thresholds.
- Implement solar-powered operation for off-grid use.
- Enhance ThingSpeak dashboards with advanced analytics.

---

VIII.. Acknowledgments
Thanks to the PlatformIO and ThingSpeak communities for their resources and tools that made this project possible.


