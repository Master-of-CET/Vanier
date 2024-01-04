#!/bin/bash

echo "[Start of shutdown script!]"

echo "Enter time before shutdown (in minutes):"
read minutes

echo "System going down in $minutes minutes!"

shutdown -h +"$minutes"

echo "[End of shutdown script!]"

