#include "projectile.h"
#include "physics.h"
#include "integrator.h"
#include "utils.h"
#include <cmath>
#include <vector>

void simulateProjectile(const std::string& integrator) {
  double dt = 0.01;
  double m = 0.145, Cd = 0.47, A = 0.0042, rho = 1.225;
  Params p = {m, rho, Cd, A};

  State s = {{0, 0},
            {50 * std::cos(M_PI/4), 50 * std::sin(M_PI/4)}};

  std::vector<State> trajectory;
  while (s.position.y >= 0) {
    trajectory.push_back(s);
    if (integrator == "euler")
      s = eulerStep(s, m, rho, Cd, A, dt);
    else
      s = rk4Step(s, p, dt);
  }
  saveToCSV("data/projectile.csv", trajectory);
  std::cout << "Projectile motion complete. Data saved.\n";
}