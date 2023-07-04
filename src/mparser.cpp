#include "mparser.h"

bool MParser::text2doubleNumber(std::string str, double& number)
{
    if (str.length() == 0)
        return false;
    number = std::stod(str);
    return true;
}
