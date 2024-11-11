#include "WordList.h"

/**
 * Default constructor that initializes an empty WordList.
 */
WordList::WordList() : head(nullptr), tail(nullptr), size(0) {}

/**
 * Copy constructor that creates a new WordList as a copy of another WordList.
 * @param list The WordList to be copied.
 */

WordList::WordList(const WordList& list) : head(nullptr), tail(nullptr), size(0) {
    WordNode* temp = list.head;
    while (temp != nullptr) {
        this->addBack(temp->theWord);
        temp = temp->next;
    }
}

/**
 * Move constructor that creates a new WordList by moving the resources from another WordList.
 * @param list The WordList to move resources from.
 */
WordList::WordList(WordList&& list) : head(list.head), tail(list.tail), size(list.size) {
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}


/**
 * Copy assignment operator that replaces the contents of the WordList with a copy of another WordList.
 * @param rhs The WordList to be copied.
 * @return A reference to the updated WordList.
 */
WordList& WordList::operator=(const WordList& rhs) {
    if (this != &rhs) {
        while (head != nullptr) {
            removeFront();
        }
        WordNode* temp = rhs.head;
        while (temp != nullptr) {
            addBack(temp->theWord);
            temp = temp->next;
        }
    }
    return *this;
}

/**
 * Move assignment operator that replaces the contents of the WordList by moving the resources from another WordList.
 * @param rhs The WordList to move resources from.
 * @return A reference to the updated WordList.
 */
WordList& WordList::operator=(WordList&& rhs) {
    if (this != &rhs) {
        while (head != nullptr) {
            removeFront();
        }
        head = rhs.head;
        tail = rhs.tail;
        size = rhs.size;
        rhs.head = nullptr;
        rhs.tail = nullptr;
        rhs.size = 0;
    }
    return *this;
}

/**
 * Destructor that cleans up the memory allocated for the WordList.
 */
WordList::~WordList() {
    while (head != nullptr) {
        removeFront();
    }
}

/**
 * Checks if the WordList is empty.
 * @return true if the WordList is empty, false otherwise.
 */
bool WordList::empty() const {
    return size == 0;
}

/**
 * Returns the number of Word objects in the WordList.
 * @return The number of Word objects in the WordList.
 */
size_t WordList::listSize() const {
    return size;
}

/**
 * Prints the WordList to the output stream.
 * @param sout The output stream to print to.
 */
void WordList::print(std::ostream& sout) const {
    WordNode* temp = head;
    while (temp != nullptr) {
        temp->theWord.print(sout);
        temp = temp->next;
    }
}

/**
 * Retrieves the Word at the front of the WordList.
 * @return A constant reference to the Word at the front.
 */
const Word& WordList::front() const {
    // Need to handle case where list is empty
    return head->theWord;
}

/**
 * Retrieves the Word at the back of the WordList.
 * @return A constant reference to the Word at the back.
*/
const Word& WordList::back() const {
    // Need to handle case where list is empty
    return tail->theWord;
}

/**
Adds a Word to the WordList in sorted order.
@param aWord The Word to add.
*/
void WordList::addSorted(const Word& aWord) {
    if (head == nullptr || aWord.compare(head->theWord) < 0) {
        // The list is empty or the word is smaller than the current head, so it becomes the new head
        addFront(aWord);
    } else {
        // Find the node after which to insert the new word
        WordNode* current = head;
        while (current->next != nullptr && current->next->theWord.compare(aWord) < 0) {
            current = current->next;
        }
        // Insert the new word after the found node
        addAfter(current, aWord);
    }
}

/**
Adds a Word to the WordList in sorted order, given a string and a line number.
@param str The string representing the Word.
@param lineNum The line number associated with the Word.
*/
void WordList::addSorted(const std::string& str, int lineNum) {
    addSorted(Word(str.c_str(), lineNum));
}

/**
Removes the Word at the front of the WordList.
@return true if a Word was successfully removed, false if the WordList is empty.
*/
bool WordList::removeFront() {
    if (head == nullptr) {
        return false;
    }
    WordNode* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    size--;
    return true;
}

/**
 * Removes the back WordNode from the WordList.
 * If the WordList is empty or contains only one element, nothing is removed.
 */
void WordList::removeBack() {
    // if the list is empty, there's nothing to remove
    if (head == nullptr) return;

    // if the list only contains one element, we remove it
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        // the list contains at least two elements, so we find the element before the last one
        WordNode* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        // now current points to the element before the last one
        // we remove the last element
        delete current->next;
        // and update the next pointer of the current element
        current->next = nullptr;
    }
}

/**
Searches for a Word in the WordList.
@param aWord The Word to search for.
@return true if the Word is found in the WordList, false otherwise.
*/
bool WordList::search(const Word& aWord) const {
    WordNode* temp = head;
    while (temp != nullptr) {
        if (temp->theWord.compare(aWord) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Private member functions
/**
 * Looks up a Word in the WordList.
 * @param aWord The Word to look up.
 * @return A pointer to the WordNode containing the Word, or nullptr if the Word is not found.
 */
WordList::WordNode* WordList::lookup(const Word& aWord) const {// Implement a lookup function
    WordNode* temp = head;
    while (temp != nullptr) {
        if (temp->theWord.compare(aWord) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

/**
 * Adds a Word to the front of the WordList.
 * @param aWord The Word to add.
 */
void WordList::addFront(const Word& aWord) {
    WordNode* newNode = new WordNode(aWord, head);
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;

    if (head->next != nullptr && head->theWord.compare(head->next->theWord) == 0) {
        // Word already exists, increment its frequency and append the line number
        head->next->theWord.appendNumber(aWord.getNumberList().get(0));
        delete newNode;
        head = head->next;
        size--;
    }
}


/**
 * Adds a Word to the back of the WordList.
 * @param aWord The Word to add.
 */
void WordList::addBack(const Word& aWord) {
    WordNode* newNode = new WordNode(aWord);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

/**
 * Adds a Word after a specified WordNode in the WordList.
 * @param p The WordNode after which to add the Word.
 * @param aWord The Word to add.
 */
void WordList::addAfter(WordNode* p, const Word& aWord) {
    if (p == nullptr) {
        addFront(aWord);
    } else {
        WordNode* nextNode = p->next;
        // Check if the word already exists in the list
        if (nextNode != nullptr && nextNode->theWord.compare(aWord) == 0) {
            // Word already exists, increment its frequency and append the line number
            nextNode->theWord.appendNumber(aWord.getNumberList().get(0));
        } else {
            // Word does not exist, create a new WordNode
            WordNode* newNode = new WordNode(aWord, nextNode);
            p->next = newNode;
            if (tail == p) {
                tail = newNode;
            }
            size++;
        }
    }
}



/**
 * Removes a WordNode from the WordList.
 * @param nodePtr A pointer to the WordNode to remove.
 * @return true if the WordNode was successfully removed, false if the WordNode is nullptr or the WordList is empty.
 */
bool WordList::remove(WordNode* nodePtr) {
    if (nodePtr == nullptr || head == nullptr) {
        return false;
    }
    if (nodePtr == head) {
        return removeFront();
    }
    WordNode* temp = head;
    while (temp->next != nodePtr) {
        temp = temp->next;
        if (temp == nullptr) {
            return false;
        }
    }
    temp->next = nodePtr->next;
    delete nodePtr;
    if (temp->next == nullptr) {
        tail = temp;
    }
    size--;
    return true;
}
