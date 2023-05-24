// £ukasz Belka indeks nr. 156162

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void randomData(int numberOfYears, int numberOfMonths, float **rainfall, float minNum, float maxNum)
{
    for (int i = 0; i < numberOfYears; i++)
    {
        for (int j = 0; j < numberOfMonths; j++)
        {
            // rainfall[i][j] = (maxNum - minNum) * ((((float) rand()) / (float) RAND_MAX)) + minNum ;
            rainfall[i][j] = 0.1 * (rand() % 101);
        }
    }
}

string monthToSting(int month)
{
    string monthSting = "";
    switch (month)
    {
		case 0:
		{
		    monthSting = "STYCZEN";
		    break;
		}
		case 1:
		{
		    monthSting = "LUTY";
		    break;
		}
		case 2:
		{
		    monthSting = "MARZEC";
		    break;
		}
		case 3:
		{
		    monthSting = "KWIECIEN";
		    break;
		}
		case 4:
		{
		    monthSting = "MAJ";
		    break;
		}
		case 5:
		{
		    monthSting = "CZERWIEC";
		    break;
		}
		case 6:
		{
		    monthSting = "LIPIEC";
		    break;
		}
		case 7:
		{
		    monthSting = "SIERPIEN";
		    break;
		}
		case 8:
		{
		    monthSting = "WRZESIEN";
		    break;
		}
		case 9:
		{
		    monthSting = "PAZDZIERNIK";
		    break;
		}
		case 10:
		{
		    monthSting = "LISTOPAD";
		    break;
		}
		case 11:
		{
		    monthSting = "GRUDZIEN";
		    break;
		}
    }
    return monthSting;
}

void showData(int numberOfYears, int numberOfMonths, float **rainfall, int *years)
{ // cout << "liczba lat "<< numberOfYears;
    for (int i = 0; i < numberOfYears; i++)
    {
        cout << "Rok : " << years[i] << endl;
        for (int j = 0; j < numberOfMonths; j++)
        {
            cout << "Miesiac: " << monthToSting(j) << " = " << rainfall[i][j] << "  " << endl;
            // if((j+1) % 4 == 0){
            //  cout << endl;
            // }
        }
        cout << endl;
    }
    cout << endl;
}

void fillInnYears(int *years, int startYear, int endYear, int numberOfYears)
{
    for (int i = 0; i < numberOfYears; i++)
    {
        years[i] = startYear + i;
    }
}

void SumRain(float *rainSums, int numberOfYears, int numberOfMonths, float **rainfall)
{
	for (int i = 0; i < numberOfYears; i++)
	{
		rainSums[i] = 0;
	}

    for (int i = 0; i < numberOfYears; i++)
    {

        for (int j = 0; j < numberOfMonths; j++)
        {
            rainSums[i] += rainfall[i][j];
        }
    }
    //return rainSums;
}

void wroteAbstractData(float *data, int n, int *axis, string textType, string textItem)
{
    for (int i = 0; i < n; i++)
    {
        cout << textItem << axis[i] << textType << data[i] << endl;
    }
    cout << endl;
}

void wroteDataMoths(float *data, int n, string textType, string textItem)
{
    for (int i = 0; i < n; i++)
    {
        cout << textItem << monthToSting(i) << textType << data[i] << endl;
    }
    cout << endl;
}

void AvgYearRain(float *rainAvg, int numberOfYears, int numberOfMonths, float **rainfall)
{
    for (int i = 0; i < numberOfYears; i++)
    {
        rainAvg[i] = 0;
    }
    for (int i = 0; i < numberOfYears; i++)
    {
        for (int j = 0; j < numberOfMonths; j++)
        {
            rainAvg[i] += rainfall[i][j];
        }
        rainAvg[i] = rainAvg[i] / 12.0;
    }
    //return rainAvg;
}

void AvgMonthRain(float *rainAvg, int numberOfYears, int numberOfMonths, float **rainfall)
{
    for (int i = 0; i < numberOfMonths; i++)
    {
        rainAvg[i] = 0;
    }
    for (int i = 0; i < numberOfMonths; i++)
    {
        for (int j = 0; j < numberOfYears; j++)
        {
            rainAvg[i] += rainfall[j][i];
        }
    }
    for (int j = 0; j < numberOfMonths; j++)
    {
        rainAvg[j] = rainAvg[j] / numberOfYears;
    }
    //return rainAvg;
}

void BestRainsVoid(float **rainfall, int numberOfYears, int numberOfMonths, int *years)
{
    float maxRain = 0;
    int gigaRainsCounter = 0;
    for (int i = 0; i < numberOfYears; i++)
    {
        for (int j = 0; j < numberOfMonths; j++)
        {
            if (rainfall[i][j] == maxRain)
            {
                gigaRainsCounter++;
            }
            if (rainfall[i][j] > maxRain)
            {
                // if(abs(rainfall[i][j] - maxRain) < 0.1){
                maxRain = rainfall[i][j];
                gigaRainsCounter = 1;
                // cout <<"giga rain  " << rainfall[i][j]<<endl;
                // cout <<"max rain  " << setprecision(1) << maxRain<<endl;
                // cout <<"i " << i<<endl;
                // cout <<"j " << j<<endl;
            }
        }
    }
    int **bestReins = new int *[gigaRainsCounter];
    int counter = 0;
    for (int i = 0; i < numberOfYears; i++)
    {
        for (int j = 0; j < numberOfMonths; j++)
        {
            if (rainfall[i][j] == maxRain)
            {
                bestReins[counter] = new int[2];
                bestReins[counter][0] = j;
                bestReins[counter][1] = years[i];
                // cout <<"i " << i<<endl;
                // cout <<"j " << j<<endl;
                counter++;
            }
        }
    }

    // cout <<"ciounter " << gigaRainsCounter<<endl;
    cout << "najwyzsze opady wystepowaly w ";
    for (int i = 0; i < gigaRainsCounter; i++)
    {
        cout << monthToSting(bestReins[i][0]) << " / " << bestReins[i][1] << ", ";
    }
    cout << endl;
    for (int i = 0; i < counter; i++)
    {
        delete[] bestReins[i];
    }
    delete[] bestReins;
}

void saveValue(float **rainfall, int year, int month, int startYear, int numberOfYears, int numberOfMonths)
{
    int yearPosition = year - startYear;
    month = month - 1;
    float valueTemp = -1.0;
    while (valueTemp < 0 || valueTemp > 10)
    {
        cout << "Podaj wartosc do zmiany dla " << monthToSting(month) << " / " << year << " zakres przyjmowanych wartosci od 0.0 do 10.0" << endl;
        cin >> valueTemp;
    }

    rainfall[yearPosition][month] = valueTemp;

    cout << "*DANE ZAPISANO*" << endl;
    cout << "Data : " << monthToSting(month) << " / " << year << " wartosc opadow " << valueTemp << endl;
}

void changeData(float **rainfall, int startYear, int endYear, int numberOfYears, int numberOfMonths)
{
    int year = 0, month = 0, exit = 3;
    float valueTemp = 0.0;
    while (exit != 0)
    {
        cout << "okresl ktora wartosc chcesz zmienic" << endl;
        cout << "podaj rok: " << endl;
        cin >> year;
        cout << "podaj miesiac: " << endl;
        cin >> month;
        cout << "jesli chcesz wyjsc wpisz 0 jesli zas zapisac 1" << endl;
        cin >> exit;
        // if(exit == 0 )
        //     break;
        // }
        if (year >= startYear && year <= endYear && month >= 1 && month <= numberOfMonths)
        {
            if (exit == 1)
            {
                saveValue(rainfall, year, month, startYear, numberOfYears, numberOfMonths);
                exit = 0;
            }
        }
        else
        {
            cout << "wprowadzono dane niepoprawne lub spoza zakresu sprobuj jeszcze raz" << endl;
        }
        cout << endl;
    }
}

void changeYear(int &startYear, int &endYear, int &numberOfYears)
{
    cout << "Wprowadz poczatkowy i koncowy rok" << endl;
    cout << "podaj nowy rok poczatkowy: " << endl;
    cin >> startYear;
    cout << "podaj nowy rok koncowy: " << endl;
    cin >> endYear;
    numberOfYears = endYear - startYear+1;
}

void menu()
{
    int c = 9, numberOfYears = 5, numberOfMonths = 12, startYear = 2018, endYear = 2022;
    float minNum = 0.0, maxNum = 10.0;

    cout << fixed;
    // cout << showpoint;
    cout << setprecision(1);

    int *years = new int[numberOfYears];
    // string months[12] = {{"STYCZEN"}, {"LUTY"}, {"MARZEC"}, {"KWIECIEN"}, {"MAJ"}, {"CZERWIEC"}, {"LIPIEC"}, {"SIERPIEN"}, {"WRZESIEN"}, {"PAZDZIERNIK"}, {"LISTOPAD"}, {"GRUDZIEN"} };
    float **rainfall = new float *[numberOfYears];
    float *rainSums = new float[numberOfYears];
    float *rainYearAvgs = new float[numberOfYears];
    float *rainMonthAvgs = new float[numberOfMonths];

    for (int i=0;i<numberOfYears;i++)
	{
		rainfall[i] = new float [numberOfMonths];
	}

    fillInnYears(years, startYear, endYear, numberOfYears);
    randomData(numberOfYears, numberOfMonths, rainfall, minNum, maxNum);
    SumRain(rainSums, numberOfYears, numberOfMonths, rainfall);
    AvgYearRain(rainYearAvgs, numberOfYears, numberOfMonths, rainfall);
    AvgMonthRain(rainMonthAvgs, numberOfYears, numberOfMonths, rainfall);

    cout << "Lukasz Belka indeks nr. 156162 Zadanie projektowe 2.2" << endl;
    while (c != 0)
    {
        // cout <<"wjhile start";
        srand(time(0));
        cout << "Podaj co chcesz zrobic przez wprowadzenie numeru" << endl;
        cout << "1)Wyswietlic Dane " << endl;
        cout << "2)Korekta Danych " << endl;
        cout << "3)Losuj nowe wartosci " << endl;
        cout << "4)Zmien lata (UWAGA LOSUJE NOWE DANE) " << endl;
        cout << "0)Wyjdz" << endl;
        cin >> c;
        cout << endl;
        for (int i = 0; i < 100; i++)
        {
            cout << "-";
        }
        cout << endl;
        switch (c)
        {
        case 1:
        {
            showData(numberOfYears, numberOfMonths, rainfall, years);
            wroteAbstractData(rainSums, numberOfYears, years, " suma opadow wynosila ", "dla roku ");
            wroteAbstractData(rainYearAvgs, numberOfYears, years, " srednia opadow wynosila ", "dla roku ");
            // wroteDataMoths(rainMonthAvgs, numberOfMonths, months, " srednia opadow wynosila " , "dla miesiaca ");
            wroteDataMoths(rainMonthAvgs, numberOfMonths, " srednia opadow wynosila ", "dla miesiaca ");
            // int** listBestRains = BestRains(rainfall, numberOfYears, numberOfMonths, years);
            BestRainsVoid(rainfall, numberOfYears, numberOfMonths, years);
            break;
        }
        case 2:
        {
            changeData(rainfall, startYear, endYear, numberOfYears, numberOfMonths);
            SumRain(rainSums, numberOfYears, numberOfMonths, rainfall);
            AvgYearRain(rainYearAvgs, numberOfYears, numberOfMonths, rainfall);
            AvgMonthRain(rainMonthAvgs, numberOfYears, numberOfMonths, rainfall);
            break;
        }
        case 3:
        {
            randomData(numberOfYears, numberOfMonths, rainfall, minNum, maxNum);
            SumRain(rainSums, numberOfYears, numberOfMonths, rainfall);
            AvgYearRain(rainYearAvgs, numberOfYears, numberOfMonths, rainfall);
            AvgMonthRain(rainMonthAvgs, numberOfYears, numberOfMonths, rainfall);
            break;
        }
        case 4:
        {

            for (int i = 0; i < numberOfYears; i++)
            {
                delete[] rainfall[i];
            }
            delete[] rainfall;
            delete[] years;
            delete[] rainSums;
            delete[] rainYearAvgs;
            delete[] rainMonthAvgs;
            changeYear(startYear, endYear, numberOfYears);
            // cout <<" number of years outside after change Yer " << numberOfYears<< endl;
            years = new int[numberOfYears];
            // string months[12] = {{"STYCZEN"}, {"LUTY"}, {"MARZEC"}, {"KWIECIEN"}, {"MAJ"}, {"CZERWIEC"}, {"LIPIEC"}, {"SIERPIEN"}, {"WRZESIEN"}, {"PAZDZIERNIK"}, {"LISTOPAD"}, {"GRUDZIEN"} };
            // cout <<" usunieto tablice" << numberOfYears<< endl;
            rainfall = new float *[numberOfYears];
            rainSums = new float[numberOfYears];
            rainYearAvgs = new float[numberOfYears];
            rainMonthAvgs = new float[numberOfMonths];

            for (int i=0;i<numberOfYears;i++)
			{
				rainfall[i] = new float [numberOfMonths];
			}

            fillInnYears(years, startYear, endYear, numberOfYears);
            randomData(numberOfYears, numberOfMonths, rainfall, minNum, maxNum);
            SumRain(rainSums, numberOfYears, numberOfMonths, rainfall);
            AvgYearRain(rainYearAvgs, numberOfYears, numberOfMonths, rainfall);
            AvgMonthRain(rainMonthAvgs, numberOfYears, numberOfMonths, rainfall);

            break;
        }
        case 0:
        {
            for (int i = 0; i < numberOfYears; i++)
            {
                delete[] rainfall[i];
            }
            delete[] years;
            delete[] rainfall;
            delete[] rainSums;
            delete[] rainYearAvgs;
            delete[] rainMonthAvgs;
            break;
        }
        }
        cout << endl;
    }
}

int main()
{

    menu();

    return 0;
}
