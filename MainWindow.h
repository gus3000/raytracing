//
// Created by achateauricherd on 05/03/2020.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Utils.h"
#include "Obstacle.h"
#include "Ray.h"
#include "Light.h"

class MainWindow : public sf::RenderWindow {
private:
    std::deque<float> updates;

protected:
    const int TIME_STEP = 20; // in milliseconds

    sf::Clock globalClock;
    std::vector<std::unique_ptr<Obstacle>> obstacles;
    std::vector<std::unique_ptr<Light>> lights;

    //resources
    std::vector<std::unique_ptr<sf::Texture>> textures;
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;

public:
    explicit MainWindow(int width = 512, int height = 512, const std::string &title = "Raytracing demo");

    void init();

    void run();

    void handleEvents();

    void update();

    void render();

    int getFPS();
};


#endif //MAINWINDOW_H
