#ifndef _NOTETABLES_
#define _NOTETABLES_

#include "avr/pgmspace.h"

#define MIDI_NOTES 128
// used to convert midi note numbers into the increments required to generate the note in the ISR
const PROGMEM unsigned int midiNoteToWavePhaseIncrement[MIDI_NOTES] =
{
 66 // 0,8.18,66.98,66                C
,70 // 1,8.66,70.96,70
,75 // 2,9.18,75.18,75
,79 // 3,9.72,79.65,79
,84 // 4,10.30,84.38,84
,89 // 5,10.91,89.40,89
,94 // 6,11.56,94.72,94
,100 // 7,12.25,100.35,100
,106 // 8,12.98,106.32,106
,112 // 9,13.75,112.64,112
,119 // 10,14.57,119.34,119
,126 // 11,15.43,126.43,126
,133 // 12,16.35,133.95,133            C
,141 // 13,17.32,141.92,141
,150 // 14,18.35,150.35,150
,159 // 15,19.45,159.29,159
,168 // 16,20.60,168.77,168
,178 // 17,21.83,178.80,178
,189 // 18,23.12,189.43,189
,200 // 19,24.50,200.70,200
,212 // 20,25.96,212.63,212
,225 // 21,27.50,225.28,225
,238 // 22,29.14,238.67,238
,252 // 23,30.87,252.86,252
,267 // 24,32.70,267.90,267           C - lowest note used on rcarduino ribbon synth
,283 // 25,34.65,283.83,283
,300 // 26,36.71,300.71,300
,318 // 27,38.89,318.59,318 
,337 // 28,41.20,337.53,337
,357 // 29,43.65,357.60,357
,378 // 30,46.25,378.87,378
,401 // 31,49.00,401.40,401
,425 // 32,51.91,425.27,425
,450 // 33,55.00,450.55,450
,477 // 34,58.27,477.34,477
,505 // 35,61.74,505.73,505
,535 // 36,65.41,535.80,535           C
,567 // 37,69.30,567.66,567
,601 // 38,73.42,601.42,601
,637 // 39,77.78,637.18,637
,675 // 40,82.41,675.07,675
,715 // 41,87.31,715.21,715
,757 // 42,92.50,757.74,757
,802 // 43,98.00,802.79,802
,850 // 44,103.83,850.53,850
,901 // 45,110.00,901.11,901
,954 // 46,116.54,954.69,954
,1011 // 47,123.47,1011.46,1011       C
,1071 // 48,130.81,1071.60,1071
,1135 // 49,138.59,1135.32,1135
,1202 // 50,146.83,1202.83,1202
,1274 // 51,155.56,1274.36,1274
,1350 // 52,164.81,1350.13,1350
,1430 // 53,174.61,1430.42,1430
,1515 // 54,185.00,1515.47,1515
,1605 // 55,196.00,1605.59,1605
,1701 // 56,207.65,1701.06,1701
,1802 // 57,220.00,1802.21,1802
,1909 // 58,233.08,1909.38,1909
,2022 // 59,246.94,2022.92,2022
,2143 // 60,261.63,2143.20,2143       C
,2270 // 61,277.18,2270.64,2270
,2405 // 62,293.66,2405.66,2405
,2548 // 63,311.13,2548.71,2548
,2700 // 64,329.63,2700.27,2700
,2860 // 65,349.23,2860.83,2860
,3030 // 66,369.99,3030.95,3030
,3211 // 67,392.00,3211.18,3211
,3402 // 68,415.30,3402.12,3402
,3604 // 69,440.00,3604.42,3604
,3818 // 70,466.16,3818.75,3818
,4045 // 71,493.88,4045.83,4045
,4286 // 72,523.25,4286.41,4286      C
,4541 // 73,554.37,4541.29,4541
,4811 // 74,587.33,4811.33,4811
,5097 // 75,622.25,5097.42,5097
,5400 // 76,659.26,5400.53,5400
,5721 // 77,698.46,5721.67,5721
,6061 // 78,739.99,6061.89,6061
,6422 // 79,783.99,6422.36,6422
,6804 // 80,830.61,6804.25,6804
,7208 // 81,880.00,7208.85,7208
,7637 // 82,932.33,7637.51,7637
,8091 // 83,987.77,8091.66,8091
,8572 // 84,1046.50,8572.82,8572     C
,9082 // 85,1108.73,9082.58,9082
,9622 // 86,1174.66,9622.66,9622
,10194 // 87,1244.51,10194.85,10194
,10801 // 88,1318.51,10801.07,10801
,11443 // 89,1396.91,11443.33,11443
,12123 // 90,1479.98,12123.79,12123
,12844 // 91,1567.98,12844.71,12844
,13608 // 92,1661.22,13608.50,13608
,14417 // 93,1760.00,14417.70,14417
,15275 // 94,1864.65,15275.02,15275
,16183 // 95,1975.53,16183.31,16183
,17145 // 96,2093.00,17145.63,17145     C
,18165 // 97,2217.46,18165.16,18165
,19245 // 98,2349.32,19245.31,19245
,20389 // 99,2489.01,20389.70,20389
,21602 // 100,2637.02,21602.14,21602
,22886 // 101,2793.83,22886.67,22886
,24247 // 102,2959.95,24247.58,24247
,25689 // 103,3135.96,25689.42,25689
,27216 // 104,3322.44,27216.99,27216
,28835 // 105,3520.00,28835.39,28835
,30550 // 106,3729.31,30550.04,30550
,32366 // 107,3951.06,32366.63,32366
,34291 // 108,4186.01,34291.26,34291    C
,36330 // 109,4434.92,36330.32,36330
,38490 // 110,4698.64,38490.65,38490
,40779 // 111,4978.03,40779.41,40779
,43204 // 112,5274.04,43204.25,43204
,45773 // 113,5587.65,45773.32,45773
,48495 // 114,5919.91,48495.14,48495
,51378 // 115,6271.92,51378.79,51378
,54433 // 116,6644.87,54433.96,54433
,57670 // 117,7040.00,57670.76,57670
,61100 // 118,7458.62,61100.07,61100
,64733 // 119,7902.13,64733.26,64733
,3046 // 120,8372.02,68582.53,3046      C
,7124 // 121,8869.84,72660.64,7124
,11445 // 122,9397.27,76981.30,11445
,16022 // 123,9956.06,81558.77,16022
,20872 // 124,10548.07,86408.50,20872
,26010 // 125,11175.30,91546.65,26010
,31454 // 126,11839.81,96990.28,31454
,31454 // 127,11839.81,96990.28,31454 // this is wrong, need to calculate correct value, even though at 8Khz its wrapping around on every tick
};

// Pentatonic scale
// C D E G A C
// to map to midi note

#define PENTATONIC_NOTES 54

// provides an index of pentatonic notes in the midi note table

const PROGMEM unsigned char sPentatonicNotes[PENTATONIC_NOTES] =
{
  0,   2,  4,  7,  9, 
  12, 14, 16, 19, 21, 
  24, 26, 28, 31, 33,
  36, 38, 40, 43, 45,
  48, 50, 52, 55, 57,
  60, 62, 64, 67, 69,
  72, 74, 76, 79, 81,
  84, 86, 88, 91, 93,
  96, 98,100,103,105,
 108,110,112,115,117,
 120,122,124,127 
};

// C Minor Blues scale
// C D# F F# G A# C
// to map to midi note

#define CMBLUES_NOTES 65

// provides an index of pentatonic notes in the midi note table

const PROGMEM unsigned char sCMBluesNotes[CMBLUES_NOTES] =
{
  0,   3,  5,  6,  7, 10,  // 6
  12, 15, 17, 18, 19, 22,  // 12
  24, 27, 29, 30, 31, 34,  // 18
  36, 39, 41, 42, 43, 46,  // 24
  48, 51, 53, 54, 55, 58,  // 30
  60, 63, 65, 66, 67, 70,  // 36   
  72, 75, 77, 78, 79, 82,  // 42
  84, 87, 89, 90, 91, 94,  // 48
  96, 99,101,102,103,106,  // 54
 108,111,113,114,115,118,  // 60
 120,123,125,126,127       // 65
};


unsigned int getMidiNotePhaseIncrement(unsigned char sNote)
{
 if(sNote >= MIDI_NOTES)
 {
   sNote = (MIDI_NOTES - 1);
 }

 return pgm_read_word(midiNoteToWavePhaseIncrement + (sNote));
}
unsigned int getPentatonicPhaseIncrement(unsigned char sPentatonicNote)
{
 if(sPentatonicNote >= PENTATONIC_NOTES)
  sPentatonicNote = (PENTATONIC_NOTES - 1);

 uint8_t sMidiIndex = pgm_read_byte(sPentatonicNotes + sPentatonicNote);

 return pgm_read_word(midiNoteToWavePhaseIncrement + sMidiIndex);
}

unsigned int getCMBluesPhaseIncrement(unsigned char sCMBluesNote)
{
 if(sCMBluesNote >= CMBLUES_NOTES)
  sCMBluesNote = (CMBLUES_NOTES - 1);
  
 uint8_t sMidiIndex = pgm_read_byte(sCMBluesNotes + sCMBluesNote);
 return pgm_read_word(midiNoteToWavePhaseIncrement + sMidiIndex);
}

#endif
