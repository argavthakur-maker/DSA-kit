#include <cassert>
#include <stdexcept>

#include "dsa/linked_list.hpp"

int main()
{
    dsa::LinkedList<int> original;
    assert(original.empty());
    assert(original.size() == 0);

    original.push_back(10);
    original.push_back(20);
    original.push_back(30);

    // Copy construction must create independent nodes.
    dsa::LinkedList<int> copied(original);
    assert(copied.size() == 3);
    assert(copied.front() == 10);
    assert(copied.back() == 30);
    copied.front() = 99;
    assert(original.front() == 10);

    // Copy assignment must replace the destination and remain independent.
    dsa::LinkedList<int> assigned;
    assigned.push_back(-1);
    assigned = original;
    assert(assigned.size() == 3);
    assigned.back() = 77;
    assert(original.back() == 30);

    // Self-assignment must preserve the list.
    original = original;
    assert(original.size() == 3);
    assert(original.front() == 10);
    assert(original.back() == 30);

    // Copying an empty list must remain safe and empty.
    dsa::LinkedList<int> empty_copy(assigned);
    empty_copy.clear();
    dsa::LinkedList<int> empty;
    empty_copy = empty;
    assert(empty_copy.empty());

    // Empty access and removal operations must report out_of_range.
    bool front_threw = false;
    try { (void)empty.front(); }
    catch (const std::out_of_range&) { front_threw = true; }
    assert(front_threw);

    bool pop_threw = false;
    try { empty.pop_back(); }
    catch (const std::out_of_range&) { pop_threw = true; }
    assert(pop_threw);

    return 0;
}
