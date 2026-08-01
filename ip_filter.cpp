
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> result;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);

    while (stop != std::string::npos)
    {
        result.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    result.push_back(str.substr(start));

    return result;
}

bool comparator(const std::vector<std::string>& l,
                const std::vector<std::string>& r)
{
    for (std::size_t i = 0; i < l.size(); ++i)
    {
        int left = std::stoi(l[i]);
        int right = std::stoi(r[i]);

        if (left > right)
            return true;

        if (left < right)
            return false;
    }

    return false;
}

void print_ip(const std::vector<std::string>& ip)
{
    for (std::size_t i = 0; i < ip.size(); ++i)
    {
        if (i != 0)
            std::cout << '.';

        std::cout << ip[i];
    }

    std::cout << '\n';
}

int main()
{
    try
    {
        std::vector<std::vector<std::string>> ip_pool;

        // Read IP addresses
        for (std::string line; std::getline(std::cin, line);)
        {
            if (line.empty())
                continue;

            std::vector<std::string> fields = split(line, '\t');

            ip_pool.push_back(split(fields.at(0), '.'));
        }

        // Reverse lexicographical sort
        std::sort(ip_pool.begin(), ip_pool.end(), comparator);

        // 1. Print all IP addresses
        for (const auto& ip : ip_pool)
        {
            print_ip(ip);
        }

        // 2. Print IP addresses with first byte == 1
        for (const auto& ip : ip_pool)
        {
            if (std::stoi(ip[0]) == 1)
            {
                print_ip(ip);
            }
        }

        // 3. Print IP addresses with first byte == 46
        //    and second byte == 70
        for (const auto& ip : ip_pool)
        {
            if (std::stoi(ip[0]) == 46 &&
                std::stoi(ip[1]) == 70)
            {
                print_ip(ip);
            }
        }

        // 4. Print IP addresses where any byte == 46
        for (const auto& ip : ip_pool)
        {
            for (const auto& part : ip)
            {
                if (std::stoi(part) == 46)
                {
                    print_ip(ip);
                    break;
                }
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}