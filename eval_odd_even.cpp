
int main() {
	int i;
	cin >> i;

	if (i & 1)
		cout << "odd";
	else if (~i & 1)
		cout << "even";

	return 0;
}