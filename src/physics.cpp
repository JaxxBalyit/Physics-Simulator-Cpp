#include "physics.h"

vector2D gravityForce(double m) {
  return {0, -9.81 * m};
}

vector2D dragForce(const vector2D& v, double rho, double Cd, double A) {
  double vmag = std::sqrt(v.x*v.x + v.y*v.y);
  double factor = -0.5 * rho * Cd * A * vmag;
  return {factor * v.x, factor * v.y};
}