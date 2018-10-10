#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define bool int
#define true 1
#define false 0
#define int8 char
#define int16 short
#define int32 int

typedef struct Fruit
{
	char name[20];
	int priceInCents;
} Fruit;
struct Fruit fruits[5] = {
	{.name = "Apple", .priceInCents = 100},
	{.name = "Banana", .priceInCents = 200},
	{.name = "C", .priceInCents = 300},
	{.name = "D", .priceInCents = 400},
	{.name = "E", .priceInCents = 500},
};

typedef struct Time
{
	int8 hour;
	int8 minute;
	int8 second;
} Time;
typedef struct CashPayment
{
	int payInCents;
	int changeInCents; // fill automatically
} CashPayment;
typedef struct CardPayment
{
	int cardId;
	int beforeDepositInCents;
	int afterDepositInCents; // fill automatically
} CardPayment;
typedef union Payment {
	CashPayment cashPayment;
	CardPayment cardPayment;
} Payment;

typedef struct Invoice
{
	int id;
	Time time;
	int8 fruitId;
	float quantity;
	int priceInCents; // fill automatically
	Payment payment;
} Invoice;
typedef struct Node
{
	struct Invoice *pData; // data
	struct Node *pFather;  // previous node
	struct Node *pNext;	// next node
} Node;

struct Invoice *invoice_constructor_cash_pay(
	int id,
	int8 hour,
	int8 minute,
	int8 second,
	int8 fruitId,
	float quantity,
	int payInCents)
{
	Invoice *pInvoice = malloc(sizeof(struct Invoice));
	if (id >= 0 && id <= 9999)
		pInvoice->id = id;
	else
		printf("[WARNING] invalid input syntax for id"); // may be better to return NULL
	if (hour >= 0 && hour < 24)
		pInvoice->time.hour = hour;
	else
		printf("[WARNING] invalid input syntax for hour");
	if (minute >= 0 && minute < 60)
		pInvoice->time.minute = minute;
	else
		printf("[WARNING] invalid input syntax for minute");
	if (second >= 0 && second < 60)
		pInvoice->time.second = second;
	else
		printf("[WANRING] invalid input syntax for second");
	if (fruitId >= 0 && fruitId < 5)
		pInvoice->fruitId = fruitId;
	else
		printf("[WANRING] invalid input syntax for fruitId");
	if (quantity >= 0)
		pInvoice->quantity = quantity;
	else
		printf("[WARNING] quantity cannot be negative");
	pInvoice->priceInCents = fruits[fruitId].priceInCents * quantity;
	pInvoice->payment.cashPayment.payInCents = payInCents;
	pInvoice->payment.cashPayment.changeInCents = payInCents - pInvoice->priceInCents;
	return pInvoice;
}
struct Invoice *invoice_constructor_card_pay()
{
	return NULL;
	// fill by yourself
}
Node *node_constructor(Invoice *pInvoice, Node *pFather)
{
	Node *pNode = malloc(sizeof(Node));
	pNode->pData = pInvoice;
	pNode->pFather = pFather;
	pNode->pNext = NULL;
	return pNode;
}
// when using this function, please ensure pCurrent is not NULL
void node_append(Node *pCurrent, Node *pNode)
{
	Node *tail = pCurrent;
	while (tail->pNext != NULL)
		tail = tail->pNext;
	tail->pNext = pNode;
	pNode->pFather = tail;
}
void node_drop(Node *pNode)
{
	pNode->pFather->pNext = pNode->pNext;
	pNode->pNext->pFather = pNode->pFather;
	free(pNode);
}
Node *find_invoice_by_id(int id, Node *pFirst)
{
	Node *current = pFirst;
	while (current->pData->id != id && current->pNext != NULL)
	{
		current = current->pNext;
	}
	if (current->pData->id == id)
		return current;
	else
		return NULL;
}

int main()
{
	return 0;
}