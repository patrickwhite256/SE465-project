/* Test 6 - Enough Confidence, not enough support
 */

#include <iostream>

void scope1();
void scope2();
void scope3();
void scope4();
void scope5();
void scope6();
void scope7();
void scope8();
void scope9();

int main() {
    scope1();
    scope2();
    scope3();
    scope4();
    scope5();
    scope6();
    scope7();
    scope8();
    scope9();
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

void D() {
    std::cout << "D" << std::endl;
}

void scope1() {
    A(); B();
}

void scope2() {
    A(); B();
}

void scope3() {
    A();
}

void scope4() {
    C(); D();
}

void scope5() {
    C(); D();
}

void scope6() {
    C(); D();
}

void scope7() {
    C(); D();
}

void scope8() {
    C(); D();
}

void scope9() {
    C();
}

