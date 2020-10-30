  //  Copyright by Oganyan Robert

#include <iostream>
#include <string>
#include <../include/Tokenizer.h>
#include <../src/Tokenizer.cpp>

int main() {
  TStack<int> st(5);
  int temp;
  std::cout << "Stack testing" << std::endl;
  for (int i = 0; i < 35; i++)
  {
    if (!st.IsFull()) {
      st.Push(i);
      std::cout << "Put the object: " << i << std::endl;
    };
  }
  while (!st.IsEmpty())
  {
    temp = st.Pop();
    std::cout << "Took the object " << temp << std::endl;
  }

  std::cout << "Reverse Polish Notation testing"<<std::endl;
  std::cout << "Enter the Formula:  "<<std::endl;
  std::string s;
  std::cin >> s;
  int n;
  Token* t = Postfix(s.c_str(), n);
  std::cout << "\n Postfix form: \n";
  for (int i = 0; i < n; i++) {
    if (t[i].type == Token::kNumber)
      std::cout << t[i].number << ' ';
    else
      std::cout << t[i].symbol << ' ';
  }
  std::cout << "\n The result: " << Calculate(t, n);

  return 0;
}
