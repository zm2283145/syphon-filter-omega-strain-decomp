/* Minimal kernel-style vprintf (putchar hook D_004861A4), interrupts disabled while printing. */
__asm__("__moddi3 = Libgcc_Moddi3\n"
        "__divdi3 = Libgcc_Divdi3\n"
        "__umoddi3 = Libgcc_Umoddi3\n"
        "__udivdi3 = Libgcc_Udivdi3\n"
        "dptofp = SoftFloat_DoubleToFloat\n"
        "fptodp = SoftFloat_FloatToDouble\n");
extern int DIntr(void);
extern int EIntr(void);
extern void printfloat(double x);
extern void (*D_004861A4)(int);

void _printf(const char *fmt, char *ap)
{
    char buf[32];
    char *s;
    const char *p;
    char *pad;
    int lmod;
    int w;
    long v;
    float f;
    int intr;
    int c;

    intr = DIntr();
    for (; *fmt; fmt = p) {
        pad = 0;
        lmod = 0;
        if (*fmt == '%') {
        top:
        p = fmt + 1;
    again:
        fmt = p;
        switch (*fmt) {
        case '0':
            w = p[1] - '0';
            c = p[2];
            if ((unsigned char)w < 10) {
                if ((unsigned)(c - '0') < 10) {
                    w = w * 10 + (c - '0');
                    fmt = p + 2;
                    if (w > 31) w = 31;
                } else {
                    fmt = p + 1;
                }
                pad = &buf[31 - w];
                if (w <= 0) goto top;
                p = fmt + 1;
            fill:
                buf[31 - w] = '0';
                w--;
                if (w > 0) goto fill;
                goto again;
            }            p++;
            goto again;
        case 'l':
            lmod = 'l';
            p++;
            goto again;
        case 'h':
            lmod = 'h';
            p++;
            goto again;
        case 'o':
            if (lmod == 'l') { ap += 8; v = *(unsigned long *)(ap - 8); }
            else if (lmod == 'h') { ap += 8; v = *(unsigned short *)(ap - 8); }
            else { ap += 8; v = *(unsigned int *)(ap - 8); }
            s = &buf[31];
            *s = 0;
            if (v == 0) { *--s = '0'; p++; }
            else { p++; do {
                *--s = (v & 7) + '0';
                v = (unsigned long)v >> 3;
            } while (v); }
            if (pad && pad < s) s = pad;
            while (*s) D_004861A4(*s++);
            continue;
        case 'x':
            if (lmod == 'l') { ap += 8; v = *(unsigned long *)(ap - 8); }
            else if (lmod == 'h') { ap += 8; v = *(unsigned short *)(ap - 8); }
            else { ap += 8; v = *(unsigned int *)(ap - 8); }
            s = &buf[31];
            *s = 0;
            if (v == 0) { *--s = '0'; p++; }
            else { p++; do {
                unsigned long d = v & 15;
                if (d < 10) *--s = d + '0'; else *--s = d + 'a' - 10;

                v = (unsigned long)v >> 4;
            } while (v); }
            if (pad && pad < s) s = pad;
            while (*s) D_004861A4(*s++);
            continue;
        case 'd':
            if (lmod == 'l') { ap += 8; v = *(long *)(ap - 8); }
            else if (lmod == 'h') { ap += 8; v = *(short *)(ap - 8); }
            else { ap += 8; v = *(int *)(ap - 8); }
            s = &buf[31];
            *s = 0;
            if (v == 0) { *--s = '0'; p++; }
            else {
                if (v < 0) {
                    v = -v;
                    D_004861A4('-');
                }
                while (v) {
                    *--s = v % 10 + '0';
                    v = v / 10;
                }
                p++;
            }
            if (pad && pad < s) s = pad;
            while (*s) D_004861A4(*s++);
            continue;
        case 'u':
            if (lmod == 'l') { ap += 8; v = *(unsigned long *)(ap - 8); }
            else if (lmod == 'h') { ap += 8; v = *(unsigned short *)(ap - 8); }
            else { ap += 8; v = *(unsigned int *)(ap - 8); }
            s = &buf[31];
            *s = 0;
            if (v == 0) { *--s = '0'; p++; }
            else { p++; do {
                *--s = (unsigned long)v % 10 + '0';
                v = (unsigned long)v / 10;
            } while (v); }
            if (pad && pad < s) s = pad;
            while (*s) D_004861A4(*s++);
            continue;
        case 'e':
        case 'f':
            ap += 8;
            f = *(double *)(ap - 8);
            if (f == 0.0f) {
                D_004861A4('0');
                p++;
            } else {
                p++;
                printfloat(f);
            }
            continue;
        case 's':
            ap += 8;
            {
            char *str = *(char **)(ap - 8);
            if (*str == 0) {
                p++;
                D_004861A4('('); D_004861A4('n'); D_004861A4('u'); D_004861A4('l'); D_004861A4('l'); D_004861A4(')');
            } else {
                s = str; p++;
                do D_004861A4(*s++); while (*s);
            }
            }
            continue;
        case 'c':
            ap += 8;
            v = *(char *)(ap - 8);
            p++;
            D_004861A4(v);
            continue;
        case '1' ... 'b': case 'g': case 'i' ... 'k': case 'm': case 'n': case 'p' ... 'r': case 't': case 'v': case 'w':
            break;
        default:
            goto oor;
        }
        } else {
            p = fmt + 1;
            D_004861A4(*fmt);
            continue;
        }
        goto inc;
    oor:
        p = fmt + 1;
        continue;
    inc:
        p++;
    }
    if (intr) EIntr();
}
