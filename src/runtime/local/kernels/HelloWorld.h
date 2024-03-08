#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

void helloWorld(DCTX(ctx)) {
    std::cout << "Hello World";
}


