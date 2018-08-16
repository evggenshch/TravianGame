//
// Created by evggenshch on 30.07.18.
//

#include "../include/trvSystemEnemyAI.h"

void trvSystemEnemyAI::update(trvIOContainerWorld * gameWorld) {
    std::for_each(gameWorld->gameObjects.equal_range("CultistEnemy").first, gameWorld->gameObjects.equal_range("CultistEnemy").second,
    [] (std::pair <std::string, std::shared_ptr <trvEntity> > curObj) {



    });
}