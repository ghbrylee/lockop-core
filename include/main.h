//
//  main.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-01.
//  Copyright (c) 2019 brylabs. All rights reserved.
//

#pragma once
#include <string>

namespace lockop{

    class CMainParams{
        public:
            CMainParams();
            void setNetworkID();
            std::string& getNetwrokID();
            uint8_t getStartMessage(int arrNum);
            void setNodeSeeds();
        private:
            const uint64_t networkPassphrase = 18446744073709551615;
            std::string mStrNetworkID;
            uint8_t mStartMessage;
            uint16_t mDefaultPort;
            std::string mNode1;
            std::string mNode2;


    };

}