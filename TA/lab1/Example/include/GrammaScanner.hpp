#ifndef _INC_GRAMMASCANNER_HPP
#define _INC_GRAMMASCANNER_HPP

#include "GrammaParser.hpp"

#include <string>
#include <vector>
#include <functional>

struct ScanResult{
    ScanResult();
    std::string begin; 
    std::string toReplace; 
    std::string replacement; 
    std::string end; 
    int start = -1; 
    int num = -1; 
};

// ENUM
enum ScannerStatus{
    OK,
    NON_TERM,
    WRONG_RULE,
    RECURSION_OVERFLOW
};

class GrammaScanner{
    public:
    virtual std::vector<ScanResult> scan(std::string str, Transition tr) = 0;
    virtual std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g) = 0;
    virtual std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g, std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc) = 0;
    virtual bool isCommon(void);
};

class GrammaScannerLeft : public GrammaScanner{
    public:
    std::vector<ScanResult> scan(std::string str, Transition tr);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g, std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc);
};

class GrammaScannerRight : public GrammaScanner{
    public:
    std::vector<ScanResult> scan(std::string str, Transition tr);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g, std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc);
};

class GrammaScannerCommon : public GrammaScanner{
    public:
    std::vector<ScanResult> scan(std::string str, Transition tr);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g);
    std::pair<std::vector<ScanResult>, ScannerStatus> scan(std::string str, Gramma g, std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc);
    bool isCommon(void);
};

#endif