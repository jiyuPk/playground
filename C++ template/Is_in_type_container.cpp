template<typename P>
struct type_in_container<P> {
	static constexpr bool value = false;
};

template<typename P, non_type_container_c Type, typename... Tails>
struct type_in_container<P, Type, Tails...> {
	static constexpr bool value = std::same_as<P, Type> || type_in_container<P, Tails...>::value;
};

template<typename P, typename... Types, typename... Tails>
struct type_in_container<P, type_container<Types...>, Tails...> {
	static constexpr bool value = type_in_container<P, Types...>::value || type_in_container<P, Tails...>::value;
};

template<typename P, typename...  Types>
concept is_in_type_container_c = type_in_container<P, Types...>::value;

int main() {
	std::cout << std::boolalpha;
	
	std::cout << "Is int in type_container<short, char, double>? "
		<< is_in_type_container_c<int, short, char, double> << std::endl;
	
	std::cout << "Is int in type_container<int, char, double>? "
		<< is_in_type_container_c<int, type_container<int, char, double>> << std::endl;

	return 0;
}
