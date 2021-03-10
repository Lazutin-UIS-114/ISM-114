#pragma once
#include <string>

/**
 * \brief Класс, описывающий работу с комплексным числом *
 */
class Complex
{
private:
    double Re;
    double Im;

public:
    /**
     * \brief Конструктор по умолчанию
     */
    Complex();
    ~Complex();
    Complex(const double re, const double im);
    Complex(const Complex& other);

    double GetRe() const;
    double GetIm() const;
    double GetModulus() const;
    
    std::string GetAlgebraView() const;
    std::string GetTrigonometricView() const;
    std::string GetExpView() const;

    Complex& GetConjugate() const;
};
