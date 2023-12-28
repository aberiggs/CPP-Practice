#include <iostream>

class Point3d {
public:

    bool isEqual(Point3d& otherPoint) const {

        return ((m_x == otherPoint.m_x) 
                && (m_y == otherPoint.m_y) 
                && (m_z == otherPoint.m_z));
    }
    
    void print() const {
        std::cout << "<" << m_x << "," << m_y << "," << m_z << ">"; 
    }


    void setValues(int x, int y, int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }

private:
    int m_x {};
    int m_y {};
    int m_z {};
};

void partA() {
    std::cout << "Start of part A\n";
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';
}

void partB() {
    std::cout << "Start of part B\n";
    Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";
}

int main() {
    partA();

    partB();
    return 0;
}

