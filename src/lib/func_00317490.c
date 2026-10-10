typedef struct { float x, y; } G7V2;
typedef struct { float a; float pad; G7V2 v; } G7A;
extern float D_004E1BE0, D_004E1CB8, D_004E1C4C, D_004E1C50, D_004E1C30, D_004E1CBC;
void func_00317490(G7A* a, G7V2* b)
{
    G7V2* v = &a->v;
    float x = b->x;
    float y = b->y;
    float s;
    if (v->x * D_004E1BE0 < x && x < v->x * D_004E1CB8) {
        y += 1.0f;
        x = x * D_004E1C4C + v->x * D_004E1C50;
    } else if (D_004E1C4C <= v->y) {
        x = v->x;
        y = v->y;
    } else {
        x = 1000.0f;
        y = 0.0f;
    }
    s = a->a;
    b->x = x;
    if (s * D_004E1C30 < x && x < s * D_004E1CBC) y += 1.0f;
    b->y = y;
}