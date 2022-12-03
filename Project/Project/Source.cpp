#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

enum type { numbers, text, default_column };

class column {
	const string column_name = "";
	int size = 0;
	type column_type = default_column;
	char* default_char_value = nullptr;
	float* default_float_value = nullptr;
	float** numbers_column = nullptr;
	char** text_column = nullptr;

public:
	//seters-------------------------------------------------------------------------------

	void setType(type column_type) {
		if ((column_type != text) || (column_type != numbers))
			throw "Invlid Column Type";
		this->column_type = column_type;
	}

	//default value for a char
	void setDefault_Value(char* default_value) {
		if (default_value == nullptr) {
			throw "Invalid Default Value";
		}
		if (this->default_char_value != nullptr)
			delete[] this->default_char_value;
		this->default_char_value = new char[strlen(default_char_value) + 1];
		strcpy(this->default_char_value, default_char_value);
	}

	//default value for a float
	void setDefault_Value(float* default_float_value) {
		if (default_float_value == nullptr) {
			throw "Invalid Default Value";
		}
		if (this->default_float_value != nullptr)
			delete[] this->default_float_value;
		this->default_float_value = new float;
	}



	//geter------------------------------------------------------------------------------------------

	//default value for a char
	char* getDefault_char_Value() {
		return this->default_char_value;
	}

	//default value for a float
	float* getDefault_float_Value() {
		return this->default_float_value;
	}

	type getType() {
		return this->column_type;
	}

	//functions-----------------------------------------------------------------------------------------
	float** addDefault_Value(float** f, int size, float* default_value) {
		for (int i = 0; i < size; i++) {
			f[i] = default_value;
		}
		return f;
	}

	char** addDefault_Value(char** c, int size, char* default_value) {
		for (int i = 0; i < size; i++) {
			c[i] = default_value;
		}
		return c;
	}

	//constructor without default value-----------------------------------------------------------------
	column(string column_name, type column_type, int size) :column_name(column_name), size(size) {
		this->setType(column_type);
	}

	//Constructor with default value of a char* --------------------------------------------------------------------
	column(string column_name, type column_type, int size, char* default_value) :column_name(column_name), size(size) {
		this->setType(column_type);
		this->setDefault_Value(default_value);

		if (column_type == text) {
			this->text_column = new char* [size];
			addDefault_Value(text_column, size, default_value);
		}
	}

	//Constructor with default value of a float*---------------------------------------------------------
	column(string column_name, type column_type, int size, float* default_float_value) :column_name(column_name), size(size) {
		this->setType(column_type);
		this->setDefault_Value(default_float_value);

		if (column_type == numbers) {
			this->numbers_column = new float* [size];
			addDefault_Value(numbers_column, size, default_float_value);
		}
	}

	//destructor-------------------------------------------------------------------------------------------
	~column() {
		delete[] this->numbers_column;
		delete[] this->text_column;
		delete[] this->default_char_value;
		delete[] this->default_float_value;
	}
};



int main() {
	float* x;
	char* y;
	column tra("nume", text, 12, x);
	column bla("stoc", numbers, 12, y);
	//column_1_name,type,size, default_value
	//create table pateu ((nume,name, 12,bucovina),(stoc,number,10,0))
}