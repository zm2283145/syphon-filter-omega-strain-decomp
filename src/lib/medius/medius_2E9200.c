typedef struct {
    int state;
    int pad[7];
    unsigned int time;
    int a;
    int b;
} Ent_2E9200;
extern Ent_2E9200 D_005227F0[];
extern int rt_time_get_local(unsigned int *);
extern void DmeFree(int *);
int NetTimeoutMultiPackets(void)
{
    unsigned int now;
    unsigned int i;
    rt_time_get_local(&now);
    for (i = 0; i < 0x100; i++) {
        if (D_005227F0[i].state == 2 && now - D_005227F0[i].time > 30000) {
            if (D_005227F0[i].b) {
                DmeFree(&D_005227F0[i].b);
                D_005227F0[i].b = 0;
            }
            if (D_005227F0[i].a) {
                DmeFree(&D_005227F0[i].a);
                D_005227F0[i].a = 0;
            }
            D_005227F0[i].state = 0;
        }
    }
    return 0;
}

