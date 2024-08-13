# L76_GPS_Breakout_Software

The L76K GPS breakout board is a compact, high-performance GNSS module designed to provide precise and reliable positioning. It supports multiple satellite systems, including GPS, BeiDou, GLONASS, and QZSS, ensuring comprehensive coverage and accuracy. The breakout board offers flexible interfacing options, including direct access via onboard USB to TTL or through a TTL breakout header, making it ideal for a wide range of applications, from navigation and asset tracking to research and educational projects.

This Github provides a getting started guide and other working details for the L76 GPS module Breakout.

### Features:
- Breakout for L76K GNSS module which supports GPS, BeiDou, GLONASS, and QZSS for effective navigation
- Serial RX/TX and PPS pins breakout as standard 2.54” Header and SH 1mm connector for easy interfacing with microcontrollers
- Onboard USB-UART converter for direct use of module with PC/laptop to instantly read live location
- Type C interface
- Selection option available to switch between UART or USB access
- Coin cell CR1220/3V holder for preserving configuration and real-time-clock circuitry 
- Seamlessly interface with various hardware platform like Arduino, Raspberry Pi, Pico/Pico W, ESP32, STM32
  
### Specifications:
- Module: L76K breakout
- Supply Voltage: 5V
- Operating pin voltage: 3.3V
- Coin Cell: CR1220/3V [not included]
- L76K GNSS Module =>
	- Supports Multi-GNSS systems: GPS/GLONASS/BDS/QZSS
	- Protocol: NMEA 0183 
	- Accuracy of 1PPS Signal:  < 100 ns 
	- UART Communication Baud Rate: 4800 ~ 115200 bps (9600 bps by default)
	- L1 Band Receiver: 32 tracking ch/ 72 acquisition ch
	- Sensitivity: Acquisition -148dBm, Re-Acquisition -160dBm, Tracking -162dBm
	- TTFF (TIME TO FIRST FIX): 
	- For Cold Starts => 30s Autonomous, 5.5s AGNSS and for HOT Starts => 2s
	- GNSS DATA UPDATE RATE:  Max 5Hz (Default 1Hz)
	- Position Accuracy: 2.0m CEP
	- Speed Accuracy: 0.1m/s
	- Acceleration Accuracy(MAX): 0.1m/s²
	- Timing Accuracy: 30ns


### Hardware Overview
#### Pinout
<img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/L76_GPS_Breakout_Pinouts.png">


- **_Breakout Pins_**
  
  | L76 Breakout | Function |
  |---|---|
  | RX | Serial Receive UART pin |
  | TX | Serial Transmit UART pin |
  | PPS | Pulse Per Second Signal pin |
  | 5V | Positive 5V Supply | 
  | GND | Supply Ground Pin |

You have two options to use L76 GPS breakout 
  1) Standalone using Type C to get live location on PC/Laptop directly
  2) Interface with any Microcontroller using Serial UART pins

### Breakout Directly with PC/Laptop 
- For using breakout directly set selection option to USB using jumper as shown below and connect breakout to system using Type C,

  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/usb_selection.jpg" width="389" height="275">

- Now you will see device listed with COM port you can checkout in device manager
  
  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/device_manager_comport.jpg" width="583" height="426">

- To monitor GNSS data you can use any serial console terminal. For demo we have used XCTU which you can download from [official site here](https://hub.digi.com/support/products/xctu/).
  
  Select Tools > Serial console > configure

  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/xctu_1.jpg" width="600" height="451">

- Follow Setting as shown with suitable com port selection, maybe different in your case

  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/xctu_2.jpg" width="600" height="452">

- Close the connection, in some interval of time you will start getting Location data. Indicated by PPS Led blinking on breakout.
  
  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/console_gps_readings.jpg" width="1150" height="609">


- You can even use UCenter software for indepth analysis, which you can download from [official site here](https://www.u-blox.com/en/product/u-center)
  
  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/ucenter_view.jpg" width="" height="">

  **Note**: _You may face issue getting location indoor due to satellite search, place GPS antenna outdoor._  
  
### Interfacing with MCU
- For using breakout with microcontrollers set selection option to UART using jumper as shown below,
  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/uart_selection.jpg" width="389" height="275">

#### Interfacing Breakout with Arduino 
- Once you have set selection jumper properly for UART access, so now you can either use header or 5pin SH connector to interface with microcontroller
- We have used D7 and D8 digital pins of Arduino as SoftwareSerial, if you change make sure to update same in code as well.

  | Arduino | L76 Breakout | Function |
  |---|---|---|
  |D8 (TX) | RX | Serial UART connection |
  |D7 (RX) | TX  | Serial UART connection |
  |5V | 5V | Positive Supply connection |
  |GND | GND | Ground Supply connection |

- Connection ready, download [Demo Arduino code](https://github.com/sbcshop/L76_GPS_Breakout_Software/tree/main/examples/L76K_GNSS_Demo) for test reading GPS location. 
  
#### Interfacing Breakout with Pico/Pico W
- Follow below pin connection for interfacing breakout with Pico/Pico W microcontroller, again you can use either Header or SH breakout connector for interfacing.
    
  | Pico RP2040 | L76 Breakout | Function |
  |---|---|---|
  |GP4 (TXD1) | RX | Serial UART connection |
  |GP5 (RXD1) | TX  | Serial UART connection |
  |5V | 5V | Positive Supply connection |
  |GND | GND | Ground Supply connection |
  
- Once you are done with connection, now you can try gps examples available on Trekko Github => [Demo_GPS.py](https://github.com/sbcshop/Trekko_Software/blob/main/examples/Demo_GPS.py)
- Make sure to save library file [trekkoGPS.py](https://github.com/sbcshop/Trekko_Software/blob/main/examples/trekkoGPS.py) to your Pico/Pico W
- Everything all set then you can run script through IDE or save as main.py to your pico. To understand working with Thonny IDE for Pico, checkout Trekko [Github Here](https://github.com/sbcshop/Trekko_Software#2-running-first-program) 


#### Interfacing Breakout with Raspberry Pi
  - Follow the connection below to interface breakout with Raspberry Pi

    | Raspberry Pi | L76 Breakout | Function |
    |---|---|---|
    |UART0 TX | RX | Serial UART connection |
    |UART0 RX | TX  | Serial UART connection |
    |5V | 5V | Positive Supply connection |
    |GND | GND | Ground Supply connection |

  - Checkout [Github Here](https://github.com/sbcshop/GPS-Hat-for-Raspberry-Pi/tree/main#code) for Working examples.
  

## Resources
  * [Schematic](https://github.com/sbcshop/L76_GPS_Breakout_Hardware/blob/main/Design%20Data/Sch%20GPS%20L76K%20Breakout.pdf)
  * [Hardware Files](https://github.com/sbcshop/L76_GPS_Breakout_Hardware)
  * [Step File](https://github.com/sbcshop/L76_GPS_Breakout_Hardware/blob/main/Mechanical%20Data/GPS%20L76K.step)
  * [L76K GNSS Documents](https://github.com/sbcshop/L76_GPS_Breakout_Software/tree/main/Documents)


## Related Products
  * [GPS External Antenna](https://shop.sb-components.co.uk/products/gps-external-antenna?_pos=1&_sid=7f1c5cecc&_ss=r) 
   
     ![GPS_External_Antenna](https://shop.sb-components.co.uk/cdn/shop/products/GPSAntenna_2.jpg?v=1640588714&width=300)   

  * [GPS HAT for Raspberry Pi](https://shop.sb-components.co.uk/products/gps-hat-for-raspberry-pi?_pos=6&_sid=7f1c5cecc&_ss=r) 
   
     ![gps-hat-for-raspberry-pi](https://shop.sb-components.co.uk/cdn/shop/products/GPSHATforRaspberryPi_5.png?v=1648553361&width=300) 

  * [IoTFi 4G/2G : IoT Board based on RP2040](https://shop.sb-components.co.uk/products/iotfi-2g-4g-iot-board-based-on-rp2040?variant=40430002307155) 
   
     ![IoTFi 4G/2G : IoT Board based on RP2040](https://shop.sb-components.co.uk/cdn/shop/products/Untitled-2_1.png?v=1679651257&width=300)
    
  * [UBlox GPS-RTK Breakout](https://shop.sb-components.co.uk/products/gps-rtk-hat-gps-rtk-hat-with-high-precision-rtk-gps-location-at-the-cm-level?_pos=3&_sid=7f1c5cecc&_ss=r) 
   
     ![UBlox GPS-RTK Breakout](https://shop.sb-components.co.uk/cdn/shop/products/03_32836ef3-a3d3-4039-bbd2-14d97fb53879.png?v=1675245485&width=300) 

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
