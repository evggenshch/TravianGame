//
// Created by evggenshch on 30.07.18.
//

#include "../include/trvSystemEnemyAI.h"
#include "../include/trvSystemEntityCollision.h"

void trvSystemEnemyAI::update(trvIOContainerWorld * gameWorld) {

    int aimY = gameWorld->gameObjects.find("MainBuilding")->second->getPos().getY();
    int aimX = gameWorld->gameObjects.find("MainBuilding")->second->getPos().getX();

    std::for_each(gameWorld->gameObjects.equal_range("CultistEnemy").first, gameWorld->gameObjects.equal_range("CultistEnemy").second,
    [aimX, aimY, gameWorld] (std::pair <std::string, std::shared_ptr <trvEntity> > curEnemy) {
       int dY = 0, dX = 0;
       bool correctMove = true;
       if(curEnemy.second->getPos().getY() < aimY) {
           dY = 1;
           curEnemy.second->setPos(trvComponentLocation(curEnemy.second->getPos().getX(), curEnemy.second->getPos().getY() + dY));
           std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), [curEnemy, &correctMove, gameWorld]
               (std::pair <std::string, std::shared_ptr <trvEntity> > curObj) {
               if(trvSystemEntityCollision::isIntersect(curEnemy.second, curObj.second) && (curEnemy.second != curObj.second)) {
                 correctMove = false;
               }
           });
           if(!correctMove) {
             curEnemy.second->setPos(trvComponentLocation(curEnemy.second->getPos().getX(), curEnemy.second->getPos().getY() - dY));
           }
       }
       correctMove = true;
       if(curEnemy.second->getPos().getX() < aimX) {
           dX = 1;
         curEnemy.second->setPos(trvComponentLocation(curEnemy.second->getPos().getX() + dX, curEnemy.second->getPos().getY()));
         std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), [curEnemy, &correctMove, gameWorld]
             (std::pair <std::string, std::shared_ptr <trvEntity> > curObj) {
           if(trvSystemEntityCollision::isIntersect(curEnemy.second, curObj.second) && (curEnemy.second != curObj.second)) {
             correctMove = false;
           }
         });
         if(!correctMove) {
           curEnemy.second->setPos(trvComponentLocation(curEnemy.second->getPos().getX() - dX, curEnemy.second->getPos().getY()));
         }
       }
    });
}