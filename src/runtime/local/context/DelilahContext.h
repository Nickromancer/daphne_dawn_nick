#pragma once

#include <cassert>
#include <iostream>
#include <memory>

class DelilahContext : public IContext {
    int device_id = -1;

    explicit DelilahContext(int id) : device_id(id) {
	 
	}
public:
    io_uring = NULL;
    path = "/dev/delilah0";
    fd = -1;

    static std::unique_ptr<IContext> createDelilahContext(int id);

private:
    void init();
}