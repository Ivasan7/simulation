#ifndef MODEL_H
#define MODEL_H

class Model
{
    private:
    int state;
    int output;
    Model();
    public:
    void update(int input);
    void showOutput();
};


#endif