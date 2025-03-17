#include <gtest/gtest.h>

#include "../src/dijkstras.h"
#include "../src/ladder.h"


TEST(isadj, working) {
  EXPECT_TRUE( is_adjacent("cog", "pog") );
  EXPECT_FALSE( is_adjacent("cog", "poggers") );

}
