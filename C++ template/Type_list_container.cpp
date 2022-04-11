#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
constexpr std::string type_to_string() {
	std::string name, prefix, suffix;
	
	name = __FUNCSIG__;
	prefix = "to_string<";
	size_t len = prefix.length();
	auto pos = name.find(prefix);

	name = name.substr(pos + len);
	
	return name.substr(0, name.find_last_of('>'));
}

template<typename... Types> struct type_container {};

template<typename Type>
using const_ptr_t = std::add_pointer_t < std::add_const_t<Type>>;


template<typename>
struct is_type_container : std::false_type {};

template<typename... Types>
struct is_type_container<type_container<Types...>> : std::true_type {};


template<typename Type>
concept type_container_c = is_type_container<Type>::value;

template<typename Target_char = char, typename Source_char = char>
std::basic_string<Target_char> smart_convert(const std::basic_string<Source_char>& source) {
	std::basic_string<Target_char> target;

	target.reserve(source.size());

	for (auto c : source)
		target.push_back(static_cast<Target_char>(c));

	return target;
}

template<typename Target_char_ptr = const char*, typename Source_char_ptr = const char*>
Target_char_ptr smart_convert(Source_char_ptr ptr) {
	return ptr;
}

template<typename Char_type, typename... Types>
std::basic_ostream<Char_type>& operator<<(std::basic_ostream<Char_type>&, const type_container<Types...>&);

template<typename Char_type, typename Type, typename... Types>
std::basic_ostream<Char_type>& print_type_container(std::basic_ostream<Char_type>& os,
	const type_container<Type, Types...>& tc) {
	using char_ptr = const_ptr_t<Char_type>;
	
	if constexpr(sizeof...(Types) == 0) {
		if constexpr(type_container_c<Type>)
			os << Type{};
		else
			os << smart_convert<Char_type>(type_to_string<Type>());
		
		return os;
	}
	else {
		if constexpr (type_container_c<Type>)
			os << Type{};
		else
			os << smart_convert<Char_type>(type_to_string<Type>());
		
		os << smart_convert<char_ptr>(", ");
		return print_type_container(os, type_container<Types...>{});
	}
}

template<typename Char_type, typename... Types>
std::basic_ostream<Char_type>& operator<<(std::basic_ostream<Char_type>& os, const type_container<Types...>& tc) {
	using char_ptr = const_ptr_t<Char_type>;

	if constexpr(sizeof...(Types) == 0) {
		os << smart_convert<char_ptr>("< >");
		return os;
	}
	else {
		os  << smart_convert<char_ptr>("< ");
		print_type_container(os, tc);
		os << smart_convert<char_ptr>(" >");
		return os;
	}
}

int main() {
	using sub_list = type_container<int, char>;
	using type_list = type_container<sub_list, short, double>;

	std::cout << type_list{} << std::endl;
	
	return 0;
}
