#lab 1

#include <iostream>
#include <sstream>
using namespace std;



string moveCharToLeft(string word) {
    word.insert(0, 1, word[word.length() - 1]);
    word.erase(word.length() - 1, 1);
    return word;
}

string decodeWord(string word) {
    for (int i = 0; i < 3; i++) {
        word = moveCharToLeft(word);
    }
    return word;
}

void decode(string sentence) {
    string resultSentence = "";
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        resultSentence += decodeWord(word) + " ";
    }
    cout << resultSentence << endl;
}

int main(int argc, const char * argv[]) {
    string sentence = "ethingSom  ethingSom ethingSom";
    decode(sentence);
    return 0;
}

# lab 2

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



//lab 3

#include <iostream>
#include <string>
#include <vector>

#include <fstream>

using namespace std;


void generateGrayarr(int n)
{

    ofstream codes1("C:\\Users\\Alexander\\Desktop\\codes1.txt");
    if (n <= 0)
        return;
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
    int i, j;
    for (i = 2; i < (1 << n); i = i << 1)
    {

        for (j = i - 1; j >= 0; j--)
            arr.push_back(arr[j]);

        for (j = 0; j < i; j++)
            arr[j] = "0" + arr[j];

        for (j = i; j < 2 * i; j++)

            arr[j] = "1" + arr[j];

    }
    for (i = 0; i < arr.size(); i++)
        codes1 << arr[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    generateGrayarr(n);
    return 0;
}
