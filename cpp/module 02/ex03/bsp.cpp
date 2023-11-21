#include "Point.hpp"
#include <iostream>
#include <iomanip>

// Barycentric coordinate system
// https://www.educative.io/answers/what-are-barycentric-coordinates
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const px = point.getX();
    Fixed const py = point.getY();

    Fixed const ax = a.getX();
    Fixed const ay = a.getY();
    Fixed const bx = b.getX();
    Fixed const by = b.getY();
    Fixed const cx = c.getX();
    Fixed const cy = c.getY();

    Fixed const alpha = ((by - cy) * (px - cx) + (cx - bx) * (py - cy))
					  / ((by - cy) * (ax - cx) + (cx - bx) * (ay - cy));
    Fixed const beta = ((cy - ay) * (px - cx) + (ax - cx) * (py - cy))
					 / ((by - cy) * (ax - cx) + (cx - bx) * (ay - cy));
    Fixed const gamma = (Fixed)1 - alpha - beta;

    if (alpha >= 0 && beta >= 0 && gamma >= 0)
        return (true);
    return (false);
}

// Display point and triangle in space in terminal
void displayPoint(Point const a, Point const b, Point const c, Point const point, int const width, int const height)
{
    bool const inside = bsp(a, b, c, point);
    // Clear terminal
    std::cout << "\033[2J\033[1;1H";

    const int A[2] = {(int)(a.getX().toFloat() * 10.0), (int)(a.getY().toFloat() * 10.0)};
    const int B[2] = {(int)(b.getX().toFloat() * 10.0), (int)(b.getY().toFloat() * 10.0)};
    const int C[2] = {(int)(c.getX().toFloat() * 10.0), (int)(c.getY().toFloat() * 10.0)};
    const int P[2] = {(int)(point.getX().toFloat() * 10.0), (int)(point.getY().toFloat() * 10.0)};

    if (inside)
        std::cout << "\033[1;32m P \033[0m(" << P[0]/10.0 + 0.1 << ", " << P[1]/10.0 + 0.1 << ") is inside the triangle" << std::endl;
    else
        std::cout << "\033[1;31m P \033[0m(" << P[0]/10.0 + 0.1 << ", " << P[1]/10.0 + 0.1 << ") is outside the triangle" << std::endl;
    std::cout << "\033[1;33m A \033[0m(" << A[0]/10.0 + 0.1 << ", " << A[1]/10.0 + 0.1 << ")" << " \033[1;33m B \033[0m(" << B[0]/10.0 + 0.1 << ", " << B[1]/10.0 + 0.1 << ")" << " \033[1;33m C \033[0m(" << C[0]/10.0 + 0.1 << ", " << C[1]/10.0 + 0.1 << ")" << std::endl << std::endl;

    std::cout << " 0 |";
    for (int x = 1; x <= width; x++)
    {
        if (x % 10 == 0)
            std::cout << " " << std::setw(2) << std::left << x/10.0 << "|";
        else
            std::cout << std::setw(3) << std::left << x/10.0 << "|";
    }
    std::cout << std::endl;
    for (int x = 0; x <= width; x++)
        std::cout << "---+";
    std::cout << std::endl;
    for (int y = 0; y < height; y++)
    {
        std::cout << std::setw(3) << std::left << y/10.0 + 0.1 << "|";
        for (int x = 0; x < width; x++)
        {
            if (x == P[0] && y == P[1] && inside)
                std::cout << "\033[1;32m P \033[0m|";
            else if (x == P[0] && y == P[1] && !inside)
                std::cout << "\033[1;31m P \033[0m|";
            else if (x == A[0] && y == A[1])
                std::cout << "\033[1;33m A \033[0m|";
            else if (x == B[0] && y == B[1])
                std::cout << "\033[1;33m B \033[0m|";
            else if (x == C[0] && y == C[1])
                std::cout << "\033[1;33m C \033[0m|";
            else
                std::cout << "   |";
        }
        std::cout << std::endl;

        std::cout << "---+";
        for (int x = 0; x < width; x++)
            std::cout << "---+";
        std::cout << std::endl;
    }
}