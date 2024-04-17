#pragma once

#include <mlir/IR/Builders.h>
#include <runtime/local/context/DaphneContext.h>
#include <runtime/local/context/DelilahContext.h>
#include <ir/daphneir/Daphne.h>
#include <liburing.h>
#include <iostream>

int destroy_kernel(DCTX(ctx)) {
    auto DelilahContext = ctx->getDelilahContext(0);  
    io_uring_queue_exit(&DelilahContext->ring);
    close(DelilahContext->fd);

    return 0;
}