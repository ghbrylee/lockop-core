#include "block.h"
#include <iostream>

using namespace std;
namespace lockop{
    CBlockHeader::CBlockHeader()
        : mVersion(1)
        , mHeight(0)
        , mHashPrevBlock(0)
        , mHashMerkleRoot(0)
        , mTime(0)
        , mData("0")
    {
    }

    int CBlockHeader::getHeight(){
        return mHeight;
    }


}