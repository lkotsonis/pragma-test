#include <iostream>

#include <cstdint>




#include "packed.h"
struct Foo
{
    std::uint32_t a;
    std::uint32_t b;

    std::uint16_t c;

    std::uint32_t d;
    std::uint32_t e;
    std::uint32_t f;
    std::uint32_t g;
    std::uint32_t h;


} PACKED;
#include "endpacked.h"

struct Bar
{
    Foo foo[2];
} __attribute__((packed, aligned(2)));

static_assert(sizeof(Foo) == sizeof(std::uint32_t) *7 + sizeof( std::uint16_t));

int main()
{
    std::cout << "align:" << alignof(Foo) << std::endl;
    std::cout << "size:" << sizeof(Foo) << std::endl;

    if (sizeof(Foo) != 30)
    {
        std::cout << "WRONG!" << std::endl;
    }

}