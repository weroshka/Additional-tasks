#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <zombie.hpp>
#include<circle.hpp>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std::chrono_literals;

int main()
{
    float t = 0;
    int score = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 429), "Zombie VS Plants");

    // Подгрузка фонового изображения
    sf::Texture texture;
    if (!texture.loadFromFile("img/day_level.png"))
    {
        std::cout << "ERROR when loading day_level.png" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

    // Подгрузка шрифта и создание отображения счета
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);

    // Добавление иконки
    sf::Image icon;
    if (!icon.loadFromFile("img/icon32.ico"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    veroshka::Zombie* zombie = nullptr;
    veroshka::Circle* circle = nullptr;

    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
      
            sf::Vector2i mp = sf::Mouse::getPosition(window);


            if (zombie != nullptr)
                delete zombie;

            float sx = mp.x;
            float sy = mp.y;

            zombie = new veroshka::Zombie(sx, sy, 20);

            if (!zombie->Setup())
            {
                delete zombie;
                window.close();
                return -1;
            }

            t = 0;
        }

        // Движение зомби
        if (zombie != nullptr)
        {
            zombie->Move();

           
        }
    

        // Вывод на экрна
        window.clear();

        // Вывод фона
        window.draw(back);

        // Вывод счета
        text.setString(std::string("Score ") + std::to_string(score));
        window.draw(text);

        if (zombie != nullptr)
            window.draw(*zombie->Get());

        /*if (circle != nullptr)
            window.draw(*circle->Get());*/

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(40ms);
        t += 0.04;
    }

    if (zombie != nullptr)
        delete zombie;

    if (circle != nullptr)
        delete circle;
    
    return 0;

}
