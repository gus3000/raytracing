//
// Created by achateauricherd on 05/03/2020.
//

#include<iostream>
#include <string>
#include <deque>
#include "MainWindow.h"
#include "Utils.h"
#include "Line.h"

using std::string;
using std::vector;

void MainWindow::init() {
    updates.clear();
    obstacles.clear();
    globalClock.restart();
    textures.clear();
    lights.clear();

    //fonts
    for (auto &fontName : {"arial"}) {
        auto *font = new sf::Font();
        if (!font->loadFromFile(utils::FONTS_DIRECTORY + fontName + "/" + fontName + ".ttf")) {
            this->close();
        }
        fonts.insert(std::pair<string, std::unique_ptr<sf::Font>>(fontName, font));
    }

    // borders
    const float width = getSize().x;
    const float height = getSize().y;
    obstacles.emplace_back(new Line({0, 0}, {width, 0}));
    obstacles.emplace_back(new Line({width, 0}, {width, height}));
    obstacles.emplace_back(new Line({width,height}, {0, height}));
    obstacles.emplace_back(new Line({0, height}, {0, 0}));

    for (int i = 0; i < 4; ++i) {
        Line line = utils::randomLine(0, 0, getSize().x, getSize().y);
        std::cout << line << std::endl;
        this->obstacles.emplace_back(new Line(line));
    }

    auto *light = new Light(sf::Vector2u{getSize().x / 2, getSize().y / 2});
    this->lights.emplace_back(light);
}

void MainWindow::run() {
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


void MainWindow::handleEvents() {
    sf::Event event{};
    while (pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            close();
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::R:
                    init();
                    break;
                default:
                    break;
            }
        } else if (event.type == sf::Event::MouseMoved) {
            lights[0]->setPosition(sf::Mouse::getPosition(*this));
        }
    }
}

// updates the physics
// function to call 50 times a second
void MainWindow::update() {
//    std::cout << "update" << std::endl;
}

// updates the graphics
void MainWindow::render() {
    handleEvents();

    clear(sf::Color::Black);
    //draw objects
    for (auto &obstacle : obstacles) {
        draw(*obstacle);
    }
    for (auto &light: lights) {
        light->cast(obstacles);
        draw(*light);
    }

//    sf::Vector2i mousePos = sf::Mouse::getPosition(*this);
//    Ray r(50, 50, mousePos.x, mousePos.y);
//    sf::Vector2f *impact = r.cast(*obstacles[0]);
//    Line l(r.getOrigin(), {static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)});
//    draw(l);
//    if (impact) {
//        sf::CircleShape circle(10);
//        utils::setPositionCentered(circle, *impact);
//        draw(circle);
//        delete impact;
//    }

    //show fps
    sf::Text fpsText(std::to_string(getFPS()), *fonts["arial"], 20);
    draw(fpsText);
    sf::Text helpText("Press r to reset", *fonts["arial"], 15);
    helpText.setPosition(0,getSize().y - helpText.getCharacterSize() - 2);
    draw(helpText);

    display();
}

MainWindow::MainWindow(int width, int height, const std::string &title)
        : sf::RenderWindow(sf::VideoMode(width, height), title) {
    init();
    run();
}


int MainWindow::getFPS() {
    updates.push_back(globalClock.getElapsedTime().asSeconds());

    float delta;
    while ((delta = updates.back() - updates.front()) > 1 && updates.size() >= 10) {
        updates.pop_front();
    }
//    std::cout << updates << std::endl;
    return static_cast<int>(updates.size() / delta);
}
