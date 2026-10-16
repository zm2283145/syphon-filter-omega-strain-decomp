typedef struct { int a, b, c; } Str3D;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_EF0;
typedef struct {
    Str3D name;
    int i;
    V4_EF0 v;
    float f0, f1;
} Ent3D;
typedef struct { int value; } Word;
extern void String_CtorCStr_13B480(Str3D* s, const char* c);
extern void String_Dtor(Str3D* s, int d);
extern void func_003D1280(Word* out, void* list, Word* pos, Ent3D* e);
void TextManager_QueueText(char* o, const char* name, int i, V4_EF0* v, int a, int b)
{
    Ent3D e;
    Word out;
    Word pos;
    String_CtorCStr_13B480(&e.name, name);
    e.i = i;
    e.v.x = v->x;
    e.v.y = v->y;
    e.v.z = v->z;
    e.v.w = v->w;
    e.f0 = (float)a;
    e.f1 = (float)b;
    pos.value = (int)(o + 8);
    func_003D1280(&out, o + 4, &pos, &e);
    String_Dtor(&e.name, 0);
}
