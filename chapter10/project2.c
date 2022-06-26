#include <stdbool.h>    /* C99 ���̺귯�� */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

/* �ܺ� ���� */
bool g_is_straight = false;
bool g_is_flush = false;
bool g_is_four = false;
bool g_is_three = false;
int g_pairs = 0;  /* ���� ī��� 0, ������ 1, ������ 2 */

/* ���� */
void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

/**********************************************************
 * main: read_cards, analyze_hand�� print_result��         *
 *       �ݺ������� ȣ�����ش�.                                *
 **********************************************************/
 int main(void)
 {
    int num_in_rank[NUM_RANKS] = {0, };
    int num_in_suit[NUM_SUITS] = {0, };
    
    for (;;) {
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit);
        print_result();
    }
 }

/**********************************************************
 * read_cards: ī�带 �Է¹޾� �ܺκ����� �������ش�; ��ȿ����      *
 *             �ʰų� �ߺ��� ī�尡 �ִ��� Ȯ�����ش�.            *
 **********************************************************/
void read_cards(int num_in_rank[], int num_in_suit[])
{
    bool does_card_exists[NUM_RANKS][NUM_SUITS];
    char ch = '\0';
    char rank_ch = '\0';
    char suit_ch = '\0';
    int rank = 0;
    int suit = 0;
    bool is_bad_card = false;
    int cards_read = 0;

    for (rank = 0; rank < NUM_RANKS; ++rank) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; ++suit) {
            does_card_exists[rank][suit] = false;
        }
    }

    for (suit = 0; suit < NUM_SUITS; ++suit) {
        num_in_suit[suit] = 0;
    }

    while (cards_read < NUM_CARDS) {
        is_bad_card = false;

        printf("ī�带 �Է����ּ���: ");

        rank_ch = getchar();
        switch (rank_ch) {
        case '0':
            exit(EXIT_SUCCESS);
        case '2': 
            rank = 0;
            break;
        case '3':
            rank = 1; 
            break;
        case '4':
            rank = 2; 
            break;
        case '5':
            rank = 3; 
            break;
        case '6':
            rank = 4; 
            break;
        case '7':
            rank = 5; 
            break;
        case '8':
            rank = 6; 
            break;
        case '9': 
            rank = 7; 
            break;
        case 't':
            /* intentional fallthrough */
        case 'T': 
            rank = 8; 
            break;
        case 'j':
            /* intentional fallthrough */
        case 'J': 
            rank = 9; 
            break;
        case 'q':
            /* intentional fallthrough */
        case 'Q':
            rank = 10; 
            break;
        case 'k':
            /* intentional fallthrough */
        case 'K':
            rank = 11; 
            break;
        case 'a':
            /* intentional fallthrough */
        case 'A':
            rank = 12;
            break;
        default:
            is_bad_card = true;
            break;
        }

        suit_ch = getchar();
        switch (suit_ch) {
        case 'c':
            /* intentional fallthrough */
        case 'C':
            suit = 0;
            break;
        case 'd':
            /* intentional fallthrough */
        case 'D':
            suit = 1;
            break;
        case 'h':
            /* intentional fallthrough */
        case 'H':
            suit = 2;
            break;
        case 's':
            /* intentional fallthrough */
        case 'S': 
            suit = 3;
            break;
        default:
            is_bad_card = true;
            break;
        }

        while ((ch = getchar()) != '\n') {
            if (ch != ' ') {
                is_bad_card = true;
            }
        }

        if (is_bad_card) {
            printf("��ȿ���� ���� ī���Դϴ�; �ٽ� �Է����ּ���.\n");
        } else if (does_card_exists[rank][suit]) {
            printf("�̹� �����ϴ� ī���Դϴ�; �ٽ� �Է����ּ���.\n");
        } else {
            ++num_in_rank[rank];
            ++num_in_suit[suit];
            does_card_exists[rank][suit] = true;
            ++cards_read;
        }
    }
}

/**********************************************************
 * analyze_hand: �а� ��Ʈ����Ʈ����, �÷�������, ��ī������,      *
 *               ����ī�ε������� �Ǻ����ְ�; ����� ������ �Ǻ���  *
 *               �� ���� �ܺκ����� �������ش�.                 *
 **********************************************************/
void analyze_hand(int num_in_rank[], int num_in_suit[])
{
    int num_consec = 0;
    int rank = 0;
    int suit = 0;
    g_is_straight = false;
    g_is_flush = false;
    g_is_four = false;
    g_is_three = false;
    g_pairs = 0;

    /* �÷������� Ȯ�� */
    for (suit = 0; suit < NUM_SUITS; ++suit) {
        if (num_in_suit[suit] == NUM_CARDS) {
            g_is_flush = true;
        }
    }

    /* ��Ʈ����Ʈ���� Ȯ�� */
    rank = 0;
    while (num_in_rank[rank] == 0) {
        ++rank;
    }

    for(; rank < NUM_RANKS && num_in_rank[rank] > 0; ++rank) {
        ++num_consec;
    }

    if (num_consec == NUM_CARDS) {
        g_is_straight = true;
        return;
    }

    /* ��ī��/����ī�� ���ο� ����� ������ Ȯ��*/
    for (rank = 0; rank < NUM_RANKS; ++rank) {
        if (num_in_rank[rank] == 4) {
            g_is_four = true;
        }

        if (num_in_rank[rank] == 3) {
            g_is_three = true;
        }

        if (num_in_rank[rank] == 2) {
            ++g_pairs;
        }
    }
}

/**********************************************************
 * print_result: ����ڿ��� analyze_hand�� ���� ���� �ܺκ�����  *
 *               ���� ������� ������ش�.                     *
 **********************************************************/
void print_result(void)
{
    if (g_is_straight && g_is_flush) {
        printf("��Ʈ����Ʈ �÷���");
    } else if (g_is_four) {
        printf("��ī��");
    } else if (g_is_three && g_pairs == 1) {
        printf("Ǯ�Ͽ콺");
    } else if (g_is_flush) {
        printf("�÷���");
    } else if (g_is_straight) {
        printf("��Ʈ����Ʈ");
    } else if (g_is_three) {
        printf("����ī��");
    } else if (g_pairs == 2) {
        printf("�����");
    } else if (g_pairs == 1) {
        printf("�����");
    } else {
        printf("����ī��");
    }

    printf("\n\n");
}