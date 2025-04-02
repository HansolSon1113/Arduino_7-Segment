#ifndef SEGMENT_H
#define SEGMENT_H

class Segment {
private:
  const int *seg;
  int type;
  void AllOff();
  void On(int *onSeg, int size);

public:
  Segment(int type, int *_seg);

  void Do(int num);
};

extern Segment;

#endif