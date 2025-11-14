#include "integrator.h"

State eulerStep(const State& s, double m, double rho, double Cd, double A, double dt) {
  vector2D Fg = gravityForce(m);
  vector2D Fd = dragForce(s.velocity, rho, cD, A);
  vector2D acc = {(Fg.x + Fd.x)/m, (Fg.y + Fd.y)/m};

  State newS;
  newS.velocity = s.velocity + acc * dt;
  newS.position = s.position + s.velocity * dt;
  return newS;
}