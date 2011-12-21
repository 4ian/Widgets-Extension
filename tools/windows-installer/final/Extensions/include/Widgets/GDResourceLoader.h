#ifndef GDRESOURCELOADER_H
#define GDRESOURCELOADER_H

#include "SFGUI/ResourceLoader.hpp"
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>

class RuntimeScene;

/**
GDResourceLoader allows SFGUI to load itself the resources (pictures and fonts) from Game Develop data file.
**/
class GDResourceLoader : public sfg::ResourceLoader
{
public:

    GDResourceLoader();
    virtual ~GDResourceLoader();


    virtual const sf::Font* LoadFont(const std::string& path);

    virtual const sf::Texture* LoadTexture(const std::string& path);

    virtual const std::string& GetIdentifier() const;

private:

};

#endif
