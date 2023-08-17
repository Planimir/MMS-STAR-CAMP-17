#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ITEMS_COUNT 10 

typedef struct BankAccount{

    unsigned short number;
    char holderName[101];
    double availability;
    char currency[5];

} BankAccount;

typedef struct node {

    BankAccount account;
    struct node *next;

} node_t;

char *currencies[] = {"USD", "EUR", "BGN", "GBP"};


void randomString(char *str, size_t length);

void randomizeAccount(BankAccount *account, unsigned short number);

node_t* createAccountList();

double totalBalance(node_t *head);

node_t *maxBalance(node_t *head);

void printAccountList(node_t *head);

int main() {
    srand(time(NULL));
    node_t *accountsList = createAccountList();
    printAccountList(accountsList);
    printf("Total Balance: %.2lf\n", totalBalance(accountsList));
    node_t *maxAcc = maxBalance(accountsList);
    if (maxAcc) {
        printf("\n\nBank Account with Highest Balance:\n");
        printf("Account Number: %u\n", maxAcc->account.number);
        printf("Holder Name: %s\n", maxAcc->account.holderName);
        printf("Availability: %.2lf %s\n", maxAcc->account.availability, maxAcc->account.currency);
    }

    return 0;
}

void randomString(char *str, size_t length) {

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t i;

    for(i  = 0 ; i < length; i++) {
        str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }

    str[length] = 0;
    str[0] = toupper(str[0]);

}

void randomizeAccount(BankAccount *account, unsigned short number) {

    account->number = number;

    int wordsCount = 2 + rand() %4;
    char word[21];

    account->holderName[0] = '\0'; 

    int i;

    for(i = 0; i < wordsCount ; i++) {

        randomString(word, 1 + rand() % 20);
        strcat(account->holderName, word);

        if (i < wordsCount - 1) {
            strcat(account->holderName, " ");
        }

    }

    account->availability = ((double)rand() / RAND_MAX) * 100000;
    strcpy(account->currency, currencies[rand() % (sizeof(currencies) / sizeof(currencies[0]))]);

}

node_t *createAccountList() {

    node_t *head = NULL, *current = NULL;

    for (int i = 0; i < ITEMS_COUNT; i++) {

        node_t *newNode = (node_t *)malloc(sizeof(node_t));
        randomizeAccount(&newNode->account, i + 1);

        newNode->next = NULL;

        if (!head) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

    }

    return head;
}


double totalBalance(node_t *head) {

    if (!head) {
        return -1;
    } 

    double sum = 0;

    while (head) {
        sum += head->account.availability;
        head = head->next;
    }

    return sum;
}

node_t *maxBalance(node_t *head) {

    if (!head) {
        return NULL;
    }

    node_t *maxNode = head;
    double maxAvailability = head->account.availability;

    while (head) {

        if (head->account.availability > maxAvailability) {
            maxAvailability = head->account.availability;
            maxNode = head;
        }

        head = head->next;
        
    }

    return maxNode;
}

void printAccountList(node_t *head) {

    while (head) {
        printf("Account Number: %u\n", head->account.number);
        printf("Holder Name: %s\n", head->account.holderName);
        printf("Availability: %.2lf %s\n", head->account.availability, head->account.currency);
        printf("----------------------------\n");
        head = head->next;
    }

}

/*

    gcc task1.c -lm -o task1 -Wall -Wextra

    ./task1


    Направете структура BankAccount, която да има:
    номер - цяло положително 16 битово число;
    име на притежател - символен низ до 100 символа;
    наличност - реално число;
    валута - символен низ до 4 символа.

    Да се направи свързан списък от ITEMS_COUNT (препроцесорна константа) елементи. Да се генерират автоматично произволни данни, с които да се запълни списъка от предмети.
    Ограничения за произволните данни:
    номер - цяло положително 16 битово число - уникално за всеки елемент в списъка;
    име на притежател - Съдържа между 2 и 5 произволни думи, разделени с интервал. Всяка дума е между 1 и 20 произволни символа (малки или главни латински букви).  Всяка дума започва с главна буква.
    наличност - реално число между 0.00лв и 100 000.00лв;
    валута - избира се от предварително създаден масив от символни низове.

    Да се реализират следните функции които обработват свързания списък:
    функция, която намира общата наличност на всички елементи в списъка. При неуспех да върне -1.
    double totalBalance(node_t* head);
    функция, която намира банковата сметка с най-висока наличност. При успех да върне указател към елемента, а при неуспех нулев указател.
   
            node_t * maxBalance(node_t* head);


Изведете съдържанието на списъка в стандартния изход с подходящо форматиране. Да се изведе общата наличност на банковите сметки и информация за банковата сметка с най-висока наличност.

*/