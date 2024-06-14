#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

ifstream MyFile("input.txt");


class Comparare 
{
public:
	bool operator()(pair<string, int>& c1, pair<string, int>& c2)
	{
		if (c1.second != c2.second)  return c1.second<c2.second;
		else return c1.first > c2.first;
		
	}

};

string TransformareLiteraMica(const string& cuv)
{
	int i;
	string rez;
	for (i = 0;i < cuv.length();i++)
		rez += tolower(cuv[i]);
	return rez;

}

vector<string> DespartireInCuv(const string& text, const string& delimitatori)
{
	vector<string> cuvinte;
	int i, j;
	size_t index1;
	index1 = text.find_first_not_of(delimitatori);//poz primului loc diferit de delimitatori
	while (index1 != string::npos)///cat timp nu am ajuns la valoarea maxima
	{
		size_t index2 = text.find_first_of(delimitatori, index1);///prima poz unde gasim delimitatori dupa index1
		cuvinte.push_back(text.substr(index1, index2 - index1));///substr genereaza un nou string de la index1
		                                                        ///de lg index2-index1
		index1 = text.find_first_not_of(delimitatori , index2);///primul loc unde nu sunt delimitatori dupa index1


	}
	return cuvinte;

}

int main()
{

	string text;
	getline(MyFile, text);
	string delimitatori = " ,?!.";

	vector<string> cuvinte = DespartireInCuv(text, delimitatori);

	map<string, int> wordcount;
	for (const auto& cuv : cuvinte)
	{
		string cuvliteremici = TransformareLiteraMica(cuv);
		wordcount[cuvliteremici]++;
	}


	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparare> wordqueue;

	for (auto& pair : wordcount) wordqueue.push(pair);
	while (!wordqueue.empty())
	{
		cout << wordqueue.top().first << " => " << wordqueue.top().second << "\n";
		wordqueue.pop();

	}
    


	MyFile.close();
	return 0;

}