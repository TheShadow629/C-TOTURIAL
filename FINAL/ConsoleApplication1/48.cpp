//��Ҫ�ֶ�ʵ��set�Ĳ�����
//The Set data structure is an unordered collection of unique elements.
//It represents a mathematical set and is commonly used in computer science
//to store a collection of distinct values. Sets do not allow duplicate elements,
//and the order of elements is not important.
//
//Common set operations include:
//
//1. Insertion: Adds an element to the set if it doesn't already exist.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - If it doesn't, add the element to the set.
//   - Preconditions: None.
//
//2. Deletion: Removes an element from the set if it exists.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - If it does, remove the element from the set.
//   - Preconditions: None.
//
//3. Membership Test: Checks if an element exists in the set.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - Return true if it does, false otherwise.
//   - Preconditions: None.
//
//4. Union: Combines two sets, resulting in a new set that contains all elements from both sets.
//   - Algorithm:
//     - Create an empty set to hold the union of the two sets.
//     - Add all elements from the first set to the new set.
//     - Iterate over the second set and add only the elements that do not already exist in the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//5. Intersection: Finds elements that exist in both sets, resulting in a new set.
//   - Algorithm:
//     - Create an empty set to hold the intersection of the two sets.
//     - Iterate over the elements in one set.
//     - If an element exists in the other set, add it to the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//6. Difference: Finds elements in the first set that do not exist in the second set, resulting in a new set.
//   - Algorithm:
//     - Create an empty set to hold the difference of the two sets.
//     - Iterate over the elements in the first set.
//     - If an element does not exist in the second set, add it to the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//Efficiency of the algorithms:
//
//- The efficiency of set operations depends on the underlying implementation of the Set data structure.
//Common implementations, such as HashSet or Red-Black Tree, offer efficient average-case time complexities
//for operations like insertion, deletion, and membership testing. These operations typically have an
//average-case time complexity of O(1) or O(log n), where n is the number of elements in the set. However,
//worst-case scenarios can occur if there are many hash collisions or unbalanced trees, resulting in a time
//complexity of O(n).
//- The efficiency of set operations also depends on the hash code or comparison function used for elements.
//For a hash-based set, a good hash function can distribute elements evenly, reducing the chance of collisions
//and providing efficient average-case behavior.
//- The efficiency of the Union, Intersection, and Difference operations is dependent on the sizes of the sets
//being operated on. In the worst case, they have a time complexity of O(n), where n is the size of the larger set.
//
//Preconditions for efficient algorithms:
//
//- To achieve efficient set operations, it is important to use an appropriate implementation of the Set
//data structure that provides efficient average-case time complexities.
//- It is crucial to ensure that the elements in the set have well-distributed hash codes or an effective
//comparison function to minimize collisions.
//- For Union, Intersection, and Difference operations, the efficiency is affected by the sizes of the sets.
//If one set is significantly larger than the other, it can impact the performance.

//���ϣ�Set�����ݽṹ��һ������ġ�Ԫ��Ψһ�ļ��ϡ�����������ѧ�еļ��ϸ���ڼ������ѧ�г����ڴ洢���ظ���ֵ��
//���ϲ������ظ���Ԫ�أ���Ԫ�ص�˳�򲢲���Ҫ��
//
//�����ļ��ϲ���������
//
//1. ���룺��Ԫ����ӵ������У�����������ڵĻ���
//   - �㷨��
//     - ��鼯�����Ƿ���ڸ�Ԫ�ء�
//     - ��������ڣ���Ԫ����ӵ������С�
//   - ǰ���������ޡ�
//
//2. ɾ�����Ӽ�����ɾ��һ�����ڵ�Ԫ�ء�
//   - �㷨��
//     - ��鼯�����Ƿ���ڸ�Ԫ�ء�
//     - ������ڣ���Ӽ�����ɾ����Ԫ�ء�
//   - ǰ���������ޡ�
//
//3. ��Ա���ԣ����Ԫ���Ƿ�����ڼ����С�
//   - �㷨��
//     - ��鼯�����Ƿ���ڸ�Ԫ�ء�
//     - ������ڣ��򷵻� true�����򷵻� false��
//   - ǰ���������ޡ�
//
//4. �������ϲ��������ϣ�����һ��������������������Ԫ�ص��¼��ϡ�
//   - �㷨��
//     - ����һ���ռ��ϣ����ڴ洢�������ϵĲ�����
//     - ����һ�������е�����Ԫ����ӵ��¼����С�
//     - �����ڶ������ϣ�ֻ�����Щ���¼����в����ڵ�Ԫ�ء�
//     - �����¼��ϡ�
//   - ǰ���������ޡ�
//
//5. �������ҳ����������й�ͬ���ڵ�Ԫ�أ�����һ���¼��ϡ�
//   - �㷨��
//     - ����һ���ռ��ϣ����ڴ洢�������ϵĽ�����
//     - ��������һ�����ϵ�Ԫ�ء�
//     - ���һ��Ԫ��Ҳ��������һ�������У�������ӵ��¼����С�
//     - �����¼��ϡ�
//   - ǰ���������ޡ�
//
//6. ����ҳ���һ�������д��ڵ��ڶ��������в����ڵ�Ԫ�أ�����һ���¼��ϡ�
//   - �㷨��
//     - ����һ���ռ��ϣ����ڴ洢�������ϵĲ��
//     - ������һ�����ϵ�Ԫ�ء�
//     - ���һ��Ԫ�ز������ڵڶ��������У�������ӵ��¼����С�
//     - �����¼��ϡ�
//   - ǰ���������ޡ�
//
//�㷨��Ч�ʣ�
//
//- ���ϲ�����Ч��ȡ���ڼ������ݽṹ��ʵ�ַ�ʽ��������ʵ�ַ�ʽ�����ϣ���ϣ�HashSet����������Red-Black Tree����
//���ڲ��롢ɾ���ͳ�Ա���ԵȲ�����ͨ������ƽ��ʱ�临�Ӷ�ΪO(1)��O(log n)��Ч�ʣ�����n�Ǽ����е�Ԫ��������
//Ȼ�����ڴ��ڴ�����ϣ��ͻ������ƽ�������£������µ�ʱ�临�Ӷȿ���ΪO(n)��
//- ���ϲ�����Ч�ʻ�ȡ����Ԫ�صĹ�ϣ���ȽϺ�����ѡ�񡣶��ڻ��ڹ�ϣ�ļ��ϣ����õĹ�ϣ�������Ծ��ȵطֲ�Ԫ�أ�
//������ײ�Ļ��ᣬ�ṩ��Ч��ƽ�������Ϊ��
//- ���ڲ����������Ͳ��������Ч��ȡ�������������ϵĴ�С�����������£����ǵ�ʱ�临�Ӷ�ΪO(n)������n�ǽϴ󼯺ϵĴ�С��
//
//�㷨��ǰ��������
//
//- Ҫʵ�ָ�Ч�ļ��ϲ�������Ҫѡ���ʵ��ļ������ݽṹʵ�֣����ṩ��Ч��ƽ��ʱ�临�Ӷȡ�
//- ȷ�������е�Ԫ�ؾ������÷ֲ��Ĺ�ϣ�����Ч�ıȽϺ���������С����ײ�ķ�����
//- ���ڲ����������Ͳ��������Ч���ܵ����ϴ�С��Ӱ�졣���һ������Զ������һ�����ϣ����ܻ�Ӱ�����ܡ�