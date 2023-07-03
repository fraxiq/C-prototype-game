

#include "Framework.h"
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "Platforms.h"
#include "PlatformGenerator.h"
#include "Enemy.h"

/* Test Framework realization */
class MyFramework : public Framework {
private:
	Player player;
	Bullet bullet;
	Platform platform;
	Enemy enemy;
	bool moveLeftFlag = false;
	bool moveRightFlag = false;
	int mouseX = 0;
	int mouseY = 0;
	int screenwidth;
	int screenheight;

public:
	MyFramework() : Framework() {}
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		std::cout << "Enter game window width: ";
		std::cin >> width;
		std::cout << "Enter game window height: ";
		std::cin >> height;
		fullscreen = false;
		screenheight = height;
		screenwidth= width;
	}

	virtual bool Init() {
		platform.CreateSpritePlatform();
		player.CreateSpritePlayer();
		bullet.CreaterSpriteBullet();
		enemy.CreateSpriteEnemy();
		player.SetX(screenwidth/2);
		player.SetY(screenheight/2);
		return true;
	}

	virtual void Close() {
	}

	virtual bool Tick() {
		player.SetPosition();				
		if (moveLeftFlag) {
			player.MoveLeft();
		}
		else if (moveRightFlag) {
			player.MoveRight();
		}
		player.screenWrap(screenwidth);
		player.pointCounter();	
		player.playergravity(screenheight);
		platform.MoveAndReset(player,screenheight,screenwidth);
		platform.generatePlatforms(screenheight,screenwidth, enemy);
		platform.CollisionDetect(player);
		//draw
		drawTestBackground();
		player.Draw();
		enemy.Draw();
		platform.Draw();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		mouseX = x;
		mouseY = y;
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
		if (k == FRKey::LEFT) {
			moveLeftFlag = true;
		}
		else if (k == FRKey::RIGHT) {
			moveRightFlag = true;
		}
	}

	virtual void onKeyReleased(FRKey k) {
		if (k == FRKey::LEFT) {
			moveLeftFlag = false;
		}
		else if (k == FRKey::RIGHT) {
			moveRightFlag = false;
		}
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump Game (Dragons Lake task)";
	}
};

int main(int argc, char* argv[])
{
	return run(new MyFramework);
}
