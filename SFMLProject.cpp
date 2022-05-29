#include <SFML/Graphics.hpp>
#include "windows.h"
#include<iostream>
#include<vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");//создаем окно
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::Yellow);

    int a = 130;
    int b = 0;



    std::vector<sf::RectangleShape> vec(6);
    sf::RectangleShape prep;
    prep.setSize(sf::Vector2f(20, 700));
    prep.setFillColor(sf::Color::White);
    rectangle.setPosition(5, 5);
    int i = 0;

    sf::RectangleShape itog;
    itog.setSize(sf::Vector2f(75, 200));
    itog.setFillColor(sf::Color::Red);
    itog.setPosition(825, 0);
    std::vector<std::pair<int, int>> coors(6);
    std::pair<int, int> coor;
    int srav = 0;
    while (window.isOpen()) {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(itog);
        while (i < 6) {
            prep.setPosition(a, b);
            coor.first = a;
            coor.second = b;
            coors[i] = coor;
            vec[i] = prep;
            if (i == 5) {
                vec[i].setSize(sf::Vector2f(200, 700));
                vec[i].setFillColor(sf::Color::Black);
                vec[i].setOutlineThickness(20);
                vec[i].setOutlineColor(sf::Color::White);
            }
            a += 135;
            b = 200;
            if (i % 2 != 0) {
                b = 0;
            }
            ++i;
        }
        for (int j = 0;j < 6;++j) {
            window.draw(vec[j]);
        }
        rectangle.setPosition(5, 5);
        window.draw(rectangle);
        window.display();
        float x = sf::Mouse::getPosition(window).x;
        float y = sf::Mouse::getPosition(window).y;
        std::cout << x << "." << y << std::endl;
        if (x > 55 || x < 5 || y > 55 || y < 5) {
            continue;
        }
        while (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
            float x = sf::Mouse::getPosition(window).x;
            float y = sf::Mouse::getPosition(window).y;
            rectangle.setPosition(x - 25, y - 25);
            if (x - 20 >= 800) {
                std::cout << "WIN";
                return 0;
            }
            for (int j = 0; j < 6; ++j) {
                if (x + 25 > coors[j].first && x - 25 < coors[j].first + 20) {
                    if (j % 2 == 0 && y <= 723) {
                        std::cout << "LOSE";
                        return 0;
                    }
                    if (y >= 176 && j % 2 != 0) {
                        std::cout << "LOSE";
                        return 0;
                    }
                }
            }
            window.draw(rectangle);
            window.display();
            window.clear();
            window.draw(itog);
            for (int j = 0;j < 6;++j) {
                window.draw(vec[j]);
            }
        }
    }
    return 0;
}
