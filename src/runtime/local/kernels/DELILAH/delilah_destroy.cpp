

int destroy_kernel(struct io_uring *ring, int fd, char *src, char *dst, char *prog) {
    io_uring_queue_exit(ring);
    close(fd);
    free(src);
    free(dst);
    free(prog);

    return 0;
}