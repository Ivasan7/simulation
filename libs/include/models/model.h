#ifndef MODEL_H
#define MODEL_H

#include <memory>

class Model
{
    public:
        Model();
        ~Model();
        Model(Model&& sim) noexcept;
        Model& operator=(Model&& model) noexcept;
        int getInput(float input);
        int update();
        void showOutput();
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
};


#endif
