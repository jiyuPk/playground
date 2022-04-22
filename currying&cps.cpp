#include <iostream>

using namespace std;

int main() {
	auto print = [](int a) {
		cout << a << endl;
	};

	auto add = [](int a, int b) {
		return a + b;
	};

	auto add_curry = [](int a) {
		return [a](int b) {
			return a + b;
		};
	};

	auto add_c = [](int a, int b, auto&& fn) {
		return fn(a + b);
	};

	auto mul_c = [](int a, int b, auto&& fn) {
		return fn(a * b);
	};

	auto add_with_10 = add_curry(10);

	cout << add_curry(10)(1) << endl;	// 11
	cout << add_with_10(1) << endl;		// 11
	
	add_c(10, 1, print);				// print 11

	int res = add(1, 10);
	cout << res << endl;					// print 11

	add_c(1,mul_c(2,3,add_curry(4)),print);	// print 11
}

