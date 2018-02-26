
#include "sym_Newton.h"
class sym_Newton_prosta :
	public sym_Newton
{
public:
	sym_Newton_prosta();
	//virtual void oblicz_F(obj_fiz& drugi_obj, sf::Time& sym_time);
	virtual void oblicz_F(obj_fiz& drugi_obj);
	virtual void zakoncz_cykl_sym(); 
	~sym_Newton_prosta();
};
