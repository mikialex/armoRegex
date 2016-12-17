//
//  main.cpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/16.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//regex parse 结果
enum regexParseResult{
    REGEX_PARSE_OK,
    REGEX_PARSE_EXPECT_VALUE,
    REGEX_PARSE_INVALID_VALUE,
};

class AutomataNode;

// NFA DFA 状态转换图 转换
class AutomataNodeTrans{
public:
    char letter;
    AutomataNode* aimNode;
};

//NFA DFA 状态转换图节点
class AutomataNode{
public:
    vector<AutomataNodeTrans> trans;
    
};

//NFA
class regexNFA{
public:
    vector<AutomataNode> nodes; //nfa所有节点，用于加速节点查找，所有NFA合并完成以后再运行生成
    
    AutomataNode start;  //nfa开始节点
    AutomataNode end;   //nfa结束节点
    
    regexNFA connect(regexNFA &theOtherRegexNFA);//连接
    regexNFA unite(regexNFA &theOtherRegexNFA); //并
    regexNFA closure(); //自身的闭包
};


class RegexContext{
public:
    string regex; //正则文本内容
    string currentP;//当前解析位置
};

regexParseResult regexParseNode(RegexContext){
    
    
    return 0//
}

class Regex{
    
};


int main(int argc, const char * argv[]) {
    
    string testRex="(a|b)*abb";
    
    int *a=new int(100);
    
    Regex *testRegex = new Regex(testRex);
    
    cout<<testRegex.match("aababababb")<<endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
