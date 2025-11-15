#include "integrator.h"

State eulerStep(const State& s, double m, double rho, double Cd, double A, double dt)
{
  vector2D Fg = gravityForce(m);
  vector2D Fd = dragForce(s.velocity, rho, Cd, A);
  vector2D a  = (Fg + Fd) * (1.0 / m);

  State next;
  next.velocity = s.velocity + a * dt;
  next.position = s.position + s.velocity * dt;   // explicit Euler
  return next;
}

State rk4Step(const State& s, const Params& p, double dt)
{
  auto forces = [&](const State& st) -> vector2D {
    vector2D Fg = gravityForce(p.m);
    vector2D Fd = dragForce(st.velocity, p.rho, p.Cd, p.A);
    return (Fg + Fd) * (1.0 / p.m);
  };

  vector2D k1v = forces(s);
  vector2D k1x = s.velocity;

  State s2 = { s.position + k1x * (0.5*dt), s.velocity + k1v * (0.5*dt) };
  vector2D k2v = forces(s2);
  vector2D k2x = s2.velocity;

  State s3 = { s.position + k2x * (0.5*dt), s.velocity + k2v * (0.5*dt) };
  vector2D k3v = forces(s3);
  vector2D k3x = s3.velocity;

  State s4 = { s.position + k3x * dt, s.velocity + k3v * dt };
  vector2D k4v = forces(s4);
  vector2D k4x = s4.velocity;

  State next;
  next.position = s.position + (k1x + k2x*2.0 + k3x*2.0 + k4x) * (dt/6.0);
  next.velocity = s.velocity + (k1v + k2v*2.0 + k3v*2.0 + k4v) * (dt/6.0);
  return next;
}