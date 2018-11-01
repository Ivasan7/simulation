#ifndef MODEL_H
#define MODEL_H

class Model
{
    private:
    int state;
    int input;
    int output;
    public:
    Model();
    void getInput(int input);
    void update();
    void showOutput();
};


#endif
