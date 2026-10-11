typedef struct { int a, b, c; } S29930;
typedef struct { int first; int count; void* buf; char flag; } V29F60;
typedef struct { S29930 s0; V29F60 v; int x; } E20;
extern void func_00329930(S29930* dst, S29930* src);
extern V29F60* func_00329F60(V29F60* dst, V29F60* src);
E20* func_00329FD0(E20* first, E20* last, E20* result)
{
    while (first < last) {
        --last;
        --result;
        func_00329930(&result->s0, &last->s0);
        func_00329F60(&result->v, &last->v);
        result->x = last->x;
    }
    return result;
}