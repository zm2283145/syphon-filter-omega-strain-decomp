typedef struct { char pad[0xE]; short cnt; char pad2[3]; char on; char flag; } G1S;
extern float D_004E1C1C;
void func_0031E988(short a, G1S* p, float lim, float v)
{
    if (p->on) {
        float x = (float)a - 42.5f;
        float t = v - D_004E1C1C;
        float m = (x <= t) ? t : x;
        if (m <= lim) {
            if (++p->cnt >= 2) {
                p->flag = 1;
                p->cnt = 1;
                return;
            }
            p->flag = 0;
            return;
        }
    }
    p->cnt = 0;
    p->flag = 0;
}