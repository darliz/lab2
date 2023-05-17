#include "SolvePoly.h"

std::vector<double> SolvePoly(double a, double b, double c) {
    constexpr double INF = std::numeric_limits<double>::infinity();
    double x1, x2, discriminant;

    if (a == 0 && b == 0 && c == 0)
        return { INF, INF };

    if (a == 0 && b == 0)
        return { -INF, -INF };

    if (a == 0)
        return { -c / b, -c / b };

    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return { -INF, -INF };

    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    return { x1, x2 };
}