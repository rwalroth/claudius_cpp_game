#include "game_state.h"

GameState::GameState(Army claudius_, Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_):
    claudius {claudius_}, 
    currentPhase {Phase::starting},
    choice{},
    world{british_, danube_, goths_, severus_, defectionSize_}
    {
        currentRegion = world.beginning;
}

void GameState::print_stats() {
    std::cout << claudius;
    std::cout << std::endl << "Severus Army: " << this->world.italy->get_army_size() << std::endl;
}

void GameState::move_location() {
    switch (choice) {
        case 'Z': {
            claudius.location = eBeginning;
            break;
        }
        case 'B': {
            claudius.location = eBritain;
            this->currentRegion = world.britain;
            break;
        }
        case 'I': {
            claudius.location = eItaly;
            this->currentRegion = world.italy;
            break;
        }
        case 'G': {
            claudius.location = eGaul;
            this->currentRegion = world.gaul;
            break;
        }
        case 'E': {
            claudius.location = eIberia;
            this->currentRegion = world.iberia;
            break;
        }
        case 'D': {
            claudius.location = eDanube;
            this->currentRegion = world.danube;
            break;
        }
        case 'Q':{
            std::cout << "So that's it? Maybe you were not meant to be" << std::endl;
            std::cout << "the Augustus after all..." << std::endl;
        }
        default:
            break;
    }
}
