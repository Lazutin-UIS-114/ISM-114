#pragma once
#include <string>

class complex_number;

/**
 * \brief Сравнение двух комплексных чисел
 * \param lh Одно комплексное число
 * \param rh другое комплексное число
 * \return true, если равны, false, если не равно
 */
bool operator==(const complex_number& lh, const complex_number& rh);

/**
 * \brief Метод преобразования в широкую строку комплексного числа
 * \param number комплексное число
 * \return wide string
 */
std::wstring ToString(const complex_number& number);

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
     * \brief Перемещающий конструктор
     * \param other Другой вектор
     */
    complex_number(complex_number&& other) = default;

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
     * \brief Метод показа комплексного числа в алгебраическом виде
     * \return алгебраический вид комплексного числа для wide string
     */
    std::wstring get_wide_algebra_view() const;

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
    complex_number get_conjugate() const;

    /**
     * \brief Сложение с другим комплексным числом
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number add(const complex_number& other) const;

    /**
     * \brief Вычитание другого комплексного числа
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number sub(const complex_number& other) const;

    /**
     * \brief Умножение на другое комплексное число
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number mul(const complex_number& other) const;

    /**
     * \brief Деление на другое комплексное число
     * \param other другое комплексное число
     * \return новое комплексное число
     */
    complex_number div(const complex_number& other) const;

    /**
     * \brief Сравнение двух комплексных чисел
     * \param other другое комплексное число
     * \return true, если равны, false, если не равно
     */
    bool are_equal(const complex_number& other) const;

    /**
     * \brief Сравнение двух комплексных чисел
     * \param other другое комплексное число
     * \return false, если равны, true, если не равно
     */
    bool are_not_equal(const complex_number& other) const;

    /**
     * \brief Сравнение двух комплексных чисел
     * \param lh Одно комплексное число
     * \param rh другое комплексное число
     * \return true, если равны, false, если не равно
     */
    friend bool operator==(const complex_number& lh, const complex_number& rh);

    /**
 * \brief Сравнение двух комплексных чисел
 * \param lh Одно комплексное число
 * \param rh другое комплексное число
 * \return false, если равны, true, если не равно
 */
    friend bool operator!=(const complex_number& lh, const complex_number& rh);



    /**
     * \brief Метод строкового представления
     * \param number комплексное число
     * \return wide string
     */
    static std::wstring to_wide_string(complex_number& number);

    /**
     * \brief Оператор вывода в поток
     * \param out Поток вывода
     * \param number комплексное число
     * \return Поток
     */
    friend std::ostream& operator<< (std::ostream& out, const complex_number& number);

    /**
     * \brief Оператор вывода в поток
     * \param out Поток вывода
     * \param number комплексное число
     * \return Поток
     */
    friend std::wostream& operator<< (std::wostream& out, const complex_number& number);
};
