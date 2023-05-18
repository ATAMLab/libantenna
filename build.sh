#!/bin/bash
pyinstaller --onefile main.py --name antenna
rm -rf *.spec
mv ./dist/antenna ./