#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

struct CustomAlphaCmp
{
    int table[1 << CHAR_BIT];
    CustomAlphaCmp(const std::string& alpha)
    {
        std::fill(std::begin(table), std::end(table), INT_MAX);
        int value = 0;
        for (auto x : alpha)
            table[ static_cast<unsigned char>(x) ] = ++value;
    }

    bool operator()(const std::string& a, const std::string& b)
    {
        auto lhs = a.begin();
        auto rhs = b.begin();

        for (; lhs != a.end() && rhs != b.end(); ++lhs,++rhs)
        {
            int lhs_val = table[static_cast<unsigned char>(*lhs)];
            int rhs_val = table[static_cast<unsigned char>(*rhs)];

            if (lhs_val != rhs_val)
                return lhs_val < rhs_val;
        }

        return (rhs != b.end());
    }
};

int main()
{
    std::string alpha = "bBAadcCDTt";
    std::string ar[] = { "Bat", "bat", "X", "atb", "bBb", "bbb", "B",
                         "bat", "aaa", "Y", "Cat", "CaT", "Bat", "A" };

    std::sort(std::begin(ar), std::end(ar), CustomAlphaCmp(alpha));

    for (auto const& s : ar)
        std::cout << s << '\n';
}