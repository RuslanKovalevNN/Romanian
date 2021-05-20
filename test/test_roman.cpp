#include "roman.h"

#include <gtest.h>

TEST(Roma, can_create_roma)
{
  ASSERT_NO_THROW(Roma r(5,"LXVI"));
}

TEST(Roma, can_create_copied_roma)
{
	Roma romanian(14, "XXV");

    ASSERT_NO_THROW(Roma _romanian(romanian));
}

TEST(Roma, can_to_number)
{
	Roma r(12, "XXX");
	EXPECT_EQ(r.ToNumber(), 30);
	EXPECT_EQ(r.ToRoma(), "XII");
}

TEST(Roma, is_romanian)
{
	Roma r(12, "MX");
	EXPECT_EQ(r.itsRoma("MX"),1);
}

TEST(Roma, is_not_romanian)
{
	Roma romanian(33, "TS");
	EXPECT_EQ(romanian.itsRoma("TS"),0);
}

