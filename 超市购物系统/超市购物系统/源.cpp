#include<iostream>                     
#include<fstream>
#include<string>
#include<iomanip>
#include<ctime>
#include<windows.h>
using namespace std;
string td;
class Product                   //��Ʒ��
{
private:                     //˽�����ݳ�Ա
	double price;
	char name[30];
	long  number;
public:                             //��Ա����
	double getprice()              //��ȡ��Ʒ�۸�
	{
		return price;
	}
	char *getname()                //��ȡ��Ʒ��
	{
		return name;
	}
	long getnumber()              //��ȡ��Ʒ������
	{
		return number;
	}
	double setprice()              //���ü۸�
	{
		cout << "�� �� �� �� �� : ";
		cin >> price;
	}
	string  setname()              //������Ʒ��
	{
		cout << "�� �� �� �� Ʒ �� : ";
		cin >> name;
	}
	void setnumber()                //������Ʒ������
	{
		cout << "�� �� �� �� Ʒ �� �� �� : ";
		cin >> number;
	}
	void addproduct();                  //������Ʒ
	void search();						//������Ʒ��Ϣ
	void change();						// ������Ʒ��Ϣ
	void display();                      //��ʾ��Ʒ��Ϣ
	int del(int k = 0);                     //ɾ����Ʒ��Ϣ
};

void  Product::addproduct()                  //������Ʒ  
{
	string pnumber, nam;
	int k = 0;
	cout << "�� �� �� �� Ʒ �� �� �� : ";
	cin >> pnumber;
	nam = "D:\\��Ʒ\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (infile)
	{
		cout << "                    ����Ʒ�Ѵ���,������ѡ��!" << endl;
		k = 1;
		infile.close();
	}
	infile.close();
	if (k == 0)
	{
		ofstream outfile(nam.c_str());
		if (!outfile)
		{
			cout << "                     ϵͳ���ִ��������±���!" << endl;
		}
		if (outfile)
		{
			outfile << setw(20) << "��Ʒ������:" << pnumber << endl;
			cout << "�� �� �� �� Ʒ �� �� : ";
			cin >> price;
			outfile << setw(20) << "��Ʒ�۸�:" << price << endl;
			cout << "�� �� �� �� Ʒ �� : ";
			cin >> name;
			outfile << setw(20) << "��Ʒ��:" << name << endl;
			outfile.close();
			cout << "                ������Ʒ�ɹ�!" << endl;
		}
	}
}

void Product::search()             //������Ʒ��Ϣ
{
	string pnumber, nam;
	cout << "�� �� �� �� Ʒ �� �� ��: ";
	cin >> pnumber;
	nam = "D:\\��Ʒ\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "								δ�ҵ�����Ʒ����˶� !" << endl;
	}
	else
	{
		cout << "                        ����Ʒ���ڣ��������ѯ������Ϣ !" << endl;
		infile.close();
	}
}

void Product::change()            // ������Ʒ��Ϣ
{
	string pnumber, nam;
	int m = 0;
	m = del(1);
	if (m == 1)
	{
		nam = "D:\\��Ʒ\\" + pnumber + ".txt";
		ofstream outfile(nam.c_str());
		if (outfile)
		{
			cout << "                         �� �� �� �� �� �� �� �� Ʒ �� Ϣ !";
			cout << "                               �� Ʒ �� : ";
			cin >> name;
			cout << "                               �� Ʒ �� �� �� : ";
			cin >> number;
			cout << "                               �� Ʒ �� �� : ";
			cin >> price;
			outfile << setw(20) << "��Ʒ������:" << number << endl;
			outfile << setw(20) << "��Ʒ�۸�:" << price << endl;
			outfile << setw(20) << "��Ʒ��:" << name << endl;
			outfile.close();
		}
	}
}

void Product::display()                      //��ʾ��Ʒ��Ϣ
{
	string pnumber, nam;
	cout << "�� �� �� Ҫ �� �� �� Ʒ �� �� �� ��";
	cin >> pnumber;
	nam = "D:\\��Ʒ\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "						 ����Ʒ�����ڣ���˶�!" << endl;
	}
	else
	{
		cout << "					  ����Ʒ����!��Ʒ��Ϣ����:" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
	}
	infile.close();
}

int Product::del(int k)                     //ɾ����Ʒ��Ϣ
{
	string pnumber, nam;
	cout << "�� �� �� �� Ʒ �� �� �� : ";
	cin >> pnumber;
	nam = "D:\\��Ʒ\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "							����Ʒ�����ڣ���˶�!" << endl;
		return 0;
	}
	else
	{
		infile.close();
		DeleteFile(nam.c_str());
		if (k == 0)  cout << "								ɾ���ɹ�!" << endl;
		return 1;
	}
}


class Member		                //��Ա��
{
private:
	char name[30];
	int  number;
	unsigned long int pnumber;

public:
	void addcustomer();                      //���ӻ�Ա
	int search(int k = 0);                     //���һ�Ա
	void change();                   // ���Ļ�Ա��Ϣ
	void display();                                   //��ʾ��Ա��Ϣ
	int del(int k = 0);                     //ɾ����Ա��Ϣ
};


void Member::addcustomer()                      //���ӻ�Ա
{
	string cnumber, nu;
	int k = 0;
	cout << "�� �� �� �� Ա �� �� : ";
	cin >> cnumber;
	nu = "D:\\��Ա\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (infile)
	{
		cout << "                   �û�Ա�Ѵ��ڣ�����������ѡ��!" << endl;
		k = 1;
		infile.close();
	}
	infile.close();
	if (k == 0)
	{
		ofstream outfile(nu.c_str());
		if (!outfile)
		{
			cout << "                          ϵͳ���ִ��������±��棡" << endl;
		}
		if (outfile)
		{
			cout << "�� �� �� �� Ա �� �� : ";
			cin >> name;
			outfile << setw(20) << "��Ա��:" << name << endl;
			outfile << setw(20) << "��Ա����:" << cnumber << endl;
			cout << "�� �� �� �� Ա �� �� �� : ";
			cin >> pnumber;
			outfile << setw(20) << "��Ա�ֻ���:" << pnumber << endl;
			outfile.close();
			cout << "                       �����Ա�ɹ�!" << endl;
		}
	}
}

int Member::search(int k)                     //���һ�Ա
{
	string cnumber, nu;
	cout << "�������Ա����";
	cin >> cnumber;
	nu = "D:\\��Ա\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "δ�ҵ��û�Ա����˶�!" << endl;
		return 0;
	}
	if (infile)
	{
		if (k == 0) cout << "�û�Ա���ڣ��������ѯ������Ϣ !" << endl;
		infile.close();
		return 1;
	}
	return 0;
}

void Member::change()                   // ���Ļ�Ա��Ϣ
{
	string cnumber, nu;
	int m = 1;
	m = del(1);
	if (m == 1)
	{
		cout << "			��������ĺ�Ļ�Ա��Ϣ!";
		cout << "�� Ա �� ��: ";
		cin >> cnumber;
		nu = "D:\\��Ա\\" + cnumber + ".txt";
		ofstream outfile(nu.c_str());
		if (outfile)
		{
			cout << "�� Ա �� : ";
			cin >> name;
			cout << "�� Ա �� �� �� ��";
			cin >> pnumber;
			outfile << setw(20) << "��Ա����:" << name << endl;
			outfile << setw(20) << "��Ա����:" << cnumber << endl;
			outfile << setw(20) << "��Ա�ֻ���:" << pnumber << endl;
			outfile.close();
		}
	}
}

void Member::display()                                   //��ʾ��Ա��Ϣ
{
	string cnumber, nu;
	cout << "�� �� �� Ҫ �� �� �� Ա �� �� Ա �� �� ��";
	cin >> cnumber;
	nu = "D:\\��Ա\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "                      �û�Ա�����ڣ���˶�!" << endl;
	}
	else
	{
		cout << "                      �û�Ա����!��Ա��Ϣ���£�" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
	}
}

int Member::del(int k)                     //ɾ����Ա��Ϣ
{
	string cnumber, nu;
	cout << "�� �� �� �� Ա �� �� : ";
	cin >> cnumber;
	nu = "D:\\��Ա\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "                      �û�Ա�����ڣ���˶�!" << endl;
		return 0;
	}
	if (infile)
	{
		infile.close();
		DeleteFile(nu.c_str());
		if (k == 0)   cout << "ɾ���ɹ�!" << endl;
		return 1;
	}
	return 0;
}


class Vip :public Member			                //vip��
{
private:
	char name[30];
	int  numbervip;
	unsigned long int pnumber;

public:
	int addvip();								//����vip
	void searchvip();							//����vip
	void changevip();							// ����vip��Ϣ
	void displayvip();							//��ʾvip��Ϣ
	int delvip(int k = 0);						//ɾ��vip��Ϣ
	void memv();								//member���VIP
};


int Vip::addvip()						//����vip
{
	string vnumber, vn;
	int k = 0;
	cout << "�� �� �� VIP �� ��: ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (infile)
	{
		cout << "                     ��VIP�Ѵ��ڣ�������ѡ��!" << endl;
		k = 1;
		infile.close();
	}
	if (k == 0)
	{
		ofstream outfile(vn.c_str());
		if (!outfile)
		{
			cout << "                           ϵͳ���ִ��������±���!" << endl;
		}
		if (outfile)
		{
			cout << "�� �� �� VIP �� ��: ";
			cin >> name;
			outfile << setw(20) << "VIP����:" << name << endl;
			outfile << setw(20) << "VIP����:" << vnumber << endl;
			cout << "�� �� �� VIP �� �� ��:";
			cin >> pnumber;
			outfile << setw(20) << "VIP�ֻ���:" << pnumber << endl;
			outfile.close();
			cout << "                           ����VIP�ɹ�!" << endl;
			return 1;
		}
	}
	return 0;
}

void Vip::searchvip()                   //����vip
{
	string vnumber, vn;
	cout << "�� �� �� vip �� �� : ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                       δ�ҵ���vip����˶�" << endl;
	}
	else
	{
		cout << "                      ��vip���ڣ��������ѯ������Ϣ ��" << endl;
		infile.close();
	}
}

void Vip::changevip()                        // ����vip��Ϣ
{
	string vnumber, vn;
	int m = 0;
	m = delvip(1);
	if (m == 1)
	{
		vn = "D:\\VIP\\" + vnumber + ".txt";
		ofstream outfile(vn.c_str());
		if (outfile)
		{
			cout << "                    ��������ĺ�VIP��Ϣ!";
			cout << "vip �� �� : ";
			cin >> name;
			cout << "vip �� �� : ";
			cin >> numbervip;
			cout << "vip �� �� �� �� : ";
			cin >> pnumber;
			outfile << setw(20) << "VIP����:" << name << endl;
			outfile << setw(20) << "VIP����:" << numbervip << endl;
			outfile << setw(20) << "VIP�ֻ���:" << pnumber << endl;
			outfile.close();
		}
	}
}

void Vip::displayvip()                  //��ʾvip��Ϣ
{
	string vnumber, vn;
	cout << "�� �� �� Ҫ �� �� vip �� vip �� �ţ�";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                     ��vip�����ڣ���˶�!" << endl;
	}
	else
	{
		cout << "                    ��vip����!vip��Ϣ���£�" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
		infile.close();
	}
}

int Vip::delvip(int k)                    //ɾ��vip��Ϣ
{
	string vnumber, vn;
	cout << "�� �� �� vip �� �� : ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                      ��vip�����ڣ���˶�!";
		return 0;
	}
	if (infile)
	{
		infile.close();
		DeleteFile(vn.c_str());
		if (k == 0) cout << "ɾ���ɹ�!" << endl;
		return 1;
	}
	return 0;
}

void Vip::memv()                            //member���VIP
{
	int flag = 0, flag1 = 0;
	Member m;
	flag = m.search(1);
	if (flag == 1)
	{
		cout << "						 �û�Ա����!�����!" << endl;
		while (flag1 == 0)	flag1 = addvip();
		m.del(1);
	}
}

int charge()                            //����Աϵͳ
{
	system("cls");
	system("color 5f");
	int cchoice = 1;
	char name[20];
  	while (cchoice != 0)
	{
		if (cchoice != 3)
		{
			cout << "                  �q------------< ����Ա >-----------�r" << endl;
			cout << "                 �O                                   �O" << endl;
			cout << "                 ��-----------------------------------��" << endl;
			cout << "                 �O            1.����Աע��           �O" << endl;
			cout << "                 �O            2.����Ա��½           �O" << endl;
			cout << "                 �O            3.��   ��              �O" << endl;
			cout << "                 �t-----------------------------------�s" << endl;
			cout << "                           ��ѡ����Ҫ��������:";
			cin >> cchoice;
			if ((cchoice != 1) && (cchoice != 2) && (cchoice != 3))
			{
				cout << "                          �����������������룡" << endl;
				continue;
			}
		}
		if (cchoice == 1)
		{
			string ad, wn;
			cout << "�� �� �� �� �� : ";
			cin >> ad;
			wn = "D:\\����Ա\\" + ad + ".txt";
			ifstream infile(wn.c_str());
			if (infile)
			{
				cout << "                                  ��ע��!" << endl;
				continue;
			}
			ofstream outfile(wn.c_str());
			if (!outfile)
			{
				cout << "                               �д���������!" << endl;
				continue;
			}
			cout << "�� �� �� �� �� : ";
			cin >> name;
			outfile << setw(10) << "����: " << name << endl;
			outfile << setw(10) << "����: " << ad << endl;
			cout << "                            ��ӭ��ע��ɹ���" << endl;
		}
		if (cchoice == 2)
		{
			string wn, ad;
			cout << "�� �� �� �� �� �� �� : ";
			cin >> ad;
			wn = "D:\\����Ա\\" + ad + ".txt";
			ifstream infile(wn.c_str());
			{
				if (infile)
				{
					cout << "              ������   ��   ӭ   ��   ��    ������" << endl;
					return 'a';
				}
				if (!infile)
				{
					cout << "                  �����������������˶ԣ�" << endl;
				}
			}
			continue;
		}
		if (cchoice == 3)
			return 2;
	}
	return 0;
}

int shouying_system()
{
	system("color 3b");
	int cho = 1;
	while (cho != 0)
	{
		cout << "          ���������      ��������ϵͳ      ���������" << endl;
		cout << "          ********************************************************" << endl;
		cout << "          *       ��Ʒ֧��ϵͳ---------------------------1       *" << endl;
		cout << "          *       ��Ա����ϵͳ---------------------------2       *" << endl;
		cout << "          *       VIP ����ϵͳ---------------------------3       *" << endl;
		cout << "          *       ��Ʒ����ϵͳ---------------------------4       *" << endl;
		cout << "          *       �鿴�����������-----------------------5       *" << endl;
		cout << "          *       �� ��----------------------------------6       *" << endl;
		cout << "          ********************************************************" << endl;
		cout << "                           ����������ָ�" << endl;
		cin >> cho;
		if (cho == 1) { return 1; }
		if (cho == 2) { return 2; }
		if (cho == 3) { return 3; }
		if (cho == 4) { return 4; }
		if (cho == 5) { return 5; }
		if (cho == 6) { return 6; }
	}
	return 0;
}

int productpay_system()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	system("color 3c");
	double income = 0, total, price, quantity;
	string pn, pm, mov, s;
	int f, k, flag = 0, flag1 = 1, flag2 = 1;
	while (flag == 0)
	{
		if (flag1 == 2)
		{
			cout << "             1.����֧����Ʒ          2.��������ϵͳ";
			cin >> flag2;
		}
		if (flag2 == 2) return 1;
		if (flag2 == 1)
		{
			cout << "�� �� �� �� Ʒ �� �� �� ��";
			cin >> pn;
			pm = "D:\\��Ʒ\\" + pn + ".txt";
			ifstream infile(pm.c_str());
			if (!infile)
			{
				cout << "                              δ�ҵ�����Ʒ��" << endl;
				cout << "1.�� �� �� ��     2.�� ��";
				cin >> k;
				if (k == 1)
				{
					k = 0;
					continue;
				}
				if (k == 2) { f = 0, flag = 0; flag1 = 2; }
			}
			if (infile)
			{
				while (getline(infile, s))
				{
					cout << s << endl;
				}
				cout << "��������Ʒ���ۣ�";
				cin >> price;
				cout << "������������������";
				cin >> quantity;
				cout << "1:��Ա 2��VIP 3����ͨ�˿�" << endl;
				cout << "����ѯ�ʣ����ǻ�Ա��VIP��������Ӧ���ֽ���ϵͳ��";
				cin >> f;
			}
			while (f == 1)
			{
				string a, mn;
				cout << "�� �� Ա �� �� ��";
				cin >> a;
				mn = "D:\\��Ա\\" + a + ".txt";
				ifstream infile(mn.c_str());
				if (!infile)
				{
					cout << "                  δ�ҵ��û�Ա��" << endl;
					cout << "1.�� �� �� ��     2.�� ��";
					cin >> k;
					if (k == 1)
					{
						k = 0;
						continue;
					}
					if (k == 2) { f = 0, flag = 0; flag1 = 2; }
				}
				if (infile)
				{
					string in;
					string date;
					total = price * quantity*0.9;
					income = income + total;
					cout << "Ӧ �� �� �� ��" << total << endl;
					in = "D:\\����\\��Ա����\\" + td + ".txt";
					ofstream outfile(in.c_str());
					outfile << income << '\t' << sys.wSecond << '/' << sys.wMinute << '/' << sys.wHour << endl;
					f = 0, flag = 0; flag1 = 2;
				}
			}
			while (f == 2)
			{
				string b, vn;
				cout << "�� �� �� VIP �� �� ��";
				cin >> b;
				vn = "D:\\VIP\\" + b + ".txt";
				ifstream infile(vn.c_str());
				if (!infile)
				{
					cout << "                              δ�ҵ���vip��" << endl;
					cout << "1.�� �� �� ��     2.�� ��";
					cin >> k;
					if (k == 1)
					{
						k = 0;
						continue;
					}
					if (k == 2) { f = 0, flag = 0; flag1 = 2; }
				}
				if (infile)
				{
					infile.close();
					total = price * quantity*0.8;
					income = income + total;
					string in;
					string date;
					cout << "Ӧ �� �� �" << total << endl;
					in = "D:\\����\\VIP����\\" + td + ".txt";
					ofstream outfile(in.c_str());
					outfile << income << '\t' << sys.wSecond << '/' << sys.wMinute << '/' << sys.wHour << endl;
					f = 0, flag = 0; flag1 = 2;
				}
			}
			while (f == 3)
			{
				total = price * quantity;
				cout << "Ӧ����" << total << endl;
				income = income + total;
				string in;
				string date;
				in = "D:\\����\\��ͨ����\\" + td + ".txt";
				ofstream outfile(in.c_str());
				outfile << income << '\t' << sys.wSecond << '/' << sys.wMinute << '/' << sys.wHour << endl;
				f = 0, flag = 0; flag1 = 2;
			}
		}
	}
	return 1;
}

int member_system()
{
	system("color 1d");
	Member m;
	int choic = 1;
	while (choic != 0)
	{
		{
			cout << "                 1.����               2.����           " << endl;
			cout << "                 3.����               4.��ʾ           " << endl;
			cout << "                 5.ɾ��               6.����           " << endl;
			cout << "����������ָ�";
			cin >> choic;
		}
		if (choic == 1)
		{
			m.addcustomer(); continue;
		}
		if (choic == 2)
		{
			m.search(); continue;
		}
		if (choic == 3)
		{
			m.change(); continue;
		}
		if (choic == 4)
		{
			m.display(); continue;
		}
		if (choic == 5)
		{
			m.del(0); continue;
		}
		if (choic == 6)
		{
			return 1;
		}
	}
	return 0;
}

int vip_system()
{
	system("color 4a");
	Vip v;
	int choic = 1;
	while (choic != 0)
	{
		{
			cout << "                 1.����               2.����           " << endl;
			cout << "                 3.����               4.��ʾ           " << endl;
			cout << "                 5.ɾ��               6.����           " << endl;
			cout << "                 7.��Ա���VIP                         " << endl;
			cout << "����������ָ�";
			cin >> choic;
		}
		if (choic == 1)
		{
			v.addvip(); continue;
		}
		if (choic == 2)
		{
			v.searchvip(); continue;
		}
		if (choic == 3)
		{
			v.changevip(); continue;
		}
		if (choic == 4)
		{
			v.displayvip(); continue;
		}
		if (choic == 5)
		{
			v.delvip(0); continue;
		}
		if (choic == 6)
		{
			return 1;
		}
		if (choic == 7)
		{
			v.memv(); continue;
		}
	}
	return 0;
}

int productmanage_system()
{
	system("color 5e");
	Product p;
	int ch = 1;
	while (ch != 0)
	{
		cout << "                 1.����               2.����           " << endl;
		cout << "                 3.����               4.ɾ��           " << endl;
		cout << "                 5.��ʾ               6.����           " << endl;
		cout << "����������ָ��: ";
		cin >> ch;
		if (ch == 1)
		{
			p.addproduct(); continue;
		}
		if (ch == 2)
		{
			p.change(); continue;
		}
		if (ch == 3)
		{
			p.search(); continue;
		}
		if (ch == 4)
		{
			p.del(0); continue;
		}
		if (ch == 5)
		{
			p.display(); continue;
		}
		if (ch == 6)
			return 1;
	}
	return 0;
}

int showincome_system()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	system("color 2e");
	double tincome = 0, number;
	string s, in, date;
	cout << "������Ҫ��ѯ�����ڣ�";
	cin >> date;
	in = "D:\\����\\��Ա����\\" + date + ".txt";
	ifstream infile(in.c_str());
	if (!infile)
	{
		cout << "δ��ͳ�ƻ�Ա����" << endl;
	}
	while (getline(infile, s))
	{
		ofstream outfile("d:\\����\\totalincome.txt", ios::app);
		outfile << s << endl;
		infile.close();
	}
	string vn;
	vn = "D:\\����\\VIP����\\" + date + ".txt";
	ifstream fin(vn.c_str());
	if (!fin)
	{
		cout << "δ��ͳ��VIP����" << endl;
	}
	while (getline(fin, s))
	{
		ofstream outfile("d:\\����\\totalincome.txt", ios::app);
		outfile << s << endl;
		fin.close();
	}
	ifstream input_data;
	string pt;
	pt = "D:\\����\\��ͨ����\\" + date + ".txt";
	input_data.open(pt.c_str());
	if (!input_data)
	{
		cout << "δ��ͳ����ͨ�˿�����" << endl;
	}
	while (getline(input_data, s))
	{
		ofstream outfile("d:\\����\\totalincome.txt", ios::app);
		outfile << s << endl;
		input_data.close();
	}
	ifstream datafile("d:\\����\\totalincome.txt", ios::in);
	if (!datafile)
	{
		cout << "���ļ�δ����ȷ�򿪣�" << endl;
	}
	while (datafile >> number)
	{
		int se, m, h, d, m1, y;
		char d1, d2, d3, d4, d5;
		datafile >> se >> d1 >> m >> d2 >> h >> d3 >> d >> d4 >> m1 >> d5 >> y;
		tincome = tincome + number;
	}
	datafile.clear();
	cout << "������:" << tincome << endl;
	return 1;
}

int main()
{
	system("color 06f");
	extern string td;
	cout << "�����뵱ǰ���ڣ���/��/ �գ���";
	cin >> td;
	double income = 0, flag1 = 0, flag2 = 0;
	int c = 1, cho = 1, k, p;
	cout << "           ********************************************************" << endl;
	cout << "                 ��ӭʹ��!����Աϵͳ��!����ϸ�Ķ�ʹ��˵��!�� " << endl;
	cout << "           ********************************************************" << endl;
	cout << "                            please press 1!" << endl;
	cout << "                                ʹ��˵��                             " << endl;
	cout << "                   һ.�밴��ʾ����Ҫ��ѡ��" << endl;
	cout << "                   ��.������D�̽����ĸ��ļ���" << endl;
	cout << "                      ������Ա   �ڻ�Ա   ��VIP   ������" << endl;
	cout << "                   ��.���������ļ����н��������ļ���" << endl;
	cout << "                      �ٻ�Ա����   ��VIP����   ����ͨ����" << endl;
	cout << "                   ��.����Ҫ�ı�·��������ϵ��ؼ�����Ա" << endl;
	cout << "                   ��.ϵͳ���ڲ��Խ׶Σ�ллʹ��!" << endl;
	cin >> c;
	if (c != 1)
	{
		cout << "please press 1!" << endl;
		cin >> c;
	}
	while (c != 0)
	{
		system("cls");
		cout << "            ������   ��   ӭ    ʹ     �ã�  ������" << endl;
		cout << "                       ����Աϵͳ-------------1" << endl;
		cout << "                       ��  ��-----------------2" << endl;
		cin >> c;
		if (c == 1)
		{
			c = charge();
		}
		if (c == 'a')
		{
			cout << "                       ����ϵͳ----------------1" << endl;
			cout << "                       ��  ��------------------2" << endl;
			cout << "                       ��  ��------------------3" << endl;
			cin >> k;
			if (k == 2)
			{
				c = 2; continue;
			}
			while (k == 1)
			{
				int flag3 = 0;
				if (flag1 == 0) p = shouying_system();
				if (p == 1) { flag2 = productpay_system(); }
				if (p == 2) { flag2 = member_system(); }
				if (p == 3) { flag2 = vip_system(); }
				if (p == 4) { flag2 = productmanage_system(); }
				if (p == 5) { flag3 = 1; flag2 = showincome_system(); }
				if (p == 6) { k = 2; flag1 = 0; flag2 = 0; continue; }
				if (flag2 == 1)
				{
					if (flag3 == 0) system("cls");
					p = shouying_system();
					flag1 = 1;
				}
			}
			if (k == 3)
				exit(1);
		}
		if (c == 2)  exit(1);
	}
	return 0;
}
