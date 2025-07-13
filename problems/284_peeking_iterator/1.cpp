#include <vector>
using namespace std;

 class Iterator {
	struct Data;
    Data* data;
 public:
	Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

		// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int peekedValue;
    bool hasPeeked;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), hasPeeked(false) {
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeeked) {
            peekedValue = Iterator::next();
            hasPeeked = true;
        }
        return peekedValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peekedValue;
        }
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return hasPeeked || Iterator::hasNext();
	}
};