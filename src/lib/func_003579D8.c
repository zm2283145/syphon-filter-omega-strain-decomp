extern int sprintf(char* buf, const char* fmt, ...);
extern int* func_003583F0();
extern int func_00357D40();
extern int* func_00123320();
extern void String_Copy(char* d, char* s);
extern void* memset(void*, int, unsigned int);
extern unsigned int strlen(const char*);
extern char* func_00357938(unsigned char* a, char* dst, unsigned int size);

char* func_003579D8(unsigned char* src, char* dst, unsigned int size)
{
    char tmp[sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"], *tp;
    struct { int base, len; } best, cur;
    unsigned int words[8];
    int i;

    memset(words, 0, sizeof words);
    for (i = 0; i < 16; i++)
        words[i / 2] |= (src[i] << ((1 - (i % 2)) << 3));
    best.base = -1;
    cur.base = -1;
    for (i = 0; i < 8; i++) {
        if (words[i] == 0) {
            if (cur.base == -1)
                cur.base = i, cur.len = 1;
            else
                cur.len++;
        } else {
            if (cur.base != -1) {
                if (best.base == -1 || cur.len > best.len)
                    best = cur;
                cur.base = -1;
            }
        }
    }
    if (cur.base != -1) {
        if (best.base == -1 || cur.len > best.len)
            best = cur;
    }
    if (best.base != -1 && best.len < 2)
        best.base = -1;

    tp = tmp;
    for (i = 0; i < 8; i++) {
        if (best.base != -1 && i >= best.base && i < (best.base + best.len)) {
            if (i == best.base)
                *tp++ = ':';
            continue;
        }
        if (i != 0)
            *tp++ = ':';
        if (i == 6 && best.base == 0 &&
            (best.len == 6 || (best.len == 5 && words[5] == 0xffff))) {
            if (!func_00357938(src + 12, tp, sizeof tmp - (tp - tmp)))
                return 0;
            tp += strlen(tp);
            break;
        }
        tp += sprintf(tp, "%x", words[i]);
    }
    if (best.base != -1 && (best.base + best.len) == 8)
        *tp++ = ':';
    *tp++ = '\0';

    if ((unsigned int)(tp - tmp) > size) {
        *func_003583F0() = 0x1C;
        if (func_00357D40()) {
            int* e = func_00123320();
            *e = *func_003583F0();
        }
        return 0;
    }
    String_Copy(dst, tmp);
    return dst;
}
