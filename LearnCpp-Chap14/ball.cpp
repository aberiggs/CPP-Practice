#include <iostream>
#include <string>

class Ball {
public:
    Ball(std::string color, double radius)
        : m_color { color }
        , m_radius { radius } {
    }

    void print() const 
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")";
    }


private:
    double m_radius {};
    std::string m_color {};
};


int main()
{
	Ball blue{ "blue", 10.0 };
	blue.print();
    std::cout << "\n";

	Ball red{ "red", 12.0 };
	red.print();
    std::cout << "\n";

	return 0;
}