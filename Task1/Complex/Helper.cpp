#include "Helper.h"
#include <limits>

bool are_equal(const double lh, const double rh)
{
    return fabs(lh - rh) <= std::numeric_limits<double>::min();
}

bool is_zero(const double value)
{
    return are_equal(value, 0);
}

bool are_not_equal(const double lh, const double rh)
{
    return !are_equal(lh, rh);
}
