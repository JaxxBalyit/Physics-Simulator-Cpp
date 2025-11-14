#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "physics.h"

State eulerStep(const State& s, double m, double rho, double Cd, double A, double dt);

#endif // INTEGRATOR_H