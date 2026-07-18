#include <gtest/gtest.h>

TEST(VersionTest, VersionIsPositive)
{
  int version = 1;

  ASSERT_GT(version, 0);
}

TEST(VersionTest, VersionIsValid)
{
  int version = 1;

  ASSERT_TRUE(version >= 0);
}