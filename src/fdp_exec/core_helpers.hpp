#pragma once

#include "core.hpp"
#include "endian.hpp"
#include "log.hpp"

// uint helpers
template<typename T, T(*read)(const void*)>
std::optional<T> read_mem(ICore& core, uint64_t ptr)
{
    T value;
    const auto ok = core.read_mem(&value, ptr, sizeof value);
    if(!ok)
        FAIL(std::nullopt, "unable to read %zd bits at 0x%llx", 8 * sizeof value, ptr);

    return read(&value);
}

namespace core
{
    static inline auto read_le16(ICore& core, uint64_t ptr) { return read_mem<uint16_t, &::read_le16>(core, ptr); }
    static inline auto read_le32(ICore& core, uint64_t ptr) { return read_mem<uint32_t, &::read_le32>(core, ptr); }
    static inline auto read_le64(ICore& core, uint64_t ptr) { return read_mem<uint64_t, &::read_le64>(core, ptr); }
    static inline auto read_be16(ICore& core, uint64_t ptr) { return read_mem<uint16_t, &::read_be16>(core, ptr); }
    static inline auto read_be32(ICore& core, uint64_t ptr) { return read_mem<uint32_t, &::read_be32>(core, ptr); }
    static inline auto read_be64(ICore& core, uint64_t ptr) { return read_mem<uint64_t, &::read_be64>(core, ptr); }
    static inline auto read_ptr (ICore& core, uint64_t ptr) { return read_mem<uint64_t, is_little_endian ? &::read_le64 : &::read_be64>(core, ptr); }
}
