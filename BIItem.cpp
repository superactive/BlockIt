#include "BIItem.h"

BIItem()
    :exePath(""), iconPath(""), name("") {}

BIItem(string exe, icon, name)
    :exePath(exe), icon(iconPath), name(name) {}

std::string BIItem::getExePath()
{
    return exePath();
}

std::string BIItem::getIconPath()
{
    return iconPath();
}
