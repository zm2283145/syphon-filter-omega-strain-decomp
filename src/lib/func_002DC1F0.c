typedef struct { char pad[0x24]; void (*cb)(int); char pad2[0x14]; int arg; } XC1F0;
extern void func_002FB3C0(XC1F0** pp);
void func_002DC1F0(XC1F0* p)
{
    if (p) {
        if (p->cb)
            p->cb(p->arg);
        func_002FB3C0(&p);
    }
}
