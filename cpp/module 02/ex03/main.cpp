#include "Point.hpp"

int main ( void ) {
    srand(time(NULL));
    // Grid size ex: 5.0 x 5.0 (50 x 50)
    const int HEIGHT = 20;
    const int WIDTH = 50;
    float scale = 10.0;
    while (1)
    {
        Point a(0, 0);
        Point b(WIDTH / scale - 0.05, HEIGHT / scale - 0.05);
        Point c(rand() % WIDTH / scale, rand() % HEIGHT / scale);
        Point point(rand() % WIDTH / scale, rand() % HEIGHT / scale);

        displayPoint(a, b, c, point, WIDTH, HEIGHT);
        std::cout << "Press ENTER to run again or CTRL+C to exit" << std::endl;
        if (std::cin.get() != '\n')
            break;
    }
    return 0;
}