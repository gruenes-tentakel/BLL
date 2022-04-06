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

  // Definitions & Constructions
  Point2 A(100.0, 100.0);
  Point2 B = A.translate(80.0, 0.0);
  Point2 C(Circle2(Segment2(A, B).point(0.5), 0.5 * A.dist(B)).periphery(115.0));
  Point2 X(Line2(A, B).nearest(C));
  Point2 Y(X.x(), X.y() - A.dist(B));
  Triangle2 unten = Triangle2(A, B, C).rotate(A, 180).translate(80,-80);
  Segment2 g = Segment2(Point2(64.0, 123.0), Point2( 216.0, 157.0));
  Segment2 h = Segment2(unten.third(), C);
  Square2 a_2 = Square2(B, Segment2(C, B).rotate(_90));
  Square2 b_2 = Square2(A, Segment2(C, A).rotate(-_90));
  Square2 c_2 = Square2(B, Segment2(A, B).rotate(-_90));
  Point2 E = a_2.third();
  Point2 D = a_2.fourth();
  Point2 F = b_2.third();
  Point2 G = b_2.second();
  Point2 H = c_2.third();
  Point2 I = c_2.second();
  Point2 J = Line2(h.first(), h.second()).intersect(Line2(A, B));
  Point2 K = Line2(h.first(), h.second()).intersect(Line2(H, I));
  Point2 L = Line2(Point2(64.0, 123.0), Point2( 216.0, 157.0)).intersect(Line2(B, B.translate(0, 10)));
  Point2 M = c_2.center();
  Point2 N = Line2(Point2(64.0, 123.0), Point2( 216.0, 157.0)).intersect(Line2(A, A.translate(0, 10)));
  Point2 Ce = unten.third();
  
  // Plots
  
  Triangle2(A, B, C).plot(p);
  unten.plot(p);
  a_2.plot(p);
  b_2.plot(p);
  c_2.plot(p);
  Segment2(unten.third(), unten.first()).plot_angle(p, 90.0);
  Segment2(C, A).plot_angle(p, 90.0);
  g.stretch_centered(1.3).plot(p);
  h.stretch_centered(1.3).plot(p);
  Segment2(A, N).plot(p);
  Segment2(B, L).plot(p);
  
  // Names
  p.font("Times-Italic", FN_NORMAL - 2.0);
  A.plot_label(p, "A", B, C);
  B.plot_label(p, "B", A, C);
  C.plot_label(p, "C", A, B, 3, 8);
  D.plot_label(p, "D", B, E, 0, -3);
  E.plot_label(p, "E", C, D, 0, 2);
  F.plot_label(p, "F", C, G, 0, 2);
  G.plot_label(p, "G", A, F, 1, 8);
  H.plot_label(p, "H", A, K, -2, 3);
  I.plot_label(p, "I", H, B, 2, 3);
  J.plot_label(p, "J", A, C, 2, 0);
  K.plot_label(p, "K", H, Ce, 2, 4);
  N.plot_label(p, "N", A, C, 2, 4);
  L.plot_label(p, "L", B, D, 2, 4);
  Ce.plot_label(p, "C'", H, I, -6, 2);
  
  Circle2(M, 1.0).plot(p);
  M.plot_label(p, "M", A, B, 7, 8);
  
  p.string(C.x() - 10, C.y() + 16, "h");
  p.string(D.x() + 16, D.y() + 8, "g");

  p.font("Times-Italic", FN_NORMAL+6.0);
  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
