#include <iostream>

class Fraction
{
public:
    explicit Fraction(int numerator = 0, int denominator = 1) 
        : m_numerator{ numerator }
        , m_denominator{ denominator} {
    }

    auto& getNumerator() const { return m_numerator; }
    void setNumerator(int newNumerator) { m_numerator = newNumerator; }

    auto& getDenominator() const { return m_denominator; }
    void setDenominator(int newDenominator) { m_denominator = newDenominator; }

    Fraction multiply(const Fraction& otherFrac) {
        return Fraction{ m_numerator * otherFrac.m_numerator, 
                         m_denominator * otherFrac.m_denominator };
    }

private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};

Fraction getFraction() {
    int numerator{ 0 };
    int denominator{ 1 };
    std::cout << "Enter a value for numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> denominator;
    std::cout << '\n';

    return Fraction{numerator, denominator};
}


void printFraction(const Fraction& f) {
    std::cout << f.getNumerator() << '/' << f.getDenominator() << '\n';
}

int main() {
    Fraction f1{ getFraction() };
    Fraction f2{ getFraction() };

    std::cout << "Your fractions multiplied together: ";

    printFraction(f1.multiply(f2));

    return 0;
}