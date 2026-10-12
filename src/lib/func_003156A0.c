int func_003156A0(int code, int *out)
{
    if (out == 0) return 0x17;
    switch (code) {
    case 0x21: *out = 0; break;
    case 0x3F: *out = 1; break;
    case 0x22: *out = 2; break;
    case 0x24: *out = 3; break;
    case 0x23: *out = 4; break;
    default: return 0x17;
    }
    return 0;
}
