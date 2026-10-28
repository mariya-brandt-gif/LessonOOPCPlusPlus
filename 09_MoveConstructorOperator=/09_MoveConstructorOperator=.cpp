#include"book.h"

int main()
{
	Book book("Kobzar", 1865, "Shevchenko", 1200, Genre::Novel);
	book.ShowInfo();
}
