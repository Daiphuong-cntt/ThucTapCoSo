#include <iostream>
#include <vector>
#include <algorithm>        
#include <iterator>            
#include <queue>
#include <time.h>
#include <cstdio>           
using namespace std;

// Radix Sort using base-10 radix
template <typename InputIterator, typename OutputIterator> 
void radixSort(InputIterator start, InputIterator end, OutputIterator output){
	const int BASE = 10;    // Base
	std::queue<  typename std::iterator_traits<OutputIterator>::value_type > bucket[BASE];    // An array of buckets based on the base

	unsigned size = end - start;
	// Get the maximum number
	typename std::iterator_traits<InputIterator>::value_type max = *std::max_element(start, end);    // O(n)

	// Copy from input to output
	std::copy(start, end, output);    // O(n)

	// Iterative Radix Sort - if k is log BASE (max), then the complexity is O( k * n)
	for (unsigned power = 1; max != 0; max /= BASE, power *= BASE){ 

		// Assign to buckets
		for (OutputIterator it = output; it != output + size; it++){
			unsigned bucketNumber = (unsigned)((*it / power) % BASE);
			bucket[bucketNumber].push(*it);        // O(1)
		}

		// Re-assemble
		OutputIterator it = output;
		for (int i = 0; i < BASE; i++){
			int bucketSize = bucket[i].size();
			for (int j = 0; j < bucketSize; j++){
				*it = bucket[i].front();
				bucket[i].pop();
				it++;
			}
		}
	}
}


int main(){
	vector<unsigned> input = { 5, 10, 15, 20, 25, 50, 40, 30, 20, 10, 9524, 878, 17, 1, 99, 18785, 3649, 164, 94,
		123, 432, 654, 3123, 654, 2123, 543, 131, 653, 123, 533, 1141, 532, 213, 2241, 824, 1124, 42, 134, 411,
		491, 341, 1234, 527, 388, 245, 1992, 654, 243, 987 };
	vector<unsigned> output(input.size());
	  clock_t start = clock();
	radixSort(input.begin(), input.end(), output.begin());
 printf("Time: %.9fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);

	for (unsigned it : output){
		cout << it << endl;
	}
	cin.get();
	getchar();
	return 0;
}