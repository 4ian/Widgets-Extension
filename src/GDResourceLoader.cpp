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
