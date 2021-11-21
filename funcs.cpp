//https://contest.yandex.ru/contest/27665/problems/B/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::map<std::string, unsigned int> dict;
    std::string word;
    std::vector<unsigned int> ans;
    while (input >> word){
        ans.push_back(dict[word]);
        dict[word] += 1;
    }

    std::copy(ans.begin(), ans.end(),
              std::ostream_iterator<unsigned int>(output, " "));
}
