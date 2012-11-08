//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_AOP_IS_ASPECT_HPP
#define FAS_AOP_IS_ASPECT_HPP

#include <fas/aop/metalist.hpp>
#include <fas/typemanip/is_has_metatype.hpp>
#include <fas/mp/f.hpp>

namespace fas{

template<typename T>
struct is_aspect: f< is_has_metatype<T, metalist::aspect> >{};

}

#endif
