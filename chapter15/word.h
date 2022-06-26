#ifndef WORD_H
#define WORD_H

/**********************************************************
 * read_word: 입력의 다음 단어를 읽은 다음, word에 저장해준다. 만약 *
 *            파일 끝이라 읽을 수 있는 단어가 없다면 word를       *
 *            비워준다. 만약 단어의 길이가 len을 초과한다면        *
 *            잘라준다.                                     *
 **********************************************************/
void read_word(char *word, int len);

#endif