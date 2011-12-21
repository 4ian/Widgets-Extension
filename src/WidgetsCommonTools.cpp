#include "WidgetsCommonTools.h"

#include <string>
#include <vector>
#include "GDL/CommonTools.h"
#include "GDL/RuntimeScene.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics.hpp"

#if defined(GD_IDE_ONLY)
#include "wx/colour.h"
#endif


namespace WidgetsCommonTools
{
    sf::Color GetColorFromString(const std::string &colorString, const unsigned int alpha)
    {
        std::vector<std::string> colorSpec = SplitString<std::string>(colorString, ';');

        if(colorSpec.size() == 3)
        {
            return sf::Color(ToInt<std::string>(colorSpec[0]),
                             ToInt<std::string>(colorSpec[1]),
                             ToInt<std::string>(colorSpec[2]),
                             alpha);
        }
        else
        {
            return sf::Color(255, 255, 255, alpha);
        }
    }


    sf::Vector2f GetViewsPosition(const RuntimeScene &scene, const sf::Vector2f &position, const std::string &str)
    {
        if(position.x < 0 || position.y < 0 || position.x > scene.game->windowWidth || position.y > scene.game->windowHeight)
            return position;

        int camerasNumber = scene.GetLayer(str).GetCamerasNumber();
        sf::Vector2f newPos = position;

        int a = 0;
        for(a = 0; a < camerasNumber; a++)
        {
            sf::FloatRect rect(scene.GetLayer(str).GetCamera(a).GetSFMLView().GetViewport().Left * scene.game->windowWidth,
                               scene.GetLayer(str).GetCamera(a).GetSFMLView().GetViewport().Top * scene.game->windowHeight,
                               scene.GetLayer(str).GetCamera(a).GetSFMLView().GetViewport().Width * scene.game->windowWidth,
                               scene.GetLayer(str).GetCamera(a).GetSFMLView().GetViewport().Height * scene.game->windowHeight);

            if(rect.Contains(position))
            {
                newPos = scene.renderWindow->ConvertCoords(position.x, position.y, scene.GetLayer(str).GetCamera(a).GetSFMLView());
                break;
            }
        }

        return newPos;
    }

    sf::Vector2f GetViewsPosition(const RuntimeScene &scene, const sf::Vector2i &position, const std::string &str)
    {
        return GetViewsPosition(scene, sf::Vector2f(position.x, position.y), str);
    }


    #if defined(GD_IDE_ONLY)
    const wxColour& GetWxColourFromSfColor(const sf::Color &color)
    {
        return *(new wxColour(color.r, color.g, color.b, color.a));
    }

    const sf::Color& GetSfColorFromWxColour(const wxColour &color)
    {
        return *(new sf::Color(color.Red(), color.Green(), color.Blue(), color.Alpha()));
    }
    #endif
}
