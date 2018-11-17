#ifndef __CODEGENERATOR__
#define __CODEGENERATOR__

#include "iostream"
#include "llvm/IR/Value.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"

#define INT_WIDTH 32
#define CHAR_WIDTH 8
#define BOOL_WIDTH 1


extern llvm::LLVMContext the_context;
extern llvm::IRBuilder<> builder;
extern llvm::Module* the_module;
extern std::map<std::string, llvm::Value *> named_values;

llvm::Value *log_error(std::string);

#endif