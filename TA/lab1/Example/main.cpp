#include <iostream>
#include <memory>
#include <algorithm>

#include "GrammaParser.hpp"
#include "GrammaScanner.hpp"
#include "TreeBuilder.hpp"

int main(){
    auto g = GrammaParser::parseFile("gramma.json");
    int gramma_index = 1;
    for(auto t : g){
        std::cout  << gramma_index << ". " << t.left << "-->" << t.right << "\n";
        gramma_index++;
    }
    std::string str = "S";
    auto ptr = std::make_shared<GrammaScannerRight>();
    int index = 0;
    std::vector<int> test1 = {1, 2, 3, 5, 8, 6, 2, 3, 5, 8, 4, 3, 6};
    std::vector<int> test2 = {2, 1, 3, 5, 8, 4, 3, 6, 2, 3, 5, 8, 6};
    std::vector<int> test3 = {1, 2, 2, 3, 3, 5, 5, 8, 8, 4, 6, 3, 6}; // L-WR R-WR
    std::vector<int> test4 = {2, 1, 2, 3, 5, 8, 6, 3, 5, 8, 4, 3, 6};

    std::vector<int> test5 = {1, 2, 2, 3, 5, 8, 4, 3, 6, 3, 5, 8, 6};
    std::vector<int> test6 = {1, 3, 5, 8, 6, 2, 2, 3, 5, 8, 4, 3, 6};
    std::vector<int> test7 = {2, 1, 3, 6, 2, 3, 6};
    std::vector<int> rules = test7;

    auto [v, res] = ptr->scan(str, g, [rules, index](ScanResult &sr, std::vector<ScanResult> &tsr) mutable{
        if(index == rules.size())
            return -1;
        int num = rules[index]-1;
        index++;
        return num;
    });

    int step_i = 1;
    for(auto const &it : v){
        std::cout << "\033[33mStep #" << step_i++ << "\033[0m\n";
        std::cout << it.begin << "\033[31m" << it.toReplace << "\033[0m" << it.end << "\n";
        std::cout << "Rule\033[34m #" << it.num + 1 << ": \033[31m" << it.toReplace << "\033[34m-->\033[32m" << it.replacement << "\033[0m\n";
    }
    if(v.size() != 0){
        auto finalSr = v[v.size()-1];
        auto finalStr = finalSr.begin + finalSr.replacement + finalSr.end;
        std::cout << "Final: \033[32m" << finalStr << "\033[0m\n";

    }
    if(res == ScannerStatus::OK){
        std::cout << "\033[32mFine \033[0m\n";
        if(ptr->isCommon() != true){
            TreeBuilder tb;
            std::string str = tb.buildTree(ptr.get(), g, v);
            std::cout << str << "\n";
            tb.buildTree(str);
        }
    } else if (res == ScannerStatus::WRONG_RULE){
        std::cout << "\033[31mWRONG RULE \033[0m\n";
    } else if (res == ScannerStatus::NON_TERM){
        std::cout << "\033[33mNON TERM \033[0m\n";
    }
    return 0;
}