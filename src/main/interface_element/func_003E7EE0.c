typedef struct { char pad[0x1A]; unsigned char r, g, b, a; } O_E7EE0;
void func_003E7EE0(O_E7EE0* o, float* c)
{
    unsigned char g = (unsigned int)(255.0f * c[1]);
    unsigned char b = (unsigned int)(255.0f * c[2]);
    unsigned char a = (unsigned int)(255.0f * c[3]);
    o->r = (unsigned int)(255.0f * c[0]);
    o->g = g;
    o->b = b;
    o->a = a;
}
