#ifndef SEGMENT_H
#define SEGMENT_H

class Segment {
private:
  const int *seg;
  void AllOff();
  void On(int *onSeg, int size);

public:
  Segment(int *_seg);

  void Do(int num);
};

extern Segment;

#endif