//a.Running time of an algorithm : The running time of an algorithm refers to the amount of time it takes to
//execute or complete.It is often represented in terms of the number of elementary operations performed by the
//algorithm, such as comparisons, assignments, and arithmetic operations.The running time helps us understand
//how the algorithm's performance scales with the input size.
//b.Worst case running time : The worst case running time of an algorithm is the maximum time it takes to run
//for any possible input of a given size.It represents the scenario where the algorithm performs the least
//efficiently or takes the longest time to complete among all possible inputs.Analyzing the worst case running
//time helps us understand the maximum time complexity of the algorithm.
//For example, consider a sorting algorithm like Quicksort.The worst case running time occurs when the input
//array is already sorted or sorted in reverse order, leading to the maximum number of comparisons and swaps.
//c.Order(rate) of growth of the running time : The order or rate of growth of the running time describes
//how the running time of an algorithm increases relative to the size of the input.It provides an approximation
//of the running time's behavior as the input size approaches infinity. It is often denoted using big O notation.
//For example, an algorithm with a running time of O(n ^ 2) indicates that the running time grows quadratically
//with the input size.If the input size doubles, the running time roughly quadruples.
//d.Asymptotic upper bound : An asymptotic upper bound represents the upper limit on the growth rate of the
//running time as the input size increases.It provides an upper bound on the running time but may not be tight
//or precise.The asymptotic upper bound is often represented using big O notation.
//For example, if an algorithm's running time is determined to be O(n^2), it means the running time will not
//grow faster than a quadratic function of the input size, even though it may actually be faster in practice.
//It's important to note that terms like worst case running time, order of growth, and asymptotic upper bound
//help us characterize the performance of algorithms and make comparisons, but they may not provide exact
//measurements for the actual running time on specific inputs. They offer insights into how the algorithm scales
//and behaves with increasing input size.

/*
a. �㷨������ʱ�䣺�㷨������ʱ��ָ����ִ�л���������ʱ������ͨ�����㷨ִ�еĻ�������������ʾ��
��Ƚϡ���ֵ����������������ʱ����������˽��㷨���������������ģ�����Ӷ���α仯��

b. ��������ʱ�䣺�㷨����������ʱ����ָ��������ܵĸ�����С�������£�����ʱ����������
���������㷨�����п��ܵ�������ִ��Ч����ͻ���Ҫ�ʱ��������������������ʱ�������������˽��㷨�����ʱ�临�Ӷȡ�
���磬����һ�������㷨����������򣩡���������ʱ�䷢�������������Ѿ�������෴˳�����������£�
���½������ıȽϺͽ���������

c. ����ʱ��������ʣ�����ʱ����������������㷨������ʱ������������ģ�����Ӷ������ķ�ʽ��
���ṩ������ʱ���������ģ�����������ʱ����Ϊ���ơ�ͨ��ʹ�ô�O��ʾ������ʾ�����ʡ�
���磬���һ���㷨������ʱ��ȷ��ΪO(n^2)������ζ������ʱ���������ģ��ƽ�������ȡ�

d. �����Ͻ磺�����Ͻ��ʾ�������ģ����ʱ������ʱ�������ʵ����ޡ����ṩ������ʱ����Ͻ磬�����ܲ��ǽ��ܻ�׼ȷ�ġ�
�����Ͻ�ͨ��ʹ�ô�O��ʾ������ʾ��
���磬���һ���㷨������ʱ�䱻ȷ��ΪO(n^2)������ζ������ʱ�䲻��������ģ��ƽ�����������ø��죬��ʹ��ʵ���п��ܸ��졣
��Ҫע����ǣ���������ʱ�䡢�����ʺͽ����Ͻ�����������������㷨�����ܲ����бȽϣ�
�����ǿ����޷��ṩʵ�������׼ȷ����ʱ������������ṩ���㷨�ڲ������ӵ������ģ�µ���չ�Ժ���Ϊ�ļ��⡣*/