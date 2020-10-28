// Copyright 2020 Oganyan Robert

#include "TMatrix.h"

template <class ValType>
TMatrix<ValType>::TMatrix(std::size_t s): TVector<TVector<ValType>>(s) {
  if (s > MAX_MATRIX_SIZE || s < 0) {
    throw std::runtime_error("Incorrect input");
  }
  for (std::size_t i = 0; i < s; ++i) {
    this->pVector[i] = TVector<ValType>(s - i, i);
  }
}

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
    TVector<TVector<ValType>>(mt) {
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
    TVector<TVector<ValType>>(mt) {
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const {
  if (this->Size == mt.Size) {
    for (std::size_t i = 0; i<this->Size; ++i) {
      if (this->pVector[i] != mt.pVector[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
  return !(*this == mt);
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
  if (this != &mt) {
    delete[] this->pVector;
    this->Size = mt.Size;
    this->StartIndex = mt.StartIndex;
    this->pVector = new TVector<ValType>[this->Size];
    for (int i = 0; i < this->Size; ++i) {
      this->pVector[i] = mt.pVector[i];
    }
  }
  return *this;
}

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
  if (this->Size != mt.Size) {
    throw - 1;
  }
  return TVector< TVector<ValType> >::operator + (mt);
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
  if (this->Size != mt.Size) {
    throw - 1;
  }
  return TVector< TVector<ValType> >::operator - (mt);
}

template <class ValType>
std::istream& operator>>(std::istream &in, TMatrix<ValType> &mt)
{
  for (std::size_t i = 0; i < mt.Size; ++i)
    in >> mt.pVector[i];
  return in;
}

template <class ValType>
std::ostream& operator<<( std::ostream &out, const TMatrix<ValType> &mt)
{
  for (std::size_t i = 0; i < mt.Size; ++i)
    out << mt.pVector[i] << std::endl;
  return out;
}