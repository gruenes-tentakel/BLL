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
  Segment2(A,B).plot_label(p, "c");
  
  // Plots
  Triangle2(A, G, N).plot(p);
  Triangle2(A, B, C).plot(p);
  Triangle2(B, L, D).plot(p);
  Segment2(N, L).plot(p);
  Circle2(Point2(82.0,124.0), 1.0).plot(p);
  Circle2(Point2(209.0,151.0), 1.0).plot(p);
  Circle2(Point2(108.0,121.0), 0.5).plot(p);
  
  // Names
  p.font("Times-Italic", FN_NORMAL - 2.0);
  A.plot_label(p, "A", B, C);
  B.plot_label(p, "B", A, C);
  C.plot_label(p, "C", A, B, 0, 3);
  D.plot_label(p, "D", L, B);
  G.plot_label(p, "G", A, N);
  N.plot_label(p, "N", A, C, 2, 4);
  L.plot_label(p, "L", B, D, 2, 4);
  Segment2(B, L).plot_angle(p, 90.0);
  Segment2(A, B).plot_angle(p, 90.0);
  Segment2(A, C).plot_angle(p, 90.0, 8);
  Segment2(C, A).plot_angle(p, 90.0);
  Line2(A, B).plot_angle(p, Line2(A,C),16);
  Line2(A, N).plot_angle(p, Line2(A,G),16);
  Line2(A, C).plot_angle(p, Line2(A,N),26);
  Line2(B, D).plot_angle(p, Line2(B,L),26);
  Line2(D, L).plot_angle(p, Line2(D,B),21);
  Line2(G, A).plot_angle(p, Line2(G,N),21);
  Segment2(A,B).plot_label(p, "c",0,2);
  Segment2(B,D).plot_label(p, "a",0,2);
  Segment2(G,A).plot_label(p, "b",0,2);
  
  p.font("Times", FN_NORMAL-2);  
  p.string(200,146,"45");
  p.string(73,118,"45");
  p.font("Times", FN_NORMAL-4);
  p.string(101,117,"90 -");
  p.font("Symbol", FN_NORMAL-2);  
  p.string(107, 102, "a");
  p.string(91, 108, "a");
  p.string(182, 114, "b");
  p.font("Symbol", FN_NORMAL-4);  
  p.string(101, 111, "a");
  p.expand(1.0, 1.0, 1.0, 1.0, false);
}
