//In a recursive algorithm, the base case and the general case are interrelated and form the backbone
//of the recursive logic.They work together to ensure that the recursive algorithm terminates and produces
//the desired result.
//The base case defines the simplest scenario or stopping condition in which the recursive function does
//not make any further recursive calls and returns a specific result.It acts as the termination condition
//for the recursion.When the base case is reached, the recursion stops and the function starts unwinding the
//stack, returning values to previous recursive calls.
//The general case, also known as the recursive case, defines the problem in terms of smaller instances of
//the same problem.It breaks down the original problem into smaller subproblems that can be solved using the
//same recursive algorithm.In the general case, the recursive function calls itself with a modified input,
//making progress towards the base case.
//The relationship between the base case and the general case is crucial for the correct functioning of a
//recursive algorithm.The general case reduces the problem size or complexity and brings it closer to the base
//case.Each recursive call moves the problem closer to the base case until the base case is eventually reached.
//At that point, the recursion stops, and the function begins to unwind, returning values and combining the results
//from each recursive call.
//It's important to define both the base case and the general case correctly to ensure the termination and
//correctness of the recursive algorithm. The base case provides the exit condition, while the general case
//defines the recursive logic to progress towards the base case and solve the problem.

/*�ڵݹ��㷨�У����������base case����һ�������general case���໥��������ͬ���ɵݹ��߼�����Ҫ���֡�
 *����һ��ȷ���ݹ��㷨�ܹ���ֹ�����������Ľ����
���������������򵥵��������ֹ����������������£��ݹ麯�����ٽ��еݹ���ã��������ض��Ľ����
����Ϊ�ݹ����ֹ���������ﵽ�������ʱ���ݹ�ֹͣ����ʼ�⿪��������ջ����ֵ���ظ�ǰ��ĵݹ���á�
һ�������Ҳ��Ϊ�ݹ�������Խ�С��ͬ�����������������⡣����ԭʼ����ֽ�Ϊ����ʹ����ͬ�ݹ��㷨����Ľ�С�����⡣
��һ������£��ݹ麯��ʹ���޸ĺ������������������������Ͽ�����
���������һ�����֮��Ĺ�ϵ���ڵݹ��㷨����ȷ����������Ҫ��һ������������ģ��������С��������ƽ����������
ÿ�εݹ���ö���������������������ֱ�����մﵽ�������������һ���ϣ��ݹ�ֹͣ��������ʼ�⿪��
����ֵ��������ÿ���ݹ���õĽ�����������
Ϊȷ���ݹ��㷨����ֹ����ȷ�ԣ���ȷ������������һ������ǳ���Ҫ����������ṩ���˳���������һ����������˵ݹ��߼���
���������ƽ���������⡣*/