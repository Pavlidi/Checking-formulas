#include <iostream>                                             // Для операторов cin и cout
#include <ctime>                                                // Для функции srand() которая помогает делать реальный рандомайзер
#include <cmath>                                                // Для математических операторов
#include <string>
using namespace std;

struct Formula
{
    string formula;
    string answer;
};

int main_menu()                                                 // Функция которая выводит главное меню
{
    int choice_mm;
    cout << "\033[2J\033[1;1H";
    cout << "\"Генератор заданий ЕГЭ: математика\"\n" << endl;
    cout << "Выберите действие:" << endl;
    cout << "1. Сгенерировать формулы по темам" << endl;
    cout << "2. Сгенерировать все формулы" << endl << endl;
    cout << "0. Выход" << endl << endl;
    cout << "Ваш выбор: ";
    cin >> choice_mm;
    return choice_mm;
}

int Min(int first, int second)
{
    int answer;
    answer = first;
    if(answer > second)
        answer = second;
    return answer;
}

int AlgebraicExpressionCHECK[8] = {0,0,0,0,0,0,0,0};
int DegreeCHECK[7] = {0,0,0,0,0,0,0};
int SquareRootCHECK[8] = {0,0,0,0,0,0,0,0};
int LogarithmsCHECK[11] = {0,0,0,0,0,0,0,0,0,0};

int TrigonomBaseCHECK[4] = {0,0,0,0};
int TrigonomFormulCHECK[7] = {0,0,0,0,0,0,0};
int TrigonomMeanSCCHECK[66];
int TrigonomMeanTCCHECK[57];

int TriangleCHECK[9] = {0,0,0,0,0,0,0,0,0};
int QuadrangleCHECK[8] = {0,0,0,0,0,0,0,0};
int CircleCHECK[2] = {0,0};
int VectorCHECK[4] = {0,0,0,0};

int PrizmaCHECK[3] = {0,0,0};
int PiramidaCHECK[3] = {0,0,0};
int CilindrCHECK[4] = {0,0,0,0};
int KonusCHECK[4] = {0,0,0,0};
int BallCHECK[2] = {0,0};
int PodobCHECK[3] = {0,0,0};

int ArifmetProgCHECK[2] = {0,0};
int GeometrProgCHECK[2] = {0,0};

int ProizvodnMainCHECK[8] = {0,0,0,0,0,0,0,0};
int ProizvodnArifmCHECK[3] = {0,0,0};

string AlgebraicExpression()
{
    string Answer;
    Formula a[8];
    int unit, check;

    a[0].formula = "\\item     $$ax^2+bx+c";
    a[0].answer = "\\item     $$a(x-x_1)(x-x_2)";

    a[1].formula = "\\item     $$(a+b)^2";
    a[1].answer = "\\item     $$a^2+2ab+b^2";

    a[2].formula = "\\item     $$(a-b)^2";
    a[2].answer = "\\item     $$a^2-2ab+b^2";

    a[3].formula = "\\item     $$a^2-b^2";
    a[3].answer = "\\item     $$(a-b)(a+b)";;

    a[4].formula = "\\item     $$(a+b)^3";
    a[4].answer = "\\item     $$a^3+3a^2b+3ab^2+b^3";

    a[5].formula = "\\item     $$(a-b)^3";
    a[5].answer = "\\item     $$a^3-3a^2b+3ab^2-b^3";

    a[6].formula = "\\item     $$a^3+b^3";
    a[6].answer = "\\item     $$(a+b)(a^2-ab+b^2)";

    a[7].formula = "\\item     $$a^3-b^3";
    a[7].answer = "\\item     $$(a-b)(a^2+ab+b^2)";

    check = 1;
        do{
            unit = rand()%8;
            if(AlgebraicExpressionCHECK[unit] == 0)
            {
                AlgebraicExpressionCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if(rand() % 2 == 0)
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            cout << a[unit].answer << "= $$ \n";
            Answer =  a[unit].formula + "$$ \n";
        }
    return Answer;
}

string Degree()
{
    string Answer;
    Formula a[7];
    int unit, check;

    a[0].formula = "\\item     $$a^m\\cdot a^n";
    a[0].answer = "\\item     $$a^{m+n}";

    a[1].formula = "\\item     $$\\frac{a^m}{a^n}";
    a[1].answer = "\\item     $$a^{m-n}";

    a[2].formula = "\\item     $$\\left(a^m\\right)^n";
    a[2].answer = "\\item     $$a^{m\\cdot n}";

    a[3].formula = "\\item     $$\\left(a\\cdot b\\right)^m";
    a[3].answer = "\\item     $$a^m\\cdot b^m";

    a[4].formula = "\\item     $$\\left(\\frac{a}{b}\\right)^m";
    a[4].answer = "\\item     $$\\frac{a^m}{b^m}";

    a[5].formula = "\\item     $$a^{-1}";
    a[5].answer = "\\item     $$\\frac{1}{a}";

    a[6].formula = "\\item     $$\\left(\\frac{1}{a}\\right)^{-1}";
    a[6].answer = "\\item     $$a";

    check = 1;
        do{
            unit = rand()%7;
            if(DegreeCHECK[unit] == 0)
            {
                DegreeCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if((unit == 5) || (unit == 6))
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            if(rand() % 2 == 0)
            {
                cout << a[unit].formula << "= $$ \n";
                Answer =  a[unit].answer + "$$ \n";
            }
            else
            {
                cout << a[unit].answer << "= $$ \n";
                Answer =  a[unit].formula + "$$ \n";
            }
        }
    return Answer;
}

string SquareRoot()
{
    string Answer;
    Formula a[8];
    int unit, check;

    a[0].formula = "\\item     $$\\left(\\sqrt[n]{a}\\right)^m";
    a[0].answer = "\\item     $$a^{\\frac{m}{n}}";

    a[1].formula = "\\item     $$\\sqrt{ab}";
    a[1].answer = "\\item     $$\\sqrt{a}\\sqrt{b}";

    a[2].formula = "\\item     $$\\sqrt{\\frac{a}{b}}";
    a[2].answer = "\\item     $$\\frac{\\sqrt{a}}{\\sqrt{b}}";

    a[3].formula = "\\item     $$\\sqrt{a^2}";
    a[3].answer = "\\item     $$|a|";

    a[4].formula = "\\item     $$\\sqrt{a^k}";
    a[4].answer = "\\item     $$\\sqrt{a}^k";

    a[5].formula = "\\item     $$\\sqrt[3]{ab}";
    a[5].answer = "\\item     $$\\sqrt[3]a\\sqrt[3]b";

    a[6].formula = "\\item     $$\\sqrt[3]{\\frac{a}{b}}";
    a[6].answer = "\\item     $$\\frac{\\sqrt[3]a}{\\sqrt[3]b}";

    a[7].formula = "\\item     $$\\sqrt[3]{a^k}";
    a[7].answer = "\\item     $$\\left(\\sqrt[3]a\\right)^k";

    check = 1;
        do{
            unit = rand()%8;
            if(SquareRootCHECK[unit] == 0)
            {
                SquareRootCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if(unit == 3)
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            if(rand() % 2 == 0)
            {
                cout << a[unit].formula << "= $$ \n";
                Answer =  a[unit].answer + "$$ \n";
            }
            else
            {
                cout << a[unit].answer << "= $$ \n";
                Answer =  a[unit].formula + "$$ \n";
            }
        }
    return Answer;
}

string Logarithms()
{
    string Answer;
    Formula a[11];
    int unit, check;

    a[0].formula = "\\item     $$\\log_a1";
    a[0].answer = "\\item     $$0";

    a[1].formula = "\\item     $$\\log_aa";
    a[1].answer = "\\item     $$1";

    a[2].formula = "\\item     $$\\log_a(xy)";
    a[2].answer = "\\item     $$\\log_ax+\\log_ay";

    a[3].formula = "\\item     $$\\log_a\\left(\\frac{x}{y}\\right)";
    a[3].answer = "\\item     $$\\log_ax-\\log_ay";

    a[4].formula = "\\item     $$\\log_a(x)^n";
    a[4].answer = "\\item     $$n\\cdot\\log_a(x)";

    a[5].formula = "\\item     $$\\log_{a^n}(x)";
    a[5].answer = "\\item     $$\\frac{1}{n}\\log_a(x)";

    a[6].formula = "\\item     $$a^{\\log_ab}";
    a[6].answer = "\\item     $$b";

    a[7].formula = "\\item     $$\\frac{\\log_c(x)}{\\log_c(a)}";
    a[7].answer = "\\item     $$\\log_a(x)";

    a[8].formula = "\\item     $$\\log_a(b)\\cdot\\log_b(a)";
    a[8].answer = "\\item     $$1";

    a[9].formula = "\\item     $$\\log_a\\sqrt[n]{x}";
    a[9].answer = "\\item     $$\\frac{1}{n}\\log_ax";

    a[10].formula = "\\item     $$\\log_{\\sqrt[n]{a}}(x)";
    a[10].answer = "\\item     $$n\\cdot\\log_a(x)";

    check = 1;
        do{
            unit = rand()%11;
            if(LogarithmsCHECK[unit] == 0)
            {
                LogarithmsCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if((unit == 0) || (unit == 1) || (unit == 4) || (unit == 5) || (unit == 6) || (unit == 7) || (unit == 8) || (unit == 9) || (unit == 10))
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            if(rand() % 2 == 0)
            {
                cout << a[unit].formula << "= $$ \n";
                Answer =  a[unit].answer + "$$ \n";
            }
            else
            {
                cout << a[unit].answer << "= $$ \n";
                Answer =  a[unit].formula + "$$ \n";
            }
        }
    return Answer;
}

string TrigonomBase()
{
    string Answer;
    Formula a[4];
    int unit, check;

    a[0].formula = "\\item     $$\\sin(\\alpha)";
    a[0].answer = "\\item     $$\\frac{\\text{противолежащий катет}}{\\text{гипотенуза}}";

    a[1].formula = "\\item     $$\\cos(\\alpha)";
    a[1].answer = "\\item     $$\\frac{\\text{прилежащий катет}}{\\text{гипотенуза}}";

    a[2].formula = "\\item     $$\\tg(\\alpha)";
    a[2].answer = "\\item     $$\\frac{\\text{противолежащий катет}}{\\text{прилежащий катет}}";

    a[3].formula = "\\item     $$\\ctg(\\alpha)";
    a[3].answer = "\\item     $$\\frac{\\text{прилежащий катет}}{\\text{противолежащий катет}}";

    check = 1;
        do{
            unit = rand()%4;
            if(TrigonomBaseCHECK[unit] == 0)
            {
                TrigonomBaseCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if(rand() % 2 == 0)
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            cout << a[unit].answer << "= $$ \n";
            Answer =  a[unit].formula + "$$ \n";
        }
    return Answer;
}

string TrigonomFormul()
{
    string Answer;
    Formula a[7];
    int unit, check;

    a[0].formula = "\\item     $$\\sin^2(\\alpha)+\\cos^2(\\alpha)";
    a[0].answer = "\\item     $$1";

    a[1].formula = "\\item     $$\\sin(2\\alpha)";
    a[1].answer = "\\item     $$2\\sin(\\alpha)\\cos(\\alpha)";

    a[2].formula = "\\item     $$\\cos(2\\alpha)";
    a[2].answer = "\\item     $$\\cos^2(\\alpha)-\\sin^2(\\alpha)";

    a[3].formula = "\\item     $$\\cos(2\\alpha)";
    a[3].answer = "\\item     $$2\\cos^2(\\alpha)-1";

    a[4].formula = "\\item     $$\\cos(2\\alpha)";
    a[4].answer = "\\item     $$1-2\\sin^2(\\alpha)";

    a[5].formula = "\\item     $$\\sin(\\alpha\\pm\\beta)";
    a[5].answer = "\\item     $$\\sin(\\alpha)\\cos(\\beta)\\pm\\sin(\\beta)\\cos(\\alpha)";

    a[6].formula = "\\item     $$\\cos(\\alpha\\pm\\beta)";
    a[6].answer = "\\item     $$\\cos(\\alpha)\\cos(\\beta)\\mp\\sin(\\alpha)\\sin(\\beta)";

    check = 1;
        do{
            unit = rand()%7;
            if(TrigonomFormulCHECK[unit] == 0)
            {
                TrigonomFormulCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        if(unit == 0)
        {
            cout << a[unit].formula << "= $$ \n";
            Answer =  a[unit].answer + "$$ \n";
        }
        else
        {
            if(rand() % 2 == 0)
            {
                cout << a[unit].formula << "= $$ \n";
                Answer =  a[unit].answer + "$$ \n";
            }
            else
            {
                cout << a[unit].answer << "= $$ \n";
                Answer =  a[unit].formula + "$$ \n";
            }
        }
    return Answer;
}

string TrigonomMeanSC()
{
    string Answer;
    Formula a[66];
    int unit, check;
        
    a[0].formula = "\\item     $$\\sin\\left(-2\\pi\\right)";                   //sin
    a[0].answer = "\\item     $$0";

    a[1].formula = "\\item     $$\\sin\\left(-\\frac{11\\pi}{6}\\right)";
    a[1].answer = "\\item     $$\\frac{1}{2}";

    a[2].formula = "\\item     $$\\sin\\left(-\\frac{7\\pi}{4}\\right)";
    a[2].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[3].formula = "\\item     $$\\sin\\left(-\\frac{5\\pi}{3}\\right)";
    a[3].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[4].formula = "\\item     $$\\sin\\left(-\\frac{3\\pi}{2}\\right)";
    a[4].answer = "\\item     $$1";

    a[5].formula = "\\item     $$\\sin\\left(-\\frac{4\\pi}{3}\\right)";
    a[5].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[6].formula = "\\item     $$\\sin\\left(-\\frac{5\\pi}{4}\\right)";
    a[6].answer = "\\item     $$\\frac{\\sqrt{2}}{2}"; //

    a[7].formula = "\\item     $$\\sin\\left(-\\frac{7\\pi}{6}\\right)";
    a[7].answer = "\\item     $$\\frac{1}{2}";

    a[8].formula = "\\item     $$\\sin\\left(-\\pi\\right)";
    a[8].answer = "\\item     $$0";

    a[9].formula = "\\item     $$\\sin\\left(-\\frac{5\\pi}{6}\\right)";
    a[9].answer = "\\item     $$-\\frac{1}{2}";

    a[10].formula = "\\item     $$\\sin\\left(-\\frac{3\\pi}{4}\\right)";
    a[10].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}";

    a[11].formula = "\\item     $$\\sin\\left(-\\frac{2\\pi}{3}\\right)";
    a[11].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[12].formula = "\\item     $$\\sin\\left(-\\frac{\\pi}{2}\\right)";
    a[12].answer = "\\item     $$-1";

    a[13].formula = "\\item     $$\\sin\\left(-\\frac{\\pi}{3}\\right)";
    a[13].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[14].formula = "\\item     $$\\sin\\left(-\\frac{\\pi}{4}\\right)";
    a[14].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}";

    a[15].formula = "\\item     $$\\sin\\left(-\\frac{\\pi}{6}\\right)";
    a[15].answer = "\\item     $$-\\frac{1}{2}";

    a[16].formula = "\\item     $$\\sin\\left(0\\right)";
    a[16].answer = "\\item     $$0";                                             //

    a[17].formula = "\\item     $$\\sin\\left(2\\pi\\right)";
    a[17].answer = "\\item     $$0";

    a[18].formula = "\\item     $$\\sin\\left(\\frac{11\\pi}{6}\\right)";
    a[18].answer = "\\item     $$-\\frac{1}{2}";

    a[19].formula = "\\item     $$\\sin\\left(\\frac{7\\pi}{4}\\right)";
    a[19].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}";

    a[20].formula = "\\item     $$\\sin\\left(\\frac{5\\pi}{3}\\right)";
    a[20].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[21].formula = "\\item     $$\\sin\\left(\\frac{3\\pi}{2}\\right)";
    a[21].answer = "\\item     $$-1";

    a[22].formula = "\\item     $$\\sin\\left(\\frac{4\\pi}{3}\\right)";
    a[22].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[23].formula = "\\item     $$\\sin\\left(\\frac{5\\pi}{4}\\right)";
    a[23].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}"; //

    a[24].formula = "\\item     $$\\sin\\left(\\frac{7\\pi}{6}\\right)";
    a[24].answer = "\\item     $$-\\frac{1}{2}";

    a[25].formula = "\\item     $$\\sin\\left(\\pi\\right)";
    a[25].answer = "\\item     $$0";

    a[26].formula = "\\item     $$\\sin\\left(\\frac{5\\pi}{6}\\right)";
    a[26].answer = "\\item     $$\\frac{1}{2}";

    a[27].formula = "\\item     $$\\sin\\left(\\frac{3\\pi}{4}\\right)";
    a[27].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[28].formula = "\\item     $$\\sin\\left(\\frac{2\\pi}{3}\\right)";
    a[28].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[29].formula = "\\item     $$\\sin\\left(\\frac{\\pi}{2}\\right)";
    a[29].answer = "\\item     $$1";

    a[30].formula = "\\item     $$\\sin\\left(\\frac{\\pi}{3}\\right)";
    a[30].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[31].formula = "\\item     $$\\sin\\left(\\frac{\\pi}{4}\\right)";
    a[31].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[32].formula = "\\item     $$\\sin\\left(\\frac{\\pi}{6}\\right)";
    a[32].answer = "\\item     $$\\frac{1}{2}";

    a[33].formula = "\\item     $$\\cos\\left(-2\\pi\\right)";                   //cos
    a[33].answer = "\\item     $$1";

    a[34].formula = "\\item     $$\\cos\\left(-\\frac{11\\pi}{6}\\right)";
    a[34].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[64].formula = "\\item     $$\\cos\\left(-\\frac{7\\pi}{4}\\right)";
    a[64].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[35].formula = "\\item     $$\\cos\\left(-\\frac{5\\pi}{3}\\right)";
    a[35].answer = "\\item     $$\\frac{1}{2}";

    a[36].formula = "\\item     $$\\cos\\left(-\\frac{3\\pi}{2}\\right)";
    a[36].answer = "\\item     $$0";

    a[37].formula = "\\item     $$\\cos\\left(-\\frac{4\\pi}{3}\\right)";
    a[37].answer = "\\item     $$-\\frac{1}{2}";

    a[38].formula = "\\item     $$\\cos\\left(-\\frac{5\\pi}{4}\\right)";
    a[38].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}"; //

    a[39].formula = "\\item     $$\\cos\\left(-\\frac{7\\pi}{6}\\right)";
    a[39].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[40].formula = "\\item     $$\\cos\\left(-\\pi\\right)";
    a[40].answer = "\\item     $$-1";

    a[41].formula = "\\item     $$\\cos\\left(-\\frac{5\\pi}{6}\\right)";
    a[41].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[42].formula = "\\item     $$\\cos\\left(-\\frac{3\\pi}{4}\\right)";
    a[42].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}";

    a[43].formula = "\\item     $$\\cos\\left(-\\frac{2\\pi}{3}\\right)";
    a[43].answer = "\\item     $$-\\frac{1}{2}";

    a[44].formula = "\\item     $$\\cos\\left(-\\frac{\\pi}{2}\\right)";
    a[44].answer = "\\item     $$0";

    a[45].formula = "\\item     $$\\cos\\left(-\\frac{\\pi}{3}\\right)";
    a[45].answer = "\\item     $$\\frac{1}{2}";

    a[46].formula = "\\item     $$\\cos\\left(-\\frac{\\pi}{4}\\right)";
    a[46].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[47].formula = "\\item     $$\\cos\\left(-\\frac{\\pi}{6}\\right)";
    a[47].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[48].formula = "\\item     $$\\cos\\left(0\\right)";
    a[48].answer = "\\item     $$1";                                             //

    a[49].formula = "\\item     $$\\cos\\left(2\\pi\\right)";                   
    a[49].answer = "\\item     $$1";

    a[50].formula = "\\item     $$\\cos\\left(\\frac{11\\pi}{6}\\right)";
    a[50].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    a[51].formula = "\\item     $$\\cos\\left(\\frac{7\\pi}{4}\\right)";
    a[51].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[52].formula = "\\item     $$\\cos\\left(\\frac{5\\pi}{3}\\right)";
    a[52].answer = "\\item     $$\\frac{1}{2}";

    a[53].formula = "\\item     $$\\cos\\left(\\frac{3\\pi}{2}\\right)";
    a[53].answer = "\\item     $$0";

    a[54].formula = "\\item     $$\\cos\\left(\\frac{4\\pi}{3}\\right)";
    a[54].answer = "\\item     $$-\\frac{1}{2}";

    a[55].formula = "\\item     $$\\cos\\left(\\frac{5\\pi}{4}\\right)";
    a[55].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}"; //

    a[56].formula = "\\item     $$\\cos\\left(\\frac{7\\pi}{6}\\right)";
    a[56].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[57].formula = "\\item     $$\\cos\\left(\\pi\\right)";
    a[57].answer = "\\item     $$-1";

    a[58].formula = "\\item     $$\\cos\\left(\\frac{5\\pi}{6}\\right)";
    a[58].answer = "\\item     $$-\\frac{\\sqrt{3}}{2}";

    a[59].formula = "\\item     $$\\cos\\left(\\frac{3\\pi}{4}\\right)";
    a[59].answer = "\\item     $$-\\frac{\\sqrt{2}}{2}";

    a[60].formula = "\\item     $$\\cos\\left(\\frac{2\\pi}{3}\\right)";
    a[60].answer = "\\item     $$-\\frac{1}{2}";

    a[61].formula = "\\item     $$\\cos\\left(\\frac{\\pi}{2}\\right)";
    a[61].answer = "\\item     $$0";

    a[62].formula = "\\item     $$\\cos\\left(\\frac{\\pi}{3}\\right)";
    a[62].answer = "\\item     $$\\frac{1}{2}";

    a[63].formula = "\\item     $$\\cos\\left(\\frac{\\pi}{4}\\right)";
    a[63].answer = "\\item     $$\\frac{\\sqrt{2}}{2}";

    a[65].formula = "\\item     $$\\cos\\left(\\frac{\\pi}{6}\\right)";
    a[65].answer = "\\item     $$\\frac{\\sqrt{3}}{2}";

    check = 1;
    do{
        unit = rand()%66;
        if(TrigonomMeanSCCHECK[unit] == 0)
        {
            TrigonomMeanSCCHECK[unit] = 1;
            check = 0;
        }
    }while(check != 0);

    cout << a[unit].formula << "= $$ \n";
    Answer =  a[unit].answer + "$$ \n";

    return Answer;
}

string TrigonomMeanTC()
{
    string Answer;
    Formula a[57];
    int unit, check;
        
    a[0].formula = "\\item     $$\\tg\\left(-2\\pi\\right)";                   //tg
    a[0].answer = "\\item     $$0";

    a[1].formula = "\\item     $$\\tg\\left(-\\frac{11\\pi}{6}\\right)";
    a[1].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[2].formula = "\\item     $$\\tg\\left(-\\frac{7\\pi}{4}\\right)";
    a[2].answer = "\\item     $$1";

    a[3].formula = "\\item     $$\\tg\\left(-\\frac{5\\pi}{3}\\right)";
    a[3].answer = "\\item     $$\\sqrt{3}";

    a[4].formula = "\\item     $$\\tg\\left(-\\frac{4\\pi}{3}\\right)";
    a[4].answer = "\\item     $$-\\sqrt{3}";

    a[5].formula = "\\item     $$\\tg\\left(-\\frac{5\\pi}{4}\\right)";
    a[5].answer = "\\item     $$-1"; //

    a[6].formula = "\\item     $$\\tg\\left(-\\frac{7\\pi}{6}\\right)";
    a[6].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[7].formula = "\\item     $$\\tg\\left(-\\pi\\right)";
    a[7].answer = "\\item     $$0";

    a[8].formula = "\\item     $$\\tg\\left(-\\frac{5\\pi}{6}\\right)";
    a[8].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[9].formula = "\\item     $$\\tg\\left(-\\frac{3\\pi}{4}\\right)";
    a[9].answer = "\\item     $$1";

    a[10].formula = "\\item     $$\\tg\\left(-\\frac{2\\pi}{3}\\right)";
    a[10].answer = "\\item     $$\\sqrt{3}";

    a[11].formula = "\\item     $$\\tg\\left(-\\frac{\\pi}{3}\\right)";
    a[11].answer = "\\item     $$-\\sqrt{3}";

    a[12].formula = "\\item     $$\\tg\\left(-\\frac{\\pi}{4}\\right)";
    a[12].answer = "\\item     $$-1";

    a[13].formula = "\\item     $$\\tg\\left(-\\frac{\\pi}{6}\\right)";
    a[13].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[14].formula = "\\item     $$\\tg\\left(0\\right)";
    a[14].answer = "\\item     $$0";                                             //

    a[15].formula = "\\item     $$\\tg\\left(2\\pi\\right)";
    a[15].answer = "\\item     $$0";

    a[16].formula = "\\item     $$\\tg\\left(\\frac{11\\pi}{6}\\right)";
    a[16].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[17].formula = "\\item     $$\\tg\\left(\\frac{7\\pi}{4}\\right)";
    a[17].answer = "\\item     $$-1";

    a[18].formula = "\\item     $$\\tg\\left(\\frac{5\\pi}{3}\\right)";
    a[18].answer = "\\item     $$-\\sqrt{3}";

    a[19].formula = "\\item     $$\\tg\\left(\\frac{4\\pi}{3}\\right)";
    a[19].answer = "\\item     $$\\sqrt{3}";

    a[20].formula = "\\item     $$\\tg\\left(\\frac{5\\pi}{4}\\right)";
    a[20].answer = "\\item     $$1"; //

    a[21].formula = "\\item     $$\\tg\\left(\\frac{7\\pi}{6}\\right)";
    a[21].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[22].formula = "\\item     $$\\tg\\left(\\pi\\right)";
    a[22].answer = "\\item     $$0";

    a[23].formula = "\\item     $$\\tg\\left(\\frac{5\\pi}{6}\\right)";
    a[23].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[24].formula = "\\item     $$\\tg\\left(\\frac{3\\pi}{4}\\right)";
    a[24].answer = "\\item     $$-1";

    a[25].formula = "\\item     $$\\tg\\left(\\frac{2\\pi}{3}\\right)";
    a[25].answer = "\\item     $$-\\sqrt{3}";

    a[26].formula = "\\item     $$\\tg\\left(\\frac{\\pi}{3}\\right)";
    a[26].answer = "\\item     $$\\sqrt{3}";

    a[27].formula = "\\item     $$\\tg\\left(\\frac{\\pi}{4}\\right)";
    a[27].answer = "\\item     $$1";

    a[28].formula = "\\item     $$\\tg\\left(\\frac{\\pi}{6}\\right)";
    a[28].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[29].formula = "\\item     $$\\ctg\\left(-\\frac{3\\pi}{2}\\right)";                   //ctg
    a[29].answer = "\\item     $$0";

    a[30].formula = "\\item     $$\\ctg\\left(-\\frac{11\\pi}{6}\\right)";
    a[30].answer = "\\item     $$\\sqrt{3}}";

    a[31].formula = "\\item     $$\\ctg\\left(-\\frac{7\\pi}{4}\\right)";
    a[31].answer = "\\item     $$1";

    a[32].formula = "\\item     $$\\ctg\\left(-\\frac{5\\pi}{3}\\right)";
    a[32].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[33].formula = "\\item     $$\\ctg\\left(-\\frac{4\\pi}{3}\\right)";
    a[33].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[34].formula = "\\item     $$\\ctg\\left(-\\frac{5\\pi}{4}\\right)";
    a[34].answer = "\\item     $$-1"; //

    a[35].formula = "\\item     $$\\ctg\\left(-\\frac{7\\pi}{6}\\right)";
    a[35].answer = "\\item     $$-\\sqrt{3}";

    a[36].formula = "\\item     $$\\ctg\\left(-\\frac{\\pi}{2}\\right)";
    a[36].answer = "\\item     $$0";

    a[37].formula = "\\item     $$\\ctg\\left(-\\frac{5\\pi}{6}\\right)";
    a[37].answer = "\\item     $$\\sqrt{3}";

    a[38].formula = "\\item     $$\\ctg\\left(-\\frac{3\\pi}{4}\\right)";
    a[38].answer = "\\item     $$1";

    a[39].formula = "\\item     $$\\ctg\\left(-\\frac{2\\pi}{3}\\right)";
    a[39].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[40].formula = "\\item     $$\\ctg\\left(-\\frac{\\pi}{3}\\right)";
    a[40].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[41].formula = "\\item     $$\\ctg\\left(-\\frac{\\pi}{4}\\right)";
    a[41].answer = "\\item     $$-1";

    a[42].formula = "\\item     $$\\ctg\\left(-\\frac{\\pi}{6}\\right)";
    a[42].answer = "\\item     $$-\\sqrt{3}";

    a[43].formula = "\\item     $$\\ctg\\left(\\frac{\\pi}{2}\\right)";
    a[43].answer = "\\item     $$0";                                             //

    a[44].formula = "\\item     $$\\ctg\\left(\\frac{3\\pi}{2}\\right)";
    a[44].answer = "\\item     $$0";

    a[45].formula = "\\item     $$\\ctg\\left(\\frac{11\\pi}{6}\\right)";
    a[45].answer = "\\item     $$-\\sqrt{3}";

    a[46].formula = "\\item     $$\\ctg\\left(\\frac{7\\pi}{4}\\right)";
    a[46].answer = "\\item     $$-1";

    a[47].formula = "\\item     $$\\ctg\\left(\\frac{5\\pi}{3}\\right)";
    a[47].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[48].formula = "\\item     $$\\ctg\\left(\\frac{4\\pi}{3}\\right)";
    a[48].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[49].formula = "\\item     $$\\ctg\\left(\\frac{5\\pi}{4}\\right)";
    a[49].answer = "\\item     $$1"; //

    a[50].formula = "\\item     $$\\ctg\\left(\\frac{7\\pi}{6}\\right)";
    a[50].answer = "\\item     $$\\sqrt{3}";

    a[51].formula = "\\item     $$\\ctg\\left(\\frac{5\\pi}{6}\\right)";
    a[51].answer = "\\item     $$-\\sqrt{3}";

    a[52].formula = "\\item     $$\\ctg\\left(\\frac{3\\pi}{4}\\right)";
    a[52].answer = "\\item     $$-1";

    a[53].formula = "\\item     $$\\ctg\\left(\\frac{2\\pi}{3}\\right)";
    a[53].answer = "\\item     $$-\\frac{1}{\\sqrt{3}}";

    a[54].formula = "\\item     $$\\ctg\\left(\\frac{\\pi}{3}\\right)";
    a[54].answer = "\\item     $$\\frac{1}{\\sqrt{3}}";

    a[55].formula = "\\item     $$\\ctg\\left(\\frac{\\pi}{4}\\right)";
    a[55].answer = "\\item     $$1";

    a[56].formula = "\\item     $$\\ctg\\left(\\frac{\\pi}{6}\\right)";
    a[56].answer = "\\item     $$\\sqrt{3}";

    check = 1;
    do{
        unit = rand()%57;
        if(TrigonomMeanTCCHECK[unit] == 0)
        {
            TrigonomMeanTCCHECK[unit] = 1;
            check = 0;
        }
    }while(check != 0);

    cout << a[unit].formula << "= $$ \n";
    Answer =  a[unit].answer + "$$ \n";

    return Answer;
}

string Triangle()
{
    string Answer;
    Formula a[9];
    int unit, check;

    a[0].formula = "\\item     Стороны через коэффициент подобия:";
    a[0].answer = "\\item     $$\\frac{a}{a'}=\\frac{b}{b'}=\\frac{c}{c'}=k";

    a[1].formula = "\\item     Площади через коэффициент подобия:";
    a[1].answer = "\\item     $$\\frac{S}{S'}=k^2";

    a[2].formula = "\\item     Теорема синусов:";
    a[2].answer = "\\item     $$\\frac{a}{\\sin(\\alpha)}=\\frac{b}{\\sin(\\beta)}=\\frac{c}{\\sin(\\gamma)}=2R";

    a[3].formula = "\\item     Теорема Пифагора:";
    a[3].answer = "\\item     $$c^2=a^2+b^2";

    a[4].formula = "\\item     Площадь прямоугольного треугольнкиа:";
    a[4].answer = "\\item     $$S=\\frac{a\\cdot b}{2}";

    a[5].formula = "\\item     Площадь треугольника через высоту и сторону:";
    a[5].answer = "\\item     $$S=\\frac{a\\cdot h_a}{2}";

    a[6].formula = "\\item     Площадь треугольника через две стороны и угол между ними:";
    a[6].answer = "\\item     $$S=\\frac{ab\\cdot \\sin(\\alpha)}{2}";

    a[7].formula = "\\item     Площадь треугольника через радиус вписанной окружности:";
    a[7].answer = "\\item     $$S=p\\cdot r";

    a[8].formula = "\\item     Формула Герона:";
    a[8].answer = "\\item     $$S=\\sqrt{p(p-a)(p-b)(p-c)}";

    check = 1;
        do{
            unit = rand()%9;
            if(TriangleCHECK[unit] == 0)
            {
                TriangleCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Quadrangle()
{
    string Answer;
    Formula a[8];
    int unit, check;

    a[0].formula = "\\item     Площадь паралелограмма через сторону и высоту:";
    a[0].answer = "\\item     $$S=a\\cdot h_a";

    a[1].formula = "\\item     Площадь параллелограмма через две стороны и синус угла между ними:";
    a[1].answer = "\\item     $$S=ab\\cdot \\sin(\\alpha)";

    a[2].formula = "\\item     Площадь ромба через диагонали:";
    a[2].answer = "\\item     $$S=\\frac{d_1\\cdot d_2}{2}";

    a[3].formula = "\\item     Средняя линия трапеции:";
    a[3].answer = "\\item     $$MN=\\frac{a+b}{2}";

    a[4].formula = "\\item     Площадь трапеции:";
    a[4].answer = "\\item     $$S=\\frac{a+b}{2}\\cdot h";

    a[5].formula = "\\item     Условие описанного четырехугольника:";
    a[5].answer = "\\item     $$a+c=b+d";

    a[6].formula = "\\item     Условие вписанного четырехугольника:";
    a[6].answer = "\\item     $$\\angle A+\\angle C=\\angle B +\\angle D=180^{\\circ}";

    a[7].formula = "\\item     Площадь описанного четырехугольника:";
    a[7].answer = "\\item     $$S=p\\cdot r";

    check = 1;
        do{
            unit = rand()%8;
            if(QuadrangleCHECK[unit] == 0)
            {
                QuadrangleCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Circle()
{
    string Answer;
    Formula a[2];
    int unit, check;

    a[0].formula = "\\item     Длина окружности:";
    a[0].answer = "\\item     $$L=2\\pi R";

    a[1].formula = "\\item     Площадь круга:";
    a[1].answer = "\\item     $$S=\\pi R^2";

    check = 1;
        do{
            unit = rand()%2;
            if(CircleCHECK[unit] == 0)
            {
                CircleCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Vector()
{
    string Answer;
    Formula a[4];
    int unit, check;

    a[0].formula = "\\item     Длина вектора:";
    a[0].answer = "\\item     $$|\\overrightarrow{AB}|=\\sqrt{AB_x^2+AB_y^2}";

    a[1].formula = "\\item     Скалярное произведение векторов через угол:";
    a[1].answer = "\\item     $$(\\vec{a},\\vec{b})=|\\vec{a}|\\cdot|\\vec{b}|\\cdot \\cos(\\alpha)";

    a[2].formula = "\\item     Скалярное произведение векторов через координаты:";
    a[2].answer = "\\item     $$(\\vec{a},\\vec{b})=a_xb_x+a_yb_y";

    a[3].formula = "\\item     Косинус угла между векторами:";
    a[3].answer = "\\item     $$\\cos(\\alpha)=\\frac{a_xb_x+a_yb_y}{|\\vec{a}|\\cdot|\\vec{b}|}";

    check = 1;
        do{
            unit = rand()%4;
            if(VectorCHECK[unit] == 0)
            {
                VectorCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Prizma()
{
    string Answer;
    Formula a[3];
    int unit, check;

    a[0].formula = "\\item     Площадь боковой поверхности призмы:";
    a[0].answer = "\\item     $$S_{\\text{бок}}=P_{\\text{осн}}\\cdot h";

    a[1].formula = "\\item     Площадь полной поверхности призмы:";
    a[1].answer = "\\item     $$S_{\\text{пов}}=S_{\\text{бок}}+2S_{\\text{осн}}";

    a[2].formula = "\\item     Объем призмы:";
    a[2].answer = "\\item     $$V=S_{\\text{осн}}\\cdot h";

    check = 1;
        do{
            unit = rand()%3;
            if(PrizmaCHECK[unit] == 0)
            {
                PrizmaCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Piramida()
{
    string Answer;
    Formula a[3];
    int unit, check;

    a[0].formula = "\\item     Площадь боковой поверхности пирамиды:";
    a[0].answer = "\\item     $$S_{\\text{бок}}=\\frac{a\\cdot h}{2}\\cdot n";

    a[1].formula = "\\item     Площадь полной поверхности пирамиды:";
    a[1].answer = "\\item     $$S_{\\text{пол}}=\\frac{a\\cdot h}{2}\\cdot n + S_{\\text{осн}}";

    a[2].formula = "\\item     Объем пирамиды:";
    a[2].answer = "\\item     $$V=\\frac{S_{\\text{осн}}\\cdot h}{3}";

    check = 1;
        do{
            unit = rand()%3;
            if(PiramidaCHECK[unit] == 0)
            {
                PiramidaCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Cilindr()
{
    string Answer;
    Formula a[4];
    int unit, check;

    a[0].formula = "\\item     Площадь основания цилиндра:";
    a[0].answer = "\\item     $$S_{\\text{осн}}=\\pi R^2";

    a[1].formula = "\\item     Площадь боковой поверхности цилиндра:";
    a[1].answer = "\\item     $$S_{\\text{бок}}=2\\pi Rh";

    a[2].formula = "\\item     Площадь полной поверхности цилиндра:";
    a[2].answer = "\\item     $$S_{\\text{полн}}=2\\pi R(R+h)";

    a[3].formula = "\\item     Объем цилиндра:";
    a[3].answer = "\\item     $$V=\\pi R^2h";

    check = 1;
        do{
            unit = rand()%4;
            if(CilindrCHECK[unit] == 0)
            {
                CilindrCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Konus()
{
    string Answer;
    Formula a[4];
    int unit, check;

    a[0].formula = "\\item     Площадь основания конуса:";
    a[0].answer = "\\item     $$S_{\\text{осн}}=\\pi R^2";

    a[1].formula = "\\item     Площадь боковой поверхности конуса:";
    a[1].answer = "\\item     $$S_{\\text{бок}}=\\pi Rl";

    a[2].formula = "\\item     Площадь полной поверхности конуса:";
    a[2].answer = "\\item     $$S_{\\text{полн}}=\\pi R(R+l)";

    a[3].formula = "\\item     Объем конуса:";
    a[3].answer = "\\item     $$V=\\frac{\\pi R^2h}{3}";

    check = 1;
        do{
            unit = rand()%4;
            if(KonusCHECK[unit] == 0)
            {
                KonusCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Ball()
{
    string Answer;
    Formula a[2];
    int unit, check;

    a[0].formula = "\\item     Площадь полной поверхности шара:";
    a[0].answer = "\\item     $$S_{\\text{полн}}=4\\pi R^2";

    a[1].formula = "\\item     Объем шара:";
    a[1].answer = "\\item     $$V=\\frac{4}{3}\\pi R^3";

    check = 1;
        do{
            unit = rand()%2;
            if(BallCHECK[unit] == 0)
            {
                BallCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string Podob()
{
    string Answer;
    Formula a[3];
    int unit, check;

    a[0].formula = "\\item     Стороны подобных фигур:";
    a[0].answer = "\\item     $$\\frac{a}{a'}=k";

    a[1].formula = "\\item     Площади подобных фигур:";
    a[1].answer = "\\item     $$\\frac{S}{S'}=k^2";

    a[2].formula = "\\item     Объемы подобных фигур:";
    a[2].answer = "\\item     $$\\frac{V}{V'}=k^3";

    check = 1;
        do{
            unit = rand()%3;
            if(PodobCHECK[unit] == 0)
            {
                PodobCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string ArifmetProg()
{
    string Answer;
    Formula a[2];
    int unit, check;

    a[0].formula = "\\item     Формула n-го члена арифметической прогрессии:";
    a[0].answer = "\\item     $$a_{n}=a_1+d\\cdot(n-1)";

    a[1].formula = "\\item     Формула суммы первых n членов арифметической прогрессии:";
    a[1].answer = "\\item     $$S_n=\\frac{a_1+a_n}{2}\\cdot n";

    check = 1;
        do{
            unit = rand()%2;
            if(ArifmetProgCHECK[unit] == 0)
            {
                ArifmetProgCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string GeometrProg()
{
    string Answer;
    Formula a[2];
    int unit, check;

    a[0].formula = "\\item     Формула n-го члена геометрической прогрессии:";
    a[0].answer = "\\item     $$b_n = b_1\\cdot q^{n-1}";

    a[1].formula = "\\item     Формула суммы первых n членов геометрической прогрессии:";
    a[1].answer = "\\item     $$S_n=b_1\\cdot \\frac{q^n-1}{q-1}";

    check = 1;
        do{
            unit = rand()%2;
            if(GeometrProgCHECK[unit] == 0)
            {
                GeometrProgCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << " \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string ProizvodnMain()
{
    string Answer;
    Formula a[8];
    int unit, check;

    a[0].formula = "\\item     $$\\left(C\\right)'";
    a[0].answer = "\\item     $$0";

    a[1].formula = "\\item     $$\\left(x^n\\right)'";
    a[1].answer = "\\item     $$n\\cdot x^{n-1}";

    a[2].formula = "\\item     $$\\left(x^{\\frac{3}{2}}\\right)'";
    a[2].answer = "\\item     $$\\frac{3}{2}\\sqrt{x}";

    a[3].formula = "\\item     $$\\left(x\\sqrt{x}\\right)'";
    a[3].answer = "\\item     $$\\frac{3}{2}\\sqrt{x}";

    a[4].formula = "\\item     $$\\left(\\sin(x)\\right)'";
    a[4].answer = "\\item     $$\\cos(x)";

    a[5].formula = "\\item     $$\\left(\\cos(x)\\right)'";
    a[5].answer = "\\item     $$-\\sin(x)";

    a[6].formula = "\\item     $$\\left(e^u\\right)'";
    a[6].answer = "\\item     $$e^u\\cdot u'";

    a[7].formula = "\\item     $$\\left(\\ln(u)\\right)'";
    a[7].answer = "\\item     $$\\frac{1}{u}\\cdot u'";

    check = 1;
        do{
            unit = rand()%8;
            if(ProizvodnMainCHECK[unit] == 0)
            {
                ProizvodnMainCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << "= $$ \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

string ProizvodnArifm()
{
    string Answer;
    Formula a[3];
    int unit, check;

    a[0].formula = "\\item     $$(f(x)\\pm g(x))'";
    a[0].answer = "\\item     $$f'(x)\\pm g'(x)";

    a[1].formula = "\\item     $$(f(x)\\cdot g(x))'";
    a[1].answer = "\\item     $$f'(x)\\cdot g(x) +g'(x)\\cdot f(x)";

    a[2].formula = "\\item     $$\\left(\\frac{f(x)}{g(x)}\\right)'";
    a[2].answer = "\\item     $$\\frac{f'(x)\\cdot g(x) -g'(x)\\cdot f(x)}{g^2(x)}";


    check = 1;
        do{
            unit = rand()%3;
            if(ProizvodnArifmCHECK[unit] == 0)
            {
                ProizvodnArifmCHECK[unit] = 1;
                check = 0;
            }
        }while(check != 0);
        cout << a[unit].formula << "= $$ \n";
        Answer =  a[unit].answer + "$$ \n";
    return Answer;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int count_task[70];              // Создает массив из номеров заданий
    for (int i = 0; i < 70; i++)     // Обнуляет количество заданий в номерах
        count_task[i] = 0;
    int choice = 0;
    string Answers = "";
    do{
        choice = main_menu();
        switch(choice)
        {
            case(1):
            {
                do{
                    cout << "\033[2J\033[1;1H";
                    cout << "Выберите темы:" << endl;
                    cout << "1. Алгебраические выражения (" << count_task[0] + count_task[1] + count_task[2] + count_task[3] + count_task[4] + count_task[5] + count_task[6] + count_task[7] + count_task[8] + count_task[9] << ")" << endl;
                    cout << "2. Тригонометрия (" << count_task[10] + count_task[11] + count_task[12] + count_task[13] + count_task[14] + count_task[15] << ")" << endl;
                    cout << "3. Планиметрия (" << count_task[16] + count_task[17] + count_task[18] + count_task[19] + count_task[20] + count_task[21] + count_task[22] + count_task[23] + count_task[24] + count_task[25] << ")" << endl;
                    cout << "4. Стереометрия (" << count_task[26] + count_task[27] + count_task[28] + count_task[29] + count_task[30] + count_task[31] + count_task[32] + count_task[33] << ")" << endl;
                    cout << "5. Прогрессии (" << count_task[34] + count_task[35] + count_task[36] << ")" << endl;
                    cout << "6. Производные (" << count_task[37] + count_task[38] + count_task[39] << ")" << endl;
                    cout << endl << "69. Сгенерировать" << endl;
                    cout << "0. Выход" << endl;
                    cout << "Ваш выбор: ";
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Разложение на множители и ФСУ   (" << count_task[0] + count_task[1] << ")" << endl;
                            cout << "2. Степени   (" << count_task[2] + count_task[3] << ")" << endl;
                            cout << "3. Корни   (" << count_task[4] + count_task[5] << ")" << endl;
                            cout << "4. Логарифмы   (" << count_task[6] + count_task[7] << ")" << endl;
                            cout << "5. Весь раздел   (" << count_task[8] + count_task[9] << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[0] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[1] << ")" << endl;
                                    cout << endl << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[0];
                                            break;

                                        case 2:
                                            count_task[1] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 2:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[2] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[3] << ")" << endl;
                                    cout << endl << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[2];
                                            break;

                                        case 2:
                                            count_task[3] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 3:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[4] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[5] << ")" << endl;
                                    cout << endl << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[4];
                                            break;

                                        case 2:
                                            count_task[5] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 4:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[6] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[7] << ")" << endl;
                                    cout << endl << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[6];
                                            break;

                                        case 2:
                                            count_task[7] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 5:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[8] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[9] << ")" << endl;
                                    cout << endl << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[8];
                                            break;

                                        case 2:
                                            count_task[9] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;

                        case 2:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Базовые   (" << count_task[10] << ")" << endl;
                            cout << "2. Формулы   (" << count_task[11] + count_task[12] << ")" << endl;
                            cout << "3. Тригонометрические значения sin(a), cos(a)  (" << count_task[13] << ")" << endl;
                            cout << "4. Тригонометрические значения tg(a), ctg(a)  (" << count_task[14] << ")" << endl;
                            cout << "5. Весь раздел   (" << count_task[15] << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                    count_task[10] = 1;
                                    break;

                                case 2:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[11] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[12] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[11];
                                                break;

                                            case 2:
                                                count_task[12] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;

                                case 3:
                                    cout << "\033[2J\033[1;1H";
                                    cout << "Введите количество формул: ";
                                    cin >> count_task[13];
                                    break;

                                case 4:
                                    cout << "\033[2J\033[1;1H";
                                    cout << "Введите количество формул: ";
                                    cin >> count_task[14];
                                    break;

                                case 5:
                                    cout << "\033[2J\033[1;1H";
                                    cout << "Введите количество формул: ";
                                    cin >> count_task[15];
                                    break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;

                        case 3:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Треугольники   (" << count_task[16] + count_task[17] << ")" << endl;
                            cout << "2. Четырехугольники   (" << count_task[18] + count_task[19] << ")" << endl;
                            cout << "3. Окружности  (" << count_task[20] + count_task[21] << ")" << endl;
                            cout << "4. Векторы  (" << count_task[22] + count_task[23] << ")" << endl;
                            cout << "5. Весь раздел   (" << count_task[24] + count_task[25] << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[16] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[17] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[16];
                                                break;

                                            case 2:
                                                count_task[17] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;

                                case 2:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[18] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[19] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[18];
                                                break;

                                            case 2:
                                                count_task[19] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;

                                case 3:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[20] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[21] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[20];
                                                break;

                                            case 2:
                                                count_task[21] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;

                                case 4:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[22] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[23] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[22];
                                                break;

                                            case 2:
                                                count_task[23] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;

                                case 5:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[24] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[25] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[24];
                                                break;

                                            case 2:
                                                count_task[25] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;
                        
                        case 4:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Призма   (" << count_task[26] << ")" << endl;
                            cout << "2. Пирамида   (" << count_task[27] << ")" << endl;
                            cout << "3. Цилиндр  (" << count_task[28]  << ")" << endl;
                            cout << "4. Конус  (" << count_task[29] << ")" << endl;
                            cout << "5. Шар  (" << count_task[30] << ")" << endl;
                            cout << "6. Подобные фигуры  (" << count_task[31]  << ")" << endl;
                            cout << "7. Весь раздел   (" << count_task[32] + count_task[33] << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                    count_task[26] = 1;
                                    break;

                                case 2:
                                    count_task[27] = 1;
                                    break;

                                case 3:
                                    count_task[28] = 1;
                                    break;

                                case 4:
                                    count_task[29] = 1;
                                    break;

                                case 5:
                                    count_task[30] = 1;
                                    break;

                                case 6:
                                    count_task[31] = 1;
                                    break;

                                case 7:
                                    do{
                                        cout << "\033[2J\033[1;1H";
                                        cout << "1. Произвольное количество   (" << count_task[32] << ")" << endl;
                                        cout << "2. Все целиком   (" << count_task[33] << ")" << endl;
                                        cout << endl << "0. Выход" << endl;
                                        cout << "Ваш выбор: ";
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "\033[2J\033[1;1H";
                                                cout << "Введите количество формул: ";
                                                cin >> count_task[32];
                                                break;

                                            case 2:
                                                count_task[33] = 1;
                                                break;
                                        }
                                    }while(choice != 0);
                                    choice = -1;
                                    break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;

                        case 5:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Арифметическая прогрессия   (" << count_task[34] << ")" << endl;
                            cout << "2. Геометрическая прогрессия   (" << count_task[35] << ")" << endl;
                            cout << "3. Весь раздел  (" << count_task[36]  << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                    count_task[34] = 1;
                                    break;

                                case 2:
                                    count_task[35] = 1;
                                    break;

                                case 3:
                                    count_task[36] = 1;
                                    break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;

                        case 6:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Производные основных функций   (" << count_task[37] << ")" << endl;
                            cout << "2. Производная и арифметические действия   (" << count_task[38] << ")" << endl;
                            cout << "3. Весь раздел  (" << count_task[39]  << ")" << endl;
                            cout << endl << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                    count_task[37] = 1;
                                    break;

                                case 2:
                                    count_task[38] = 1;
                                    break;

                                case 3:
                                    count_task[39] = 1;
                                    break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;

                        case 69:
                        cout << "\033[2J\033[1;1H";
                        int Count = 0;
                        for(int i = 0; i < 66; i++)
                        {
                            TrigonomMeanSCCHECK[i] = 0;
                        }
                        for(int i = 0; i < 57; i++)
                        {
                            TrigonomMeanTCCHECK[i] = 0;
                        }
                        if(count_task[0] != 0)
                        {
                            count_task[0] = Min(count_task[0], 8);
                            for(int i = 0; i < count_task[0]; i++)
                            {
                                Answers = Answers + AlgebraicExpression();
                                Count++;
                            }
                            count_task[0] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                AlgebraicExpressionCHECK[i] = 0;
                            }
                        }
                        if(count_task[1] != 0)
                        {
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + AlgebraicExpression();
                                Count++;
                            }
                            count_task[1] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                AlgebraicExpressionCHECK[i] = 0;
                            }
                        }
                        if(count_task[2] != 0)
                        {
                            count_task[2] = Min(count_task[2], 7);
                            for(int i = 0; i < count_task[2]; i++)
                            {
                                Answers = Answers + Degree();
                                Count++;
                            }
                            count_task[2] = 0;
                            for(int i = 0; i < 7; i++)
                            {
                                DegreeCHECK[i] = 0;
                            }
                        }
                        if(count_task[3] != 0)
                        {
                            for(int i = 0; i < 7; i++)
                            {
                                Answers = Answers + Degree();
                                Count++;
                            }
                            count_task[3] = 0;
                            for(int i = 0; i < 7; i++)
                            {
                                DegreeCHECK[i] = 0;
                            }
                        }
                        if(count_task[4] != 0)
                        {
                            count_task[4] = Min(count_task[4], 8);
                            for(int i = 0; i < count_task[4]; i++)
                            {
                                Answers = Answers + SquareRoot();
                                Count++;
                            }
                            count_task[4] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                SquareRootCHECK[i] = 0;
                            }
                        }
                        if(count_task[5] != 0)
                        {
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + SquareRoot();
                                Count++;
                            }
                            count_task[5] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                SquareRootCHECK[i] = 0;
                            }
                        }
                        if(count_task[6] != 0)
                        {
                            count_task[6] = Min(count_task[6], 11);
                            for(int i = 0; i < count_task[6]; i++)
                            {
                                Answers = Answers + Logarithms();
                                Count++;
                            }
                            count_task[6] = 0;
                            for(int i = 0; i < 11; i++)
                            {
                                LogarithmsCHECK[i] = 0;
                            }
                        }
                        if(count_task[7] != 0)
                        {
                            for(int i = 0; i < 11; i++)
                            {
                                Answers = Answers + Logarithms();
                                Count++;
                            }
                            count_task[7] = 0;
                            for(int i = 0; i < 11; i++)
                            {
                                LogarithmsCHECK[i] = 0;
                            }
                        }
                        if(count_task[8] != 0)
                        {
                            count_task[8] = Min(count_task[8], 34);
                            for(int i = 0; i < count_task[8]; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%4;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 8; k++)
                                            {
                                                if(AlgebraicExpressionCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 8)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 7; k++)
                                            {
                                                if(DegreeCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 7)
                                                check = 0;
                                            break;
                                        case 2:
                                            for(int k = 0; k < 8; k++)
                                            {
                                                if(SquareRootCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 8)
                                                check = 0;
                                            break;
                                        case 3:
                                            for(int k = 0; k < 11; k++)
                                            {
                                                if(LogarithmsCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 11)
                                                check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + AlgebraicExpression();
                                        break;
                                    case 1:
                                        Answers = Answers + Degree();
                                        break;
                                    case 2:
                                        Answers = Answers + SquareRoot();
                                        break;
                                    case 3:
                                        Answers = Answers + Logarithms();
                                        break;
                                }
                            }
                            count_task[8] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                AlgebraicExpressionCHECK[i] = 0;
                            }
                            for(int i = 0; i < 7; i++)
                            {
                                DegreeCHECK[i] = 0;
                            }
                            for(int i = 0; i < 8; i++)
                            {
                                SquareRootCHECK[i] = 0;
                            }
                            for(int i = 0; i < 11; i++)
                            {
                                LogarithmsCHECK[i] = 0;
                            }
                        }
                        if(count_task[9] != 0)
                        {
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + AlgebraicExpression();
                                Count++;
                            }
                            for(int i = 0; i < 7; i++)
                            {
                                Answers = Answers + Degree();
                                Count++;
                            }
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + SquareRoot();
                                Count++;
                            }
                            for(int i = 0; i < 11; i++)
                            {
                                Answers = Answers + Logarithms();
                                Count++;
                            }
                            for(int i = 0; i<10; i++)
                                count_task[i] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                AlgebraicExpressionCHECK[i] = 0;
                            }
                            for(int i = 0; i < 7; i++)
                            {
                                DegreeCHECK[i] = 0;
                            }
                            for(int i = 0; i < 8; i++)
                            {
                                SquareRootCHECK[i] = 0;
                            }
                            for(int i = 0; i < 11; i++)
                            {
                                LogarithmsCHECK[i] = 0;
                            }
                        }
                        if(count_task[10] != 0)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                Answers = Answers + TrigonomBase();
                                Count++;
                            }
                            count_task[10] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                TrigonomBaseCHECK[i] = 0;
                            }
                        }
                        if(count_task[11] != 0)
                        {
                            count_task[11] = Min(count_task[11], 7);
                            for(int i = 0; i < count_task[11]; i++)
                            {
                                Answers = Answers + TrigonomFormul();
                                Count++;
                            }
                            count_task[11] = 0;
                            for(int i = 0; i < 7; i++)
                            {
                                TrigonomFormulCHECK[i] = 0;
                            }
                        }
                        if(count_task[12] != 0)
                        {
                            for(int i = 0; i < 7; i++)
                            {
                                Answers = Answers + TrigonomFormul();
                                Count++;
                            }
                            count_task[12] = 0;
                            for(int i = 0; i < 7; i++)
                            {
                                TrigonomFormulCHECK[i] = 0;
                            }
                        }
                        if(count_task[13] != 0)
                        {
                            count_task[13] = Min(count_task[13], 66);
                            for(int i = 0; i < count_task[13]; i++)
                            {
                                Answers = Answers + TrigonomMeanSC();
                                Count++;
                            }
                            count_task[13] = 0;
                            for(int i = 0; i < 66; i++)
                            {
                                TrigonomMeanSCCHECK[i] = 0;
                            }
                        }
                        if(count_task[14] != 0)
                        {
                            count_task[14] = Min(count_task[14], 57);
                            for(int i = 0; i < count_task[14]; i++)
                            {
                                Answers = Answers + TrigonomMeanTC();
                                Count++;
                            }
                            count_task[14] = 0;
                            for(int i = 0; i < 57; i++)
                            {
                                TrigonomMeanTCCHECK[i] = 0;
                            }
                        }
                        if(count_task[15] != 0)
                        {
                            for(int i = 0; i < count_task[15]; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%3;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(TrigonomBaseCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 7; k++)
                                            {
                                                if(TrigonomFormulCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 7)
                                                check = 0;
                                            break;
                                        case 2:
                                            check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + TrigonomBase();
                                        break;
                                    case 1:
                                        Answers = Answers + TrigonomFormul();
                                        break;
                                    case 2:
                                        if(rand()%2 == 0)
                                            Answers = Answers + TrigonomMeanSC();
                                        else
                                            Answers = Answers + TrigonomMeanTC();
                                        break;
                                }
                            }
                            count_task[15] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                TrigonomBaseCHECK[i] = 0;
                            }
                            for(int i = 0; i < 7; i++)
                            {
                                TrigonomFormulCHECK[i] = 0;
                            }
                            for(int i = 0; i < 66; i++)
                            {
                                TrigonomMeanSCCHECK[i] = 0;
                            }
                            for(int i = 0; i < 57; i++)
                            {
                                TrigonomMeanTCCHECK[i] = 0;
                            }
                        }
                        if(count_task[16] != 0)
                        {
                            count_task[16] = Min(count_task[16], 9);
                            for(int i = 0; i < count_task[16]; i++)
                            {
                                Answers = Answers + Triangle();
                                Count++;
                            }
                            count_task[16] = 0;
                            for(int i = 0; i < 9; i++)
                            {
                                TriangleCHECK[i] = 0;
                            }
                        }
                        if(count_task[17] != 0)
                        {
                            for(int i = 0; i < 9; i++)
                            {
                                Answers = Answers + Triangle();
                                Count++;
                            }
                            count_task[17] = 0;
                            for(int i = 0; i < 9; i++)
                            {
                                TriangleCHECK[i] = 0;
                            }
                        }
                        if(count_task[18] != 0)
                        {
                            count_task[18] = Min(count_task[18], 8);
                            for(int i = 0; i < count_task[18]; i++)
                            {
                                Answers = Answers + Quadrangle();
                                Count++;
                            }
                            count_task[18] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                QuadrangleCHECK[i] = 0;
                            }
                        }
                        if(count_task[19] != 0)
                        {
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + Quadrangle();
                                Count++;
                            }
                            count_task[19] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                QuadrangleCHECK[i] = 0;
                            }
                        }
                        if(count_task[20] != 0)
                        {
                            count_task[20] = Min(count_task[20], 2);
                            for(int i = 0; i < count_task[20]; i++)
                            {
                                Answers = Answers + Circle();
                                Count++;
                            }
                            count_task[20] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                CircleCHECK[i] = 0;
                            }
                        }
                        if(count_task[21] != 0)
                        {
                            for(int i = 0; i < 2; i++)
                            {
                                Answers = Answers + Circle();
                                Count++;
                            }
                            count_task[21] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                CircleCHECK[i] = 0;
                            }
                        }
                        if(count_task[22] != 0)
                        {
                            count_task[22] = Min(count_task[22], 4);
                            for(int i = 0; i < count_task[22]; i++)
                            {
                                Answers = Answers + Vector();
                                Count++;
                            }
                            count_task[22] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                VectorCHECK[i] = 0;
                            }
                        }
                        if(count_task[23] != 0)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                Answers = Answers + Vector();
                                Count++;
                            }
                            count_task[23] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                VectorCHECK[i] = 0;
                            }
                        }
                        if(count_task[24] != 0)
                        {
                            count_task[24] = Min(count_task[24], 23);
                            for(int i = 0; i < count_task[24]; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%4;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 9; k++)
                                            {
                                                if(TriangleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 9)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 8; k++)
                                            {
                                                if(QuadrangleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 8)
                                                check = 0;
                                            break;
                                        case 2:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(CircleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        case 3:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(VectorCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + Triangle();
                                        break;
                                    case 1:
                                        Answers = Answers + Quadrangle();
                                        break;
                                    case 2:
                                        Answers = Answers + Circle();
                                        break;
                                    case 3:
                                        Answers = Answers + Vector();
                                        break;
                                }
                            }
                            count_task[24] = 0;
                            for(int i = 0; i < 9; i++)
                            {
                                TriangleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 8; i++)
                            {
                                QuadrangleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 2; i++)
                            {
                                CircleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                VectorCHECK[i] = 0;
                            }
                        }
                        if(count_task[25] != 0)
                        {
                            for(int i = 0; i < 23; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%4;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 9; k++)
                                            {
                                                if(TriangleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 9)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 8; k++)
                                            {
                                                if(QuadrangleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 8)
                                                check = 0;
                                            break;
                                        case 2:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(CircleCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        case 3:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(VectorCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + Triangle();
                                        break;
                                    case 1:
                                        Answers = Answers + Quadrangle();
                                        break;
                                    case 2:
                                        Answers = Answers + Circle();
                                        break;
                                    case 3:
                                        Answers = Answers + Vector();
                                        break;
                                }
                            }
                            count_task[25] = 0;
                            for(int i = 0; i < 9; i++)
                            {
                                TriangleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 8; i++)
                            {
                                QuadrangleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 2; i++)
                            {
                                CircleCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                VectorCHECK[i] = 0;
                            }
                        }
                        if(count_task[26] != 0)
                        {
                            for(int i = 0; i < 3; i++)
                            {
                                Answers = Answers + Prizma();
                                Count++;
                            }
                            count_task[26] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                PrizmaCHECK[i] = 0;
                            }
                        }
                        if(count_task[27] != 0)
                        {
                            for(int i = 0; i < 3; i++)
                            {
                                Answers = Answers + Piramida();
                                Count++;
                            }
                            count_task[27] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                PiramidaCHECK[i] = 0;
                            }
                        }
                        if(count_task[28] != 0)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                Answers = Answers + Cilindr();
                                Count++;
                            }
                            count_task[28] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                CilindrCHECK[i] = 0;
                            }
                        }
                        if(count_task[29] != 0)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                Answers = Answers + Konus();
                                Count++;
                            }
                            count_task[29] = 0;
                            for(int i = 0; i < 4; i++)
                            {
                                KonusCHECK[i] = 0;
                            }
                        }
                        if(count_task[30] != 0)
                        {
                            for(int i = 0; i < 2; i++)
                            {
                                Answers = Answers + Ball();
                                Count++;
                            }
                            count_task[30] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                BallCHECK[i] = 0;
                            }
                        }
                        if(count_task[31] != 0)
                        {
                            for(int i = 0; i < 3; i++)
                            {
                                Answers = Answers + Podob();
                                Count++;
                            }
                            count_task[31] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                PodobCHECK[i] = 0;
                            }
                        }
                        if(count_task[32] != 0)
                        {
                            count_task[32] = Min(count_task[32], 19);
                            for(int i = 0; i < count_task[32]; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%6;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PrizmaCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PiramidaCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                        case 2:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(CilindrCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;
                                        case 3:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(KonusCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;

                                        case 4:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(BallCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        case 5:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PodobCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + Prizma();
                                        break;
                                    case 1:
                                        Answers = Answers + Piramida();
                                        break;
                                    case 2:
                                        Answers = Answers + Cilindr();
                                        break;
                                    case 3:
                                        Answers = Answers + Konus();
                                        break;
                                    case 4:
                                        Answers = Answers + Ball();
                                        break;
                                    case 5:
                                        Answers = Answers + Podob();
                                        break;
                                }
                            }
                            count_task[32] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                PrizmaCHECK[i] = 0;
                            }
                            for(int i = 0; i < 3; i++)
                            {
                                PiramidaCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                CilindrCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                KonusCHECK[i] = 0;
                            }
                            for(int i = 0; i < 2; i++)
                            {
                                BallCHECK[i] = 0;
                            }
                            for(int i = 0; i < 3; i++)
                            {
                                PodobCHECK[i] = 0;
                            }
                        }
                        if(count_task[33] != 0)
                        {
                            for(int i = 0; i < 19; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%6;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PrizmaCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PiramidaCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                        case 2:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(CilindrCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;
                                        case 3:
                                            for(int k = 0; k < 4; k++)
                                            {
                                                if(KonusCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 4)
                                                check = 0;
                                            break;

                                        case 4:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(BallCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        case 5:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(PodobCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + Prizma();
                                        break;
                                    case 1:
                                        Answers = Answers + Piramida();
                                        break;
                                    case 2:
                                        Answers = Answers + Cilindr();
                                        break;
                                    case 3:
                                        Answers = Answers + Konus();
                                        break;
                                    case 4:
                                        Answers = Answers + Ball();
                                        break;
                                    case 5:
                                        Answers = Answers + Podob();
                                        break;
                                }
                            }
                            count_task[33] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                PrizmaCHECK[i] = 0;
                            }
                            for(int i = 0; i < 3; i++)
                            {
                                PiramidaCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                CilindrCHECK[i] = 0;
                            }
                            for(int i = 0; i < 4; i++)
                            {
                                KonusCHECK[i] = 0;
                            }
                            for(int i = 0; i < 2; i++)
                            {
                                BallCHECK[i] = 0;
                            }
                            for(int i = 0; i < 3; i++)
                            {
                                PodobCHECK[i] = 0;
                            }
                        }
                        if(count_task[34] != 0)
                        {
                            for(int i = 0; i < 2; i++)
                            {
                                Answers = Answers + ArifmetProg();
                                Count++;
                            }
                            count_task[34] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                ArifmetProgCHECK[i] = 0;
                            }
                        }
                        if(count_task[35] != 0)
                        {
                            for(int i = 0; i < 2; i++)
                            {
                                Answers = Answers + GeometrProg();
                                Count++;
                            }
                            count_task[35] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                GeometrProgCHECK[i] = 0;
                            }
                        }
                        if(count_task[36] != 0)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%2;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(ArifmetProgCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 2; k++)
                                            {
                                                if(GeometrProgCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 2)
                                                check = 0;
                                            break;
                                        
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + ArifmetProg();
                                        break;
                                    case 1:
                                        Answers = Answers + GeometrProg();
                                        break;
                                    
                                }
                            }
                            count_task[36] = 0;
                            for(int i = 0; i < 2; i++)
                            {
                                ArifmetProgCHECK[i] = 0;
                            }
                            for(int i = 0; i < 2; i++)
                            {
                                GeometrProgCHECK[i] = 0;
                            }
                        }
                        if(count_task[37] != 0)
                        {
                            for(int i = 0; i < 8; i++)
                            {
                                Answers = Answers + ProizvodnMain();
                                Count++;
                            }
                            count_task[37] = 0;
                            for(int i = 0; i < 8; i++)
                            {
                                ProizvodnMainCHECK[i] = 0;
                            }
                        }
                        if(count_task[38] != 0)
                        {
                            for(int i = 0; i < 3; i++)
                            {
                                Answers = Answers + ProizvodnArifm();
                                Count++;
                            }
                            count_task[38] = 0;
                            for(int i = 0; i < 3; i++)
                            {
                                ProizvodnArifmCHECK[i] = 0;
                            }
                        }
                        if(count_task[39] != 0)
                        {
                            for(int i = 0; i < 11; i++)
                            {
                                int type;
                                int check;
                                do{
                                    type = rand()%2;
                                    check = 0;
                                    switch(type)
                                    {
                                        case 0:
                                            for(int k = 0; k < 8; k++)
                                            {
                                                if(ProizvodnMainCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 8)
                                                check = 0;
                                            break;
                                        case 1:
                                            for(int k = 0; k < 3; k++)
                                            {
                                                if(ProizvodnArifmCHECK[k] == 1)
                                                    check++;
                                            }
                                            if(check != 3)
                                                check = 0;
                                            break;
                                        
                                    }
                                }while(check != 0);
                                switch(type)
                                {
                                    case 0:
                                        Answers = Answers + ProizvodnMain();
                                        break;
                                    case 1:
                                        Answers = Answers + ProizvodnArifm();
                                        break;
                                    
                                }
                            }
                        }
                        cout << endl << "}" << endl << "\\end{enumerate}" << endl << "\\newpage \n {\\centering \\subsubsection*{Ответы}} \n \\begin{enumerate} \n" << Answers << endl << "\\end{enumerate}" << endl << endl;
                        Answers = "";
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        choice = -1;
                        break;
                    }
                }while(choice != 0);
                choice = -1;
                break;
            }
        }
    }while(choice != 0);
    return 0;
}