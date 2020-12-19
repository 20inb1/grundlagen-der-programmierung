#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <iterator>

/**
 * Get array position position for the given character.
 * 
 * @param character 
 * @return int 
 */
int getCharacterPosition(const char &character)
{
	// Checking if character is A-Z or a-z
	for (int i = 0; i < 26; i++)
	{
		char lowercaseChar = 'a' + i;
		char uppercaseChar = 'A' + i;

		if (lowercaseChar == character || uppercaseChar == character)
		{
			return i;
		}
	}

	// Checking if character is 0-9
	for (int i = 0; i < 10; i++)
	{
		char iChar = i + '0';

		if (iChar == character)
		{
			return i + 26;
		}
	}

	return -1;
}

/**
 * Get's the character frequency for the given string.
 * 
 * Only the following characters are being checked:
 * - A-Z
 * - 0-9 
 * 
 * @param str 
 * @return std::array<int, 26 + 10> 
 */
std::array<int, 26 + 10> characterFrequency(std::string &str)
{
	std::array<int, 26 + 10> freq = {};

	for (char &character : str)
	{
		int pos;
		pos = getCharacterPosition(character);

		if (pos < 0)
		{
			continue;
		}

		freq.at(pos)++;
	}

	return freq;
}

/**
 * Get's the string content of the given path.
 * 
 * @param path 
 * @return std::string
 */
std::string getFileContents(const std::string &path)
{
	std::string contents;

	std::ifstream ifs(path);
	contents.assign(
		(std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	return contents;
}

/**
 * Get character for the given position of a freq array calculated in 
 * "characterFrequency".
 * 
 * @param pos 
 * @return char 
 */
char getCharFromPosition(int &pos)
{
	// Ascii character for
	if (pos < 26)
	{
		char character = pos % 26 + 97;

		return character;
	}

	char character = pos - 26 + '0';

	return character;
}

/**
 * Prints histogram for the given character frequencies.
 * 
 * @param freq 
 */
void printFrequencyHistogram(const std::array<int, 26 + 10> &freq)
{

	for (int i = 0; i < freq.size(); i++)
	{
		int charFrequency = freq.at(i);
		char character = getCharFromPosition(i);

		std::cout << character << ": ";
		for (int j = 0; j < charFrequency; j++)
		{
			std::cout << "=";
		}
		std::cout << "\n";
	}
}

int main()
{
	std::string path;

	path = "foo.txt";
	auto contents = getFileContents(path);
	auto freq = characterFrequency(contents);

	printFrequencyHistogram(freq);
}
