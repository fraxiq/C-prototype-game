#pragma once
#include "Framework.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Platform
{
private:
	int x;
	int y;
	Sprite* sprite;
	int width;
	int height;
	std::vector<Platform> platforms;
	int maxPlatforms = 5;
	int platformsJumped;
public:
	
	Platform() {

	};
	void CreateSpritePlatform() {
		sprite = createSprite("data/doodle-jump-platform.png");
		getSpriteSize(sprite, width, height); // Fixed
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int x1) {
		x = x1;
	}
	void SetY(int y1) {
		y = y1;
	}

	void generatePlatforms(int screenheight, int screenwidth,Enemy& enemy) {
		srand(getTickCount());
		for (size_t i = 0; i < maxPlatforms; i++)
		{
			CreateSpritePlatform();
			Platform plat;
			plat.x = rand() % screenwidth - width / 2;
			plat.y = screenheight;
			platforms.push_back(plat);
			enemy.spawnOnPlatform(plat.x,plat.y);
		}

	}

	bool CollisionDetect(Player& player) {
		for (size_t i = 0; i < maxPlatforms; i++)
		{
			if (player.GetVelocity() > 0
				&& player.GetX() + player.GetWidth() > platforms[i].x
				&& player.GetX() < platforms[i].x + width
				&& player.GetY() + player.GetHeight() > platforms[i].y
				&& player.GetY() + player.GetHeight() < platforms[i].y + 10)
			{
				player.Jump();
				return true;
			}
		}
		return false;
	}
	void Draw() {
		for (size_t i = 0; i < maxPlatforms; i++) {
			drawSprite(sprite, platforms[i].GetX(), platforms[i].GetY());
		}
	}
	void MoveAndReset(Player& player, int screenheight, int screenwidth)
	{
		static const int limit = screenheight / 3;
		if (player.GetY() < limit)
		{
			for (int i = 0; i < maxPlatforms; ++i)
			{
				player.SetY(limit);
				platforms[i].y -= static_cast<int>(player.GetVelocity());
				if (platforms[i].y > screenheight + 10)
				{
					platforms[i].y = rand() % screenheight / 3 + 100;
					platforms[i].x = rand() % screenwidth;
				}
			}
		}
	}
};
