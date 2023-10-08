#include "GrammaScanner.hpp"

#include <algorithm>
#include <functional>
#include <map>

#include "common.hpp"

ScanResult::ScanResult() {}

static ScanResult substrToSR(std::string str, int pos, Transition tr) {
    ScanResult sr;
    sr.begin = str.substr(0, pos);
    sr.toReplace = str.substr(pos, tr.left.size());
    sr.end = str.substr(pos + tr.left.size());
    sr.replacement = tr.right;
    sr.start = pos;
    sr.num = tr.num;
    return sr;
}

std::vector<ScanResult> GrammaScannerCommon::scan(std::string str,
                                                  Transition tr) {
    std::vector<ScanResult> r;
    auto pos = 0; 
    while ((pos = str.find(tr.left, pos)) != std::string::npos) {
        r.push_back(substrToSR(str, pos, tr));
        pos += tr.left.size();
    }
    return r;
}

std::vector<ScanResult> GrammaScannerLeft::scan(std::string str,
                                                Transition tr) {
    std::vector<ScanResult> r;
    auto pos = 0;
    if ((pos = str.find(tr.left)) != std::string::npos)
        r.push_back(substrToSR(str, pos, tr));
    return r;
}

std::vector<ScanResult> GrammaScannerRight::scan(std::string str,
                                                 Transition tr) {
    std::vector<ScanResult> r;
    auto pos = 0;
    if ((pos = str.rfind(tr.left)) != std::string::npos)
        r.push_back(substrToSR(str, pos, tr));
    return r;
}

static int _manualInputVariantOfRule(std::vector<ScanResult> tsr,
                                     ScanResult sr) {
    if(sr.num == -1){
        return -1;
    } else{
        std::cout << "Current string: \033[34m" << sr.begin << "\033[31m"
                  << sr.toReplace << "\033[34m" << sr.end << "\033[0m\n";
        std::cout << "Choose:"
                  << "\n";
        auto offset =
            std::min_element(tsr.begin(), tsr.end(),
                             [](const ScanResult &lh, const ScanResult &rh) {
                                 return lh.num < rh.num;
                             })
                ->num;
        for (int i = 0; i < tsr.size(); i++) {
            std::cout << "\033[32m" << offset + i + 1 << ". \033[0m"
                      << tsr[i].toReplace << "-->" << tsr[i].replacement << "\n";
        }
        int chooseID;
        std::cout << "$> ";
        std::cin >> chooseID;
        chooseID = chooseID - 1;
        return chooseID;
    }
}

std::pair<std::vector<ScanResult>, ScannerStatus> _grammaScannerInner(
    GrammaScanner *gs_ptr, std::string str, Gramma g,
    std::function<bool(ScanResult &, std::vector<ScanResult> &)> cond,
    std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc) {
    std::vector<ScanResult> r;
    while (true) {
        ScanResult sr;               
        std::vector<ScanResult> tsr; 
        for (auto const &it : g) {
            auto srNew = gs_ptr->scan(str, it);
            if (srNew.size() != 0) {
                if (cond(srNew[0], tsr)) {
                    sr = srNew[0];
                    tsr.clear();
                    tsr.push_back(sr);
                } else if (srNew[0].start == sr.start) {
                    tsr.push_back(srNew[0]);
                }
            }
        }
        auto chooseID = getFunc(sr, tsr);
        if (chooseID == -1) {
            if (sr.start == -1)
                return {r, ScannerStatus::OK};
            else
                return {r, ScannerStatus::NON_TERM};
        }
        auto fsr = std::find_if(tsr.begin(), tsr.end(), [chooseID](ScanResult const &rsr){
            return rsr.num == chooseID;
        });
        if(fsr == tsr.end()){
            return {r, ScannerStatus::WRONG_RULE};
        }
//        if (sr.start == -1) {
//            return {r, ScannerStatus::OK};
//        }
        str =
            fsr->begin + fsr->replacement + fsr->end;
        r.push_back(*fsr);
    }
}

std::pair<std::vector<ScanResult>, ScannerStatus> _grammaScannerInner(
    GrammaScanner *gs_ptr, std::string str, Gramma g,
    std::function<bool(ScanResult &, std::vector<ScanResult> &)> cond) {
    return _grammaScannerInner(
        gs_ptr, str, g, cond, [](ScanResult &sr, std::vector<ScanResult> &tsr) {
            return _manualInputVariantOfRule(tsr, sr);
        });
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerLeft::scan(
    std::string str, Gramma g) {
    return _grammaScannerInner(
        this, str, g, [](ScanResult &sr, std::vector<ScanResult> &tsr) {
            return tsr.size() == 0 || tsr[0].start > sr.start;
        });
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerRight::scan(
    std::string str, Gramma g) {
    return _grammaScannerInner(
        this, str, g, [](ScanResult &sr, std::vector<ScanResult> &tsr) {
            return tsr.size() == 0 || tsr[0].start < sr.start;
        });
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerLeft::scan(
    std::string str, Gramma g,
    std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc) {
    return _grammaScannerInner(
        this, str, g,
        [](ScanResult &sr, std::vector<ScanResult> &tsr) {
            return tsr.size() == 0 || tsr[0].start > sr.start;
        },
        getFunc);
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerRight::scan(
    std::string str, Gramma g,
    std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc) {
    return _grammaScannerInner(
        this, str, g,
        [](ScanResult &sr, std::vector<ScanResult> &tsr) {
            return tsr.size() == 0 || tsr[0].start < sr.start;
        },
        getFunc);
}

ScannerStatus _grammaScannerInnerRecursive(
    GrammaScanner *gs_ptr, std::string str, Gramma &g,
    std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc,
    int depth, std::vector<ScanResult> &r, std::map<int, ScanResult> &badResults) {
    ScannerStatus res;
    if (depth == 0) {
        return ScannerStatus::RECURSION_OVERFLOW;
    } else {
        ScanResult sr;
        std::vector<ScanResult> tsr;
        int ruleID = getFunc(sr, tsr);
        if (ruleID == -1) {
            for (auto const &it : g) {
                auto check_tsr = gs_ptr->scan(str, it);
                if (check_tsr.size() != 0) {
                    return ScannerStatus::NON_TERM;
                }
            }
            return ScannerStatus::OK;
        }
        tsr = gs_ptr->scan(str, g[ruleID]);
        if (tsr.size() == 0) {
            return ScannerStatus::WRONG_RULE;
        } else {
            for (auto const &it : tsr) {
                r.push_back(it);
                res = _grammaScannerInnerRecursive(
                    gs_ptr, it.begin + it.replacement + it.end, g, getFunc,
                    depth - 1, r, badResults);
                if (res != ScannerStatus::OK) {
                    badResults[depth] = it;
                    r.pop_back();
                } else {
                    return res;
                }
            }
        }
    }
    return res;
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerCommon::scan(
    std::string str, Gramma g) {
    UNIMPLEMENTED;
}

std::pair<std::vector<ScanResult>, ScannerStatus> GrammaScannerCommon::scan(
    std::string str, Gramma g,
    std::function<int(ScanResult &, std::vector<ScanResult> &)> getFunc) {
    std::vector<ScanResult> r;
    std::map<int, ScanResult> badResults;
    ScannerStatus res =
        _grammaScannerInnerRecursive(this, str, g, getFunc, 100, r, badResults);
    if(res != ScannerStatus::OK){
        for(auto it = badResults.rbegin(); it != badResults.rend(); it++){
            r.push_back(it->second);
        }
    }
    return {r, res};
}

bool GrammaScanner::isCommon(void){
    return false;
}


bool GrammaScannerCommon::isCommon(void){
    return true;
}
