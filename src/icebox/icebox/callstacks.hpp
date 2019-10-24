#pragma once

#include "types.hpp"

namespace core { struct Core; }

namespace callstacks
{
    struct context_t
    {
        uint64_t ip;    // instruction pointer
        uint64_t sp;    // stack pointer
        uint64_t bp;    // base pointer
        uint64_t cs;    // code segment
        flags_e  flags; // process flags
    };

    struct caller_t
    {
        uint64_t addr;
    };

    size_t  read        (core::Core& core, caller_t* callers, size_t num_callers, proc_t proc);
    size_t  read_from   (core::Core& core, caller_t* callers, size_t num_callers, proc_t proc, const context_t& where);
} // namespace callstacks
