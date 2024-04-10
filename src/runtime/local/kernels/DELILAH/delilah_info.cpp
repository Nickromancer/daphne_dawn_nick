#include <linux/types.h>

struct delilah_device
{
  __u32 ehver;
  __u8 eheng;
  __u8 ehpslot;
  __u8 ehdslot;
  __u64 ehpssze;
  __u64 ehdssze;
  __u64 ehsssze;
};

int delilahInfo(DCTX(ctx)) 
{
    //delilahInit(ctx);

    struct delilah_device *info = malloc(sizeof(struct delilah_device));


    /* Submit a DMA command to 0th program slot  */
    ctx->sqe->opcode = IORING_OP_URING_CMD;
    ctx->sqe->fd = fd;
    ctx->sqe->cmd_op = DELILAH_OP_INFO;
    memcpy(&ctx->sqe->cmd, &info, sizeof(uint64_t));

    ctx->ret = io_uring_submit(&ctx->ring);
    if (ctx->ret < 0) {
        fprintf(stderr, "Cannot submit to uring: %s\n", strerror(-ctx->ret));
        return 5;
    }

    /* Wait for the device to confirm that the program was loaded */
    ctx->ret = io_uring_wait_cqe(&ctx->ring, &ctx->cqe);
    if (ctx->ret < 0) {
      fprintf(stderr, "Cannot wait for CQE: %i\n", ctx->ret);
      return 6;
    }

    /* Inform io_uring that we've received the completion */
    io_uring_cqe_seen(&ctx->ring, ctx->cqe);

    printf("Delilah device has %i engines\n", info->eheng);
    printf("Delilah device has %i program slots of size %llu\n", info->ehpslot, info->ehpssze);
    printf("Delilah device has %i data slots of size %llu\n", info->ehdslot, info->ehdssze);


    //destroy_kernel(*ctx->ring, ctx->fd, *ctx->src, *ctx->dst, *ctx->prog)
}