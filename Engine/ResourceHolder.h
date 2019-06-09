//
// Created by Samuel Gallay on 2019-06-02.
//

#ifndef GAMEENGINE_RESOURCEHOLDER_H
#define GAMEENGINE_RESOURCEHOLDER_H

#include <string>
#include <map>
#include <memory>
#include <iostream>

#include <SFML/Graphics.hpp>

template<typename T>
class ResourceHolder {
public:
    const T& get(std::string key) {
        auto it = list.find(key);
        if (it != list.end()) {
            std::cout << "Access resource : " << key << std::endl;
            return it->second;
        } else {
            T temp;
            temp.loadFromFile(key);
            if (!temp.loadFromFile(key))
                std::cout << "Failed to load resource : " << key << std::endl;
            else
                std::cout << "Load resource : " << key << std::endl;
            list.insert(std::make_pair(key, temp));
            return list[key];
        }
    }

private:
    std::map<std::string, T> list;
};

struct Holder{
    ResourceHolder<sf::Image> image;
    ResourceHolder<sf::Texture> texture;
    ResourceHolder<sf::Font> font;
    ResourceHolder<sf::Shader> shader;
    //ResourceHolder<sf::SoundBuffer> soundBuffer;
};

#endif //GAMEENGINE_RESOURCEHOLDER_H
