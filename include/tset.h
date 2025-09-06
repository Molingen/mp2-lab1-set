// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество

#ifndef __SET_H__
#define __SET_H__

#include "tbitfield.h"

class TSet {
public:
  explicit TSet(int mp);
  TSet(const TSet& s);       // конструктор копирования
  explicit TSet(const TBitField& bf); // конструктор преобразования типа
  operator TBitField();      // преобразование типа к битовому полю

  // доступ к битам
  int GetMaxPower() const;     // максимальная мощность множества
  void InsElem(int Elem);       // включить элемент в множество
  void DelElem(int Elem);       // удалить элемент из множества
  int IsMember(int Elem) const; // проверить наличие элемента в множестве

  // теоретико-множественные операции
  int operator==(const TSet& s) const; // сравнение
  int operator!=(const TSet& s) const; // сравнение
  TSet& operator=(const TSet& s);  // присваивание
  TSet operator+(int Elem) const; // объединение с элементом
                                   // элемент должен быть из того же универса
  TSet operator-(int Elem) const; // разность с элементом
                                   // элемент должен быть из того же универса
  TSet operator+(const TSet& s);  // объединение
  TSet operator*(const TSet& s);  // пересечение
  TSet operator~ ();           // дополнение

  friend std::istream& operator>>(std::istream& istr, TSet& bf);
  friend std::ostream& operator<<(std::ostream& ostr, const TSet& bf);

private:
  int MaxPower;       // максимальная мощность множества
  TBitField BitField; // битовое поле для хранения характеристического вектора
};

#endif
