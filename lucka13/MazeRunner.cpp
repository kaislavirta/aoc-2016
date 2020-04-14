#include "MazeRunner.h"

#include <bitset>

MazeRunner::MazeRunner(std::int32_t favoriteNumber)
	: mFavoriteNumber(favoriteNumber)
{
	mCurrent.insert({1, 1});
}
	
std::size_t MazeRunner::countSteps(std::int32_t x, std::int32_t y) {
	std::size_t counter = 0;
	
	while(mCurrent.end() == mCurrent.find({x, y})) {
		iterate();
		
		++counter;
	}
	
	return counter;
}

std::size_t MazeRunner::fiftySteps() {
	for(std::size_t counter = 0; counter <= 50; ++counter) {
		iterate();
	}
	
	return mVisited.size();
}

bool MazeRunner::isWall(Coord pos) const {
	auto calc = pos.x * pos.x + 3 * pos.x + 2 * pos.x * pos.y + pos.y + pos.y * pos.y;
	calc += mFavoriteNumber;
	std::bitset<32> binary(calc);
	
	return binary.count() % 2 != 0;
}
	
void MazeRunner::iterate() {
	std::unordered_set<Coord> newPositions;
	
	for(const auto& pos : mCurrent) {
		if(pos.x > 0) {
			insertIfValidMove({ pos.x - 1, pos.y }, newPositions);
		}
		if(pos.y > 0) {
			insertIfValidMove({ pos.x, pos.y - 1 }, newPositions);
		}
		insertIfValidMove({ pos.x + 1, pos.y }, newPositions);
		insertIfValidMove({ pos.x, pos.y + 1 }, newPositions);
	}
	
	mVisited.insert(mCurrent.begin(), mCurrent.end());
	mCurrent.swap(newPositions);
}

void MazeRunner::insertIfValidMove(Coord pos, std::unordered_set<Coord>& coll) const {
	if(mCurrent.end() == mCurrent.find(pos) && mVisited.end() == mVisited.find(pos) && !isWall(pos)) {
		coll.insert(pos);
	}
}
