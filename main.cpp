#include "shape/ellipse.h"
#include <windows.h>

#define HSCREEN 640
#define WSCREEN 480

sf::Image LoadImageFromResource(const std::string& name)
{
    HRSRC rsrcData = FindResource(NULL, name.c_str(), RT_RCDATA);
    if(!rsrcData)
        throw std::runtime_error("Failed to find resource.");

    DWORD rsrcDataSize = SizeofResource(NULL, rsrcData);
    if(rsrcDataSize <= 0)
        throw std::runtime_error("Size of resource is 0.");

    HGLOBAL grsrcData = LoadResource(NULL, rsrcData);
    if(!grsrcData)
        throw std::runtime_error("Failed to load resource.");

    LPVOID firstByte = LockResource(grsrcData);
    if(!firstByte)
        throw std::runtime_error("Failed to lock resource.");

    sf::Image image;
    if(!image.loadFromMemory(firstByte, rsrcDataSize))
        throw std::runtime_error("Failed to load image from memory.");

    return image;
}

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(HSCREEN, WSCREEN), "Tree of Life");
    sf::Event event;
    bool resolutionDragEllipse = false;
    sf::Image icon = LoadImageFromResource("tree");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // std::vector<CEllipse*> m_list;
    CEllipse ellipse(sf::Vector2f(100, 50));
    // m_list.push_back(&ellipse);

    while(window.isOpen()) {
        window.clear(sf::Color::Cyan);
        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if(event.mouseButton.button == sf::Mouse::Left)
                    resolutionDragEllipse = true;

            if(event.type == sf::Event::MouseButtonReleased)
                if(event.mouseButton.button == sf::Mouse::Left)
                    resolutionDragEllipse = false;

            if(event.type == sf::Event::MouseMoved) {

                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl;

                if(resolutionDragEllipse == true) {
                    float xE = event.mouseMove.x;
                    float yE = event.mouseMove.y;
                    if(ellipse.getGlobalBounds().contains(xE, yE) == true)
                        ellipse.SetPosition(xE, yE);
                }
            }
        }
        window.draw(ellipse);
        window.display();
    }
    return 0;
}
