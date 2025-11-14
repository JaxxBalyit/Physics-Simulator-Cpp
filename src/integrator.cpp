#include "integrator.h"

State eulerStep(const State& s, const Params& p, double dt) {
  // gravity
  vector2D g(0, -9.81);

  // drag force
  vector2D Fd = dragForce(s.velocity, p.rho, p.Cd, p.A);

  // total acceleration: a = (Fg + Fd) / m
  vector2D a = g + (Fd / p.m);

  // Euler update
  State next;
  next.position = s.position + s.velocity * dt;
  next.velocity = s.velocity + a * dt;

  return next;
}

// TODO: implement properly
State rk4Step(const State& s, const Params& p, double dt) {
  // Implement later
  return s;
}