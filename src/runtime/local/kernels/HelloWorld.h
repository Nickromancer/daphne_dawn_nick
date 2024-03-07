#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

template<>
void printHelloWorld() {
    std::cout << "Hello World";
}


