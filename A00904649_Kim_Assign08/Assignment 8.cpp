//Comp2618 Assignment 8
//Daniel (Yooho) Kim
//July 2, 2018

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

void display(int); // display prototype for displaying hangman

int main()
{
	// populate the 10 string objects in a vector- 5 to 8 letters long
	const vector <string> wordList = { "COMPUTER","MOUSE","MONITOR","SPEAKER","PHONE",
									   "TRASH","PENCIL","BRUSH","APPLE","LIGHT" };

	// for selecting random word each time user plays
	default_random_engine engine(static_cast<unsigned int> (time(0)));
	uniform_int_distribution<unsigned int> randomInt(0, wordList.size() - 1);
	string replay; // y or n for user to play again or not
	
	do
	{
		string word = wordList[randomInt(engine)]; // select a random word from the list
		string xWord(word.size(), 'X'); // to show number of letters in the word to guess in 'X'
		string guess(word.size(), '?'); // for displaying guessed result of word
		string userInput = ""; // user input
		string tempChar = "", userTemp = ""; //for processing user input
		bool correct = false; // true if user guessed the word correctly
		unsigned int incorrectGuesses = 0; // for counting number of incorrect guesses

		cout << "Guess the word: " << xWord << "\n\n" << endl;

		while (incorrectGuesses < 7 && !correct)
		{
			cout << "Guess a letter: " << guess << '\n' << '?';
			getline(cin, userInput);
			transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);

			for (unsigned int i = 0; i < userInput.length(); i++)
			{
				if (isalpha(userInput[i]))
				{
					tempChar = userInput[i];
					size_t guessed = userTemp.find(userInput[i]);

					if (guessed != string::npos)
					{
						cout << '\'' << userInput[i] << '\'' <<
							" was already guessed. Try another letter\n" << endl;
					}
					else
					{
						userTemp.push_back(userInput[i]);
						userTemp.push_back(' ');
						size_t found = word.find(userInput[i]);

						if (found != string::npos)
						{
							while (found != string::npos)
							{
								guess.replace(found, 1, tempChar); // replace ? with letter found
								found = word.find(userInput[i], found + 1); // find next appearance
							}
						}
						else
						{
							incorrectGuesses++; // increase the number of incorrect guesses
						} // end if-else letter found in the answer word

						tempChar = ""; // reset the tempChar for next input letter
						display(incorrectGuesses); // display hangman depending on number of incorrect guesses
						cout << "Your guesses: \n" << " " << userTemp << "\n" << endl;

					}// end if-else user input found in answer.

				} // end if incorrectGuesses < 7 && !correct
				else
				{
					cout << "Letters only please" << endl;
				}// end of validation if
			}
				if (word == guess)
				{
					cout << "Word: " << word << "\n\n" <<
						"Congratulations!!! You guessed my word.\n" << endl;
					correct = true;
				}
		}
			if(word != guess)
			{
				cout << "Sorry - you have run out of guesses ;-( \n"
					<< "The correct answer was: " << word << "\n\n"
					<< "...GAME OVER...\n" << endl;
			} // end if-else correct answer.

			cout << "Play again? (y/n)" << endl;
			getline(cin,replay);

	} while (replay!= "n" && replay != "N");// end do-while

	system("pause");
	return 0;
}


void display(int incorrect) {

	switch (incorrect) {
	case 1: cout << "\n o\n" << endl;
		break;
	case 2: cout << "\n o\n" << "/\n" << endl;
		break;
	case 3: cout << "\n o\n" << "/|\n" << endl;
		break;
	case 4: cout << "\n o\n" << "/|\\\n" << endl;
		break;
	case 5: cout << "\n o\n" << "/|\\\n" << " |\n" << endl;
		break;
	case 6: cout << "\n o\n" << "/|\\\n" << " |\n" << "/\n" << endl;
		break;
	case 7: cout << "\n o\n" << "/|\\\n" << " |\n" << "/ \\\n" << endl;
		break;
	}
}