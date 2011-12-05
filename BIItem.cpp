#include "BIItem.h"

BIItem()
    :exePath(""), iconPath(""), name("") {}

BIItem(std::string exe, std::string icon, std::string name)
    :exePath(exe), icon(iconPath), name(name) {}

std::string BIItem::getExePath()
{
    return exePath;
}

std::string BIItem::getIconPath()
{
    return iconPath;
}
