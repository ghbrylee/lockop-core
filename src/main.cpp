//
//  main.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-01.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "main.h"
#include "util.h"
#include "block.h"

using namespace std;
using namespace lockop;

namespace lockop{
    CMainParams::CMainParams()
        : mNetworkPassphrase(18446744073709551615)
        , mStrNetworkID("main")
        , mStartMessage(256)
        , mDefaultPort(25250)
        , mNode("172.0.0.1")
    {
    }

    std::string& CMainParams::getNode(){
        return mNode;
    }

    uint8_t CMainParams::getStartMessage(int arrNum){
        return mStartMessage;
    }
}

void test(){
    for (int i=0; i<1000000; i++){
        std:;cout << "[DEBUG] Generating block.....  #Block age count : " << i << "\n";
        usleep(100000);
    }
}

int main(void){
    lockop::CLogManager log;
    log.printText("DEBUG", "Lockop-core world");
    
    std::thread t1(addBlock);
    t1.join();
    /*
    std::thread t2(checkerBlock);
    std::thread t3(test);
    t2.join();
    t3.join();
    */
}
