# L76_GPS_Breakout_Software

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
  
  

### Interfacing with MCU
- For using breakout with microcontrollers set selection option to UART using jumper as shown below,
  <img src="https://github.com/sbcshop/L76_GPS_Breakout_Software/blob/main/images/uart_selection.jpg" width="389" height="275">

  
#### Interfacing Breakout with Pico/Pico W
  
  | Pico RP2040 | L76 Breakout | Function |
  |---|---|---|
  |GP4 (TXD1) | RX | Serial UART connection |
  |GP5 (RXD1) | TX  | Serial UART connection |
  |5V | 5V | Positive Supply connection |
  |GND | GND | Ground Supply connection |

	
#### Interfacing Breakout with Arduino 

  | Arduino | L76 Breakout | Function |
  |---|---|---|
  |GP4 (TXD1) | RX | Serial UART connection |
  |GP5 (RXD1) | TX  | Serial UART connection |
  |5V | 5V | Positive Supply connection |
  |GND | GND | Ground Supply connection |


#### Interfacing Breakout with Raspberry Pi
  - Follow the connection below to interface breakout with Raspberry Pi
    
  | Raspberry Pi | L76 Breakout | Function |
  |---|---|---|
  |GP4 (TXD1) | RX | Serial UART connection |
  |GP5 (RXD1) | TX  | Serial UART connection |
  |5V | 5V | Positive Supply connection |
  |GND | GND | Ground Supply connection |

  Checkout [Github Here](https://github.com/sbcshop/GPS-Hat-for-Raspberry-Pi) for Working and Examples


## Resources
  * [Schematic]()
  * [Hardware Files]()
  * [Step File]()
  * [L76K Module Datasheet]()


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
