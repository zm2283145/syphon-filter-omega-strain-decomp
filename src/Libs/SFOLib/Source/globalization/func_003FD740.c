/* func_003FD740: converts a UTF-8 string in place to the game's local character set (globalization). */
#include "types.h"

typedef union String {
    struct {
        unsigned int cap;
        int size;
        char* data;
    } l;
    struct {
        unsigned char isLong : 1;
        unsigned char size : 7;
        char data[11];
    } s;
} String;

typedef struct CharMap {
    char pad[0x5C0];
    unsigned char* page[256];
} CharMap;

extern unsigned char D_0055D450;
extern CharMap D_0055CA90;
extern void std_basic_string_char_char_traits_char_reserve(String* s, int n);
extern const unsigned char* std_basic_string_char_char_traits_char_c_str(String* s);
extern void std_basic_string_char_char_traits_char_opAddAssign(String* s, char c);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* d, String* s);
extern void String_Dtor(String* s, int del);

/* Inlined UTF-8 decoder. Locals as below (q first-byte pointer, continuation loop re-indexes base + at,
 * which MW strength-reduces from a fresh p + pos); the declaration order sets retail's colouring. */
static inline void Utf8Decode(unsigned int* ch, int* len, const unsigned char* base, int at)
{
    int n;
    const unsigned char* q;
    unsigned int v;
    int c;
    int i;
    *ch = 0;
    q = base + at;
    if (q == 0) {
        *len = 0;
        return;
    }
    c = *q;
    if (c & 0x80) {
        if (c >= 0xC0 && c < 0xFE) {
            if (c >> 5 == 6)
                n = 1;
            else if (c >> 4 == 0xE)
                n = 2;
            else if (c >> 3 == 0x1E)
                n = 3;
            else if (c >> 2 == 0x3E)
                n = 4;
            else if (c >> 1 == 0x7E)
                n = 5;
            else {
                *len = -1;
                return;
            }
            v = ((1 << (6 - n)) - 1) & c;
            for (i = 1; i <= n; i++) {
                int b;
                if (!(base + at)[i]) {
                    *len = -i;
                    return;
                }
                b = (base + at)[i] & 0xFF;
                if (!(b & 0x80)) {
                    *len = -i;
                    return;
                }
                if (b & 0x40) {
                    *len = -i;
                    return;
                }
                v <<= 6;
                v += b & 0x3F;
            }
            *ch = v;
            *len = n + 1;
            return;
        }
        *len = -1;
        return;
    }
    *ch = c;
    *len = 1;
}

int func_003FD740(String* str)
{
    unsigned int ch;
    String out;
    int pos;
    const unsigned char* p;
    int n;
    int len;
    if (!D_0055D450)
        return 0;
    if (str->l.cap & 1)
        len = str->l.size;
    else
        len = (unsigned char)str->s.size;
    if (len == 0)
        return 1;
    { String* o = (String*)((char*)&out + 0); o->l.cap = 0; o->l.size = 0; o->l.data = 0; }
    std_basic_string_char_char_traits_char_reserve(&out, len);
    pos = 0;
    p = std_basic_string_char_char_traits_char_c_str(str);
    while (pos <= len) {
        Utf8Decode(&ch, &n, p, pos);
        if (n <= 0) {
            if (n == 0)
                break;
            pos -= n;
        } else {
            if (ch < 0x10000) {
                unsigned short w = ch;
                unsigned char* page = D_0055CA90.page[(w >> 8) & 0xFF];
                unsigned char c = page ? page[w & 0xFF] : 0xFF;
                if (c != 0xFF) {
                    if (ch < 0x20)
                        std_basic_string_char_char_traits_char_opAddAssign(&out, c);
                    else
                        std_basic_string_char_char_traits_char_opAddAssign(&out, (unsigned char)(c + 0x20));
                }
            }
            pos += n;
        }
    }
    std_basic_string_char_char_traits_char_assign_basicstringR(str, &out);
    String_Dtor(&out, 0);
    return 1;
}
