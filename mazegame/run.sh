#!/bin/bash

# Start Xvfb
Xvfb :99 -screen 0 640x480x24 &
XVFB_PID=$!

# Export DISPLAY variable
export DISPLAY=:99

# Set XDG_RUNTIME_DIR environment variable
export XDG_RUNTIME_DIR=/tmp/runtime-$(id -u)
mkdir -p $XDG_RUNTIME_DIR
chmod 700 $XDG_RUNTIME_DIR

# Run the game
./mazegame assets/maps/map.txt

# Kill Xvfb after the game exits
kill $XVFB_PID
