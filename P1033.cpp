/* 表达式求值 */
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

enum OptType {ADD, SUB, MUL, DIV, BRACKET, EXP, POS, NEG, NONE};
enum TokenType {DIGIT, OPT, VOID};

class Opt{
public:
    Opt() : opt(' '), type(NONE), predency(-2) {}
    Opt(char ch) : opt(ch){
        switch(ch){
        case '+':
            type = ADD;
            predency = 1;
            break;
        case '-':
            type = SUB;
            predency = 1;
            break;
        case '*':
            type = MUL;
            predency = 2;
            break;
        case '/':
            type = DIV;
            predency = 2;
            break;
        case '(':
            type = BRACKET;
            predency = 0;
            break;
        case '^':
            type = EXP;
            predency = 3;
            break;
        case '&':
            type = POS;
            predency = 4;
            break;
        case '|':
            type = NEG;
            predency = 4;
            break;
        case ')':
            type = BRACKET;
            predency = 10;
            break;
        default:
            throw runtime_error("fuck it");
            break;
        }
    }
    OptType getType() { return type; }
    int getPred() { return predency; }
    char getOpt() { return opt; }
private:
    char opt;
    OptType type;
    int predency;
};

long long qpow(long long x, long long n){
    long long ans = 1, tmp =x;
    while (n > 0){
        if (n & 1) ans *= tmp;
        n >>= 1;
        tmp *= tmp;
    }
    return ans;
}

long long operate(long long x, long long y, Opt opt){
    switch(opt.getOpt()){
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y == 0) throw runtime_error("fuck it");
        return x / y;
    case '^':
        return qpow(x, y);
    default:
        throw runtime_error("fuck it");
    }
}

char suf[200];
int sufSize = 0;

void infToSuf(){
    char ch;
    long long curNum = 0x7fffffff;
    TokenType lastTokenType = VOID;
    Opt optStack[200];
    int optSize = 0;

    while (cin >> ch){
        if (isdigit(ch)){
            if (curNum == 0x7fffffff) curNum = 0;
            curNum = curNum * 10 + ch - '0';
            lastTokenType = DIGIT;
        }
        else{
            if (lastTokenType == DIGIT && curNum != 0x7fffffff){
                if (curNum != 0){
                    int dec = ceil(log10(curNum));
                    if (abs(dec - log10(curNum)) < 1e-6) ++dec;
                    while (dec > 0){
                        suf[sufSize++] = curNum / qpow(10, dec - 1) + '0';
                        curNum %= qpow(10, dec - 1);
                        --dec;
                    }
                }
                else{
                    suf[sufSize++] = '0';
                }
                curNum = 0x7fffffff;
                suf[sufSize++] = '#';
            }
            Opt curOpt(ch);
            switch(curOpt.getOpt()){
            case ')':
                while (optSize > 0 && optStack[optSize - 1].getOpt() != '('){
                    suf[sufSize++] = optStack[--optSize].getOpt();
                }
                if (optSize == 0){
                    throw runtime_error("fuck it");
                }
                if (optStack[--optSize].getOpt() != '('){
                    throw runtime_error("fuck it");
                }
                lastTokenType = DIGIT;
                break;
            case '(':
                optStack[optSize++] = curOpt;
                lastTokenType = OPT;
                break;
            case '-': case '+':
                if (lastTokenType == VOID || lastTokenType == OPT){
                    lastTokenType = OPT;
                    if (curOpt.getOpt() == '-'){
                        Opt tmpOpt('|');
                        optStack[optSize++] = tmpOpt;
                    }
                    else{
                        Opt tmpOpt('&');
                        optStack[optSize++] = tmpOpt;
                    }
                    break;
                }
            case '*': case '/':
                if (optSize == 0 || curOpt.getPred() > optStack[optSize - 1].getPred()){
                    optStack[optSize++] = curOpt;
                }
                else{
                    while (optSize > 0 && curOpt.getPred() <= optStack[optSize - 1].getPred()){
                        suf[sufSize++] = optStack[--optSize].getOpt();
                    }
                    optStack[optSize++] = curOpt;
                }
                lastTokenType = OPT;
                break;
            case '^':
                if (optSize == 0 || curOpt.getPred() >= optStack[optSize - 1].getPred()){
                    optStack[optSize++] = curOpt;
                }
                else{
                    while (optSize > 0 && curOpt.getPred() < optStack[optSize - 1].getPred()){
                        suf[sufSize++] = optStack[--optSize].getOpt();
                    }
                    optStack[optSize++] = curOpt;
                }
                lastTokenType = OPT;
                break;
            }
        }
    }
    if (lastTokenType == DIGIT && curNum != 0x7fffffff){
        if (curNum != 0){
            int dec = ceil(log10(curNum));
            if (abs(dec - log10(curNum)) < 1e-6) ++dec;
            while (dec > 0){
                suf[sufSize++] = curNum / qpow(10, dec - 1) + '0';
                curNum %= qpow(10, dec - 1);
                --dec;
            }
        }
        else{
            suf[sufSize++] = '0';
        }
        curNum = 0x7fffffff;
        suf[sufSize++] = '#';
    }
    while (optSize > 0){
        if (optStack[--optSize].getOpt() == '('){
            throw runtime_error("fuck it");
        }
        suf[sufSize++] = optStack[optSize].getOpt();
    }
}

long long calcSuf(){
    long long numStack[200];
    int numSize = 0;
    int curPos = 0;
    long long curNum = 0x7fffffff;
    while (curPos < sufSize){
        while (isdigit(suf[curPos])){
            if (curNum == 0x7fffffff) curNum = 0;
            curNum = curNum * 10 + suf[curPos++] - '0';
        }
        if (suf[curPos] == '#') ++curPos;
        if (curNum != 0x7fffffff){
            numStack[numSize++] = curNum;
            curNum = 0x7fffffff;
        }
        if (isdigit(suf[curPos]))
            continue;
        Opt curOpt(suf[curPos++]);
        long long opr1 = 0, opr2 = 0;
        switch(curOpt.getOpt()){
        case '+': case '-': case '*': case '/': case '^':
            if (numSize < 2) throw runtime_error("fuck it");
            opr2 = numStack[--numSize];
            opr1 = numStack[--numSize];
            numStack[numSize++] = operate(opr1, opr2, curOpt);
            break;
        case '&': case '|':
            if (numSize < 1) throw runtime_error("fuck it");
            if (curOpt.getOpt() == '|')
                numStack[numSize - 1] = -numStack[numSize - 1];
            break;
        default:
            throw runtime_error("fuck it");
            break;
        }
    }
    return numStack[0];
}

int main(){
    try{
        infToSuf();
    }
    catch(runtime_error){
        cout << "Error" << endl;
        return 0;
    }
    try{
        cout << calcSuf() << endl;
    }
    catch(runtime_error){
        cout << "Error" << endl;
        return 0;
    }
    return 0;
}
