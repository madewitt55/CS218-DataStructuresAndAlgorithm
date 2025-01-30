// Mason DeWitt; mason.dewitt@snhu.edu; ID: 2595261
// stack_queue.cpp: Stores user inputs in a list and, upon receiving a negative number,
// removes it and the preceeding five numbers

#include <iostream>
#include <string>
#include<stack>
#include <queue>
using std::cout;
using std::cin;
using std::endl;

int main() {
	std::queue<int> nums_queue;
	std::stack<int> nums_stack;
	int input;

	// Add values to stack until 0 is inputted
	cout << "Input numbers (0 to terminate):" << endl;
	cin >> input;
	while (input != 0) {
		nums_queue.push(input);
		cin >> input;
	}

	while (!nums_queue.empty()) {
		if (nums_queue.front() < 0) {
			// If five positives or more preceed the negative
			if (nums_stack.size() >= 5) {
				cout << "Eliminating values:" << endl;
				for (int i = 0; i < 5; i++) {
					cout << nums_stack.top() << " ";
					nums_stack.pop();
				}
				cout << endl;
			}
			// Throw error and exit program
			else {
				cout << "ERROR: Less than five positive numbers entered between negatives." << endl;
				exit(0);
			}
		}
		// Add positive values to stack
		else {
			nums_stack.push(nums_queue.front());
		}
		nums_queue.pop(); // Iterate through queue
	}

	// Output result
	cout << "Remaining values:" << endl;
	while (!nums_stack.empty()) {
		cout << nums_stack.top() << " ";
		nums_stack.pop();
	}
}