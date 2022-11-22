#pragma once
#include <iostream>

std::string get_function();

double* funcArray(double D, int i, std::string function);

int string_size(std::string str);

int find_char(std::string str, char character);

std::string extract_index_b(std::string function);

std::string extract_index_a(std::string function);

double get_a_quadratic(std::string function);

double get_b_quadratic(std::string function);

double get_c_quadratic(std::string function);

double calculate_function(std::string function, double x);

double get_x(std::string function);

double get_x_zero_positive(std::string function);

double get_x_zero_negative(std::string function);

double calculate_hyperbola_function(std::string function, double x);

void run();