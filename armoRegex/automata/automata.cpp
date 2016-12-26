//
//  automata.cpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/17.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#include "automata.hpp"


regexNFA regexNFA::closureNFA(){
    regexNFA closure;
    closure.startNode.trans.push_back(AutomataNodeTrans('\0',closure.endNode));
    closure.startNode.trans.push_back(AutomataNodeTrans('\0',startNode));
    endNode.trans.push_back(AutomataNodeTrans('\0',startNode));
    endNode.trans.push_back(AutomataNodeTrans('\0',closure.endNode));
    return closure;
}

regexNFA regexNFA::connect(regexNFA &theOtherRegexNFA){
    regexNFA chain;
    chain.startNode=startNode;
    endNode.trans.push_back(AutomataNodeTrans('\0',theOtherRegexNFA.startNode));
    chain.endNode=theOtherRegexNFA.endNode;
    return chain;
}

regexNFA regexNFA::unite(regexNFA &theOtherRegexNFA){
    regexNFA unite;
    unite.startNode.trans.push_back(AutomataNodeTrans('\0',theOtherRegexNFA.startNode));
    unite.startNode.trans.push_back(AutomataNodeTrans('\0',startNode));
    theOtherRegexNFA.endNode.trans.push_back(AutomataNodeTrans('\0',unite.endNode));
    endNode.trans.push_back(AutomataNodeTrans('\0',unite.endNode));
    return unite;
}

regexNFA regexNFA::convert(regexNode &v,regexNFA &nfaAll){
    
    switch (v.type) {
        case REGEX_CHAR:
            nfaAll=regexNFA(v.ch);
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
