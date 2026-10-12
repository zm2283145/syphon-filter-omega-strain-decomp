#pragma cplusplus on

typedef union Str {
    struct { unsigned int word; unsigned int length; char* data; } l;
    struct { unsigned int isLong : 1; unsigned int length : 7; } s;
    char inl[12];
} Str;

extern "C" unsigned int func_003B9410(const Str* self, const char* s, unsigned int pos, unsigned int n)
{
    const char* data;
    unsigned int len;
    if (!(self->l.word & 1)) {
        data = (const char*)self + 1;
        len = (unsigned char)self->s.length;
    } else {
        data = self->l.data;
        len = self->l.length;
    }
    if (len >= n) {
        const char* last;
        const char* p;
        if (len - n < pos) pos = len - n;
        last = s + n;
        for (p = data + pos; ; --p) {
            const char* g = p;
            const char* f = s;
            for (; f < last; ++f, ++g)
                if (*f != *g) goto next;
            return p - data;
        next:
            if (!(data < p)) break;
        }
    }
    return (unsigned int)-1;
}



