#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cmath>
#include <limits>
#include <limits.h>
#include <string>
#include <string.h>

class Convert
{

    private:

        char *      input;
        char        c_value;
        int         i_value;
        double      d_value;
        float       f_value;
        int         type;
        bool        int_imp;
        bool        fl_imp;

    public:

        void converter();
        void print();
        void print_char();
        void print_int();
        void print_float();
        void print_double();
        void selectType();
        void getInputValue();

        void int_case();
        
        Convert(char * input);
        Convert(const Convert &Convert);
        Convert& operator= (const Convert &rhs);
        ~Convert();

};

#endif