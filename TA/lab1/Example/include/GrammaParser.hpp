#ifndef _INC_GRAMMAPARSER_HPP
#define _INC_GRAMMAPARSER_HPP

#include <string>
#include <vector>

struct Transition{
    Transition(std::string const &left, std::string const &right, int num);
    std::string left;
    std::string right;
    int num = -1;
};

class Gramma{
    public:
    Transition& operator[](int i);
    void push_back(Transition const &t);
    auto begin(){ return rules.begin();}
    auto end(){ return rules.end();}

    private:
    std::vector<Transition> rules;
};

class GrammaParser{
    public:
    static Gramma parseFile(std::string fname);
};




#endif