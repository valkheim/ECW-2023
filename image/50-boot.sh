#!/bin/sh

# start qemu monitor with:
# socat -,echo=0,icanon=0 unix-connect:qemu-monitor-socket

qemu-system-x86_64 \
  -m 1024\
  -enable-kvm \
  -hda alpine.qcow2 \
  -device e1000,netdev=net0 \
  -netdev user,id=net0,hostfwd=tcp::5555-:22,hostfwd=udp::9999-:9999 \
  -object filter-dump,id=id,netdev=net0,file=./trace.pcap \
  -monitor unix:qemu-monitor-socket,server,nowait
