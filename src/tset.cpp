// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(const int mp) : MaxPower(mp), BitField(mp) {}

TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField) {}

TSet::TSet(const TBitField& bf) :  MaxPower(bf.GetLength()), BitField(bf) {}

TSet::operator TBitField() { return BitField; }

int TSet::GetMaxPower() const {
    return MaxPower;;
}

int TSet::IsMember(const int Elem) const { return BitField.GetBit(Elem); }

void TSet::InsElem(const int Elem) { BitField.SetBit(Elem); }

void TSet::DelElem(const int Elem) { BitField.ClrBit(Elem); }

// теоретико-множественные операции
TSet& TSet::operator=(const TSet& s) {
    BitField = s.BitField;
    MaxPower = s.MaxPower;
    return *this;
}

int TSet::operator==(const TSet& s) const { return BitField == s.BitField; }

int TSet::operator!=(const TSet& s) const { return BitField != s.BitField; }

TSet TSet::operator+(const TSet& s) {
    TSet tmp(BitField | s.BitField);
    return tmp;
}

TSet TSet::operator+(const int Elem) const {
    TSet tmp(BitField);
    tmp.InsElem(Elem);
    return tmp;
}

TSet TSet::operator-(const int Elem) const {
    TSet tmp(BitField);
    tmp.DelElem(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet& s) {
    TSet res(MaxPower);
    res.BitField = BitField & s.BitField;
    return res;
}

TSet TSet::operator~() {
    TSet res(MaxPower);
    res.BitField = ~BitField;
    return res;
}

// перегрузка ввода/вывода
std::istream &operator>>(std::istream& istr, TSet& s) {
    int i = 0;
    istr >> i;
    while ((i >= 0) && (i < s.MaxPower)) {
        s.InsElem(i);
        istr >> i;
    }
    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TSet& s) {
    for (int i = 0; i < s.GetMaxPower(); ++i)
        if (s.IsMember(i)) {
            ostr << i;
        }
    return ostr;
}
