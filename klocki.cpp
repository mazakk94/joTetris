#include "procedurki.h"
#include <GL/freeglut.h>

void kwadrat(double xx, double yy, double y2)
{
	int i = 1;
	if (y2 == -40)
		i++;

	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 2, y2 + 0);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 0);

		rysuj_kwadrat(Square, xx + 2, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
	}
	else{
		rysuj_kwadrat(Square, xx + 2, yy + 0, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
	}

}

void prawoskretny(double xx, double yy, double y2)
{
	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 4, i);
	}
}

void prawoskretny2(double xx, double yy, double y2)
{
	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 2, y2 + 0);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 4, y2 + 0);

		rysuj_kwadrat(Square, xx + 2, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 4, yy + 0, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 2, yy + 0, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 4, yy + 0, i);
	}
}


void lewoskretny(double xx, double yy, double y2)
{
	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + -2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + -2, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + -2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + -2, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx - 2, yy + 4, i);
	}
}

void lewoskretny2(double xx, double yy, double y2)
{
	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx - 4, y2);
		rysuj_kontur(Square, xx - 2, y2);

		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx - 4, yy + 0, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 0, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx - 4, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 0, i);
	}
}

void dlugas(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);
		rysuj_kontur(Square, xx + 0, y2 + 6);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 6, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
		rysuj_kwadrat(Square, xx + 0, yy + 6, i);
	}
}

void dlugas2(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 1 * 2, y2 + 2);
		rysuj_kontur(Square, xx + 1 * 4, y2 + 2);
		rysuj_kontur(Square, xx + -2, y2 + 2);

		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 1 * 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 1 * 4, yy + 2, 0);
		rysuj_kwadrat(Square, xx + -2, yy + 2, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 4, yy + 2, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
	}
}

void trzyprawy(double xx, double yy, double y2)
{


	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);
		rysuj_kontur(Square, xx + 2, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
		rysuj_kwadrat(Square, xx + 2, yy + 4, i);
	}
}

void trzyprawy1(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 0);

		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 0, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 0, i);
	}
}

void trzyprawy2(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx - 2, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
	}

}

void trzyprawy3(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx - 2, y2 + 4);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);

		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 4, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx - 2, yy + 4, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
	}
}
void trzylewy(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);
		rysuj_kontur(Square, xx - 2, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
		rysuj_kwadrat(Square, xx - 2, yy + 4, i);
	}
}
void trzylewy1(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 4);

		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 4, i);
	}
}
void trzylewy2(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 2, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 2, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
	}
}
void trzylewy3(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx - 2, y2 + 0);
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);

		rysuj_kwadrat(Square, xx - 2, yy + 0, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx - 2, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
	}
}

void uniwersal(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40)
	{
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
	}
}

void uniwersal1(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
	}
}
void uniwersal2(double xx, double yy, double y2)
{

	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx - 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);

		rysuj_kwadrat(Square, xx - 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx - 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
	}
}
void uniwersal3(double xx, double yy, double y2)
{


	int i = 1;
	if (y2 == -40)
		i++;
	if (y2 != -50 && y2 != -40){
		rysuj_kontur(Square, xx + 0, y2 + 0);
		rysuj_kontur(Square, xx + 0, y2 + 2);
		rysuj_kontur(Square, xx + 2, y2 + 2);
		rysuj_kontur(Square, xx + 0, y2 + 4);

		rysuj_kwadrat(Square, xx + 0, yy + 0, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 2, yy + 2, 0);
		rysuj_kwadrat(Square, xx + 0, yy + 4, 0);
	}
	else
	{
		rysuj_kwadrat(Square, xx + 0, yy + 0, i);
		rysuj_kwadrat(Square, xx + 0, yy + 2, i);
		rysuj_kwadrat(Square, xx + 2, yy + 2, i);
		rysuj_kwadrat(Square, xx + 0, yy + 4, i);
	}
}
