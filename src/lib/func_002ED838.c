typedef struct { char pad[0x5C]; int x5C; void *x60; } S838;
extern void func_002F3450(void *);
extern int func_002FB3C0(void *pp);
void func_002ED838(S838 *s)
{
    if (s) {
        func_002F3450((char *)s + 0x50);
        if (s->x60) {
            func_002FB3C0(&s->x60);
            s->x60 = 0;
            s->x5C = 0;
        }
        func_002FB3C0(&s);
    }
}
