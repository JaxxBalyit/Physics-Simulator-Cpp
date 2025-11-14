#include "simulation.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    // Help or missing main argument
    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        std::cerr << "Usage: ./PhysSim <projectile|pendulum|oscillator> [--integrator=euler|rk4]\n";
        return 1;
    }

    std::string system = argv[1];
    std::string integrator = "euler"; // default

    // Optional second argument
    if (argc >= 3) {
        std::string arg = argv[2];

        // Expected format: --integrator=...
        std::string prefix = "--integrator=";
        if (arg.rfind(prefix, 0) == 0) {
            integrator = arg.substr(prefix.size());

            if (integrator != "euler" && integrator != "rk4") {
                std::cerr << "Error: integrator must be 'euler' or 'rk4'.\n";
                return 1;
            }
        }
        else {
            std::cerr << "Unknown option: " << arg << "\n";
            return 1;
        }
    }

    runSimulation(system, integrator);
    return 0;
}