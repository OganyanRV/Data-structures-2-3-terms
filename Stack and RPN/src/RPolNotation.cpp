//  Copyright by Oganyan Robert

#include "../include/RPolNotation.h"

RPolNotation::RPolNotation(char *form) {
  formula = form;
  size = 0;
  if (form != nullptr) {
    size = strlen(form);
  }
}

RPolNotation::~RPolNotation() {
  if (formula != nullptr) {
    delete[] formula;
  }
}

RPolNotation::RPolNotation(const RPolNotation& rpn) {
  size = rpn.size;
  if (rpn.formula != nullptr) {
    for (std::size_t i = 0; i < size; ++i) {
      formula[i] = rpn.formula[i];
    }
  }
}

Token * RPolNotation::Postfix() {
  int formulaidx=0;
  Token* ans = new Token[size];
  TStack<Token> st(size);
  Token cur = Next(formulaidx);
  int curidx = 0;
  while (cur.type != Token::kEnd) {
    if (cur.type == Token::kNumber) {
      ans[curidx] = cur;
      curidx++;
    }
    else {
      if (st.IsEmpty() || cur.symbol == '(') {
        st.Push(cur);
      } else if (cur.symbol == ')') {
        while (st.Top().symbol != '(') {
          ans[curidx] = st.Pop();
          curidx++;
        }
        st.Pop();
      } else if (cur.prior > st.Top().prior) {
        st.Push(cur);
      } else {
        while (!st.IsEmpty() && st.Top().symbol != '(' && st.Top().prior >= cur.prior) {
          ans[curidx] = st.Pop();
          curidx++;
        }
        st.Push(cur);
      }
    }
    cur = Next(formulaidx);
  }
  while (!st.IsEmpty()) {
    ans[curidx] = st.Pop();
    curidx++;
  }
  return ans;
}

Token RPolNotation::Next(int& ind) {
  char cur = formula[ind];
  // Если это конец строки
  if (cur == 0) {
    return Token(Token::Type::kEnd);
  }
  // Если это знак
  if (cur < '0' || cur > '9') {
    Token token(Token::Type::kSymbol, cur);
    ++ind;
    return token;
  }
  Token token(Token::Type::kNumber);
  // алгоритм чтоб узнать какое число и вернуть его
  double num;
  int begin = ind;
  while ((formula[ind] >= '0' && formula[ind] <= '9') || (formula[ind] == '.')) {
    ind++;
  }
  char *number = new char[ind - begin + 1];
  strncpy(number, formula + begin, ind - begin + 1);
  number[ind - begin] = '\0';
  num = atof(number);
  delete[] number;
  token.number = num;
  return token;
}


