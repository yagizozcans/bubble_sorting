//
// Created by Yağız Özcan on 10.03.2024.
//
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

void Game::sRender() {
    s_window.clear();
    for (const auto& line : vertices) {
        s_window.draw(line.data(), line.size(), sf::Quads);
    }
    s_window.display();
}

void Game::sCheckLines() {
    if(i_sorting < (s_width / l_thickness))
    {
        float a = vertices[j_sorting][2].position.y;
        float b = vertices[j_sorting+1][2].position.y;
        if(a < b)
        {
            vertices[j_sorting][2].position.y = b;
            vertices[j_sorting+1][2].position.y = a;
            vertices[j_sorting][3].position.y = b;
            vertices[j_sorting+1][3].position.y = a;
        }
        j_sorting += 1;
        if(j_sorting > (s_width / l_thickness) - i_sorting - 2)
        {
            j_sorting = 0;
            i_sorting += 1;
        }
    }
}

void Game::run()
{
    std::cout<<"Enter screen height : ";
    cin>>s_height;
    std::cout<<"Enter screen width : ";
    cin>>s_width;
    std::cout<<"Enter line thickness : ";
    cin>>l_thickness;

    s_window.create(sf::VideoMode(s_width, s_height), "Zorting");

    srand(time(NULL));
    for(int i = 0; i < (s_width / l_thickness); i++)
    {
        float random_y =  std::rand() / (float)RAND_MAX * s_height;
        std::vector<sf::Vertex> line = {
                //White & Black
                /*sf::Vertex(sf::Vector2f(i * l_thickness, s_height), sf::Color((i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness))),
                sf::Vertex(sf::Vector2f(i * l_thickness + l_thickness, s_height), sf::Color((i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness))),
                sf::Vertex(sf::Vector2f(i * l_thickness + l_thickness, s_height - random_y), sf::Color((i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness))),
                sf::Vertex(sf::Vector2f(i * l_thickness, s_height - random_y), sf::Color((i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness),(i * 255) / (s_width / l_thickness)))*/
                sf::Vertex(sf::Vector2f(i * l_thickness, s_height), sf::Color(255,(i * 255) / (s_width / l_thickness),0,255)),
                sf::Vertex(sf::Vector2f(i * l_thickness + l_thickness, s_height), sf::Color(255,(i * 255) / (s_width / l_thickness),0,255)),
                sf::Vertex(sf::Vector2f(i * l_thickness + l_thickness, s_height - random_y), sf::Color(255,(i * 255) / (s_width / l_thickness),0,255)),
                sf::Vertex(sf::Vector2f(i * l_thickness, s_height - random_y), sf::Color(255,(i * 255) / (s_width / l_thickness),0,255))
        };
        vertices.push_back(line);
    }
    while (s_window.isOpen())
    {
        sf::Event event;
        while (s_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                s_window.close();
        }
        sCheckLines();
        sRender();
    }
}
