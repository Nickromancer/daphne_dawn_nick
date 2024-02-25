/*
 * add a new compiler pass that can replace a DAG of operations by a CompStorageOP.
 * TODO needs to be implemented.
 */

#include "ir/daphneir/Daphne.h"
#include "ir/daphneir/Passes.h"

// Not sure about these imports.
#include "mlir/Dialect/Arith/IR/Arith.h"
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;

//Should anything be added here?

namespace {

// Is 'mlir::' needed?
struct PlaceholderPass : public PassWrapper<PlaceholderPass, OperationPass<ModuleOp>> {
//TODO add implementation.
    void runOnOperation() final;
};

} // end anonymous namespace

void PlaceholderPass::runOnOperation() {
//TODO add implementation.
}

std::unique_ptr<mlir::Pass> mlir::daphne::createCompStoragePass() {
    return std::make_unique<PlaceholderPass>();
}
