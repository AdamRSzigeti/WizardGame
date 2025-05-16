#include <iostream>  
#include "game.hpp"  
#include "DEFINITIONS.hpp"  

int main()  
{  
    // Fix: Assign the result of Sziad::game to a named variable to avoid the error.  
    auto gameInstance = Sziad::game(SCREEN_HEIGHT, SCREEN_HEIGHT, "Wizard Game");  

    return EXIT_SUCCESS;  
}
