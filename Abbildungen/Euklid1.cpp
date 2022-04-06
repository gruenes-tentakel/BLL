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
  Point2 D(Line2(A, B).nearest(C));
  Point2 E(D.x(), D.y()-A.dist(B));

  // Plots
  Square2(B, Segment2(C, B).rotate(_90)).plot_filled(p, Color(string("Sky Blue1")));
  Square2(A, Segment2(C, A).rotate(-_90)).plot_filled(p, Color(string("Scarlet Red1")));
  Rectangle2(E, B.x()-D.x(), A.dist(B), false).plot_filled(p, Color(string("Sky Blue1")));
  Rectangle2(A-Vector2(0.0, A.dist(B)), D.x()-A.x(), A.dist(B), false).plot_filled(p, Color(string("Scarlet Red1")));

  Segment2(C, E).plot(p);
  Triangle2(A, B, C).plot(p);
  Segment2(C, A).plot_angle(p, 90.0);

  Square2(B, Segment2(C, B).rotate(_90)).plot(p);
  Square2(A, Segment2(C, A).rotate(-_90)).plot(p);
  Square2(B, Segment2(A, B).rotate(-_90)).plot(p);

  // Names

  p.font("Times-Italic", FN_NORMAL+6.0);
  p.string(165.0, 143.0, "a");
  p.string( 90.0, 123.0, "b");
  p.string(139.0,  53.0, "c");

  p.font("Times-Roman", FN_NORMAL-2.0);
  p.string(174.0, 149.0, "2");
  p.string( 99.0, 131.0, "2");
  p.string(148.0,  59.0, "2");

  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
