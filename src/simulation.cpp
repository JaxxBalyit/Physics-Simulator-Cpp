#include "simulation.h"
#include "projectile.h"
#include "pendulum.h"
#include "oscillator.h"
#include <iostream>

void runSimulation(const std::string& systemName, const std::string& integrator) {
  if (systemName == "projectile") {
    simulateProjectile(integrator);
  } else if (systemName == "pendulum") {
    simulatePendulum(integrator);
  } else if (systemName == "oscillator") {
    simulateOscillator(integrator);
  } else {
    std::cerr << "Invalid system name. Options: projectile | pendulum | oscillator\n";
  }
}