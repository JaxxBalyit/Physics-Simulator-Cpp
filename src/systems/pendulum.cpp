#include "pendulum.h"
#include "../utils.h"
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

void simulatePendulum(){
  double dt = 0.01, t = 0.0;
  double g = 9.81, L = 1.0;
  PendulumState s = {M_PI/4, 0.0}; // 45°

  std::vector<PendulumState> results;
  for (int i = 0; i < 2000; i++) {
    results.push_back(s);
    s = eulerStepPendulum(s, g, L, dt);
    t += dt;
  }

  std::ofstream file("data/pendulum.csv");
  file << "theta,omega\n";
  for (auto& r : results) file << r.theta << "," << r.omega << "\n";
  file.close();

  std::cout << "Simulation finished. Data saved to data/pendulum.csv\n";
}