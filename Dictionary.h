#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include<string>
#include "WordList.h"

using std::string;
using std::ostream;

/**
 * The Dictionary class processes and stores words in WordList buckets.
 * It provides methods for adding words to the dictionary, printing its contents, and managing word buckets.
 */
class Dictionary {
private:
    /** The name of the file the dictionary words are read from */
    string filename;

    /** An array of WordList buckets for storing words. 26 alpha buckets + 1 none-alpha bucket */
    WordList wordListBuckets[27];

    /**
     * Calculate the bucket index for a given word.
     * @param word The word to calculate the bucket index for.
     * @return The index of the bucket where the word should be stored.
     */
    size_t bucketIndex(const string& word) const;

public:
    /**
     * Constructor that takes a filename and creates a Dictionary.
     * @param filename The name of the file to read words from.
     */
    Dictionary(const string& filename);

    /**
     * Process a word from the file and add it to the correct WordList bucket.
     * @param word The word to be processed.
     * @param linenum The line number where the word was found.
     */
    void processWord(const string& word, int linenum);

    /**
     * Prints the contents of the Dictionary to an output stream.
     * @param out The output stream to print to.
     */
    void print(ostream& out) const;

    // Deleting the default constructor as it is not required.
    Dictionary()  = delete;

    // Using the default destructor.
    ~Dictionary() = default;

    // Using the default copy constructor.
    Dictionary(const Dictionary& ) = default;

    // Using the default move constructor.
    Dictionary(Dictionary&&) = default;

    // Using the default copy assignment operator.
    Dictionary& operator=(const Dictionary&) = default;

    // Using the default move assignment operator.
    Dictionary& operator=(Dictionary&&) = default;
};

#endif /* DICTIONARY_H_ */
