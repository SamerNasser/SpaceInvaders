#include <iostream>
#include "AFactory.h"
#include "../SDL/SDLFactory.h"
#include "Game.h"

int main(int argc, char* args[]) {
    NONSDL::AFactory* afact = new SDL::SDLFactory(); // afact moet een pointer zijn, want als dit niet zo zou zijn en we zeggen gewoon:
    // Afactory afact
    // afact = SDLFactory
    // dan zouden in afact enkel de velden van SDLFactory
    // zitten die ook in AFactory zitten. Er zou dus een deel missen en het
    // hele principe van polymorfisme gaat verloren. Ook zouden we dan op de stack
    // bezig zijn en dat is niet de bedoeling want we willen exact weten waar
    // afact zich bevindt (in de heap, dus).
    NONSDL::Game* G = NONSDL::Game::gameInstance(afact);
    G->run();
    delete G;
    delete afact;
    return 0;
}


