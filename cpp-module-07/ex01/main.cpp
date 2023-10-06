#include "iter.hpp"

int main()
{
    std::cout << "___________________Int___________________" << std::endl;
    int i_arr[10] = {1, 2, 3, 4, 5, 6, 5000, -999, 0, 1000000};

    iter(i_arr, 10, &print_element);

    std::cout << "__________________Double_________________" << std::endl;
    double d_arr[10] = {1.0, 2.24, 3.1, 4.99, 5.324234, 6.98970989, 50000000000000, -999, 0, 1000000};

    iter(d_arr, 10, &print_element);

    std::cout << "__________________Float__________________" << std::endl;
    float f_arr[10] = { 1.02f, 2.24f, 3.1f, 4.99f, 5.324234f, 6.98f, 50000.12f, -999.1f, 0.123f, 1000.9f};

    iter(f_arr, 10, &print_element);

    std::cout << "_________________String__________________" << std::endl;
    std::string s_arr[5] = { "string1", "string2", "string3", "string4", "string5"};
    
    iter(s_arr, 5, &print_element);

    std::cout << std::endl << "String with different size" << std::endl << std::endl;
    std::cout << "size = 1" << std::endl << std::endl;
    iter(s_arr, 1, &print_element);
    std::cout << std::endl << "size = 3" << std::endl << std::endl;
    iter(s_arr, 3, &print_element);
    std::cout << std::endl << "size = 4" << std::endl << std::endl;
    iter(s_arr, 4, &print_element);


    std::cout << "__________________Bool___________________" << std::endl;
    bool b_arr[2] = { true, false};
    
    iter(b_arr, 2, &print_element);

}
