int func_003010D8(int *out, unsigned char v)
{
    if (out == 0) return 2;
    switch (v) {
    case 0: *out = 2; break;
    case 1: *out = 4; break;
    case 2: *out = 5; break;
    case 3: *out = 6; break;
    case 4: *out = 7; break;
    case 5: *out = 8; break;
    case 6: *out = 9; break;
    default: return 1;
    }
    return 0;
}
