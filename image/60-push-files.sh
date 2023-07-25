#!/bin/sh

sshpass -p root scp -P 5555 -r ./backup root@localhost:/
