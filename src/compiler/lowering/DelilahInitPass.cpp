#include <ir/daphneir/Daphne.h>
#include <ir/daphneir/Passes.h>

#include <mlir/Pass/Pass.h>
#include <iostream>


using namespace mlir;

struct DelilahInitPass : public PassWrapper<DelilahInitPass, OperationPass<ModuleOp>> 
{
    explicit DelilahInitPass() {}
    void runOnOperation() final;
};

void DelilahInitPass::runOnOperation() {
//TODO add implementation.
}

std::unique_ptr<mlir::Pass> mlir::daphne::createDelilahInitPass() {
    return std::make_unique<DelilahInitPass>();
}
