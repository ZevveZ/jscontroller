#! /bin/bash

EXECPATH=$PWD

# build JoystickLibrary
sudo apt-get update && sudo apt-get install cmake libudev-dev libevdev-dev -y
git clone https://github.com/WisconsinRobotics/JoystickLibrary.git
cd JoystickLibrary/cpp
mkdir build && cd build
cmake .. && make

# build jscontroller
cd $EXECPATH
mkdir build && cd build
qmake ../jscontroller.pro && make clean && make

