typedef struct {
    int sock;
    char pad4[4];
    unsigned int kind;
    char padC[4];
    char timer[8];
    char hdr[0xA24 - 0x18];
    char service[0x2070 - 0xA24];
    char resp[0x800];
} UpnpReq;
typedef struct {
    char pad0[0x58];
    UpnpReq *req;
} UpnpObj;
extern int func_002F61A0(int sock, void *from, unsigned short *fromlen, char *buf, int size, unsigned short *len);
extern int func_0030B760(char *resp, char *hdr);
extern int func_003060F0(void *timer, unsigned int *ms);
extern int String_CompareN(const char *a, const char *b, unsigned int n);
extern char D_004AFAB0[];
extern char D_004AFAE0[];
extern char D_004AFB18[];
extern char D_004AFB48[];

/* Polls the UPnP discovery reply; sets *done and returns 0 when the expected service answered. */
int func_0030BE60(UpnpObj *o, unsigned char *done)
{
    char from[16];
    unsigned short fromlen = 0;
    unsigned short len = 0;
    unsigned int ms;
    char *svc;

    if (func_002F61A0(o->req->sock, from, &fromlen, o->req->resp, 0x800, &len) != 0) {
        *done = 1;
        return 5;
    }
    if (len != 0) {
        *done = 1;
        o->req->resp[len] = 0;
        len = func_0030B760(o->req->resp, o->req->hdr);
        if (len == 200) {
            switch (o->req->kind) {
            case 0x20:
                if (String_CompareN(D_004AFAB0, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x40:
                if (String_CompareN(D_004AFAE0, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x1000:
                if (String_CompareN(D_004AFB18, o->req->service, 0x200) != 0) return 10;
                break;
            case 0x800:
                if (String_CompareN(D_004AFB48, o->req->service, 0x200) != 0) return 10;
                break;
            default:
                return 13;
            }
        } else {
            return 11;
        }
    } else {
        func_003060F0(o->req->timer, &ms);
        if (ms >= 5001) {
            *done = 1;
            return 6;
        }
    }
    return 0;
}
