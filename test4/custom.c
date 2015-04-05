#include "stdio.h"

void call_1();
void call_2();
void call_3();
void call_4();
void call_5();
void call_6();
void call_7();
void call_8();
void call_9();
void call_10();
void call_11();
void call_12();
void call_13();
void call_14();
void call_15();
void call_16();

void A();
void B();
void C();
void D();
void E();

int main() {
    call_1();
    call_2();
    call_3();
    call_4();
    call_5();
    call_6();
    call_7();
    call_8();
    call_9();
    call_10();
    call_11();
    call_12();
    call_13();
    call_14();
    call_15();
    call_16();

    return 0;
}

void A() {
    printf("A");
}

void B() {
    printf("B");
}

void C() {
    printf("C");
}

void D() {
    printf("D");
}

void E() {
    printf("E");
}

void call_1() {
    A(); B(); C();
}

void call_2() {
    A(); B(); C(); D();
}

void call_3() {
    A(); B(); C(); E();
}

void call_4() {
    A(); B(); C(); D();
}

void call_5() {
    A(); B(); C();
}

void call_6() {
    A(); B(); C(); D(); E();
}

void call_7() {
    A(); B(); C();
}

void call_8() {
    A(); B(); C(); D();
}

void call_9() {
    A(); B(); C(); E();
}

void call_10() {
    A(); B(); C(); D();
}

void call_11() {
    B(); C();
}

void call_12() {
    B(); C(); D(); E();
}

void call_13() {
    B(); C();
}

void call_14() {
    B(); C(); D();
}

void call_15() {
    C(); E();
}

void call_16() {
    C(); D();
}
