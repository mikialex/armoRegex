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

const char asciiTable[2]={'a','b'};

enum charType{
    
};

//regex parse 结果
enum regexParseResult{
    REGEX_PARSE_OK,
    REGEX_PARSE_EXPECT_VALUE,
    REGEX_PARSE_INVALID_VALUE,
};


enum regexType{
    REGEX_INVAILD,
    
    REGEX_CHAR,//
    
    REGEX_TERM,//
    
    REGEX_FACTOR,//
    REGEX_FACTOR_TAIL,//
    
    REGEX_EXPER_TAIL,//
    REGEX_EXPER,//
    
    REGEX_REGEX_TAIL,//
    REGEX_REGEX//regex表达式
};


//regex节点
class regexNode{
public:
    regexNode(){
        ch='\0';
        subNodeLeft=nullptr;
        subNodeRight=nullptr;
        type=REGEX_INVAILD;
    }
    ~regexNode(){
        delete subNodeLeft;
        delete subNodeRight;
    }
    char ch;
    regexNode* subNodeLeft;//左子节点
    regexNode* subNodeRight;//右子节点
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


regexParseResult regexParseTerm(RegexContext &c,regexNode &v);
regexParseResult regexParseFactorTail(RegexContext &c,regexNode &v);
regexParseResult regexParseFactor(RegexContext &c,regexNode &v);
regexParseResult regexParseExprTail(RegexContext &c,regexNode &v);
regexParseResult regexParseExpr(RegexContext &c,regexNode &v);
regexParseResult regexParseRegexTail(RegexContext &c,regexNode &v);
regexParseResult regexParseRegex(RegexContext &c,regexNode &v);

regexParseResult regexParseNode(RegexContext &c,regexNode &node);


regexParseResult regexParse(regexNode &rootNode,const string &regexRawString);//解析正则文本



#endif /* parser_hpp */
