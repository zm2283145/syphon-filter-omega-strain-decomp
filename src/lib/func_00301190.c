int func_00301190(int *out, unsigned char v)
{
    if (out == 0) return 2;
    switch (v) {
    case 0: *out = 0; break;
    case 1: *out = 1; break;
    case 2: *out = 2; break;
    case 3: *out = 3; break;
    case 4: *out = 4; break;
    default: return 1;
    }
    return 0;
}
