#include<iostream>                     
#include<fstream>
#include<string>
#include<iomanip>
#include<ctime>
#include<windows.h>
using namespace std;
string td;
class Product                   //商品类
{
private:                     //私有数据成员
	double price;
	char name[30];
	long  number;
public:                             //成员函数
	double getprice()              //获取商品价格
	{
		return price;
	}
	char *getname()                //获取商品名
	{
		return name;
	}
	long getnumber()              //获取商品条形码
	{
		return number;
	}
	double setprice()              //设置价格
	{
		cout << "请 输 入 价 格 : ";
		cin >> price;
	}
	string  setname()              //设置商品名
	{
		cout << "请 输 入 商 品 名 : ";
		cin >> name;
	}
	void setnumber()                //设置商品条形码
	{
		cout << "请 输 入 商 品 条 形 码 : ";
		cin >> number;
	}
	void addproduct();                  //增加商品
	void search();						//查找商品信息
	void change();						// 更改商品信息
	void display();                      //显示商品信息
	int del(int k = 0);                     //删除商品信息
};

void  Product::addproduct()                  //增加商品  
{
	string pnumber, nam;
	int k = 0;
	cout << "请 输 入 商 品 条 形 码 : ";
	cin >> pnumber;
	nam = "D:\\商品\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (infile)
	{
		cout << "                    该商品已存在,请重新选择!" << endl;
		k = 1;
		infile.close();
	}
	infile.close();
	if (k == 0)
	{
		ofstream outfile(nam.c_str());
		if (!outfile)
		{
			cout << "                     系统出现错误，请重新保存!" << endl;
		}
		if (outfile)
		{
			outfile << setw(20) << "商品条形码:" << pnumber << endl;
			cout << "请 输 入 商 品 价 格 : ";
			cin >> price;
			outfile << setw(20) << "商品价格:" << price << endl;
			cout << "请 输 入 商 品 名 : ";
			cin >> name;
			outfile << setw(20) << "商品名:" << name << endl;
			outfile.close();
			cout << "                保存商品成功!" << endl;
		}
	}
}

void Product::search()             //查找商品信息
{
	string pnumber, nam;
	cout << "请 输 入 商 品 条 形 码: ";
	cin >> pnumber;
	nam = "D:\\商品\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "								未找到该商品，请核对 !" << endl;
	}
	else
	{
		cout << "                        该商品存在，详情请查询所有信息 !" << endl;
		infile.close();
	}
}

void Product::change()            // 更改商品信息
{
	string pnumber, nam;
	int m = 0;
	m = del(1);
	if (m == 1)
	{
		nam = "D:\\商品\\" + pnumber + ".txt";
		ofstream outfile(nam.c_str());
		if (outfile)
		{
			cout << "                         请 输 入 更 改 后 的 商 品 信 息 !";
			cout << "                               商 品 名 : ";
			cin >> name;
			cout << "                               商 品 条 形 码 : ";
			cin >> number;
			cout << "                               商 品 价 格 : ";
			cin >> price;
			outfile << setw(20) << "商品条形码:" << number << endl;
			outfile << setw(20) << "商品价格:" << price << endl;
			outfile << setw(20) << "商品名:" << name << endl;
			outfile.close();
		}
	}
}

void Product::display()                      //显示商品信息
{
	string pnumber, nam;
	cout << "请 输 入 要 查 找 商 品 条 形 码 ：";
	cin >> pnumber;
	nam = "D:\\商品\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "						 该商品不存在，请核对!" << endl;
	}
	else
	{
		cout << "					  该商品存在!商品信息如下:" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
	}
	infile.close();
}

int Product::del(int k)                     //删除商品信息
{
	string pnumber, nam;
	cout << "请 输 入 商 品 条 形 码 : ";
	cin >> pnumber;
	nam = "D:\\商品\\" + pnumber + ".txt";
	ifstream infile(nam.c_str());
	if (!infile)
	{
		cout << "							该商品不存在，请核对!" << endl;
		return 0;
	}
	else
	{
		infile.close();
		DeleteFile(nam.c_str());
		if (k == 0)  cout << "								删除成功!" << endl;
		return 1;
	}
}


class Member		                //会员类
{
private:
	char name[30];
	int  number;
	unsigned long int pnumber;

public:
	void addcustomer();                      //增加会员
	int search(int k = 0);                     //查找会员
	void change();                   // 更改会员信息
	void display();                                   //显示会员信息
	int del(int k = 0);                     //删除会员信息
};


void Member::addcustomer()                      //增加会员
{
	string cnumber, nu;
	int k = 0;
	cout << "请 输 入 会 员 卡 号 : ";
	cin >> cnumber;
	nu = "D:\\会员\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (infile)
	{
		cout << "                   该会员已存在，请重新输入选择!" << endl;
		k = 1;
		infile.close();
	}
	infile.close();
	if (k == 0)
	{
		ofstream outfile(nu.c_str());
		if (!outfile)
		{
			cout << "                          系统出现错误，请重新保存！" << endl;
		}
		if (outfile)
		{
			cout << "请 输 入 会 员 姓 名 : ";
			cin >> name;
			outfile << setw(20) << "会员名:" << name << endl;
			outfile << setw(20) << "会员卡号:" << cnumber << endl;
			cout << "请 输 入 会 员 手 机 号 : ";
			cin >> pnumber;
			outfile << setw(20) << "会员手机号:" << pnumber << endl;
			outfile.close();
			cout << "                       保存会员成功!" << endl;
		}
	}
}

int Member::search(int k)                     //查找会员
{
	string cnumber, nu;
	cout << "请输入会员卡号";
	cin >> cnumber;
	nu = "D:\\会员\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "未找到该会员，请核对!" << endl;
		return 0;
	}
	if (infile)
	{
		if (k == 0) cout << "该会员存在，详情请查询所有信息 !" << endl;
		infile.close();
		return 1;
	}
	return 0;
}

void Member::change()                   // 更改会员信息
{
	string cnumber, nu;
	int m = 1;
	m = del(1);
	if (m == 1)
	{
		cout << "			请输入更改后的会员信息!";
		cout << "会 员 卡 号: ";
		cin >> cnumber;
		nu = "D:\\会员\\" + cnumber + ".txt";
		ofstream outfile(nu.c_str());
		if (outfile)
		{
			cout << "会 员 名 : ";
			cin >> name;
			cout << "会 员 手 机 号 ：";
			cin >> pnumber;
			outfile << setw(20) << "会员姓名:" << name << endl;
			outfile << setw(20) << "会员卡号:" << cnumber << endl;
			outfile << setw(20) << "会员手机号:" << pnumber << endl;
			outfile.close();
		}
	}
}

void Member::display()                                   //显示会员信息
{
	string cnumber, nu;
	cout << "请 输 入 要 查 找 会 员 的 会 员 卡 号 ：";
	cin >> cnumber;
	nu = "D:\\会员\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "                      该会员不存在，请核对!" << endl;
	}
	else
	{
		cout << "                      该会员存在!会员信息如下：" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
	}
}

int Member::del(int k)                     //删除会员信息
{
	string cnumber, nu;
	cout << "请 输 入 会 员 卡 号 : ";
	cin >> cnumber;
	nu = "D:\\会员\\" + cnumber + ".txt";
	ifstream infile(nu.c_str());
	if (!infile)
	{
		cout << "                      该会员不存在，请核对!" << endl;
		return 0;
	}
	if (infile)
	{
		infile.close();
		DeleteFile(nu.c_str());
		if (k == 0)   cout << "删除成功!" << endl;
		return 1;
	}
	return 0;
}


class Vip :public Member			                //vip类
{
private:
	char name[30];
	int  numbervip;
	unsigned long int pnumber;

public:
	int addvip();								//增加vip
	void searchvip();							//查找vip
	void changevip();							// 更改vip信息
	void displayvip();							//显示vip信息
	int delvip(int k = 0);						//删除vip信息
	void memv();								//member变成VIP
};


int Vip::addvip()						//增加vip
{
	string vnumber, vn;
	int k = 0;
	cout << "请 输 入 VIP 卡 号: ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (infile)
	{
		cout << "                     该VIP已存在，请重新选择!" << endl;
		k = 1;
		infile.close();
	}
	if (k == 0)
	{
		ofstream outfile(vn.c_str());
		if (!outfile)
		{
			cout << "                           系统出现错误，请重新保存!" << endl;
		}
		if (outfile)
		{
			cout << "请 输 入 VIP 姓 名: ";
			cin >> name;
			outfile << setw(20) << "VIP姓名:" << name << endl;
			outfile << setw(20) << "VIP卡号:" << vnumber << endl;
			cout << "请 输 入 VIP 手 机 号:";
			cin >> pnumber;
			outfile << setw(20) << "VIP手机号:" << pnumber << endl;
			outfile.close();
			cout << "                           保存VIP成功!" << endl;
			return 1;
		}
	}
	return 0;
}

void Vip::searchvip()                   //查找vip
{
	string vnumber, vn;
	cout << "请 输 入 vip 卡 号 : ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                       未找到该vip，请核对" << endl;
	}
	else
	{
		cout << "                      该vip存在，详情请查询所有信息 ！" << endl;
		infile.close();
	}
}

void Vip::changevip()                        // 更改vip信息
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
			cout << "                    请输入更改后VIP信息!";
			cout << "vip 姓 名 : ";
			cin >> name;
			cout << "vip 卡 号 : ";
			cin >> numbervip;
			cout << "vip 手 机 号 码 : ";
			cin >> pnumber;
			outfile << setw(20) << "VIP姓名:" << name << endl;
			outfile << setw(20) << "VIP卡号:" << numbervip << endl;
			outfile << setw(20) << "VIP手机号:" << pnumber << endl;
			outfile.close();
		}
	}
}

void Vip::displayvip()                  //显示vip信息
{
	string vnumber, vn;
	cout << "请 输 入 要 查 找 vip 的 vip 卡 号：";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                     该vip不存在，请核对!" << endl;
	}
	else
	{
		cout << "                    该vip存在!vip信息如下：" << endl;
		string s;
		while (getline(infile, s))
		{
			cout << s << endl;
		}
		infile.close();
	}
}

int Vip::delvip(int k)                    //删除vip信息
{
	string vnumber, vn;
	cout << "请 输 入 vip 卡 号 : ";
	cin >> vnumber;
	vn = "D:\\VIP\\" + vnumber + ".txt";
	ifstream infile(vn.c_str());
	if (!infile)
	{
		cout << "                      该vip不存在，请核对!";
		return 0;
	}
	if (infile)
	{
		infile.close();
		DeleteFile(vn.c_str());
		if (k == 0) cout << "删除成功!" << endl;
		return 1;
	}
	return 0;
}

void Vip::memv()                            //member变成VIP
{
	int flag = 0, flag1 = 0;
	Member m;
	flag = m.search(1);
	if (flag == 1)
	{
		cout << "						 该会员存在!请继续!" << endl;
		while (flag1 == 0)	flag1 = addvip();
		m.del(1);
	}
}

int charge()                            //收银员系统
{
	system("cls");
	system("color 5f");
	int cchoice = 1;
	char name[20];
  	while (cchoice != 0)
	{
		if (cchoice != 3)
		{
			cout << "                  ╭------------< 收银员 >-----------╮" << endl;
			cout << "                 ∣                                   ∣" << endl;
			cout << "                 ├-----------------------------------┤" << endl;
			cout << "                 ∣            1.收银员注册           ∣" << endl;
			cout << "                 ∣            2.收银员登陆           ∣" << endl;
			cout << "                 ∣            3.返   回              ∣" << endl;
			cout << "                 ╰-----------------------------------╯" << endl;
			cout << "                           请选择您要服务的类别:";
			cin >> cchoice;
			if ((cchoice != 1) && (cchoice != 2) && (cchoice != 3))
			{
				cout << "                          输入有误，请重新输入！" << endl;
				continue;
			}
		}
		if (cchoice == 1)
		{
			string ad, wn;
			cout << "请 输 入 工 号 : ";
			cin >> ad;
			wn = "D:\\收银员\\" + ad + ".txt";
			ifstream infile(wn.c_str());
			if (infile)
			{
				cout << "                                  已注册!" << endl;
				continue;
			}
			ofstream outfile(wn.c_str());
			if (!outfile)
			{
				cout << "                               有错误，请重试!" << endl;
				continue;
			}
			cout << "请 输 入 姓 名 : ";
			cin >> name;
			outfile << setw(10) << "姓名: " << name << endl;
			outfile << setw(10) << "工号: " << ad << endl;
			cout << "                            欢迎！注册成功！" << endl;
		}
		if (cchoice == 2)
		{
			string wn, ad;
			cout << "请 输 入 你 的 工 号 : ";
			cin >> ad;
			wn = "D:\\收银员\\" + ad + ".txt";
			ifstream infile(wn.c_str());
			{
				if (infile)
				{
					cout << "              ☆☆☆☆☆   欢   迎   光   临    ☆☆☆☆☆" << endl;
					return 'a';
				}
				if (!infile)
				{
					cout << "                  您的输入有误，请您核对！" << endl;
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
		cout << "          ☆☆☆☆☆☆☆☆      超市收银系统      ☆☆☆☆☆☆☆☆" << endl;
		cout << "          ********************************************************" << endl;
		cout << "          *       商品支付系统---------------------------1       *" << endl;
		cout << "          *       会员管理系统---------------------------2       *" << endl;
		cout << "          *       VIP 管理系统---------------------------3       *" << endl;
		cout << "          *       商品管理系统---------------------------4       *" << endl;
		cout << "          *       查看超市收入情况-----------------------5       *" << endl;
		cout << "          *       返 回----------------------------------6       *" << endl;
		cout << "          ********************************************************" << endl;
		cout << "                           请输入您的指令！" << endl;
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
			cout << "             1.继续支付商品          2.返回收银系统";
			cin >> flag2;
		}
		if (flag2 == 2) return 1;
		if (flag2 == 1)
		{
			cout << "请 输 入 商 品 条 形 码 ：";
			cin >> pn;
			pm = "D:\\商品\\" + pn + ".txt";
			ifstream infile(pm.c_str());
			if (!infile)
			{
				cout << "                              未找到该商品！" << endl;
				cout << "1.重 新 输 入     2.返 回";
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
				cout << "请输入商品单价：";
				cin >> price;
				cout << "请输入重量或质量：";
				cin >> quantity;
				cout << "1:会员 2：VIP 3：普通顾客" << endl;
				cout << "（请询问，若是会员或VIP请输入相应数字进入系统）";
				cin >> f;
			}
			while (f == 1)
			{
				string a, mn;
				cout << "请 会 员 卡 号 ：";
				cin >> a;
				mn = "D:\\会员\\" + a + ".txt";
				ifstream infile(mn.c_str());
				if (!infile)
				{
					cout << "                  未找到该会员！" << endl;
					cout << "1.重 新 输 入     2.返 回";
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
					cout << "应 付 金 额 ：" << total << endl;
					in = "D:\\收入\\会员收入\\" + td + ".txt";
					ofstream outfile(in.c_str());
					outfile << income << '\t' << sys.wSecond << '/' << sys.wMinute << '/' << sys.wHour << endl;
					f = 0, flag = 0; flag1 = 2;
				}
			}
			while (f == 2)
			{
				string b, vn;
				cout << "请 输 入 VIP 卡 号 ：";
				cin >> b;
				vn = "D:\\VIP\\" + b + ".txt";
				ifstream infile(vn.c_str());
				if (!infile)
				{
					cout << "                              未找到该vip！" << endl;
					cout << "1.重 新 输 入     2.返 回";
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
					cout << "应 付 金 额：" << total << endl;
					in = "D:\\收入\\VIP收入\\" + td + ".txt";
					ofstream outfile(in.c_str());
					outfile << income << '\t' << sys.wSecond << '/' << sys.wMinute << '/' << sys.wHour << endl;
					f = 0, flag = 0; flag1 = 2;
				}
			}
			while (f == 3)
			{
				total = price * quantity;
				cout << "应付金额：" << total << endl;
				income = income + total;
				string in;
				string date;
				in = "D:\\收入\\普通收入\\" + td + ".txt";
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
			cout << "                 1.增加               2.查找           " << endl;
			cout << "                 3.更改               4.显示           " << endl;
			cout << "                 5.删除               6.返回           " << endl;
			cout << "请输入您的指令：";
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
			cout << "                 1.增加               2.查找           " << endl;
			cout << "                 3.更改               4.显示           " << endl;
			cout << "                 5.删除               6.返回           " << endl;
			cout << "                 7.会员变成VIP                         " << endl;
			cout << "请输入您的指令：";
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
		cout << "                 1.增加               2.更改           " << endl;
		cout << "                 3.查找               4.删除           " << endl;
		cout << "                 5.显示               6.返回           " << endl;
		cout << "请输入您的指令: ";
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
	cout << "请输入要查询的日期：";
	cin >> date;
	in = "D:\\收入\\会员收入\\" + date + ".txt";
	ifstream infile(in.c_str());
	if (!infile)
	{
		cout << "未能统计会员收入" << endl;
	}
	while (getline(infile, s))
	{
		ofstream outfile("d:\\收入\\totalincome.txt", ios::app);
		outfile << s << endl;
		infile.close();
	}
	string vn;
	vn = "D:\\收入\\VIP收入\\" + date + ".txt";
	ifstream fin(vn.c_str());
	if (!fin)
	{
		cout << "未能统计VIP收入" << endl;
	}
	while (getline(fin, s))
	{
		ofstream outfile("d:\\收入\\totalincome.txt", ios::app);
		outfile << s << endl;
		fin.close();
	}
	ifstream input_data;
	string pt;
	pt = "D:\\收入\\普通收入\\" + date + ".txt";
	input_data.open(pt.c_str());
	if (!input_data)
	{
		cout << "未能统计普通顾客收入" << endl;
	}
	while (getline(input_data, s))
	{
		ofstream outfile("d:\\收入\\totalincome.txt", ios::app);
		outfile << s << endl;
		input_data.close();
	}
	ifstream datafile("d:\\收入\\totalincome.txt", ios::in);
	if (!datafile)
	{
		cout << "该文件未能正确打开！" << endl;
	}
	while (datafile >> number)
	{
		int se, m, h, d, m1, y;
		char d1, d2, d3, d4, d5;
		datafile >> se >> d1 >> m >> d2 >> h >> d3 >> d >> d4 >> m1 >> d5 >> y;
		tincome = tincome + number;
	}
	datafile.clear();
	cout << "总收入:" << tincome << endl;
	return 1;
}

int main()
{
	system("color 06f");
	extern string td;
	cout << "请输入当前日期（年/月/ 日）：";
	cin >> td;
	double income = 0, flag1 = 0, flag2 = 0;
	int c = 1, cho = 1, k, p;
	cout << "           ********************************************************" << endl;
	cout << "                 欢迎使用!收银员系统（!请仔细阅读使用说明!） " << endl;
	cout << "           ********************************************************" << endl;
	cout << "                            please press 1!" << endl;
	cout << "                                使用说明                             " << endl;
	cout << "                   一.请按提示输入要的选项" << endl;
	cout << "                   二.请先在D盘建立四个文件夹" << endl;
	cout << "                      ①收银员   ②会员   ③VIP   ④收入" << endl;
	cout << "                   三.请在收入文件夹中建立三个文件夹" << endl;
	cout << "                      ①会员收入   ②VIP收入   ③普通收入" << endl;
	cout << "                   四.如需要改变路径，请联系相关技术人员" << endl;
	cout << "                   五.系统还在测试阶段，谢谢使用!" << endl;
	cin >> c;
	if (c != 1)
	{
		cout << "please press 1!" << endl;
		cin >> c;
	}
	while (c != 0)
	{
		system("cls");
		cout << "            ☆☆☆☆☆   欢   迎    使     用！  ☆☆☆☆☆" << endl;
		cout << "                       收银员系统-------------1" << endl;
		cout << "                       退  出-----------------2" << endl;
		cin >> c;
		if (c == 1)
		{
			c = charge();
		}
		if (c == 'a')
		{
			cout << "                       收银系统----------------1" << endl;
			cout << "                       返  回------------------2" << endl;
			cout << "                       退  出------------------3" << endl;
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
