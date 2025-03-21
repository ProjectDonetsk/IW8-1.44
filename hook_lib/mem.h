#pragma once
#include "framework.h"
#include "globals.h"

#define INRANGE(x,a,b)  (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

#define is_valid_ptr(p) ((uintptr_t)(p) <= 0x7FFFFFFEFFFF && (uintptr_t)(p) >= 0x1000) 
#define is_bad_ptr(p)	(!is_valid_ptr(p))

#define ENCODE(l, r) l << 8 | r
#define SCAN(name, start, size, sig, extension, debase, log) name = Scanner(start, size, sig).extension; if (debase && name > var->baseModule) name -= var->baseModule; if (log) LOGS_ADDR(name);

namespace mem
{
    extern __int64 find_pattern(__int64 range_start, __int64 range_end, const char* pattern);

    template<typename T> inline auto readMemory(uintptr_t ptr) noexcept -> T {
        if (is_bad_ptr(ptr)) {
            //DEBUG_INFO("Attempted to read invalid memory at {:#x}", ptr);
            return {};
        }
        return *reinterpret_cast<T*>(ptr);
    }

    template<typename T> inline auto writeMemory(uintptr_t ptr, T value) noexcept -> T {
        if (is_bad_ptr(ptr)) {
            //DEBUG_INFO("Attempted to read invalid memory at {:#x}", ptr);
            return {};
        }
        return *reinterpret_cast<T*>(ptr) = value;
    }
}

class Scanner
{
private:
    std::ptrdiff_t _skip = 0x0;
    std::ptrdiff_t  searchStart = (std::ptrdiff_t)var->baseModule + _skip;
    std::ptrdiff_t addr = 0;

public:
    enum Opcodes {
        GET_ADDRESS = 0,
        OP_LEA = ENCODE(3, 7),
        OP_MOV = ENCODE(3, 7),
        OP_MOVCS = ENCODE(2, 7),
        OP_CALL = ENCODE(1, 5),
        OP_XOR = ENCODE(2, 2),
        OP_CMP = ENCODE(2, 6),
        OP_JZ = ENCODE(2, 6),
        OP_35 = ENCODE(3, 5)
    };

    explicit Scanner(std::ptrdiff_t address);
    explicit Scanner(__int64 skip, __int64 search_size, const char* pattern);
    uintptr_t find_ida_sig(const char* mod, const char* sig);

    Scanner at(std::ptrdiff_t offset);

    ~Scanner() {};

    auto getaddr() -> std::ptrdiff_t;
    auto validaddr() -> bool;

    auto resolve(Opcodes op) -> std::ptrdiff_t;

    template <typename T>
    Scanner add(T offset)
    {
        if (getaddr())
            addr += offset;
        return Scanner(addr);
    }

    template <typename T>
    Scanner sub(T offset)
    {
        if (getaddr())
            addr -= offset;
        return Scanner(addr);
    }

    template<typename T> T get_offset() {
        if (is_bad_ptr(getaddr()))
            return NULL;
        return *reinterpret_cast<T*>(getaddr());
    }
};
