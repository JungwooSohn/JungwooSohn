// DATA STRUCTURE HW2
// KUGODS, Korea University
// 07.05.22
#define _CRT_SECURE_NO_WARNINGS
#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

LIST* createList(int(*compare)(STUDENT* pArg1, STUDENT* pArg2))
{
    // TODO
    LIST* newlist = (LIST*) malloc(sizeof(LIST));
	newlist->compare = compare;
	newlist->head = NULL;
	newlist->pos = NULL;
	newlist->rear = NULL;
	newlist->listSize = 0;

	return newlist;
}

void destoryList(LIST* pList)
{
    // TODO
    for (pList->pos = pList->rear; pList->pos == pList->head; pList->pos = pList->rear) {
		pList->rear = pList->pos->next;
		free(pList->pos);
	}
	
	free(pList->pos);
	free(pList);
}

bool insertData(LIST* pList, studentId id, char* name, char* email)
{
    // TODO
	NODE* newnode = (NODE*) malloc(sizeof(NODE));

	newnode->next = NULL;
	
	STUDENT* newstudent;

	if (newstudent == NULL) {
		return false;
	}

	makeStudent(&newstudent, id, name, email);

	newnode->pData = newstudent;

	if (pList->listSize == 0) {
		pList->pos = newnode;
		pList->head = newnode;
		pList->rear = newnode;
		pList->listSize++;
		return true;
	} else {
		NODE *prev, *cur;

		for (prev = pList->rear, cur = NULL; prev != NULL; cur = prev, prev = prev->next) {
			if (pList->compare(prev->pData, newnode->pData) == -1) {

			} else {
				if (prev == pList->rear) {
					pList->rear = newnode;
					newnode->next = prev;
					pList->listSize++;
					return true;
				}
				cur->next = newnode;
				newnode->next = prev;
				pList->listSize++;
				return true;
			}
		}

		cur->next = newnode;
		pList->head = newnode;
		pList->listSize++;
		return true;
	}
}

bool removeData(LIST* pList, studentId pKey)
{
    // TODO
    NODE *prev, *cur;

	for (prev = pList->rear, cur = NULL; prev != NULL; cur = prev, prev = prev->next) {
		if (prev->pData->id == pKey) {
			if (prev == pList->rear) {
				if (pList->pos = pList->rear) {
					pList->pos = pList->rear->next;
				}
				pList->rear = pList->rear->next;
				
				pList->listSize--;
				free(prev);
				return true;
			}

			if (prev == pList->head) {
				pList->head = cur;
				pList->head->next = NULL;
				pList->listSize--;
				free(prev);
				return true;
			}

			cur->next = prev->next;
			pList->listSize--;
			free(prev);
			return true;
		}
	}

	return false;
}

bool searchData(LIST* pList, studentId pKey, STUDENT** pDataOut)
{
    // TODO
	NODE *prev;

	for (prev = pList->rear; prev != NULL;prev = prev->next) {
		if (prev->pData->id == pKey) {
			*pDataOut = prev->pData;
			return true;
		}

	}
	return false;
}

int listSize(LIST* pList)
{
	return pList->listSize;
}

bool isEmpty(LIST* pList)
{
	if (pList->listSize == 0)
		return true;
	else
		return false;
}

void initIterator(LIST* pList)
{
	pList->pos = pList->rear;
}

bool iterateList(LIST* pList, STUDENT** pDataOut)
{
    // TODO
	if (pList->listSize == 0 || pList->pos == NULL) {
		pList->pos = pList->rear;
		return false;
	}

    *pDataOut = pList->pos->pData;
	pList->pos = pList->pos->next;

	return true;
}

void printList(LIST* pList, void(*print)(STUDENT* pArg))
{
	STUDENT* temp;
	while(iterateList(pList, &temp)) {
		printStudent(temp);
	}
	printf("====================\n");
}

static bool _doInsert(LIST* pList, NODE* pPre, STUDENT* pDataIn)
{
	return true;
}

static void _doRemove(LIST* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL)
		pList->head = pCur->next;
	else
		pPre->next = pCur->next;
	free(pCur);
	pList->listSize--;
}

static bool _doSearch(LIST* pList, NODE** pPre, NODE** pLoc, studentId pKey)
{
    // TODO
    return true;
}

bool makeStudent(STUDENT** pDataOut, studentId id, char* name, char* email)
{
	STUDENT* sample = (STUDENT*)malloc(sizeof(STUDENT));
	strcpy(sample->email, email);
	strcpy(sample->name, name);
	sample->id = id;
	*pDataOut = sample;
	if (sample)
		return true;
	else
		return false;
}

void printStudent(STUDENT* pStudent)
{
	printf("STUDENT ID: %d\n", pStudent->id);
	printf("NAME: %s\n", pStudent->name);
	printf("EMAIL: %s\n", pStudent->email);
	printf("--------------------\n");
}

int cmpStudentId(STUDENT* pStudent1, STUDENT* pStudent2)
{
	if (pStudent1->id > pStudent2->id)
		return 1;
	else if (pStudent1->id < pStudent2->id)
		return -1;
	else
		return 0;
}
