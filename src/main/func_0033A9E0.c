#pragma cplusplus on
struct Tag3A9E0 {};
struct V3A9E0 { int cap; int size; char* buf; };
extern "C" void func_0033B980(V3A9E0* self, char* b, char* e, Tag3A9E0 t);
extern "C" V3A9E0* func_0033A9E0(V3A9E0* self, V3A9E0* o)
{
    if (self != o) {
        Tag3A9E0 t;
        func_0033B980(self, o->buf, o->buf + o->size, t);
    }
    return self;
}