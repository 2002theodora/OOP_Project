#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

enum type { number, name, default_column };

class column {
	char* name = nullptr;
	int noColumns = 0;
	int size = 0;
	type column_type = default_column;

public:

	const static int MIN_NAME_SIZE = 2;
	const static int MIN_SIZE = 0;
	const static int MIN_NOCOLUMNS = 0;

	void setName(const char* name) {
		if (strlen(name) < column::MIN_NAME_SIZE) {
			throw "Invalid name";
		}
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setSize(int size) {
		if (size < column::MIN_SIZE) {
			throw "Invalid Size";
		}
		this->size = size;
	}

	void setNoColumns(int noColumns) {
		if (noColumns < column::MIN_NOCOLUMNS) {
			throw "Invalid Number of Columns";
		}
		this->noColumns = noColumns;
	}

	void setType(type column_type) {
		if (column_type == default_column)
			throw "Invlid Column Type";
		this->column_type = column_type;
	}

	char* getName() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy(nameCopy, this->name);
		return nameCopy;
	}

	int getNoColumns() {
		return this->noColumns;
	}

	int getSize() {
		return this->size;
	}

	type getType() {
		return this->column_type;
	}
};



int main() {
	//create table pateu ((nume,name, 12,bucovina),(stoc,number,10,0))
}