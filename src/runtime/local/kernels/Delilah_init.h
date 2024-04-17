#pragma once

#include <mlir/IR/Builders.h>
#include <runtime/local/context/DaphneContext.h>
#include <runtime/local/context/DelilahContext.h>
#include <ir/daphneir/Daphne.h>
#include <liburing.h>



int delilahInit(DCTX(ctx)) 
{
    //Delilah Context contains:
    // struct io_uring ring;
    // struct io_uring_sqe* sqe;
    // struct io_uring_cqe* cqe;
    // struct io_uring_params p = {};
    // int ret, fd

    int ret, fd;

    auto DelilahContext = ctx->getDelilahContext(0);  
    fd = DelilahContext->fd;

    //----------------------------------------------
    // Create io_uring queue
    //---------------------------------------------

    DelilahContext->p.flags = IORING_SETUP_SQE128;
  
    /* Initialize io_uring queue with four entries */
    DelilahContext->ret = io_uring_queue_init(4, &DelilahContext->ring, DelilahContext->p.flags);

    if (DelilahContext->ret) {
    fprintf(stderr, "Cannot init queue\n");
    return 2;
    }

    /* Get the next free submission queue entry or fail */
    DelilahContext->sqe = io_uring_get_sqe(&DelilahContext->ring);

    if (!DelilahContext->sqe) {
    fprintf(stderr, "Cannot get SQE\n");
    return 4;
    }

    //TODO: make the rest

    return 0;
}