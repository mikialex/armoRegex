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

////<regex> => <expr> <regex-tail>
////<regex-tail> => "|" <expr>  |  <e>
////
////<expr> => <factor> <expr-tail>
////<expr-tail> => <factor> <expr-tail>  |  <e>
////
////<factor> => <term> <factor-tail>
////<factor-tail> => "*" <factor-tail>  |  <e>
////
////<term> => char  |  "(" <regex> ")"

//regex parse 结果
enum regexParseResult{
    REGEX_PARSE_OK,
    REGEX_PARSE_EXPECT_VALUE,
    REGEX_PARSE_INVALID_VALUE,
};

//


enum regexType{
    REGEX_INVAILD,
    REGEX_CHAR,//
    REGEX_TERM,//
    REGEX_FACTOR,//
    REGEX_MIDEXPER,//
    REGEX_EXPER//regex表达式
};


//regex节点
class regexNode{
public:
    char ch;
    regexNode* term;
    regexType type;//节点类型
};

class RegexContext{
public:
    string regex; //正则文本内容
    string::iterator currentP;//当前解析位置
    
    regexParseResult match();
};


//void regexParseWhitespace(RegexContext &c);//正则表达式 空白如何处理？？
void regexParse(RegexContext &c);


regexParseResult regexParseTerm(RegexContext &c,regexNode &node);
regexParseResult regexParseChar(RegexContext &c,regexNode &node);//解析一位字符
regexParseResult regexParseRegex(RegexContext &c,regexNode &node);//解析regex

regexParseResult regexParseNode(RegexContext &c,regexNode &node);//解析regex node


regexParseResult regexParse(regexNode &rootNode,const string &regexRawString);//解析正则文本



#endif /* parser_hpp */
