/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <fstream>

#include "funzioni.hpp"
#include "vettore.hpp"

using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		cout << "Uso del programma: " << argv[0] << " <n_data> <filename>" << endl;
		return 0;
	}

	int ndata = atoi(argv[1]);
	vettore<double> data(ndata);

	//1) leggi dati da file
	{
		char *filename = argv[2];

		ifstream file_input(filename);

		if (!file_input)
		{
			cout << "Non posso aprire il file " << filename << endl;
			return -1;
		}
		else
		{
			for (size_t i = 0; i < ndata; i++)
			{
				if (file_input.eof())
				{
					cout << "Fine del file raggiunta prematuramente dopo " << i << " elementi" << endl;
					return -2;
				}

				file_input >> data[i];
			}
		}
		//file_input autoclose + autodestroy
	}

	//2) calcolo media e varianza
	{
		funzioni<double> fn;

		double media = fn.media(data, ndata);
		double varianza = fn.varianza(data, ndata, media);
		double mediana = fn.mediana(data, ndata);

		cout << "Media: " << media << "; Varianza: " << varianza << endl;
		cout << "Mediana: " << mediana << endl;

		//funzioni autodestroy
	}

	//5) scrittura elementi su file
	{
		auto log = "output_file.txt";

		ofstream file_output(log);

		for (size_t i = 0; i < ndata; i++)
			file_output << data[i] << endl;

		//file_output autoclose + autodestroy
	}

	//data autodestroy

	return 0;
}