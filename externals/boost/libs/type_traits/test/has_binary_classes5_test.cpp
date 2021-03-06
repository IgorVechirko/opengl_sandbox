//  (C) Copyright 2009-2011 Frederic Bron.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/type_traits/has_operator.hpp>
#include "test.hpp"
#include "check_integral_constant.hpp"
#include "has_binary_classes.hpp"

TT_TEST_BEGIN(BOOST_TT_TRAIT_NAME)
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const, C288 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const, C288 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 &, C288 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C288 const &, C288 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289, C289, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289, C289 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289, C289 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289, C289 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const, C289 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 &, C289 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const &, C289, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const &, C289 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const &, C289 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C289 const &, C289 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290, C290 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const, C290 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 &, C290 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C290 const &, C290 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293, C293 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const, C293 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 &, C293 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C293 const &, C293 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294, C294 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const, C294 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 &, C294 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C294 const &, C294 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297, C297 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const, C297 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 const &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 &, C297 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C297 const &, C297 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298, C298 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const, C298, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const, C298, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const, C298 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const, C298 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const, C298 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 &, C298, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 &, C298, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 &, C298 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 &, C298 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 &, C298 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C298 const &, C298 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299, C299 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const, C299 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const, C299 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const, C299 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const, C299 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 &, C299 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C299 const &, C299 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302, C302 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302 const, C302, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C302 const, C302, ret const >::value), 0);
TT_TEST_END
