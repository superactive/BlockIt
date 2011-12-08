#ifndef BIITEM_H
#define BIITEM_H

#include <string>

class BIItem
{
private:
    std::string exePath;
    std::string iconPath;
    std::string name;

public:
    BIItem();
    BIItem(std::string exe, std::string icon, std::string name);
    std::string getExePath();
    std::string getIconPath();
    std::string getName();
    std::string toString();
};

#endif // BIITEM_H
