#include "model.h"

#include <iostream>
#include <vector>


    struct Model::Impl{
        std::vector<float> input = {5};
        std::vector<float> state = {10, 1};
        std::vector<float> output = {0};
        std::vector<float> stateCoefficients = {0, 0};
        std::vector<float> inputCoefficients = {0};
    };

    Model::Model()
    :pImpl(std::make_unique<Impl>())
    {
       float m, b, k;
       m = 1;
       b = 0.01;
       k = 0.001; 
       pImpl->stateCoefficients.at(0) = -b/m;
       pImpl->stateCoefficients.at(1) = -k/m;
       pImpl->inputCoefficients.at(0) = 1/m;
    }

    Model::~Model() = default;
    Model::Model(Model&& sim) noexcept = default;
    Model& Model::operator=(Model&& sim) noexcept = default;
    
    int Model::getInput(float input)
    {
        pImpl->input[0] = input;
        return 0;
    }

    int Model::update()
    {
        pImpl->output[0] = pImpl->stateCoefficients[0] * pImpl->state[0] +
         pImpl->stateCoefficients[1] * pImpl->state[1] +
         pImpl->inputCoefficients[0] * pImpl->input[0];  
        pImpl->state[1] = pImpl->state[0];
        pImpl->state[0] = pImpl->output[0];
        return 0;
    }

    void Model::showOutput()
    {
        std::cout << "The output of the model is " << pImpl->output[0] << std::endl;
    }
