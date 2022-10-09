#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	string str;
	cout << "Please enter the line:" << endl;
	getline(cin, str, '\n');
	cout << endl;

	// map <initial character, new character>
	map <char, char>character_swap;
	size_t str_size = str.size();
	const char single_character = '(';
	const char common_character = ')';

	for (size_t i = 0; i < str_size; i += 1)
	{
		char *character = &(str[i]);
		*character = tolower(*character);

		auto character_position = character_swap.find(*character);

		if (character_position == character_swap.end())
		{
			character_swap.insert(make_pair(*character, single_character));
		}
		else if (character_position->second == single_character)
		{
			character_position->second = common_character;
		}
	}

	for (size_t i = 0; i < str_size; i += 1)
	{
		char *character = &(str[i]);
		auto character_position = character_swap.find(*character);
		if (character_position == character_swap.end())
		{
			throw runtime_error("Character not found when replacing (how?!)");
		}
		*character = character_position->second;
	}

	cout << "Result:" << endl << str << endl << endl;
	system("pause");
}