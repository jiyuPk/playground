#include <format>
#include <source_location>

using namespace std;

string file_log(
    const source_location location =
        source_location::current())
{
    return format("file: {}({}:{}) `{}` \n", location.file_name(),
                  location.line(), location.column(), location.function_name());
}

int main() {}