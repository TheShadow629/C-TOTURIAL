//Cyclomatic complexity is a software metric that measures the complexity of a program's control flow based
//on the number of decision points and the number of independent paths through the program. It helps identify
//the number of logical conditions and possible execution paths in a program, which in turn provides an estimate of how difficult it is to understand, test, and maintain the code.
//
//The cyclomatic complexity of a program can be calculated using the following formula :
//
//M = E - N + 2
//
//Where :
//    -M is the cyclomatic complexity
//    - E is the number of edges(control flow branches)
//    - N is the number of nodes(decision points)
//
//    The higher the cyclomatic complexity, the more complex the program's logic and the more difficult it
//    may be to understand and test. A low cyclomatic complexity indicates simpler and more manageable code.
//
//    Cyclomatic complexity can provide insights into the number of test cases needed to achieve good code
//    coverage.In general, the number of test cases required should be at least equal to the cyclomatic complexity
//    to ensure that all possible paths and decision points are covered.Each distinct path through the code should
//    be tested at least once.
//
//    Here is an example in C++ to illustrate how cyclomatic complexity relates to program logic complexity
//    and the number of test cases :
//
//```cpp
//#include <iostream>
//
//int calculate(int x, int y, int z) {
//    int result;
//
//    if (x > 0) {
//        if (y > 0) {
//            result = x + y;
//        }
//        else {
//            result = x - y;
//        }
//    }
//    else {
//        if (z > 0) {
//            result = x * z;
//        }
//        else {
//            result = x / z;
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    int a = 10, b = 5, c = 2;
//    int res = calculate(a, b, c);
//
//    std::cout << "Result: " << res << std::endl;
//
//    return 0;
//}
//```
//
//In this example, the `calculate` function takes three input parameters and performs a set of nested if -
//else conditions based on the values of those parameters.The code has multiple decision points, resulting
//in different paths of execution.
//
//To calculate the cyclomatic complexity, we need to count the number of decision points(nodes) and control
//flow branches(edges).In this case, we have four decision points(`x > 0`, `y > 0`, `z > 0`, and the final
//`return` statement) and six control flow branches(two branches for each if - else condition).Therefore,
//the cyclomatic complexity is 6 - 4 + 2 = 4.
//
//Based on the cyclomatic complexity of 4, it is recommended to have a minimum of 4 test cases to cover all
//possible paths and decision points in the code.This will ensure that all branches are tested and increase
//the likelihood of finding potential bugs or issues.
//
//By having an appropriate number of test cases, we can have better code coverage and gain more confidence
//in the correctness of the program.However, it's important to note that cyclomatic complexity is just one
//aspect of measuring program complexity, and additional factors should be considered for comprehensive testing.

/*Ȧ���Ӷȣ�Cyclomatic complexity����һ�ֺ�����������������Ե��������ָ�꣬�����ڳ����еľ��ߵ������Ͷ���·��������������
 *�����԰���ʶ������е��߼������Ϳ��ܵ�ִ��·���������Ӷ��ṩ�˶Դ���������⡢���Ժ�ά���̶ȵĹ��ơ�

��������Ȧ���Ӷȿ���ʹ�����¹�ʽ��

M = E - N + 2

���У�
- M ��Ȧ���Ӷ�
- E �Ǳߵ���������������֧��
- N �ǽڵ�����������ߵ㣩

Ȧ���Ӷ�Խ�ߣ������߼�Խ���ӣ����Ͳ�����������Խ���ѡ���Ȧ���Ӷȱ�ʾ������򵥡������ڹ���

Ȧ���Ӷȿ����ṩ���ڲ������������Ĳο���һ����˵������Ĳ���������������Ӧ����Ȧ���Ӷȣ���ȷ���������п��ܵ�·���;��ߵ㡣
ÿ����ͬ�Ĵ���·������Ӧ������һ�Ρ�

������һ���� C++ ʾ����˵��Ȧ���Ӷ����������߼������ԺͲ�������������ص�ʾ����

```cpp
#include <iostream>

int calculate(int x, int y, int z) {
  int result;

  if (x > 0) {
    if (y > 0) {
      result = x + y;
    } else {
      result = x - y;
    }
  } else {
    if (z > 0) {
      result = x * z;
    } else {
      result = x / z;
    }
  }

  return result;
}

int main() {
  int a = 10, b = 5, c = 2;
  int res = calculate(a, b, c);
  
  std::cout << "Result: " << res << std::endl;

  return 0;
}
```

�����ʾ���У�`calculate` �����������������������������Щ������ִֵ��һϵ��Ƕ�׵� if-else �������������ж�����ߵ㣬
����ִ�в�ͬ��·����

Ҫ����Ȧ���Ӷȣ�������Ҫͳ�ƾ��ߵ���������ڵ㣩�Ϳ�������֧���������ߣ�������������У�
�������ĸ����ߵ㣨`x > 0`��`y > 0`��`z > 0` ������ `return` ��䣩���Լ�������������֧��ÿ�� if-else ����������֧������ˣ�Ȧ���Ӷ�Ϊ 6 - 4 + 2 = 4��

����Ȧ���Ӷ�Ϊ 4������������ 4 ���������������Ǵ����е����п���·���;��ߵ㡣�⽫ȷ�����з�֧�������ԣ�
�����ӷ���Ǳ�ڴ��������Ŀ����ԡ�

ͨ��ʹ���ʵ������Ĳ������������ǿ�����ߴ��븲���ʣ��Գ�����ȷ�Ը������ġ�Ȼ������Ҫע����ǣ�
Ȧ���Ӷ�ֻ�Ǻ����������Ե�һ�����棬�ۺϿ����������ؽ���ȫ����ԡ�*/


