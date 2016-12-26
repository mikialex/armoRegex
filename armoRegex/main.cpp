//
//  main.cpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/16.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#include <iostream>
#include <vector>

#include "regexParser/parser.hpp"
#include "automata/automata.hpp"

using namespace std;

class Regex{
public:
    regexNFA NFA ;//nfa
    bool test(string &s);//测试字符串是否匹配
};


int main(int argc, const char * argv[]) {
    
    string testRex="b*a";
    
    
//    Regex *testRegex = new Regex(testRex);
//    
//    cout<<testRegex->test("aababababb")<<endl;
    RegexContext context;
    context.regex=testRex;
    context.currentP=context.regex.begin();
    
//    regexNode *root=new regexNode();
//    regexParseRegex(context,*root);
//    delete root;root=nullptr;
    
    AutomataNode a1;
    {
        AutomataNode a2;
    AutomataNodeTrans b('a',a2);
    
    a1.trans.push_back(b);
    }
    
//    for(int i=0;i<=10000;i++){
//        int a=int(1);
//    }
    
    std::cout <<asciiTable[0];
    return 0;
}
