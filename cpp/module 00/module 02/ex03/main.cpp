#include "Point.hpp"

int main ( void ) {
    srand(time(NULL));
    // Grid size ex: 5.0 x 5.0 (50 x 50)
    const int HEIGHT = 40;
    const int WIDTH = 100;
    float scale = 10.0;
    while (1)
    {
        Point a(0, 0);
        Point b(rand() % WIDTH / scale, rand() % HEIGHT / scale);
        Point c(rand() % WIDTH / scale, rand() % HEIGHT / scale);
        Point point(rand() % WIDTH / scale, rand() % HEIGHT / scale);

        displayPoint(a, b, c, point, WIDTH, HEIGHT);
        std::cout << "Press ENTER to run again or enter any other key to exit" << std::endl;
        if (std::cin.get() != '\n')
            break;
    }
    return 0;
}