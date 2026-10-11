int func_00315730(int a, int* out)
{
    if (out == 0)
        return 0x17;
    switch (a) {
    case 0: *out = 3; break;
    case 1: *out = 0; break;
    default: return 0x17;
    }
    return 0;
}
