// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>


using TELEM = unsigned int;


class TBitField {
public:
  explicit TBitField(int len);
  TBitField(const TBitField& bf);
  ~TBitField();

  int GetLength() const;
  void SetBit(int n);
  void ClrBit(int n);
  int  GetBit(int n) const;

  int operator==(const TBitField& bf) const;
  int operator!=(const TBitField& bf) const;
  TBitField& operator=(const TBitField& bf);
  TBitField  operator|(const TBitField& bf);
  TBitField  operator&(const TBitField& bf);
  TBitField&  operator~();

  friend std::istream& operator>>(std::istream& istr, TBitField& bf);
  friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);

private:
  int  BitLen;
  TELEM *pMem;
  int  MemLen;

  static int GetMemIndex (int n);
  static TELEM GetMemMask (int n);
};

#endif
