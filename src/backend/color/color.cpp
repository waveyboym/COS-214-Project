#include "../includes/color.hpp"

std::string color::format_colour::make_colour(ColorCode cc)
{
    return "\033[" + std::to_string(cc) + "m";
}
