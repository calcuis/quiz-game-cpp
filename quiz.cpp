#include <iostream>

int main (){
    std::string questions[] = {"1. What year did the C language debut?: ",
                               "2. Who is credited with creating C?: ",
                               "3. Python is written by which language?: "};

    std::string options[][4] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                                "A. Dennis Ritchie", "B. Bill Gate", "C. Tim Cook", "D. Elon Musk",
                                "A. C", "B. C+", "C. C++", "D. C#"};

    char answerKey[] = {'B', 'A', 'A'};
    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    std::cout << "************** QUIZ GAME ***************\n";
    FILE *pF = fopen("results.txt", "w");

    for(int i = 0; i < size; i++){
        std::cout << "****************************************\n";
        std::cout << questions[i] << '\n';
        std::cout << "****************************************\n";

        for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
            std::cout << options[i][j] << '\n';
        }

        std::cout << "Guess: ";
        std::cin >> guess;
        guess = toupper(guess);
        fprintf(pF, "%c\n", guess);

        if(guess == answerKey[i]){
            std::cout << "CORRECT\n";
            score++;
        }
        else{
            std::cout << "WRONG!\n";
            std::cout << "Answer: " << answerKey[i] << '\n';
        }
    }

    std::cout << "**************************\n";
    std::cout << "**       RESULTS        **\n";
    std::cout << "**************************\n";
    std::cout << "CORRECT GUESSES: " << score << '\n';
    std::cout << "NUMBER of QUESTIONS: " << size << '\n';
    std::cout << "SCORE: " << (score/(double)size)*100 << "%";

    fprintf(pF, "FINAL SCORE: %d/%d", score, size);

    return 0;
}