//
// Created by buaa on 12/26/17.
//

#ifdef NS_PORT
#include "ns-2/aodv-uu.h"
#else
#include "aodv_rrcq.h"
#include "aodv_socket.h"
#endif


RRCQ *NS_CLASS rrcq_create(u_int8_t flags, int dest_addr, u_int32_t dest_seqno, int orig_addr)
{
    RRCQ *rrcq;

    rrcq = (RRCQ *) aodv_socket_new_msg();
    rrcq->type = AODV_RREQ;
    rrcq->res1 = 0;
    rrcq->res2 = 0;
    rrcq->hcnt = 0;
    rrcq->rrcq_id = htonl(this_host.rreq_id++);

    rrcq->dest_seqno = htonl(dest_seqno);

    /* Immediately before a node originates a RREQ flood it must
       increment its sequence number... */
    seqno_incr(this_host.seqno);
    rrcq->orig_seqno = htonl(this_host.seqno);

    rrcq->j = 1;
    rrcq->r = 1;
    rrcq->g = 1;
    rrcq->d = 1;

    fprintf(stderr,"---------------This is the rrcq_create!--------------\n");
    return rrcq;
}
void NS_CLASS rrcq_send(struct in_addr dest_addr, u_int32_t dest_seqno, int ttl, u_int8_t flags)
{
    fprintf(stderr,"---------------This is the rrcq_send!--------------\n");
}

void NS_CLASS rrcq_forward(RRCQ * rreq, int size, int ttl)
{

}
void NS_CLASS rrcq_process(RRCQ * rreq, int rreqlen, struct in_addr ip_src, struct in_addr ip_dst, int ip_ttl, unsigned int ifindex)
{

}
void NS_CLASS rrcq_route_discovery(struct in_addr dest_addr, u_int8_t flags, struct ip_data *ipd)
{

}

void NS_CLASS rrcq_record_timeout(void *arg)
{
    fprintf(stderr,"---------------This is the rrcq_send!--------------\n");
}

void NS_CLASS rrcq_blacklist_timeout(void *arg)
{

}
void NS_CLASS rrcq_local_repair(rt_table_t * rt, struct in_addr src_addr, struct ip_data *ipd)
{

}


