#include "geom2d.hpp"

// ================================
   int main(int argc, char* argv[])
// ================================
{
  argc += 0;
  char fname[201];
  sprintf(fname, "%s.ps", argv[0]);
  Plot p(fname, false, false);
  LW_NORMAL = 0.36;
  FN_NORMAL = 10.0;
  p.set_lw(LW_NORMAL);

  // Definitions
  Point2 A(100.0, 100.0);  

  // Constructions
  Point2 B(A+Vector2(80.0, 0.0));
  Point2 C(Circle2(Segment2(A,B)).periphery(115.0));
  
  // Plots
  Triangle2(A, B, C).plot(p);
  Segment2(C,A).plot_angle(p, 90.0);
  (A-C).plot(p,C.vector(),6.0,1.5,0.84);
  (B-A).plot(p,A.vector(),6.0,1.5,0.84);
  (B-C).plot(p,C.vector(),6.0,1.5,0.84);

  // Names
  p.font("Times-Italic", FN_NORMAL);
  Segment2(A, B).plot_vector(p, 'c', 0, 0);
  Segment2(B, C).plot_vector(p, 'a', 0, 0);
  Segment2(C, A).plot_vector(p, 'b', -2, 0);
  A.plot_label(p, "A", C, B, 0, 2);
  B.plot_label(p, "B", A, C, 0, 2);
  C.plot_label(p, "C", A, B, 0, 2);
}
