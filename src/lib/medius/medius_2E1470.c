extern int D_0048C4B0;
extern int rt_p2p_receive_broadcasts(int, unsigned char);
int __attribute__((weak, section(".dtors_drop"))) DmeToRtMsgConnectionIndex(unsigned int p0) { return 0; }
extern int rt_msg_client_receive_broadcasts(int, unsigned char);
extern int NetMapMsgClientError(int, int);
int NetISetMyClientReceiveBroadcast(unsigned int a, int b)
{
    int r;
    if (a >= 4) return 0x17;
    if (!(a == 0 || a == 0xFFFF)) {
        r = NetMapMsgClientError(rt_msg_client_receive_broadcasts(DmeToRtMsgConnectionIndex(a), b), 0x18);
        if (r) return r;
    } else {
        if (rt_p2p_receive_broadcasts(D_0048C4B0, b)) return 0x25;
    }
    return 0;
}

/* score: 1 insn diff (beql vs beq w/ lui in delay slot; reorg liveness) */
