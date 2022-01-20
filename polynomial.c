#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct $ {
	int coef;
	unsigned int degrees;
	struct $* next;
} Poly_Node;

// This function create a root poly node
Poly_Node* new_poly()
{
	Poly_Node* P = malloc(sizeof(Poly_Node));
	P->coef = 0;
	P->degrees = 0;
	P->next = NULL;

	return P;
}

// This function insert a new poly inside another poly
void create_poly(Poly_Node* P)
{
	Poly_Node* curr_poly_node = P->next;

	P->next = new_poly();

	P->next->next = curr_poly_node;
}

// This function permit to display a poly
void display_poly(Poly_Node* P)
{
	Poly_Node* curr_poly_node;

	for (curr_poly_node = P->next; curr_poly_node != NULL; curr_poly_node = curr_poly_node->next)
	{
		if (curr_poly_node->coef != 0)
		{
			// We show the sign if +
			printf("%c", (curr_poly_node->coef >= 0) ? '+' : '\0');

			// We show the coef
			if ((curr_poly_node->coef != 1 && curr_poly_node->coef != -1) || curr_poly_node->degrees == 0)
				printf("%i", curr_poly_node->coef);

			// We show the variable
			if (curr_poly_node->degrees > 0)
				printf("%cx", (curr_poly_node->coef == -1) ? '-' : '\0');

			// We show the degrees
			if (curr_poly_node->degrees > 1)
				printf("^%i", curr_poly_node->degrees);
		}
	}

	printf("\n");
}

// This function return the degree of the poly
// The degree of a poly is the highest degree of this poly
unsigned int degree_poly(Poly_Node* P)
{
	unsigned degrees = 0;
	Poly_Node* curr_poly_node;

	for (curr_poly_node = P->next; curr_poly_node != NULL; curr_poly_node = curr_poly_node->next)
	{
		if (curr_poly_node->degrees > degrees)
			degrees = curr_poly_node->degrees;
	}

	return degrees;
}

// This function parse an integer from a char
unsigned int parse_int(char x)
{
	if (x >= '0' && x <= '9')
	{
		return x - '0';
	}
	else
	{
		fprintf(stderr, "%c is not an integer\n", x);
		exit(EXIT_FAILURE);
	}
}

// This function permit to clear a poly
void clear_poly(Poly_Node* P)
{
	Poly_Node* curr_poly_node = P;

	// We clear in the end
	while (P->next != NULL)
	{
		for (curr_poly_node = P; curr_poly_node->next != NULL; curr_poly_node->next = curr_poly_node->next->next);

		// We delete the poly
		free(curr_poly_node->next);
	}
}

// This function permit to simplify a poly
void simplify_poly(Poly_Node* P)
{
	Poly_Node* curr_poly_node_a;
	Poly_Node* curr_poly_node_b;
	Poly_Node* R = new_poly();

	// we will sum polynomial of same degrees
	for (curr_poly_node_a = P->next; curr_poly_node_a != NULL; curr_poly_node_a = curr_poly_node_a->next)
	{
		// We begin by create a poly in R with data of the current poly
		create_poly(R);

		R->next->degrees = curr_poly_node_a->degrees;
		R->next->coef = curr_poly_node_a->coef;

		for (curr_poly_node_b = curr_poly_node_a->next; curr_poly_node_b != NULL; curr_poly_node_b = curr_poly_node_b->next)
		{
			if (R->next->degrees == curr_poly_node_b->degrees)
			{
				R->next->coef += curr_poly_node_b->coef;
				
				// We cancel this polynomial (because already used)
				curr_poly_node_b->degrees = 0;
				curr_poly_node_b->coef = 0;
			}
		}
	}

	// We replace the current poly by his simplify form
	// We clear the current poly
	clear_poly(P);

	// We set
	P->next = R->next;
}

// This function permit to add two poly
// :R is the result poly
void add_poly(Poly_Node* R, Poly_Node* P, Poly_Node* Q)
{
	Poly_Node* curr_poly_node_p;
	Poly_Node* curr_poly_node_q;

	// we clear the result poly
	clear_poly(R);

	// We will merge P and Q (partial adding)
	// R(x) = P(x) + Q(x)

	for (curr_poly_node_p = P->next; curr_poly_node_p != NULL; curr_poly_node_p = curr_poly_node_p->next)
	{
		create_poly(R);
		R->next->degrees = curr_poly_node_p->degrees;
		R->next->coef = curr_poly_node_p->coef;
	}

	for (curr_poly_node_q = Q->next; curr_poly_node_q != NULL; curr_poly_node_q = curr_poly_node_q->next)
	{
		create_poly(R);
		R->next->degrees = curr_poly_node_q->degrees;
		R->next->coef = curr_poly_node_q->coef;
	}

	// We simplify the result (complete adding)
	simplify_poly(R);
}


// This function parse a poly from a string
Poly_Node* parse_poly(char* string)
{
	int coef = 0;
	int degrees = 0;
	bool is_negative = 0;
	bool degrees_expected = 0;
	bool coef_expected = 1;
	bool coef_got = false;
	Poly_Node* P = new_poly();

	while (1)
	{
		// -..., ...-, ...\n, ...\0
		if (*string == '-' || *string == '+' || *string == '\n' || *string == '\0')
		{
			// -...
			if (*string == '-' && coef_expected && !coef_got)
				is_negative = 1;

			// x...-, ...-, ...\n, ...\0 
			if (!coef_expected || coef_got || *string == '\n' || *string == '\0')
			{
				// We save the current poly
				create_poly(P);
				P->next->coef = coef * (is_negative ? -1 : 1);
				P->next->degrees = degrees;

				// We init data
				coef = 0;
				degrees = 0;

				// We set the sign of the next poly
				is_negative = (*string == '-' ? true : false);

				coef_expected = true;
				degrees_expected = false;
				coef_got = false;
			}

			// We break th loop
			if (*string == '\n' || *string == '\0')
				break;
		}
		// ...x, ...x^
		else if (*string == 'x')
		{
			coef_expected = false;

			// We mark his default degrees in the case of no degree specified
			// ...x
			if (*(string+1) != '^')
			{
				degrees = 1;
			}
			// ...x^
			else
			{
				string++;
				degrees_expected = true;
			}

			// We mark his default coef in the case of no coef specified
			// x
			if (!coef_got)
				coef = 1;

		}
		else if (coef_expected)
		{
			coef = coef * 10 + parse_int(*string);
			coef_got = true;
		}
		else if (degrees_expected)
		{
			degrees = degrees * 10 + parse_int(*string);
		}
		else
		{
			fprintf(stderr, "Error, %c not expected\n", *string);
			exit(EXIT_FAILURE);
		}

		string++;
	}

	return P;
}

// This function permit to multiply two poly
// :R is the result poly
void multiply_poly(Poly_Node* R, Poly_Node* P, Poly_Node* Q)
{
	Poly_Node* curr_poly_node_p;
	Poly_Node* curr_poly_node_q;

	// we clear the result poly
	clear_poly(R);

	// We will multiply each element in P with element in Q
	for (curr_poly_node_p = P->next; curr_poly_node_p != NULL; curr_poly_node_p = curr_poly_node_p->next)
	{
		for (curr_poly_node_q = Q->next; curr_poly_node_q != NULL; curr_poly_node_q = curr_poly_node_q->next)
		{
			// We begin by create a poly in R
			create_poly(R);

			R->next->coef = curr_poly_node_p->coef * curr_poly_node_q->coef;
			R->next->degrees = curr_poly_node_p->degrees + curr_poly_node_q->degrees;
		}
	}

	// We simplify the result
	simplify_poly(R);
}

// This function permit to eval a poly
// P(x0)
int eval_poly(Poly_Node* P, int x0)
{
	Poly_Node* curr_poly_node;
	int value = 0;

	for (curr_poly_node = P->next; curr_poly_node != NULL; curr_poly_node = curr_poly_node->next)
	{
		value += curr_poly_node->coef * pow(x0, curr_poly_node->degrees);
	}

	return value;
}

int main()
{
	Poly_Node* R = new_poly();
	Poly_Node* P = parse_poly("6x^3+4x^2+7x+10");
	Poly_Node* Q = parse_poly("8x^4+10x^3-5x^2+3");
	
	// We add two poly and save the result in R
	add_poly(R, P, Q);

	// We display the result
	printf("P(x) + Q(x) = ");
	display_poly(R);

	// We multiply two poly
	printf("P(x) * Q(x) = ");
	multiply_poly(R, P, Q);

	// We display the result
	display_poly(R);

	// We eval the poly
	printf("P(3) = %i\nQ(3) = %i\n", eval_poly(P, 3), eval_poly(Q, 3));

	return 0;
}
