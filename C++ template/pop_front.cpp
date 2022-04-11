template<typename...> struct pop_front_t;

template<>
struct pop_front_t<> {
	using type = type_container<>;
};

template<typename Type, typename... Types>
struct pop_front_t<Type, Types...> {
	using type = type_container<Types...>;
};

template<typename... Types>
struct pop_front_t<type_container<Types...>> {
	using type = typename pop_front_t<Types...>::type;
};

template<typename... Types>
using pop_front = typename pop_front_t<Types...>::type;

int main() {
	std::cout << std::boolalpha;
	
	using type_list = type_container<int, double, char, float>;

	std::cout << " Before pop front: " << type_list{} << std::endl;

	using pop_front_result = pop_front<type_list>;

	std::cout << " After pop front: " << pop_front_result{} << std::endl;

	return 0;
}
