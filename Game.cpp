#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;

enum enOperationType
{
	Add = 1,
	Sub = 2,
	Mul = 3,
	Div = 4,
	MixOp = 5
};

enum enQuestionsLevel
{
	EasyLevel = 1,
	MedLevel = 2,
	HardLevel = 3,
	Mix = 4
};


struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
	int PlayerAnswers = 0;
	int CorrectAnswer = 0;
	bool AnswerResult = false;
};


struct stQuiz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enOperationType OpType;
	enQuestionsLevel QuestionLevel;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

short ReadHowManyQuestions()
{
	short Number = 0;
	
	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> Number;
	} while (Number < 0 || Number > 10);

	return Number;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel = 0;
	
	do
	{
		cout << "\nEnter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);

	return (enQuestionsLevel)QuestionsLevel;
}

enOperationType ReadOpType()
{
	short OperationType = 0;

	do
	{
		cout << "\nEnter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);

	return (enOperationType)OperationType;
}

int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return (Number1 + Number2);

	case enOperationType::Sub:
		return (Number1 - Number2);

	case enOperationType::Mul:
		return (Number1 * Number2);

	case enOperationType::Div:
		return (Number1 / Number2);
	}
	return 0;
}

stQuestion GenrateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionsLevel::Mix)
	{
		QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = (enOperationType)RandomNumber(1, 4);
	}

	Question.OperationType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionsLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;
	
	case enQuestionsLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;

	case enQuestionsLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;

		return Question;
	}

	return Question;
}

void GenerateQuizQuestions(stQuiz &Quiz)
{
	for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionList[Question] = GenrateQuestion(Quiz.QuestionLevel, Quiz.OpType);
	}
}

string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";

	case enOperationType::Sub:
		return "-";

	case enOperationType::Mul:
		return "*";

	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

int ReadPlayerAnswer()
{
	int Number;
	cin >> Number;
	return Number;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F");
	else 
	{
		system("color 4F");
		cout << "\a";
	}
}

void CorrectTheQuestionAnswer(stQuiz &Quiz, short QuestionsNumber)
{
	if (Quiz.QuestionList[QuestionsNumber].PlayerAnswers != Quiz.QuestionList[QuestionsNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionsNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is : " <<
			Quiz.QuestionList[QuestionsNumber].CorrectAnswer << "\n";	
	}

	else
	{
		Quiz.QuestionList[QuestionsNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :-) \n";
	}
	cout << endl;

	SetScreenColor(Quiz.QuestionList[QuestionsNumber].AnswerResult);
}

void PrintTheQuestion(stQuiz Quiz, short QuestionsNumber)
{
	cout << "\nQustion [" << QuestionsNumber + 1 << "/" << Quiz.NumberOfQuestions << "]" << endl;
	cout << "\n" << Quiz.QuestionList[QuestionsNumber].Number1 << "\n"
		<< Quiz.QuestionList[QuestionsNumber].Number2 << "   " << GetOpTypeSymbol(Quiz.QuestionList[QuestionsNumber].OperationType) ;
	cout << "\n__________\n";
}

void AskAndCorrectQuestionsListAnswers(stQuiz &Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);

		Quiz.QuestionList[QuestionNumber].PlayerAnswers = ReadPlayerAnswer();

		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.IsPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResultText(bool Pass)
{
	if (Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

string GetQuestionsLevelText(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = {"Easy", "Med" , "Hard", "Mix"};

	return arrQuestionLevelText[QuestionLevel - 1];
}

void PrintQuizReuslt(stQuiz Quiz)
{
	cout << "\n";
	cout << "______________________________\n\n";

	cout << " Final Reuslt is : " << GetFinalResultText(Quiz.IsPass);
	cout << "\n______________________________\n\n";

	cout << "Number Of Questions : " << Quiz.NumberOfQuestions << endl;
	cout << "Questions Level     : " << GetQuestionsLevelText(Quiz.QuestionLevel) << endl;
	cout << "OpType              : " << GetOpTypeSymbol(Quiz.OpType) << endl;

	cout << "Number Of Right Answers : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers : " << Quiz.NumberOfWrongAnswers << endl;

	cout << "______________________________\n";
}

void PlayMathGame()
{
	stQuiz Quiz;

	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuestionLevel = ReadQuestionsLevel();
	Quiz.OpType = ReadOpType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionsListAnswers(Quiz);
	PrintQuizReuslt(Quiz);

}

void ResetScreen()
{
	system("cls"); 
	system("color 0F"); 
}

void StartMathGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do You Want To Play Again ? Y/N ?";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum enWinner
{
	Player1 = 1,
	Computer = 2,
	Draw = 3
};

enum enGameChoice
{
	Stone = 1,
	Paper = 2,
	Scissors = 3
};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";
};

struct stGameResult
{
	short GameRounds = 0;
	short Player1Winns = 0;
	short ComputerWinsTimes = 0;
	short DrawTimes = 0;
	enWinner Winner;
	string WinnerName = "";
};

short ReadHowManyRuonds()
{

	short GameRounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;
	}
	while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

enGameChoice ReadPlyaer1Choice()
{
	short Choice = 1;

	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWinTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Stone", "Paper", "Scissors" };

	return arrWinnerName[Winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
	
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	default:
		system("color 6F");
		break;
	}
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n"; 
		
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;

	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;

	cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n"; 

	cout << "__________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner HowWinTheGame(short Player1WinTimes, short ComputerWinsTimes)
{
	if (Player1WinTimes == ComputerWinsTimes)
	{
		return enWinner::Draw;
	}

	else if (Player1WinTimes > ComputerWinsTimes)
	{
		return enWinner::Player1;
	}
	
	else
	{
		return enWinner::Draw;
	}
}

stGameResult FillGameResult(short GameRounds ,short Player1WinTimes, short ComputerWinsTimes, short DrawTimes)
{
	stGameResult GameResult;

	GameResult.GameRounds = GameRounds;
	GameResult.Player1Winns = Player1WinTimes;
	GameResult.ComputerWinsTimes = ComputerWinsTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.Winner = HowWinTheGame(Player1WinTimes, ComputerWinsTimes);
	GameResult.WinnerName = WinnerName(GameResult.Winner);

	return GameResult;
}

stGameResult PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinsTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlyaer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Computer)
		{
			ComputerWinsTimes++;
		}
		else if (RoundInfo.Winner == enWinner::Player1)
		{
			Player1WinTimes++;
		}
		else
		{
			DrawTimes++;
		}

		PrintRoundResult(RoundInfo);


	}

	return FillGameResult(HowManyRounds, Player1WinTimes, ComputerWinsTimes, DrawTimes);
}

string Tabs(short NumebrOfTaps)
{
	string t = "";

	for (int i = 1; i < NumebrOfTaps; i++)
	{
		t = t + "\t";
		cout << t;;
	}
	return t;
}

void ShowFinalGameResults(stGameResult GameResults)
{
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n"; 

	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;

	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1Winns << endl;

	cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinsTimes << endl;

	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;

	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;

	cout << Tabs(2) << "___________________________________________________________\n";

	SetWinnerScreenColor(GameResults.Winner);
}

void ShowGameOverScreen()
{
	cout << Tabs(2) <<	"__________________________________________________________\n\n";

	cout << Tabs(2) << "                 +++ G a m e  O v e r ++ + \n"; 

	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void StartStonePaperSicssorGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResult GameResult = PlayGame(ReadHowManyRuonds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResult);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}

string PrintWelcomeToCourseFive()
{
	string WelcomeToCourseFive = "\t\t\t\t        !@--  Welcome To Course Five  --@!";

	return WelcomeToCourseFive;
}

void PrintHeader()
{
	string Line = "\t\t\t\t ___________________________________________________\n";


	cout << "\n\n";

	for (int i = 0; i < Line.length(); i++)
	{
		cout << Line[i];
		this_thread::sleep_for(chrono::microseconds(10000));
	}

	cout << "\n";

	string Welcome = PrintWelcomeToCourseFive();

	for (int i = 0; i < Welcome.length(); i++)
	{
		cout << Welcome[i];
		this_thread::sleep_for(chrono::microseconds(20000));
	}

	cout << "\n";

	for (int i = 0; i < Line.length(); i++)
	{
		cout << Line[i];
		this_thread::sleep_for(chrono::microseconds(10000));
	}

}

void PrintProjectsName()
{
	string FirstProject = "\n\t\t\t\t\t1- Stone Paper Scissors Game Project ";
	string SecondProject = "\n\t\t\t\t\t2- Math Game Project ";

	for (int i = 0; i < FirstProject.length(); i++)
	{
		cout << FirstProject[i];
		this_thread::sleep_for(chrono::microseconds(20000));
	}


	for (int i = 0; i < SecondProject.length(); i++)
	{
		cout << SecondProject[i];
		this_thread::sleep_for(chrono::microseconds(20000));
	}
}

short ReadWhichCourse()
{
	string ChoiceProject = "\n\n\t\t\t\t\tChoice Project ? ";
	short NumberOfProject = 0;

	for (int i = 0; i < ChoiceProject.length(); i++)
	{
		cout << ChoiceProject[i];
		this_thread::sleep_for(chrono::microseconds(20000));
	}

	cin >> NumberOfProject;

	return NumberOfProject;
}

void ChoiceProject(short ProjectNumber)
{
	if (ProjectNumber == 1)
	{
		StartStonePaperSicssorGame();
	}

	else
	{
		StartMathGame();
	}
}

void MainScreen()
{
	PrintHeader();

	PrintProjectsName();

	ChoiceProject(ReadWhichCourse());

}

int main()
{
	srand((unsigned)time(NULL));


	MainScreen();
	system("pause > 0");

	return 0;
}