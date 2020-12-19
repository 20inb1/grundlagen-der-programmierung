#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

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
 * Determine if a character is a letter.
 * 
 * @param character 
 * @return true 
 * @return false 
 */
bool isLetter(char &character)
{
	return isalpha(character);
}

/**
 * Explode a string by the given delimiter
 * 
 * @param s 
 * @param delim 
 * @return std::vector<std::string> 
 */
std::vector<std::string> explode(std::string &str, char delimiter)
{
	std::vector<std::string> result;
	std::string element = "";

	for (char &character : str)
	{
		if (character == delimiter)
		{
			// Do not add empty strings to vector.
			if (element.empty())
			{
				continue;
			}

			// Add element to result vector when character matches delimiter.
			result.push_back(element);

			// Reset character.
			element = "";
		}
		else if (isLetter(character))
		{
			// Add character to element if it does not match the given delimiter.
			// Only add character if it is a letter.
			element += character;
		}
	}

	// Add last element to result vector.
	if (!element.empty())
	{
		result.push_back(element);
	}

	return result;
}

/**
 * Count words and return their frequencies. 
 * 
 * @param words 
 * @return std::map<std::string, int> 
 */
std::map<std::string, int> countWords(const std::vector<std::string> &words)
{
	std::map<std::string, int> frequencies;

	for (int i = 0; i < words.size(); i++)
	{
		std::string word = words.at(i);

		// Determine if the word already exists.
		if (frequencies.count(word))
		{
			// If word already in map: count +1
			frequencies[word] += 1;
		}
		else
		{
			// If word does not exist: set to 1
			frequencies[word] = 1;
		}
	}

	return frequencies;
}

/**
 * Print words an it's frequencies.
 * 
 * @param wordFrequency 
 * @return void
 */
void printWordFrequencyHistorgram(std::map<std::string, int> wordFrequency)
{
	for (const auto &w : wordFrequency)
	{
		std::cout << w.first << ": " << w.second << std::endl;
	}
}

int main()
{
	std::string path;

	std::cout << "Enter the relative path of the file:" << std::endl;
	std::cin >> path;

	// Read string from file path.
	auto contents = getFileContents(path);

	// Get words from file contents.
	auto words = explode(contents, ' ');

	// Get word frequency.
	auto wordFrequency = countWords(words);

	// Print word frequencies.
	printWordFrequencyHistorgram(wordFrequency);
}