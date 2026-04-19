#include <iostream>
#include "Field.h" // Assuming you saved the classes in this header file

using namespace std;

int main() {
    cout << "=========================================" << endl;
    cout << "1. CONSTRUCTORS & PRINT MAGNITUDE" << endl;
    cout << "=========================================" << endl;
    
    // Create objects using the parameterized constructor
    // (Using the 0, 1e5, 1e3 example from your assignment prompt)
    Electric_Field e_test(0.0, 1e5, 1e3);
    Magnetic_Field m_test(0.5, 1.5, 2.5);

    // Use printMagnitude (Inherited from the base class)
    cout << "Electric ";
    e_test.printMagnitude();
    cout << "Magnetic ";
    m_test.printMagnitude();
    cout << endl;

    cout << "=========================================" << endl;
    cout << "2. PHYSICS CALCULATIONS (GAUSS & AMPERE)" << endl;
    cout << "=========================================" << endl;

    // Made-up values for Electric Field (Gauss' Law)
    double charge_Q = 0.005; // 5 milliCoulombs
    double distance_rE = 0.1; // 10 cm away
    e_test.calculateElectricField(charge_Q, distance_rE);

    // Made-up values for Magnetic Field (Ampere's Law)
    double current_I = 15.0; // 15 Amps
    double distance_rB = 0.05; // 5 cm away
    m_test.calculateMagneticField(current_I, distance_rB);
    cout << endl;

    cout << "=========================================" << endl;
    cout << "3. OVERLOADED OPERATORS (+ and <<)" << endl;
    cout << "=========================================" << endl;

    // --- Electric Field Operator Demo ---
    Electric_Field e2(10.0, 20.0, 30.0);
    Electric_Field e3(5.0, 5.0, 5.0);
    Electric_Field e1; // Default constructor
    
    e1 = e2 + e3; // Demonstrates operator+ and operator=
    
    cout << "Electric Field Addition:" << endl;
    cout << "  e2: " << e2 << endl; // Demonstrates operator<<
    cout << "+ e3: " << e3 << endl;
    cout << "----------------------" << endl;
    cout << "= e1: " << e1 << endl << endl;

    // --- Magnetic Field Operator Demo ---
    Magnetic_Field m2(1.1, 2.2, 3.3);
    Magnetic_Field m3(4.4, 5.5, 6.6);
    Magnetic_Field m1; // Default constructor
    
    m1 = m2 + m3; 
    
    cout << "Magnetic Field Addition:" << endl;
    cout << "  m2: " << m2 << endl;
    cout << "+ m3: " << m3 << endl;
    cout << "----------------------" << endl;
    cout << "= m1: " << m1 << endl;

    return 0;
}
