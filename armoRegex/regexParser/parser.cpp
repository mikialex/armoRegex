//
//  parser.cpp
//  armoRegex
//
//  Created by MikiAlex on 16/12/16.
//  Copyright © 2016年 MikiAlex. All rights reserved.
//

#include "parser.hpp"

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

//char lookAhead;
//void match(char ch);
//
//void regexParseTerm(){
//    switch (lookAhead) {
//        case 'a':
//            match('a');
//            break;
//        case 'b':
//            match('b');
//            break;
//        case '(':
//            match('(');
////            regexParseRegex();
//            break;
//        default:
//            break;  //返回错误
//    }
//}
//
//void regexParseFactorTail(){
//    switch (lookAhead) {
//        case '*':
//            match('*');
//            regexParseFactorTail();
//            break;
//        default:
//            break;  // <e>
//    }
//}
//
//void regexParseFactor(){
//    switch (lookAhead) {
//        case '(':
//            regexParseTerm();
//            regexParseFactorTail();
//            break;
//        case 'a':
//            regexParseTerm();
//            regexParseFactorTail();
//            break;
//        case 'b':
//            regexParseTerm();
//            regexParseFactorTail();
//            break;
//        case '\0':
//            return;
//            break;
//        default:
//            break;  //返回错误
//    }
//}
//
//void regexParseExprTail(){
//    switch (lookAhead) {
//        case '(':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//        case 'a':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//        case 'b':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//        default :
//            return;
//            break; // <e>
//    }
//}
//
//void regexParseExpr(){
//    switch (lookAhead) {
//        case '(':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//        case 'a':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//        case 'b':
//            regexParseFactor();
//            regexParseExprTail();
//            break;
//            
//        default:
//            break;  //返回错误
//    }
//};
//
//void regexParseRegexTail(){
//    switch (lookAhead) {
//        case '|':
//            match('|');
//            regexParseExpr();
//            regexParseRegexTail();
//            break;
//        default :
//            return;
//            break; // <e>
//    }
//};
//
//
//void regexParseRegex(){
//    switch (lookAhead) {
//        case '(':
//            regexParseExpr();
//            regexParseRegexTail();
//            break;
//        case 'a':
//            regexParseExpr();
//            regexParseRegexTail();
//            break;
//        case 'b':
//            regexParseExpr();
//            regexParseRegexTail();
//            break;
//            
//        default:
//            break;  //返回错误
//    }
//}





/////////////////////////////////////////////////////////////

//regexParseResult regexParseChar(RegexContext &c,regexNode &node){//解析一位字符
//    node.type=REGEX_CHAR;
//    node.ch=*(c.currentP);
//    c.currentP++;
//    return REGEX_PARSE_OK;
//}
//
//regexParseResult regexParseTerm(RegexContext &c,regexNode &node){
//    
//    regexParseResult ret;
//    
//    switch (*(c.currentP)) {
//        case '(':
//            c.currentP++;
//            
//            regexNode subNode;
//            ret=regexParseRegex(c,subNode);
//            if(ret==REGEX_PARSE_OK){
//                node.term=&subNode;
//            }
//            node.type=REGEX_TERM;
//            break;
//        default:
//            
//            break;
//    }
//    
//    return ret;
//}
//
//
//regexParseResult regexParseRegex(RegexContext &c,regexNode &node){//解析regex
//    
//    return REGEX_PARSE_OK;
//    
//}
//
//regexParseResult regexParseNode(RegexContext &c,regexNode &node){//解析regex node
//    switch (*c.currentP) {
//        case '\0': return REGEX_PARSE_EXPECT_VALUE;
//        case '(':  return regexParseRegex(c, node);
//        default:   return regexParseChar(c, node);
//    }
//}
//
//
//regexParseResult regexParse(regexNode &rootNode,const string &regexRawString){//解析正则文本
//    RegexContext c;
//    c.regex=regexRawString;
//    c.currentP=c.regex.begin();
//    regexParseResult ret;
//    rootNode.type=REGEX_INVAILD;
//    ret = regexParseNode(c, rootNode);
//    return ret;
//}
