#include <iostream>
#include "CustomLib.h"
#include "Result.h"


void CustomLib::ToString1(){
    std::cout << "ToString1 \n"; 

    Result rs;

    rs.value = 100;

    std::cout << "Value: " << rs.value << std::endl; 
}

void CustomLib::ToString2(){

    std::cout << "ToString2 \n"; 

    Result rs;

    rs.value = 200;

    std::cout << "Value: " << rs.value << std::endl; 
}