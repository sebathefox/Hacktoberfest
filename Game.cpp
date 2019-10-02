#include "Game.h"
#include "memory/StackAllocator.h"
#include "core/ResourceManager.h"
#include "systems/events/EventDispatcher.h"
#include "systems/events/Event.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Cb(std::string message) {
    std::cout << message << std::endl;
}

game::Game::Game() {
    systems::events::EventDispatcher dispatcher;
    dispatcher.RegisterEvent(new systems::events::Event<std::string>("KekEvent", &Cb));

    dispatcher.DispatchEvent("KekEvent", "Lol");

    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 800), "{NAME}");

//    memory::StackAllocator sa(1024);
//
//    for (int i = 0; i < 24; ++i) {
//        int* tal = (int*)sa.Alloc(sizeof(int));
//
//        *tal = 5 + i;
//
//        std::cout << *tal << std::endl;
//    }
//
//    long* tal = (long*)sa.Alloc(sizeof(long));
//
//    *tal = 54020592;
//
//    std::cout << *tal << std::endl;



}

game::Game::~Game() {

}

int game::Game::Run() {

    core::ResourceManager rm;

    rm.AddResource(ResourceType::SPRITE, "./assets/player.png");

    sf::Sprite spr(rm.GetResource<sf::Texture>("img"));

    spr.setPosition(50, 50);

    while(m_window->isOpen()) {

        sf::Event event;

        while(m_window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                m_window->close();
        }

        m_window->clear();

        m_window->draw(spr);

        m_window->display();
    }

    return 0;
}

void game::Game::StartSystems() {

}

void game::Game::LoadAssets() {

}
