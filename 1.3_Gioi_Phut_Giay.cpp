#include<iostream>
using namespace std;

struct Thoigian
{
	int gio, phut, giay;
};

Thoigian calcTime(Thoigian time1, Thoigian time2);
void NhapTG(Thoigian &t)
{
	do
	{
		cout << "\nNhap vao gio: ";
		cin >> t.gio;
		if (t.gio < 0 || t.gio>24)
			cout << "Nhap sai, yeu cau nhap lai gio! ";
	} while (t.gio < 0 || t.gio>24);

	do
	{
		cout << "Nhap vao phut: ";
		cin >> t.phut;
		if (t.phut < 0 || t.phut>60)
			cout << "Nhap sai, yeu cau nhap lai phut! ";
	} while (t.phut < 0 || t.phut>60);

	do
	{
		cout << "Nhap vao giay: ";
		cin >> t.giay;
		if (t.giay < 0 || t.giay>60)
			cout << "Nhap sai, yeu cau nhap lai giay! ";
	} while (t.giay < 0 || t.giay>60);
}

void XuatTG(Thoigian t)
{
	cout << t.gio << ":" << t.phut << ":" << t.giay;
}


void main()
{
	Thoigian t1, t2, time;
	cout << "Nhap thoi gian 1: ";
	NhapTG(t1);

	cout << "Nhap thoi gian 2: ";
	NhapTG(t2);
	cout << "Thoi gian 1:  ";
	XuatTG(t1);
	cout << "\nThoi gian 2:  ";
	XuatTG(t2);
	time = calcTime(t1, t2);
	cout << "\nKhoang cach la : ";
	XuatTG(time);
	
	cout << endl;
}
Thoigian calcTime(Thoigian time1, Thoigian time2)
{
	int s1 = 0, s2 = 0;
	int s;
	Thoigian time;
	s1 = 60 * 60 * time1.gio + 60 * time1.phut + time1.giay;
	s2 = 60 * 60 * time2.gio + 60 * time2.phut + time2.giay;
	s = s1 - s2;
	if (s < 0)
	{
		s = (-1) * s;
	}
	time.phut = s / 60;
	time.giay = s % 60;
	time.gio = time.phut / 60;
	time.phut = time.phut % 60;

	return time;
}