#include "GrammaParser.hpp"

#include <cassert>
#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"

Transition::Transition(std::string const& left, std::string const& right, int num)
    : left(left), right(right), num(num) {}

Transition& Gramma::operator[](int i) {
    assert(i < rules.size());
    return rules[i];
}

void Gramma::push_back(Transition const& t) { rules.push_back(t); }

Gramma GrammaParser::parseFile(std::string fname) {
    std::ifstream fileStream(fname);
    assert(fileStream.is_open());

    nlohmann::json j = nlohmann::json::parse(fileStream);
    fileStream.close();

    j = j["gramma"];
    Gramma g;
    int num = 0;
    for (auto const &it : j.items()){
        for (const auto& val : it.value().items()) {
            g.push_back(Transition(val.key(), val.value(), num));
            num++;
        }
    }
    return g;
}