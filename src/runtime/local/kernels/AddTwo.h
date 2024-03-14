#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

template<class VTRes, class VTLhs, class VTRhs>
VTRes addTwo(VTLhs lhs, VTRhs rhs, DCTX(ctx)) {
        return lhs + rhs;
}
