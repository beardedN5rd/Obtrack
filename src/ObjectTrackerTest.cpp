//============================================================================
// Test for Object tracker
//	 
//	2014 by Hagen Pache
//	https://github.com/beardedN5rd	 
//============================================================================
#include <ObjectTracker.hpp>


#define BOOST_TEST_MODULE ObjectTracker
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>


struct X : public ObjectTracker<X>
{
	X(){};
};
struct Y : public ObjectTracker<Y>
{
	Y(){};
};
struct Z : public ObjectTracker<Z>
{
	Z(){};
};

BOOST_AUTO_TEST_SUITE( BOT )

BOOST_AUTO_TEST_CASE( alive_test )
{
	volatile X* x;
	x = new X();
	x = new X();
	x = new X();
	x = new X();
	delete(x);
	BOOST_CHECK_EQUAL( X::getAlive(),3 );
}

BOOST_AUTO_TEST_CASE( creation_test )
{
	volatile Y* y = new Y();
	y = new Y();
	BOOST_CHECK_EQUAL( Y::getCreated(),2 );
}

BOOST_AUTO_TEST_CASE( destruction_test )
{
	volatile Z* z = new Z();
	delete(z);
	BOOST_CHECK_EQUAL( Z::getDestroyed(),1 );
}

BOOST_AUTO_TEST_SUITE_END()
