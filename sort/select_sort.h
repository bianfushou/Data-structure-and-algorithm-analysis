#pragma once
#include<deque>

template<class T>
void selectSort(T& data) 
{
	if (data.size() < 2) {
		return;
	}
	
	std::deque<T::iterator> itDeq;
	auto end = data.end();
	end--;
	for (auto it = data.begin(); it != end; it++) {
		auto k = it;
		T::iterator j = it;
		j++;
		
		if (!itDeq.empty()) {
			if (itDeq.front() == it) {
				itDeq.pop_front();
			}
			//cout << *m<<endl;
			if (!itDeq.empty()) {
				k = itDeq.back();
				j = k;
				j++;
				itDeq.pop_back();
			}
		}
		for (; j != data.end(); j++) {
			if (*j < *k) {
				if (k != it) {
					itDeq.push_back(k);
				}
				k = j;
			}
		}
		if (k != it) {
			swap(*k, *it);
		}
		//cout << endl;
	}
}
