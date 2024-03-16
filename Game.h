//
// Created by Yağız Özcan on 10.03.2024.
//

#ifndef COLOR_NODES_GAME_H
#define COLOR_NODES_GAME_H


class Game {
    void sRender();
    void sCheckLines();
    sf::RenderWindow s_window;
    std::vector<std::vector<sf::Vertex>> vertices;

    int i_sorting = 0;
    int j_sorting = 0;

    int s_height = 0;
    int s_width = 0;
    int l_thickness = 0;

public:
    void run();
};


#endif //COLOR_NODES_GAME_H
