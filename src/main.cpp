#include "simulation.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PhysSim <system>\n";
        std::cerr << "Available: projectile | pendulum | oscillator\n";
        return 1;
    }
    
    std::string system = argv[1];
    runSimulation(system);
    return 0;
}