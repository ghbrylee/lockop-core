#include <iostream>
#include "include/block.h"

using namespace std;
namespace lockop{
    CBlockHeader::CBlockHeader()
        : mBlockNum(0)
        , mHash("")
        , mPreviousHash("")
        , mTimestamp(0)
    {
    }
    
    int CBlockHeader::getBlockNum() const{
        return mBlockNum;
    }

    void CBlockHeader::setGenesisBlock() const{
        
    }

}