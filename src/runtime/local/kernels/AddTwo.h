#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <ir/daphneir/Daphne.h>

#include <iostream>

template<class TRes, class TLhs, class TRhs>
TRes addTwo(TRes *& res, const TLhs * lhs, const TRhs * rhs, DCTX(ctx)) {
        TRes result = lhs + rhs;
        return static_cast<bool>(result);
}
