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
  Point2 C(150.0, 170.0);
  Point2 C_(196.0, 170.0);

  // Constructions
  Line2 g(A, B);
  Line2 h(g.parallel(C));

  // Plots
  Segment2(A, C).plot(p);
  Segment2(B, C).plot(p);
  Segment2(A, C_).plot(p);
  Segment2(B, C_).plot(p);
  g.plot(p,  70.0, 220.0);
  h.plot(p,  70.0, 220.0);

  // Names
  p.font("Times-Italic", FN_NORMAL);
  p.string(A.x()- 6.0, A.y()-10.0, "A");
  p.string(B.x()+ 0.0, B.y()-10.0, "B");
  p.string(C.x()- 2.0, C.y()+ 4.0, "C");
  p.string(C_.x()- 2.0, C_.y()+ 4.0, "C'");

  // Symbols
  p.symbol(1, A.x(), A.y(), PT_SIZE);
  p.symbol(1, B.x(), B.y(), PT_SIZE);
  p.symbol(1, C.x(), C.y(), PT_SIZE);
  p.symbol(1, C_.x(), C_.y(), PT_SIZE);

  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
