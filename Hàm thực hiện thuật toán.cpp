float CalcValue(vector<string> M)
{
	float fResult = 0;

	Stack* Sh = new Stack();
	Stack* St = new Stack();

	int iLength = M.size();

	for (int i = 0; i < iLength; i++)
	{
		if (HT(M[i]) == 1 && M[i] != "(" && M[i] != ")")
		{
			Sh->Push(M[i]);
		}

		if (M[i] == "(")
		{
			St->Push(M[i]);
		}

		if (HT(M[i]) == 2)
		{
			while (!St->IsEmpty() && (UT(M[i]) <= UT(St->GetHead()->Info)))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(this->CalcValue(b, x, a));
			}
			St->Push(M[i]);
		}

		if (M[i] == ")")
		{

			while (St->GetHead()->Info != "(")
			{

				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(this->CalcValue(b, x, a));
			}
			string c = "";
			St->Pop(c);
		}
	}

	while (!St->IsEmpty())
	{
		string a = "";
		Sh->Pop(a);
		string x = "";
		St->Pop(x);
		string b = "";
		Sh->Pop(b);
		Sh->Push(this->CalcValue(b, x, a));
	}

	string strResult = "";
	Sh->Pop(strResult);
	fResult = atof(strResult.c_str());
	return fResult;
}