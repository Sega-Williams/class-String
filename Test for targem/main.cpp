#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
//����������
	
//void sort() {
//	int cifra;
//	int* forSort = new int[lenght];
//	for (int i = 0; i < lenght; i++)
//	{
//		cout << "������� �����\n";
//		cin >> cifra;
//		forSort[i] = cifra;
//		cin.clear();
//	}
//
//	//����� ���������� �������
//	cout << "NONSORTED\n\n";
//	for (int i = 0; i < lenght; i++)
//	{
//		cout << forSort[i] << endl;
//	}
//	system("PAUSE");
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	int num;
//	bool check = true;
//	int numCheck = 0;
//	while (check == true) {
//		for (int i = 1; i < lenght; i++)
//		{
//
//			if (forSort[i - 1] > forSort[i]) {
//
//				numCheck = numCheck + 1;
//				num = forSort[i];
//				forSort[i] = forSort[i - 1];
//				forSort[i - 1] = num;
//			}
//		}
//		if (numCheck == 0) {
//			check = false;
//		}
//		numCheck = 0;
//	}
//
//	//����� ���������������� �������
//	cout << "SORTED: \n";
//	for (int i = 0; i < lenght; i++)
//	{
//		cout << forSort[i] << endl;
//	}
//	delete[] forSort;
//	system("PAUSE");
//}

class String {
public:
	
	//����������� ��������� ������
	String(int size) {
		//cout << "����� ������������ ������� " << this << endl;
		//��������� ������
		this->len = size;
		this->buffer = new char[len + 1];
		if (buffer == NULL) delete[] buffer;
		for (int i = 0; i < size; i++)
		{
			int randomChoose = rand() % 2;
			if (randomChoose == 1) {
				buffer[i] = rand() % 26 + 'A';
			}
			else {
				buffer[i] = rand() % 26 + 'a';
			}
		}
		this -> buffer[size] = '\0';
		//cout << "��������� ������ : " << buffer << endl;
	}
	//����������� ����������� �������� ������
	String(string other) {
		//cout << "����� ������������ ������� " << this << endl;
		
		this->len = other.size();
		this->buffer = new char[len + 1];
		if (buffer == NULL) delete[] buffer;
		for (int i = 0; i < size; i++)
		{
			buffer[i] = other[i];
		}
		this -> buffer[len] = '\0';
	}

	//����������� ����������� ������
	String(const String& other) {
		cout << "����� ������������ ����������� ������ " << this << endl;
		/*this->str = other.str;*/
		this->len = other.len;
		buffer = new char[len+1];
		if (buffer == NULL) delete[] buffer;
		for (int i = 0; i < len; i++)
		{
			buffer[i] = other.buffer[i];
		}
		this -> buffer[len] = '\0';
		cout << "������������� ������ : " << buffer << endl;
		
	}

	//������������ �����������
	String(String&& other) {
		cout << "����� move ������������ ������ " << this << endl;
		buffer = other.buffer;
		len = other.len;
		other.buffer = NULL;
		other.len = 0;
	}

	//����������
	~String() {
		//cout << "����� ����������� ������� " << this << endl; 
	delete[] buffer;
	}

	//�������� ���� �����
	String(const String& s1, const String& s2) {
		cout << "����� ������������ �������� ���� ����� " << this << endl;
		string sum;
		string string1;
		string string2;
		if (s1.buffer == NULL) {
			string1 = "\0";
		}
		else string1 = s1.buffer;
		if (s2.buffer == NULL) {

			string2 = "\0";
		}
		else string2 = s2.buffer;

		sum = string1 + string2;
		len = sum.size();
		buffer = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			buffer[i] = sum[i];
		}
		buffer[len] = '\0';
		cout << "��������� ������ : " << this->buffer << endl;
	}

	//������������ �������� ������������
	String & operator = (String&& other){
		cout << "����� move ��������� ������������ ������ " << this << endl;
		delete[] buffer;
		buffer = other.buffer;
		len = other.len;
		other.buffer = NULL;
		other.len = 0;
		return *this;
	}

	//�������� ������������ ������
	String& operator = (const String& other) {
		cout << "����� ��������� ������������ ������ " << this << endl;


		if (buffer == NULL) delete[] buffer;
		this->len = other.len;
		buffer = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			buffer[i] = other.buffer[i];
		}
		this->buffer[len] = '\0';
		cout << "����������� ������ : " << buffer << endl;

		return *this;
	}

	//����� ��������� ������
	string get() {

		//cout << "�������� ������: " << this << endl;
		if (buffer == NULL) {
			cout << "������ �����\n";

			return "\0";
		}
		else {
			//cout << buffer << endl;
			return buffer;
		}
	}

	

	



private:
	char* buffer;
	int len;
	int size;
};

//���������� �������� � ������ � ������� �������� �������������������
string sortChar(string forSort) {
	
	char letter;
	bool check = true;
	int numCheck = 0;
	while (check == true) {
		for (int i = 1; i < forSort.size(); i++)
		{
			if (tolower(forSort[i - 1]) < tolower(forSort[i])) {
				numCheck = numCheck + 1;
				letter = forSort[i];
				forSort[i] = forSort[i - 1];
				forSort[i - 1] = letter;
			}
		}
		if (numCheck == 0) {
			check = false;
		}
		numCheck = 0;
	}
	return forSort;
}

//��������� ������� ���������� ����� (�����������)
// 
////���������� ����� � ������� �������� �������������������
//bool sortByChar(string forSort1, string forSort2) {
//	
//	string fullString;
//	bool check = true;
//	int numCheck = 0;
//	
//	if ((forSort1.size()) > (forSort2.size())) {
//		for (int i = 0; i < forSort2.size() - 1; i++)
//		{
//			if ((tolower(forSort2[i]) == tolower(forSort1[i]))) continue;
//			if (tolower(forSort2[i]) > tolower(forSort1[i])) { return true; }
//		}
//	}
//	else if ((forSort1.size()) < (forSort2.size())) {
//		for (int i = 0; i < forSort1.size() - 1; i++)
//		{
//			if ((tolower(forSort2[i]) == tolower(forSort1[i]))) continue;
//			if (tolower(forSort2[i]) > tolower(forSort1[i])) { return true; }
//		}
//	}
//	else return false;
//}




int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	vector <string> MyVector;

	int size;
	cout << "������� ������������ ����� ������\n";
	cin >> size;
	int count;
	cout << "������� ���������� �����\n";
	cin >> count;
	
	//����������������� ��� ���������
	//....................................................................

	//String a(size);
	//MyVector.push_back(a.get());

	//String b(a);
	//cout << "\n\n\n\n\nSUM\n\n\n\n\n";
	//String u(a, b);
	//u.get();
	//String c(10);

	//b = c;
	//b.get();
	//String f = b = a;

	/*String g(move(a));
	g.get();
	a.get();

	g = move(b);
	g.get();
	b.get();*/

	////�������� ���� �����
	//String o(b, a);

	//..............................................................................................

	//�������� ������� ����� � ���������� �������
	cout << "�������� ������� ����� � ���������� �������\n";
	system("PAUSE");
	for (char i = 0; i < count; i++)
	{
		String a(rand() % (size + 1) + 1);

		MyVector.push_back(a.get());
	}
	
	//����� ������������� ������� �����
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << "MyVector " << i << " = " << MyVector[i] << endl;
	}
	system("PAUSE");

	cout << "\n�������� ����� �� ���������� ���� � ������� �������� �������������������\n";
	system("PAUSE");
	//�������� ����� �� ���������� ���� � ������� �������� �������������������
	for (int i = 0; i < MyVector.size(); i++)
	{
		MyVector[i] = sortChar(MyVector[i]);
	}
	//����� ��������������� ����� 
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << "MyVector " << i << " = " << MyVector[i] << endl;
	}

	system("PAUSE");

	
	cout << "\n���������� ����� �� ������ ����� � ������� �������� �������������������\n";
	system("PAUSE");

	//���������� ����� � �������� ������� �� ������ �����
	string stringToArr1;
	string stringToArr2;
	bool check = true;
	int counter = 0;
	int n=0;
	while (check == true) {
		check = false;
		for (vector<string>::iterator i = MyVector.begin(); i < MyVector.end() - counter - 1; i++)
		{
			stringToArr1 = *i;
			stringToArr2 = *(i + 1);
			if (tolower(stringToArr1[0]) < tolower(stringToArr2[0])) {
				MyVector[n].swap(MyVector[n + 1]);
				check = true;
			}
			n++;
		}
		counter++;
		n = 0;
		//cout << "Counter = " << counter << endl;
	}


	//����������� � ����������� ����� �� ������ � ������������ �������
	/*string stringToArr1;
	string stringToArr2;
	int minSizeArr;
	bool check = true;
	int counter = 0;
	int n=0;
	while (check == true) {
	
		check = false;
		for (vector<string>::iterator i = MyVector.begin(); i < MyVector.end() - counter - 1; i++)
		{
			stringToArr1 = *i;
			stringToArr2 = *(i + 1);
			if (stringToArr1.size() < stringToArr2.size()) minSizeArr = stringToArr1.size();
			else minSizeArr = stringToArr2.size();
			for (int j = 0; j < minSizeArr; j++)
			{
				if (tolower(stringToArr1[j]) < tolower(stringToArr2[j])) {
					MyVector[n].swap(MyVector[n + 1]);
					check = true; 
					break;
				}
			}
			n++;
		}
		counter++;
		n = 0;
		cout << "Counter = " << counter << endl;
	}*/


	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << "MyVector " << i << " = " << MyVector[i] << endl;
	}
	
	cout << "\n\n����������, ����� �������� ��������\n";
	system("PAUSE");
	system("cls");
	//����� ��������������� ����� ��� �������� 
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << "������ ����� " << i + 1 << " = " << MyVector[i] << endl;
	}

	string input = "\0";
	while (input != "exit") {
		cout << "��� ������ ������? \n���������� ������: copy\n����������� ��������: move\n�����: exit\n";
		cin.ignore();
		getline(cin, input);



		if (input == "copy" || input == "Copy") {
			cout << "Copy: \n������� ����� ������, ������� ������ �����������\n";
			int num;
			cin >> num;
			if (num < MyVector.size()) {
				string toCopy = MyVector[num - 1];
				MyVector.push_back(toCopy);
			}
			else cout << "�� ���������� ������ ��� ����� �������!\n";
		}
		else if (input == "move" || input == "Move") {
			cout << "Move: \n������� ����� ������, �������� ������� ������ ��������\n";
			int num1;
			int num2;
			cin >> num1;
			cout << "\n������� ����� ������, ������� ������ �����������\n";
			cin >> num2;
			string toMove;
			int counterIterator = 0;
			for (vector<string>::iterator i= MyVector.begin(); i < MyVector.end(); i++)
			{
				if (counterIterator == num2-1) {
					toMove = *i;
					MyVector[num1-1] = toMove;
					MyVector.erase(i);
					break;
				}
				counterIterator++;
			}
			
		}
		

		//����� ��������������� ����� 
		for (int i = 0; i < MyVector.size(); i++)
		{
			cout << "������ ����� " << i+1 << " = " << MyVector[i] << endl;
		}
	}
	
	return 0;
}
