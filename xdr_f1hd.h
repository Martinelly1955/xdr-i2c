#include <Arduino.h>

#define DSP_I2C                  0x38
#define IF_I2C                   0xC4

#define DSP_FALSE                0x000
#define DSP_TRUE                 0x7FF

#define DSP_RDS_STATUS           0x000030
#define DSP_RDS_DATA             0x000031
#define DSP_RDS_CONTROL          0x000035

#define DSP_FM_LEVEL_FAST        0x030092
#define DSP_FM_LEVEL             0x030097
#define DSP_FM_MULTIPATH         0x030099
#define DSP_AM_LEVEL             0x03006E
#define DSP_VOLUME_SCALER        0x031011
#define DSP_FORCE_MONO           0x031020
#define DSP_ST_19kHz             0x03102C
#define DSP_ST_THRESHOLD         0x03128D
#define DSP_DEEMPHASIS           0x0311D7

#define DSP_ULTRASONIC_NOISE     0x0100D2
#define TDSP1_X_CIBW_1_FirCtl    0x0101A1
#define TDSP1_X_CIBW_1_FirCtlFix 0x0101A2
#define TDSP1_X_CIBW_1_pFirCtl   0x0101A3
#define TDSP1_X_CIBW_4_FirCtl    0x0101A4
#define TDSP1_X_CIBW_4_FirCtlFix 0x0101A5
#define TDSP1_X_CIBW_4_pFirCtl   0x0101A6

#define IR_POWER                 0xA8BC8

// DSP initialization data
const uint8_t DSP_INIT[] PROGMEM =
{
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    5,0x03,0x10,0x09,0x00,0x00,
    6,0x00,0x00,0x20,0x02,0x09,0x7A,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x01,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x03,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x05,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x09,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x02,0x00,
    6,0x09,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x0D,0x0F,0xFD,0x00,0x00,0x00,
    6,0x00,0x00,0x10,0x00,0x00,0x00,
    6,0x09,0x01,0x5F,0x80,0x00,0x00,
    6,0x09,0x01,0x60,0x80,0x00,0x00,
    6,0x09,0x01,0x61,0x80,0x00,0x00,
    6,0x01,0x00,0x04,0x00,0x00,0x01,
    6,0x0D,0x0F,0xF6,0x01,0xB6,0xDB,
    6,0x0D,0x0F,0xF7,0x00,0xC0,0x3E,
    6,0x01,0x0F,0xF9,0x57,0xF3,0x55,
    6,0x00,0x00,0x20,0x02,0x09,0x7A,
    6,0x05,0x0F,0xF9,0x00,0x00,0x13,
//  5,0x03,0x12,0x8D,0x00,0x58, // stereo pilot threshold
    5,0x01,0x10,0x04,0x00,0x00,
    5,0x05,0x10,0x48,0x00,0x00,
    5,0x03,0x10,0x11,0x07,0xFF,
    5,0x0D,0x14,0x88,0x05,0x09,
    5,0x03,0x12,0x3B,0x05,0x2C,
    5,0x03,0x11,0x26,0x00,0xF6,
    5,0x03,0x11,0x27,0x0F,0xEB,
    5,0x05,0x10,0x19,0x00,0xF6,
    5,0x05,0x10,0x1A,0x0F,0xD9,
    5,0x03,0x11,0x38,0x0A,0x00,
    5,0x03,0x12,0x7A,0x00,0xF6,
    5,0x03,0x12,0x7B,0x0F,0xD9,
    5,0x05,0x10,0x86,0x00,0xE8,
    5,0x05,0x10,0x87,0x0F,0xC5,
    5,0x01,0x10,0x95,0x00,0x80,
    5,0x01,0x10,0x96,0x00,0x00,
    5,0x01,0x10,0x97,0x00,0x00,
    5,0x03,0x11,0xFD,0x07,0xFE,
    5,0x03,0x11,0xFE,0x00,0x01,
    5,0x03,0x12,0x29,0x05,0xB6,
    6,0x01,0x01,0xD1,0x00,0x10,0x22,
    6,0x01,0x01,0xD2,0x00,0x00,0xE5,
    7,0x03,0x12,0x25,0x06,0x34,0x07,0xFE,
    7,0x03,0x12,0x27,0x00,0xC4,0x00,0x01,
    5,0x05,0x10,0xC2,0x00,0x80,
    5,0x05,0x10,0xC3,0x00,0x00,
    5,0x05,0x10,0xC4,0x00,0x00,
    5,0x05,0x10,0xAA,0x05,0xB6,
    6,0x05,0x02,0xA1,0x00,0x10,0x22,
    6,0x05,0x02,0xA2,0x00,0x00,0xE5,
    7,0x05,0x10,0xA6,0x06,0x34,0x07,0xFE,
    7,0x05,0x10,0xA8,0x00,0xC4,0x00,0x01,
    5,0x03,0x11,0xB1,0x03,0xD4,
    5,0x03,0x11,0xB2,0x00,0x00,
    5,0x03,0x11,0xC4,0x00,0x89,
    6,0x03,0x02,0x67,0x02,0x85,0x47,
    5,0x03,0x11,0xB3,0x01,0x94,
    5,0x03,0x11,0xBB,0x00,0x00,
    5,0x03,0x11,0xBC,0x00,0x00,
    5,0x03,0x11,0xBD,0x07,0xFF,
    6,0x03,0x02,0x6B,0x80,0x00,0x00,
    6,0x03,0x02,0x6C,0x7F,0xFF,0xFF,
    5,0x03,0x11,0xBF,0x00,0x00,
    5,0x03,0x11,0xC0,0x07,0xFF,
    6,0x03,0x02,0x6E,0x80,0x00,0x00,
    6,0x03,0x02,0x6F,0x7F,0xFF,0xFF,
    5,0x03,0x11,0xC6,0x00,0x73,
    5,0x03,0x11,0xC2,0x00,0x1C,
    6,0x03,0x02,0x61,0x00,0x20,0x44,
    5,0x03,0x11,0x87,0x00,0x00,
    5,0x03,0x11,0x88,0x07,0xFF,
    5,0x03,0x11,0x91,0x00,0x00,
    5,0x03,0x11,0xA1,0x00,0x07,
    6,0x03,0x02,0x45,0x00,0x04,0x4D,
    5,0x03,0x11,0x95,0x00,0x00,
    5,0x03,0x11,0x96,0x07,0xFF,
    5,0x03,0x11,0xA0,0x00,0x1C,
    6,0x03,0x02,0x42,0x00,0x04,0x4D,
    5,0x03,0x11,0x83,0x00,0x00,
    5,0x03,0x11,0x9D,0x00,0x00,
    5,0x03,0x11,0x9B,0x0C,0x93,
    5,0x03,0x11,0x9C,0x01,0xBF,
    5,0x03,0x11,0x9E,0x00,0x89,
    6,0x03,0x02,0x3C,0x00,0x02,0x27,
    5,0x03,0x11,0x50,0x04,0xC8,
    5,0x03,0x11,0x51,0x0F,0x8B,
    5,0x03,0x11,0x5D,0x00,0x1C,
    6,0x03,0x02,0x13,0x00,0x08,0x11,
    5,0x03,0x11,0xDA,0x05,0x12,
    5,0x03,0x11,0x5D,0x03,0xFD,
    6,0x03,0x02,0x13,0x02,0x85,0x47,
    5,0x03,0x11,0x5E,0x03,0xFD,
    6,0x03,0x02,0x15,0x02,0x85,0x47,
    5,0x03,0x11,0x53,0x0E,0x57,
    5,0x03,0x11,0x54,0x00,0xD5,
    6,0x03,0x02,0x17,0x80,0x00,0x00,
    6,0x03,0x02,0x18,0x7F,0xFF,0xFF,
    5,0x03,0x11,0x5B,0x00,0x1C,
    6,0x03,0x02,0x0E,0x00,0x08,0x11,
    5,0x03,0x11,0x5B,0x03,0xFD,
    6,0x03,0x02,0x0E,0x02,0x85,0x47,
    5,0x03,0x11,0x5C,0x03,0xFD,
    6,0x03,0x02,0x10,0x02,0x85,0x47,
    5,0x03,0x11,0x56,0x0D,0x80,
    5,0x03,0x11,0x57,0x01,0x40,
    5,0x03,0x11,0x60,0x07,0xFF,
    6,0x03,0x02,0x1A,0x80,0x00,0x00,
    6,0x03,0x02,0x1B,0x7F,0xFF,0xFF,
    5,0x03,0x11,0x59,0x00,0x1C,
    6,0x03,0x02,0x09,0x00,0x08,0x11,
    5,0x03,0x11,0x59,0x00,0x1C,
    6,0x03,0x02,0x09,0x00,0x08,0x11,
    5,0x03,0x11,0x5A,0x00,0x1C,
    6,0x03,0x02,0x0B,0x00,0x08,0x11,
    5,0x03,0x11,0x98,0x03,0xC2,
    5,0x03,0x11,0x99,0x0F,0x40,
    5,0x03,0x11,0x9F,0x00,0x89,
    6,0x03,0x02,0x3F,0x00,0x02,0x27,
    5,0x01,0x10,0xB3,0x07,0xE3,
    5,0x01,0x10,0xB4,0x00,0x11,
    5,0x01,0x10,0xB5,0x01,0x9A,
    6,0x01,0x01,0xF2,0x00,0x00,0x0A,
    6,0x01,0x02,0x08,0x00,0x42,0x00,
    5,0x01,0x10,0xA6,0x00,0x66,
    6,0x01,0x01,0xF0,0x02,0x8F,0x5C,
    6,0x03,0x00,0x81,0x00,0xCE,0xC0,
    6,0x03,0x02,0xEB,0x00,0x00,0x64,
    5,0x0D,0x12,0x5A,0x04,0x00,
    5,0x0D,0x12,0x6B,0x00,0xCD,
    5,0x0D,0x12,0x7C,0x05,0x00,
    6,0x0D,0x01,0x72,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x5B,0x03,0xD7,
    5,0x0D,0x12,0x6C,0x01,0x71,
    5,0x0D,0x12,0x7D,0x05,0x00,
    6,0x0D,0x01,0x73,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x5C,0x03,0xAE,
    5,0x0D,0x12,0x6D,0x01,0x71,
    5,0x0D,0x12,0x7E,0x05,0x00,
    6,0x0D,0x01,0x74,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x5D,0x03,0x85,
    5,0x0D,0x12,0x6E,0x01,0x71,
    5,0x0D,0x12,0x7F,0x05,0x00,
    6,0x0D,0x01,0x75,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x5E,0x03,0x5C,
    5,0x0D,0x12,0x6F,0x01,0x71,
    5,0x0D,0x12,0x80,0x05,0x00,
    6,0x0D,0x01,0x76,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x5F,0x03,0x33,
    5,0x0D,0x12,0x70,0x01,0x71,
    5,0x0D,0x12,0x81,0x05,0x00,
    6,0x0D,0x01,0x77,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x60,0x03,0x1F,
    5,0x0D,0x12,0x71,0x01,0x71,
    5,0x0D,0x12,0x82,0x05,0x00,
    6,0x0D,0x01,0x78,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA3,0x04,0xF6,
    5,0x0D,0x12,0x61,0x02,0x66,
    5,0x0D,0x12,0x72,0x01,0x71,
    5,0x0D,0x12,0x83,0x05,0x00,
    6,0x0D,0x01,0x79,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x62,0x02,0x66,
    5,0x0D,0x12,0x73,0x01,0x71,
    5,0x0D,0x12,0x84,0x05,0x00,
    6,0x0D,0x01,0x7A,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x63,0x02,0x66,
    5,0x0D,0x12,0x74,0x01,0x71,
    5,0x0D,0x12,0x85,0x05,0x00,
    6,0x0D,0x01,0x7B,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x64,0x02,0x66,
    5,0x0D,0x12,0x75,0x01,0x71,
    5,0x0D,0x12,0x86,0x05,0x00,
    6,0x0D,0x01,0x7C,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x90,0x08,0x8F,
    5,0x0D,0x12,0x8F,0x00,0x8F,
    5,0x0D,0x12,0x96,0x09,0xB8,
    5,0x0D,0x12,0x95,0x01,0xB8,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x65,0x02,0x00,
    5,0x0D,0x12,0x76,0x01,0x71,
    5,0x0D,0x12,0x87,0x05,0x00,
    6,0x0D,0x01,0x7D,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x66,0x02,0x00,
    5,0x0D,0x12,0x77,0x01,0x71,
    5,0x0D,0x12,0x88,0x05,0x00,
    6,0x0D,0x01,0x7E,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x67,0x02,0x00,
    5,0x0D,0x12,0x78,0x01,0x71,
    5,0x0D,0x12,0x89,0x05,0x00,
    6,0x0D,0x01,0x7F,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x68,0x02,0x00,
    5,0x0D,0x12,0x79,0x01,0x71,
    5,0x0D,0x12,0x8A,0x05,0x00,
    6,0x0D,0x01,0x80,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x69,0x02,0x00,
    5,0x0D,0x12,0x7A,0x01,0x71,
    5,0x0D,0x12,0x8B,0x05,0x00,
    6,0x0D,0x01,0x81,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA4,0x05,0xAE,
    5,0x0D,0x12,0x6A,0x02,0x00,
    5,0x0D,0x12,0x7B,0x01,0x71,
    5,0x0D,0x12,0x8C,0x05,0x00,
    6,0x0D,0x01,0x82,0x00,0xA3,0xD7,
    5,0x0D,0x12,0x92,0x08,0x1A,
    5,0x0D,0x12,0x91,0x00,0x1A,
    5,0x0D,0x12,0x9E,0x08,0x3A,
    5,0x0D,0x12,0x9D,0x00,0x3A,
    5,0x0D,0x12,0xA5,0x06,0xA4,
    5,0x0D,0x12,0x98,0x09,0x15,
    5,0x0D,0x12,0x97,0x01,0x15,
    5,0x0D,0x12,0xA0,0x08,0x40,
    5,0x0D,0x12,0x9F,0x00,0x40,
    6,0x0D,0x01,0xD8,0x00,0x00,0x00,
    6,0x0D,0x01,0xD9,0x00,0x00,0x00,
    5,0x0D,0x12,0x9A,0x09,0x15,
    5,0x0D,0x12,0x99,0x01,0x15,
    5,0x0D,0x12,0xA2,0x08,0x40,
    5,0x0D,0x12,0xA1,0x00,0x40,
    5,0x0D,0x12,0x8E,0x09,0x76,
    5,0x0D,0x12,0x8D,0x01,0x76,
    6,0x03,0x05,0xE5,0x0F,0xE7,0x00,
    6,0x05,0x04,0xAB,0x10,0x05,0x00,
    6,0x01,0x02,0x77,0x0C,0x14,0x00,
    6,0x03,0x05,0xE4,0x0F,0xE6,0x00,
    6,0x05,0x04,0xAC,0x1F,0xF6,0x00,
    6,0x01,0x02,0x78,0x0D,0x46,0x00,
    6,0x0D,0x00,0x76,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x87,0x00,0x00,0x00,
    6,0x0D,0x00,0x77,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x88,0x00,0x00,0x00,
    6,0x0D,0x00,0x78,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x89,0x00,0x00,0x00,
    6,0x0D,0x00,0x79,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8A,0x00,0x00,0x00,
    6,0x0D,0x00,0x7A,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x7B,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8B,0x00,0x00,0x00,
    6,0x0D,0x00,0x7C,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8C,0x00,0x00,0x00,
    6,0x0D,0x00,0x7D,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8D,0x00,0x00,0x00,
    6,0x0D,0x00,0x7E,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8E,0x00,0x00,0x00,
    6,0x0D,0x00,0x7F,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8F,0x00,0x00,0x00,
    6,0x0D,0x00,0x80,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x90,0x00,0x00,0x00,
    6,0x0D,0x00,0x81,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x91,0x00,0x00,0x00,
    6,0x0D,0x00,0x82,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x83,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x84,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x85,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x86,0x7F,0xFF,0xFF,
    5,0x03,0x11,0x6A,0x00,0x00,
    5,0x03,0x11,0x6B,0x00,0x00,
    5,0x03,0x11,0x6C,0x00,0x00,
    5,0x03,0x11,0x6D,0x00,0x00,
    5,0x03,0x11,0x6E,0x00,0x00,
    5,0x03,0x11,0x6F,0x00,0x00,
    5,0x03,0x11,0x70,0x00,0x00,
    5,0x03,0x11,0x71,0x00,0x00,
    5,0x03,0x11,0x72,0x00,0x00,
    5,0x03,0x11,0x73,0x00,0x00,
    5,0x03,0x11,0x74,0x00,0x00,
    5,0x03,0x11,0x75,0x00,0x00,
    5,0x03,0x11,0x76,0x07,0xFF,
    5,0x03,0x11,0x77,0x00,0x00,
    5,0x03,0x11,0x78,0x00,0x00,
    5,0x03,0x11,0x79,0x00,0x00,
    5,0x03,0x11,0x7A,0x00,0x00,
    5,0x03,0x11,0x7B,0x00,0x00,
    5,0x03,0x11,0x7C,0x00,0x00,
    5,0x03,0x11,0x7D,0x00,0x00,
    5,0x03,0x11,0x7E,0x00,0x00,
    5,0x03,0x11,0x7F,0x00,0x00,
    5,0x03,0x11,0x80,0x00,0x00,
    5,0x03,0x11,0x81,0x00,0x00,
    5,0x03,0x11,0x82,0x00,0x00,
    5,0x0D,0x14,0x8A,0x01,0x57,
    5,0x0D,0x14,0x8B,0x07,0xF4,
    5,0x0D,0x14,0x8C,0x02,0x04,
    5,0x0D,0x14,0x8D,0x00,0x0B,
    6,0x03,0x00,0x31,0x00,0x00,0x00,
    6,0x03,0x00,0x34,0x40,0x00,0x00,
    6,0x03,0x00,0x33,0x06,0x4D,0x32,
    6,0x03,0x00,0x2D,0x00,0x00,0x00,
    6,0x03,0x00,0x30,0x40,0x00,0x00,
    6,0x03,0x00,0x2E,0x00,0x03,0xE8,
    6,0x09,0x02,0x1D,0x00,0x00,0x00,
    6,0x09,0x02,0x7A,0x00,0x00,0x01,
    6,0x09,0x02,0x77,0x40,0x00,0x00,
    6,0x09,0x02,0x79,0x00,0x00,0x00,
    6,0x0D,0x00,0x3C,0x00,0x00,0x00,
    6,0x0D,0x00,0x76,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x87,0x00,0x00,0x00,
    6,0x0D,0x00,0x77,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x88,0x00,0x00,0x00,
    6,0x0D,0x00,0x78,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x89,0x00,0x00,0x00,
    6,0x0D,0x00,0x79,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8A,0x00,0x00,0x00,
    6,0x0D,0x00,0x7A,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x7B,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8B,0x00,0x00,0x00,
    6,0x0D,0x00,0x7C,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8C,0x00,0x00,0x00,
    6,0x0D,0x00,0x7D,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8D,0x00,0x00,0x00,
    6,0x0D,0x00,0x7E,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8E,0x00,0x00,0x00,
    6,0x0D,0x00,0x7F,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x8F,0x00,0x00,0x00,
    6,0x0D,0x00,0x80,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x90,0x00,0x00,0x00,
    6,0x0D,0x00,0x81,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x91,0x00,0x00,0x00,
    6,0x0D,0x00,0x82,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x83,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x84,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x85,0x7F,0xFF,0xFF,
    6,0x0D,0x00,0x86,0x7F,0xFF,0xFF,
    5,0x03,0x10,0x2E,0x00,0x00,
    6,0x0D,0x00,0x00,0x00,0x00,0xC6,
    6,0x0D,0x00,0x01,0x00,0x00,0xC7,
    6,0x0D,0x00,0xC4,0x00,0x00,0x41,
    6,0x03,0x00,0x06,0x00,0x00,0x3C,
    6,0x03,0x00,0x07,0x00,0x00,0x3D,
    6,0x03,0x00,0x08,0x00,0x00,0x3A,
    6,0x03,0x00,0x09,0x00,0x00,0x3B,
    6,0x09,0x01,0x2E,0x00,0x01,0x37,
    5,0x01,0x10,0xA5,0x02,0x66,
    9,0x03,0x11,0xDD,0x07,0xFF,0x00,0x00,0x00,0x00,
    5,0x03,0x10,0x38,0x07,0xFF,
    6,0x03,0x00,0xEA,0x04,0x60,0x80,
    6,0x03,0x00,0xE8,0x00,0x00,0x32,
    5,0x03,0x10,0xF0,0x01,0xD0,
    5,0x03,0x10,0xF1,0x0F,0x7E,
    5,0x03,0x10,0xF2,0x00,0x41,
    5,0x03,0x10,0xF3,0x00,0x46,
    6,0x03,0x00,0xFC,0x00,0x20,0x44,
    5,0x03,0x10,0xE8,0x00,0x00,
    5,0x03,0x10,0xE9,0x07,0xFF,
    5,0x03,0x10,0xEE,0x00,0x07,
    6,0x03,0x00,0xFA,0x00,0x04,0x4D,
    5,0x03,0x10,0xEB,0x00,0x00,
    5,0x03,0x10,0xEC,0x07,0xFF,
    5,0x03,0x10,0xEF,0x00,0x1C,
    5,0x03,0x10,0x2F,0x00,0x00,
    5,0x03,0x10,0x30,0x07,0xFF,
    5,0x03,0x10,0x32,0x00,0x0E,
    6,0x03,0x00,0xE2,0x00,0x06,0x74,
    5,0x03,0x11,0x0E,0x05,0x76,
    5,0x03,0x11,0x0D,0x01,0x30,
    5,0x03,0x11,0x0C,0x00,0x03,
    5,0x03,0x11,0x0B,0x00,0xA3,
    5,0x03,0x10,0xE7,0x03,0xB3,
    5,0x01,0x10,0x26,0x00,0x07,
    5,0x01,0x10,0x21,0x00,0x49,
    5,0x01,0x10,0x38,0x04,0x00,
    6,0x03,0x00,0xE7,0xFA,0x00,0x00,
    5,0x03,0x10,0x34,0x00,0x0A,
    13,0x03,0x11,0x11,0x0F,0x42,0x0D,0x7B,0x00,0xBE,0x00,0x00,0x06,0x7F,
    5,0x03,0x12,0x70,0x03,0x94,
    5,0x03,0x12,0x71,0x0F,0x80,
    5,0x03,0x12,0x72,0x00,0xCD,
    5,0x03,0x12,0x73,0x00,0x46,
    6,0x03,0x05,0xB4,0x00,0x06,0x74,
    5,0x03,0x10,0x20,0x00,0x00,
    6,0x01,0x0F,0xF1,0x7C,0x90,0x20,
    6,0x05,0x0F,0xF1,0xB1,0x10,0x40,
    5,0x03,0x11,0xE9,0x07,0xFF,
    5,0x05,0x10,0x71,0x07,0xFF,
    6,0x0D,0x07,0xDA,0xFF,0xFF,0x12,
    6,0x0D,0x07,0xD9,0xFF,0xFF,0x12,
    0
};

const uint8_t DSP_FM[] PROGMEM =
{
    5,0x0D,0x14,0x89,0x02,0x00,
    5,0x0D,0x14,0x88,0x05,0x73,
    5,0x03,0x11,0xF7,0x0F,0xC0,
    6,0x01,0x00,0x01,0x00,0x00,0x52, // FM mode
    6,0x05,0x0F,0xF1,0xB1,0x10,0x40,
    5,0x05,0x10,0x41,0x00,0x02,
    5,0x01,0x10,0x6C,0x07,0xFF,
    5,0x01,0x10,0x6D,0x0F,0x6B,
    5,0x01,0x10,0x6E,0x00,0x00,
    5,0x01,0x10,0x6F,0x04,0x00,
    5,0x01,0x10,0x70,0x01,0x9A,
    5,0x01,0x10,0x71,0x00,0x00,
    5,0x01,0x10,0x76,0x00,0x03,
    5,0x01,0x10,0x77,0x00,0x00,
    5,0x01,0x10,0x78,0x00,0x02,
    5,0x01,0x10,0x79,0x00,0x03,
    5,0x01,0x10,0x7F,0x00,0x00,
    6,0x01,0x01,0xAD,0x0F,0xC0,0xFC,
    6,0x01,0x01,0xAF,0x00,0x00,0x00,
    6,0x05,0x00,0x67,0x00,0x00,0x0C,
    5,0x03,0x11,0xF6,0x00,0xE9,
    5,0x03,0x10,0x2E,0x00,0x00,
    6,0x0D,0x00,0x00,0x00,0x00,0xC6,
    6,0x0D,0x00,0x01,0x00,0x00,0xC7,
    6,0x0D,0x00,0xC4,0x00,0x00,0x41,
    6,0x03,0x00,0x06,0x00,0x00,0x38,
    6,0x03,0x00,0x07,0x00,0x00,0x39,
    6,0x03,0x00,0x08,0x00,0x00,0x3A,
    6,0x03,0x00,0x09,0x00,0x00,0x3B,
    6,0x09,0x01,0x2E,0x00,0x01,0x37,
    6,0x01,0x0F,0xF5,0xE2,0x76,0x28,
    6,0x05,0x0F,0xF5,0xE2,0x50,0x8D,
    6,0x05,0x0F,0xF9,0x00,0x00,0x17,
//  5,0x03,0x10,0x11,0x06,0x5A, // audio volume scaler
    5,0x00,0x00,0x34,0x30,0x20, // RDS sync mode - max 2 bits error correctable blocks are handled as vaild
    0
};

const uint8_t DSP_AM[] PROGMEM =
{
    5,0x0D,0x14,0x89,0x02,0x00,
    6,0x01,0x00,0x01,0x00,0x00,0x51, // AM mode
    6,0x05,0x0F,0xF9,0x00,0x00,0x1F,
    5,0x05,0x10,0x41,0x00,0x02,
    6,0x01,0x00,0xE7,0x00,0x00,0x01,
    6,0x01,0x00,0xE8,0x00,0x00,0x02,
    6,0x05,0x02,0x1B,0x00,0x00,0x01,
    6,0x05,0x02,0x1C,0x00,0x00,0x02,
    5,0x03,0x11,0xF6,0x00,0xE9,
    5,0x03,0x10,0x2E,0x07,0xFF,
    6,0x0D,0x00,0x00,0x00,0x00,0xC6,
    6,0x0D,0x00,0x01,0x00,0x00,0xC7,
    6,0x0D,0x00,0xC4,0x00,0x00,0x03,
    6,0x03,0x00,0x06,0x00,0x00,0x3C,
    6,0x03,0x00,0x07,0x00,0x00,0x3D,
    6,0x09,0x01,0x2E,0x00,0x02,0x1A,
    6,0x01,0x0F,0xF5,0xE2,0x76,0x28,
    6,0x05,0x0F,0xF5,0xE2,0x75,0xC1,
    5,0x03,0x11,0x27,0x0F,0xEC,
//  5,0x03,0x10,0x11,0x07,0x21, // audio volume scaler
    0
};

