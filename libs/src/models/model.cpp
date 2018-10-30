#include "model.h"
#include <iostream>

    Model::Model()
    :state(0)
    , output(0)
    {}
    void Model::update(int input)
    {
        this->state = this->state + 2* input;
    }
    void Model::showOutput()
    {
        std::cout << "The output of the model is " << this->state << std::endl;
    }
