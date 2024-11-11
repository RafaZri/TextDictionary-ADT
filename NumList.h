#ifndef NUMLIST_H
#define NUMLIST_H
#pragma once
#include <iostream>

/**
 * Class for managing a dynamic array of integers.
 * The class provides various methods for manipulating and accessing the elements of the array.
 */
class NumList {
private:
    int* pArray;  // a pointer to the dynamic array

    int capacity; // The maximum number of elements that pArray can currently hold.

    int size;     // The actual number of elements currently in pArray.

public:
    /**
     * Default constructor. Initializes an empty list.
     */
    NumList();

    /**
     * Copy constructor. Makes a new list that is a copy of an existing one.
     * @param other The existing list to copy from.
     */
    NumList(const NumList& other);

    /**
     * Move constructor. Takes ownership of the resources of a temporary list.
     * @param other The temporary list to take resources from.
     */
    NumList(NumList&& other) noexcept;

    /**
     * Copy assignment operator. Makes the left-hand list a copy of the right-hand one.
     * @param other The right-hand list to copy from.
     * @return A reference to the updated list.
     */
    NumList& operator=(const NumList& other);

    /**
     * Move assignment operator. Makes the left-hand list take ownership of the resources of a temporary right-hand list.
     * @param other The temporary list to take resources from.
     * @return A reference to the updated list.
     */
    NumList& operator=(NumList&& other) noexcept;

    /**
     * Destructor. Cleans up a NumList object when it is destroyed.
     */
    ~NumList();

    /**
     * Checks if the list is empty.
     * @return true if the list is empty, false otherwise.
     */
    bool empty() const;

    /**
     * Checks if the list is full.
     * @return true if the list is full, false otherwise.
     */
    bool full() const;

    /**
     * Returns the current size of the list.
     * @return The current size of the list.
     */
    int getSize() const;

    /**
     * Expands the capacity of the list.
     */
    void expand();

    /**
     * Returns the current capacity of the list.
     * @return The current capacity of the list.
     */
    int getCapacity() const;

    /**
     * Checks if a certain value is in the list.
     * @param x The value to check for.
     * @return true if the value is in the list, false otherwise.
     */
    bool contains(int x) const;

    /**
     * Appends a value to the end of the list.
     * @param x The value to append.
     */
    void append(int x);

    /**
     * Prints the list to the output stream.
     * @param out The output stream to print to.
     * @param indentLevel The level of indentation for pretty-printing.
     */
    void print(std::ostream& out, int indentLevel = 0) const;

    /**
     * Retrieves the value at a given index.
     * @param index The index to retrieve the value from.
     * @return The value at the given index.
     */
    int get(int index) const;

/**
 * Retrieves the value at a given index and stores it in 'value'.
 * @param index The index to retrieve the value from.
 * @param value A reference to an integer where the retrieved value will be stored.
 * @return true if the operation was successful, false otherwise
     * (i.e., if the index is out of range).
     */
    bool get(int index, int& value) const;
};

#endif // NUMLIST_H  // End of the inclusion guard
