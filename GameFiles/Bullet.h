#pragma once
#include "Framework.h"
#include <cmath>

class Bullet
{
private:
	int x;
	int y;
	Sprite* bulletSprite;
	int velocityX;
	int velocityY;
	int speed;
public:
	void CreaterSpriteBullet() {
		bulletSprite = createSprite("data/snow@2x.png");
		getSpriteSize(bulletSprite, x, y);
	}
	int GetX()const { return x; }
	int GetY()const { return y; }
	void SetX(int x1) {
		x = x1;
	}
	void SetY(int y1) {
		y = y1;
	}
	void Reset(int startX, int startY, int targetX, int targetY) {
		x = startX;
		y = startY;
		int dx = targetX - startX;
		int dy = targetY - startY;
		int distance = sqrt(dx * dx + dy * dy);
		velocityX = dx / distance * speed;
		velocityY = dy / distance * speed;
	}
	void Update(int deltaTime) {
		x += velocityX * deltaTime;
		y += velocityY * deltaTime;
	}
	void MoveBullet(int x1, int y1) {
		
	}
	void shoot() {
		drawSprite(bulletSprite, x, y);
	}
};

