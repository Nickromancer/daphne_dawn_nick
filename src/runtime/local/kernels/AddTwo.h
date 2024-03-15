#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

template<typename VTRes, typename VTLhs, typename VTRhs>
    void addTwo(VTRes *& res, VTLhs * lhs, VTRhs * rhs, DCTX(ctx)) {
        std::cout << *lhs << std::endl; // Print value pointed by lhs
        std::cout << *rhs << std::endl; // Print value pointed by rhs
        
        *res = *lhs + *rhs; // Dereference pointers and then add
        
        std::cout << res << std::endl; // Print the result

}
