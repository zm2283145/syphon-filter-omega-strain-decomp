extern unsigned char D_00499C71[];
int String_ToLower(int c) {
    if (D_00499C71[c] & 1) c += 0x20;
    return c;
}