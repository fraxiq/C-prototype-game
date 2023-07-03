//#pragma once
//
//#include "Framework.h"
//#include "Platforms.h"
//#include <vector> 
//#include "Player.h"
//
//class PlatformGenerator
//{
//private:
//    std::vector<Platform> platforms;
//    int maxPlatforms = 5;
//    int platformsJumped;
//public:
//    Platform platform;
//    Player player;
//
//    void generatePlatforms(Player& player) {
//        if (platforms.size() < 1)
//        {
//            Platform newPlatform;
//            newPlatform.CreateSpritePlatform();
//            newPlatform.Draw(400, 550);
//            platforms.push_back(newPlatform);
//        }
//        else if (platforms.size() < maxPlatforms)
//        {
//            while (platforms.size() < maxPlatforms)
//            {
//                player.Update();
//                Platform newPlatform;
//                newPlatform.CreateSpritePlatform();
//                int py = player.GetY() + (rand() % -300);
//                int x = rand() % 600;
//                newPlatform.Draw(x, py);
//                int lastPlatformY = py;
//                platforms.push_back(newPlatform);
//            }
//        }
//        else if (player.GetY() > platforms.front().GetY() - 800)
//        {
//            platforms.erase(platforms.begin());
//        }
//
//        for (auto& platform : platforms) {
//            platform.Update();
//            platform.Draw(platform.GetX(), platform.GetY());
//        }
//    }
//};
