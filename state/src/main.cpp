#include <stdio.h>
#include <string>
#include <iostream>

#include "heroine.h"


int main()
{
    // Allow an object to alter its behavior when its internal state changes. The object will appear to change its class. [GoF]

    std::cout << "> start" << std::endl;
    Heroine hero;

    std::cout << "> input press down" << std::endl;
    hero.handleInput(Input::PRESS_DOWN);

    std::cout << "> input release down" << std::endl;
    hero.handleInput(Input::RELEASE_DOWN);
    
    std::cout << "> input release down" << std::endl;
    hero.handleInput(Input::RELEASE_DOWN);
    
    std::cout << "> exit" << std::endl;
};

