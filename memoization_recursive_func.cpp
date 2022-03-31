#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;
using llu = long long unsigned;

class null_param {};

template <typename Sig, typename F>
class memoize_helper;

template <typename Result, typename... Args, typename F>
class memoize_helper<Result(Args...), F> {
public:
	// Constructors
	template <typename Function>
	memoize_helper(Function&& f, null_param)
		: f(f) {}

	memoize_helper(const memoize_helper& other)
		: f(other.f) {}

	template <typename... InnerArgs>
	Result operator()(InnerArgs&&... args) const {
		const auto args_tuple{ make_tuple(args...) };
		const auto cached{ cache.find(args_tuple) };

		if (cached != cache.end()) {
			return cached->second;
		}
		else {
			auto&& result{ f(*this,forward<InnerArgs>(args)...) };
			cache[args_tuple] = result;
			return result;
		}
	}
private:
	using function_type = F;
	using args_tuple_type = tuple<decay_t<Args>...>;

	function_type f;

	mutable map<args_tuple_type, Result> cache;
};

template <typename Sig, typename F>
memoize_helper<Sig, decay_t<F>>
make_memoized(F&& f) {
	return { forward<F>(f), null_param{} };
}


template <typename F>
llu fib(F&& fib_memo, llu n)
{
	return n == 0 ? 0
		: n == 1 ? 1
		: fib_memo(n - 1) + fib_memo(n - 2);
}

int main() {
	llu i{};
	cin >> i;

	auto fib_memo{ make_memoized<llu(llu)>(
			[](auto& fib, llu n) {
				return n == 0 ? 0
					 : n == 1 ? 1
					 : fib(n - 1) + fib(n - 2);
			}) };

	cout << fib_memo(i) << endl;
}