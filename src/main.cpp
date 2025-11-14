#include "simulation.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2 || strcmp(argv[1], "--help")==0) {
        std::cerr << "Usage: ./PhysSim <projectile|pendulum|oscillator> [--integrator=euler|rk4]\n";
        return 1;
    }
    
    std::string system = argv[1];
    runSimulation(system);
    return 0;
}