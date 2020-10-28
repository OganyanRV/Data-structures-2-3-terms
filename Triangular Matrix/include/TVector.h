// Copyright 2020 Oganyan Robert

// Вектор
#include <iostream>

#ifndef MATRIX_INCLUDE_TVECTOR_H_
#define MATRIX_INCLUDE_TVECTOR_H_

const int MAX_VECTOR_SIZE = 100000000;
template <class ValType>
class TVector {
   protected:
     ValType *pVector;
     std::size_t Size;       // размер вектора
     std::size_t StartIndex;  // индекс первого элемента вектора
   public:
     TVector(std::size_t s = 10, std::size_t si = 0);
     TVector(const TVector& v);  // конструктор копирования
     virtual ~TVector();
     std::size_t GetSize(void);  // размер вектора
     std::size_t GetStartIndex(void);  // индекс первого элемента
     ValType& operator[](const std::size_t& pos);  // доступ
     bool operator==(const TVector& v) const;  // сравнение
     bool operator!=(const TVector& v) const;  // сравнение
     TVector& operator=(const TVector& v);   // присваивание

  // скалярные операции
     TVector  operator+(const ValType &val);   // прибавить скаляр
     TVector  operator-(const ValType &val);   // вычесть скаляр
     TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
     TVector  operator+(const TVector &v);     // сложение
     TVector  operator-(const TVector &v);     // вычитание
     ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
    friend std::istream& operator>>(std::istream &in, TVector &v);
    friend std::ostream& operator<<(std::ostream &out, const TVector &v);
};

#endif //MATRIX_INCLUDE_TVECTOR_H_

