#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00110720(int arg0) {
    int temp_a1;

    temp_a1 = F_(arg0, 0x0, int);
    if ((temp_a1 == NULL) || (F_(arg0, 0x4, int) != F_(temp_a1, 0x18, int)) || !(F_(temp_a1, 0x10, int) & 1)) {
        return 0;
    }
    return 1;
}
