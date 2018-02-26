#pragma once
#include <iostream>
using namespace std;
template <typename typ>
class wektor_3D
{
public:
	wektor_3D();
	wektor_3D(typ x, typ y, typ z);
	//	~wektor_3D();

	virtual wektor_3D operator+(wektor_3D) const; //zdef
	virtual wektor_3D operator*(typ skalar) const;//zdef
	virtual wektor_3D operator/(typ skalar) const;	//zdef
	virtual wektor_3D operator*(wektor_3D) const; //iloczyn wektorowy zdef
	virtual typ operator%(wektor_3D) const;
	//virtual std::ostream& wypisz(std::ostream& ) const;
	friend std::ostream& operator<<(std::ostream& wy, wektor_3D wypisywany)
	{
		wy << "x: " << wypisywany.x << "y: " << wypisywany.y << "z: " << wypisywany.z << endl;
		return wy;
	}

	typ norma_2(const wektor_3D<typ> &drugi = wektor_3D<typ>()) const; //zdef
	wektor_3D<typ>& normalizuj(); //zdef
protected:
	typ x, y, z;


	typ pow_2(const typ &wartosc) const;//zdef
};
template <typename typ>
wektor_3D<typ> operator*(typ skalar, wektor_3D<typ>);

template <typename typ>
wektor_3D<typ>::wektor_3D() : x(0), y(0), z(0) {}

template <typename typ>
wektor_3D<typ>::wektor_3D(typ x, typ y, typ z) : x(x), y(y), z(z) {}

template<typename typ>
wektor_3D<typ> wektor_3D<typ>::operator+(wektor_3D drugi) const
{
	return wektor_3D(this->x + drugi.x, this->y + drugi.y, this->z + drugi.z);
}

template<typename typ>
wektor_3D<typ> wektor_3D<typ>::operator*(typ skalar) const
{
	return wektor_3D(this->x * skalar, this->y * skalar, this->z * skalar);
}

template<typename typ>
wektor_3D<typ> wektor_3D<typ>::operator/(typ skalar) const
{
	return wektor_3D(this->x / skalar, this->y / skalar, this->z / skalar);
}

template<typename typ>
wektor_3D<typ> wektor_3D<typ>::operator*(wektor_3D drugi) const
{
	return wektor_3D((this->y * drugi.z - this->z * drugi.y), (this->z * drugi.x - this->x * drugi.z), (this->x * drugi.y - this->y * drugi.x));
}

template<typename typ>
typ wektor_3D<typ>::operator%(wektor_3D drugi) const
{
	return (this->x * drugi.x + this->y * drugi.y + this->z * drugi.z);
}

//template<typename typ>
//std::ostream & wektor_3D<typ>::wypisz(std::ostream &wy) const
//{
//	//std::cout << "cos";
//	wy << "[ " << x << << " , " << y << " , " << z << " ]" << endl;
//	return wy;
//}

template<typename typ>
wektor_3D<typ> operator*(typ skalar, wektor_3D<typ> wekt)
{
	return wekt*skalar;
}


template<typename typ>
wektor_3D<typ>& wektor_3D<typ>::normalizuj()
{
	typ k = norma_2();
	*this = *this / k;
	return *this;
}

template<typename typ>
typ wektor_3D<typ>::norma_2(const wektor_3D<typ> &drugi) const
{
	return sqrt(pow_2(this->x - drugi.x) + pow_2(this->y - drugi.y) + pow_2(this->z - drugi.z));
}

template<typename typ>
typ wektor_3D<typ>::pow_2(const typ & wartosc) const
{
	return wartosc * wartosc;
}


