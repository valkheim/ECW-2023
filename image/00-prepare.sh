ARCH="x86_64"
VER="3.15"
URL="https://dl-cdn.alpinelinux.org/alpine/v${VER}/releases/${ARCH}/alpine-virt-${VER}.0-${ARCH}.iso"
ISO=`basename $URL`

if [ ! -f $ISO ]; then
    curl -O $URL
    curl -O ${URL}.sha512
    SHA512=`cat *sha512 | awk '{print $1}'`
    SCHECK=`openssl dgst -sha512 alpine*.iso | awk '{print $2}'`
    if [ "${SHA512}" != "${SCHECK}" ]; then echo "[FATAL] Invalid hash: ${SCHECK}" >&2 && rm -f ${ISO}*; fi
fi


qemu-img create -f qcow2 alpine.qcow2 2G
qemu-system-x86_64 -m 512 -nic user -boot d -cdrom ${ISO} -hda alpine.qcow2
