#pragma once
#include "Framework.h"
#include "Player.h"
#include <vector>
class Enemy
{
private:
	int x;
	int y;
	Sprite* sprite;
	int width;
	int height;
	std::vector<Enemy> enemies;
	int maxEnemies = 2;
public:
	void CreateSpriteEnemy() {
		sprite = createSprite("data/Enemy.png");
		getSpriteSize(sprite, width, height);
	}
    int GetX()const { return x; }
	int GetY()const { return y; }
	void die() {
		destroySprite(sprite);
	}
    void spawnOnPlatform(int platx, int platy) {
        int spawnprob = rand() % 10;
        if (spawnprob>3)
        {
            srand(getTickCount());
            for (size_t i = 0; i < maxEnemies; i++)
            {
                CreateSpriteEnemy();
                Enemy enem;
                enem.x = platx;
                enem.y = platy - 10;
                enemies.push_back(enem);
            }
          
        }      
    }
    void playerCollision(Player& player) {
        for (size_t i = 0; i < maxEnemies; i++)
        {
            if (player.GetX() + player.GetWidth() > enemies[i].x
                && player.GetX() < enemies[i].x + width
                && player.GetY() + player.GetHeight() > enemies[i].y
                && player.GetY() < enemies[i].y + height)
            {
                // check if player is above enemy
                if (player.GetY() + player.GetHeight() <= enemies[i].y + height / 2) {
                    // player collides with enemy's head, so enemy dies
                    enemies[i].die();
                }
                else {
                    // player collides with enemy from the sides or from below, so player dies
                    player.die();
                }
            }
        }
    }
    void Draw() {
        for (size_t i = 0; i < maxEnemies; i++) {
            drawSprite(sprite, enemies[i].GetX(), enemies[i].GetY());
        }
    }
};

