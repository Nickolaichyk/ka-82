#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

class Nota
{
public:

	Nota();

	Nota(string dataN, string dataO, int valueL);

	~Nota();

	Nota& SetName(char* dataN)
	{
		Name = dataN;
		return *this;
	}

	string GetName()
	{
		return Name;
	}

	Nota& SetOktava(char* dataO)
	{
		Oktava = dataO;
		return *this;
	}

	string GetOktava()
	{
		return Oktava;
	}

	Nota& SetLenght(int valueL)
	{
		this->lenght = valueL;
		return *this;
	}

	int GetLenght()
	{
		return lenght;
	}

	Nota(const Nota &other)
	{
		cout << "� ����������� ����" << endl;
		this->Name = other.Name;
		this->Oktava = other.Oktava;
		this->lenght = other.lenght;
	}

	void Print()
	{
		cout << this->Name << "\t" << this->Oktava << "\t" << this->lenght << "\t" << endl;
	}

	void Print2()
	{
		cout << "Name: " << this->Name << endl;
	}

protected:
	string Name;
	string Oktava;
	int lenght;
};

Nota::Nota(string dataN, string dataO, int valueL)
{
	cout << "� ����������� ����" << endl;
	this->Name = dataN;
	this->Oktava = dataO;
	lenght = valueL;
}

Nota::Nota()
{
	cout << "� ����������� ����" << endl;
	this->Name = "noname";
	this->Oktava = "noname";
	lenght = 0;
}

Nota::~Nota()
{
	cout << "� de�������� ����" << endl;
}

class Voice: public Nota
{
public:
	Voice();
	Voice(double Frequency,int Number, string dataN, string dataO, int valueL);
	Voice(const Voice& other);
	~Voice();

	void PrintV()
	{
		this->Print();
		cout << this->Frequency << this->Number << endl;
	}
private:
	double Frequency;
	int Number;
};

Voice::Voice()
{
	this->Number = 0;
	Frequency = 0;
	cout << "� ����������� Voice" << endl;
}

Voice::Voice(double Frequency,int Number, string dataN, string dataO, int valueL):Nota(dataN,dataO,valueL)
{
	this->Number = Number;
	this->Frequency = Frequency;
	cout << "� ����������� Voice" << endl;
}

Voice::Voice(const Voice & other):Nota(other.Name,other.Oktava,other.lenght)
{
	this->Number = other.Number;
	this->Frequency = other.Frequency;
	cout << "� ����������� Voice" << endl;
}

Voice::~Voice()
{
	cout << "� de�������� Voice" << endl;
}

class Picture : public Nota
{
public:
	Picture();
	Picture(int x, int y,int Number, double Frequency, string dataN, string dataO, int valueL);
	Picture(const Picture& other);
	~Picture();

	void PrintP()
	{
		this->Print();
		cout << "(" << x << "," << y << ")" << this->Number << endl;
	}
private:
	int x, y;
	int  Number;
};

Picture::Picture()
{
	this->Number = 0;
	this->x = 0;
	this->y = 0;
	cout << "� ����������� Picture" << endl;
}

Picture::Picture(int x, int y,int Number,double Frequency, string dataN, string dataO, int valueL) :Nota(dataN, dataO, valueL)
{
	this->x = x;
	this->Number = Number;
	this->y = y;
	cout << "� ����������� Picture" << endl;
}

Picture::Picture(const Picture& other):Nota(other.Name, other.Oktava, other.lenght)
{
	this->Number = other.Number;
	this->x = other.x;
	this->y = other.y;
	cout << "� ����������� Picture" << endl;
}

Picture::~Picture()
{
	cout << "� de�������� Picture" << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	Nota q1;
	q1.Print();

	Voice V1;
	V1.PrintV();

	Picture P1;
	P1.PrintP();

	return 0;
}