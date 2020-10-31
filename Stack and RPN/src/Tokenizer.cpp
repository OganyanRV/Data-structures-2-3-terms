#include "../include/Tokenizer.h"
#include "../include/Tstack.h"
#include "cstring"
#include <stdlib.h>

Tokenizer::Tokenizer(const char* _str) {
  str = new char[strlen(_str) + 1];
  ind = 0;
  strcpy(str, _str);

}

Tokenizer::~Tokenizer() {
  delete[] str;
}

Token Tokenizer::Next() {
  if (str[ind] == 0)
    return Token(Token::Type::kEnd);
  char cur = str[ind];
  if (!(cur >= '0' && cur <= '9')) {
    Token token(Token::Type::kSymbol, cur);
    //token.symbol = cur;
    ++ind;
    return token;
  }
  else {
    Token token(Token::Type::kNumber);
    // алгоритм чтоб узнать какое число и вернуть его
    double num;
    int begin = ind;
    while ((str[ind] >= '0' && str[ind] <= '9') || (str[ind] == '.')) ind++;
    char* number = new char[ind - begin + 1];
    strncpy(number, str + begin, ind - begin + 1);
    number[ind - begin] = '\0';
    //strcpy(number, str);
    //number[ind - begin] = 0;
    num = atof(number);
    delete[] number;
    token.number = num;
    return token;
  }
}

Token* Postfix(const char* str, int& N) {
  Tokenizer tok(str);
  Token* ans = new Token[strlen(str)];
  TStack<Token> st(strlen(str));
  Token cur = tok.Next();
  N = 0;
  while (cur.type != Token::kEnd) {
    if (cur.type == Token::kNumber) {
      ans[N] = cur;
      N++;
    }
    else {
      if (st.IsEmpty() || cur.symbol == '(')
        st.Push(cur);
      else if (cur.symbol == ')') {
        while (st.Top().symbol != '(') {
          ans[N] = st.Pop();
          N++;
        }
        st.Pop();
      }
      else if (cur.prior > st.Top().prior) {
        st.Push(cur);
      }
        else {
          while (!st.IsEmpty() && st.Top().symbol != '(' && st.Top().prior >= cur.prior) {
            ans[N] = st.Pop();
            N++;
          }
          st.Push(cur);
        }
    }
    cur = tok.Next();
  }
  while (!st.IsEmpty()) {
    ans[N] = st.Pop();
    N++;
  }
  return ans;
}


double Calculate(Token* post, int& n) {
  TStack<double> st(n);
  int i = 0;
  while (i < n) {
    if (post[i].type == Token::kSymbol) {
      if (st.GetTop() < 1)
        throw - 1;
      double op2 = st.Pop(), op1 = st.Pop(), res;
      switch (post[i].symbol)
      {
        case '-':
          res = op1 - op2;
          break;

        case '+':
          res = op1 + op2;
          break;

        case '*':
          res = op1 * op2;
          break;

        case '/':
          res = op1 / op2;
          break;

      }
      st.Push(res);
    }
    else
      st.Push(post[i].number);

    i++;
  }
  if (st.GetTop() > 1)
    throw - 1;

  return st.Pop();
}

