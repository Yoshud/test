#pragma once
#include "obj_fiz.h"
class obj_fiz_sym: virtual public obj_fiz
{
public:
	obj_fiz_sym();
	virtual void zakoncz_cykl_sym() {}
	virtual ~obj_fiz_sym();


};

