int Infix::HT(string x)
{
	if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^" || x == "sqrt")
	{
		return 2;
	}
	else
	{
		return 1;
	}
}