#include "model.h" 
#include <iostream>
int main(int argc, char* argv[])
{
    std::cout << "Starting ..." << std::endl;
    Model test;
    test.showOutput();
    test.update(20);
    test.showOutput();
    std::cout << "Done!" << std::endl;
    return 0;
}
