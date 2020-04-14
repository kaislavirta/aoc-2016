#pragma once

#include "Coord.h"

#include <cstdint>
#include <unordered_set>

class MazeRunner {
public:
	MazeRunner(std::int32_t favoriteNumber);
	~MazeRunner() = default;
	MazeRunner& operator=(const MazeRunner&) = delete;
	
	std::size_t countSteps(std::int32_t x, std::int32_t y);
	std::size_t fiftySteps();

private:
	bool isWall(Coord pos) const;
	void iterate();
	void insertIfValidMove(Coord pos, std::unordered_set<Coord>& coll) const;
	
private:
	std::int32_t mFavoriteNumber;
	std::unordered_set<Coord> mVisited;
	std::unordered_set<Coord> mCurrent;
};

