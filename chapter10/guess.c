/* ����ڰ� ���� ���߱� ���� */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER (100)

/* ���� */
void initialize_number_generator(void);
int get_new_secret_number(void);
void read_guesses(int secret_number);

int main(void) {
    char command = '\0';
    int secret_number = 0;

    printf("1�� 100 ������ ������ ���纸����!!\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        secret_number = get_new_secret_number();
        printf("��ǻ�Ͱ� ������ ���߽��ϴ�, ���纸����!.\n");
        read_guesses(secret_number);
        printf("�� �� ��? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');

    return 0;
}

/**********************************************************
 * initialize_number_generator: ���� �ð��� ��������          *
 *                              ���� �����⸦ �ʱ�ȭ�Ѵ�.      *
 **********************************************************/
void initialize_number_generator(void)
{
    srand((unsigned) time(NULL));
}

/**********************************************************
 * get_new_secret_number: 1�� MAX_NUMBER ������ ������       *
 *                        ��ȯ�Ѵ�.                         *
 **********************************************************/
int get_new_secret_number(void)
{
    return rand() % MAX_NUMBER + 1;
}

/**********************************************************
 * read_guesses: ������� �Է��� �ݺ������� �޾� �������         *
 *               �Է°��� ���亸�� �� ������, ū��,             *
 *               �������� �˷��ش�. ���� ���ٸ� ����ڰ�          *
 *               �� �� �� ��������� �˷��ְ� ��ȯ�Ѵ�.          *
 **********************************************************/
void read_guesses(int secret_number)
{
    int guess = 0;
    int num_guesses = 0;

    for (;;) {
        ++num_guesses;
        printf("������?: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("%d��° �õ����� ����׿�!\n\n", num_guesses);
            return;
        } else if (guess < secret_number) {
            printf("�ʹ� �۳׿�; �ٽ��غ�����.\n");
        } else {
            printf("�ʹ� ũ�׿�; �ٽ��غ�����.\n");
        }
    }
}