extern int printf(const char *, ...);
extern int rt_memory_allocate_init_zero(void **pp, unsigned long size);
extern int func_002FB2D8(void **pp, unsigned long size);
extern void rt_memory_free(void *pp);
typedef struct { char pad[0x8000]; unsigned int size; char pad2[0x8410 - 0x8004]; int x8410; } Ctx310D40;
int RtXml_CreateParser(Ctx310D40 **out, int flags, unsigned int size)
{
    Ctx310D40 *c = 0;
    void *h = 0;
    int r;
    if (out == 0) {
        printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0xF4, "NULL != p_parser");
        return 3;
    }
    *out = 0;
    if (flags) {
        printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0xF6, "RT_XML_ENCODING_ASCII == encoding_type");
        return 6;
    }
    if (size == 0) {
        printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0xF7, "0 != memory_ceiling");
        return 3;
    }
    r = rt_memory_allocate_init_zero((void **)&c, 0x8C2C);
    if (c == 0) {
        printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0xFB, "NULL != p_iparser");
        return 2;
    }
    if (r) {
        printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0xFC, "RT_MEMORY_OK == memErr");
        return 2;
    }
    c->x8410 = 0x18;
    c->size = size;
    r = func_002FB2D8(&h, c->size);
    if (c == 0 || r != 0) {
        if ("Couldn't allocate memory ceiling!\n")
            printf(">>>RT_XML_ASSERT in file %s on line %d due to %s\n", "/usr/local/rel-1.50/rt_xmlparse/src/rt_xmlparse.c", 0x104, "!\"Couldn't allocate memory ceiling!\\n\"");
        rt_memory_free(&c);
        return 2;
    }
    rt_memory_free(&h);
    *out = c;
    return 0;
}