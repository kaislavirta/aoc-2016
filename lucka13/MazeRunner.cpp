#include "MazeRunner.h"

#include "Coord.h"

#include <unordered_set>
#include <bitset>

namespace {
	class MazeRunner {
	public:
		MazeRunner(std::int32_t favoriteNumber)
			: mFavoriteNumber(favoriteNumber)
		{
			mCurrent.insert({1, 1});
		}
		~MazeRunner() = default;
		MazeRunner& operator=(const MazeRunner&) = delete;
		
		std::size_t countSteps(const Coord& endPos) {
			std::size_t counter = 0;
			
			while(mCurrent.end() == mCurrent.find(endPos)) {
				iterate();
				
				++counter;
			}
			
			return counter;
		}

		std::size_t fiftySteps() {
			for(std::size_t counter = 0; counter <= 50; ++counter) {
				iterate();
			}
			
			return mVisited.size();
		}

	private:
		bool isWall(Coord pos) const {
			auto calc = pos.x * pos.x + 3 * pos.x + 2 * pos.x * pos.y + pos.y + pos.y * pos.y;
			calc += mFavoriteNumber;
			std::bitset<32> binary(calc);
			
			return binary.count() % 2 != 0;
		}

		void iterate() {
			std::unordered_set<Coord> newPositions;
			auto insertIfValidMove = [this, &newPositions](Coord pos) {
				if(mCurrent.end() == mCurrent.find(pos) && mVisited.end() == mVisited.find(pos) && !isWall(pos)) {
					newPositions.insert(pos);
				}
			};

			for(const auto& pos : mCurrent) {
				if(pos.x > 0) {
					insertIfValidMove({ pos.x - 1, pos.y });
				}
				if(pos.y > 0) {
					insertIfValidMove({ pos.x, pos.y - 1 });
				}
				insertIfValidMove({ pos.x + 1, pos.y });
				insertIfValidMove({ pos.x, pos.y + 1 });
			}
			
			mVisited.insert(mCurrent.begin(), mCurrent.end());
			mCurrent.swap(newPositions);
		}

	private:
		std::int32_t mFavoriteNumber;
		std::unordered_set<Coord> mVisited;
		std::unordered_set<Coord> mCurrent;
	};
} // namesspace

std::size_t countSteps(const Coord& endPos, std::int32_t favoriteNumber) {
	MazeRunner mr(1362);
	return mr.countSteps(endPos);
}

std::size_t fiftySteps(std::int32_t favoriteNumber) {
	MazeRunner mr(1362);
	return mr.fiftySteps();
}
