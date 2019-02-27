//
//  main.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-01.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <string>
#include <thread>
#include <unistd.h>

namespace lockop{

    class CMainParams{
        public:
            CMainParams();
            std::string& getNode();
            uint8_t getStartMessage(int arrNum);
        private:
            const uint64_t mNetworkPassphrase;
            const std::string mStrNetworkID;
            const uint8_t mStartMessage;
            const uint16_t mDefaultPort;
            std::string mNode;


    };

}