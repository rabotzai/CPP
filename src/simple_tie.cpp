#include <string>
#include <tuple>
#include <cassert>
auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::make_tuple(
        name, secondName, age, department);
}

class CustomTie
{
private:
    std::string &name;
    std::string &secondName;
    std::size_t &age;
    std::string &department;

public:
    CustomTie(std::string &name,
              std::string &secondName,
              std::size_t &age,
              std::string &department)
        : name(name), secondName(secondName), age(age), department(department) {}
    CustomTie& operator=(const std::tuple<std::string, std::string, std::size_t, std::string>& person) {
        name = std::get<0>(person);
        secondName = std::get<1>(person);
        age = std::get<2>(person);
        department = std::get<3>(person);

        return *this;
    }
};

int main(int argc, char *argv[])
{
    std::string name, secondName, department;
    std::size_t age;
    CustomTie(name, secondName, age, department) = getPerson();
    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    return 0;
}