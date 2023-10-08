#include "TreeBuilder.hpp"

#include <iostream>
#include <map>
#include <stack>
#include <fstream>

// Recursive

std::string TreeBuilder::buildTree(GrammaScannerCommon *gs_ptr, Gramma g, std::vector<ScanResult> &tsr) {
    return buildTree((GrammaScannerLeft*)gs_ptr, g, tsr);
}

std::string TreeBuilder::buildTree(GrammaScannerLeft *gs_ptr, Gramma g, std::vector<ScanResult> &tsr) {
    std::string to_scan = tsr[0].begin + tsr[0].toReplace + tsr[0].end;
    int pos = 0;
    for(auto const &it : tsr){
        auto sr = gs_ptr->scan(to_scan.substr(pos), g[it.num])[0];
        pos = sr.start + pos;
        if(pos == 0)
            to_scan = to_scan.substr(pos) + "(" + sr.replacement + ")";
        else
            to_scan = to_scan.substr(0, pos+1) + "(" + sr.replacement + ")" + to_scan.substr(pos+1);
        pos += 1;
    }
    return to_scan;
}

std::string TreeBuilder::buildTree(GrammaScannerRight *gs_ptr, Gramma g, std::vector<ScanResult> &tsr) {
    std::string to_scan = tsr[0].begin + tsr[0].toReplace + tsr[0].end;
    int pos = to_scan.size() - 1;
    int offset = 0;
    for(auto const &it : tsr){
        auto sr = gs_ptr->scan(to_scan.substr(0, pos?pos+1:1), g[it.num])[0];
        pos = sr.start + sr.toReplace.size();
        if(to_scan.size() == 1)
            to_scan = "(" + sr.replacement + ")" + to_scan.substr(0, pos?pos:1) ;
        else
            to_scan =  to_scan.substr(0, pos-1) + "(" + sr.replacement + ")" + to_scan.substr(pos-1);
        pos = sr.start + sr.replacement.size();
    }
    return to_scan;
}

struct treeDrawer{
    std::vector<std::pair<std::string, std::string>> declarations;
    std::vector<std::pair<std::string, std::string>> links;
    int index = 0;
    int nodeIndex = 0;
    int level = 0;
    std::stack<int> st;
    void addDef(std::string const &str){
        declarations.push_back(std::make_pair(std::to_string(nodeIndex), str));
        nodeIndex++;
    }
    void connectToNode(int ii, std::string toCon){
        links.push_back(std::make_pair(std::to_string(ii), toCon));
    }
    void drawTreeRight(std::string &str){
        if(str[index] != '(' && str[index] != ')'){
            st.push(nodeIndex);
            addDef(std::string{str[index]});
        } else{
            if(str[index] == '('){
                std::vector<int> back;
                while(st.top() != -1){
                    back.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(auto const &it : back){
                    connectToNode(st.top(), std::to_string(it));
                }
            } else{
                st.push(-1);
            }
        }
        index--;
        if(index >= 0){
            drawTreeRight(str);
        }
    }

    void drawTreeLeft(std::string &str){
        if(str[index] != '(' && str[index] != ')'){
            st.push(nodeIndex);
            addDef(std::string{str[index]});
        } else{
            if(str[index] == '('){
                st.push(-1);
            } else{
                std::vector<int> back;
                while(st.top() != -1){
                    back.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(auto const &it : back){
                    connectToNode(st.top(), std::to_string(it));
                }
            }
        }
        index++;
        if(index < str.size()){
            drawTreeLeft(str);
        }
    }

    std::string done(void){
        std::string res;
        auto decl = [&](std::pair<std::string, std::string> pp){
            res += "n" + pp.first + "[label=\"" + pp.second + "\"";
            if(std::islower(pp.second[0])){
                res += ",style=filled,fillcolor=green";
            }
            res += "]\n";
        };
        if(index < 0){
            for(auto p = declarations.rbegin(); p != declarations.rend(); ++p)
                decl(*p);
        } else{
            for(auto p = declarations.begin(); p != declarations.end(); ++p)
                decl(*p);
        }
        for(auto p : links){
            res += "n" + p.first + "->n" + p.second + "\n";
        }
        return res;
    }
};


void TreeBuilder::buildTree(std::string str){
    std::ofstream file("output.dot");
    file << "digraph name{\n";
    treeDrawer drawer;
    if(str[0] == '('){
        drawer.index = str.size() - 1;
        drawer.drawTreeRight(str);
    }
    else{
        drawer.index = 0;
        drawer.drawTreeLeft(str);
    }
    file << drawer.done() << "\n";
    file << "}";
    file.close();
    int statusGraphviz = system("dot -V >nul 2>nul");
    if (WEXITSTATUS(statusGraphviz) == 0) {
        std::string command = "dot output.dot -Tsvg > output.svg";
        system(command.c_str());
    } else {
        std::cout << "Проблема при определении Graphviz. .dot описание "
                     "изображения сгенерировано, но генерация самого "
                     "изображения требует Graphviz";
    }
}