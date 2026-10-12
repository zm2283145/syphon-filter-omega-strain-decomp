int func_00315608(int code, int *out)
{
    if (out == 0) return 0x17;
    switch (code) {
    case 0: *out = 0x21; break;
    case 1: *out = 0x3F; break;
    case 2: *out = 0x22; break;
    case 3: *out = 0x24; break;
    case 4: *out = 0x23; break;
    default: return 0x17;
    }
    return 0;
}
