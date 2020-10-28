// Copyright 2020 Oganyan Robert

// Верхнетреугольная матрица

#include <../include/TVector.h>

#ifndef MATRIX_INCLUDE_TMATRIX_H_
#define MATRIX_INCLUDE_TMATRIX_H_

const int MAX_MATRIX_SIZE = 10000;

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
 public:
  TMatrix(std::size_t s = 10);
  TMatrix(const TMatrix &mt);   // копирование
  TMatrix(const TVector<TVector<ValType> > &mt);  // преобразование типа
  bool operator==(const TMatrix &mt) const;  // сравнение
  bool operator!=(const TMatrix &mt) const;  // сравнение
  TMatrix& operator= (const TMatrix &mt);   // присваивание
  TMatrix  operator+ (const TMatrix &mt);  // сложение
  TMatrix  operator- (const TMatrix &mt);   // вычитание

  // ввод / вывод
  friend std::istream& operator>>(std::istream &in, TMatrix &mt);
  friend std::ostream & operator<<( std::ostream &out, const TMatrix &mt);
};

#endif //MATRIX_INCLUDE_TMATRIX_H_

