//============================================================================
// Name        : QuizMaker.cpp
// Author      : BurakSonmez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>

using namespace std;


//It is the base class
class Questions {
    public:
    virtual string getQuestion() = 0;
    virtual int getQuestionNumber() = 0;
    private:
    protected:
};
//Derived from Questions class
class ClassicalQuestions: public Questions {

public:
    string getQuestion() {
        return question;
    }

    string getAnswer() {
        return answer;
    }
    int getQuestionNumber() {
        return questionNumber;
    }

    void setQuestion(string a) {
        question = a;
    }

    void setAnswer(string a) {
        answer = a;
    }
    void setQuestionNumber (int a) {
        questionNumber = a;
    }
    void setQuestionAdress (string a) {
        questionAdress = a;
    }

protected:

private:
    string question;
    string answer;
    int questionNumber;
    string questionAdress;

};

//derived from Question class
class MultipleChoiceQuestions : public Questions {

public:

    string getQuestion() {
        return question;
    }

    string getOption1() {
        return option1;
    }

    string getOption2() {
        return option2;
    }

    string getOption3() {
        return option3;
    }

    string getOption4() {
        return option4;
    }

    string getAnswer() {
        return answer;
    }
    int getQuestionNumber() {
        return questionNumber;
    }
    string getQuestionAdress() {

        return questionAdress;
    }

    void setQuestion(string a) {
        question = a;
    }

    void setOption1(string a) {
        option1 = a;
    }
    void setOption2(string a) {
        option2 = a;
    }

    void setOption3(string a) {
        option3 = a;
    }

    void setOption4(string a) {
        option4 = a;
    }

    void setAnswer(string a) {
        answer = a;
    }

    void setQuestionNumber(int a) {
        questionNumber = a;
    }

    void setQuestionAdress(string a) {
        questionAdress = a;
    }

protected:

private:
    string question;
    string option1;
    string option2;
    string option3;
    string option4;
    string answer;
    int questionNumber;
    string questionAdress;


};

//Derived from Questions class
class FillBlankQuestions: public Questions {

public:
    string getQuestion() {
        return question;
    }

    string getAnswer() {
        return answer;
    }
    int getQuestionNumber() {
        return questionNumber;
    }

    void setQuestion(string a) {
        question = a;
    }

    void setAnswer(string a) {
        answer = a;
    }
    void setQuestionNumber (int a) {
        questionNumber = a;
    }
    void setQuestionAdress (string a) {
        questionAdress = a;
    }

protected:

private:
    string question;
    string answer;
    int questionNumber;
    string questionAdress;

};

int main() {
	string line;
    string answer;

    //Counter to track true and Falses
    static int trueCount = 0;
    static int falseCount = 0;

    //Multiple question number is 35. and in the file one question is 7 line
    string multipleChoiceQuestions[20][7];

   //Classical question number is 15. and in the file one question is 5 line
    string classicalQuestions[10][5];

    //Fill in the blank question number is 10. and in the file one question is 7 line
    string fillBlankQuestions[10][5];

    string multipleChoiceFileAdress = "test_questions.txt";
    string classicalFileAdress = "classical_questions.txt";
    string answerBlankFileAdress = "answer_blank.txt";
    int questionNumber;

    //Files are loaded to program
      ifstream multipleChoiceFile("test_questions.txt");
      ifstream classicalFile("classical_questions.txt");
      ifstream fillBlankFile("answer_blank.txt");


      cout<<"Welcome to our Quiz Maker Application\n Questions are coming! Look below!"<<endl;

      //This checks for file is open or not
          if (multipleChoiceFile.is_open()) {
              cout << "Multiple Choice Questions are loaded"<<endl<<endl;

              for(int a=0; a<20; a++) {
                  for (int b= 0 ; b<7; b++) {
                      getline(multipleChoiceFile,multipleChoiceQuestions[a][b]);
                  }
              }
          }

          //multiple choice questions

          cout << "How many multiple choice questions would you like to answer? Please enter a count max:20" <<endl;
          cin >> questionNumber;



          while (questionNumber > 20 || questionNumber < 0 ) {
              cout << "You exceed the max num of questions or you entered the negative value. Please enter less than 20 again!"<<endl;
              cin>> questionNumber;
          }


          for (int c = 0; c<questionNumber; c++) {
              for (int d =0; d<5; d++) {
                  cout << multipleChoiceQuestions[c][d]<<endl;
              }

                  cout << "Please enter an answer"<<endl;
                  cin >> answer;


              if (answer == multipleChoiceQuestions[c][5] ||answer == multipleChoiceQuestions[c][6] ) {
                  trueCount++;
              }

                  else falseCount++;
          }
          //classical questions
          //This checks for file is open or not
              if (classicalFile.is_open()) {
                  cout << "Classical Questions are loaded"<<endl;

                  for(int a=0; a<10; a++) {
                      for (int b= 0 ; b<5; b++) {
                          getline(classicalFile,classicalQuestions[a][b]);
                      }
                  }
              }

              cout << "How many classical questions would you like to answer? Please enter a count (max:10)" <<endl;
              cin >> questionNumber;

                  while (questionNumber > 10 || questionNumber < 0 ) {
                  cout << "You exceed the max num of questions or you entered the negative value. Please enter less than 10 again!"<<endl;
                  cin>> questionNumber;
              }

              for (int c = 0; c<questionNumber; c++) {
                  for (int d =0; d<1; d++) {
                      cout << classicalQuestions[c][d]<<endl;
                  }

                  cout << "Please enter an answer"<<endl;
                  cin >> answer;


                  if (answer == classicalQuestions [c][1] || answer == classicalQuestions [c][2] ||answer == classicalQuestions[c][3] ||answer == classicalQuestions[c][4]  ) {
                      trueCount++;
                  }

                  else falseCount++;
              }

              //answerBlank Questions

              if (fillBlankFile.is_open()) {
                  cout << "Answer Blank Questions are loaded"<<endl;

                  for(int a=0; a<10; a++) {
                      for (int b= 0 ; b<5; b++) {
                          getline(fillBlankFile,fillBlankQuestions[a][b]);
                      }
                  }
              }

              cout << "How many answer blank questions would you like to answer? Please enter a count ( max:10)" <<endl;
              cin >> questionNumber;

                  while (questionNumber > 10 || questionNumber < 0 ) {
                  cout << "You exceed the max num of questions or you entered the negative value. Please enter less than 10 again!"<<endl;
                  cin>> questionNumber;
              }

              for (int c = 0; c<questionNumber; c++) {
                  for (int d =0; d<1; d++) {
                      cout << fillBlankQuestions[c][d]<<endl;
                  }

                  cout << "Please enter an answer"<<endl;
                  cin >> answer;


                  if (answer == fillBlankQuestions [c][1] || answer == fillBlankQuestions [c][2] ||answer == fillBlankQuestions[c][3] ||answer == fillBlankQuestions[c][4] ) {
                      trueCount++;
                  }

                  else falseCount++;
              }

              cout << "You solved " << trueCount + falseCount << " questions" <<endl;
              cout << "You answered "<<trueCount << " questions as true" << endl;
              cout << "You answered "<<falseCount << " questions as false" << endl;

              multipleChoiceFile.close();
              classicalFile.close();
              fillBlankFile.close();
              cin.get();

              return 0;
          }

