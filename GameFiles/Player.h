#pragma once
#include "Framework.h"

class Player
{
private:
	float gravity = 0.2f;
	int x;
	int y;
	int width;
	int height;
	int playerSize = 60;
	float velocity= -30;
	bool jumpFlag;
	int speed = 4;
	int points;
	Sprite* sprite;
	bool isalive;
public:
	Player() {
	}
	~Player() {
		destroySprite(sprite);
	}
	void CreateSpritePlayer() {
		sprite = createSprite("data/blue-lik-right@2x.png");
		getSpriteSize(sprite, width, height);
	}
	int GetX()const { return x; }
	int GetY()const { return y; }
	int GetSize()const { return playerSize; }
	int GetPoints()const { return points; }
	int GetVelocity()const { return velocity; }
	int GetHeight()const { return height; }
	int GetWidth()const { return width; }
	void SetX(int x1) {
		x = x1;
	}
	void SetY(int y1) {
		y = y1;
	}
	void SetVelocity(int v1) {
		velocity = v1;
	}
	void MoveLeft() {
		x -= speed;
	}
	void MoveRight() {
		x += speed;
	}
	void playergravity(int screenheight) {
		jumpFlag = true;
		velocity += gravity;
		y += static_cast<int>(velocity);
		if (y> screenheight -height)
		{
			jumpFlag = false;
			velocity = -10;
		}
	}
	void Jump() {
		jumpFlag = false;
		velocity -= 25;
	}
	void die() {
		isalive = false;
	}
	int pointCounter(){
		if (points<x)
		{
			points = x;
		}
		return points;
	}
	void SetPosition() {
		setSpriteSize(sprite, width, height);
		drawSprite(sprite, x, y);
	}

	void screenWrap(int screenWidith) {
		if (x < -playerSize) {
			x = screenWidith;
		}
		else if (x > screenWidith) {
			x = -playerSize;
		}
	}
	void Draw() {
		drawSprite(sprite, x, y);
	}
};

