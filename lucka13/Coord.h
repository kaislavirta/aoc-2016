#pragma once

#include <functional>

namespace {
	struct Coord {
		std::int32_t x;
		std::int32_t y;
		
		bool operator==(const Coord& other) const {
			return x == other.x && y == other.y;
		}
	};
}

namespace std
{
    template<> struct hash<Coord>
    {
        std::size_t operator()(Coord const& c) const noexcept
        {
            std::size_t h1 = std::hash<std::int32_t>{}(c.x);
            std::size_t h2 = std::hash<std::int32_t>{}(c.y);
            return h1 ^ (h2 << 1);
        }
    };
}
