#ifndef PHYSICS_H
#define PHYSICS_H

#include <cmath>
#include <vector>

struct vector2D {
  double x, y;

  vector2D() : x(0), y(0) {}
  vector2D(double x_, double y_) : x(x_), y(y_) {}

  vector2D operator+(const vector2D& v) const { return {x + v.x, y + v.y}; }
  vector2D operator-(const vector2D& v) const { return {x - v.x, y - v.y}; }
  vector2D operator*(double s) const { return {x * s, y * s}; }
  vector2D operator/(double s) const { return {x / s, y / s}; }
};

struct State {
  vector2D position;
  vector2D velocity;
};

struct Params {
  double m, rho, Cd, A;
};

vector2D gravityForce(double m);
vector2D dragForce(const vector2D& v, double rho, double Cd, double A);

#endif