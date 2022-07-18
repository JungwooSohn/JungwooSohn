// DATA STRUCTURE HW2
// KUGODS, Korea University
// 07.05.22
#define _CRT_SECURE_NO_WARNINGS
#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    NODE *prev;
	for (prev = NULL, pList->pos = pList->head; pList->pos != NULL; prev = pList->pos, pList->pos = pList->pos->next) {
		free(prev);
	}

	free(prev);
	free(pList);
}

bool insertData(LIST* pList, studentId id, char* name, char* email)
{
    // TODO
	STUDENT* newstudent;
	NODE *prev, *loc;
	makeStudent(&newstudent, id, name, email);
	_doSearch(pList, &prev, &loc, id);
	return _doInsert(pList, prev, newstudent);
}

bool removeData(LIST* pList, studentId pKey)
{
    // TODO
	bool flag;
	NODE *prev, *loc;
	if (_doSearch(pList, &prev, &loc, pKey)) {
		_doRemove(pList, prev, loc);
		return true;
	} 

	return false;
}

bool searchData(LIST* pList, studentId pKey, STUDENT** pDataOut)
{
    // TODO
	NODE *prev, *loc;
	if (_doSearch(pList, &prev, &loc, pKey)) {
		*pDataOut = loc->pData;
		return true;
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
	pList->pos = NULL;
}

bool iterateList(LIST* pList, STUDENT** pDataOut)
{
    // TODO
	static bool last = false;
	if (pList->listSize == 0) {
		return false;
	}

    if (pList->pos == NULL) {
		if (last == true) {
			last = false;
			return false;
		}
		pList->pos = pList->head;
	}

	if (pList->pos == pList->rear) {
		last = true;
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
    // TODO
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
	if (newnode == NULL) {
		return false;
	}
	newnode->pData = pDataIn;
	
	if (pPre == NULL) {	// 첫 노드 앞에 추가하거나 비어있는 리스트일 때
		if (pList->listSize == 0) {
			pList->rear = newnode;
		}
		newnode->next = pList->head;
		pList->head = newnode;
	} else {
		if (pPre == pList->rear) {
			pList->rear = newnode;
		}

		newnode->next = pPre->next;
		pPre->next = newnode;
	}

	pList->listSize++;
	return true;
}

static void _doRemove(LIST* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL)
		pList->head = pCur->next;
	else {
		if (pCur == pList->rear) {
			pList->rear = pPre;
		}
		pPre->next = pCur->next;
	}
	free(pCur);
	pList->listSize--;
}

static bool _doSearch(LIST* pList, NODE** pPre, NODE** pLoc, studentId pKey)
{
    // TODO
	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->listSize == 0) {
		return false;
	}
	if (pList->rear->pData->id < pKey) {
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}
    for (; *pLoc != NULL; *pPre = *pLoc, *pLoc = (*pLoc)->next) {
		if ((*pLoc)->pData->id == pKey) {
			return true;
		} else if ((*pLoc)->pData->id > pKey) {
			break;	
		}
	}
	return false;
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
