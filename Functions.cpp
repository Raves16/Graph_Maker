#include <iostream>
#include <string>
#include "Functions.hpp"
#include <cmath>
#include "Draw.hpp"

std::string get_function()
{
	std::string function;
	std::cout << "f(x): ";
	std::cin >> function;
	return function;
}

double* funcArray(double D, int i, std::string function)
{
	double* arr = new double[i];

	if (D > 0)
	{
		arr[0] = get_x_zero_negative(function) - 6;
		arr[1] = get_x_zero_negative(function) - 5;
		arr[2] = get_x_zero_negative(function) - 4;
		arr[3] = get_x_zero_negative(function) - 3;
		arr[4] = get_x_zero_negative(function) - 2;
		arr[5] = get_x_zero_negative(function) - 1;
		arr[6] = get_x_zero_negative(function);
		arr[7] = get_x_zero_negative(function) / 2;
		arr[8] = get_x(function);
		arr[9] = get_x_zero_positive(function) / 2;
		arr[10] = get_x_zero_positive(function);
		arr[11] = get_x_zero_positive(function) + 1;
		arr[12] = get_x_zero_positive(function) + 2;
		arr[13] = get_x_zero_positive(function) + 3;
		arr[14] = get_x_zero_positive(function) + 4;
		arr[15] = get_x_zero_positive(function) + 5;
		arr[16] = get_x_zero_positive(function) + 6;
	}
	else if (D == 0)
	{
		arr[0] = get_x_zero_negative(function) - 6;
		arr[1] = get_x_zero_negative(function) - 5;
		arr[2] = get_x_zero_negative(function) - 4;
		arr[3] = get_x_zero_negative(function) - 3;
		arr[4] = get_x_zero_negative(function) - 2;
		arr[5] = get_x_zero_negative(function) - 1;
		arr[6] = get_x_zero_negative(function);
		arr[7] = get_x_zero_negative(function) / 2;
		arr[8] = get_x(function);
		arr[9] = get_x_zero_positive(function) / 2;
		arr[10] = get_x_zero_positive(function);
		arr[11] = get_x_zero_positive(function) + 1;
		arr[12] = get_x_zero_positive(function) + 2;
		arr[13] = get_x_zero_positive(function) + 3;
		arr[14] = get_x_zero_positive(function) + 4;
		arr[15] = get_x_zero_positive(function) + 5;
		arr[16] = get_x_zero_positive(function) + 6;
	}
	else
	{
		arr[0] = get_x(function) + 8;
		arr[1] = get_x(function) + 7;
		arr[2] = get_x(function) + 6;
		arr[3] = get_x(function) + 5;
		arr[4] = get_x(function) + 4;
		arr[5] = get_x(function) + 3;
		arr[6] = get_x(function) + 2;
		arr[7] = get_x(function) + 1;
		arr[8] = get_x(function);
		arr[9] = get_x(function) - 1;
		arr[10] = get_x(function) - 2;
		arr[11] = get_x(function) - 3;
		arr[12] = get_x(function) - 4;
		arr[13] = get_x(function) - 5;
		arr[14] = get_x(function) - 6;
		arr[15] = get_x(function) - 7;
		arr[16] = get_x(function) - 8;
	}
	return arr;
}

int string_size(std::string str)
{
	int i = 0;
	int count = -1;
	while (str[i] != NULL)
	{
		i++;
	}
	if (i == 0)
	{
		return -1;
	}
	count = i;
	return count;
}

int find_char(std::string str, char character)
{
	int index = -1;
	for (int i = 0; i < string_size(str); i++)
	{
		if (str[i] == character)
		{
			index = i;
			break;
		}
	}
	return index;
}

std::string extract_index_b(std::string function)
{
	std::string new_function = function.substr(find_char(function, '^')+2, string_size(function));
	int size = find_char(new_function, 'x');
	std::string index_b = function.substr(find_char(function, '^')+2, size);
	return index_b;
}

std::string extract_index_a(std::string function)
{
	std::string index_a = function.substr(0, find_char(function, 'x'));
	return index_a;
}

double get_a_quadratic(std::string function)
{
	double a;
	std::string index_a;
	if (find_char(function, 'x') == 0)
	{
		a = 1;
	}
	else if (find_char(function, '-') == 0 && find_char(function, 'x') == 1)
	{
		a = -1;
	}
	else
	{
		index_a = extract_index_a(function);
		a = std::stoi(index_a);
	}
	return a;
}

double get_b_quadratic(std::string function)
{
	double b;
	std::string index_b;
	int index_one = find_char(function, '^');
	std::string new_function = function.substr(find_char(function, '^') + 2, string_size(function));

	if (function[index_one + 2] == '-' && function[index_one + 3] == 'x')
	{
		b = -1;
	}
	else if (function[index_one + 2] == '+' && function[index_one + 3] == 'x')
	{
		b = 1;
	}
	else if (find_char(new_function, 'x') == -1)
	{
		b = 0;
	}
	else
	{
		index_b = extract_index_b(function);
		b = std::stoi(index_b);
	}
	return b;
}

double get_c_quadratic(std::string function)
{
	double c;
	std::string index_c;
	std::string new_function = function.substr(find_char(function, '^') + 2, string_size(function));
	if (new_function[find_char(new_function, 'x') + 1] == NULL)
	{
		c = 0;
	}
	else if (find_char(new_function, 'x') == -1)
	{
		index_c = new_function;
		c = std::stoi(index_c);
	}
	else
	{
		index_c = new_function.substr(find_char(new_function, 'x') + 1, string_size(new_function));
		c = std::stoi(index_c);
	}
	return c;
}

double calculate_function(std::string function, double x)
{	
	double a = get_a_quadratic(function);
	double b = get_b_quadratic(function);
	double c = get_c_quadratic(function);

	double solution = a * pow(x, 2) + b * x + c;

	return solution;
}

double get_x(std::string function)
{
	double a = get_a_quadratic(function);
	double b = get_b_quadratic(function);
	double c = get_c_quadratic(function);

	double x = -b / (2 * a);

	return x;
}

double get_x_zero_positive(std::string function)
{
	double a = get_a_quadratic(function);
	double b = get_b_quadratic(function);
	double c = get_c_quadratic(function);
	double x;

	if (b != 0 && c != 0)
	{
		x = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	}
	else if (b == 0 && c == 0)
	{
		x = 0;
	}
	else if (b != 0 && c == 0)
	{
		x = -b / a;
	}
	else if (b == 0 && c != 0)
	{
		x = sqrt(-c / a);
	}
	std::cout << x << std::endl;
	return x;
}

double get_x_zero_negative(std::string function)
{
	double a = get_a_quadratic(function);
	double b = get_b_quadratic(function);
	double c = get_c_quadratic(function);

	double x;

	if (b != 0 && c != 0)
	{
		x = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	}
	else if (b == 0 && c == 0)
	{
		x = 0;
	}
	else if (b != 0 && c == 0)
	{
		x = 0;
	}
	else if (b == 0 && c != 0)
	{
		x = -sqrt(-c / a);
	}
	std::cout << x << std::endl;
	return x;
}

double get_a_hyperbola(std::string function)
{
	std::string index_a = function.substr(0, find_char(function, ':'));
	double a = std::stoi(index_a);
	return a;
}

double calculate_hyperbola_function(std::string function, double x)
{
	double a = get_a_hyperbola(function);

	double solution = a / x;
	std::cout << solution << std::endl;
	return solution;
}

void run()
{
	std::string function = get_function();
	if (find_char(function, '^') != -1 && find_char(function, 'x') != -1)
	{
		draw_quadratic_function(function);
	}
	else if (find_char(function, '/') != -1 && find_char(function, 'x') != -1)
	{
		draw_hyperbola_function(function);
	}
}