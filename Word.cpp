#include "Word.h"

/**
 * Constructor that creates a new Word using the supplied C-string pChArr and integer n.
 * @param pChArr A character array that represents the word.
 * @param n An integer associated with the word.
 */
Word::Word(const char* pChArr, int n) : frequency(1) {
    // Allocate memory for the character array (C-string)
    pCharArray = new char[strlen(pChArr) + 1];
    // Copy the supplied C-string into the allocated memory
    std::strcpy(pCharArray, pChArr);
    num_list.append(n);
}

/**
 * Copy constructor that creates a new Word which is a copy of another Word.
 * @param other The Word object to copy.
 */
Word::Word(const Word& other) : frequency(other.frequency), num_list(other.num_list) {
    pCharArray = new char[strlen(other.pCharArray) + 1];
    // Copy the character array from the other Word
    std::strcpy(pCharArray, other.pCharArray);
}

/**
 * Move constructor that creates a new Word by moving resources from another Word.
 * @param other The Word object to move resources from.
 */
Word::Word(Word&& other) noexcept : frequency(other.frequency), num_list(std::move(other.num_list)) {
    // Move the pointer to the character array from the other Word
    pCharArray = other.pCharArray;
    other.pCharArray = nullptr; // Null the source pointer to avoid double deletion
}

/**
 * The copy assignment operator that replaces the contents of the Word with a copy of another Word.
 * @param other The Word object to copy.
 * @return A reference to the updated Word.
 */
Word& Word::operator=(const Word& other) {
    if (this != &other) {
        delete[] pCharArray; // Delete existing memory
        pCharArray = new char[strlen(other.pCharArray) + 1];
        // Copy the character array from the other Word
        std::strcpy(pCharArray, other.pCharArray);
        // Copy the frequency and NumList from the other Word
        frequency = other.frequency;
        num_list = other.num_list;
    }
    return *this;
}

/**
 * The move assignment operator that replaces the contents of the Word by moving resources from another Word.
 * @param other The Word object to move resources from.
 * @return A reference to the updated Word.
 */
Word& Word::operator=(Word&& other) noexcept {
    if (this != &other) {
        delete[] pCharArray; // Delete existing memory
        pCharArray = other.pCharArray;
        other.pCharArray = nullptr; // Null the source pointer to avoid double deletion
        // Move the frequency and NumList from the other Word
        frequency = other.frequency;
        num_list = std::move(other.num_list);
    }
    return *this;
}

/**
 * Destructor that frees the memory allocated for the Word.
 */
Word::~Word() {
    delete[] pCharArray;
}

/**
 * Returns a const pointer to the C-string representation of the Word.
 * @return A const pointer to the character array.
 */
const char* Word::c_str() const {
    return pCharArray;
}

/**
 * Adds a number to the end of the Word's NumList.
 * @param n The number to append.
 */
void Word::appendNumber(int n) {
    num_list.append(n);
    // Increment the frequency count
    frequency++;
}

/**
 * Returns the length of the Word's C-string.
 * @return The length of the character array.
 */
size_t Word::size() const {
    return strlen(pCharArray);
}

/**
 * Writes the Word's character array and its NumList to an output stream.
 * @param out The output stream to write to.
 */
void Word::print(std::ostream& out) const {
    if (pCharArray != nullptr) { // Check for nullptr before using pCharArray
        out << pCharArray << ": " << frequency << " times, lines: ";
        num_list.print(out);
        out << "\n";
    }
    else {
        out << "(empty)\n"; // Print something suitable when the Word is empty
    }
}


/**
 * Returns a constant reference to the Word's NumList.
 * @return A constant reference to the NumList.
 */
const NumList& Word::getNumberList() const {
    return num_list;
}

/**
 * Compares this Word's character array to another Word's character array.

Returns -1, 0, or 1, depending on whether this Word's character array is less than, equal to, or greater than the other Word's character array.
@param other The Word to compare with.
@return An integer representing the comparison result.
*/
int Word::compare(const Word& other) const {
    return std::strcmp(pCharArray, other.pCharArray);
}

