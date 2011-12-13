#ifndef IBLOCK_H
#define IBLOCK_H

#include "BIItem.h"
#include <vector>

class IBlock
{

public:
    virtual ~IBlock() {}
    virtual void Block(BIItem item);
    virtual void Block(std::string path);

    virtual std::vector<BIItem> GetInstalled();
    virtual std::vector<BIItem> GetRunning();

};

#endif // IBLOCK_H
