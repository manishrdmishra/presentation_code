#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> seq = { 15, 2, 4, 5, 8, 9, 20, 3 };

// max_element example
     auto max_element_it = std::max_element(std::begin(seq), std::end(seq));
     std::cout << "max element: " << *max_element_it << "\n";

// min_element example
     auto min_element_it = std::min_element(std::begin(seq), std::end(seq));
     std::cout << "min element: " << *min_element_it << "\n";

// binary_search example
    std::vector<int> sorted_seq = {1, 2, 4, 5, 8, 9, 20};
    auto found = std::binary_search(std::begin(sorted_seq), std::end(sorted_seq), 8);
    if(found) { std::cout << "element 8 found" << "\n";}

// accumulate example
    auto sum = std::accumulate(std::begin(seq), std::end(seq), 0);
    std::cout << "summation of seq : "<< sum << "\n";

    return 0;
}
