#include <string>
#include <sstream>
#include <cmath>
#include "complex_number.h"

complex_number::complex_number(const double re, const double im)
    : re(re), im(im)
{
}

complex_number::complex_number(const complex_number & other)
    :complex_number(other.re, other.im)
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

std::string complex_number::get_trigonometric_view() const
{
    //{\displaystyle z=r(\cos \varphi +i\sin \varphi ).}
    std::stringstream buffer;
    buffer << this->get_modulus() << " * (Cos(" << this->get_argument()
           << ") + iSin(" << this->get_argument() << "))";
    return buffer.str();
}

std::string complex_number::get_exp_view() const
{
    std::stringstream buffer;
    buffer  << this->get_modulus() << " * exp( i "
    << this->get_argument() << ")";
    return buffer.str();
}

complex_number& complex_number::get_conjugate() const
{
    const auto result = new complex_number(this->get_re(), -this->get_im());
    return *result;
}

complex_number& complex_number::add(const complex_number& other) const
{
    const auto re = this->get_re() + other.get_re();
    const auto im = this->get_im() + other.get_im();
    const auto result = new complex_number(re, im);
    return *result;
}

complex_number& complex_number::sub(const complex_number& other) const
{
    const auto re = this->get_re() - other.get_re();
    const auto im = this->get_im() - other.get_im();
    const auto result = new complex_number(re, im);
    return *result;
}

complex_number& complex_number::mul(const complex_number& other) const
{
    // (a + bi)*(c + di) = (ac - bd) + (ad + bc)i
    const auto re = this->get_re() * other.get_re() - this->get_im() * other.get_im();
    const auto im = this->get_re() * other.get_im() + this->get_im() * other.get_re();
    const auto result = new complex_number(re, im);
    return *result;
}

complex_number& complex_number::div(const complex_number& other) const
{
    const auto result = new complex_number(re, im);
    return *result;
}
