//Description this task found under READ ME
#include<iostream>
using namespace std;
class Drinc
{
	double a,b;                     //ингридиенты
	double x, y, w, r,max_pr;   //переменные "прибыль"
	double t, f,k,l;                 //ингридиенты при смешивании
	double determinate, determinate_x, determinate_y;
public:
	Drinc(){}
	void set_value(double val_a,double val_b);
	void set_profit(double val_w, double val_r);
	void set_ingridient_A(double val_t,double val_f);
	void set_ingridient_B(double val_k, double val_l);
	void show_equation();
	void equil();
	double set_x_y_max_profit();
	void show_max_profit();
};
int main(int argc, char*argv[])
{
	Drinc ob;
	cout << "You have two types of product A  and B which prepared by mixed the two ingridients\n";
	cout << "Set quantity ingridients please\n";
	ob.set_value(0,0);
	cout << "Set your profits on the sale product A and B\n";
	ob.set_profit(0,0);
	cout << "What  quantity ingridients needs by mixed that get product A\n";
	ob.set_ingridient_A(0,0);
	cout << "What quantity ingridiets needs by mixed that get product B\n";
	ob.set_ingridient_B(0, 0);
	cout << "This task is sloved by a system of linear equations which has the form\n";
	ob.show_equation();
	ob.equil();
	cout << "The unknown quatities x and y\n";
	ob.set_x_y_max_profit();
	ob.show_max_profit();
	return 0;
}

void Drinc::set_value(double val_a,double val_b)
{
	cin >> val_a;
	cin >> val_b;
	a = val_a;
	b = val_b;
}

void Drinc::set_profit(double val_w, double val_r)
{
	cin >> val_w;
	cin >> val_r;
	w = val_w;
	r = val_r;
}

void Drinc::set_ingridient_A(double val_t,double val_f)
{
	cin >> val_t;
	cin >> val_f;
	t = val_t;
	f = val_f;
}

void Drinc::set_ingridient_B(double val_k, double val_l)
{
	cin >> val_k;
	cin >> val_l;
	k = val_k;
	l = val_l;
}

void Drinc::show_equation()
{
	cout<< a<<" >= ("<<t<<"*x) + ("<<k<<"*y)\n";
	cout<< b<<" >= ("<<f<<"*x) + ("<<l<<"*y)\n";
}

void Drinc::equil()
{
	const int row = 2, col = 2;
	double mtx[row][col] = { {t,k},       //вычисляем главный определитель
			    		     {t,l} };
    determinate = (t*l) - (k*f);

	double mtx_x[row][col] = { {a,k},   //вычисляем определитель_х
							   {b,l} };
	 determinate_x = (a * l) - (b * k);

	double mtx_y[row][col] = { {t,a},        //вычисляем определитель_y
	                           {f,b} };
	 determinate_y = (t*b) - (f*a);	
}

double Drinc::set_x_y_max_profit()
{
    double x=0, y=0;
	x = determinate_x / determinate;               //находим х
	y = determinate_y / determinate;               //находим y
	cout << "x= " << x << "    " << "y= " << y<<"\n";
	max_pr = w*x + r*y;                            //максимальная прибыль
	return max_pr;
}
void Drinc::show_max_profit()
{
	cout << "Your maximum profit has expression\n";
	cout << w << "*x + " << r << "*y = "<<max_pr<<endl;
}


