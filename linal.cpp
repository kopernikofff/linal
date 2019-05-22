#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Vector3D
{
private:
	double x, y, z;
public:
	Vector3D() {}
	~Vector3D() {}

	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double getZ()
	{
		return z;
	}

	void setX(double x)
	{
		this->x = x;
	}
	void setY(double x)
	{
		this->y = x;
	}
	void setZ(double x)
	{
		this->z = x;
	}

	friend Vector3D operator +(Vector3D v1, Vector3D v2)
	{
		Vector3D res;
		res.x = v1.x + v2.x;
		res.y = v1.y + v2.y;
		res.z = v1.z + v2.z;
		return res;
	}
	friend Vector3D operator -(Vector3D v1, Vector3D v2)
	{
		Vector3D res;
		res.x = v1.x - v2.x;
		res.y = v1.y - v2.y;
		res.z = v1.z - v2.z;
		return res;
	}
	friend double operator *(Vector3D v1, Vector3D v2)
	{
		return v1.x* v2.x + v1.y * v2.y + v1.z * v2.z;
	}
	friend Vector3D operator *(Vector3D v, double c)
	{
		Vector3D res;
		res.x = v.x * c;
		res.y = v.y * c;
		res.z = v.z * c;
		return res;
	}
	friend Vector3D operator *(double c, Vector3D v)
	{
		Vector3D res;
		res.x = v.x * c;
		res.y = v.y * c;
		res.z = v.z * c;
		return res;
	}
	friend istream& operator >>(istream& in, Vector3D& v)
	{
		in >> v.x >> v.y >> v.z;
		return in;
	}
	friend ostream& operator <<(ostream& out, Vector3D v)
	{
		out << v.x << " " << v.y << " " << v.z << endl;
		return out;
	}
};

class Matrix3D
{
private:
	double m[3][3];
public:
	Matrix3D() {}
	~Matrix3D()
	{}

	friend Matrix3D operator +(Matrix3D m1, Matrix3D m2)
	{
		Matrix3D res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				res.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
		return res;
	}
	friend Matrix3D operator -(Matrix3D m1, Matrix3D m2)
	{
		Matrix3D res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				res.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
		return res;
	}
	friend Matrix3D operator *(Matrix3D m1, Matrix3D m2)
	{
		Matrix3D res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				double s = 0;
				for (int r = 0; r < 3; r++)
				{
					s += m1.m[i][r] * m2.m[r][j];
				}
				res.m[i][j] = s;
			}
		}
		return res;
	}
	friend Vector3D operator *(Vector3D v, Matrix3D m)
	{
		Vector3D res;
		res.setX(v.getX() * m.m[0][0] + v.getY() * m.m[1][0] + v.getZ() * m.m[2][0]);
		res.setY(v.getX() * m.m[0][1] + v.getY() * m.m[1][1] + v.getZ() * m.m[2][1]);
		res.setZ(v.getX() * m.m[0][2] + v.getY() * m.m[1][2] + v.getZ() * m.m[2][2]);
		return res;
	}
	friend Matrix3D operator *(Matrix3D m, double c)
	{
		Matrix3D res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				res.m[i][j] = m.m[i][j] * c;
		}
		return res;
	}
	friend Matrix3D operator *(double c, Matrix3D m)
	{
		Matrix3D res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				res.m[i][j] = m.m[i][j] * c;
		}
		return res;
	}
	friend double det(Matrix3D m)
	{
		return m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] + m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] - m.m[0][0] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][0] * m.m[2][2];
	}
	friend istream& operator >>(istream & in, Matrix3D & m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				in >> m.m[i][j];
		}
		return in;
	}
	friend ostream& operator <<(ostream & out, Matrix3D m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) out << m.m[i][j] << " ";
			out << endl;
		}
		return out;
	}
};

int main()
{
	Vector3D v1, v2;
	Matrix3D m1, m2;

	cout << "Enter first vector(v1): ";
	cin >> v1;
	cout << v1 << endl;
	cout << "Enter second vector(v2): ";
	cin >> v2;
	cout << v2 << endl;

	cout << "v1 + v2 = " << v1 + v2 << endl;
	cout << "v1 - v2 = " << v1 - v2 << endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
	cout << "v1 * 2 = " << v1 * 2 << endl;
	cout << "3 * v1 =  " << 3 * v1 << endl;

	cout << "Enter first matrix(M1): ";
	cin >> m1;
	cout << endl << m1 << endl;
	cout << "Enter second matrix(M2): ";
	cin >> m2;
	cout << endl << m2 << endl;

	cout << "det(M1) = " << det(m1) << endl;
	cout << "M1 + M2 = " << endl << m1 + m2 << endl;
	cout << "M1 - M2 = " << endl << m1 - m2 << endl;
	cout << "M1 * M2 = " << endl << m1 * m2 << endl;
	cout << "v2 * M2 = " << v2 * m2 << endl;
	cout << "M1 * 2 = " << endl << m1 * 2 << endl;
	cout << "3 * M1 = " << endl << 3 * m1 << endl;

	system("pause");
	return 0;
}
