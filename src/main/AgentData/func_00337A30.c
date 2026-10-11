typedef struct { int cap; int size; char* buf; } V3A9E0;
typedef struct { signed char a; V3A9E0 v; unsigned char b; } E37A30;
extern V3A9E0* func_0033A9E0(V3A9E0* d, V3A9E0* s);
E37A30* func_00337A30(E37A30* first, E37A30* last, E37A30* result)
{
    while (first < last) {
        --last;
        --result;
        result->a = last->a;
        func_0033A9E0(&result->v, &last->v);
        result->b = last->b;
    }
    return result;
}