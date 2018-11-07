string CalcValue(string b, string x, string a)
{

	float fResult = 0;

	if (x == "sqrt")
	{
		fResult = int(sqrt(atof(a.c_str())));
	}

	if (x == "^")
	{
		fResult = 1;
		for (int i = 1; i <= int(atof(a.c_str())); i++)
			fResult = fResult * atof(b.c_str());

	}

	if (x == "%")
	{
		fResult = int(atof(b.c_str())) % int(atof(a.c_str()));
	}

	if (x == "*")
	{
		fResult = atof(b.c_str()) * atof(a.c_str());

	}

	else if (x == "/")
	{
		fResult = atof(b.c_str()) / atof(a.c_str());

	}

	else if (x == "+")
	{
		fResult = atof(b.c_str()) + atof(a.c_str());

	}

	else if (x == "-")
	{
		fResult = atof(b.c_str()) - atof(a.c_str());

	}

	string strResult = to_string(fResult);
	return strResult;

}