//
// Created by achateauricherd on 05/03/2020.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Obstacle.h"
#include "Ray.h"
#include "Light.h"

class MainWindow: public sf::RenderWindow
{
protected:
    const int TIME_STEP = 20; // in milliseconds

    sf::Clock globalClock;
    std::vector<std::unique_ptr<Obstacle>> obstacles;
    std::vector<std::unique_ptr<sf::Texture>> textures;
    std::vector<std::unique_ptr<Light>> lights;

public:
    explicit MainWindow(int width = 512, int height = 512, const std::string &title = "Raytracing demo");

    void init();
    void run();
    void handleEvents();
    void update();
    void render();
};



#endif //MAINWINDOW_H
