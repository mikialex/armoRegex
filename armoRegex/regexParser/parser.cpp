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


regexParseResult regexParseTerm(RegexContext &c,regexNode &v){
    
    regexParseResult ret;
    regexNode *chr=new regexNode();
    (*chr).type=REGEX_CHAR;
    switch (*c.currentP) {
        case 'a':
            c.currentP++;
            (*chr).ch='a';
            v.subNodeLeft=chr;
            ret=REGEX_PARSE_OK;
            break;
        case 'b':
            c.currentP++;
            (*chr).ch='b';
            v.subNodeLeft=chr;
            ret=REGEX_PARSE_OK;
            break;
        case '(':
            {
            c.currentP++;
            regexNode *regex=new regexNode();
            (*regex).type=REGEX_REGEX;
            ret=regexParseRegex(c,*regex);
            break;
            }
        default:
            ret=REGEX_PARSE_INVALID_VALUE;
            break;  //返回错误
    }
    return ret;
}

regexParseResult regexParseFactorTail(RegexContext &c,regexNode &v){
    regexParseResult ret;
    regexNode *factorTail=new regexNode();
    (*factorTail).type=REGEX_FACTOR_TAIL;
    switch (*c.currentP) {
        case '*':
            c.currentP++;
            v.subNodeRight=factorTail;
            ret=regexParseFactorTail(c,*factorTail);
            break;
        default:
            ret=REGEX_PARSE_OK;
            break;  // <e>
    }
    return ret;
}

regexParseResult regexParseFactor(RegexContext &c,regexNode &v){
    regexParseResult ret;
    regexNode *term=new regexNode();
    regexNode *factorTail=new regexNode();
    (*term).type=REGEX_TERM;
    (*factorTail).type=REGEX_FACTOR_TAIL;
    
    v.subNodeLeft=term;
    v.subNodeRight=factorTail;
    switch (*c.currentP) {
        case '(':
            ret=regexParseTerm(c,*term);
            ret=regexParseFactorTail(c,*factorTail);
            break;
        case 'a':
            ret=regexParseTerm(c,*term);
            ret=regexParseFactorTail(c,*factorTail);
            break;
        case 'b':
            ret=regexParseTerm(c,*term);
            ret=regexParseFactorTail(c,*factorTail);
            break;
            
        default:
            ret=REGEX_PARSE_INVALID_VALUE;
            break;  //返回错误
    }
    return ret;
}

regexParseResult regexParseExprTail(RegexContext &c,regexNode &v){
    regexParseResult ret;
    regexNode *exprTail=new regexNode();
    regexNode *factor=new regexNode();
    (*factor).type=REGEX_FACTOR;
    (*exprTail).type=REGEX_EXPER_TAIL;
    
    v.subNodeLeft=factor;
    v.subNodeRight=exprTail;
    switch (*c.currentP) {
        case '(':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
        case 'a':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
        case 'b':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
        default :
            ret=REGEX_PARSE_OK;
            break; // <e>
    }
    return ret;
}

regexParseResult regexParseExpr(RegexContext &c,regexNode &v){
    regexParseResult ret;
    regexNode *factor=new regexNode();
    regexNode *exprTail=new regexNode();
    (*factor).type=REGEX_FACTOR;
    (*exprTail).type=REGEX_EXPER_TAIL;
    
    v.subNodeLeft=factor;
    v.subNodeRight=exprTail;
    switch (*c.currentP) {
        case '(':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
        case 'a':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
        case 'b':
            ret=regexParseFactor(c,*factor);
            ret=regexParseExprTail(c,*exprTail);
            break;
            
        default:
            ret=REGEX_PARSE_INVALID_VALUE;
            break;  //返回错误
    }
    return ret;
};

regexParseResult regexParseRegexTail(RegexContext &c,regexNode &v){
    regexParseResult ret;
    regexNode *expr =new regexNode();
    regexNode *regexTail=new regexNode();
    (*expr).type=REGEX_EXPER;
    (*regexTail).type=REGEX_REGEX_TAIL;
    switch (*c.currentP) {
        case '|':
            c.currentP++;
            v.subNodeRight=expr;
            ret=regexParseExpr(c,*expr);
            break;
        default :
            ret=REGEX_PARSE_OK;
            break; // <e>
    }
    return ret;
};


regexParseResult regexParseRegex(RegexContext &c,regexNode &v){
    
    regexParseResult ret=REGEX_PARSE_INVALID_VALUE;
    v.type=REGEX_REGEX;
    
    regexNode *expr= new regexNode();
    regexNode *regexTail= new regexNode();
    (*expr).type=REGEX_EXPER;
    (*regexTail).type=REGEX_REGEX_TAIL;
    
    v.subNodeLeft=expr;
    v.subNodeRight=regexTail;
    switch (*c.currentP) {
        case '(':
            ret=regexParseExpr(c,*expr);
            ret=regexParseRegexTail(c,*regexTail);
            break;
        case 'a':
            ret=regexParseExpr(c,*expr);
            ret=regexParseRegexTail(c,*regexTail);
            break;
        case 'b':
            ret=regexParseExpr(c,*expr);
            ret=regexParseRegexTail(c,*regexTail);
            break;
            
        default:
            ret=REGEX_PARSE_INVALID_VALUE;
            break;  //返回错误
    }
    return ret;
}


