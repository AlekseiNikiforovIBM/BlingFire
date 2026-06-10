/**
 * Copyright (c) Microsoft Corporation. All rights reserved.
 * Licensed under the MIT License.
 */


#ifndef _BF_ENDIAN_H_
#define _BF_ENDIAN_H_

#include <stdint.h>


#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define BF_LITTLE_ENDIAN 1
#else /* __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ */
#define BF_BIG_ENDIAN 1
#endif /* __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ */
#else /* defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) */
#define BF_LITTLE_ENDIAN 1
#endif /* defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) */

#if defined(BF_LITTLE_ENDIAN)
#define from_le16(x) (x)
#define from_le32(x) (x)
#define from_le64(x) (x)
#else /* defined(BF_LITTLE_ENDIAN) */
#include <byteswap.h>
#define from_le16(x) bswap_16(x)
#define from_le32(x) bswap_32(x)
#define from_le64(x) bswap_64(x)
#endif /* defined(BF_LITTLE_ENDIAN) */

namespace bf_byteswap_helper
{
    template <typename T>
    inline T from_le(T value)
    {
        return value;
    }

    template <>
    inline uint16_t from_le<uint16_t>(uint16_t value)
    {
        return from_le16(value);
    }

    template <>
    inline int16_t from_le<int16_t>(int16_t value)
    {
        return from_le16(value);
    }

    template <>
    inline uint32_t from_le<uint32_t>(uint32_t value)
    {
        return from_le32(value);
    }

    template <>
    inline int32_t from_le<int32_t>(int32_t value)
    {
        return from_le32(value);
    }

    template <>
    inline uint64_t from_le<uint64_t>(uint64_t value)
    {
        return from_le64(value);
    }

    template <>
    inline int64_t from_le<int64_t>(int64_t value)
    {
        return from_le64(value);
    }
};

#endif
