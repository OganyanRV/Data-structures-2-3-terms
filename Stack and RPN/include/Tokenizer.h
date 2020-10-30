// Copyright 2020 Oganyan Robert

#include "../include/Token.h"
#ifndef STACK_INCLUDE_TOKENIZER_H_
#define STACK_INCLUDE_TOKENIZER_H_
class Tokenizer
{
 public:
  Tokenizer(const char* _str);
  ~Tokenizer();
  Token Next();
 private:
  char* str;
  Token* postfix;
  int ind;
};

#endif //STACK_INCLUDE_TOKENIZER_H_
