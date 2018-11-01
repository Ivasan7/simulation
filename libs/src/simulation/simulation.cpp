#include "simulation.h"
#include "model.h"

#include <vector>

struct Simulation::Impl{
    std::vector<std::unique_ptr<Model>> Graph;
};

Simulation::Simulation()
:pImpl(std::make_unique<Impl>())
{}
Simulation::~Simulation() = default;
Simulation::Simulation(Simulation&& sim) noexcept = default;
Simulation& Simulation::operator=(Simulation&& sim) noexcept = default;


int Simulation::run(float simTime)
{
    int time = 0;
    initialize();
    while(time != simTime)
    {
        makeStep();
        time += 1;
    }
    return 0;
}

int Simulation::initialize()
{
    pImpl->Graph.emplace_back(std::make_unique<Model>());
    return 0;
}

int Simulation::makeStep()
{
    for (auto const& it: pImpl->Graph)
    {
        it->update();
        it->showOutput();
        it->getInput(3);
    }
    return 0;
}