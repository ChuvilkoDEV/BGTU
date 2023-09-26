#include <iostream>
#include "vector"
#include "cstdlib"
#include "cmath"
#include <iomanip>

struct simb {
  public:
  simb(std::string Liter) {
    liter = Liter;
    ratio = 0;
  }

  simb() {}

  std::string code;
  std::string liter;
  int ratio;
};

struct treeSimb {
  public:
  treeSimb(simb *a) {
    simb = a;
    code = "";
    ratio = a->ratio;
  }

  treeSimb() {

  }


  bool isIncluded = false;
  int ratio;
  simb *simb = nullptr;
  treeSimb *left = nullptr;
  treeSimb *right = nullptr;
  std::string code;
};

std::vector<simb> breakToParts(std::string &massage, int size) {
  std::vector<simb> res;
  for (int i = 0; i < massage.size(); i += size) {
    std::string latter;

    for (int j = 0; j < size; ++j)
      latter.push_back(massage[j + i]);
    res.push_back(simb(latter));
  }

  return res;
}

bool isContain(std::vector<simb> *simbs, std::string liter, int *i) {
  for (*i; *i < simbs->size(); (*i)++)
    if (simbs->at(*i).liter == liter)
      return true;
  return false;
}

void sort(std::vector<simb> *simbs) {
  for (int i = 1; i < simbs->size(); ++i) {
    simb t = simbs->at(i);
    int j = i - 1;
    while (j > 0 && simbs->at(j).ratio < t.ratio) {
      simbs->at(j + 1) = simbs->at(j);
      j--;
    }

    simbs->at(j + 1) = t;
  }
}

std::vector<simb> collapse(std::vector<simb> simbs) {
  std::vector<simb> res;
  for (int i = 0; i < simbs.size(); ++i) {
    int j = 0;
    if (isContain(&res, simbs[i].liter, &j))
      res[j].ratio += 1;
    else {
      res.push_back(simb(simbs[i].liter));
      res.back().ratio = 1;
    }
  }

  sort(&res);

  return res;
}

int getSumCountOfMet(simb *letters, int size) {
  int metCount = 0;
  for (int i = 0; i < size; ++i)
    metCount += letters[i].ratio;

  return metCount;
}


void _encrypt(simb *begin, int sizeOfPart, std::string code) {
  if (sizeOfPart == 1) {
    begin[0].code = code;
    return;
  }

  int count = getSumCountOfMet(begin, sizeOfPart);
  int leftCount = 0;
  int partitionIndex = -1;

  while (leftCount < count) {
    partitionIndex++;
    leftCount += begin[partitionIndex].ratio;
    count -= begin[partitionIndex].ratio;
  }

  code.push_back('0');
  _encrypt(begin, partitionIndex + 1, code);
  code.pop_back();
  code.push_back('1');
  _encrypt(&begin[partitionIndex + 1], sizeOfPart - partitionIndex - 1, code);
}

void sort(std::vector<simb> &letters) {
  for (int i = 1; i < letters.size(); ++i) {
    simb t = letters[i];
    int j = i;
    while (j > 0 && t.ratio > letters[j - 1].ratio) {
      letters[j] = letters[j - 1];
      j--;
    }
    letters[j] = t;
  }
}


std::vector<simb> encrypt(std::vector<simb> &massage) {
  sort(massage);

  std::string code = "";
  _encrypt(&massage[0], massage.size(), code);

  return massage;
}

void writeCode(treeSimb *tree, std::string code) {
  tree->code = code;

  if (tree->left != nullptr) {
    std::string newCode = tree->code;
    newCode.push_back('0');
    writeCode(tree->left, newCode);
    if (tree->right != nullptr) {
      newCode.pop_back();
      newCode.push_back('1');
      writeCode(tree->right, newCode);
    }
  } else
    tree->simb->code = code;
}

int getMinI(std::vector<treeSimb> &tree) {
  int minI = -1;
  for (int i = 0; i < tree.size(); ++i)
    if (!tree[i].isIncluded && (minI == -1 || tree[i].ratio < tree[minI].ratio))
      minI = i;

  return minI;
}

void encryptByHoffman(std::vector<simb> &massage) {
  sort(massage);
  std::vector<treeSimb> tree;
  for (int i = 0; i < massage.size(); ++i)
    tree.push_back(treeSimb(&massage[massage.size() - i - 1]));

  int size = tree.size();
  while (size != 1) {
    int i = getMinI(tree);
    tree[i].isIncluded = true;

    int k = getMinI(tree);
    tree[k].isIncluded = true;

    tree.push_back(treeSimb());
    tree[tree.size() - 1].left = &tree[i];
    if (k != -1)
      tree[tree.size() - 1].right = &tree[k];
    else
      tree[tree.size() - 1].right = nullptr;
    tree[tree.size() - 1].ratio = tree[i].ratio + tree[k].ratio;
    size--;
  }

  writeCode(&tree[tree.size() - 1], "");
}

void printCodedMassage(std::vector<simb> &text, std::vector<simb> &alp) {
  for (int i = 0; i < text.size(); ++i) {
    int j = 0;
    while (alp[j].liter != text[i].liter)
      j++;

    std::cout << alp[j].code;
  }
}

std::vector<simb> createAlp() {
  std::cout << "input size of alp: ";
  int size;
  std::cin >> size;

  std::vector<simb> alp;

  for (int i = 0; i < size; ++i) {
    simb sb;
    std::string s;
    std::cin >> s;

    int j = 0;
    std::string liter;
    while (s[j] != '-') {
      liter.push_back(s[j]);
      j++;
    }
    sb.liter = liter;
    j++;
    liter = "";
    while (s[j] != '-') {
      liter.push_back(s[j]);
      j++;
    }
    sb.code = liter;
    j++;
    int n = 0;
    while (j < s.size()) {
      n += s[j] - '0';
      j++;
    }
    sb.ratio = n;

    alp.push_back(sb);
  }

  return alp;
}

void decodeMessage(std::string &massage, std::vector<simb> &alp) {
  int iStart = 0;
  int iEnd = 0;

  std::string liter;
  while (iStart < massage.size() - 1) {
    liter.push_back(massage[iEnd]);

    int i = -1;
    bool isFound = false;
    while (i != alp.size() - 1 && !isFound) {
      i++;
      if (liter == alp[i].code)
        isFound = true;
    }

    iEnd++;

    if (isFound) {
      std::cout << alp[i].liter;
      liter = "";
      iStart = iEnd;
    }
  }
}

#define NNN 8

int main() {
  std::cout << "input massage: ";
  std::string massage;
  char c;
  do {
    c = getchar();
    massage.push_back(c);
  } while (c != '\n');

  massage.pop_back();

//    std::cout << "input alph:";
    std::vector<simb> alp = createAlp();
//
//
//
//    decodeMessage(massage, alp);
//
//    for (int i = 0; i < massage.size(); ++i) {
//        std::cout << massage[i];
//    }
//
//    std::cout <<"\n=======\n";

  std::vector<simb> res = breakToParts(massage, NNN);
  std::vector<simb> massageToPrint = res;
  res = collapse(res);
  res = encrypt(res);


  std::cout << "Shenon\n";

  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i].liter << " |" << std::setprecision(NNN * 2)
              << std::setw(NNN * 2) << res[i].code << " |"
              << std::setprecision(4) << std::setw(4)
              << res[i].ratio
              << '\n';
  }

  std::cout << "hoffman\n";

  res = breakToParts(massage, NNN);
  res = collapse(res);
  encryptByHoffman(res);

//        std::cout <<'\n';
//    printCodedMassage(massageToPrint, res);
//    std::cout << '\n';
//
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i].liter << " |" << std::setprecision(NNN * 2)
              << std::setw(NNN * 2) << res[i].code << " |"
              << std::setprecision(4) << std::setw(4)
              << res[i].ratio << '\n';
  }


}

