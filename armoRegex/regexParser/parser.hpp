//
//  parser.hpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/16.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#ifndef parser_hpp
#define parser_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//regex parse 结果
enum regexParseResult{
    REGEX_PARSE_OK,
    REGEX_PARSE_EXPECT_VALUE,
    REGEX_PARSE_INVALID_VALUE,
};

enum regexType{
    REGEX_CHAR,//单个字符
    REGEX_UNION,//并
    REGEX_CLOSURE,//*
    REGEX_GROUP,//括号
    REGEX_EXPER//regex表达式
};


//regex节点
class regexNode{
public:
    string name;//名称
    vector<regexNode> objectNodes;//对象节点，存放对象成员
    vector<regexNode> arrayNodes;//数组节点，存放数组成员
    string s; //字符串节点，存放字符串
    double n;//数值节点，存放节点数值
    regexType type;//节点类型
};

class RegexContext{
public:
    string regex; //正则文本内容
    string currentP;//当前解析位置
};


regexParseResult regexParseNode(RegexContext);//解析regex node


regexParseResult regexParse(regexNode &rootNode,const string &regexRawString);



#endif /* parser_hpp */
