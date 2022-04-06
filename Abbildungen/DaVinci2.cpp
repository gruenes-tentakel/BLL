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
  Triangle2(A, J, C).plot(p);
  Triangle2(K, H, Ce).plot(p);
  Segment2(A, H).plot(p);
  Segment2(J, K).plot(p);
  Circle2(Point2(124, 124), 1).plot(p);
  Circle2(Point2(151, 0), 1).plot(p);
  
  // Names
  p.font("Times-Italic", FN_NORMAL - 2.0);
  A.plot_label(p, "A", H, C, 0, 0);
  C.plot_label(p, "C", A, J, 3, 3);
  H.plot_label(p, "H", A, Ce, -2, 4);
  J.plot_label(p, "J", K, A, 2, -1);
  K.plot_label(p, "K", J, H, 2, 4);
  Ce.plot_label(p, "C'", H, K, -6, 1);
  Segment2(H, Ce).plot_label(p, "a", 0, 2);
  Segment2(A, H).plot_label(p, "c", 0, 2);
  Segment2(C, A).plot_label(p, "b", 0, 2);
  Segment2(H, K).plot_angle(p, 90.0);
  Segment2(A, H).plot_angle(p, 90.0);
  Line2(A, J).plot_angle(p, Line2(A,C),16);
  Line2(H, Ce).plot_angle(p, Line2(H,K),24);
  Line2(C, A).plot_angle(p, Line2(C,J),20);
  Line2(Ce, K).plot_angle(p, Line2(Ce,H),23);
  
  p.font("Times", FN_NORMAL-2);
  p.string(115,119,"45");
  p.string(142,-5,"45");
  
  p.font("Symbol", FN_NORMAL-2);  
  p.string(107, 103, "a");
  p.string(115, 13, "b");

  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
