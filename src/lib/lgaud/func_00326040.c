#include "lgaud.h"

/* Completion callback of lgAudAWrite/AWriteVag; releases the semaphore they kept. */
void lgAudAWriteCallback(lgAudAsyncReq *req)
{
    *req->len = lgAud_pkt->u.size;
    req->ret = lgAud_pkt->ret;
    iSignalSema(lgAud_sema);
}
