//
//  main.cpp
//  Task-10.01 Smart pointer
//
//  Created by Маргарет  on 26.02.2024.
//

#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr <tridiagonal_matrix> clone() {
        auto ptr = std::make_unique <tridiagonal_matrix> (
                                                          m_down,
                                                          m_upper,
                                                          m_middle
                                                          );
        return ptr;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    
    std::cout << "Check unique_ptr matrix clone:\n";
    auto it_begin_cl = matrix_clone->m_down.begin();
    auto it_end_cl = matrix_clone->m_down.end();
    while(it_begin_cl!= it_end_cl) {
        std::cout << *it_begin_cl << " ";
        ++it_begin_cl;
    }
    std::cout << "\n";
    std::cout << "Check unique_ptr matrix:\n";
    auto it_begin = matrix->m_down.begin();
    auto it_end = matrix->m_down.end();
    while(it_begin!= it_end) {
        std::cout << *it_begin << " ";
        ++it_begin;
    }
    

    return 0;
}
