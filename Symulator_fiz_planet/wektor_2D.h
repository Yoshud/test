#pragma once
#include <iostream>
using namespace std;
template <typename typ>
class wektor_2D
{
public:
	wektor_2D();
	wektor_2D(typ x, typ y);
	//	~wektor_3D();
	virtual wektor_2D operator+ (wektor_2D) const; //zdef
	virtual wektor_2D operator+=(wektor_2D); //zdef
	virtual wektor_2D operator-=(wektor_2D); //zdef
	virtual wektor_2D operator- (wektor_2D) const; //zdef
	virtual wektor_2D operator-() const; //zdef
	virtual wektor_2D operator*(typ skalar) const;//zdef
	virtual wektor_2D operator/(typ skalar) const;	//zdef
	virtual typ operator*(wektor_2D) const; //iloczyn skalarny 

	virtual typ iloczyn_wektorowy_2D(const wektor_2D& drugi) const
	{
		return (x * drugi.get_y() - y * drugi.get_x());
	}
	const double& get_x() const
	{
		return x;
	}
	const double& get_y() const
	{
		return y;
	}
	friend std::ostream& operator<<(std::ostream& wy, wektor_2D wypisywany)
	{
		wy << "x: " << wypisywany.x << "y: " << wypisywany.y;
		return wy;
	}

	typ norma_2(const wektor_2D<typ> &drugi = wektor_2D<typ>()) const; //zdef
	wektor_2D<typ>& normalizuj(); //zdef
protected:
	typ x, y;


	typ pow_2(const typ &wartosc) const;//zdef
};
template <typename typ>
wektor_2D<typ> operator*(typ skalar, wektor_2D<typ>);

template <typename typ>
wektor_2D<typ>::wektor_2D() : x(0), y(0){}

template <typename typ>
wektor_2D<typ>::wektor_2D(typ x, typ y) : x(x), y(y){}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator+(wektor_2D drugi) const
{
	return wektor_2D(this->x + drugi.x, this->y + drugi.y);
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator+=(wektor_2D drugi) 
{
	*this = *this + drugi; 
	return *this;
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator-=(wektor_2D drugi)
{
	*this = *this - drugi;
	return *this;
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator-(wektor_2D drugi) const
{
	return wektor_2D(this->x - drugi.x, this->y - drugi.y);
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator-() const
{
	return wektor_2D(-this->x, -this->y );
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator*(typ skalar) const
{
	return wektor_2D(this->x * skalar, this->y * skalar);
}

template<typename typ>
wektor_2D<typ> wektor_2D<typ>::operator/(typ skalar) const
{
	return wektor_2D(this->x / skalar, this->y / skalar);
}

template<typename typ>
typ wektor_2D<typ>::operator*(wektor_2D drugi) const
{
	return (this->x * drugi.x + this->y * drugi.y);
}

template<typename typ>
wektor_2D<typ> operator*(typ skalar, wektor_2D<typ> wekt)
{
	return wekt*skalar;
}

template<typename typ>
wektor_2D<typ>& wektor_2D<typ>::normalizuj()
{
	typ k = norma_2();
	*this = *this / k;
	return *this;
}

template<typename typ>
typ wektor_2D<typ>::norma_2(const wektor_2D<typ> &drugi) const
{
	return sqrt(pow_2(this->x - drugi.x) + pow_2(this->y - drugi.y));
}

template<typename typ>
typ wektor_2D<typ>::pow_2(const typ & wartosc) const
{
	return wartosc * wartosc;
}



