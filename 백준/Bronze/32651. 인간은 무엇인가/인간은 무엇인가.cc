#include <iostream>
int main()
{
    int N; std::cin >> N;
    std::cout << (N<=1e5 && N%2024 == 0 ? "Yes":"No");
}