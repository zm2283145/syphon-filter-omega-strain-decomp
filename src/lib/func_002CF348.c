extern short D_0048C414;
extern char D_004AD230[];
extern int MGCLCheckRequestQueue(void);
extern int NetUpdate(void);
extern int printf(const char *, ...);
int MGCLUpdate(void)
{
    int r;
    if (D_0048C414 != 1) return -0xC;
    r = MGCLCheckRequestQueue();
    if (r != 0) return r;
    r = NetUpdate();
    if (r != 0) {
        printf(D_004AD230, r);
        return -8;
    }
    return r;
}
