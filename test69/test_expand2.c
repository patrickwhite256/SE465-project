void b1(){};
void b2(){};
void b2_wrapper(){
    b2();
}

void c1(){
    b1();
    b2();
};

void c2(){
    b1();
    b2();
}

void c3(){
    b1();
    b2();
}

void c4(){
    b1();
    b2();
}

void c5(){
    b1();
    b2();
}

void c6(){
    b1();
    b2();
}

void c7(){
    b1();
    b2();
}

void c8(){
    b1();
    b2_wrapper();
}

void r1();
void r2();

void r1(){
    b1();
    r2();
}

void r2(){
    b2();
    r1();
}

int main(int argc, char **argv){
    c1();
    c2();
    c3();
    c4();
    c5();
    c6();
    c7();
    c8();
}
