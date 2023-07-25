Let's take a look at the infected image:

```console
$ tar zxvf infected.tgz
infected.img
$ xxd -l 512 infected.img
00000000: fa31 c08e d88e d0bc 0020 89e5 fbe8 d900  .1....... ......
00000010: bb25 7ce8 f800 bb53 7ce8 f200 bb94 7ce8  .%|....S|.....|.
00000020: ec00 e9b8 000a 204f 6f6f 7073 2c20 796f  ...... Ooops, yo
00000030: 7572 2069 6d70 6f72 7461 6e74 2066 696c  ur important fil
00000040: 6573 2061 7265 2065 6e63 7279 7074 6564  es are encrypted
00000050: 210a 000a 2054 6f20 6465 6372 7970 7420  !... To decrypt 
00000060: 7365 6e64 2031 2e35 2042 5443 2074 6f20  send 1.5 BTC to 
00000070: 6d70 3979 6145 7a75 796d 344c 4548 3364  mp9yaEzuym4LEH3d
00000080: 7278 6544 5331 7053 5172 4b69 4a7a 4a69  rxeDS1pSQrKiJzJi
00000090: 314d 0a00 0a20 5468 656e 2065 6d61 696c  1M... Then email
000000a0: 2075 7320 6174 2063 6f6e 7461 6374 4065   us at contact@e
000000b0: 7669 6c63 6f72 702e 636f 6d20 7769 7468  vilcorp.com with
000000c0: 2079 6f75 2070 6572 736f 6e61 6c20 4944   you personal ID
000000d0: 3a20 6e47 5139 7846 3834 430a 0031 c0cd  : nGQ9xF84C..1..
000000e0: 16cd 1968 00f0 6af0 cb50 b803 00cd 1058  ...h..j..P.....X
000000f0: c350 b40e b00d cd10 b00a cd10 58c3 60b4  .P..........X.`.
00000100: 0e8a 073c 0074 05cd 1043 ebf5 61c3 e8ed  ...<.t...C..a...
00000110: ffe8 ddff c3ff ffff ffff ffff ffff ffff  ................
00000120: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000130: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000140: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000150: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000160: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000170: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000180: ffff ffff ffff ffff ffff ffff ffff ffff  ................
00000190: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001a0: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001b0: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001c0: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001d0: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001e0: ffff ffff ffff ffff ffff ffff ffff ffff  ................
000001f0: ffff ffff ffff ffff ffff ffff ffff 55aa  ..............U.
```

When launching (`qemu-system-x86_64 -hda infected.img`) the image, we indeed
are launching an infected machine:

![](./img/infected.png)

The `testdisk` utility can both write a standard MBR code and reconstruct the
partition table.

```console
$ cp infected.img bootable.img
$ testdisk bootable.img
```

[find partitions and fix the partition table]
[repair mbr bootloader code]

After running it, here is the code obtained that allows us to
boot the system again:

```
$ xxd -l 512 bootable.img
00000000: fc31 c08e d031 e48e d88e c0be 007c bf00  .1...1.......|..
00000010: 06b9 0001 f3a5 beee 07b0 08ea 2006 0000  ............ ...
00000020: 803e b307 ff75 0488 16b3 0780 3c00 7404  .>...u......<.t.
00000030: 0806 af07 83ee 10d0 e873 f090 9090 9090  .........s......
00000040: 9090 9090 9090 9090 9090 9090 9090 9090  ................
00000050: 9090 9090 9090 9090 9090 9090 9090 9090  ................
00000060: 9090 9090 9090 9090 9090 9090 9090 9090  ................
00000070: 9090 9090 9090 9090 9090 9090 9090 bebe  ................
00000080: 07b0 00b9 0400 803c 0075 6efe c083 c610  .......<.un.....
00000090: e2f4 31db b40e be9d 078a 0eaf 07ac d0e9  ..1.............
000000a0: 7302 cd10 08c9 75f5 b03a cd10 31c0 cd16  s.....u..:..1...
000000b0: 3c00 74f8 be8b 07b9 0200 e8ba 003c 0d74  <.t..........<.t
000000c0: b43c 6172 063c 7a77 022c 2088 c3be 9d07  .<ar.<zw., .....
000000d0: 8a0e af07 acd0 e973 0438 c374 0608 c975  .......s.8.t...u
000000e0: f3eb afb8 0d0e 31db cd10 8d84 6200 3c07  ......1.....b.<.
000000f0: 7507 b01f a2af 07eb 9931 d2b9 0100 3c04  u........1....<.
00000100: 7411 73f3 30e4 b104 d2e0 bebe 0701 c68a  t.s.0...........
00000110: 16b3 07bf 0500 56f6 c280 7431 b441 bbaa  ......V...t1.A..
00000120: 5552 cd13 5a5e 5672 1e81 fb55 aa75 18f6  UR..Z^Vr...U.u..
00000130: c101 7413 8b44 088b 5c0a be8d 0789 4408  ..t..D..\.....D.
00000140: 895c 0ab4 42eb 0c8a 7401 8b4c 02b8 0102  .\..B...t..L....
00000150: bb00 7c50 c606 8f07 01cd 1358 5e73 054f  ..|P.......X^s.O
00000160: 75b4 eb93 813e fe7d 55aa 75f6 ea00 7c00  u....>.}U.u...|.
00000170: 00be 8307 b90a 0050 b40e 31db accd 10e2  .......P..1.....
00000180: fb58 c354 6573 7444 6973 6b0d 0a10 0001  .X.TestDisk.....
00000190: 0000 7c00 0000 0000 0000 0000 0031 3233  ..|..........123
000001a0: 3446 0000 414e 4454 6d62 7200 0202 021f  4F..ANDTmbr.....
000001b0: c700 0080 0000 0000 ffff ffff ffff 8020  ............... 
000001c0: 2100 83df 130c 0008 0000 0020 0300 00df  !.......... ....
000001d0: 140c 8225 174e 0028 0300 0000 1000 0025  ...%.N.(.......%
000001e0: 184e 8315 5005 0028 1300 00d8 2c00 0000  .N..P..(....,...
000001f0: 0000 0000 0000 0000 0000 0000 0000 55aa  ..............U.
```

Using testdisk, we found an recovered the `/backup` folder but also discovered
some suspicious files under `/root`:

```console
$ ls -R recovery/
recovery/:
backup  root

recovery/backup:
Artists.csv  secrets.db.enc

recovery/root:
implant  key
```

The `/backup/Artists.csv` file looks clean, we can give it to John. However,
its secrets.db.enc looks like it has been encrypted, which John's doesn't remember about...

It looks like `/root/implant` is the malware we're looking for! There is also a `/root/key` file.

```console
/root$ file *
implant: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, stripped
key:     data
/root$ xxd key
00000000: 0ac8 6aa7 ce0f 9af6 fbff 91f9 c6d9 9dee  ..j.............
00000010: 9450 a659 a22e 0ddc b51b 1a27 2361 6b53  .P.Y.......'#akS
00000020: 4ca7 b6e4 3852 4edb bca3 79fa 53c9 0fcd  L...8RN...y.S...
00000030: d29a d806 630f 9a0c 04ab 584f 1d07 b7bc  ....c.....XO....
00000040: 64d7 a492 edac 647b f5f1 4a50 e162 46c6  d.....d{..JP.bF.
00000050: 3724 718a 957c 3c97 3b46 458d 2da7 d72e  7$q..|<.;FE.-...
00000060: a60e 6af8 4b29 b9f8 ed40 a4ec e333 99d7  ..j.K)...@...3..
00000070: 598e 8ee5 6517 02c6 7151 032a cb18 acca  Y...e...qQ.*....
00000080: 8449 8751 0017 0e82 6555 7717 aeeb 1501  .I.Q....eUw.....
00000090: f09e 0ffd de19 d0d6 f681 8862 a7be 26da  ...........b..&.
000000a0: daac 0c8a 92ef 64b6 a129 8566 1b17 23a1  ......d..).f..#.
000000b0: 8f42 c5c1 d08b 76e2 688f 2ee1 60f0 0072  .B....v.h...`..r
000000c0: 0168 2453 5b90 a8e7 5479 3e9f 4114 2d9a  .h$S[...Ty>.A.-.
000000d0: 0dfc f8f9 dd6b ed5f fe45 3040 92d2 aff4  .....k._.E0@....
000000e0: 858d d4f6 0ee5 c785 6f45 db84 77e5 3742  ........oE..w.7B
000000f0: 33ec 8c60 d9fd ae72 0989 83d4 53f5 f012  3..`...r....S...
```

There is no symbols but we can extract a lot of juicy strings from the implant:

```
shred -zuf key.bin
shred /etc/hosts
/root/secret
/user/secret
/root/backup
/user/backup
/dev/sda
/dev/hda
/dev/sdb
/dev/hdb
/dev/sdc
/dev/hdc
/dev/sdd
/dev/hdd
/dev/sde
/dev/hde
/dev/sdf
/dev/hdf
/dev/sdg
/dev/hdg
current domain is %s.%s
openssl enc -aes-256-cbc -salt -pbkdf2 -in 
 -out 
.enc -pass file:./key.bin
shred -uzf 
 Ooops, your important files are encrypted!
 To decrypt send 1.5 BTC to mp9yaEzuym4LEH3drxeDS1pSQrKiJzJi1M
 Then email us at contact@evilcorp.com with you personal ID: nGQ9xF84C
```

It looks like the files have been encrypted using a `key.bin` key file that was
then deleted using `shred`. It also looks like both `secret` and `backup` of
`root` and `user` folders have been targeted. Also there is a debug string
mentioning a domain. We suspect a domain name generation algorithm because the
`/etc/hosts` file also has been `shred`ded.

Our goal is to find the hackers, while reversing the implant, we indeed find a
domain name generation algorithm:

```
void __fastcall __noreturn sub_4011F1(unsigned int a1)
{
  __int64 v1; // rax
  __int64 v2; // rax
  __int64 v3; // rax
  unsigned int v4; // [rsp+8h] [rbp-2E0h] BYREF
  int cmd; // [rsp+Ch] [rbp-2DCh] BYREF
  char v6[32]; // [rsp+10h] [rbp-2D8h] BYREF
  __int16 v7[65]; // [rsp+30h] [rbp-2B8h] BYREF
  char v8[255]; // [rsp+B2h] [rbp-236h] BYREF
  char v9[311]; // [rsp+1B1h] [rbp-137h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      do
        v4 = 0x80;
      while ( recvfrom_4049E0(a1, &cmd, 4LL, 0LL, v7, &v4) != 4 );
      if ( !(unsigned int)getnameinfo_4025E0(v7, v4, (__int64)v8, 0xFFu, (__int64)v6, 0x20u, 2) )
      {
        generate_domain_401517();
        memset(v9, 0, 0xFFuLL);
        v1 = strcat_40A300((__int64)v9, (__int64)&g_domain_name);
        v2 = strcat_40A300(v1, (__int64)&string_dot_414000);
        v3 = strcat_40A300(v2, (__int64)&string_bzh_414002);
        if ( !(unsigned int)sub_40A440(v8, v3) )
          break;
      }
    }
    if ( !(unsigned int)sub_40A510(&cmd, "ABRT", 4LL) )
      abrt();
    if ( !(unsigned int)sub_40A510(&cmd, "NUKE", 4LL) )
      nuke();
    cmd = 4932417;
    sub_405AA0(a1, &cmd, 4LL, 0LL, v7, v4);
  }
}
```

The domain name is generated at generate_domain_401517 and is appended with a
dot at string_dot_414000 and a "bzh" TLD at string_bzh_414002.

Most of the job now is to reverse the generate_domain_401517 algorithm:

```
unsigned __int64 generate_domain_401517()
{
  int *v0; // rax
  __m128 day; // xmm1
  __m128 year; // xmm0
  char *domain; // rcx
  __m128 month; // xmm2
  unsigned __int64 v5; // xmm3_8
  unsigned __int64 result; // rax
  __int64 v7; // [rsp+8h] [rbp-10h] BYREF

  v7 = time_40B0C0(0LL);
  v0 = (int *)localtime_40B020(&v7);
  day = (__m128)(unsigned __int64)v0[3];
  year = (__m128)(unsigned __int64)(v0[5] + 1900);
  domain = (char *)&g_domain_name;
  month = (__m128)(unsigned __int64)(v0[4] + 1);
  do
  {
    ++domain;
    month = _mm_xor_ps(
              (__m128)_mm_slli_epi64((__m128i)_mm_and_ps(month, (__m128)xmmword_4141A0), 4u),
              (__m128)_mm_srli_epi64((__m128i)_mm_xor_ps((__m128)_mm_slli_epi64((__m128i)month, 2u), month), 1u));
    year = _mm_xor_ps(
             _mm_and_ps((__m128)_mm_slli_epi64((__m128i)year, 8u), (__m128)xmmword_4141B0),
             (__m128)_mm_srli_epi64((__m128i)_mm_xor_ps((__m128)_mm_slli_epi64((__m128i)year, 3u), year), 4u));
    day = _mm_xor_ps(
            _mm_and_ps((__m128)_mm_slli_epi64((__m128i)day, 4u), (__m128)xmmword_4141C0),
            (__m128)_mm_srli_epi64((__m128i)_mm_xor_ps((__m128)_mm_slli_epi64((__m128i)day, 0x10u), day), 2u));
    v5 = month.m128_u64[0] ^ year.m128_u64[0] ^ day.m128_u64[0];
    result = v5 / 0x19;
    *(domain - 1) = v5 % 0x19 + 97;
  }
  while ( (char *)&g_domain_name + 9 != domain );
  end_of_g_domain_name_41A631 = 0;
  return result;
}
```

The nine domain name characters are generated from a `struct tm` structure
obtained from the `localtime(time(NULL))` call. The assembly for the loop will
help us better than the decompiler to recover the DGA:

```assembly
loc_401577:
movaps  xmm7, xmm2      ; Move Aligned Four Packed Single-FP
movaps  xmm3, cs:xmmword_4141A0 ; Move Aligned Four Packed Single-FP
xor     edx, edx        ; Logical Exclusive OR
inc     rcx             ; Increment by 1
psllq   xmm7, 2         ; Packed Shift Left Logical (Qword)
movaps  xmm6, xmm7      ; Move Aligned Four Packed Single-FP
movaps  xmm7, xmm0      ; Move Aligned Four Packed Single-FP
xorps   xmm6, xmm2      ; Bitwise Logical XOR for Single-FP Data
psllq   xmm7, 3         ; Packed Shift Left Logical (Qword)
andps   xmm2, xmm3      ; Bitwise Logical And for Single-FP
psrlq   xmm6, 1         ; Packed Shift Right Logical (Qword)
psllq   xmm2, 4         ; Packed Shift Left Logical (Qword)
movaps  xmm3, xmm7      ; Move Aligned Four Packed Single-FP
xorps   xmm2, xmm6      ; Bitwise Logical XOR for Single-FP Data
xorps   xmm3, xmm0      ; Bitwise Logical XOR for Single-FP Data
movaps  xmm6, xmm1      ; Move Aligned Four Packed Single-FP
psllq   xmm0, 8         ; Packed Shift Left Logical (Qword)
psrlq   xmm3, 4         ; Packed Shift Right Logical (Qword)
movaps  xmm7, xmm2      ; Move Aligned Four Packed Single-FP
andps   xmm0, xmm5      ; Bitwise Logical And for Single-FP
psllq   xmm6, 10h       ; Packed Shift Left Logical (Qword)
xorps   xmm0, xmm3      ; Bitwise Logical XOR for Single-FP Data
movaps  xmm3, xmm6      ; Move Aligned Four Packed Single-FP
xorps   xmm3, xmm1      ; Bitwise Logical XOR for Single-FP Data
psllq   xmm1, 4         ; Packed Shift Left Logical (Qword)
xorps   xmm7, xmm0      ; Bitwise Logical XOR for Single-FP Data
psrlq   xmm3, 2         ; Packed Shift Right Logical (Qword)
andps   xmm1, xmm4      ; Bitwise Logical And for Single-FP
xorps   xmm1, xmm3      ; Bitwise Logical XOR for Single-FP Data
movaps  xmm3, xmm7      ; Move Aligned Four Packed Single-FP
xorps   xmm3, xmm1      ; Bitwise Logical XOR for Single-FP Data
movq    rax, xmm3       ; Move 64 bits
div     rsi             ; Unsigned Divide
add     edx, 61h ; 'a'  ; Add
mov     [rcx-1], dl
cmp     rdi, rcx        ; Compare Two Operands
jnz     loc_401577      ; Jump if Not Zero (ZF=0)
```

Here is a C transcript:

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <err.h>

int main(int ac, char**av)
{
    if (ac != 4)
        errx(EXIT_FAILURE, "usage: %s <month> <day> <year>\n", av[0]);

    char subdomain[10];
    uint64_t month = (uint64_t)atoi(av[1]);
    uint64_t day = (uint64_t)atoi(av[2]);
    uint64_t year = (uint64_t)atoi(av[3]);
    for(unsigned i = 0 ; i < sizeof(subdomain) - 1; ++i)
    {
        month = ((month ^ 4 * month) >> 1) ^ 16 * (month & 0xFFFFFFF2);
        year = ((year ^ 8 * year) >> 4) ^ ((year & 0xFFFFFFF4) << 8);
        day = ((day ^ (day << 16)) >> 2) ^ ((day & 0xFFFFFFFA) << 4);
        subdomain[i] = (char)(((year ^ month ^ day) % 25) + 'a');
    }

    subdomain[sizeof(subdomain)-1] = 0;
    printf("subdomain: %s\n", subdomain);
}
```

With such algorithm, we are able to recover the domain name generated for the
date of the attack:

```
$ ./dga 07 26 2023
subdomain: uxigxmxvm
```

Now let's hack back those hackers at `uxigxmxvm.bzh`!

![](./img/tycon_leaks.png)

It's a static website leaking data from those hackers victims. Can we find
John's data over there? Definetly not, but we recovered a cryptographic key
using the unique identifier he was given in his corrupted bootloader:

`uxigxmxvm.bzh/files/nGQ9xF84C/key.pem`

```console
$ wget uxigxmxvm.bzh/files/nGQ9xF84C/key.pem
$ cat key.pem
-----BEGIN PRIVATE KEY-----
MIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQDChc3ubr7clJtt
RGVTIKmaZdRDMETKZIOLIehLH3U52QJ1Xa1ruZ+PC1BKWVNPqS/E3x9p5CSec6Ba
nJtn7KI1m7Qxu8uCtkr8xCZ1jFge1KYmYh4u21r7fJzdXM9qyxgML3knKi4GV0BA
clZ6UXX6m/432CzufbmDhMRSd7XfdQed8X2SK7gwtePOmqY4AmnRl9ozLtR+qTff
sv5FtZQcxyA5FHR9MQlTaYzg+mKrvtax+vKZg+INfolQobXKoi17nLwHhZ5Ow8Ha
xyLkqMfBC3hej6qo2yBY5JzxgIGhufjXV1F82IbFFx6B7JY2hmvhjiAG4dqfkHWw
q+ojOYoVAgMBAAECggEAHvLAjEuaBH3aP/yumEFX6o+Clrv9EyxXEhGaI9WZ8NME
xUfbBGAbMYbNxpPGoaPGd1k+Zg+yVHQLUk9HRGC4KrTz6tO43GTaB7QXda1CBIm1
nja5xvUHA9WpdBNE5stFhK7K5OnHj80IP8NRMeh4T5/LnEvsU3dfnBFJVjY4kpgE
tXsZxBU8NaR6XtZEx1ohtUwVMZth4ZMgNs1b24acQaH0KK40sG8sbzqhdA2Qk+cQ
XKPyji6uS4stzpxQrgC4eyD2aM/Oq0g7zSf+HfhCY03Fvx97G4rDRtpP4KIW2Htg
gkoaVwOBXiNsqMD935n09Xwplk9Lawioe/f8LQEQQwKBgQDsr6SLMDn4oMQFombN
lgKcejI93XDOHpJS9Oxh/Y6yLdAeQUaLUX7DfR90XiTLRuP6BiljWN8Dh66nrklo
JBYUW1FIZeqL2Woa14BT0MZN14x0c3wunqR1zQWlGmwROc+phAJp/Y2Q/AyDDkrn
wvV01/tT0BJ+0jcfcI5gV134wwKBgQDSZV7Pf3GOD2kH5jjCBHWNXVf45UJktqjk
3I//rOfy4XO2bR8TKufo8mM8lOmRxsThpWgxnKjE+6qisSahqwObB9R73aebPFBq
KMCNOMsjj5+isuhhwaH5rtS1OUCBpM+mkjkZmua6tJtiH1UhEPUJoPmEf4+CcGF8
3RTW1jeERwKBgQCtHPKek1FzVjLJZDUI3VVfmcixkwt01stzPYy/RzNdg0CbQGcW
cy7iUNv2wvzqaRlJv8P51ACZll3aaxFpyCsWDIxxBYn9a7G9nC1SIHtKaANlESqc
9o+XUbN1RNQR7VTDybfySe+HQbLtEEEdLm1VXruGW8OLWrnSlwKr2Hr0/QKBgQDK
EK2UH1QSGd7HxWYxgFLd6A47bwPq8jsXQnXSGl/SNpEJXZgAsq50XYbNgj8o0Hv6
Mv/01f6I4SOqiPUPQ818sXJzXBhC0RRyQJ1dhHQkvSWV/rmMWYmU4UJMoqW/XWhJ
FBpe6xQ5sIejH3CFB2IvUzkQ9eoAXqpiX3pKMwaytQKBgQCYVJ5KtW20f9Ox7qJZ
2MDMu7L5gj/6C02fGN+bLLrudyxBcYvqiSzwE7Q5ZG6TRUGWSNASl9SqsK24MI2E
LdgAWInYleCS8Jali1wZtXGxtpvdRYlLiDtV58Qr7RBcpfLDVoAxyiCFtWearZqZ
AJbu+b9e33Z4SzI17gTHeRvcRw==
-----END PRIVATE KEY-----
```

On John's machine, the implant used a `key.bin` file for file encryption before
deleting it. However, it left a `key` file.

```console
$ openssl rsautl -decrypt -inkey key.pem -in recovery/root/key -out key.bin
$ cat key.bin
UyhXwZQ+cxB+QunKoBA2Nbzj5SfhoBVFtFUyoS25EMg=
```

It looks like we recovered the 256 bits key used for file encryption.
By looking at the implant strings, aes cbc was used, let's try that
on secrets.db.enc:

```console
$ openssl enc -d -aes-256-cbc -pbkdf2 -in recovery/backup/secrets.db.enc -out secrets.db -pass file:key.bin
$ file secrets.db 
secrets.db: SQLite 3.x database, last written using SQLite version 3038001
$ sqlite3 secrets.db .dump
PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE secrets(flag text not null);
INSERT INTO secrets VALUES('ECW{all_your_file_belong_to_us}');
COMMIT;
```

Awesome, here is your flag!