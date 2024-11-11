#ifndef WORDLIST_H_
#define WORDLIST_H_
#include "Word.h"

/**
 * The WordList class represents a linked list of Word objects.
 * It provides various methods for manipulating and accessing the elements of the list.

 */
class WordList {
private:
    /**
     * The WordNode struct represents a node in the WordList containing a Word object and a pointer to the next node.
     */
    struct WordNode {
        /**
         * The Word object stored in the node.
         */
        Word theWord;

        /**
         * Pointer to the next node.
         */
        WordNode* next;

        /**
         * Constructor that creates a WordNode with a given Word and optional next node.
         * @param aWord The Word object to be stored in the node.
         * @param next Pointer to the next node (default is nullptr).
         */
        WordNode(const Word& aWord, WordNode* next = nullptr) : theWord(aWord), next(next) {}

        /**
         * Disable default constructor and other special member functions.
         */
        WordNode() = delete;
        WordNode(const WordNode& other) = delete;
        WordNode(WordNode&& other) = delete;
        WordNode& operator=(const WordNode& other) = delete;
        WordNode& operator=(WordNode&& other) = delete;

        /**
         * Default destructor.
         */
        virtual ~WordNode() = default;
    };

    /**
     * Pointer to the head (first node) of the list.
     */
    WordNode* head{ nullptr };

    /**
     * Pointer to the tail (last node) of the list.
     */
    WordNode* tail{ nullptr };

    /**
     * Current size of the list.
     */
    size_t size{ 0 };

    /**
     * Search for the given Word in the list.
     * @param aWord The Word to look up.
     * @return A pointer to the WordNode containing the Word, if found; otherwise, nullptr.
     */
    WordNode* lookup(const Word& aWord) const;

    /**
     * Add a Word at the front of the list.
     * @param aWord The Word to add.
     */
    void addFront(const Word& aWord);

    /**
     * Add a Word at the back of the list.
     * @param aWord The Word to add.
     */
    void addBack(const Word& aWord);

    /**
     * Add a Word after a specified node in the list.
     * @param p The node after which the Word should be added.
     * @param aWord The Word to add.
     */
    void addAfter(WordNode* p, const Word& aWord);

    /**
     * Remove a specified node from the list.
     * @param nodePtr The node to remove.
     * @return true if the node was successfully removed; otherwise, false.
     */
    bool remove(WordNode* nodePtr);

public:
    /**
     * Default constructor that creates an empty WordList.
     */
    WordList();

    /**
     * Copy constructor that creates a new WordList as a copy of an existing WordList.
     * @param list The WordList to be copied.
     */
    WordList(const WordList& list);

    /**
     * Move constructor that creates a new WordList by moving the resources from another WordList.
     * @param list The WordList to move resources from.
     */
    WordList(WordList&& list);

    /**
     * Copy assignment operator that replaces the contents of the WordList with a copy of another WordList.
     * @param rhs The WordList to be copied.
     * @return A reference to the updated WordList.
     */
    WordList& operator=(const WordList& rhs);

    /**
     * Move assignment operator that replaces the contents of the WordList by moving the resources from another WordList.
     * @param rhs The WordList to move resources from.
     * @return A reference to the updated WordList.
     */
    WordList& operator=(WordList&& rhs);

    /**
     * Destructor that cleans up the memory used by the WordList.
     */
    virtual ~WordList();

    /**
     * Checks if the WordList is empty.
     * @return true if the WordList is empty, false otherwise.
     */
    bool empty() const;

    /**
     * Returns the current size of the WordList.
     * @return The current size of the WordList.
     */
    size_t listSize() const;

    /**
     * Prints the contents of the WordList to an output stream.
     * @param sout The output stream to write to.
     */
    void print(std::ostream& sout) const;

    /**
     * Retrieves the Word at the front of the WordList.
     * @return A constant reference to the Word at the front.
     */
    const Word& front() const;

    /**
     * Retrieves the Word at the back of the WordList.
     * @return A constant reference to the Word at the back.
     */
    const Word& back() const;

    /**
     * Adds a Word to the WordList in sorted order.
     * @param aWord The Word to be added.
     */
    void addSorted(const Word& aWord);

    /**
     * Adds a Word to the WordList in sorted order, given its string representation and line number.
     * @param str The string representation of the Word.
     * @param lineNum The line number associated with the Word.
     */
    void addSorted(const std::string& str, int lineNum);

    /**
     * Removes the Word at the front of the WordList.
     * @return true if the Word was successfully removed, false if the WordList is empty.
     */
    bool removeFront();

    /**
     * Removes the Word at the back of the WordList.
     */
    void removeBack();

    /**
     * Searches for a Word in the WordList.
     * @param aWord The Word to search for.
     * @return true if the Word is found in the WordList, false otherwise.
     */
    bool search(const Word& aWord) const;
};

#endif /* WORDLIST_H_ */

