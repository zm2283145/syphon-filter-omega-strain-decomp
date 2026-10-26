/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char pad[0xA4]; int sock; } Obj50D0;
extern short D_00491432;
extern unsigned char D_00491430;
extern int NetStreamMediaGetInfo(int idx, Obj50D0 **out);
int __attribute__((weak, section(".dtors_drop"))) NetStreamMediaIsValidInfo(Obj50D0 *o) { return 0; }
int NetStreamMediaFindValidInfo(int sock, Obj50D0 **out)
{
    Obj50D0 *o;
    int i;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    if (out == 0) return 0x17;
    *out = 0;
    for (i = 0; i < 4; i++) {
        r = NetStreamMediaGetInfo(i, &o);
        if (r != 0) return r;
        if (o != 0 && sock == o->sock) {
            *out = o;
            break;
        }
    }
    return NetStreamMediaIsValidInfo(*out) == 1 ? 0 : 0x29;
}
