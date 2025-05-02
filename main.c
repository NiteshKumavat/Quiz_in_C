#include<stdio.h>
#include<string.h>

struct quiz
{
    double price;
    char question[200];
    char option_a[200];
    char option_b[200];
    char option_c[200];
    char option_d[200];
    char correct_option;
};


struct quiz getQuiz(int, char[]);
void startQuiz(char[]);


int main(void){
    int diff;
    printf("------------------------------------------------------------------------------------\n");
    printf("\t\tQuiz with Prices\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Choose your difficulty level : ");
    scanf("%d", &diff);
    switch (diff)
    {
        case 1:
            startQuiz("Easy");
            break;

        case 2:
            startQuiz("Medium");
            break;

        case 3:
            startQuiz("Hard");
            break;
        
        default:
            printf("You lost the opportunity to play the game because you enter the invalid input");
            break;
    }

    return 0;

}

struct quiz getQuiz(int number, char level[]){
    if (level == "Medium"){
        struct quiz Medium[10] = {
            {1000, "What is the capital of France?", "Paris", "Berlin", "Madrid", "Rome", 'a'},
            {2000, "What is the currency of Japan?", "Yen", "Dollar", "Euro", "Peso", 'a'},
            {5000, "Which is the largest planet?", "Earth", "Mars", "Jupiter", "Venus", 'c'},
            {10000, "Who wrote 'Hamlet'?", "Shakespeare", "Dickens", "Twain", "Rowling", 'a'},
            {20000, "What is the boiling point of water?", "100°C", "90°C", "80°C", "120°C", 'a'},
            {40000, "What is the smallest country?", "Vatican City", "Monaco", "Nauru", "San Marino", 'a'},
            {80000, "Who painted the Mona Lisa?", "Picasso", "Van Gogh", "Da Vinci", "Rembrandt", 'c'},
            {160000, "What is the speed of light?", "300,000 km/s", "150,000 km/s", "500,000 km/s", "1,000,000 km/s", 'a'},
            {232000, "What is the formula for water?", "H2O", "CO2", "CH4", "O2", 'a'},
            {500000, "What is the largest ocean?", "Atlantic", "Indian", "Arctic", "Pacific", 'd'}
        };

        return Medium[number];
    }
    
    if(level == "Hard"){
        struct quiz Hard[10] = {
            {500, "What is the square root of 256?", "14", "15", "16", "17", 'c'},
            {1000, "What is the value of Pi to 5 decimal places?", "3.14159", "3.14257", "3.14123", "3.14059", 'a'},
            {2000, "What is the speed of light in m/s?", "3.00 × 10^8", "2.98 × 10^8", "3.00 × 10^7", "3.00 × 10^9", 'a'},
            {4000, "Who developed the theory of relativity?", "Newton", "Einstein", "Hawking", "Tesla", 'b'},
            {8000, "What is the distance between the Earth and the Sun?", "93 million miles", "98 million miles", "105 million miles", "110 million miles", 'a'},
            {16000, "What is the largest prime number?", "97", "101", "89", "113", 'b'},
            {20000, "What is the chemical formula of methane?", "CH3", "CH4", "C2H6", "CO2", 'b'},
            {40000, "Who is known as the father of modern physics?", "Newton", "Galileo", "Einstein", "Tesla", 'c'},
            {80000, "What is the atomic number of Carbon?", "6", "7", "8", "10", 'a'},
            {100000, "What is the largest desert on Earth?", "Sahara", "Gobi", "Kalahari", "Arabian", 'a'}
        };

        return Hard[number];

    }

    
    if(level == "Easy"){
        struct quiz Easy[10] = {
            {100, "What is 2 + 2?", "3", "4", "5", "6", 'b'},
            {200, "What is the color of the sky?", "Red", "Blue", "Green", "Yellow", 'b'},
            {400, "What is 5 + 3?", "7", "8", "9", "10", 'b'},
            {500, "What is the capital of the USA?", "New York", "Washington D.C.", "Los Angeles", "Chicago", 'b'},
            {700, "What is 3 x 3?", "6", "7", "8", "9", 'd'},
            {800, "What is the capital of India?", "Mumbai", "Delhi", "Kolkata", "Chennai", 'b'},
            {1000, "What is the color of grass?", "Blue", "Green", "Yellow", "Brown", 'b'},
            {2000, "Which animal is known as the king of the jungle?", "Lion", "Tiger", "Elephant", "Bear", 'a'},
            {4000, "How many days are there in a week?", "5", "6", "7", "8", 'c'},
            {8000, "Which shape has 4 equal sides?", "Circle", "Square", "Triangle", "Rectangle", 'b'}
        };

        return Easy[number];
    }
}

void startQuiz(char level[]){
    int wrong_input = 0;
    int number = 0;
    double price = 0;
    char answer;
    while(answer != 'n' || number >= 10){
        struct quiz curr = getQuiz(number, level);
        printf("------------------------------------------------------------------------------------\n");
        printf("\t\tQuestion no %d for rupees %0.1lf\n", number+1, curr.price);
        printf("------------------------------------------------------------------------------------\n");
        printf("%d. %s\n", number+1, curr.question);
        printf("a. %s\n", curr.option_a);
        printf("b. %s\n", curr.option_b);
        printf("c. %s\n", curr.option_c);
        printf("d. %s\n", curr.option_d);
        printf("Enter your answer (a, b, c, d) or enter n for quit : ");
        scanf(" %c", &answer);

        char correct_answer = curr.correct_option;
        if(answer == 'n'){
            printf("Exiting the game!\n");
        }
        else if(answer == correct_answer){
            price = curr.price;
            printf("You won %0.1lf\n", price);
            number++;
        }
        else if(answer != 'n' && answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd'){
            wrong_input++;
            if(wrong_input == 2){
                printf("You choose the invalid options more than 1 time\n");
                break;
            }
            printf("warning ! Choose the valid options else game will terminate\n");

        }

        else{
            printf("You choose the incorrect answer\n");
            printf("Correct Answer is %c\n", correct_answer);
            break;
        }

    }

    printf("You won the total price of %0.1lf\n", price);
    printf("Thank You");
}
