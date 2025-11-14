#include "projectile.h"
#include "../physics.h"
#include "../integrator.h"
#include "../utils.h"
#include <cmath>
#include <vector>

void simulateProjectile() {
  double dt = 0.01;
  double m = 0.145, Cd = 0.47, A = 0.0042, rho = 1.225;
  State s = {{0, 0}, {50 * std::cos(M_PI/4), 50 * std::sin(M_PI/4)}}; // 50 m/s at 45°
 
  std::vector<State> trajectory;
  while (s.position.y >= 0) {
  trajectory.push_back(s);
    s = eulerStep(s, m, rho, Cd, A, dt);
  }

  saveToCSV("data/projectile.csv", trajectory);
  std::cout << "Projectile motion complete. Data saved.\n";
}