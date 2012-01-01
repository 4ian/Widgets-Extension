/*
Widgets Extension
Extension providing graphical widgets.

Copyright (c) 2011-2012 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#include "GDResourceLoader.h"

#include "GDL/RuntimeScene.h"
#include "GDL/RessourcesLoader.h"

GDResourceLoader::GDResourceLoader() : sfg::ResourceLoader()
{
}

GDResourceLoader::~GDResourceLoader()
{
}

const std::string& GDResourceLoader::GetIdentifier() const
{
    static const std::string id("gdres");
    return id;
}

const sf::Font* GDResourceLoader::LoadFont(const std::string& path)
{
    #if defined(GD_IDE_ONLY)
    sf::Font *newFont = new sf::Font();
    if(newFont->LoadFromFile(path))
        return newFont;
    else
        return new sf::Font(sf::Font::GetDefaultFont());
    #else
    if(path == "")
        return new sf::Font(sf::Font::GetDefaultFont());

    return new sf::Font(*(RessourcesLoader::GetInstance()->LoadFont(path)));
    #endif
}

const sf::Texture* GDResourceLoader::LoadTexture(const std::string& path)
{
    #if defined(GD_IDE_ONLY)
    sf::Texture *newTexture = new sf::Texture();
    newTexture->LoadFromFile(path);
    return newTexture;
    #else
    return new sf::Texture(*(RessourcesLoader::GetInstance()->LoadSFMLTexture(path)));
    #endif
}
