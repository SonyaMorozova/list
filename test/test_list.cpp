#include "list.h"
#include <gtest.h>

TEST(List, can_create_list) {
	ASSERT_NO_THROW(List<int> lst);
}


TEST(List, identical_lists_are_equal) {
	List<int> lst1;
	List<int> lst2;

	lst1.push_front(5);
	lst1.push_front(15);
	lst1.push_front(25);

	lst2.push_front(5);
	lst2.push_front(15);
	lst2.push_front(25);
	ASSERT_TRUE(lst1 == lst2);
}

TEST(List, list_with_different_sizes_not_equal) {
	List<int> lst1;
	List<int> lst2;
	lst1.push_front(5);
	lst1.push_front(15);

	lst2.push_front(5);
	lst2.push_front(15);
	lst2.push_front(25);
	ASSERT_FALSE(lst1 == lst2);
}

TEST(List, different_lists_with_same_sizes_not_equal) {
	List<int> lst1;
	List<int> lst2;
	lst1.push_front(5);
	lst1.push_front(15);
	lst1.push_front(35);

	lst2.push_front(5);
	lst2.push_front(15);
	lst2.push_front(25);
	ASSERT_FALSE(lst1 == lst2);
}

TEST(List, can_equate_lists) {
	List<int> lst1;
	List<int> lst2;

	lst1.push_front(5);
	lst1.push_front(15);
	lst1.push_front(25);

	lst2.push_front(20);
	lst2.push_front(30);
	lst2 = lst1;

	EXPECT_EQ(lst2, lst1);
}


TEST(List, can_indexing_list) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	ASSERT_TRUE(lst[1] == 4);
}

TEST(List, can_indexing_list_edit_value) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	lst[1] = 10;
	ASSERT_TRUE(lst[1] == 10);
}



TEST(List, can_push_front_list) {
	List<int> lst;
	lst.push_front(4);
	
	ASSERT_NO_THROW(lst.push_front(4));
}

TEST(List, can_push_back_list) {
	List<int> lst;

	ASSERT_NO_THROW(lst.push_back(4));
}

TEST(List, can_copy_lists) {
	List<int> lst1;
	List<int>lst2(lst1);

	EXPECT_EQ(lst1, lst2);
}

TEST(List, true_if_list_is_empty) {
	List<int> lst;
	ASSERT_TRUE(lst.is_empty() == 1);
}

TEST(List, false_if_list_is_not_empty) {
	List<int> lst;
	lst.push_front(3);
	lst.push_front(15);
	ASSERT_FALSE(lst.is_empty() == 1);
}

TEST(List, can_use_size_list) {
	List<int> lst;
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);
	ASSERT_EQ(lst.size(), 3);
}



TEST(List, cant_erase_list_with_large_index) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);
	ASSERT_ANY_THROW(lst.erase(6));
}

TEST(List, cant_erase_list_with_negative_index) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);
	ASSERT_ANY_THROW(lst.erase(-2));
}

TEST(List, correct_work_erase_list) {
	List<int> lst1;
	List<int> lst2;

	lst1.push_front(4);
	lst1.push_front(3);
	lst1.push_front(2);
	lst1.push_front(1);

	lst2 = lst1;

	lst1.erase(3);
	ASSERT_FALSE(lst1 == lst2);
}


TEST(List, true_if_search_value_in_list) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	ASSERT_TRUE(lst.search(3));
}

TEST(List, false_if_not_search_value_in_list) {
	List<int> lst;
	lst.push_front(4);
	lst.push_front(3);
	ASSERT_FALSE(lst.search(15));
}

