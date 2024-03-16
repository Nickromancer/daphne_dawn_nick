#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "compiler/utils/CompilerUtils.h"
#include "compiler/utils/LoweringUtils.h"
#include "ir/daphneir/Daphne.h"
#include "ir/daphneir/Passes.h"
#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/LLVMCommon/LoweringOptions.h"
#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/IR/BuiltinDialect.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/TypeUtilities.h"
#include "mlir/IR/UseDefLists.h"
#include "mlir/IR/Value.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Support/LLVM.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;


/* template <class BinaryOp, class IOp, class FOp>
class BinaryOpLowering final : public mlir::OpConversionPattern<BinaryOp> {
    using OpAdaptor = typename mlir::OpConversionPattern<BinaryOp>::OpAdaptor;

   public:
    BinaryOpLowering(mlir::TypeConverter &typeConverter, mlir::MLIRContext *ctx)
        : mlir::OpConversionPattern<BinaryOp>(typeConverter, ctx) {
        this->setDebugName("EwDaphneOpLowering");
    }

    mlir::LogicalResult convertEwScalar(
        BinaryOp op, OpAdaptor adaptor,
        mlir::ConversionPatternRewriter &rewriter) const {
        auto lhs = adaptor.getLhs();
        auto rhs = adaptor.getRhs();
        auto loc = op.getLoc();

        if (lhs.getType().template isa<mlir::FloatType>() &&
            rhs.getType().template isa<mlir::FloatType>()) {
            rewriter.replaceOpWithNewOp<FOp>(op.getOperation(),
                                             adaptor.getOperands());
            return mlir::success();
        }

        Value castedLhs = this->typeConverter->materializeTargetConversion(
            rewriter, loc,
            rewriter.getIntegerType(
                adaptor.getRhs().getType().getIntOrFloatBitWidth()),
            ValueRange{adaptor.getLhs()});

        Value castedRhs = this->typeConverter->materializeTargetConversion(
            rewriter, loc,
            rewriter.getIntegerType(
                adaptor.getRhs().getType().getIntOrFloatBitWidth()),
            ValueRange{adaptor.getRhs()});

        Value binaryOp = rewriter.create<IOp>(loc, castedLhs, castedRhs);

        Value res = this->typeConverter->materializeSourceConversion(
            rewriter, loc, lhs.getType(), ValueRange{binaryOp});

        rewriter.replaceOp(op, res);
        return mlir::success();
    }

}; */

struct AddTwoPass : public PassWrapper<AddTwoPass, OperationPass<ModuleOp>> 
{
    explicit AddTwoPass() {}
    void runOnOperation() final;
};

void AddTwoPass::runOnOperation() {
//TODO add implementation.
//Operation *op = getOperation();

}

std::unique_ptr<mlir::Pass> mlir::daphne::createAddTwoPass() {
    return std::make_unique<AddTwoPass>();
}

