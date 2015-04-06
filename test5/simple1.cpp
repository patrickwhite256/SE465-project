/* Test 5 - Meaning less test
 * This test contains support pair values < 3 and has confidence of 0.5 or 1
 * Mainly tests that calling strcmp will not stop the processing of functions
 */

#include <iostream>
#include <cstring>

void scope1();
void scope2();
void scope3();
void scope4();

int main() {
    scope1();
    scope2();
    scope3();
    scope4();
    return 0;
}

void A() {
    std::cout << "A" << std::endl;
}

void B() {
    std::cout << "B" << std::endl;
}

void C() {
    std::cout << "C" << std::endl;
}

void scope1() {
    strcmp("Scope 1", "Cmp 1");
    A();
    B();
}

void scope2() {
    A();
    strcmp("Scope 2", "Cmp 2");
    B();
}

void scope3() {
    A();
    C();
    strcmp("Scope 3", "Cmp 3");
}

void scope4() {
    strcmp("Scope 4", "Cmp 4");
    A();
    strcmp("Scope 4", "Cmp 5");
    C();
}

