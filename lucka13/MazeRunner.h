#pragma once

#include <cstdint>
#include <cstddef>

struct Coord;

std::size_t countSteps(const Coord& endPos, std::int32_t favoriteNumber);
std::size_t fiftySteps(std::int32_t favoriteNumber);
