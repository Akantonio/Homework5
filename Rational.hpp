//
// Created by Chris Hartman on 2/18/21.
//
//Modified by Adrian Antonio for Homework 5 on 4/20/2021

#ifndef CS202CLASSEXAMPLE_RATIONAL_HPP
#define CS202CLASSEXAMPLE_RATIONAL_HPP
#include <iostream>
#include <numeric>
// class invariant:
// _denominator is always > 0
template<typename TClass>
class Rational {
    template<typename UFriend>
    friend std::ostream& operator<<(std::ostream &, const Rational<UFriend> &rhs);//must be declared as a template function also
    template<typename UFriend>
    friend Rational<UFriend> operator+(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs);
    template<typename UFriend>
    friend Rational<UFriend> operator-(const Rational<UFriend> &lhs);
    template<typename UFriend>
    friend bool operator==(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs);
    template<typename UFriend>
    friend bool operator<(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs);

public:
    Rational();
    Rational<TClass>(TClass,TClass=1);
    Rational<TClass> & operator+=(const Rational<TClass>& rhs);
    Rational<TClass> & operator-=(const Rational<TClass>& rhs);
    Rational<TClass> & operator*=(const Rational<TClass>& rhs);
    Rational<TClass> & operator/=(const Rational<TClass>& rhs);
    Rational<TClass> & operator++();        //prefix ++
    Rational<TClass> operator++(int); //postfix ++
    Rational<TClass> & operator--();        //prefix --
    Rational<TClass> operator--(int); //postfix --
private:
    void reduce();
    TClass _numerator;
    TClass _denominator;
};

template<typename TFunction>
Rational<TFunction> operator-(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs);
template<typename TFunction>
Rational<TFunction> operator*(Rational<TFunction> lhs, const Rational<TFunction> &rhs);
template<typename TFunction>
Rational<TFunction> operator/(Rational<TFunction> lhs, const Rational<TFunction> &rhs);

template<typename TFunction>
bool operator!=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs);
template<typename TFunction>
bool operator>(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs);
template<typename TFunction>
bool operator<=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs);
template<typename TFunction>
bool operator>=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs);

//Friend of Rational Class
template<typename UFriend>
std::ostream &operator<<(std::ostream &os, const Rational<UFriend> &rhs) {
    os << rhs._numerator;
    if (rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}
template<typename UFriend>
Rational<UFriend> operator+(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs) { //canonical
    auto temp{lhs};
    temp += rhs;
    return temp;
}
template<typename UFriend>
Rational<UFriend> operator-(const Rational<UFriend> &lhs) {
    return { -lhs._numerator, lhs._denominator };
}

template<typename UFriend>
bool operator==(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs) {
    return lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator;
}

template<typename UFriend>
bool operator<(const Rational<UFriend> &lhs, const Rational<UFriend> &rhs) {
    return lhs._numerator*rhs._denominator < rhs._numerator*lhs._denominator;
}

//Inside of Rational Class
template<typename TClass>
Rational<TClass>::Rational(TClass num,TClass den): _numerator(num),_denominator(den){
    reduce();
}
template<typename TClass>
Rational<TClass> & Rational<TClass>::operator+=(const Rational<TClass> &rhs) {
    // a/b + c/d = (ad+bc)/ad
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}
template<typename TClass>
Rational<TClass> &Rational<TClass>::operator-=(const Rational<TClass> &rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}
template<typename TClass>
Rational<TClass> &Rational<TClass>::operator*=(const Rational<TClass> &rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    return *this;
}
template<typename TClass>
Rational<TClass> & Rational<TClass>::operator/=(const Rational<TClass>& rhs){
    return *this *= {rhs._denominator,rhs._numerator};
}
template<typename TClass>
Rational<TClass> & Rational<TClass>::operator++() {//prefix ++
    return *this += 1;
}
template<typename TClass>
Rational<TClass> Rational<TClass>::operator++(int) {//postfix ++
    auto copy{*this};
    ++(*this);
    return copy;
}
template<typename TClass>
Rational<TClass> & Rational<TClass>::operator--() {//prefix --
    return *this -= 1;
}
template<typename TClass>
Rational<TClass> Rational<TClass>::operator--(int) {//postfix --
    auto copy{*this};
    --(*this);
    return copy;
}

template<typename TClass>
void Rational<TClass>::reduce() {
    auto gcd = std::gcd(_numerator,_denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

template<typename TClass>
Rational<TClass>::Rational() {
}



//Global Operator Function
template<typename TFunction>
bool operator!=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs) {//canonical
    return !(rhs==lhs);
}
template<typename TFunction>
bool operator>(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs){
    return rhs<lhs;
}
template<typename TFunction>
bool operator<=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs){
    return ! (rhs>lhs);
}
template<typename TFunction>
bool operator>=(const Rational<TFunction> &lhs, const Rational<TFunction> &rhs){
    return ! (rhs<lhs);
}
#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
