#ifndef _INC_TREEBUILDER_HPP
#define _INC_TREEBUILDER_HPP
#include <string>

#include "GrammaScanner.hpp"

class TreeBuilder{
    public:
    std::string buildTree(GrammaScannerCommon *gs_ptr, Gramma g, std::vector<ScanResult> &tsr);
    std::string buildTree(GrammaScannerLeft *gs_ptr, Gramma g, std::vector<ScanResult> &tsr);
    std::string buildTree(GrammaScannerRight *gs_ptr, Gramma g, std::vector<ScanResult> &tsr);
    void buildTree(std::string str);

};

#endif