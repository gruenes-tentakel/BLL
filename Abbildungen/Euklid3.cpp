#include "geom2d.hpp"
int main(int argc, char* argv[]) {
  char fname[21];
  sprintf(fname, "%s.ps", argv[0]);
  Plot p(fname, false, false);
  LW_NORMAL = 0.36;
  FN_NORMAL = 10.0;
  p.set_lw(LW_NORMAL);

  // Definitions
  Point2 A(100.0, 100.0);
  Point2 B(180.0, 100.0);

  // Constructions
  Point2 C(Circle2(Segment2(A, B).point(0.5), 0.5*A.dist(B)).periphery(115.0));
  Point2 D(C.rotate(B, -90.0));
  Point2 E(A.rotate(B,  90.0));

  p.set_lw(3.0);
  Segment2(C, B).plot(p, Color(string("Sky Blue1")));
  Segment2(B, D).plot(p, Color(string("Sky Blue1")));
  Segment2(A, B).plot(p, Color(string("Scarlet Red1")));
  Segment2(B, E).plot(p, Color(string("Scarlet Red1")));
  p.set_lw(LW_NORMAL);

  Segment2(A, D).plot(p);
  Segment2(C, E).plot(p);
  Triangle2(A, B, C).plot(p);
  Segment2(C, A).plot_angle(p, 90.0);
  Segment2(B, D).plot_angle(p, 90.0);
  Segment2(B, A).plot_angle(p, 90.0);
  Line2(B, C).plot_angle(p, Line2(B, A), 28.0);

  Square2(B, Segment2(C, B).rotate(_90)).plot(p);
  Square2(A, Segment2(C, A).rotate(-_90)).plot(p);
  Square2(B, Segment2(A, B).rotate(-_90)).plot(p);

  // Names
  p.font("Times-Italic", FN_NORMAL);
  p.string(A.x()- 8.0, A.y()- 8.0, "A");
  p.string(B.x()+ 4.0, B.y()- 6.0, "B");
  p.string(C.x()- 5.0, C.y()+ 5.0, "C");
  p.string(D.x()+ 4.0, D.y()- 2.0, "D");
  p.string(E.x()+ 2.0, E.y()- 6.0, "E");
  p.string(202.0, 124.0, "a");
  p.string(142.0, 129.0, "a");
  p.string(184.0,  57.0, "c");
  p.string(130.0,  92.0, "c");

  p.font("Symbol", FN_NORMAL-1.0);
  p.string(155.0, 104.0, "b");

  // Symbols
  p.symbol(1, A.x(), A.y(), PT_SIZE);
  p.symbol(1, B.x(), B.y(), PT_SIZE);
  p.symbol(1, C.x(), C.y(), PT_SIZE);
  p.symbol(1, D.x(), D.y(), PT_SIZE);
  p.symbol(1, E.x(), E.y(), PT_SIZE);

  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
