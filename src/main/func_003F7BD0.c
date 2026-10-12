typedef unsigned int u32;
extern char D_0055C540;
void func_003F6BE0(void* q, char** p1, int* n1, char** p2, int* n2);
void func_003F6B00(void* q, int n);
void* memcpy(void* d, const void* s, unsigned int n);

struct Hdr_F7BD0 {
    int pad0;
    int pad4;
    char* pos;
    int size;
};

int func_003F7BD0(void* self, struct Hdr_F7BD0* h, char* ring)
{
    char* p1;
    char* p2;
    int n1;
    int n2;
    int len;
    int rest;
    int cap;
    char* src;
    int total;
    int a;
    int second;
    char* d1;
    char* d2;
    int first;
    char* end;

    src = h->pos + 4;
    cap = *(int*)(ring + 0x50008);
    end = ring + cap;
    if (src >= end) {
        src -= cap;
    }
    first = end - src;
    len = h->size - 4;
    first = (first < len) ? first : len;
    second = len - first;
    func_003F6BE0(&D_0055C540, &p1, &n1, &p2, &n2);
    {
        a = n1;
        d2 = p2;
        d1 = p1;
        total = first + second;
        if (a + n2 < total) {
            total = 0;
        } else if (first >= a) {
            memcpy(d1, src, a);
            memcpy(d2, src + a, first - a);
            memcpy(d2 + first - a, ring, second);
        } else {
            rest = a - first;
            if (second >= rest) {
                memcpy(d1, src, first);
                memcpy(d1 + first, ring, rest);
                memcpy(d2, ring + a - first, second - rest);
            } else {
                memcpy(d1, src, first);
                memcpy(d1 + first, ring, second);
            }
        }
    }
    func_003F6B00(&D_0055C540, total);
    return total > 0;
}




