#include "oscillator.h"
#include "../utils.h"
#include <vector>
#include <iostream>

struct OscillatorState {
  double x;
  double v;
};

OscillatorState eulerStepOscillator(const OscillatorState& s, double m, double b, double k, double dt) {
  OscillatorState ns;
  double a = (-b * s.v - k * s.x) / m;
  ns.v = s.v + a * dt;
  ns.x = s.x + s.v * dt;
  return ns;
}

void simulateOscillator(){
  double m = 1.0, b = 0.2, k = 10.0, dt = 0.01;
  OscillatorState s = {1.0, 0.0}; // initial displacement

  std::vector<OscillatorState> results;
  for (int i = 0; i < 2000; i++) {
    results.push_back(s);
    s = eulerStepOscillator(s, m, b, k, dt);
  }

  std::ofstream file("data/oscillator.csv");
  file << "x,v\n";
  for (auto& r : results) file << r.x << "," << r.v << "\n";
  file.close();

  std::cout << "Simulation finished. Data saved to data/oscillator.csv\n";
}