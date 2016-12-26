//
//  automata.cpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/17.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#include "automata.hpp"


regexNFA regexNFA::closureNFA(){
    regexNFA a;
    return a;
}

regexNFA regexNFA::connect(regexNFA &theOtherRegexNFA){
    regexNFA a;
    return a;
}

regexNFA regexNFA::unite(regexNFA &theOtherRegexNFA){
    regexNFA a;
    return a;
}


regexNFA regexNFA::createSingleCharNFA(char chr){//识别单个字符的nfa
    regexNFA nfa;
    return nfa;
};

regexNFA regexNFA::convert(regexNode &v,regexNFA &nfaAll){
    
    switch (v.type) {
        case REGEX_CHAR:
            nfaAll=createSingleCharNFA(v.ch);
            break;
        case REGEX_TERM:
            if(v.subNodeLeft==nullptr){
                return convert(*v.subNodeRight,nfaAll);
            }else{
                return convert(*v.subNodeLeft,nfaAll);
            }
            break;
        case REGEX_FACTOR_TAIL:
            if(v.subNodeLeft==nullptr&&v.subNodeRight==nullptr){// <e>
                return nfaAll;
            }else{
                return convert(*v.subNodeRight,nfaAll).closureNFA();// TOCHECK
            }
            break;
        case REGEX_FACTOR:
            convert(*v.subNodeLeft,nfaAll);
            convert(*v.subNodeRight,nfaAll);
            break;
        case REGEX_EXPER_TAIL:
            convert(*v.subNodeLeft,nfaAll);
            convert(*v.subNodeRight,nfaAll);
            break;
        case REGEX_EXPER:
            {
            regexNFA branch=convert(*v.subNodeRight,branch);
            return convert(*v.subNodeLeft,nfaAll).connect(branch);
            
            break;
             }
        case REGEX_REGEX_TAIL:
            if(v.subNodeLeft==nullptr&&v.subNodeRight==nullptr){// <e>
                return nfaAll;
            }else{
                regexNFA branch;
                return convert(*v.subNodeRight,branch).unite(nfaAll);
            }
            break;
        case REGEX_REGEX:
            convert(*v.subNodeLeft,nfaAll);
            convert(*v.subNodeRight,nfaAll);
            break;
            
        default:
            break;
    }
    
    return nfaAll;
}
