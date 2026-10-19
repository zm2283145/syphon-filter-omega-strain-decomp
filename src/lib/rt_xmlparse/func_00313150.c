typedef struct { int a; void *name; int pad; void *attr[64]; void *text; } Elem313150;
/* same-unit callee stub: weak, in a section the link discards; restores retail delay-slot choices */
void __attribute__((weak, section(".dtors_drop"))) RtXml_Free(void *c, void *pp) { }
int func_00313150(void *c, Elem313150 *e)
{
    unsigned int i;
    if (e) {
        if (e->name)
            RtXml_Free(c, &e->name);
        for (i = 0; i < 64; i++) {
            if (e->attr[i])
                RtXml_Free(c, &e->attr[i]);
        }
        if (e->text)
            RtXml_Free(c, &e->text);
        RtXml_Free(c, &e);
    }
    return 0;
}