#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
using namespace std;


namespace MyLib {

	enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

	int ReadPositiveNumber(string Message)
	{
		int Number = 0;

		do
		{
			cout << Message << endl;
			cin >> Number;

		} while (Number <= 0);

		return Number;
	}

	void PrintDigits(int Number)
	{
		int Reminder = 0;

		while (Number > 0)
		{
			Reminder = Number % 10;

			Number /= 10;

			cout << Reminder << endl;
		}
	}

	int ReverseNumber(int Number)
	{
		int Reminder = 0;

		int Number2 = 0;

		while (Number > 0)
		{
			Reminder = Number % 10;

			Number /= 10;

			Number2 = Number2 * 10 + Reminder;
		}

		return Number2;
	}

	int CountDigitFrequecy(int DigitToCheck, int Number)
	{
		int Reminder = 0;
		int FreqCount = 0;

		while (Number > 0)
		{
			Reminder = Number % 10;

			Number /= 10;

			if (Reminder == DigitToCheck)
			{
				FreqCount++;
			}
		}

		return FreqCount;
	}

	void PrintAllDigitFrequency(int Number)
	{
		cout << endl;


		for (int i = 1; i <= 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequecy(i, Number);

			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequencey is "
					<< DigitFrequency << " Time(s).\n";
			}
		}
	}

	int SumOfDigits(int Number)
	{
		int Reminder = 0;
		int Sum = 0;

		while (Number > 0)
		{
			Reminder = Number % 10;
			Sum += Reminder;

			Number /= 10;
		}

		return Sum;
	}

	bool IsPerfectNumber(int Number)
	{
		int Sum = 0;

		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}

		return Sum == Number;
	}

	void PrintResult(int Number)
	{
		cout << endl;

		if (IsPerfectNumber(Number))
			cout << Number << " is perfect";
		else
			cout << Number << " is not perfect";

	}

	void PrintPerfectNumbersFrom1ToN(int Number)
	{
		cout << endl;

		for (int i = 1; i <= Number; i++)
		{
			if (IsPerfectNumber(i))
			{
				cout << i << endl;
			}
		}
	}

	enPrimeNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);

		for (int i = 2; i <= M; i++)
		{
			if (Number % i == 0)
				return enPrimeNotPrime::NotPrime;
		}
		return enPrimeNotPrime::Prime;
	}

	/*you should copy that to this stoped function 
	
		cout << "the name of this hsit 
	;*/

	void PrintPrimeNumbersFrom1ToN(int Number)
	{
		cout << "\nPrime Number From 1 to " << Number << " are : \n";

		for (int i = 1; i <= Number; i++)
		{
			if (CheckPrime(i) == enPrimeNotPrime::Prime)
				cout << i << endl;
		}
	}


	bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

	void PrintInvertedNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = Number; i >= 1; i--)
		{
			for (int j = i; j >= 1; j--)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	void PrintInvertedLetterPattern(int Number)
	{
		cout << "\n";
		for (int i = 65 + Number - 1; i >= 65; i--)
		{
			for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}

	void PrintAllWordsFromAToZ()
	{
		cout << "\n";
		string word = "";

		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);

					cout << word << endl;
					word = "";
				}
			}
		}
	}

	int ReadNumberInRange(int From, int To)
	{
		int Number = 0;

		do
		{
			cin >> Number;

		} while (Number < From || Number > To);


		return Number;
	}


	string ReadPassword()
	{
		string Password = "";

		cout << "\nEnter The Password ? ";
		cin >> Password;

		return Password;
	}

	bool GussPassword(string OriginalPassword)
	{
		cout << "\n";
		string word = "";
		int Counter = 0;

		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					Counter++;

					word = word + char(i);
					word = word + char(j);
					word = word + char(k);

					cout << "Trail[" << Counter << "] : " << word << endl;

					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word
							<< "\nFound after " << Counter << " Trail(s)";
						return true;
					}

					word = "";
				}
			}
		}
	}

	string Encryption(string Text, short EncryptionKey)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	string Decryption(string Text, short EncryptionKey)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	int RandomNumber(int From, int To)
	{

		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharecter = 3, Digit = 4 };
	
	char GetRandomCharcter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		};
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharecter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}

		}
	}

	string GenrateWord(enCharType CharType, short Length)
	{
		string word;

		for (int i = 1; i <= Length; i++)
		{
			word += GetRandomCharcter(CharType);
		}

		return word;
	}

	string GenrateKey()
	{
		string Key = "";

		for (int i = 1; i <= 4; i++)
		{
			Key += GenrateWord(enCharType::CapitalLetter, 55);

			if (i <= 3)
			{
				Key += "-";
			}
		}

		return Key;
	}

	void GenrateKeys(short NumberOfKeys)
	{
		cout << endl;
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "]  : " << GenrateKey() << endl;
		}
	}

	int ReadArray(int arr[100], int& arrLength)
	{
		arrLength = ReadPositiveNumber("Pleace Enter A Number ? ");

		cout << endl;

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}

		return arr[100];
	}

	void PrintArray(int arr[100], int arrLength)
	{
		cout << endl;

		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";

		cout << "\n";
	}

	int TimesRepeated(int Number, int arr[100], int arrLength)
	{

		int Count = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (Number == arr[i])
			{
				Count++;
			}
		}

		return Count;
	}

	void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
	{

		cout << "\nEnter number of elements :\n";
		cin >> arrLength;

		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(1, 100);
	}

	int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}

		return Max;
	}

	int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = arr[0];

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}

		return Min;
	}

	int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;

		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}

		return Sum;
	}

	float AvarageArray(int arr[100], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}

	void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}


	int SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}

		return arrSum[100];
	}

	void FillArrayWith1toN(int arr[100], int arrlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			arr[i] = i + 1;
		}
	}

	void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			arrDestination[i] = arrSource[arrLength - 1 - i];
		}
	}

	void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenrateKey();
		}
	}

	void PrintStringArray(string arr[100], int arrLength)
	{
		cout << "\nArray Eelements:\n\n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array [" << i << "] : ";
			cout << arr[i] << "\n";
		}
		cout << "\n";
	}

	int FindNumberPositionInArray(int Number, int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;

		}
		return -1;
	}

	bool IsNumberInArray(int Number, int arr[100], int arrLength)
	{
		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}

	int ReadNumber()
	{
		int Number;

		cout << "\nPleace Enter A Number? ";
		cin >> Number;

		return Number;
	}

	void AddArrayElements(int Number, int arr[100], int& arrLength)
	{
		arrLength++;

		arr[arrLength - 1] = Number;
	}

	void ReadNumbersOfArray(int arr[100], int& arrLength)
	{
		bool AddMore = true;

		do
		{
			AddArrayElements(ReadNumber(), arr, arrLength);

			cout << "\nDo you want to add more numbers?[0]:No,[1]:Yes? ";
			cin >> AddMore;

		} while (AddMore);
	}

	void CopyArrayUsingAddArrayElement(int SourceArray[100], int DestinationArray[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			AddArrayElements(SourceArray[i], DestinationArray, arr2Length);
		}
	}

	void CopyOddArrayNumbers(int SourceArray[100], int DestinationArray[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (SourceArray[i] % 2 != 0)
			{
				AddArrayElements(SourceArray[i], DestinationArray, arr2Length);
			}
		}
	}
	
	void CopyPrimeNumbers(int SourceArray[100], int DestinationArray[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (CheckPrime(SourceArray[i]) == enPrimeNotPrime::Prime)
			{
				AddArrayElements(SourceArray[i], DestinationArray, arr2Length);
			}
		}
	}

	void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
	{
		for (int i = 0; i < SourceLength; i++)
		{
			if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
			{
				AddArrayElements(arrSource[i], arrDestination, DestinationLength);
			}
		}
	}

	void FillArray(int arr[100], int& arrLength)
	{
		arrLength = 10;
		arr[0] = 10;
		arr[1] = 10;
		arr[2] = 10;
		arr[3] = 50;
		arr[4] = 50;
		arr[5] = 70;
		arr[6] = 70;
		arr[7] = 70;
		arr[8] = 70;
		arr[9] = 90;

	}

	bool IsPalindromeArray(int arr1[100], int arr1Length)
	{

		for (int i = 0; i < arr1Length; i++)
		{
			if (arr1[i] != arr1[arr1Length - i - 1])
			{
				return false;
			}
		}

		return true;
	}
	
	int OddCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
				Counter++;
		}

		return Counter;
	}

	int EvenCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
				Counter++;
		}

		return Counter;
	}

	int PositiveCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
				Counter++;
		}

		return Counter;
	}

	int NegativeCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
				Counter++;
		}

		return Counter;
	}

	float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}

	float GetFractionPart(float Number)
	{ 
		return Number - int(Number); 
	} 

	int MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);
		float FractionsPart = GetFractionPart(Number);
		if (abs(FractionsPart) >= .5)
		{
			if (Number > 0)
				return ++IntPart;
			else return --IntPart;
		}
		else
		{
			return IntPart;
		}
	}

	int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	int MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		else
			return Number;
	}

	int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}


	/*
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////777//////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////Course Seven/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////777//////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	*/




}