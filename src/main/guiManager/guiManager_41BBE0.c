#pragma cplusplus on

typedef union Str {
    struct { unsigned int word; unsigned int length; char* data; } l;
    struct { unsigned int isLong : 1; unsigned int length : 7; } s;
    char inl[12];
} Str;

typedef struct Alloc { char unused; } Alloc;

extern "C" {
Str* String_Replace(Str* s, unsigned int pos, unsigned int n, const char* first, const char* last, Alloc a);
void func_00123BE8(int, const char*);
void Libc_Abort(void);
extern char* D_00489738;
extern char D_004BF1D0[];
}

template <class T> static inline const T& Min(const T& a, const T& b) { return b < a ? b : a; }

extern "C" Str* func_0041BBE0(Str* self, unsigned int pos, unsigned int n1, const Str* str, unsigned int pos2, unsigned int n2)
{
    unsigned int rem;
    Alloc a;
    const char* data;
    unsigned int len;
    if (!(str->l.word & 1)) {
        data = (const char*)str + 1;
        len = (unsigned char)str->s.length;
    } else {
        data = str->l.data;
        len = str->l.length;
    }
    if (len < pos2) {
        func_00123BE8(*(int*)(D_00489738 + 0xC), D_004BF1D0);
        Libc_Abort();
    }
    data += pos2;
    rem = len - pos2; n2 = Min(n2, rem);
    return String_Replace(self, pos, n1, data, data + n2, a);
}


