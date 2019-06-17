    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constants.hpp
 * Author: ubuntu
 *
 * Created on January 21, 2018, 7:02 AM
 */

#ifndef KETO_BALANCER_CONSTANTS_HPP
#define KETO_BALANCER_CONSTANTS_HPP

#include "keto/common/MetaInfo.hpp"


namespace keto {
namespace balancer {

class Constants {
public:
    static std::string getHeaderVersion() {
        return OBFUSCATED("$Id$");
    };
    
    static std::string getSourceVersion();
    
    Constants() = delete;
    Constants(const Constants& orig) = delete;
    virtual ~Constants() = delete;
    
    // document root
    static constexpr const char* DEFAULT_BLOCK = "default_block";

    // state storage
    static constexpr const char* STATE_STORAGE_CONFIG = "balancer_state_storage";
    static constexpr const char* STATE_STORAGE_DEFAULT = "data/balancer/state.ini";

    static constexpr const char* PERSISTED_STATE = "Balancer.state";
    
};
    
}
}


#endif /* CONSTANTS_HPP */

