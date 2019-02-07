#include <iostream>
#include "block.h"

using namespace std;
namespace lockop{
    CBlockHeader::CBlockHeader(){
        : mBlockNum(0)
        , mHash("")
        , mPreviousHash("")
        , mTimestamp(0)
    }
    
    int CBlockHeader::getBlockNum() const{
        return nBlockNum;
    }

    void CBlockHeader::setGenesisBlock() const{
        
    }

}