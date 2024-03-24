#include<iostream>
#include<vector>
#include<queue>
#include<random>
#include<ctime>

struct Cell {
	int x;
	int y;
	bool occupied;
};

struct Obstacle {
	int x;
	int y;
	int width;
	int height;

	Obstacle(int x, int y, int width, int height)
		: x(x), y(y), width(width), height(height) {}

	bool occupies(int cellX, int cellY) const {
		return cellX >= x && cellX < x + width &&
			   cellY >= y && cellY < y + height;
	}
};


void initializeOccupancyGrid(std::vector<Cell>& grid, int width, int height, const std::vector<Obstacle>& obstacles) {
	grid.clear();
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Cell cell;
			cell.x = x;
			cell.y = y;
			cell.occupied = false;

			for (const auto& obstacle : obstacles) {
				if (obstacle.occupies(x, y)) {
					cell.occupied = true;
					break;
				}
			}

			grid.push_back(cell);
		}
	}
}

bool isCellOccupied(const std::vector<Cell>& grid, int x, int y) {
	
}

std::vector<Cell> aStar(const std::vector<Cell>& grid, Cell start, Cell goal) {
	
}

void printPath(const std::vector<Cell>& grid, const std::vector<Cell>& path) {
	
}

int main() {

	initializeOccupancyGrid
}

