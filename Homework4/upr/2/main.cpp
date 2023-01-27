#include <iostream>
#include "Document.hpp"
#include "KeyValueDatabase.hpp"

using namespace std;
int main()
{
	Document temp("temp", "/tmp", "doc");

	temp.write_line("This is an example doc");
	temp.write_line("This is another example line");
	temp.write_line("This is a third example line");
	temp.write_line("This is a forth example line");

	std::cout << temp.read_line() << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line

	std::cout << temp.read_line(3) << std::endl; //This is a third example line
	std::cout << temp.read_line() << std::endl; //This is a forth example line

	std::cout << temp.read_line(1) << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line

	std::cout << temp.read_line(4) << std::endl; //This is forth example line
	cout << temp.get_name() << '\n';
	cout << temp.get_extension() << '\n';
	cout << temp.get_location() << '\n';
	cout << temp.get_fullpath() << '\n';
	cout << "--------------------\n";
	cout << temp.to_string() << '\n';
	cout << "--------------------\n";
	cout << temp.debug_print() << '\n';

	Document temp1("name", "/loc", "ext");
	temp1.from_string(temp.to_string());

	Object* obj = new Document("fds", "/ytei", "fdsd");

	delete obj;

	KeyValueDatabase bey("kjfd", "sdja", "dlsa");
	bey.add_entry({ "sfda", 45 });
	bey.add_entry({ "ert", 6543 });
	bey.add_entry({ "erfds", 543 });
	cout<<bey.to_string();
	cout << bey.debug_print();

//	std::cout << temp.read_line(5) << std::endl;

	return 0;
}