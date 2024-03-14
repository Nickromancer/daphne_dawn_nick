#include <ir/daphneir/Daphne.h>
#include <ir/daphneir/Passes.h>

#include <mlir/Pass/Pass.h>

using namespace mlir;

struct AddTwoPass : public PassWrapper<AddTwoPass, OperationPass<ModuleOp>> 
{
    explicit AddTwoPass() {}
    void runOnOperation() final;
};

void AddTwoPass::runOnOperation() {
//TODO add implementation.
}

std::unique_ptr<mlir::Pass> mlir::daphne::createAddTwoPass() {
    return std::make_unique<AddTwoPass>();
}