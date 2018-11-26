#ifndef __CODEGENERATOR__
#define __CODEGENERATOR__

#include "iostream"
#include "stack"
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
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/GlobalVariable.h"

#define INT_WIDTH   32
#define CHAR_WIDTH  8
#define BOOL_WIDTH  1
#define SUCCESS     0
#define STEP_DEFAULT 1
#define CALLOUT_STR "callout"

extern llvm::LLVMContext the_context;
extern llvm::IRBuilder<> *builder;
extern llvm::Module* the_module;
extern std::map<std::string, llvm::AllocaInst*> named_values;

struct loop_metadata {
    llvm::Value* end_cond;
    std::string iter_name;
    llvm::PHINode* phi;
    llvm::BasicBlock* afterloop_bb;
    llvm::BasicBlock* loop_bb;

    loop_metadata(llvm::Value* end, std::string itr, llvm::PHINode* phifunc,
            llvm::BasicBlock* afterloop, llvm::BasicBlock* loop):
            end_cond(end), iter_name(itr), phi(phifunc), afterloop_bb(afterloop), loop_bb(loop) {}
};
extern std::stack<loop_metadata*> loop_stack;

llvm::Value *log_error(std::string);
llvm::AllocaInst *create_entry_alloc(llvm::Function*, std::string, std::string);

#endif