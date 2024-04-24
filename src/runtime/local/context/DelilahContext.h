#pragma once

#include <runtime/local/context/DaphneContext.h>
#include <cassert>
#include <iostream>
#include <memory>
#include <liburing.h>
#include <string>

using std::string;


class DelilahContext : public IContext {
    int device_id = -1;

    explicit DelilahContext(int id) : device_id(id) {
	 
	}
public:
    struct io_uring ring;
    struct io_uring_sqe* sqe;
    struct io_uring_cqe* cqe;
    struct io_uring_params p = {};
    int fd = -1;
    int ret = -1;

    static std::unique_ptr<IContext> createDelilahContext(int id);

private:
    void init();
};