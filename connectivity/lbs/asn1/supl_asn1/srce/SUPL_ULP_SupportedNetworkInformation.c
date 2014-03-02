/*
 * SUPL_ULP_SupportedNetworkInformation.c
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: david.gowers@stericsson.com for ST-Ericsson.
 * License terms: Redistribution and modifications are permitted subject to BSD license. 
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of ST-Ericsson nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ST-ERICSSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "Ver2-ULP-Components"
 *     found in "ULP_v2.0.0.asn"
 *     `asn1c -gen-PER -fcompound-names`
 */

#include <asn_internal.h>

#include "SUPL_ULP_SupportedNetworkInformation.h"

static asn_TYPE_member_t asn_MBR_SupportedNetworkInformation_1[] = {
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, wLAN),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "wLAN"
        },
    { ATF_POINTER, 2, offsetof(struct SupportedNetworkInformation, supportedWLANInfo),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_SupportedWLANInfo,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "supportedWLANInfo"
        },
    { ATF_POINTER, 1, offsetof(struct SupportedNetworkInformation, supportedWLANApsList),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_SupportedWLANApsList,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "supportedWLANApsList"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, gSM),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "gSM"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, wCDMA),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "wCDMA"
        },
    { ATF_POINTER, 1, offsetof(struct SupportedNetworkInformation, supportedWCDMAInfo),
        (ASN_TAG_CLASS_CONTEXT | (5 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_SupportedWCDMAInfo,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "supportedWCDMAInfo"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, cDMA),
        (ASN_TAG_CLASS_CONTEXT | (6 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "cDMA"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, hRDP),
        (ASN_TAG_CLASS_CONTEXT | (7 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "hRDP"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, uMB),
        (ASN_TAG_CLASS_CONTEXT | (8 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "uMB"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, lTE),
        (ASN_TAG_CLASS_CONTEXT | (9 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "lTE"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, wIMAX),
        (ASN_TAG_CLASS_CONTEXT | (10 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "wIMAX"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, historic),
        (ASN_TAG_CLASS_CONTEXT | (11 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "historic"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, nonServing),
        (ASN_TAG_CLASS_CONTEXT | (12 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "nonServing"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, uTRANGPSReferenceTime),
        (ASN_TAG_CLASS_CONTEXT | (13 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "uTRANGPSReferenceTime"
        },
    { ATF_NOFLAGS, 0, offsetof(struct SupportedNetworkInformation, uTRANGANSSReferenceTime),
        (ASN_TAG_CLASS_CONTEXT | (14 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_BOOLEAN,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "uTRANGANSSReferenceTime"
        },
};
static int asn_MAP_SupportedNetworkInformation_oms_1[] = { 1, 2, 5 };
static ber_tlv_tag_t asn_DEF_SupportedNetworkInformation_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SupportedNetworkInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* wLAN at 1331 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* supportedWLANInfo at 1332 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* supportedWLANApsList at 1333 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* gSM at 1334 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* wCDMA at 1335 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* supportedWCDMAInfo at 1336 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* cDMA at 1337 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* hRDP at 1338 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* uMB at 1339 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* lTE at 1340 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* wIMAX at 1341 */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* historic at 1342 */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* nonServing at 1343 */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* uTRANGPSReferenceTime at 1344 */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 } /* uTRANGANSSReferenceTime at 1345 */
};
static asn_SEQUENCE_specifics_t asn_SPC_SupportedNetworkInformation_specs_1 = {
    sizeof(struct SupportedNetworkInformation),
    offsetof(struct SupportedNetworkInformation, _asn_ctx),
    asn_MAP_SupportedNetworkInformation_tag2el_1,
    15,    /* Count of tags in the map */
    asn_MAP_SupportedNetworkInformation_oms_1,    /* Optional members */
    3, 0,    /* Root/Additions */
    14,    /* Start extensions */
    16    /* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SupportedNetworkInformation = {
    "SupportedNetworkInformation",
    "SupportedNetworkInformation",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
    0,    /* Use generic outmost tag fetcher */
    asn_DEF_SupportedNetworkInformation_tags_1,
    sizeof(asn_DEF_SupportedNetworkInformation_tags_1)
        /sizeof(asn_DEF_SupportedNetworkInformation_tags_1[0]), /* 1 */
    asn_DEF_SupportedNetworkInformation_tags_1,    /* Same as above */
    sizeof(asn_DEF_SupportedNetworkInformation_tags_1)
        /sizeof(asn_DEF_SupportedNetworkInformation_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_SupportedNetworkInformation_1,
    15,    /* Elements count */
    &asn_SPC_SupportedNetworkInformation_specs_1    /* Additional specs */
};
