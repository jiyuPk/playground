template <typename... LTypes>
constexpr auto fn_pop_back(type_container<LTypes...> left, type_container< > right) {
	return left;
}

template <typename... LTypes, typename Head>
constexpr auto fn_pop_back(type_container<LTypes...> left, type_container<Head> right) {
	return left;
}

template <typename... LTypes, typename First, typename Second, typename... Tails>
constexpr auto fn_pop_back(type_container<LTypes...> left, type_container<First, Second, Tails...> right) {
	return fn_pop_back(type_container<LTypes..., First>{}, type_container<Second, Tails...>{});
}

template<typename... Types> struct pop_back_t;

template<>
struct pop_back_t<> {
	using type = type_container<>;
};

template<non_type_container_c Type, non_type_container_c... Types>
struct pop_back_t<Type, Types...> {
	using type = decltype(fn_pop_back(type_container<>{}, type_container<Type, Types...>{}));
};

template<typename... Types>
struct pop_back_t<type_container<Types...>> {
	using type = decltype(fn_pop_back(type_container<>{}, type_container<Types...>{}));
};

template<typename... Types>
using pop_back = typename pop_back_t<Types...>::type;

int main() {
	using type_list = type_container<int, long, char, short>;

	std::cout << "Before Pop Back: " << type_list{} << std::endl;

	using after_pop_back = pop_back< type_list  >;

	std::cout << "After Pop Back: " << after_pop_back{} << std::endl;

	return 0;
}