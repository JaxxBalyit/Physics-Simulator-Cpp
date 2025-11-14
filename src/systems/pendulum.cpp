#include "pendulum.h"
#include "utils.h"
#include <cmath>
#include <vector>
#include <iostream>

struct PendulumState {
  double theta;
  double omega;
};

PendulumState eulerStepPendulum(const PendulumState& s, double g, double L, double dt) {
  PendulumState ns;
  ns.omega = s.omega - (g / L) * std::sin(s.theta) * dt;
  ns.theta = s.theta + s.omega * dt;
  return ns;
}

PendulumState rk4StepPendulum(const PendulumState& s, double g, double L, double dt) {
  auto deriv = [&](const PendulumState& st) {
    PendulumState d;
    d.theta = st.omega;
    d.omega = -(g / L) * std::sin(st.theta);
    return d;
  };

  PendulumState k1 = deriv(s);
  PendulumState k2 = deriv({s.theta + 0.5*dt*k1.theta, s.omega + 0.5*dt*k1.omega});
  PendulumState k3 = deriv({s.theta + 0.5*dt*k2.theta, s.omega + 0.5*dt*k2.omega});
  PendulumState k4 = deriv({s.theta + dt*k3.theta,    s.omega + dt*k3.omega});

  PendulumState out;
  out.theta = s.theta + (dt/6.0)*(k1.theta + 2*k2.theta + 2*k3.theta + k4.theta);
  out.omega = s.omega + (dt/6.0)*(k1.omega + 2*k2.omega + 2*k3.omega + k4.omega);
  return out;
}

void simulatePendulum(const std::string& integrator){
  double dt = 0.01, t = 0.0;
  double g = 9.81, L = 1.0;
  PendulumState s = {M_PI/4, 0.0}; // 45°

  std::vector<PendulumState> results;
  for (int i = 0; i < 2000; i++) {
    results.push_back(s);
    s = integrator == "euler" ? eulerStepPendulum(s, g, L, dt) : rk4StepPendulum(s, g, L, dt);
    t += dt;
  }

  std::ofstream file("data/pendulum.csv");
  file << "theta,omega\n";
  for (auto& r : results) file << r.theta << "," << r.omega << "\n";
  file.close();

  std::cout << "Simulation finished. Data saved to data/pendulum.csv\n";
}