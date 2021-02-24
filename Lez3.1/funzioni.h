/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <vector>

namespace tnds
{
	class funzioni
	{
	public:
		double calcola_media(std::vector<double> &datiOscilloscopioInMemoriaRam)
		{
			double media = 0;
			double somma = 0;
			auto numero_elementi = datiOscilloscopioInMemoriaRam.size();

			for (size_t i = 0; i < numero_elementi; i++)
			{
				somma += datiOscilloscopioInMemoriaRam[i];
			}

			media = somma / double(numero_elementi);

			return media;
		}

		double calcola_varianza(std::vector<double> &datiOscilloscopioInMemoriaRam)
		{
			double varianza = 0;
			double somma = 0;
			double media = calcola_media(datiOscilloscopioInMemoriaRam);

			auto numero_elementi = datiOscilloscopioInMemoriaRam.size();

			for (size_t i = 0; i < numero_elementi; i++)
			{
				somma += pow((datiOscilloscopioInMemoriaRam[i] - media), 2);
			}

			varianza = somma / double(numero_elementi);

			return varianza;
		}

		double calcola_mediana(std::vector<double> &datiOscilloscopioInMemoriaRam)
		{
			std::sort(datiOscilloscopioInMemoriaRam.begin(), datiOscilloscopioInMemoriaRam.end());

			auto numero_elementi = datiOscilloscopioInMemoriaRam.size();
			double elemento_mediano = (numero_elementi + 1 / 2.0);
			double mediana = datiOscilloscopioInMemoriaRam[elemento_mediano - 1];

			return mediana;
		}

		void print(std::vector<double> &datiOscilloscopioInMemoriaRam)
		{
			for (double d : datiOscilloscopioInMemoriaRam)
				std::cout << d << std::endl;
		}
	};
} // namespace tnds