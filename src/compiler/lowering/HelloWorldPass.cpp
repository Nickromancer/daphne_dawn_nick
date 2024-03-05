#include <ir/daphneir/Daphne.h>
#include <ir/daphneir/Passes.h>

#include <mlir/Pass/Pass.h>
#include <iostream>


using namespace mlir;

struct HelloWorldPass : public PassWrapper<HelloWorldPass, OperationPass<ModuleOp>> 
{
    explicit HelloWorldPass() {}
    void runOnOperation() final;
};

void HelloWorldPass::runOnOperation() {
//TODO add implementation.
}

std::unique_ptr<mlir::Pass> mlir::daphne::createHelloWorldPass() {
    return std::make_unique<HelloWorldPass>();
}
