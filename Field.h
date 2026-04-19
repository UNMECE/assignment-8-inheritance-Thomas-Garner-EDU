#ifndef FIELD_H
#define FIELD_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

// BASE CLASS
class Field {
private:
    double *value;

public:
    // Default Constructor
    Field() : value(new double[3]{0, 0, 0}) {}

    // Parameterized Constructor
    Field(double x, double y, double z) : value(new double[3]{x, y, z}) {}

    // Copy Constructor
    Field(const Field& other) : value(new double[3]) {
        for (int i = 0; i < 3; i++) {
            value[i] = other.value[i];
        }
    }

    // Assignment Operator (Crucial for e1 = e2 + e3)
    Field& operator=(const Field& other) {
        if (this != &other) { // Avoid self-assignment
            for (int i = 0; i < 3; i++) {
                value[i] = other.value[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Field() { delete[] value; }

    // Helpers
    double getComponent(int i) const { return value[i]; }

    void printMagnitude() const {
        cout << "Field Components: " << value[0] << ", " << value[1] << ", " << value[2] << endl;
    }
};

// DERIVED CLASS: ELECTRIC FIELD
class Electric_Field : public Field {
private:
    double fieldStrength;
    static constexpr double e0 = 8.854e-12;

public:
    // Default constructor
    Electric_Field() : Field() {
        fieldStrength = 0.0;
    }

    // Parameterized
    Electric_Field(double Ex, double Ey, double Ez) : Field(Ex, Ey, Ez) {
        fieldStrength = 0.0;
    }

    // Getters mapping to base class components
    double getEx() const { return getComponent(0); }
    double getEy() const { return getComponent(1); }
    double getEz() const { return getComponent(2); }

    // Overloaded + Operator
    Electric_Field operator+(const Electric_Field& other) const {
        double newX = this->getComponent(0) + other.getComponent(0);
        double newY = this->getComponent(1) + other.getComponent(1);
        double newZ = this->getComponent(2) + other.getComponent(2);

        return Electric_Field(newX, newY, newZ);
    }

    // Magnitude
    double magE() const {
        double x2 = std::pow(getEx(), 2.0);
        double y2 = std::pow(getEy(), 2.0);
        double z2 = std::pow(getEz(), 2.0);
        return sqrt(x2 + y2 + z2);
    }

    // Inner product
    double innerE() const {
        return (std::pow(getEx(), 2.0) + std::pow(getEy(), 2.0) + std::pow(getEz(), 2.0));
    }

    // Field Strength at point (Gauss' Law)
    void calculateElectricField(double Q, double r) {
        fieldStrength = Q / (4 * M_PI * std::pow(r, 2.0) * e0);
        printf("The electric field strength at %.2f units away from the charge %.2f C is : %.4e N/C\n", r, Q, fieldStrength);
    }
};

// DERIVED CLASS: MAGNETIC FIELD
class Magnetic_Field : public Field {
private:
    double fieldStrength;
    static constexpr double mu0 = M_PI * 4e-7;

public:
    // Default constructor
    Magnetic_Field() : Field() {
        fieldStrength = 0.0;
    }

    // Parameterized constructor
    Magnetic_Field(double Bx, double By, double Bz) : Field(Bx, By, Bz) {
        fieldStrength = 0.0;
    }

    // Getters mapping to base class components
    double getBx() const { return getComponent(0); }
    double getBy() const { return getComponent(1); }
    double getBz() const { return getComponent(2); }

    // Overloaded + Operator
    Magnetic_Field operator+(const Magnetic_Field& other) const {
        double newX = this->getComponent(0) + other.getComponent(0);
        double newY = this->getComponent(1) + other.getComponent(1);
        double newZ = this->getComponent(2) + other.getComponent(2);

        return Magnetic_Field(newX, newY, newZ);
    }

    // Field Strength at point (Ampere's Law)
    void calculateMagneticField(double I, double r) {
        fieldStrength = (mu0 * I) / (2 * M_PI * r);
        printf("The magnetic field strength at %.2f units away from the wire with %.2f A is : %.4e T\n", r, I, fieldStrength);
    }
};

// GLOBAL OVERLOADED << OPERATORS

// Electric Field Insertion Operator
ostream& operator<<(ostream& os, const Electric_Field& e) {
    os << "[" << e.getComponent(0) << ", " << e.getComponent(1) << ", " << e.getComponent(2) << "]";
    return os;
}

// Magnetic Field Insertion Operator
ostream& operator<<(ostream& os, const Magnetic_Field& b) {
    os << "[" << b.getComponent(0) << ", " << b.getComponent(1) << ", " << b.getComponent(2) << "]";
    return os;
}

#endif




