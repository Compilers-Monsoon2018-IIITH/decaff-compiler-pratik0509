#ifndef __CODEGENERATOR__
#define __CODEGENERATOR__

#include "iostream"
#include "llvm/IR/Value.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#define INT_WIDTH 32
#define CHAR_WIDTH 8
#define BOOL_WIDTH 8


extern llvm::LLVMContext the_context;
extern llvm::IRBuilder<> Builder;
extern std::unique_ptr<llvm::Module> the_module;
extern std::map<std::string, llvm::Value *> named_values;

llvm::Value *LogErrorV(const char *str);

#endif