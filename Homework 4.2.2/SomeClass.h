template<typename T, std::size_t S>
class SomeClass
{
public:
	template<typename... Ts>
	SomeClass(Ts... args) : elements{args...}
	{
		static_assert(sizeof... (Ts) == S, "invalid number of arguments");
	}
};