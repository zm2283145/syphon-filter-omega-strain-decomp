#pragma cplusplus on
struct E29F60 { char d[0x2C]; };
struct Tag29F60 {};
struct V29F60 { int first; int count; E29F60* buf; unsigned char flag; };
extern "C" void std_vector_imp_Slide_do_assign(V29F60* self, E29F60* b, E29F60* e, Tag29F60 t);
extern "C" V29F60* cArray_Slide_opAssign(V29F60* self, V29F60* o)
{
    if (self != o) {
        Tag29F60 t;
        std_vector_imp_Slide_do_assign(self, o->buf, o->buf + o->count, t);
    }
    self->flag = o->flag;
    return self;
}