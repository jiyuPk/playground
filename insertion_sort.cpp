// Insertion sort with fold

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Insert T in proper position
template <typename T>
vector<T> ascending_sort(vector<T> vec, T i)
{
    // Insert first number
    if (vec.empty())
    {
        vec.push_back(i);
        return vec;
    }

    // find proper position for i
    bool inserted = false;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        auto val = *iter;
        if (*iter >= i)
        {
            vec.insert(iter, i);
            inserted = true;
            break;
        }
    }

    // if i is biggest number, push back
    if (inserted != true)
    {
        vec.push_back(i);
    }

    return vec;
}

template <typename T>
vector<T> insertion_sort(vector<T> vec)
{
    vector<T> result;
    result = accumulate(
        vec.cbegin(),
        vec.cend(),
        result,
        ascending_sort<T>);
    return result;
}

vector<int> get_input()
{
    vector<int> vec;

    int input_amount;
    cin >> input_amount;
    vec.resize(input_amount);
    for (int i = 0; i < input_amount; i++)
    {
        int input;
        cin >> input;
        vec[i] = input;
    }

    return vec;
}
int main()
{
    vector<int> vec = get_input();

    auto result = insertion_sort(vec);

    for (auto elem : result)
    {
        cout << elem << endl;
    }
}