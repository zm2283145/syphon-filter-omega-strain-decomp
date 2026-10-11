#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void func_00103D08(signed char *arg0, int arg1) {
    int var_v0;
    signed char *var_a0;

    var_a0 = arg0;
    var_v0 = arg1 - 1;
    if (arg1 != 0) {
        do {
            *var_a0 = 0;
            var_v0 -= 1;
            var_a0 += 1;
        } while (var_v0 != -1);
    }
}
