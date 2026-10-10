typedef int C4q __attribute__((mode(TI)));
C4q* Mtx_Copy_23E150(C4q* d, C4q* s) {
    C4q a, b;
    a = s[0];
    b = s[1];
    d[0] = a;
    a = s[2];
    d[1] = b;
    b = s[3];
    d[2] = a;
    d[3] = b;
    return d;
}