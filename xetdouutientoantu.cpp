	int Infix(string x)
	{
			if (x == "sqrt" || x == "^")
				{
				    return 3;
				}
			if (x == "*" || x == "/" || x == "%" || x == "^" || x == "sqrt")
				{
					return 2;
				}
		else if (x == "+" || x == "-")
			{
					return 1;
				}
			else if (x == "(")
				{
					return 0;
				}
		}
