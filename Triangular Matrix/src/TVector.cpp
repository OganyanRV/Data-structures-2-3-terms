// Copyright 2020 Oganyan Robert

#include <stdexcept>
#include <TVector.h>
#include "../include/TVector.h"

template <class ValType>
TVector<ValType>::TVector(std::size_t s, std::size_t si) {
  if (s > MAX_VECTOR_SIZE || s < 0 || si < 0) {
    throw std::runtime_error("Incorrect input");
  }
  Size = s;
  StartIndex = si;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = (ValType) 0;
  }
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v) {
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = v.pVector[i];
  }
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector() {
  delete[] pVector;
}

template <class ValType>
std::size_t TVector<ValType>::GetSize() {
  return Size;
}

template <class ValType>
std::size_t TVector<ValType>::GetStartIndex() {
  return StartIndex;
}

template <class ValType> // доступ
ValType& TVector<ValType>::operator[] (const std::size_t& pos) {
  if (pos - StartIndex < 0 || pos - StartIndex >= Size) {
    throw std::runtime_error("Incorrect input");
  }

  return pVector[pos - StartIndex];
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const {
  if (Size == v.Size && StartIndex == v.StartIndex) {
    for (std::size_t i = 0; i < Size; ++i) {
      if (pVector[i] != v.pVector[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const {
  return !(this==v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v) {
  if (this == &v) {
    return *this;
  }
  if (pVector != nullptr) {
    delete[] pVector;
  }
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (std::size_t i = 0; i < Size; ++i) {
    pVector[i] = v.pVector[i];
  }
  return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] += val;
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] -= val;
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val) {
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] * val;
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v) {
  if (Size != v.Size || StartIndex != v.StartIndex) {
    throw std::runtime_error("Incorrect input");
  }
  TVector tmp(*this);
  for (std::size_t i = 0; i < Size; ++i) {
    tmp.pVector[i] = tmp.pVector[i] * v.pVector[i];
  }
  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType>
std::istream &operator>>(std::istream &in, TVector<ValType> &v)
{
  for (std::size_t i = 0; i < v.Size; ++i) {
    in >> v.pVector[i];
  }
  return in;
}
template <class ValType>
std:: ostream &operator<<(std::ostream &out, const TVector<ValType> &v)
{
  for (std::size_t i = 0; i < v.Size; ++i) {
    out << v.pVector[i] << ' ';
  }
  return out;
}

