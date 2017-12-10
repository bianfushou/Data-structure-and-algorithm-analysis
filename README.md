# Data-structure-and-algorithm-analysis
重温大学课程，重新思考提升

  第一个是一个不需要递归的快排算法，思路比较简单，就是将需要用递归调用的部分转变为对stack的push和pop,当stack empty时结束，通过分析可知需要存入stack
的数据只有需要排序的数据的首地址（left）和尾地址(right)两个数据，详细信息看代码。
