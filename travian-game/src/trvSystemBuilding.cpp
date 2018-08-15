//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvSystemBuilding.h"

/**  In such systems copies of realtime game cycles?

 No. Keep going, just check the flags and use corresponding system.

 Use enum for game mode instead. Send key value in system


**/

void trvSystemBuilding::update(trvIOContainerWorld * gameWorld, int inputKey) {
    inputKey = wgetch(gameWorld->gameUI.getInfoWidget()->getWidgetWindow());
    switch(inputKey) {
      case 'w': {
        gameWorld->gameUI.getInfoWidget()->changeSelectedOption(-1);
        break;
      }
      case 's': {
        gameWorld->gameUI.getInfoWidget()->changeSelectedOption(1);
        break;
      }
      case 'b': {
        gameWorld->gameUI.getInfoWidget()->buildSelectedOption(gameWorld);
        break;
      }
      case 'q': {
        gameWorld->setGameMode(GAME_MODES::CAMERA_MODE);
        break;
      }
      default : { break; }
    }
}