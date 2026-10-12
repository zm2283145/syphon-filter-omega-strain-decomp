extern int D_0049147C;
extern int* D_00491474;
extern int func_0010D190(int sema);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { void *dst; int *len; int ret; } lgAudReadReq;
void func_00325FD8(lgAudReadReq *req)
{
    memcpy(req->dst, (char *)D_00491474 + 0x30, D_00491474[8]);
    *req->len = D_00491474[8];
    req->ret = D_00491474[0];
    func_0010D190(D_0049147C);
}