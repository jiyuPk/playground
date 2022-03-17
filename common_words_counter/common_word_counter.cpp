#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;

void print_common_words(const string &filename)
{

    [](vector<pair<int, string>> list) { // print
        ranges::for_each(list, [](auto iter)
                         { cout << iter.first << " " << iter.second << endl; });
    }([](vector<pair<int, string>> list) { // sort by frequency
        ranges::sort(list);
        return list;
    }([](unordered_map<string, unsigned int> list) { // reverse map
        vector<pair<int, string>> result(list.size());

        ranges::transform(list, result.begin(),
                          [](const pair<const string, int> &p)
                          {
                              return make_pair(p.second, p.first);
                          });
        return result;

    }([](const vector<string> &list) { // count words
        unordered_map<string, unsigned int> result;

        for (const auto &element : list)
        {
            result[element]++;
        }
        return result;

    }([](const string &filename) { // extract words
        string text;
        std::ifstream in(filename);
        string s((std::istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

        erase(s, ',');
        erase(s, '.');
        erase(s, '!');
        erase(s, '"');
        erase(s, '*');
        erase(s, ':');

        ranges::transform(std::as_const(s), s.begin(), [](char c)
                          { return tolower(c); });

        istringstream ss(s);

        int ss_count = 0;

        vector<string> result;

        while (ss >> s)
        {
            result.push_back(s);
            ss_count++;
        }

        return result;
    }(filename)))));
}

auto main() -> int
{
    print_common_words("text.txt");

    return 0;
}
