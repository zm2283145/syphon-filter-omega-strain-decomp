int NetMapMsgClientError(int code, int r)
{
    switch (code) {
    case 0: r = 0; break;
    case 2: r = 0x17; break;
    case 8: r = 0x16; break;
    case 25: r = 2; break;
    case 3: r = 0x21; break;
    case 5: r = 0x12; break;
    case 6: r = 0x23; break;
    case 9: r = 0xA; break;
    case 11: r = 0xF; break;
    case 12: r = 3; break;
    case 13: r = 0xE; break;
    case 14: case 15: case 19: r = 0xD; break;
    case 16: r = 0x22; break;
    case 17: r = 0x1A; break;
    case 20: case 21: r = 0x24; break;
    case 18: case 22: r = 0x25; break;
    case 23: r = 0x10; break;
    case 27: case 28: r = 0x20; break;
    }
    return r;
}
