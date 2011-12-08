#include "BIItem.h"

BIItem::BIItem()
    :exePath(""), iconPath(""), name("") {}

BIItem::BIItem(std::string exe, std::string icon, std::string name)
    :exePath(exe), iconPath(icon), name(name) {}

std::string BIItem::getExePath()
{
    return exePath;
}

std::string BIItem::getIconPath()
{
    return iconPath;
}

std::string BIItem::getName()
{
    return name;
}

std::string BIItem::toString()
{
    return "Name: " + name + " Path: " + exePath + " Icon: " + iconPath;
}
