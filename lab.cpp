#include <iostream>
#include <fstream>

using namespace std;

void read()
{
	int symbol[100];
	int n; int answ = 0;
    std::ifstream codes("C:\\Users\\Alexander\\Desktop\\codes.txt");
	ofstream codes1("C:\\Users\\Alexander\\Desktop\\codes1.txt");
	while (!codes.eof())
	{
		codes >> n;


		for (int i = 0; i < n- 1; i++)
		{
			codes >> symbol[i]>>symbol[i+1];
			if ((symbol[i] + symbol[i + 1]) % n == 0)
			{
				answ = 1;
				codes1 << "Yes" << endl;
				codes1 << symbol[i] << " " << symbol[i + 1] << endl;
			}
		}
	}

	if (answ == 0)
	{

		codes1 << "NO";
	}

}

int main()
{
	read();
}
