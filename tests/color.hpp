#ifndef COLOR_HPP
# define COLOR_HPP

#include <string>
#include <sstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"
#define NC "\033[0;m"
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

static std::string color(std::string str, const std::string color)
{
	str.insert(0, color);
	str.append(NC);
	return (str);
}

#endif