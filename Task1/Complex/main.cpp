#include "complex_number.h"
#include <iostream>

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto z1 = complex_number(5,23);
    const auto z_conj = z1.get_conjugate();

    std::cout << "z = " << z1.get_algebra_view() << "\n";
    std::cout << "z_conj = " << z_conj.get_algebra_view() << "\n";

    std::cout << "z = " << z1.get_trigonometric_view() << "\n";
    std::cout << "z_conj = " << z_conj.get_trigonometric_view() << "\n";

    std::cout << "z = " << z1.get_exp_view() << "\n";
    std::cout << "z_conj = " << z_conj.get_exp_view() << "\n";

    std::cout << std::endl;
    return 0;
}
