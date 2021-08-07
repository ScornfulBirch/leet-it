#include <unordered_map>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {

private:

	const int FIRST_ELEMENT_INDEX = 0;
	const int SECOND_ELEMENT_INDEX = 1;
	const int TEN = 10;

public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		std::unordered_map<int, int> stored;

		extractDigits(stored, l1);
		extractDigits(stored, l2);

		checkAboveTen(stored);

		return mapToList(stored);
	}

private:
	void extractDigits(std::unordered_map<int, int>& store, ListNode* listNode) {
		addValue(store, FIRST_ELEMENT_INDEX, listNode->val);

		if (listNode->next != nullptr) {
			extractDigits(store, listNode->next, SECOND_ELEMENT_INDEX);
		}
	}

	void extractDigits(std::unordered_map<int, int>& store, ListNode* listNode, int i) {
		addValue(store, i, listNode->val);

		if (listNode->next != nullptr) {
			extractDigits(store, listNode->next, ++i);
		}
	}

	void addValue(std::unordered_map<int, int>& store, int i, int value) {
		int newValue = store[i];

		newValue += value;

		store[i] = newValue;
	}

	void checkAboveTen(std::unordered_map<int, int>& store) {
		for (size_t i = FIRST_ELEMENT_INDEX; i < store.size(); i++)
		{
			checkAboveTen(store, i);
		}
	}

	void checkAboveTen(std::unordered_map<int, int>& store, int i) {
		int value = store[i];

		if (value / 10 > 0)
		{
			store[i] = value % 10;
			store[i + 1] += 1;
		}
	}

	ListNode* mapToList(std::unordered_map<int, int>& store) {
		ListNode* resultNode;

		if (store.empty())
		{
			resultNode = new ListNode();
			return resultNode;
		}

		std::unordered_map<int, int>::iterator iterator = store.begin();
		resultNode = new ListNode(iterator->second);

		if (store.size() == 1)
		{
			return resultNode;
		}

		std::advance(iterator, SECOND_ELEMENT_INDEX);

		for (; iterator != store.end(); iterator++)
		{
			resultNode = merge(resultNode, iterator->second);
		}

		return resultNode;
	}

	ListNode* merge(ListNode* listNode, int value) {
		return new ListNode(value, listNode);
	}
};