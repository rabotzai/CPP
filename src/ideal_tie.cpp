#include <string>
#include <tuple>
#include <cassert>
#include <utility>

auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::make_tuple(
        name, secondName, age, department);
}

template<typename... Args>
class CustomTie
{
    std::tuple<Args&...> refs;

    template<typename Tuple, std::size_t... I>
    void assign(const Tuple& t, std::index_sequence<I...>)
    {
        ((std::get<I>(refs) = std::get<I>(t)), ...);
    }

public:
    explicit CustomTie(Args&... args)
        : refs(args...)
    {
    }

    template<typename... Ts>
    CustomTie& operator=(const std::tuple<Ts...>& t)
    {
        static_assert(sizeof...(Args) == sizeof...(Ts),
                      "Tuple sizes must match");

        assign(t, std::index_sequence_for<Args...>{});
        return *this;
    }
};

template<typename... Args>
CustomTie<Args...> custom_tie(Args&... args)
{
    return CustomTie<Args...>(args...);
}

int main(int argc, char *argv[])
{
    std::string name, secondName, department;
    std::size_t age;
    custom_tie(name, secondName, age, department) = getPerson();
    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    return 0;
}