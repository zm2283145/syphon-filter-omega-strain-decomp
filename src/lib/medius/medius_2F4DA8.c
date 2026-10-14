unsigned int func_002F4DA8(char* s)
{
    unsigned int r = 0;
    unsigned int n = 0;
    char c;
    if (s != 0) {
        while ((c = *s++) != 0) {
            if (c == '.') {
                r = (r << 8) + n;
                n = 0;
            } else if ((unsigned char)(c - '0') < 10) {
                n = n * 10 + (c - '0');
            }
        }
        r = (r << 8) + n;
    }
    return r;
}