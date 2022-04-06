#include "geom2d.hpp"

// ================================
   int main(int argc, char* argv[])
// ================================
{
  argc += 0;
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

  // Plots
  Segment2(A, D).plot(p);
  Segment2(C, D).plot(p);
  Triangle2(A, B, C).plot(p);
  Segment2(C, A).plot_angle(p, 90.0);

  Square2(B, Segment2(C, B).rotate(_90)).plot(p);
  Square2(A, Segment2(C, A).rotate(-_90)).plot(p);
  Square2(B, Segment2(A, B).rotate(-_90)).plot(p);

  // Names
  p.font("Times-Italic", FN_NORMAL);
  p.string(A.x()- 8.0, A.y()- 8.0, "A");
  p.string(B.x()+ 2.0, B.y()- 8.0, "B");
  p.string(C.x()- 3.0, C.y()+ 5.0, "C");
  p.string(D.x()+ 4.0, D.y()- 2.0, "D");

  // Symbols
  p.symbol(1, A.x(), A.y(), PT_SIZE);
  p.symbol(1, B.x(), B.y(), PT_SIZE);
  p.symbol(1, C.x(), C.y(), PT_SIZE);
  p.symbol(1, D.x(), D.y(), PT_SIZE);

  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
