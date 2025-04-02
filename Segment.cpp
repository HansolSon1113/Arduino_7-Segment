#include "Segment.h"
#include "Arduino.h"

Segment::Segment(int _type, int *_seg) {
  for (int i = 0; i < 8; i++) {
    pinMode(_seg[i], OUTPUT);
  }

  type = _type;
  seg = _seg;
}

void Segment::Do(int num) {
  int *onSeg, size;
  this->AllOff();

  static const int seg0[] = { 0, 5, 4, 3, 2, 1 };
  static const int seg1[] = { 2, 1 };
  static const int seg2[] = { 0, 4, 3, 1, 6 };
  static const int seg3[] = { 0, 3, 2, 1, 6 };
  static const int seg4[] = { 5, 2, 1, 6 };
  static const int seg5[] = { 0, 5, 3, 2, 6 };
  static const int seg6[] = { 0, 5, 4, 3, 2, 6 };
  static const int seg7[] = { 0, 2, 1 };
  static const int seg8[] = { 0, 5, 4, 3, 2, 1, 6 };
  static const int seg9[] = { 0, 5, 3, 2, 1, 6 };

  switch (num) {
    case 0:
      onSeg = seg0;
      size = sizeof(seg0) / sizeof(seg0[0]);
      break;
    case 1:
      onSeg = seg1;
      size = sizeof(seg1) / sizeof(seg1[0]);
      break;
    case 2:
      onSeg = seg2;
      size = sizeof(seg2) / sizeof(seg2[0]);
      break;
    case 3:
      onSeg = seg3;
      size = sizeof(seg3) / sizeof(seg3[0]);
      break;
    case 4:
      onSeg = seg4;
      size = sizeof(seg4) / sizeof(seg4[0]);
      break;
    case 5:
      onSeg = seg5;
      size = sizeof(seg5) / sizeof(seg5[0]);
      break;
    case 6:
      onSeg = seg6;
      size = sizeof(seg6) / sizeof(seg6[0]);
      break;
    case 7:
      onSeg = seg7;
      size = sizeof(seg7) / sizeof(seg7[0]);
      break;
    case 8:
      onSeg = seg8;
      size = sizeof(seg8) / sizeof(seg8[0]);
      break;
    case 9:
      onSeg = seg9;
      size = sizeof(seg9) / sizeof(seg9[0]);
      break;
  }

  this->On(onSeg, size);
}

void Segment::AllOff() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(seg[i], type);
  }
}

void Segment::On(int *onSeg, int size) {
  for (int i = 0; i < size; i++) {
    digitalWrite(seg[onSeg[i]], !type);
  }
}