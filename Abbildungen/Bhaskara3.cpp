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
  Point2 C(100.0, 100.0);
  fp_prec a = 30;
  fp_prec b = 70;

  // Constructions
  Point2 A(C+Vector2(b, 0.0));
  Point2 A1(C+Vector2(0.0, -b));
  Point2 A2(C+Vector2(-a, -(b-a)));
  Point2 X(C+Vector2(b,-b));
  Point2 Y(C+Vector2(-a,-b));

  // Plots
  Square2(Y, a, false).plot_filled(p, Color (string("green")));
  Square2(A1, b, false).plot_filled(p, Color (string("Sky Blue1")));
  Square2(A1, b, false).plot(p);
  Square2(Y, a, false).plot(p);
  
  // Names
  p.font("Times-Italic", FN_NORMAL);
  Segment2(Y, A1).plot_label(p, "a", 0, 2);
  Segment2(A2, Y).plot_label(p, "a", 0, 2);
  Segment2(A1, X).plot_label(p, "b", 0, 2);
  Segment2(X, A).plot_label(p, "b", 0, 2);
  p.font("Times-Italic", FN_NORMAL+3);
  p.string(129, 62, "b");
  p.string(80, 41, "a");
  p.font("Times-Italic", FN_NORMAL);
  p.string(136, 68, "2");
  p.string(87, 46, "2");

}
