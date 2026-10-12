typedef struct { int a; void *name; int pad; void *attr[64]; void *text; } Elem313150;
/* same-unit callee stub: weak, in a section the link discards; restores retail delay-slot choices */
void __attribute__((weak, section(".dtors_drop"))) func_00311320(void *c, void *pp) { }
int func_00313150(void *c, Elem313150 *e)
{
    unsigned int i;
    if (e) {
        if (e->name)
            func_00311320(c, &e->name);
        for (i = 0; i < 64; i++) {
            if (e->attr[i])
                func_00311320(c, &e->attr[i]);
        }
        if (e->text)
            func_00311320(c, &e->text);
        func_00311320(c, &e);
    }
    return 0;
}