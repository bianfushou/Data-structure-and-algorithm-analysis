#pragma once

#include<stack>

template<class T>
class DataIt {
public:
	T itBegin;
	T itEnd;
	DataIt(T itBegin, T itEnd) :itBegin(itBegin), itEnd(itEnd) {
	}
};

template<class T>
T quickScan(T itBegin, T itEnd)
{
	T point = itBegin;
	itBegin++;
	while (itBegin != itEnd)
	{
		while (*point <= *itEnd && itBegin != itEnd) {
			itEnd--;
		}
		while (*itBegin < *point && itBegin != itEnd) {
			itBegin++;
		}
		if (itBegin != itEnd) {
			swap(*itBegin, *itEnd);
		}
	}
	if (*itBegin < *point) {
		swap(*point, *itBegin);
		point = itBegin;
	}
	return point;
}

template<class T>
void quickSort(T& data)
{
	if ( data.size()< 2) {
		return;
	}
	std::stack<DataIt<T::iterator>> itStack;
	auto end = data.end();
	end--;
	itStack.emplace(data.begin(), end);
	do {
		DataIt<T::iterator> dataIt = itStack.top();
		itStack.pop();
		T::iterator point = quickScan(dataIt.itBegin, dataIt.itEnd);
		auto left = point;
		if (point != dataIt.itBegin ) {
			left--;
			if (left != dataIt.itBegin) {
				itStack.emplace(dataIt.itBegin, left);
			}
		}
		auto right = point;
		if (point != dataIt.itEnd ) {
			right++;
			if (right != dataIt.itEnd) {
				itStack.emplace(right, dataIt.itEnd);
			}
		}
	} while (!itStack.empty());
}



