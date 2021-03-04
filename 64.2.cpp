#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    	ifstream dane("dane_obrazki.txt");
    	ofstream dane2("wyniki_obrazki2.txt");
    
	string linijka;
	string obrazki[200][20][20] = {{{0}}};

	int liczLinijki = 0;
	int liczObrazki = 0;

    	bool sprawdzRekurencje = true;
	int rekurencja[10][10] = {{ 0 }};
	int liczRekurencyjne = 0;

    	int obrazek[20][20] = { { 0 } };
	while(dane >> linijka)
    	{
		for(int a=0; a<linijka.length(); a++)
        {
		obrazki[liczObrazki][liczLinijki][a] = linijka[a];
		int aktWartosc = linijka[a] - '0';

            	if(sprawdzRekurencje)
            	{
			if(liczLinijki < 10)
                	{
				if(a < 10)
                    		{
					rekurencja[liczLinijki][a] = aktWartosc;
					}
						else if(a >= 10 && a<20 && rekurencja[liczLinijki][a-10] != aktWartosc) 
                    			{
						sprawdzRekurencje = false;
					}
				}
				else if (liczLinijki < 20) 
                		{
					if(a < 10 && rekurencja[liczLinijki-10][a] != aktWartosc)
                    			{
						sprawdzRekurencje = false;
					}
					else if(a >= 10 && a<20 && rekurencja[liczLinijki-10][a-10] != aktWartosc)
                    			{
						sprawdzRekurencje = false;
					}
				}
			}
		}

        liczLinijki++;
		if(liczLinijki == 20)
        	{
			obrazki[liczObrazki] = obrazek;
			obrazek = new int[20][20];
			if(sprawdzRekurencje == true)
            		{
				liczRekurencyjne++;
				if(liczRekurencyjne == 1)
                		{
					for(int n=0; n<20; n++)
                    			{
						int newN = (n >= 10) ? n-10 : n;
						for(int m=0; m<20; m++)
                        			{
							if(m>=10)
                            				{
								cout << rekurencja[newN][m-10];
							}
							else 
                            				{
								cout << rekurencja[newN][m];
							}
						}
						cout << endl;
					}
				}
				for(int z=0; z<10; z++)
                		{
					for(int x=0; x<10; x++)
                    			{
						rekurencja[x][z] = 0;
					}
				}
			}
        liczLinijki = 0;
	liczObrazki++;
        }
    }

    	cout << "Rekurencyjne: " << liczRekurencyjne << endl;
	cout << "Pierwszy rekurencyjny: " << liczRekurencyjne << endl;

    	dane.close();
    	dane2.close();
	return 0;
}
