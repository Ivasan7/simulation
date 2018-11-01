#include "model.h"
#include <iostream>

    Model::Model()
    :state(0)
    , input(0)
    , output(0)
    {}
    
    void Model::getInput(int input)
    {
        this->input = input;
    }

    void Model::update()
    {
        this->state = this->state + 2* this->input;
    }

    void Model::showOutput()
    {
        std::cout << "The output of the model is " << this->state << std::endl;
    }
