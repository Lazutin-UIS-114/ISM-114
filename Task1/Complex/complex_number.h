#pragma once
#include <string>

/**
 * \brief Класс, описывающий работу с комплексным числом *
 */
class complex_number
{
private:
    /**
     * \brief Действительная часть комплексного числа.
     */
    double re = 0;

    /**
     * \brief  Мнимая часть комплексного числа.
     */
    double im = 0;

    /**
     * \brief Формирование знака для вывода комплексного числа
     * \return '+' or '-'
     */
    char get_sign_for_image_part() const;

public:
    /**
     * \brief Конструктор параметризованный
     */
    complex_number(double re = 0, double im = 0);

    /**
     * \brief Конструктор копирования
     */
    complex_number(const complex_number& other);

    /**
     * \brief Деструктор по умолчанию
     */
    ~complex_number() = default;

    /**
     * \brief Возвращает действительную часть комплексного числа.
     * \return  действительная часть комплексного числа.
     */
    double get_re() const;

    /**
     * \brief Возвращает мнимую часть комплексного числа.
     * \return мнимая часть комплексного числа.
     */
    double get_im() const;

    /**
     * \brief Возвращает модуль комплексного числа.
     * \return модуль комплексного числа.
     */
    double get_modulus() const;

    /**
     * \brief Возвращает аргумент комплексного числа.
     * \return аргумент комплексного числа.
     */
    double get_argument() const;
    
    /**
     * \brief Метод показа комплексного числа в алгебраическом виде
     * \return алгебраический вид комплексного числа
     */
    std::string get_algebra_view() const;

    /**
     * \brief Метод показа комплексного числа в тригонометрическом виде
     * \return тригонометрический вид комплексного числа
     */
    std::string get_trigonometric_view() const;

    /**
     * \brief Метод показа комплексного числа в экспоненциальном виде
     * \return экспоненциальный вид комплексного числа
     */
    std::string get_exp_view() const;

    /**
     * \brief Расчет комплексно сопряженного числа
     * \return новое комплексно сопряженное число
     */
    complex_number& get_conjugate() const;

    /**
     * \brief Сложение с другим комплексным числом
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number& add(const complex_number& other) const;

    /**
     * \brief Вычитание другого комплексного числа
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number& sub(const complex_number& other) const;

    /**
     * \brief Умножение на другое комплексное число
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number& mul(const complex_number& other) const;

    /**
     * \brief Деление на другое комплексное число
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number& div(const complex_number& other) const;
};
