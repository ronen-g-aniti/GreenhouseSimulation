#include <vector>
#include <iostream>

struct Box {
	float x, y, z;
	float hx, hy, hz;
	Box(float x, float y, float z, float hx, float hy, float hz) :
		x(x), y(y), z(z), hx(hx), hy(hy), hz(hz) {}
};


void addBox(std::vector<Box>& obstacleList, float x, float y, float z, float hx, float hy, float hz) {
	obstacleList.emplace_back(x, y, z, hx, hy, hz);
}

