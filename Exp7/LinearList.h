#pragma once

#include <vector>

class LinearList
{
	std::vector<int> intv;
public:
	//��λ��pos֮�����һ��Ԫ��x��
	//posΪ0ʱ���ڵ�һ��Ԫ��֮ǰ���롣
	//�����ɹ�ʱ����true�����򷵻�false��
	bool insert(int x, int pos); 

	//ɾ��λ��pos����Ԫ�ء�
	//�����ɹ�ʱ����true�����򷵻�false��
	bool remove(int &x, int pos); 

	//����λ��pos����Ԫ�ء�
	int element(int pos) const;
	//����ֵΪx��Ԫ�أ�����Ԫ�ص�λ�ã���һ��Ԫ�ص�λ��Ϊ1����δ�ҵ�ʱ����0��
	int search(int x) const;
	//����Ԫ�ظ�����
	int length() const;
};

