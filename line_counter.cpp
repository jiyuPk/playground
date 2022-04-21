#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

int counter(int prev_count, char c) {
    return (c != '\n' ? prev_count : prev_count + 1);
}

int count_lines(const string& filename) {

    ifstream in(filename);


    return std::accumulate(
        std::istream_iterator<char>(in >> std::noskipws),
        std::istream_iterator<char>(),
        0,
        counter
    );
}

vector<int> count_lines_in_files(const vector<string>& files) {
    vector<int> results(files.size());

    std::transform(files.cbegin(), files.cend(), results.begin(), count_lines);

    return results;
}

int main(int argc, char* argv[]) {
    auto results = count_lines_in_files({ "main.cpp" }); // write file names

    for (const auto& result : results) {
        cout << result << " line(s)\n";
    }

    return 0;
}
