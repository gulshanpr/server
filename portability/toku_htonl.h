/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */
// vim: ft=cpp:expandtab:ts=8:sw=4:softtabstop=4:
#ident "$Id$"
#ident "Copyright (c) 2007-2012 Tokutek Inc.  All rights reserved."

#ifndef _TOKU_HTONL_H
#define _TOKU_HTONL_H

#if !__linux__ && !__FreeBSD__ && !__sun__
//#error
#endif

// TODO: This byte order stuff should all be in once place (ie: portability layer, not toku_include)
#include <toku_htod.h>
#include <arpa/inet.h>

static inline uint32_t toku_htonl(uint32_t i) {
    return htonl(i);
}

static inline uint32_t toku_ntohl(uint32_t i) {
    return ntohl(i);
}

static inline uint64_t toku_htonl64(uint64_t i) {
#if HOST_BYTE_ORDER != NETWORK_BYTE_ORDER
    uint64_t a = ((uint64_t) htonl(i & 0xFFFFFFFF)) << 32;
    uint64_t b = htonl(i >> 32);
    return a | b;
#else
    return i;
#endif
}

static inline uint64_t toku_ntohl64(uint64_t i) {
#if HOST_BYTE_ORDER != NETWORK_BYTE_ORDER
    uint64_t a = ((uint64_t) ntohl(i & 0xFFFFFFFF)) << 32;
    uint64_t b = ntohl(i >> 32);
    return a | b;
#else
    return i;
#endif
}

#endif
