#include "NumList.h"
#include <algorithm>
#include <stdexcept>

/**
 * Default constructor that creates an empty list of capacity 1 and size 0.
 */
NumList::NumList() : capacity(1), size(0), pArray(new int[1]) {}

/**
 * Copy constructor. Creates a new list that is a copy of an existing list.
 * @param other The list to be copied.
 */
NumList::NumList(const NumList& other)
        : capacity(other.capacity), size(other.size), pArray(new int[other.capacity]) {
    // Copy the elements of the other array into this array
    std::copy(other.pArray, other.pArray + other.size, pArray);
}

/**
 * Move constructor. Transfers the ownership of an existing list to a new list.
 * @param other The list to transfer ownership from.
 */
NumList::NumList(NumList&& other) noexcept
        : capacity(other.capacity), size(other.size), pArray(other.pArray) {
    // Leave other in a valid but unspecified state
    other.pArray = nullptr;
    other.capacity = 0;
    other.size = 0;
}

/**
 * Copy assignment operator. Replaces the contents of the list with a copy of another list.
 * @param other The list to be copied.
 * @return A reference to the list.
 */
NumList& NumList::operator=(const NumList& other) {
    if (this != &other) {
        // Free the current array
        delete[] pArray;
        // Copy the properties of the other object
        capacity = other.capacity;
        size = other.size;
        pArray = new int[other.capacity];
        std::copy(other.pArray, other.pArray + other.size, pArray);
    }
    return *this;
}

/**
 * Move assignment operator. Replaces the contents of the list by transferring the ownership of another list.
 * @param other The list to transfer ownership from.
 * @return A reference to the list.
 */
NumList& NumList::operator=(NumList&& other) noexcept {
    if (this != &other) {
        // Free the current array
        delete[] pArray;
        // Take ownership of the other object's resources
        capacity = other.capacity;
        size = other.size;
        pArray = other.pArray;
        // Leave other in a valid but unspecified state
        other.pArray = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

/**
 * Destructor. Deallocates the memory used by the list.
 */
NumList::~NumList() {
    // Free the dynamic array
    delete[] pArray;
}

/**
 * Checks if the list is empty.
 * @return true if the list is empty, false otherwise.
 */
bool NumList::empty() const {
    return size == 0;
}

/**
 * Checks if the list is full.
 * @return true if the list is full, false otherwise.
 */
bool NumList::full() const {
    return size == capacity;
}

/**
 * Gets the number of elements in the list.
 * @return The number of elements in the list.
 */
int NumList::getSize() const {
    return size;
}

/**
 * Expands the capacity of the list. The new capacity is twice the old capacity.
 */
void NumList::expand() {
    // Allocate a new array with double the capacity
    int* newArray = new int[capacity * 2];
    // Copy the elements to the new array
    std::copy(pArray, pArray + size, newArray);
    // Free the old array
    delete[] pArray;
    // Update pArray and capacity
    pArray = newArray;
    capacity *= 2;
}

/**
 * Gets the capacity of the list.
 * @return The capacity of the list.
 */
int NumList::getCapacity() const {
    return capacity;
}

/**
 * Checks if the list contains a specific element.
 * @param x The element to search for.
 * @return true if the list contains the element, false otherwise.
 */
bool NumList::contains(int x) const {
    for (int i = 0; i < size; i++) {
        if (pArray[i] == x) {
            return true;
        }
    }
    return false;
}

/**
 * Adds an element to the end of the list.
 * @param x The element to be added.
 */
void NumList::append(int x) {
    if (full()) {
        // If the list is full, expand it
        expand();
    }
    pArray[size++] = x;
}

/**
 * Prints the elements of the list to an output stream.
 * @param out The output stream to write to.
 * @param indentLevel The indentation level (unused).
 */
void NumList::print(std::ostream& out, int indentLevel) const {
    for (int i = 0; i < size; i++) {
        out << pArray[i];
        if (i != size - 1) {
            out << ", ";
        }
    }
}

/**
 * Retrieves the element at a specific position in the list.
 * @param index The position of the element to retrieve.
 * @return The element at the specified position.
 * @throws std::out_of_range If the index is out of range.
 */
int NumList::get(int index) const {
    if (index < 0 || index >= size) {
        // If the index is out of range, throw an exception
        throw std::out_of_range("Index out of range");
    }
    return pArray[index];
}

/**
 * Retrieves the element at a specific position in the list and assigns it to a reference parameter.
 * @param index The position of the element to retrieve.
 * @param value Reference parameter to assign the retrieved element to.
 * @return true if the element was successfully retrieved, false if the index is out of range.
 */
bool NumList::get(int index, int& value) const {
    if (index < 0 || index >= size) {
        // If the index is out of range, return false
        return false;
    }
    // Assign the value at the index to the reference parameter
    value = pArray[index];
    // Return true to indicate success
    return true;
}

/**
 * Overloads the insertion operator to print the elements of the list to an output stream.
 * @param out The output stream to write to.
 * @param list The list to be printed.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& out, const NumList& list) {
    list.print(out);
    return out;
}

