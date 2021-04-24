//
// Created by Chris Hartman on 2/18/21.
//
//Modified by Adrian Antonio for Homework 5 on 4/20/2021

#ifndef CS202CLASSEXAMPLE_RATIONAL_HPP
#define CS202CLASSEXAMPLE_RATIONAL_HPP
#include <iostream>

// class invariant:
// _denominator is always > 0
template<typename TClass>
class Rational {
    template<typename UFriend>
    friend std::ostream& operator<<(std::ostream &, const Rational &rhs);

    template<typename UFriend>
    friend Rational operator+(const Rational &lhs, const Rational &rhs);
    template<typename UFriend>
    friend Rational operator-(const Rational &lhs);
    template<typename UFriend>
    friend bool operator==(const Rational &lhs, const Rational &rhs);
    template<typename UFriend>
    friend bool operator<(const Rational &lhs, const Rational &rhs);

public:
    Rational(int,int=1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
    Rational & operator+=(const Rational& rhs);
    Rational & operator-=(const Rational& rhs);
    Rational & operator*=(const Rational& rhs);
    Rational & operator/=(const Rational& rhs);
    Rational & operator++();        //prefix ++
    Rational operator++(int); //postfix ++
    Rational & operator--();        //prefix --
    Rational operator--(int); //postfix --
private:
    void reduce();

    int _numerator;
    int _denominator;
};

Rational operator-(const Rational &lhs, const Rational &rhs);
Rational operator*(Rational lhs, const Rational &rhs);
Rational operator/(Rational lhs, const Rational &rhs);

bool operator!=(const Rational &lhs, const Rational &rhs);
bool operator>(const Rational &lhs, const Rational &rhs);
bool operator<=(const Rational &lhs, const Rational &rhs);
bool operator>=(const Rational &lhs, const Rational &rhs);

#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
