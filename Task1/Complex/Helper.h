#pragma once

/**
 * \brief Метод сравнения двух вещественных чисел
 * \param lh первое число
 * \param rh второе число
 * \return true, если равны, false, иначе
 */
bool are_equal(const double lh, const double rh);

/**
 * \brief Метод равенства нулю вещественного числа
 * \param value вещественное число
 * \return true, если равно, false, иначе
 */
bool is_zero(const double value);

/**
 * \brief Метод сравнения двух вещественных чисел
 * \param lh первое число
 * \param rh второе число
 * \return false, если равны, true, иначе
 */
bool are_not_equal(const double lh, const double rh);
