#pragma once

#include <mlir/IR/Builders.h>
#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

template<typename VTRes, typename VTLhs, typename VTRhs>
    VTRes addTwo(VTLhs lhs, VTRhs rhs, DCTX(ctx)) {
        VTRes res = static_cast<VTLhs>(lhs) + static_cast<VTRhs>(rhs); // Dereference pointers and then add
        //std::cout << res << std::endl; // Print the result
        return static_cast<VTRes>(res);

}
