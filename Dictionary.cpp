#include <fstream>
#include <sstream>
#include <cctype>
#include "Dictionary.h"

/**
 * @brief Determines the bucket index for a word
 *
 * @param word The word for which the bucket index is required
 * @return size_t The index of the bucket for the given word
 */
size_t Dictionary::bucketIndex(const string& word) const
{
    size_t index = 26;
    if (isalpha(word[0])) // If the first character of the word is a letter
    {
        index = toupper(word[0]) - 'A'; // Bucket index is determined based on the alphabetical order
    }
    return index;
}

/**
 * @brief Construct a new Dictionary:: Dictionary object and read words from the input file
 *
 * @param filename The name of the file from which words are read
 */
Dictionary::Dictionary(const string& filename) : filename(filename)
{
    std::ifstream fin(filename);
    if (!fin) // If the file cannot be opened
    {
        std::cout << "could not open input file: " << filename << std::endl;
        exit(1);
    }

    int linenum = 0;
    string line;
    while (getline(fin, line)) // Read lines from the file
    {
        ++linenum;
        std::istringstream sin(line);
        string wordStr;
        while (sin >> wordStr) // Read words from the line
        {
            processWord(wordStr, linenum);
        }
    }
    fin.close();
}

/**
 * @brief Process a word from the file and add it to the corresponding bucket
 *
 * @param word The word to be processed
 * @param linenum The line number where the word was found
 */
void Dictionary::processWord(const string& word, int linenum)
{
    size_t index = bucketIndex(word); // Get the bucket index for the word
    wordListBuckets[index].addSorted(word, linenum); // Add the word to the corresponding bucket
}

/**
 * @brief Print the contents of the Dictionary
 *
 * @param out The output stream to which the contents are printed
 */
void Dictionary::print(ostream& out) const
{
    for (const auto& wordList : wordListBuckets) // For each bucket in the dictionary
    {
        wordList.print(out); // Print the words in the bucket
    }
}
