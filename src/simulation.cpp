#include "simulation.h"
#include "systems/projectile.h"
#include "systems/pendulum.h"
#include "systems/oscillator.h"
#include <iostream>

void runSimulation(const std::string& systemName) {
  if (systemName == "projectile") {
    simulateProjectile();
  } else if (systemName == "pendulum") {
    simulatePendulum();
  } else if (systemName == "oscillator") {
    simulateOscillator();
  } else {
    std::cerr << "Invalid system name. Options: projectile | pendulum | oscillator\n";
  }
}