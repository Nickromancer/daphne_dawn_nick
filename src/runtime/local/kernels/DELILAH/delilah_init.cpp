#pragma once

#include <mlir/IR/Builders.h>
#include <runtime/local/context/DaphneContext.h>
#include <runtime/local/context/DelilahContext.h>
#include <ir/daphneir/Daphne.h>

int delilahInit(DCTX(ctx)) 
{
    struct io_uring ring;
    struct io_uring_sqe* sqe;
    struct io_uring_cqe* cqe;
    struct io_uring_params p = {};
    struct delilah_dma* dma;
    struct delilah_exec* exec;

    int ret, fd;
    char *src, *dst, *prog;

    /* Allocate a buffer for initial data, final data and program */
    src = malloc(BUF_SIZE * sizeof(char));
    dst = malloc(BUF_SIZE * sizeof(char));
    prog = malloc(16 * sizeof(char));

    if (!src || !dst || !prog) {
    fprintf(stderr, "Failed to allocate buffers\n");
    return 1;
    }
    
    /* Set initial data buffer to 0xFF */
    memset(src, 0xFF, BUF_SIZE);
    memset(dst, 0x00, BUF_SIZE);

    //TODO: Create an eBPF program
    memset(prog, 0, 16);

    p.flags = IORING_SETUP_SQE128;
  
    /* Initialize io_uring queue with four entries */
    ret = io_uring_queue_init(4, &ring, p.flags);

    if (ret) {
    fprintf(stderr, "Cannot init queue\n");
    return 2;
    }
    
    fd = DelilahContext->fd;

    /* Get the next free submission queue entry or fail */
    sqe = io_uring_get_sqe(&ring);
    
    if (!sqe) {
    fprintf(stderr, "Cannot get SQE\n");
    return 4;
    }

    //TODO: make the rest



      

    DelilahContext* DelilahContext = ctx->getDelilahContext(0); 
    return 0;
}