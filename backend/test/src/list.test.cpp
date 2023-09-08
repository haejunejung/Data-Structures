#include "list.hpp"

#include <cstddef>
#include <gtest/gtest.h>

class listTest : public ::testing::Test {
    protected:
        list none_;
        list some_;

    public:
        listTest() {}

        virtual ~listTest() {}
        
        virtual void SetUp() {
            for (int i = 1; i <= 3; i++)
                some_.push_back(i); // (1,2,3)
        }

        virtual void TearDown() {}
};

TEST_F(listTest, init) {
    ASSERT_EQ(none_.size(), 0);
    ASSERT_EQ(none_.empty(), true);

    ASSERT_EQ(some_.size(), 3);
    ASSERT_EQ(some_.empty(), false);
}

TEST_F(listTest, front) {
    ASSERT_THROW(none_.front(), std::runtime_error);
    ASSERT_EQ(some_.front(), 1);
}

TEST_F(listTest, back) {
    ASSERT_THROW(none_.back(), std::runtime_error);
    ASSERT_EQ(some_.back(), 3);
}

TEST_F(listTest, empty) {
    ASSERT_EQ(none_.empty(), true);
    ASSERT_EQ(some_.empty(), false);
}

TEST_F(listTest, size) {
    ASSERT_EQ(none_.size(), 0);
    ASSERT_EQ(some_.size(), 3);
}

TEST_F(listTest, push_front) {
    none_.push_front(0);
    ASSERT_EQ(none_.front(), 0);
    ASSERT_EQ(none_.back(), 0);
    ASSERT_EQ(none_.size(), 1);
    ASSERT_EQ(none_.empty(), false);

    some_.push_front(0);
    ASSERT_EQ(some_.front(), 0);
    ASSERT_EQ(some_.back(), 3);
    ASSERT_EQ(some_.size(), 4);
    ASSERT_EQ(some_.empty(), false);
}

TEST_F(listTest, push_back) {
    none_.push_back(4);
    ASSERT_EQ(none_.front(), 4);
    ASSERT_EQ(none_.back(), 4);
    ASSERT_EQ(none_.size(), 1);
    ASSERT_EQ(none_.empty(), false);

    some_.push_back(4);
    ASSERT_EQ(some_.front(), 1);
    ASSERT_EQ(some_.back(), 4);
    ASSERT_EQ(some_.size(), 4);
    ASSERT_EQ(some_.empty(), false);
}

TEST_F(listTest, pop_front) {
    ASSERT_THROW(none_.pop_front(), std::runtime_error);

    some_.pop_front();
    ASSERT_EQ(some_.front(), 2);
    ASSERT_EQ(some_.size(), 2);
    ASSERT_EQ(some_.empty(), false);
    
    some_.pop_front();
    ASSERT_EQ(some_.front(), 3);
    ASSERT_EQ(some_.size(), 1);
    ASSERT_EQ(some_.empty(), false);

    some_.pop_front();
    ASSERT_EQ(some_.size(), 0);
    ASSERT_EQ(some_.empty(), true);
}

TEST_F(listTest, pop_back) {
    ASSERT_THROW(none_.pop_back(), std::runtime_error);

    some_.pop_back();
    ASSERT_EQ(some_.back(), 2);
    ASSERT_EQ(some_.size(), 2);
    ASSERT_EQ(some_.empty(), false);
    
    some_.pop_back();
    ASSERT_EQ(some_.back(), 1);
    ASSERT_EQ(some_.size(), 1);
    ASSERT_EQ(some_.empty(), false);

    some_.pop_back();
    ASSERT_EQ(some_.size(), 0);
    ASSERT_EQ(some_.empty(), true);
}
