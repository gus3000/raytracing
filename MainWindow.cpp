//
// Created by achateauricherd on 05/03/2020.
//

#include <iostream>
#include <string>
#include "MainWindow.h"
#include "Utils.h"
#include "Line.h"

using std::string;
using std::vector;

void MainWindow::run()
{
    int lastUpdate = globalClock.getElapsedTime().asMilliseconds();
    int buf;

    // run the program as long as the window is open
    while (isOpen()) {
        while ((buf = (globalClock.getElapsedTime().asMilliseconds() - lastUpdate) >= TIME_STEP)) {
            lastUpdate += TIME_STEP;
            update();
        }
        render();
    }
}

void MainWindow::handleEvents()
{
    sf::Event event{};
    while (pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            close();
        else if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::R:
                    init();
                    break;
                default:
                    break;
            }
        }
        else if(event.type == sf::Event::MouseMoved)
        {
            lights[0]->setPosition(sf::Mouse::getPosition(*this));
        }
    }
}

// updates the physics
// function to call 50 times a second
void MainWindow::update()
{
//    std::cout << "update" << std::endl;
}

// updates the graphics
void MainWindow::render()
{
    handleEvents();

    clear(sf::Color::Black);
    //do stuff here
    for (auto &obstacle : obstacles) {
        draw(*obstacle);
    }
    for(auto &light: lights){
        draw(*light);
    }

    display();
}
MainWindow::MainWindow(int width, int height, const std::string &title)
    : sf::RenderWindow(sf::VideoMode(width, height), title)
{
    init();
    run();
}
void MainWindow::init()
{
    obstacles.clear();
    globalClock.restart();
    textures.clear();
    lights.clear();

    Line line = utils::randomLine(0, 0, getSize().x, getSize().y);
    std::cout << line << std::endl;
    this->obstacles.emplace_back(new Line(line));

    auto* light = new Light(getSize()/2);
    this->lights.emplace_back(light);
}
