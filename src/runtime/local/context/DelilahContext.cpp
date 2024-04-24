#include "runtime/local/context/DelilahContext.h"
#include <spdlog/spdlog.h>
#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024 * 1024

using namespace std;

void DelilahContext::destroy() spdlog::debug("Destroying Delilah context...");

void DelilahContext::init()
{
    spdlog::debug("creating Delilah Context...");

    /* Open Delilah device */
    fd = open(path, O_RDWR);
    if (fd < 0) {
        perror("Cannot open Delilah device");
        return 3;
    }
}
std::unique_ptr<IContext> DelilahContext::createDelilahContext(int device_id) 
{
    DelilahContext* ctx = std::unique_ptr<DelilahContext>(new DelilahContext(dev_id));
    ctx->init();

    return ctx;
}