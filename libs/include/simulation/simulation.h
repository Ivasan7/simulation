#ifndef SIMULATION_H
#define SIMULATION_H

//#include "boost/graph/adjacency_list.hpp"

#include <memory>

class Simulation
{
    public:
        Simulation();
        ~Simulation();
        Simulation(Simulation&& sim) noexcept;
        Simulation& operator=(Simulation&& sim) noexcept;
        int initialize();
        int makeStep();
        int terminate();
        int run(float simTime);
        
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;

};

#endif