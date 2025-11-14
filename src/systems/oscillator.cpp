#include "oscillator.h"
#include "utils.h"
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

OscillatorState rk4StepOscillator(const OscillatorState& s, double m, double b, double k, double dt) {
  auto deriv = [&](const OscillatorState& st) {
    OscillatorState d;
    d.x = st.v;
    d.v = (-b * st.v - k * st.x) / m;
    return d;
  };

  OscillatorState k1 = deriv(s);
  OscillatorState k2 = deriv({s.x + 0.5*dt*k1.x, s.v + 0.5*dt*k1.v});
  OscillatorState k3 = deriv({s.x + 0.5*dt*k2.x, s.v + 0.5*dt*k2.v});
  OscillatorState k4 = deriv({s.x + dt*k3.x,    s.v + dt*k3.v});

  OscillatorState out;
  out.x = s.x + (dt/6.0)*(k1.x + 2*k2.x + 2*k3.x + k4.x);
  out.v = s.v + (dt/6.0)*(k1.v + 2*k2.v + 2*k3.v + k4.v);
  return out;
}

void simulateOscillator(const std::string& integrator){
  double m = 1.0, b = 0.2, k = 10.0, dt = 0.01;
  OscillatorState s = {1.0, 0.0}; // initial displacement

  std::vector<OscillatorState> results;
  for (int i = 0; i < 2000; i++) {
    results.push_back(s);
    s = integrator == "euler" ? eulerStepOscillator(s, m, b, k, dt) : rk4StepOscillator(s, m, b, k, dt);
  }

  std::ofstream file("data/oscillator.csv");
  file << "x,v\n";
  for (auto& r : results) file << r.x << "," << r.v << "\n";
  file.close();

  std::cout << "Simulation finished. Data saved to data/oscillator.csv\n";
}