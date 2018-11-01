#include "model.h" 
#include "simulation.h"
#include <iostream>
int main(int argc, char* argv[])
{
    std::cout << "Starting ..." << std::endl;
    Simulation test;
    test.run(1);
    std::cout << "Done!" << std::endl;
    return 0;
}
