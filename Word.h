#ifndef WORD_H_
#define WORD_H_
#include <cstring>
#include "NumList.h"

/**
 * The Word class represents a word, containing a character array (C-string), a frequency, and a NumList.
 * It provides methods for managing and accessing the word and associated numbers.
 */
class Word {
private:

    char* pCharArray;   // A pointer to a character array (C-string) that holds the word.

    int frequency;      // An integer representing the number of occurrences of this word.

    NumList num_list;   // A NumList holding the numbers associated with this word.

public:
    /**
     * Constructor that creates a new Word using the supplied C-string pChArr and integer n.
     * @param pChArr A character array that represents the word.
     * @param n An integer associated with the word.
     */
    Word(const char* pChArr, int n);

    /**
     * The default constructor is explicitly deleted to prevent creation of a Word without parameters.
     */
    Word() = delete;

    /**
     * Copy constructor that creates a new Word which is a copy of another Word.
     * @param other The Word object to copy.
     */
    Word(const Word& other);

    /**
     * Move constructor that creates a new Word by moving resources from another Word.
     * @param other The Word object to move resources from.
     */
    Word(Word&& other) noexcept;

    /**
     * The copy assignment operator that replaces the contents of the Word with a copy of another Word.
     * @param other The Word object to copy.
     * @return A reference to the updated Word.
     */
    Word& operator=(const Word& other);

    /**
     * The move assignment operator that replaces the contents of the Word by moving resources from another Word.
     * @param other The Word object to move resources from.
     * @return A reference to the updated Word.
     */
    Word& operator=(Word&& other) noexcept;

    /**
     * Destructor that frees the memory allocated for the Word.
     */
    ~Word();

    /**
     * Returns a const pointer to the C-string representation of the Word.
     * @return A const pointer to the character array.
     */
    const char* c_str() const;

    /**
     * Adds a number to the end of the Word's NumList.
     * @param n The number to append.
     */
    void appendNumber(int n);

    /**
     * Returns the length of the Word's C-string.
     * @return The length of the character array.
     */
    size_t size() const;

    /**
     * Writes the Word's character array and its NumList to an output stream.
     * @param out The output stream to write to.
     */
    void print(std::ostream& out) const;

    /**
     * Returns a constant reference to the Word's NumList.
     * @return A constant reference to the NumList.
     */
    const NumList& getNumberList() const;

    /**
     * Compares this Word's character array to another Word's character array.
     * Returns -1, 0, or 1, depending on whether this Word's character array is less than, equal to, or greater than the other Word's character array.
     * @param other The Word to compare with.
     * @return An integer representing the comparison result.
     */
    int compare(const Word& other) const;
    int getFrequency() const; // Getter for frequency member

};

#endif /* WORD_H_ */
