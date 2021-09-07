//- ��װ������ʾ�ý��� �� void showManu()
//- ��mian�����е��÷�װ�õĺ���

#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//@file:model
//@author:Zhaitizi
//@date:2021/8/26 13:59:05
//@brief:

//�����ϵ�˽ṹ��
struct Person
{ 
	string m_Name;      //����
	int m_Sex;          //�Ա�
	int m_Age;          //����
	string m_Phone;     //�绰
	string m_Address;   //סַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	Person personArray[MAX];   //ͨѶ¼�б������ϵ������
	int m_Size;                //ͨѶ¼�б������ϵ�˸���
};

//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������ܾ��������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� 1-----�� 2-----Ů" << endl;
		int sex = 0;

		while (true)   
		{
			//����������1����2�������˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;

		while (true)
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������1����2" << endl;
		}

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		//����ͨѶ¼�е�����
		abs->m_Size++;

		cout << "��ӳɹ���" << endl;

		system("pause");  //�밴���������
		system("cls");    //��������
	}
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж����ͨѶ¼�е������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Address << endl;
		}
	}

	system("pause");  //�밴���������
	system("cls");    //��������
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�˵�������" << endl;
	string name;
	cin >> name;
	//ret == -1 δ�鵽 ret != -1 �鵽��
	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1]; //����ǰ�Ƽ�ɾ����ǰ��¼
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}

	system("pause");  //�밴���������
	system("cls");    //��������
}

//4.������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ���ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret == -1) 
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Address << endl;
	}

	system("pause");  //�밴���������
	system("cls");    //��������
}

//5.�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ���ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա� 1-----�� 2-----Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1����2�������˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������1����2" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;

		while (true)
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "�޸ĳɹ�" << endl;
	}

	system("pause");  //�밴���������
	system("cls");    //��������
}

//6.�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;  //�����ڼ�¼��ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;

	system("pause");  //�밴���������
	system("cls");    //��������
}


//�˵�����
void showManu() 
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}

int main() {

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���

	while (true)
	{
		showManu();  //���ò˵�
		cin >> select;

		switch (select)
		{
		case 1:     //1.�����ϵ��
			addPerson(&abs);   //���õ�ַ��������ʵ��
			break;
		case 2:     //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:     //3.ɾ����ϵ��
		{	//case�������ᱨ����Ҫ��{}��������ʾΪ�����
		/*	cout << "������ɾ����ϵ�˵�������" << endl;
			string name;
			cin >> name;

			if ((isExist(&abs, name)) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}*/
			deletePerson(&abs);
			break;
		}
		case 4:     //4.������ϵ��
			findPerson(&abs);
			break;
		case 5:     //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:     //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:     //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

}