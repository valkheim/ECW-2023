#!/bin/sh

# ABRT
# NUKE/NYAN

printf "$1" | nc -cu localhost 9999
exit 0
