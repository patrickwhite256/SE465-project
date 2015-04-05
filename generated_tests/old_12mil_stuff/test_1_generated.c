#include "stdio.h"

void basic_11() {
    printf("11\n");
}

void basic_10() {
    printf("10\n");
}

void basic_1() {
    printf("1\n");
}

void basic_3() {
    printf("3\n");
}

void basic_2() {
    printf("2\n");
}

void basic_5() {
    printf("5\n");
}

void basic_4() {
    printf("4\n");
}

void basic_7() {
    printf("7\n");
}

void basic_6() {
    printf("6\n");
}

void basic_9() {
    printf("9\n");
}

void basic_8() {
    printf("8\n");
}

void caller_20() {
    basic_10();
    basic_7();
    basic_2();
    basic_8();
    basic_9();
    basic_5();
    basic_1();
    basic_11();
}

void caller_21() {
    basic_11();
    basic_5();
}

void caller_22() {
    basic_3();
    basic_6();
    basic_7();
    basic_8();
    basic_5();
    basic_2();
    basic_4();
    basic_1();
}

void caller_1() {
    basic_2();
}

void caller_3() {
    basic_10();
    basic_3();
    basic_8();
    basic_7();
    basic_11();
    basic_6();
    basic_5();
    basic_4();
    basic_9();
}

void caller_2() {
    basic_6();
    basic_3();
    basic_1();
    basic_9();
    basic_8();
    basic_10();
    basic_2();
    basic_11();
}

void caller_5() {
    basic_6();
    basic_10();
    basic_3();
    basic_7();
    basic_8();
    basic_5();
    basic_2();
    basic_4();
    basic_1();
    basic_11();
}

void caller_4() {
    basic_3();
    basic_1();
    basic_7();
    basic_5();
    basic_9();
    basic_11();
    basic_8();
    basic_2();
}

void caller_7() {
    basic_8();
    basic_4();
    basic_6();
    basic_10();
    basic_5();
    basic_11();
    basic_3();
    basic_7();
}

void caller_6() {
    basic_2();
    basic_4();
    basic_3();
    basic_5();
    basic_10();
    basic_11();
    basic_9();
}

void caller_9() {
    basic_1();
    basic_7();
    basic_4();
    basic_3();
    basic_9();
    basic_2();
    basic_6();
    basic_5();
    basic_10();
    basic_11();
}

void caller_8() {
    basic_1();
    basic_11();
}

void caller_11() {
    basic_3();
    basic_7();
    basic_5();
    basic_9();
    basic_2();
    basic_4();
    basic_8();
    basic_10();
}

void caller_10() {
    basic_3();
    basic_11();
}

void caller_13() {
    basic_8();
}

void caller_12() {
    basic_3();
    basic_9();
    basic_10();
    basic_7();
    basic_6();
    basic_11();
    basic_4();
    basic_2();
    basic_5();
}

void caller_15() {
    basic_4();
}

void caller_14() {
    basic_2();
    basic_8();
    basic_3();
    basic_4();
    basic_11();
    basic_9();
    basic_7();
    basic_6();
}

void caller_17() {
    basic_5();
    basic_3();
    basic_11();
    basic_4();
    basic_2();
    basic_6();
    basic_8();
    basic_10();
    basic_9();
    basic_1();
}

void caller_16() {
    basic_9();
    basic_7();
}

void caller_19() {
    basic_9();
    basic_3();
    basic_1();
    basic_6();
    basic_5();
    basic_8();
    basic_11();
    basic_7();
    basic_2();
}

void caller_18() {
    basic_3();
    basic_6();
    basic_7();
}

int main() {
    caller_20();
    caller_21();
    caller_22();
    caller_1();
    caller_3();
    caller_2();
    caller_5();
    caller_4();
    caller_7();
    caller_6();
    caller_9();
    caller_8();
    caller_11();
    caller_10();
    caller_13();
    caller_12();
    caller_15();
    caller_14();
    caller_17();
    caller_16();
    caller_19();
    caller_18();
    return 0;
}
