//Collision resolution refers to the process of handling collisions that occur when two or more keys are mapped to the same hash value in a hash table.When collisions happen, it becomes necessary to resolve them to ensure that each key can be stored and retrieved correctly.There are several collision resolution algorithms, but two commonly used ones are :
//
//1. Separate Chaining :
//-Approach : Separate chaining handles collisions by maintaining a linked list of key - value pairs at each index of the hash table.When a collision occurs, the new key - value pair is simply appended to the linked list at the corresponding index.
//- Advantages : Simple implementation, efficient for handling a large number of collisions, and doesn't require resizing of the hash table.
//- Disadvantages : Additional memory overhead due to the linked lists, and some cache inefficiency if the linked lists become long.
//
//2. Open Addressing :
//-Approach : Open addressing resolves collisions by searching for an alternative empty slot in the hash table and placing the collided key - value pair there.There are multiple variations of open addressing, including Linear Probing, Quadratic Probing, and Double Hashing.
//- Linear Probing : After a collision, the algorithm probes the next available slot(linearly incrementing the index) until an empty slot is found.
//- Quadratic Probing : The algorithm uses a quadratic function to probe subsequent slots(incrementing the index by a quadratic sequence) until an empty slot is found.
//- Double Hashing : The algorithm uses a secondary hash function to determine the interval between probes.It probes additional slots by applying the secondary hash function until an empty slot is found.
//- Advantages : Better cache performance because all elements are stored in contiguous memory locations.It requires less memory overhead than separate chaining.
//- Disadvantages : Can have more clustering issues if the hash table becomes crowded.It requires careful selection of probing techniques and resizing of the hash table when it becomes full.
//
//Both separate chaining and open addressing provide effective ways to handle collisions, and the choice between them depends on factors such as the expected number of collisions, memory constraints, and performance requirements.It's important to select an appropriate collision resolution algorithm based on the specific characteristics of the data being hashed.

//��ײ������ڹ�ϣ����������ʹ��ʱ�����������ϣ���з����ļ���ͻ�Ĺ��̡�������������ӳ�䵽��ϣ���е�ͬһ��ϣֵʱ��
//��������ͻ����ȷ��ÿ����������ȷ�ش洢�ͼ������м�����ײ����㷨���������ֳ��õ��ǣ�
//
//1. ����ַ����Separate Chaining����
//- ����������ַ��ͨ���ڹ�ϣ���ÿ��������ά��һ����ֵ�Ե������������ͻ����������ͻʱ��
//�µļ�ֵ�Ա�׷�ӵ���Ӧ�������������С�
//- �ŵ㣺ʵ�ּ򵥣������ڴ��������ͻ������Ҫ������ϣ��Ĵ�С��
//- ȱ�㣺�������ɶ�����ڴ濪������������úܳ������ܻᵼ��һЩ����Ч�����⡣
//
//2. ���ŵ�ַ����Open Addressing����
//- ���������ŵ�ַ��ͨ���ڹ�ϣ������������Ŀղ��������ͻ��������ͻ�ļ�ֵ�Է��������
//���ŵ�ַ���м��ֱ��֣���������̽�⡢����̽���˫��ɢ�С�
//- ����̽�⣺������ͻ���㷨���Եص���������ֱ���ҵ��ղۡ�
//- ����̽�⣺�㷨ʹ�ö��κ���������������ֱ���ҵ��ղۡ�
//- ˫��ɢ�У��㷨ʹ�õڶ�����ϣ������ȷ��̽��ļ����ֱ���ҵ��ղۡ�
//- �ŵ㣺��������Ԫ�ش洢���������ڴ�λ���ϣ����и��õĻ������ܡ�������ַ����Ҫ���ٵ��ڴ濪����
//- ȱ�㣺�����ϣ����ӵ�������ܻ���ָ���ľۼ����⡣����ϸѡ��̽�ⷽ�������ڹ�ϣ����ʱ�������С��
//
//����ַ���Ϳ��ŵ�ַ�����ṩ����Ч����ײ���������ѡ�����ַ���ȡ����Ԥ�ڵĳ�ͻ�������ڴ����ƺ�����Ҫ��
//����Ҫ��ϣ�����ݵ����ԣ�ѡ���ʵ�����ײ����㷨�ǳ���Ҫ��




















