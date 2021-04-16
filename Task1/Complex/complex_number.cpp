#include <string>
#include <sstream>
#include <cmath>
#include "complex_number.h"
#include "Helper.h"

std::wstring ToString(const complex_number& number)
{
    std::wstringstream out;
    out << number;
    return out.str();
}

complex_number::complex_number(const double re, const double im)
    : re(re), im(im)
{
}

complex_number::complex_number(const complex_number & other)
    :complex_number(other.get_re(), other.get_im())
{
}

double complex_number::get_re() const
{
    return this->re;
}

double complex_number::get_im() const
{
    return this->im;
}

double complex_number::get_modulus() const
{
    return sqrt(this->get_re() * this->get_re() + this->get_im() * this->get_im());
}

double complex_number::get_argument() const
{
    //{\displaystyle \varphi =\operatorname {atan2} \left(\operatorname {\mathcal {Im}} (z),\operatorname {\mathcal {Re}} (z)\right).}
    //TODO при re = 0 && im = 0 -> NAN
    return atan2(this->get_re(), this->get_im());
}


char complex_number::get_sign_for_image_part() const
{
    return std::signbit(this->get_im()) ? '-' : '+';
}

std::string complex_number::get_algebra_view() const
{
    std::stringstream buffer;
    buffer  << this->get_re() << " "
    << get_sign_for_image_part() << " "
    << std::abs(this->get_im()) << "i";
    return buffer.str();
}

std::wstring complex_number::get_wide_algebra_view() const
{
    std::wstringstream buffer;
    buffer << this->get_modulus()
        << L" * (Cos("
        << this->get_argument()
        << L") + iSin("
        << this->get_argument()
        << L"))";
    return buffer.str();
}


std::string complex_number::get_trigonometric_view() const
{
    //{\displaystyle z=r(\cos \varphi +i\sin \varphi ).}
    std::stringstream buffer;
    buffer << this->get_modulus() << " * (Cos(" << this->get_argument()
           << ") + iSin(" << this->get_argument() << "))";
    return buffer.str();
}

std::wstring complex_number::to_wide_string(complex_number& number)
{
    std::wstringstream out;
    out << number;
    return out.str();
}

std::string complex_number::get_exp_view() const
{
    std::stringstream buffer;
    buffer  << this->get_modulus() << " * exp( i "
    << this->get_argument() << ")";
    return buffer.str();
}

complex_number complex_number::get_conjugate() const
{ 
    return complex_number(this->get_re(), -this->get_im());
}

complex_number complex_number::add(const complex_number& other) const
{
    const auto re = this->get_re() + other.get_re();
    const auto im = this->get_im() + other.get_im();
    return complex_number(re, im);
}

complex_number complex_number::sub(const complex_number& other) const
{
    const auto re = this->get_re() - other.get_re();
    const auto im = this->get_im() - other.get_im();
    return complex_number(re, im);
}

complex_number complex_number::mul(const complex_number& other) const
{
    // (a + bi)*(c + di) = (ac - bd) + (ad + bc)i
    const auto re = this->get_re() * other.get_re() - this->get_im() * other.get_im();
    const auto im = this->get_re() * other.get_im() + this->get_im() * other.get_re();
    return complex_number(re, im);
}

complex_number complex_number::div(const complex_number& other) const
{
    //TODO реализовать умножение комплексных чисел
    const auto re = 1;
    const auto im = 1;
    return complex_number(re, im);
}

bool complex_number::are_equal(const complex_number& other) const
{
    return ::are_equal(this->get_im(), other.get_im()) &&
           ::are_equal(this->get_re(), other.get_re());
}

bool complex_number::are_not_equal(const complex_number& other) const
{
    return !are_equal(other);
}

bool operator==(const complex_number& lh, const complex_number& rh)
{
    return lh.are_equal(rh);
}

bool operator!=(const complex_number& lh, const complex_number& rh)
{
    return !lh.are_equal(rh);
}

std::ostream& operator<<(std::ostream& out, const complex_number& number)
{
    return out << number.get_algebra_view();
}

std::wostream& operator<<(std::wostream& out, const complex_number& number)
{
    return out << number.get_wide_algebra_view();
}
