# mms-arduino

Write a Micromouse maze-solving algorithm with Arduino.

As in, run algorithm code on a physical Arduino board, rather than your computer.

For use with [mackorone/mms](https://github.com/mackorone/mms), a Micromouse simulator.

## Setup

1. Clone this repository
1. Connect your Arduino board and upload the `mms-arduino.ino` sketch
1. [Download the Micromouse simulator](https://github.com/mackorone/mms#download)
1. Run the simulator and click the "+" button to configure a new algorithm
1. Enter the config for your algorithm (name, directory, and run command)
1. Click the "Run" button

## Examples

Windows:

![](https://github.com/mackorone/mms-arduino/blob/master/config-windows.png)

Linux (Ubuntu):

![](https://github.com/mackorone/mms-arduino/blob/master/config-linux.png)

## How it works

1. The Arduino board sends a message to `Main.py`
1. `Main.py` forwards that message to the simulator
1. The simulator sends a response back to `Main.py`
1. `Main.py` forwards that response back to the Arduino board

![](https://github.com/mackorone/mms-arduino/blob/master/diagram.png)


## pySerial

The `Main.py` script uses
[`pySerial`](https://pyserial.readthedocs.io/en/latest/pyserial.html)
to communicate with a running Arduino.

To install on Windows:
```
python.exe -m pip install pyserial
```

To install on Linux:
```
sudo python -m pip install pyserial
```


## Notes

- You may need to download and install [Arduino](https://www.arduino.cc/en/main/software)
- You may need to download and install [Python](https://www.python.org/downloads/)
- Spaces in file paths are not allowed, you may need to change the default Python install path
- The `--port` argument can be found in the Arduino IDE via `Tools -> Port`
- The `--baud` argument needs to match `Serial.begin()` in `mms-arduino.ino`
- Make sure the Arduino board is connected to your computer before clicking "Run"
- After clicking "Run" it takes a few seconds for `Main.py` to establish a connection with the Arduino
- Descriptions of all available API methods can be found at [mackorone/mms#mouse-api](https://github.com/mackorone/mms#mouse-api)
- The example code is a simple left wall following algorithm
