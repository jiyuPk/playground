template<typename Type>
concept iterator_available_c =
	requires {typename Type::iterator; };

template<typename Type>
concept reverse_iterator_available_c =
	requires {typename Type::reverse_iterator; };

template<typename Type> struct stl_container {
	constexpr static bool value = false;
};

template<typename Type, typename... Types, template<typename, typename...> class ContainerTemplate>
struct stl_container<ContainerTemplate<Type, Types...>> {
	constexpr static bool value = iterator_available_c< ContainerTemplate<Type, Types...>>;
};

template<typename Type>
concept stl_container_c = stl_container<Type>::value;


int main() {
	std::cout << std::boolalpha;
	std::cout << "iterator_available_c: " << iterator_available_c<std::vector<int>> << std::endl;
	std::cout << "reverse_iterator_available_c: " << reverse_iterator_available_c<std::vector<int>> << std::endl;

	std::cout << "stl_container_c<std::vector<int>>: " << stl_container_c<std::vector<int>> << std::endl;
	std::cout << "stl_container_c<std::pair<int, std::string>>: " << stl_container_c<std::pair<int, std::string>> << std::endl;
	std::cout << "stl_container_c<std::string>: " << stl_container_c<std::string> << std::endl;

	return 0;
}
