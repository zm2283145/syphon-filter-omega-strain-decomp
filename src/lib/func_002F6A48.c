/* The EE soft-float libcall is aliased to its retail function. */
__asm__("fptodp = SoftFloat_FloatToDouble");
typedef struct { unsigned int count; float rate; float peak; } Rate2F6A48;
typedef struct { int timer[2]; Rate2F6A48 r[4]; } Stats2F6A48;
extern Stats2F6A48 D_00525508;
extern char D_00525540[];
extern char D_004AF1D8[];
extern char D_004AF200[];
extern char D_004AF228[];
extern char D_004AF250[];
extern char D_004AF278[];
extern int func_00306158(void *t, unsigned int *elapsed);
extern int func_00127358(const char *fmt, ...);
extern int func_003060C0(void *t);
/* Prints the transfer-rate statistics once more than a second has elapsed. */
int func_002F6A48(void)
{
    unsigned int ms;
    Stats2F6A48 *s;

    if (func_00306158(D_00525540, &ms) != 0) return 1;
    if (ms > 1000) {
        s = &D_00525508;
        func_00127358(D_004AF1D8, s->r[0].rate, s->r[0].peak);
        func_00127358(D_004AF200, s->r[1].rate, s->r[1].peak);
        func_00127358(D_004AF228, s->r[2].rate, s->r[2].peak);
        func_00127358(D_004AF250, s->r[3].rate, s->r[3].peak);
        func_00127358(D_004AF278);
        if (func_003060C0(D_00525540) != 0) return 1;
    }
    return 0;
}
