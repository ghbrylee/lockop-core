//
//  main.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-01.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include "main.h"
#include "block.h"
#include <iostream>

using namespace std;

namespace lockop{
    CMainParams::CMainParams()
        : mStrNetworkID("ff")
        , mStartMessage(256)
        , mDefaultPort(20201)
    {
    }

    void CMainParams::setNetworkID(){
        mStrNetworkID = "main";
    }

    std::string& CMainParams::getNetwrokID(){
        return mStrNetworkID;
    }

    uint8_t CMainParams::getStartMessage(int arrNum){
        return mStartMessage;
    }

    void CMainParams::setNodeSeeds(){
        
    }
    
}

int main(void){
//    CBlockHeader genesis;
    lockop::CMainParams dm;

    std::cout << "[DEBUG] HELLO, Lockop-core world" << '\n' << std::endl;
    std::cout << dm.getNetwrokID() << '\n' << std::endl;
//    std::cout << genesis.getVersion() << '\n' << std::endl;
}


