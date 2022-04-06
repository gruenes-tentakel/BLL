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
  Point2 B(C+Vector2(0.0, a));
  Point2 C1(C+Vector2(b-a, 0.0));
  Point2 C2(C+Vector2(b-a, -(b-a)));
  Point2 C3(C+Vector2(0.0, -(b-a)));
  Point2 A1(C+Vector2(b-a, -b));
  Point2 A2(C+Vector2(-a, -(b-a)));

  // Plots
  Triangle2(A, B, C).plot(p);
  Triangle2(A, C1, A1).plot(p);
  Triangle2(A1, A2, C2).plot(p);
  Triangle2(B, A2, C3).plot(p);
  Segment2(C, A).plot_angle(p, 90.0);
  Segment2(C1, A1).plot_angle(p, 90.0);
  Segment2(C2, A2).plot_angle(p, 90.0);
  Segment2(C3, B).plot_angle(p, 90.0);
  Line2(A,B).plot_angle(p, Line2(A,C),26);
  Line2(B,C).plot_angle(p, Line2(B,A),16);
  Segment2(B, A).plot(p, Color (string("red")));
  Segment2(A1, A).plot(p, Color (string("red")));
  Segment2(A1, A2).plot(p, Color (string("red")));
  Segment2(B, A2).plot(p, Color (string("red")));
  Segment2(C, A).translate(Vector2(0.0,0.3)).plot(p, Color (string("Sky Blue2")));
  Segment2(C1, A1).translate(Vector2(0.3,0.0)).plot(p, Color (string("Sky Blue2")));
  Segment2(C2, A2).translate(Vector2(0.0,-0.3)).plot(p, Color (string("Sky Blue2")));
  Segment2(C3, B).translate(Vector2(-0.3,0.0)).plot(p, Color (string("Sky Blue2")));
  Segment2(C, B).translate(Vector2(0.3,0.0)).plot(p, Color (string("green")));
  Segment2(C1, A).translate(Vector2(0.0,-0.3)).plot(p, Color (string("green")));
  Segment2(C2, A1).translate(Vector2(-0.3,0.0)).plot(p, Color (string("green")));
  Segment2(C3, A2).translate(Vector2(0.0,0.3)).plot(p, Color (string("green")));

  // Names
  p.font("Times-Italic", FN_NORMAL);
  p.string( 94.0, 113.0, "a");
  p.string(129.0,  91.0, "b");
  p.string(131.0, 118.0, "c");

  p.font("Symbol", FN_NORMAL-3);  
  p.string(147, 102, "a");
  p.string(102, 120, "b");
  
}
