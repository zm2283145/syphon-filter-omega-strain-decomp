#pragma cplusplus on
struct E29F60 { char d[0x2C]; };
struct Tag29F60 {};
struct V29F60 { int first; int count; E29F60* buf; unsigned char flag; };
extern "C" void func_0032A870(V29F60* self, E29F60* b, E29F60* e, Tag29F60 t);
extern "C" V29F60* func_00329F60(V29F60* self, V29F60* o)
{
    if (self != o) {
        Tag29F60 t;
        func_0032A870(self, o->buf, o->buf + o->count, t);
    }
    self->flag = o->flag;
    return self;
}