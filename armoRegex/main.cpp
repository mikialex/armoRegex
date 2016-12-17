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

using namespace std;

class AutomataNode;


// NFA DFA 状态转换图 转换
class AutomataNodeTrans{
public:
    char ch;  //接受的字符
    AutomataNode* aimNode;  //目标节点
};


//NFA DFA 状态转换图 节点
class AutomataNode{
public:
    vector<AutomataNodeTrans> trans; //转换关系
//    int id;  //节点编号
};


//NFA
class regexNFA{
public:
    vector<AutomataNode> lookUpTable    ; //nfa所有节点，用于加速节点查找，所有NFA合并完成以后再运行生成
    
    AutomataNode start;  //nfa开始节点
    AutomataNode end;   //nfa结束节点
    
    regexNFA connect(regexNFA &theOtherRegexNFA);//连接
    regexNFA unite(regexNFA &theOtherRegexNFA); //并
    regexNFA closureNFA(); //自身的闭包
    
    vector<AutomataNode> move(vector<AutomataNode> Nodes,char ch);//转换函数 返回一堆节点下，读入字符后，到达的所有节点
    vector<AutomataNode> closure(vector<AutomataNode> Nodes);  //返回一堆节点的可达节点集合 即所有通过空字符（一步或多步）到达的点的集合
    
    bool test(string &s);//测试字符串是否匹配
};




class Regex{
public:
    regexNFA NFA ;//nfa
    bool test(string &s);//测试字符串是否匹配
};


int main(int argc, const char * argv[]) {
    
    string testRex="(a|b)*abb";
    
    
//    Regex *testRegex = new Regex(testRex);
//    
//    cout<<testRegex->test("aababababb")<<endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
