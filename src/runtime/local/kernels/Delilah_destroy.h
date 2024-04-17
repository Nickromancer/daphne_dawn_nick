

int destroy_kernel(DCTX(ctx)) {
    io_uring_queue_exit(ctx->ring);
    close(ctx->fd);

    return 0;
}