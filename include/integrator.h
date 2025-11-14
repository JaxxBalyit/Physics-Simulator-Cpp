#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#pragma once
#include "physics.h"

State eulerStep(const State& s, double m, double rho, double Cd, double A, double dt);
State rk4Step(const State& s, const Params& p, double dt);

#endif // INTEGRATOR_H